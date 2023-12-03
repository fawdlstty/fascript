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
        let mut pre_stmts = vec![];
        let mut post_stmts = vec![];
        let mut while_stmt = AstWhileStmt::new();
        for root_item in root.into_inner() {
            match root_item.as_rule() {
                Rule::LoopLabel => while_stmt.label = root_item.as_str().to_string(),
                Rule::MiddleExpr => {
                    let expr = AstExpr::parse_middle_expr(root_item);
                    pre_stmts.extend(expr.0);
                    while_stmt.cond_expr = expr.1;
                    post_stmts.extend(expr.2);
                }
                Rule::Stmts => while_stmt.stmts = AstStmt::parse_stmts(root_item),
                _ => unreachable!(),
            }
        }
        while_stmt.stmts.extend(pre_stmts.clone());
        for post_stmt in post_stmts.iter().enumerate() {
            while_stmt.stmts.insert(post_stmt.0, post_stmt.1.clone());
        }
        pre_stmts.push(AstStmt::While(while_stmt));
        pre_stmts.extend(post_stmts);
        pre_stmts
    }
}
