use crate::ast::{stmts::AstStmt, *};
use pest::Parser;

#[derive(Clone, Debug)]
pub struct AstProgram {
    pub stmts: Vec<AstStmt>,
}

impl ParseExt for AstProgram {
    fn parse(root: pest::iterators::Pair<'_, Rule>) -> Self {
        let mut _program = AstProgram { stmts: vec![] };
        for root_item in root.into_inner() {
            match root_item.as_rule() {
                Rule::Stmts => _program.stmts = AstStmt::parse_stmts(root_item),
                Rule::EOI => (),
                _ => unreachable!(),
            }
        }
        _program
    }
    //
}

impl FromStringExt for AstProgram {
    fn from_str(code: &str) -> Result<AstProgram, pest::error::Error<Rule>> {
        let root = match FaParser::parse(Rule::ProgramFile, code) {
            Ok(root) => root,
            Err(err) => return Err(err),
        }
        .next()
        .unwrap();
        Ok(Self::parse(root))
    }
}
