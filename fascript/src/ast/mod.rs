pub mod blocks;
pub mod exprs;
pub mod stmts;
pub mod types;
use self::types::AstType;
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
    fn get_arg_pair(self) -> (AstType, String);
    fn get_arg_pairs(self) -> (Vec<AstType>, Vec<String>);
}

impl PestApiExt for pest::iterators::Pair<'_, Rule> {
    fn get_id(self) -> String {
        match self.as_rule() {
            Rule::Id => self.as_str().to_string(),
            _ => self.into_inner().next().unwrap().get_id(),
        }
    }

    fn get_arg_pair(self) -> (AstType, String) {
        let mut type_item = AstType::new();
        let mut name_item = "".to_string();
        for root_item in self.into_inner() {
            match root_item.as_rule() {
                Rule::Type => type_item = AstType::parse(root_item),
                Rule::Id => name_item = root_item.get_id(),
                _ => unreachable!(),
            }
        }
        (type_item, name_item)
    }

    fn get_arg_pairs(self) -> (Vec<AstType>, Vec<String>) {
        let mut types = vec![];
        let mut names = vec![];
        for root_item in self.into_inner() {
            match root_item.as_rule() {
                Rule::ArgPair => {
                    let (type_item, name_item) = root_item.get_arg_pair();
                    types.push(type_item);
                    names.push(name_item);
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
