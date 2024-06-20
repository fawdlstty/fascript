use super::AstStmt;
use crate::ast::{exprs::AstExpr, Parse3Ext, Rule};

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

impl Parse3Ext for AstWhileStmt {
    fn parse(root: pest::iterators::Pair<'_, Rule>) -> Vec<AstStmt> {
        let mut while_stmt = AstWhileStmt::new();
        for root_item in root.into_inner() {
            match root_item.as_rule() {
                Rule::LoopLabel => while_stmt.label = root_item.as_str().to_string(),
                Rule::MiddleExpr => while_stmt.cond_expr = AstExpr::parse_middle_expr(root_item),
                Rule::Stmts => while_stmt.stmts = AstStmt::parse_stmts(root_item),
                _ => unreachable!(),
            }
        }
        vec![AstStmt::While(while_stmt)]
    }
}
