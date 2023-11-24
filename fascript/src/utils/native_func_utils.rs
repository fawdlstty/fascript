use crate::ast::blocks::func::{AstFunc, AstNativeFunc};
use crate::ast::exprs::func_expr::AstFuncExpr;
use crate::ast::exprs::value_expr::{FasValue, GetAstTypeTrait};
use std::marker::PhantomData;

pub trait FasCallable {
    fn call(&self, args: Vec<FasValue>) -> FasValue;
    fn clone(&self) -> Box<dyn FasCallable + 'static>;
    fn to_fas_value(self, func_name: String) -> FasValue;
}

pub trait FasToWrapper<T> {
    type Output: FasCallable;
    fn convert(self) -> Self::Output;
}

/////////////////////

pub struct FuncWrapper1<T: Fn(T1) -> R, T1, R>(T, PhantomData<(T1, R)>);

impl<T, T1, R> FasCallable for FuncWrapper1<T, T1, R>
where
    T: Fn(T1) -> R + Clone + 'static,
    T1: From<FasValue> + GetAstTypeTrait + 'static,
    R: Into<FasValue> + GetAstTypeTrait + 'static,
{
    fn call(&self, args: Vec<FasValue>) -> FasValue {
        let t1 = T1::from(args[0].clone());
        let r = (self.0)(t1);
        r.into()
    }

    fn clone(&self) -> Box<dyn FasCallable + 'static> {
        let copy = Self(self.0.clone(), PhantomData);
        Box::new(copy)
    }

    fn to_fas_value(self, func_name: String) -> FasValue {
        let native_func = AstNativeFunc {
            ret_type: R::get_ast_type(),
            name: func_name,
            arg_types: vec![T1::get_ast_type()],
            func_impl: Box::new(self),
        };
        FasValue::Func(Box::new(AstFuncExpr::new(AstFunc::AstNativeFunc(
            native_func,
        ))))
    }
}

impl<T, T1, R> FasToWrapper<(T1, R)> for T
where
    T: Fn(T1) -> R + Clone + 'static,
    T1: From<FasValue> + GetAstTypeTrait + 'static,
    R: Into<FasValue> + GetAstTypeTrait + 'static,
{
    type Output = FuncWrapper1<T, T1, R>;

    fn convert(self) -> Self::Output {
        FuncWrapper1(self, PhantomData)
    }
}

/////////////////////

pub struct FuncWrapper2<T: Fn(T1, T2) -> R, T1, T2, R>(T, PhantomData<(T1, T2, R)>);

impl<T, T1, T2, R> FasCallable for FuncWrapper2<T, T1, T2, R>
where
    T: Fn(T1, T2) -> R + Clone + 'static,
    T1: From<FasValue> + GetAstTypeTrait + 'static,
    T2: From<FasValue> + GetAstTypeTrait + 'static,
    R: Into<FasValue> + GetAstTypeTrait + 'static,
{
    fn call(&self, args: Vec<FasValue>) -> FasValue {
        let f = T1::from(args[0].clone());
        let s = T2::from(args[1].clone());
        let r = (self.0)(f, s);
        r.into()
    }

    fn clone(&self) -> Box<dyn FasCallable + 'static> {
        let copy = Self(self.0.clone(), PhantomData);
        Box::new(copy)
    }

    fn to_fas_value(self, func_name: String) -> FasValue {
        let native_func = AstNativeFunc {
            ret_type: R::get_ast_type(),
            name: func_name,
            arg_types: vec![T1::get_ast_type(), T2::get_ast_type()],
            func_impl: Box::new(self),
        };
        FasValue::Func(Box::new(AstFuncExpr::new(AstFunc::AstNativeFunc(
            native_func,
        ))))
    }
}

impl<T, T1, T2, R> FasToWrapper<(T1, T2, R)> for T
where
    T: Fn(T1, T2) -> R + Clone + 'static,
    T1: From<FasValue> + GetAstTypeTrait + 'static,
    T2: From<FasValue> + GetAstTypeTrait + 'static,
    R: Into<FasValue> + GetAstTypeTrait + 'static,
{
    type Output = FuncWrapper2<T, T1, T2, R>;

    fn convert(self) -> Self::Output {
        FuncWrapper2(self, PhantomData)
    }
}
