#[derive(Clone, Debug, Eq, PartialEq)]
pub enum AstType {
    None,
    Any,
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
    // pub fn new() -> AstType {
    //     AstType::None
    // }

    // pub fn parse_str(type_name: String) -> AstType {
    //     match &type_name[..] {
    //         "void" => AstType::Void,
    //         "array" => AstType::Array,
    //         "bool" => AstType::Bool,
    //         "datetime" => AstType::DateTime,
    //         "float" => AstType::Float,
    //         //"func" => AstType::Func(_),
    //         "future" => AstType::Future,
    //         "index" => AstType::Index,
    //         "int" => AstType::Int,
    //         "string" => AstType::String,
    //         "task" => AstType::Task,
    //         "timespan" => AstType::TimeSpan,
    //         _ => unreachable!(),
    //     }
    // }

    pub fn get_str(&self) -> &'static str {
        match self {
            AstType::None => "(none)",
            AstType::Any => "any",
            AstType::Array => "array",
            AstType::Bool => "bool",
            AstType::DateTime => "datetime",
            AstType::Float => "float",
            AstType::Func(_) => "func",
            AstType::Future => "future",
            AstType::Index => "index",
            AstType::Int => "int",
            AstType::IMap => "imap",
            AstType::SMap => "smap",
            AstType::String => "string",
            AstType::TimeSpan => "timespan",
            AstType::Tuple(_) => "tuple",
            AstType::Void => "void",
            AstType::Task => "task",
            AstType::TaskResult => "taskresult",
        }
    }
}
