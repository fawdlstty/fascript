use super::AstType;
use crate::ast::{ParseExt, Rule};

#[derive(Clone, Debug, Eq)]
pub struct AstTupleType {
    pub items: Vec<AstType>,
}

impl PartialEq for AstTupleType {
    fn eq(&self, other: &Self) -> bool {
        self.items == other.items
    }
}

impl ParseExt for AstTupleType {
    fn parse(root: pest::iterators::Pair<'_, Rule>) -> Self {
        let mut _temp_type = AstTupleType { items: vec![] };
        for root_item in root.into_inner() {
            match root_item.as_rule() {
                Rule::Type => _temp_type.items.push(AstType::parse(root_item)),
                _ => unreachable!(),
            }
        }
        _temp_type
    }
}
