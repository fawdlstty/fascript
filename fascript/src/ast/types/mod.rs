pub mod array_type;
pub mod func_type;
pub mod map_type;
pub mod tuple_type;
use self::array_type::AstArrayType;
use self::func_type::AstFuncType;
use self::map_type::AstMapType;
use self::tuple_type::AstTupleType;
use super::{ParseExt, Rule};

#[derive(Clone, Debug, Eq, PartialEq)]
pub enum AstType {
    None,
    Array(AstArrayType),
    Bool,
    Dynamic,
    Float,
    Func(AstFuncType),
    Index,
    Int,
    Map(AstMapType),
    String,
    Tuple(AstTupleType),
    Void,
    Task,
}

impl AstType {
    pub fn new() -> AstType {
        AstType::None
    }

    pub fn parse_str(type_name: String) -> AstType {
        match &type_name[..] {
            "bool" => AstType::Bool,
            "dynamic" => AstType::Dynamic,
            "float" => AstType::Float,
            "int" => AstType::Int,
            "string" => AstType::String,
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
