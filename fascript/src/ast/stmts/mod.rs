mod dec_var_stmt;
mod for_stmt;

use self::dec_var_stmt::AstDefVarStmt;
use self::for_stmt::AstForStmt;
use super::blocks::func::AstFunc;
use super::exprs::AstExpr;
use super::ParseExt;
use super::Rule;
use crate::ast::exprs::func_expr::AstFuncExpr;

#[derive(Clone, Debug)]
pub enum AstStmt {
    DefVar(AstDefVarStmt),
    Expr(AstExpr),
    For(AstForStmt),
}

impl AstStmt {
    pub fn parse_func_body(root: pest::iterators::Pair<'_, Rule>) -> Vec<AstStmt> {
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

impl ParseExt for AstStmt {
    fn parse(root: pest::iterators::Pair<'_, Rule>) -> Self {
        match root.into_inner().next() {
            Some(root_item) => match root_item.as_rule() {
                Rule::DefVarStmt => return AstStmt::DefVar(AstDefVarStmt::parse(root_item)),
                Rule::ForStmt => return AstStmt::For(AstForStmt::parse(root_item)),
                Rule::FuncStmt => {
                    //return AstStmt::Expr(AstExpr::parse(root_item.into_inner().next().unwrap()))
                    let func = AstFunc::parse(root_item);
                    let stmt = AstDefVarStmt::new(
                        func.get_type(),
                        func.get_name(),
                        AstExpr::Func(AstFuncExpr::new(func)),
                    );
                    stmt
                }
                Rule::ExprStmt => {
                    return AstStmt::Expr(AstExpr::parse(root_item.into_inner().next().unwrap()))
                }
                _ => unreachable!(),
            },
            None => unreachable!(),
        }
    }
}
