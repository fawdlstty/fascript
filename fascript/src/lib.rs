pub mod ast;
pub mod exec;
pub mod utils;

use crate::ast::exprs::value_expr::FasValue;
use ast::blocks::func::{AstFunc, AstNativeFunc};
use ast::blocks::program::AstProgram;
use ast::exprs::func_expr::AstFuncExpr;
use ast::types::AstType;
use ast::FromStringExt;
use exec::task_runner::TaskRunner;
use std::marker::PhantomData;

trait FasCallable {
    fn call(&self, args: Vec<FasValue>) -> FasValue;
}

/////////////////////

pub struct FuncWrapperWithTwo<T: Fn(T1, T2) -> R, T1, T2, R>(T, PhantomData<(T1, T2, R)>);

impl<T, T1, T2, R> FasCallable for FuncWrapperWithTwo<T, T1, T2, R>
where
    T: Fn(T1, T2) -> R,
    T1: From<FasValue>,
    T2: From<FasValue>,
    R: Into<FasValue>,
{
    fn call(&self, args: Vec<FasValue>) -> FasValue {
        let f = T1::from(args[0].clone());
        let s = T2::from(args[1].clone());
        let r = (self.0)(f, s);
        r.into()
    }
}

pub trait ToWrapper<T> {
    type Output: FasCallable;
    fn convert(self) -> Self::Output;
}

impl<T, T1, T2, R> ToWrapper<(T1, T2, R)> for T
where
    T: Fn(T1, T2) -> R,
    T1: From<FasValue>,
    T2: From<FasValue>,
    R: Into<FasValue>,
{
    type Output = FuncWrapperWithTwo<T, T1, T2, R>;

    fn convert(self) -> Self::Output {
        FuncWrapperWithTwo(self, PhantomData)
    }
}

/////////////////////

pub struct FasRuntime {
    runner: TaskRunner,
}

impl FasRuntime {
    pub fn new() -> FasRuntime {
        FasRuntime {
            runner: TaskRunner::new(),
        }
    }

    pub async fn eval(&mut self, code: &str) -> Option<FasValue> {
        let stmts = match AstProgram::from_str(code) {
            Ok(program) => program.stmts,
            Err(err) => {
                println!("parse error: {}", err);
                return None;
            }
        };
        for stmt in stmts {
            self.runner.eval_stmt(stmt);
        }
        self.runner.get_return_value()
    }

    pub fn set_global_value(&mut self, name: String, value: FasValue) {
        self.runner.set_global_value(name, value)
    }

    pub fn set_global_func(
        &mut self,
        name: String,
        func_impl: Box<dyn FasCallable>,
        arg_types: Vec<AstType>,
        ret_type: AstType,
    ) {
        let native_func = AstNativeFunc {
            ret_type,
            name: name.clone(),
            arg_types,
            func_impl,
        };
        let func = Box::new(AstFuncExpr::new(AstFunc::AstNativeFunc(native_func)));
        self.runner.set_global_value(name, FasValue::Func(func))
    }

    fn set_func_help<T: FasCallable>(&mut self, s: &str, f: T) {
        // TODO
    }

    pub fn set_func<T: ToWrapper<U>, U>(&mut self, s: &str, f: T) {
        self.set_func_help(s, f.convert());
    }
}

// pub struct Fascript {}

// impl Fascript {
//     pub fn new_runtime() -> FasRuntime {
//         FasRuntime::new()
//     }

//     pub async fn set_global_value(name: String, value: FasValue) {
//         let mut runtime_inst = RUNTIME_INST.lock().await;
//         runtime_inst.set_global_value(name, value)
//     }

//     pub async fn set_global_func(
//         name: String,
//         func_impl: Box<fn(Vec<FasValue>) -> FasValue>,
//         arg_types: Vec<AstType>,
//         ret_type: AstType,
//     ) {
//         let mut runtime_inst = RUNTIME_INST.lock().await;
//         runtime_inst.set_global_func(name, func_impl, arg_types, ret_type)
//     }

//     pub async fn set_func<A, R, F: Fn(A) -> R>(func_name: String, func: F) {
//         let mut runtime_inst = RUNTIME_INST.lock().await;
//         runtime_inst.set_func(func_name, func)
//     }
// }
