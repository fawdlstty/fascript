use crate::ast::blocks::func::{AstFunc, AstNativeFunc};
use crate::ast::exprs::{func_expr::AstFuncExpr, value_expr::FasValue};
use crate::ast::types::AstType;
use crate::FasCallable;
use crate::FasToWrapper;

pub struct NativeExprs {}

impl NativeExprs {
    fn make_func_impl<T: FasCallable>(func_name: String, f: T) -> FasValue {
        f.to_fas_value(func_name.clone())
    }

    pub fn make_func<T: FasToWrapper<U>, U>(func_name: String, f: T) -> FasValue {
        Self::make_func_impl(func_name, f.convert())
    }

    pub fn get_expr(name: &str) -> FasValue {
        match name {
            "println" => Self::make_func("println".to_string(), |value: String| -> bool {
                println!("{}", value);
                true
            }),
            _ => todo!(),
        }
    }
}
