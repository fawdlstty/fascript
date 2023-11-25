mod module_os;

use self::module_os::ModuleOs;
use crate::ast::exprs::value_expr::FasValue;

pub struct BuiltIn {}

impl BuiltIn {
    pub fn init_modules() -> Vec<&'static str> {
        vec!["os"]
    }

    pub fn get_module(name: &str) -> FasValue {
        match name {
            "os" => FasValue::SMap(ModuleOs::make()),
            _ => unreachable!(),
        }
    }
}
