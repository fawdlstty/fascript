use crate::{ast::exprs::value_expr::FasValue, utils::native_func_utils::AddFuncExt};
use std::{collections::HashMap, fs, path::Path};

pub struct ModuleDirectory {}

impl ModuleDirectory {
    pub fn make() -> HashMap<String, FasValue> {
        let mut module = HashMap::new();
        module.set_func("exists", |path: String| {
            let path = Path::new(&path);
            path.exists() && path.is_dir()
        });
        module.set_func("create", |path: String| fs::create_dir_all(path).is_ok());
        module
    }
}
