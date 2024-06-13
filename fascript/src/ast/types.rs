use super::Rule;

#[derive(Clone, Debug, Eq, PartialEq)]
pub enum AstType {
    None,
    Any,
    Array(Box<AstType>),
    Bool,
    DateTime,
    Float,
    Func((Box<AstType>, Vec<AstType>)),
    Future(Box<AstType>),
    Index,
    Int,
    Map((Box<AstType>, Box<AstType>)),
    Option(Box<AstType>),
    String,
    TimeSpan,
    Tuple(Vec<AstType>),
    Void,
    Task,
    TaskResult,
}

impl AstType {
    pub fn parse(root: pest::iterators::Pair<'_, Rule>) -> AstType {
        let mut base_type = AstType::None;
        for root_item in root.into_inner() {
            match root_item.as_rule() {
                Rule::Type => return Self::parse(root_item),
                Rule::VoidType => return AstType::None,
                Rule::BaseType => base_type = Self::parse_base_type(root_item),
                Rule::TypeSuffix => match root_item.as_str() {
                    "[]" => base_type = AstType::Array(Box::new(base_type)),
                    "?" => base_type = AstType::Option(Box::new(base_type)),
                    _ => unreachable!(),
                },
                _ => unreachable!(),
            }
        }
        base_type
    }

    pub fn parses(root: pest::iterators::Pair<'_, Rule>) -> Vec<AstType> {
        let mut types = vec![];
        for root_item in root.into_inner() {
            match root_item.as_rule() {
                Rule::Type => types.push(Self::parse_base_type(root_item)),
                _ => unreachable!(),
            }
        }
        types
    }

    pub fn parse_base_type(root: pest::iterators::Pair<'_, Rule>) -> AstType {
        let root = root.into_inner().next().unwrap();
        match root.as_rule() {
            Rule::BaseTypeStr => Self::parse_str(root.as_str()),
            Rule::MapType => {
                let types = Self::parses(root);
                AstType::Map((Box::new(types[0].clone()), Box::new(types[1].clone())))
            }
            Rule::TupleType => {
                let types = Self::parses(root);
                AstType::Tuple(types)
            }
            Rule::FuncType => {
                let mut ret_type = AstType::Void;
                let mut arg_types = vec![];
                for root_item in root.into_inner() {
                    match root_item.as_rule() {
                        Rule::Type => arg_types.push(Self::parse_base_type(root_item)),
                        _ => unreachable!(),
                    }
                }
                AstType::Func((Box::new(ret_type), arg_types))
            }
            _ => unreachable!(),
        }
    }

    pub fn parse_str(type_name: &str) -> AstType {
        match &type_name[..] {
            "void" => AstType::Void,
            "any" => AstType::Any,
            "bool" => AstType::Bool,
            "datetime" => AstType::DateTime,
            "float" => AstType::Float,
            //"func" => AstType::Func(_),
            //"future" => AstType::Future,
            "index" => AstType::Index,
            "int" => AstType::Int,
            "string" => AstType::String,
            //"task" => AstType::Task,
            "timespan" => AstType::TimeSpan,
            _ => unreachable!(),
        }
    }

    pub fn get_str(&self) -> String {
        match self {
            AstType::None => "(none)".to_string(),
            AstType::Any => "any".to_string(),
            AstType::Array(item_type) => format!("array<{}>", item_type.get_str()),
            AstType::Bool => "bool".to_string(),
            AstType::DateTime => "datetime".to_string(),
            AstType::Float => "float".to_string(),
            AstType::Func((ret_type, arg_types)) => format!(
                "func({}) -> {}",
                arg_types.get_strs().join(", "),
                ret_type.get_str()
            ),
            AstType::Future(ret_type) => format!("future<{}>", ret_type.get_str()),
            AstType::Index => "index".to_string(),
            AstType::Int => "int".to_string(),
            AstType::Map((key_type, val_type)) => {
                format!("map<{}, {}>", key_type.get_str(), val_type.get_str())
            }
            AstType::Option(val_type) => format!("{}?", val_type.get_str()),
            AstType::String => "string".to_string(),
            AstType::TimeSpan => "timespan".to_string(),
            AstType::Tuple(types) => format!("tuple({})", types.get_strs().join(", ")),
            AstType::Void => "void".to_string(),
            AstType::Task => "task".to_string(),
            AstType::TaskResult => "taskresult".to_string(),
        }
    }
}

pub trait GetStrsExt {
    fn get_strs(&self) -> Vec<String>;
}

impl GetStrsExt for Vec<AstType> {
    fn get_strs(&self) -> Vec<String> {
        self.iter().map(|arg_type| arg_type.get_str()).collect()
    }
}
