use super::module_type_object::ModuleTypeObject;
use crate::ast::exprs::value_expr::FasValue;
use crate::utils::native_func_utils::AddFuncExt;
use std::collections::HashMap;

pub struct ModuleTypeString {}

impl ModuleTypeString {
    pub fn make() -> HashMap<String, FasValue> {
        let mut module = ModuleTypeObject::make();
        module.set_func("join", |val: String, args: Vec<String>| {
            let s = args.join(&val);
            s
        });
        module
    }
}
