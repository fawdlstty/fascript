use super::module_type_object::ModuleTypeObject;
use crate::ast::exprs::value_expr::FasValue;
use crate::utils::native_func_utils::AddFuncExt;
use chrono::Duration;
use std::collections::HashMap;

pub struct ModuleTypeFloat {}

impl ModuleTypeFloat {
    pub fn make() -> HashMap<String, FasValue> {
        let mut module = ModuleTypeObject::make();
        module.set_func("nanosec", |val: f64| Duration::nanoseconds(val as i64));
        module.set_func("microsec", |val: f64| {
            Duration::nanoseconds((val * 1000.0) as i64)
        });
        module.set_func("millisec", |val: f64| {
            Duration::nanoseconds((val * 1000000.0) as i64)
        });
        module.set_func("sec", |val: f64| {
            Duration::nanoseconds((val * 1000000000.0) as i64)
        });
        module.set_func("min", |val: f64| {
            Duration::nanoseconds((val * 1000000000.0 * 60.0) as i64)
        });
        module.set_func("hour", |val: f64| {
            Duration::nanoseconds((val * 1000000.0 * 60.0 * 60.0) as i64)
        });
        module.set_func("day", |val: f64| {
            Duration::nanoseconds((val * 1000000.0 * 60.0 * 60.0 * 24.0) as i64)
        });
        module.set_func("week", |val: f64| {
            Duration::nanoseconds((val * 1000000.0 * 60.0 * 60.0 * 24.0 * 7.0) as i64)
        });
        module.set_func("month", |val: f64| {
            Duration::nanoseconds((val * 1000000.0 * 60.0 * 60.0 * 24.0 * 3.0) as i64)
        });
        module.set_func("year", |val: f64| {
            Duration::nanoseconds((val * 1000000.0 * 60.0 * 60.0 * 24.0 * 365.0) as i64)
        });
        module
    }
}
