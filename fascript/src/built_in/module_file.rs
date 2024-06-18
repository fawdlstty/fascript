use crate::{ast::exprs::value_expr::FasValue, utils::native_func_utils::AddFuncExt};
use std::{
    collections::HashMap,
    fs::{self, OpenOptions},
    io::Write,
    path::Path,
};

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
            match fs::write(path, text) {
                Ok(_) => true,
                Err(_) => false,
            }
        });
        module.set_func(
            "append",
            |path: String, text: String| match OpenOptions::new().append(true).open(path) {
                Ok(mut file) => file.write_all(text.as_bytes()).is_ok(),
                Err(_) => false,
            },
        );
        module
    }
}
