use super::AstStmt;
use crate::ast::exprs::AstExpr;
use crate::ast::Parse3Ext;
use crate::ast::Rule;

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

impl Parse3Ext for AstDoWhileStmt {
    fn parse(root: pest::iterators::Pair<'_, Rule>) -> Vec<AstStmt> {
        let mut pre_stmts = vec![];
        let mut post_stmts = vec![];
        let mut do_while_stmt = AstDoWhileStmt::new();
        for root_item in root.into_inner() {
            match root_item.as_rule() {
                Rule::LoopLabel => do_while_stmt.label = root_item.as_str().to_string(),
                Rule::MiddleExpr => {
                    let expr = AstExpr::parse_middle_expr(root_item);
                    pre_stmts.extend(expr.0);
                    do_while_stmt.cond_expr = expr.1;
                    post_stmts.extend(expr.2);
                }
                Rule::Stmts => do_while_stmt.stmts = AstStmt::parse_stmts(root_item),
                _ => unreachable!(),
            }
        }
        //
        do_while_stmt.stmts.extend(pre_stmts.clone());
        for post_stmt in post_stmts.iter().enumerate() {
            do_while_stmt.stmts.insert(post_stmt.0, post_stmt.1.clone());
        }
        //
        let mut stmts = vec![];
        stmts.extend(pre_stmts);
        stmts.push(AstStmt::DoWhile(do_while_stmt));
        stmts.extend(post_stmts);
        stmts
    }
}
