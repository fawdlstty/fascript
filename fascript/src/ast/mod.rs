pub mod blocks;
pub mod exprs;
pub mod stmts;
pub mod types;

use self::stmts::AstStmt;
pub use pest::Parser;
pub use pest_derive::Parser;

#[derive(Parser)]
#[grammar = "../fa.pest"]
pub struct FaParser;

pub trait FromStringExt: Sized {
    fn from_str(code: &str) -> Result<Self, pest::error::Error<Rule>>;
}

pub trait PestApiExt {
    fn get_id(self) -> String;
    fn get_ids(self) -> Vec<String>;
}

impl PestApiExt for pest::iterators::Pair<'_, Rule> {
    fn get_id(self) -> String {
        match self.as_rule() {
            Rule::Id => self.as_str().to_string(),
            Rule::Ids => self.as_str().to_string(),
            _ => self.into_inner().next().unwrap().get_id(),
        }
    }

    fn get_ids(self) -> Vec<String> {
        let mut names = vec![];
        for root_item in self.into_inner() {
            match root_item.as_rule() {
                Rule::Id => names.push(root_item.get_id()),
                _ => unreachable!(),
            }
        }
        names
    }
}

pub trait ParseExt {
    fn parse(root: pest::iterators::Pair<'_, Rule>) -> Self;
}

pub trait Parse2Ext {
    fn parse(root: pest::iterators::Pair<'_, Rule>) -> (Vec<AstStmt>, Self, Vec<AstStmt>)
    where
        Self: Sized;
}

pub trait Parse3Ext {
    fn parse(root: pest::iterators::Pair<'_, Rule>) -> Vec<AstStmt>
    where
        Self: Sized;
}
