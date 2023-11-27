mod break_stmt;
mod continue_stmt;
mod dec_var_stmt;
mod do_while_stmt;
mod for_stmt;
mod if_stmt;
mod while_stmt;

use self::break_stmt::AstBreakStmt;
use self::continue_stmt::AstContinueStmt;
use self::dec_var_stmt::AstDefVarStmt;
use self::do_while_stmt::AstDoWhileStmt;
use self::for_stmt::AstForStmt;
use self::if_stmt::AstIfStmt;
use self::while_stmt::AstWhileStmt;
use super::blocks::func::AstFunc;
use super::exprs::AstExpr;
use super::ParseExt;
use super::Rule;
use crate::ast::exprs::func_expr::AstFuncExpr;

#[derive(Clone, Debug)]
pub enum AstStmt {
    Break(AstBreakStmt),
    Continue(AstContinueStmt),
    DefVar(AstDefVarStmt),
    DoWhile(AstDoWhileStmt),
    Expr(AstExpr),
    For(AstForStmt),
    If(AstIfStmt),
    Return(AstExpr),
    While(AstWhileStmt),
}

impl AstStmt {
    pub fn parse_stmts(root: pest::iterators::Pair<'_, Rule>) -> Vec<AstStmt> {
        let mut stmts = vec![];
        for root_item in root.into_inner() {
            match root_item.as_rule() {
                Rule::Stmts => return Self::parse_stmts(root_item),
                Rule::Stmt => stmts.push(AstStmt::parse(root_item)),
                Rule::Expr => stmts.push(AstStmt::Return(AstExpr::parse(root_item))),
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
                Rule::BreakStmt => AstStmt::Break(AstBreakStmt::parse(root_item)),
                Rule::ContinueStmt => AstStmt::Continue(AstContinueStmt::parse(root_item)),
                Rule::DoWhileStmt => AstStmt::DoWhile(AstDoWhileStmt::parse(root_item)),
                Rule::WhileStmt => AstStmt::While(AstWhileStmt::parse(root_item)),
                Rule::DefVarStmt => AstStmt::DefVar(AstDefVarStmt::parse(root_item)),
                Rule::ExprStmt => {
                    AstStmt::Expr(AstExpr::parse(root_item.into_inner().next().unwrap()))
                }
                Rule::ForStmt => AstStmt::For(AstForStmt::parse(root_item)),
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
                Rule::IfStmt => AstStmt::If(AstIfStmt::parse(root_item)),
                _ => unreachable!(),
            },
            None => unreachable!(),
        }
    }
}
