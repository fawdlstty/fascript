use super::AstStmt;
use crate::ast::{
    exprs::{index_expr::AstIndexExpr, AstExpr},
    ParseExt, Rule,
};

#[derive(Clone, Debug)]
pub struct AstForStmt {
    pub iter_name: String,
    pub iter_items: AstExpr,
    pub stmts: Vec<AstStmt>,
}

impl AstForStmt {
    pub fn new() -> AstForStmt {
        AstForStmt {
            iter_name: "".to_string(),
            iter_items: AstExpr::None,
            stmts: vec![],
        }
    }
}

impl ParseExt for AstForStmt {
    fn parse(root: pest::iterators::Pair<'_, Rule>) -> Self {
        let mut for_stmt = AstForStmt::new();
        for root_item in root.into_inner() {
            match root_item.as_rule() {
                Rule::Id => for_stmt.iter_name = root_item.as_str().to_string(),
                Rule::Expr => for_stmt.iter_items = AstExpr::parse(root_item),
                Rule::IndexExpr => for_stmt.iter_items = AstExpr::parse_index_expr(root_item),
                Rule::Stmt => for_stmt.stmts.push(AstStmt::parse(root_item)),
                _ => unreachable!(),
            }
        }
        for_stmt
    }
}
