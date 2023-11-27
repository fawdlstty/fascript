use crate::ast::blocks::func::{AstFunc, AstNativeFunc};
use crate::ast::exprs::func_expr::AstFuncExpr;
use crate::ast::exprs::value_expr::{FasValue, GetAstTypeTrait};
use std::collections::HashMap;
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

//

macro_rules! FasWrapper {
    ($sname:ident) => {
        pub struct $sname<T: Fn() -> R, R>(T, PhantomData<R>);

        impl<T, R> FasCallable for $sname<T, R>
        where
            T: Fn() -> R + Clone + 'static,
            R: Into<FasValue> + GetAstTypeTrait + 'static,
        {
            fn call(&self, _args: Vec<FasValue>) -> FasValue {
                let r = (self.0)();
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
                    arg_types: vec![],
                    func_impl: Box::new(self),
                };
                FasValue::Func(Box::new(AstFuncExpr::new(AstFunc::AstNativeFunc(
                    native_func,
                ))))
            }
        }

        impl<T, R> FasToWrapper<R> for T
        where
            T: Fn() -> R + Clone + 'static,
            R: Into<FasValue> + GetAstTypeTrait + 'static,
        {
            type Output = $sname<T,  R>;

            fn convert(self) -> Self::Output {
                $sname(self, PhantomData)
            }
        }
    };
    ($sname:ident $(, $name1:ident $name2:ident $idx:expr)*) => {
        pub struct $sname<T: Fn($($name1,)*) -> R, $($name1,)* R>(T, PhantomData<($($name1,)* R)>);

        impl<T, $($name1,)* R> FasCallable for $sname<T, $($name1,)* R>
        where
            T: Fn($($name1,)*) -> R + Clone + 'static,
            $($name1: From<FasValue> + GetAstTypeTrait + 'static,)*
            R: Into<FasValue> + GetAstTypeTrait + 'static,
        {
            fn call(&self, args: Vec<FasValue>) -> FasValue {
                $(let $name2 = $name1::from(args[$idx].clone());)*
                let r = (self.0)($($name2,)*);
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
                    arg_types: vec![$($name1::get_ast_type(),)*],
                    func_impl: Box::new(self),
                };
                FasValue::Func(Box::new(AstFuncExpr::new(AstFunc::AstNativeFunc(
                    native_func,
                ))))
            }
        }

        impl<T, $($name1,)* R> FasToWrapper<($($name1,)* R)> for T
        where
            T: Fn($($name1,)*) -> R + Clone + 'static,
            $($name1: From<FasValue> + GetAstTypeTrait + 'static,)*
            R: Into<FasValue> + GetAstTypeTrait + 'static,
        {
            type Output = $sname<T, $($name1,)* R>;

            fn convert(self) -> Self::Output {
                $sname(self, PhantomData)
            }
        }
    };
}

FasWrapper!(FuncWrapper0);
FasWrapper!(FuncWrapper1, T0 t0 0);
FasWrapper!(FuncWrapper2, T0 t0 0, T1 t1 1);
FasWrapper!(FuncWrapper3, T0 t0 0, T1 t1 1, T2 t2 2);
FasWrapper!(FuncWrapper4, T0 t0 0, T1 t1 1, T2 t2 2, T3 t3 3);
FasWrapper!(FuncWrapper5, T0 t0 0, T1 t1 1, T2 t2 2, T3 t3 3, T4 t4 4);
FasWrapper!(FuncWrapper6, T0 t0 0, T1 t1 1, T2 t2 2, T3 t3 3, T4 t4 4, T5 t5 5);
FasWrapper!(FuncWrapper7, T0 t0 0, T1 t1 1, T2 t2 2, T3 t3 3, T4 t4 4, T5 t5 5, T7 t7 7);
FasWrapper!(FuncWrapper8, T0 t0 0, T1 t1 1, T2 t2 2, T3 t3 3, T4 t4 4, T5 t5 5, T7 t7 7, T8 t8 8);
FasWrapper!(FuncWrapper9, T0 t0 0, T1 t1 1, T2 t2 2, T3 t3 3, T4 t4 4, T5 t5 5, T7 t7 7, T8 t8 8, T9 t9 9);

//

pub trait AddFuncExt {
    fn set_func_impl<T: FasCallable>(&mut self, func_name: String, f: T);

    fn set_func<T: FasToWrapper<U>, U>(&mut self, func_name: impl Into<String>, f: T) {
        self.set_func_impl(func_name.into(), f.convert())
    }
}

impl AddFuncExt for HashMap<String, FasValue> {
    fn set_func_impl<T: FasCallable>(&mut self, func_name: String, f: T) {
        let item = f.to_fas_value(func_name.clone());
        self.insert(func_name, item);
    }
}
