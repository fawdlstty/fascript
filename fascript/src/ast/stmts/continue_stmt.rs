use crate::ast::{ParseExt, Rule};

#[derive(Clone, Debug)]
pub struct AstContinueStmt {
    pub label: String,
}

impl AstContinueStmt {
    pub fn new() -> AstContinueStmt {
        AstContinueStmt {
            label: "".to_string(),
        }
    }
}

impl ParseExt for AstContinueStmt {
    fn parse(root: pest::iterators::Pair<'_, Rule>) -> Self {
        let mut continue_stmt = AstContinueStmt::new();
        for root_item in root.into_inner() {
            match root_item.as_rule() {
                Rule::Id => continue_stmt.label = root_item.as_str().to_string(),
                _ => unreachable!(),
            }
        }
        continue_stmt
    }
}
