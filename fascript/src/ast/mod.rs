pub mod blocks;
pub mod exprs;
pub mod stmts;
pub mod types;

use self::stmts::AstStmt;
pub use pest::Parser;
pub use pest_derive::Parser;
use types::AstType;

#[derive(Parser)]
#[grammar = "../fa.pest"]
pub struct FaParser;

pub trait FromStringExt: Sized {
    fn from_str(code: &str) -> Result<Self, pest::error::Error<Rule>>;
}

pub trait PestApiExt {
    fn get_id(self) -> String;
    fn get_type_id(self) -> (AstType, String);
    fn get_type_ids(self) -> (Vec<AstType>, Vec<String>);
}

impl PestApiExt for pest::iterators::Pair<'_, Rule> {
    fn get_id(self) -> String {
        match self.as_rule() {
            Rule::Id => self.as_str().trim().to_string(),
            Rule::Ids => {
                let mut ids = "".to_string();
                for root_item in self.into_inner() {
                    let tmp = root_item.get_id();
                    if !ids.is_empty() {
                        ids.push('.');
                    }
                    ids.push_str(&tmp);
                }
                ids
            }
            _ => self.into_inner().next().unwrap().get_id(),
        }
    }

    fn get_type_id(self) -> (AstType, String) {
        let mut type_ = AstType::Any;
        let mut name_ = "".to_string();
        for root_item in self.into_inner() {
            match root_item.as_rule() {
                Rule::Type => type_ = AstType::parse(root_item),
                Rule::Id => name_ = root_item.get_id(),
                _ => unreachable!(),
            }
        }
        (type_, name_)
    }

    fn get_type_ids(self) -> (Vec<AstType>, Vec<String>) {
        let mut types = vec![];
        let mut names = vec![];
        for root_item in self.into_inner() {
            match root_item.as_rule() {
                Rule::TypeIdPair => {
                    let (type_, name_) = root_item.get_type_id();
                    types.push(type_);
                    names.push(name_);
                }
                _ => unreachable!(),
            }
        }
        (types, names)
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
