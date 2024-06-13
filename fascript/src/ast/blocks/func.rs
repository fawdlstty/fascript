use super::anno::AstAnnoPart;
use super::anno::AstAnnoParts;
use crate::ast::stmts::AstStmt;
use crate::ast::types::AstType;
use crate::ast::ParseExt;
use crate::ast::PestApiExt;
use crate::ast::Rule;
use crate::FasCallable;
use lazy_static::lazy_static;
use std::fmt::Debug;
use std::sync::Mutex;

pub enum AstFunc {
    NativeFunc(Box<dyn FasCallable>),
    FasFunc(FasFunc),
    FasTask(FasTask),
}

impl AstFunc {
    pub fn parse_lambda(root: pest::iterators::Pair<'_, Rule>) -> Self {
        AstFunc::FasFunc(FasFunc::parse_lambda(root))
    }

    pub fn get_name(&self) -> String {
        match self {
            AstFunc::NativeFunc(_) => "".to_string(),
            AstFunc::FasFunc(func) => func.name.clone(),
            AstFunc::FasTask(task) => task.name.clone(),
        }
    }

    pub fn get_type(&self) -> AstType {
        match self {
            AstFunc::NativeFunc(nfunc) => nfunc.get_type(),
            AstFunc::FasFunc(func) => func.get_type(),
            AstFunc::FasTask(task) => task.get_type(),
        }
    }

    pub fn get_arg_count(&self) -> usize {
        match self {
            AstFunc::NativeFunc(nfunc) => nfunc.get_arg_count(),
            AstFunc::FasFunc(func) => func.arg_names.len(),
            AstFunc::FasTask(task) => task.arg_names.len(),
        }
    }
}

impl ParseExt for AstFunc {
    fn parse(root: pest::iterators::Pair<'_, Rule>) -> Self {
        match root.as_rule() {
            Rule::FuncStmt => AstFunc::FasFunc(FasFunc::parse(root)),
            Rule::TaskStmt => AstFunc::FasTask(FasTask::parse(root)),
            _ => unreachable!(),
        }
    }
}

impl Clone for AstFunc {
    fn clone(&self) -> Self {
        match self {
            Self::NativeFunc(arg0) => Self::NativeFunc(arg0.clone_()),
            Self::FasFunc(arg0) => Self::FasFunc(arg0.clone()),
            Self::FasTask(arg0) => Self::FasTask(arg0.clone()),
        }
    }
}

impl Debug for AstFunc {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            Self::NativeFunc(_arg0) => f.debug_struct("NativeFunc").finish(),
            Self::FasFunc(arg0) => f.debug_tuple("FasFunc").field(arg0).finish(),
            Self::FasTask(arg0) => f.debug_tuple("FasTask").field(arg0).finish(),
        }
    }
}

#[derive(Clone, Debug)]
pub struct FasFunc {
    pub name: String,
    pub arg_types: Vec<AstType>,
    pub arg_names: Vec<String>,
    pub ret_type: AstType,
    pub body_stmts: Vec<AstStmt>,
}

impl ParseExt for FasFunc {
    fn parse(root: pest::iterators::Pair<'_, Rule>) -> Self {
        let mut _func = FasFunc {
            name: "".to_string(),
            arg_types: vec![],
            arg_names: vec![],
            ret_type: AstType::Any,
            body_stmts: vec![],
        };
        for root_item in root.into_inner() {
            match root_item.as_rule() {
                Rule::Id => _func.name = root_item.get_id(),
                Rule::Args => (_func.arg_types, _func.arg_names) = root_item.get_type_ids(),
                Rule::FuncBody => _func.body_stmts = AstStmt::parse_stmts(root_item),
                _ => unreachable!(),
            }
        }
        _func
    }
}

impl FasFunc {
    pub fn new() -> Self {
        FasFunc {
            name: "".to_string(),
            arg_types: vec![],
            arg_names: vec![],
            body_stmts: vec![],
            ret_type: AstType::Any,
        }
    }

    pub fn parse_lambda(root: pest::iterators::Pair<'_, Rule>) -> Self {
        let mut _func = Self::new();
        for root_item in root.into_inner() {
            match root_item.as_rule() {
                Rule::Id => {
                    _func.arg_names.push(root_item.get_id());
                }
                Rule::Args => (_func.arg_types, _func.arg_names) = root_item.get_type_ids(),
                Rule::FuncBody => _func.body_stmts = AstStmt::parse_stmts(root_item),
                _ => unreachable!(),
            }
        }
        _func
    }

    fn get_type(&self) -> AstType {
        AstType::Func((Box::new(self.ret_type.clone()), self.arg_types.clone()))
    }
}

#[derive(Clone, Debug)]
pub struct FasTask {
    pub annos: AstAnnoParts,
    pub name: String,
    pub arg_types: Vec<AstType>,
    pub arg_names: Vec<String>,
    pub ret_type: AstType,
    pub body_stmts: Vec<AstStmt>,
}

impl ParseExt for FasTask {
    fn parse(root: pest::iterators::Pair<'_, Rule>) -> Self {
        let mut _func = FasTask {
            annos: AstAnnoParts::new(),
            name: "".to_string(),
            arg_types: vec![],
            arg_names: vec![],
            body_stmts: vec![],
            ret_type: AstType::Any,
        };
        for root_item in root.into_inner() {
            match root_item.as_rule() {
                Rule::AnnoPart => _func.annos.push(AstAnnoPart::parse(root_item)),
                Rule::Id => _func.name = root_item.get_id(),
                Rule::Args => (_func.arg_types, _func.arg_names) = root_item.get_type_ids(),
                Rule::FuncBody => _func.body_stmts = AstStmt::parse_stmts(root_item),
                _ => unreachable!(),
            }
        }
        _func
    }
}

impl FasTask {
    fn get_type(&self) -> AstType {
        AstType::Func((Box::new(self.ret_type.clone()), self.arg_types.clone()))
    }
}

lazy_static! {
    static ref ENTRY_INC: Mutex<i32> = Mutex::new(0);
}
