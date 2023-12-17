use super::ParseExt;
use super::Rule;

#[derive(Clone, Debug, Eq, PartialEq)]
pub enum AstType {
    None,
    Array,
    Bool,
    DateTime,
    Float,
    Func(usize),
    Future,
    Index,
    Int,
    IMap,
    SMap,
    String,
    TimeSpan,
    Tuple(usize),
    Void,
    Task,
    TaskResult,
}

impl AstType {
    pub fn new() -> AstType {
        AstType::None
    }

    pub fn parse_str(type_name: String) -> AstType {
        match &type_name[..] {
            "void" => AstType::Void,
            "bool" => AstType::Bool,
            "datetime" => AstType::DateTime,
            "float" => AstType::Float,
            "int" => AstType::Int,
            "string" => AstType::String,
            "task" => AstType::Task,
            "timespan" => AstType::TimeSpan,
            _ => unreachable!(),
        }
    }
}

impl ParseExt for AstType {
    fn parse(root: pest::iterators::Pair<'_, Rule>) -> Self {
        let mut _temp_type = AstType::None;
        for root_item in root.into_inner() {
            match root_item.as_rule() {
                Rule::VoidType => _temp_type = AstType::Void,
                Rule::BaseType => {
                    let tmp_item = root_item.into_inner().next().unwrap();
                    match tmp_item.as_rule() {
                        Rule::BaseTypeStr => {
                            _temp_type = Self::parse_str(tmp_item.as_str().to_string())
                        }
                        _ => unreachable!(),
                    }
                }
                //Rule::TupleType => _temp_type = AstType::Tuple(AstTupleType::parse(root_item)),
                //Rule::TypeSuffix => {
                //    _temp_type = AstOp1Type::new(_temp_type, root_item.as_str().to_string())
                //}
                _ => unreachable!(),
            }
        }
        _temp_type
    }
}
