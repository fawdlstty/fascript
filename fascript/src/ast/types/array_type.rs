use super::AstType;
use crate::ast::{ParseExt, Rule};

#[derive(Clone, Debug, Eq)]
pub struct AstArrayType {
    pub base_type: Box<AstType>,
}

impl PartialEq for AstArrayType {
    fn eq(&self, other: &Self) -> bool {
        *self.base_type == *other.base_type
    }
}

impl AstArrayType {
    pub fn new(base_type: AstType) -> AstType {
        AstType::Array(AstArrayType {
            base_type: Box::new(base_type),
        })
    }
}

impl ParseExt for AstArrayType {
    fn parse(root: pest::iterators::Pair<'_, Rule>) -> Self {
        let mut _temp_type = AstArrayType {
            base_type: Box::new(AstType::Void),
        };
        for root_item in root.into_inner() {
            match root_item.as_rule() {
                Rule::Type => _temp_type.base_type = Box::new(AstType::parse(root_item)),
                _ => unreachable!(),
            }
        }
        _temp_type
    }
}
