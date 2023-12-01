mod module_os;
mod module_test;

use self::module_os::ModuleOs;
use self::module_test::ModuleTest;
use crate::ast::exprs::value_expr::FasValue;

pub struct BuiltIn {}

impl BuiltIn {
    pub fn init_modules() -> Vec<&'static str> {
        vec!["os", "test"]
    }

    pub fn get_module(name: &str) -> FasValue {
        match name {
            "os" => FasValue::SMap(ModuleOs::make()),
            "test" => FasValue::SMap(ModuleTest::make()),
            _ => unreachable!(),
        }
    }
}
