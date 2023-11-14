use super::AstType;
use crate::ast::{ParseExt, Rule};

#[derive(Clone, Debug, Eq)]
pub struct AstFuncType {
    pub ret_type: Box<AstType>,
    pub arg_types: Vec<AstType>,
}

impl PartialEq for AstFuncType {
    fn eq(&self, other: &Self) -> bool {
        *self.ret_type == *other.ret_type && self.arg_types == other.arg_types
    }
}

impl AstFuncType {
    pub fn new(arg_types: Vec<AstType>, ret_type: AstType) -> AstType {
        AstType::Func(AstFuncType {
            ret_type: Box::new(ret_type),
            arg_types: arg_types,
        })
    }
}

impl ParseExt for AstFuncType {
    fn parse(root: pest::iterators::Pair<'_, Rule>) -> Self {
        let mut _temp_type = AstFuncType {
            ret_type: Box::new(AstType::Void),
            arg_types: vec![],
        };
        for root_item in root.into_inner() {
            match root_item.as_rule() {
                Rule::Type => _temp_type.arg_types.push(AstType::parse(root_item)),
                _ => unreachable!(),
            }
        }
        _temp_type.ret_type = Box::new(_temp_type.arg_types.pop().unwrap());
        _temp_type
    }
}
