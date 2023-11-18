use super::AstStmt;
use crate::ast::{exprs::AstExpr, ParseExt, Rule};

#[derive(Clone, Debug)]
pub struct AstWhileStmt {
    pub label: String,
    pub cond_expr: AstExpr,
    pub stmts: Vec<AstStmt>,
}

impl AstWhileStmt {
    pub fn new() -> AstWhileStmt {
        AstWhileStmt {
            label: "".to_string(),
            cond_expr: AstExpr::None,
            stmts: vec![],
        }
    }
}

impl ParseExt for AstWhileStmt {
    fn parse(root: pest::iterators::Pair<'_, Rule>) -> Self {
        let mut while_stmt = AstWhileStmt::new();
        for root_item in root.into_inner() {
            match root_item.as_rule() {
                Rule::LoopLabel => while_stmt.label = root_item.as_str().to_string(),
                Rule::MiddleExpr => while_stmt.cond_expr = AstExpr::parse_middle_expr(root_item),
                Rule::Stmt => while_stmt.stmts.push(AstStmt::parse(root_item)),
                _ => unreachable!(),
            }
        }
        while_stmt
    }
}
