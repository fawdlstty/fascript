use crate::ast::exprs::value_expr::FasValue;
use crate::utils::native_func_utils::AddFuncExt;
use std::collections::HashMap;

pub struct ModuleOs {}

impl ModuleOs {
    pub fn make() -> HashMap<String, FasValue> {
        let mut module = HashMap::new();
        module.set_func("print", |value: String| print!("{}", value));
        module.set_func("println", |value: String| println!("{}", value));
        module
    }
}
