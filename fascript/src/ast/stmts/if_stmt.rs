use super::AstStmt;
use crate::ast::{exprs::AstExpr, ParseExt, Rule};

#[derive(Clone, Debug)]
pub struct AstIfStmt {
    pub con_exprs: Vec<AstExpr>,
    pub stmtss: Vec<Vec<AstStmt>>,
}

impl AstIfStmt {
    pub fn new() -> AstIfStmt {
        AstIfStmt {
            con_exprs: vec![],
            stmtss: vec![],
        }
    }

    fn parse_if_part(root: pest::iterators::Pair<'_, Rule>) -> (AstExpr, Vec<AstStmt>) {
        let mut condition_expr = AstExpr::None;
        let mut stmts = vec![];
        for root_item in root.into_inner() {
            match root_item.as_rule() {
                Rule::MiddleExpr => condition_expr = AstExpr::parse_middle_expr(root_item),
                Rule::Stmt => stmts.push(AstStmt::parse(root_item)),
                _ => unreachable!(),
            }
        }
        (condition_expr, stmts)
    }

    fn parse_if_end_part(root: pest::iterators::Pair<'_, Rule>) -> Vec<AstStmt> {
        let mut stmts = vec![];
        for root_item in root.into_inner() {
            match root_item.as_rule() {
                Rule::Stmt => stmts.push(AstStmt::parse(root_item)),
                _ => unreachable!(),
            }
        }
        stmts
    }
}

impl ParseExt for AstIfStmt {
    fn parse(root: pest::iterators::Pair<'_, Rule>) -> Self {
        let mut if_stmt = AstIfStmt::new();
        for root_item in root.into_inner() {
            match root_item.as_rule() {
                Rule::IfPart => {
                    let (condition_expr, stmts) = Self::parse_if_part(root_item);
                    if_stmt.con_exprs.push(condition_expr);
                    if_stmt.stmtss.push(stmts);
                }
                Rule::IfEndPart => {
                    let stmts = Self::parse_if_end_part(root_item);
                    if_stmt.stmtss.push(stmts);
                }
                _ => unreachable!(),
            }
        }
        if_stmt
    }
}
