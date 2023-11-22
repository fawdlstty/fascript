use crate::ast::{
    blocks::func::{AstFunc, AstNativeFunc},
    exprs::{func_expr::AstFuncExpr, value_expr::FasValue},
    types::AstType,
};

pub struct NativeExprs {}

impl NativeExprs {
    pub fn get_expr(name: &str) -> FasValue {
        match name {
            // "println" => FasValue::Func(Box::new(AstFuncExpr::new(AstFunc::AstNativeFunc(
            //     AstNativeFunc {
            //         ret_type: AstType::None,
            //         name: "println".to_string(),
            //         arg_types: vec![AstType::String],
            //         func_impl: Box::new(Self::println_wrap),
            //     },
            // )))),
            _ => todo!(),
        }
    }

    fn println_wrap(args: Vec<FasValue>) -> FasValue {
        let arg = match args.first() {
            Some(arg) => arg.as_str(),
            None => "".to_string(),
        };
        println!("{}", arg);
        FasValue::None
    }
}
