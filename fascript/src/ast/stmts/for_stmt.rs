use super::AstStmt;
use crate::ast::exprs::AstExpr;
use crate::ast::Parse3Ext;
use crate::ast::Rule;
#[derive(Clone, Debug)]
pub struct AstForStmt {
    pub label: String,
    pub iter_name: String,
    pub iter_items: AstExpr,
    pub stmts: Vec<AstStmt>,
}

impl AstForStmt {
    pub fn new() -> AstForStmt {
        AstForStmt {
            label: "".to_string(),
            iter_name: "".to_string(),
            iter_items: AstExpr::None,
            stmts: vec![],
        }
    }
}

impl Parse3Ext for AstForStmt {
    fn parse(root: pest::iterators::Pair<'_, Rule>) -> Vec<AstStmt> {
        let mut for_stmt = AstForStmt::new();
        for root_item in root.into_inner() {
            match root_item.as_rule() {
                Rule::LoopLabel => for_stmt.label = root_item.as_str().to_string(),
                Rule::Id => for_stmt.iter_name = root_item.as_str().to_string(),
                Rule::MiddleExpr => {
                    for_stmt.iter_items = AstExpr::parse_middle_expr(root_item);
                }
                Rule::IndexExpr => for_stmt.iter_items = AstExpr::parse_index_expr(root_item),
                Rule::Stmts => for_stmt.stmts = AstStmt::parse_stmts(root_item),
                _ => unreachable!(),
            }
        }
        vec![AstStmt::For(for_stmt)]
    }
}
