use crate::{ast::exprs::value_expr::FasValue, utils::native_func_utils::AddFuncExt};
use std::{
    collections::HashMap,
    fs::{self, OpenOptions},
    io::Write,
    path::Path,
};

pub struct ModuleProcess {}

impl ModuleProcess {
    pub fn make() -> HashMap<String, FasValue> {
        let mut module = HashMap::new();
        module.set_func("current_process_id", || std::process::id() as i64);
        module
    }
}
