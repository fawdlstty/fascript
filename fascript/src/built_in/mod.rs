mod module_os;
mod module_test;
mod module_type_float;
mod module_type_int;

use self::module_os::ModuleOs;
use self::module_test::ModuleTest;
use self::module_type_float::ModuleTypeFloat;
use self::module_type_int::ModuleTypeInt;
use crate::ast::exprs::value_expr::FasValue;
use crate::ast::types::AstType;

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

    pub fn access_type_member(obj_type: AstType, member_name: &str) -> FasValue {
        match obj_type.get_str() {
            "int" => {
                let binding = ModuleTypeInt::make();
                binding.get(member_name).unwrap().clone()
            }
            "float" => {
                let binding = ModuleTypeFloat::make();
                binding.get(member_name).unwrap().clone()
            }
            _ => unreachable!(),
        }
    }
}
