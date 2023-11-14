use super::AstType;
use crate::ast::{ParseExt, Rule};

#[derive(Clone, Debug, Eq)]
pub struct AstMapType {
    pub key_type: Box<AstType>,
    pub val_type: Box<AstType>,
}

impl PartialEq for AstMapType {
    fn eq(&self, other: &Self) -> bool {
        *self.key_type == *other.key_type && *self.val_type == *other.val_type
    }
}

impl AstMapType {
    pub fn new(key_type: AstType, val_type: AstType) -> AstType {
        AstType::Map(AstMapType {
            key_type: Box::new(key_type),
            val_type: Box::new(val_type),
        })
    }
}

impl ParseExt for AstMapType {
    fn parse(root: pest::iterators::Pair<'_, Rule>) -> Self {
        let mut _temp_type = AstMapType {
            key_type: Box::new(AstType::Void),
            val_type: Box::new(AstType::Void),
        };
        let mut is_key = true;
        for root_item in root.into_inner() {
            match root_item.as_rule() {
                Rule::Type => match is_key {
                    true => {
                        _temp_type.key_type = Box::new(AstType::parse(root_item));
                        is_key = false;
                    }
                    false => _temp_type.val_type = Box::new(AstType::parse(root_item)),
                },
                _ => unreachable!(),
            }
        }
        _temp_type
    }
}
