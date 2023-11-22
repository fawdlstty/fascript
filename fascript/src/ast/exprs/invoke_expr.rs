use std::borrow::BorrowMut;

use crate::ast::types::AstType;

use super::{op2_expr::AstOp2Expr, value_expr::FasValue, AstExpr};

#[derive(Clone, Debug)]
pub struct AstInvokeExpr {
    pub func: Box<AstExpr>,
    pub arguments: Vec<AstExpr>,
}

impl AstInvokeExpr {
    pub fn new(func: AstExpr, arguments: Vec<AstExpr>) -> AstExpr {
        AstExpr::Invoke(AstInvokeExpr {
            func: Box::new(func),
            arguments,
        })
    }
}
