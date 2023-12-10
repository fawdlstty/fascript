use super::AstType;
use crate::ast::{ParseExt, Rule};

#[derive(Clone, Debug, Eq)]
pub struct AstFuncType {
    pub arg_count: usize,
}

impl PartialEq for AstFuncType {
    fn eq(&self, other: &Self) -> bool {
        self.arg_count == other.arg_count
    }
}

impl AstFuncType {
    pub fn new(arg_count: usize) -> AstType {
        AstType::Func(AstFuncType { arg_count })
    }
}
