use crate::ast::{
    blocks::func::{AstFunc, AstNativeFunc},
    exprs::{func_expr::AstFuncExpr, value_expr::AstValueExpr},
    types::AstType,
};

pub struct NativeExprs {}

impl NativeExprs {
    pub fn get_expr(name: &str) -> AstValueExpr {
        match name {
            "println" => AstValueExpr::Func(Box::new(AstFuncExpr::new(AstFunc::AstNativeFunc(
                AstNativeFunc {
                    ret_type: AstType::None,
                    name: "println".to_string(),
                    arg_types: vec![AstType::String],
                    arg_names: vec!["str".to_string()],
                    func_impl: Box::new(Self::println_wrap),
                },
            )))),
            _ => todo!(),
        }
    }

    fn println_wrap(args: Vec<AstValueExpr>) -> AstValueExpr {
        let arg = match args.first() {
            Some(arg) => arg.as_str(),
            None => "".to_string(),
        };
        println!("{}", arg);
        AstValueExpr::None
    }
}
