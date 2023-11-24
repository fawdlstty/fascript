use crate::ast::exprs::value_expr::FasValue;
use crate::ast::stmts::AstStmt;
use crate::ast::types::{func_type::AstFuncType, AstType};
use crate::{ast::*, FasCallable};
use std::fmt::Debug;
use std::sync::Arc;

#[derive(Clone, Debug)]
pub enum AstFunc {
    AstNativeFunc(AstNativeFunc),
    AstManagedFunc(AstManagedFunc),
}

impl AstFunc {
    pub fn get_ret_type(&self) -> AstType {
        match self {
            AstFunc::AstNativeFunc(func) => func.ret_type.clone(),
            AstFunc::AstManagedFunc(func) => func.ret_type.clone(),
        }
    }

    pub fn get_name(&self) -> String {
        match self {
            AstFunc::AstNativeFunc(func) => func.name.clone(),
            AstFunc::AstManagedFunc(func) => func.name.clone(),
        }
    }

    pub fn get_arg_types(&self) -> Vec<AstType> {
        match self {
            AstFunc::AstNativeFunc(func) => func.arg_types.clone(),
            AstFunc::AstManagedFunc(func) => func.arg_types.clone(),
        }
    }

    pub fn get_arg_names(&self) -> Vec<String> {
        match self {
            AstFunc::AstNativeFunc(func) => func.arg_types.iter().map(|_| "".to_string()).collect(),
            AstFunc::AstManagedFunc(func) => func.arg_names.clone(),
        }
    }

    pub fn get_type(&self) -> AstType {
        AstFuncType::new(self.get_arg_types(), self.get_ret_type())
    }
}

impl ParseExt for AstFunc {
    fn parse(root: pest::iterators::Pair<'_, Rule>) -> Self {
        AstFunc::AstManagedFunc(AstManagedFunc::parse(root))
    }
}

//#[derive(Clone)]
pub struct AstNativeFunc {
    pub ret_type: AstType,
    pub name: String,
    pub arg_types: Vec<AstType>,
    pub func_impl: Box<dyn FasCallable>,
}

impl Clone for AstNativeFunc {
    fn clone(&self) -> Self {
        Self {
            ret_type: self.ret_type.clone(),
            name: self.name.clone(),
            arg_types: self.arg_types.clone(),
            func_impl: self.func_impl.clone(),
        }
    }
}

impl Debug for AstNativeFunc {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        f.debug_struct("AstNativeFunc")
            .field("ret_type", &self.ret_type)
            .field("name", &self.name)
            .field("arg_types", &self.arg_types)
            .finish()
    }
}

#[derive(Clone, Debug)]
pub struct AstManagedFunc {
    pub ret_type: AstType,
    pub name: String,
    pub arg_types: Vec<AstType>,
    pub arg_names: Vec<String>,
    pub body_stmts: Vec<AstStmt>,
}

impl ParseExt for AstManagedFunc {
    fn parse(root: pest::iterators::Pair<'_, Rule>) -> Self {
        let mut _func = AstManagedFunc {
            ret_type: AstType::new(),
            name: "".to_string(),
            arg_types: vec![],
            arg_names: vec![],
            body_stmts: vec![],
        };
        for root_item in root.into_inner() {
            match root_item.as_rule() {
                Rule::Type => _func.ret_type = AstType::parse(root_item),
                Rule::Id => _func.name = root_item.get_id(),
                Rule::ArgPairs => (_func.arg_types, _func.arg_names) = root_item.get_arg_pairs(),
                Rule::FuncBody => _func.body_stmts = AstStmt::parse_func_body(root_item),
                _ => {
                    println!("{:?}", root_item.as_rule());
                    unreachable!();
                }
            }
        }
        _func
    }
}
