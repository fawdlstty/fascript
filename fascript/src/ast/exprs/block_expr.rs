use super::AstExpr;
use crate::ast::stmts::AstStmt;

#[derive(Clone, Debug)]
pub struct AstBlockExpr {
    pub stmts: Vec<AstStmt>,
    pub val: Box<AstExpr>,
}

impl AstBlockExpr {
    pub fn new(stmts: Vec<AstStmt>, val: AstExpr) -> AstExpr {
        AstExpr::Block(AstBlockExpr {
            stmts,
            val: Box::new(val),
        })
    }
}
