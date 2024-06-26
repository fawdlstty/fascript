use crate::ast::exprs::value_expr::FasValue;
use crate::utils::native_func_utils::AddFuncExt;
use std::collections::HashMap;
use std::fs;
use std::path::Path;

pub struct ModuleDirectory {}

impl ModuleDirectory {
    pub fn make() -> HashMap<String, FasValue> {
        let mut module = HashMap::new();
        module.set_func("exists", |path: String| {
            let path = Path::new(&path);
            path.exists() && path.is_dir()
        });
        module.set_func("create", |path: String| fs::create_dir_all(path).is_ok());
        module.set_func("delete", |path: String| {
            let path = Path::new(&path);
            fs::remove_dir_all(&path).is_ok() || !path.exists()
        });
        module
    }
}
