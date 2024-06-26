use crate::ast::exprs::value_expr::FasValue;
use crate::utils::native_func_utils::AddFuncExt;
use std::collections::HashMap;
use std::fs;
use std::io::Write;
use std::path::Path;

pub struct ModuleFile {}

impl ModuleFile {
    pub fn make() -> HashMap<String, FasValue> {
        let mut module = HashMap::new();
        module.set_func("exists", |path: String| {
            let path = Path::new(&path);
            path.exists() && path.is_file()
        });
        module.set_func("read", |path: String| {
            fs::read_to_string(path).unwrap_or("".to_string())
        });
        module.set_func("write", |path: String, text: String| {
            fs::write(path, text).is_ok()
        });
        module.set_func(
            "append",
            |path: String, text: String| match fs::OpenOptions::new().append(true).open(path) {
                Ok(mut file) => file.write_all(text.as_bytes()).is_ok(),
                Err(_) => false,
            },
        );
        module.set_func("delete", |path: String| {
            let path = Path::new(&path);
            fs::remove_file(path).is_ok() || !path.exists()
        });
        module
    }
}
