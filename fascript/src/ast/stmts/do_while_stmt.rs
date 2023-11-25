use super::AstStmt;
use crate::ast::{exprs::AstExpr, ParseExt, Rule};

#[derive(Clone, Debug)]
pub struct AstDoWhileStmt {
    pub label: String,
    pub cond_expr: AstExpr,
    pub stmts: Vec<AstStmt>,
}

impl AstDoWhileStmt {
    pub fn new() -> AstDoWhileStmt {
        AstDoWhileStmt {
            label: "".to_string(),
            cond_expr: AstExpr::None,
            stmts: vec![],
        }
    }
}

impl ParseExt for AstDoWhileStmt {
    fn parse(root: pest::iterators::Pair<'_, Rule>) -> Self {
        let mut do_while_stmt = AstDoWhileStmt::new();
        for root_item in root.into_inner() {
            match root_item.as_rule() {
                Rule::LoopLabel => do_while_stmt.label = root_item.as_str().to_string(),
                Rule::MiddleExpr => do_while_stmt.cond_expr = AstExpr::parse_middle_expr(root_item),
                Rule::Stmts => do_while_stmt.stmts = AstStmt::parse_stmts(root_item),
                _ => unreachable!(),
            }
        }
        do_while_stmt
    }
}
