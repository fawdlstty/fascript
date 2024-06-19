use crate::ast::exprs::value_expr::FasValue;
use crate::utils::native_func_utils::AddFuncExt;
use std::collections::HashMap;

pub struct ModuleProcess {}

impl ModuleProcess {
    pub fn make() -> HashMap<String, FasValue> {
        let mut module = HashMap::new();
        module.set_func("current_process_id", || std::process::id() as i64);
        module
    }
}
