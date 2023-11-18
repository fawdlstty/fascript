use crate::ast::{ParseExt, Rule};

#[derive(Clone, Debug)]
pub struct AstBreakStmt {
    pub label: String,
}

impl AstBreakStmt {
    pub fn new() -> AstBreakStmt {
        AstBreakStmt {
            label: "".to_string(),
        }
    }
}

impl ParseExt for AstBreakStmt {
    fn parse(root: pest::iterators::Pair<'_, Rule>) -> Self {
        let mut break_stmt = AstBreakStmt::new();
        for root_item in root.into_inner() {
            match root_item.as_rule() {
                Rule::Id => break_stmt.label = root_item.as_str().to_string(),
                _ => unreachable!(),
            }
        }
        break_stmt
    }
}
