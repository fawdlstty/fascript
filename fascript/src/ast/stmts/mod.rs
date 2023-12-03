mod break_stmt;
mod continue_stmt;
mod dec_var_stmt;
mod do_while_stmt;
mod for_stmt;
mod if_stmt;
mod while_stmt;

use core::panic;

use self::break_stmt::AstBreakStmt;
use self::continue_stmt::AstContinueStmt;
use self::dec_var_stmt::AstDefVarStmt;
use self::do_while_stmt::AstDoWhileStmt;
use self::for_stmt::AstForStmt;
use self::if_stmt::AstIfStmt;
use self::while_stmt::AstWhileStmt;
use super::blocks::func::AstFunc;
use super::exprs::AstExpr;
use super::Parse2Ext;
use super::Parse3Ext;
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
                Rule::Stmt => stmts.extend(AstStmt::parse(root_item)),
                Rule::Expr => {
                    let expr = AstExpr::parse(root_item);
                    if expr.2.len() > 0 {
                        panic!();
                    }
                    stmts.extend(expr.0);
                    stmts.push(AstStmt::Return(expr.1));
                }
                _ => unreachable!(),
            }
        }
        stmts
    }
}

impl Parse3Ext for AstStmt {
    fn parse(root: pest::iterators::Pair<'_, Rule>) -> Vec<AstStmt> {
        match root.into_inner().next() {
            Some(root_item) => match root_item.as_rule() {
                Rule::BreakStmt => vec![AstStmt::Break(AstBreakStmt::parse(root_item))],
                Rule::ContinueStmt => vec![AstStmt::Continue(AstContinueStmt::parse(root_item))],
                Rule::DoWhileStmt => AstDoWhileStmt::parse(root_item),
                Rule::WhileStmt => AstWhileStmt::parse(root_item),
                Rule::DefVarStmt => AstDefVarStmt::parse(root_item),
                Rule::ExprStmt => {
                    let expr = AstExpr::parse(root_item.into_inner().next().unwrap());
                    let mut stmts = vec![];
                    stmts.extend(expr.0);
                    stmts.push(AstStmt::Expr(expr.1));
                    stmts.extend(expr.2);
                    stmts
                }
                Rule::ForStmt => AstForStmt::parse(root_item),
                Rule::FuncStmt => {
                    //return AstStmt::Expr(AstExpr::parse(root_item.into_inner().next().unwrap()))
                    let func = AstFunc::parse(root_item);
                    let stmt = AstDefVarStmt::new(
                        func.get_type(),
                        func.get_name(),
                        AstExpr::Func(AstFuncExpr::new(func)),
                    );
                    vec![stmt]
                }
                Rule::IfStmt => AstIfStmt::parse(root_item),
                _ => unreachable!(),
            },
            None => unreachable!(),
        }
    }
}
