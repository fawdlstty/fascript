use super::AstExpr;
use crate::ast::blocks::{func::AstFunc, program::AstProgram};
use crate::stmts::AstStmt;
use std::cell::RefCell;
use std::{collections::HashMap, rc::Rc};

#[derive(Clone, Debug)]
pub struct AstSwitchExpr {
    pub expr: Box<AstExpr>,
    pub conds: Vec<AstExpr>,
    pub values: Vec<AstExpr>,
}
