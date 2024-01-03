use crate::ast::exprs::value_expr::FasValue;
use crate::utils::native_func_utils::AddFuncExt;
use crate::utils::time_utils::{DurationExt, NaiveDateTimeExt};
use chrono::NaiveDateTime;
use lazy_static::lazy_static;
use std::collections::HashMap;
use std::sync::Mutex;

lazy_static! {
    static ref CACHE_STR: Mutex<String> = Mutex::new("".to_string());
}

pub struct ModuleTest {}

impl ModuleTest {
    pub fn make() -> HashMap<String, FasValue> {
        let mut module = HashMap::new();
        module.set_func("cache_str", |value: String| {
            let mut cache_str = CACHE_STR.lock().unwrap();
            cache_str.push_str(&value);
        });
        module.set_func("get_cache", || {
            let cache_str = CACHE_STR.lock().unwrap();
            cache_str.clone()
        });
        module
    }
}
