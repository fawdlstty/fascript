use crate::ast::exprs::value_expr::FasValue;
use crate::utils::native_func_utils::AddFuncExt;
use std::collections::HashMap;

pub struct ModuleTypeObject {}

impl ModuleTypeObject {
    pub fn make() -> HashMap<String, FasValue> {
        let mut module = HashMap::new();
        module.set_func("to_str", |val: FasValue| val.as_type::<String>());
        module
    }
}
