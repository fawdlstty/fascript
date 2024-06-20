pub mod break_stmt;
pub mod continue_stmt;
pub mod dec_var_stmt;
pub mod do_while_stmt;
pub mod for_stmt;
pub mod if_stmt;
pub mod while_stmt;

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
use core::panic;

#[derive(Clone, Debug)]
pub enum AstStmt {
    Abort(AstExpr),
    Break(AstBreakStmt),
    Continue(AstContinueStmt),
    DefVar(AstDefVarStmt),
    DoWhile(AstDoWhileStmt),
    Expr(AstExpr),
    FinishTime(AstExpr),
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
                Rule::Expr => stmts.push(AstStmt::Return(AstExpr::parse(root_item))),
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
                Rule::CmdStmt => {
                    let mut cmd_name = "".to_string();
                    let mut payload_expr = AstExpr::None;
                    for cmd_item in root_item.into_inner() {
                        match cmd_item.as_rule() {
                            Rule::CmdStmtName => cmd_name = cmd_item.as_str().to_string(),
                            Rule::MiddleExpr => {
                                payload_expr = AstExpr::parse_middle_expr(cmd_item);
                            }
                            _ => unreachable!(),
                        }
                    }
                    vec![match &cmd_name[..] {
                        "abort" => AstStmt::Abort(payload_expr),
                        "finish_time" => AstStmt::FinishTime(payload_expr),
                        "return" => AstStmt::Return(payload_expr),
                        _ => unreachable!(),
                    }]
                }
                Rule::ContinueStmt => vec![AstStmt::Continue(AstContinueStmt::parse(root_item))],
                Rule::DoWhileStmt => AstDoWhileStmt::parse(root_item),
                Rule::WhileStmt => AstWhileStmt::parse(root_item),
                Rule::DefVarStmt => AstDefVarStmt::parse(root_item),
                Rule::ExprStmt => {
                    let expr = AstExpr::parse(root_item.into_inner().next().unwrap());
                    vec![AstStmt::Expr(expr)]
                }
                Rule::ForStmt => AstForStmt::parse(root_item),
                Rule::FuncStmt => {
                    let func = AstFunc::parse(root_item);
                    let stmt = AstDefVarStmt::new(
                        Some(func.get_type()),
                        func.get_name(),
                        AstExpr::Func(AstFuncExpr::new(func)),
                    );
                    vec![stmt]
                }
                Rule::TaskStmt => {
                    let func = AstFunc::parse(root_item);
                    let stmt = AstDefVarStmt::new(
                        Some(func.get_type()),
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
