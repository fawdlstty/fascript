use super::module_type_object::ModuleTypeObject;
use crate::ast::exprs::value_expr::FasValue;
use crate::utils::native_func_utils::AddFuncExt;
use chrono::Duration;
use std::collections::HashMap;

pub struct ModuleTypeInt {}

impl ModuleTypeInt {
    pub fn make() -> HashMap<String, FasValue> {
        let mut module = ModuleTypeObject::make();
        module.set_func("nanosec", |val: i64| Duration::nanoseconds(val));
        module.set_func("microsec", |val: i64| Duration::microseconds(val));
        module.set_func("millisec", |val: i64| Duration::milliseconds(val));
        module.set_func("sec", |val: i64| Duration::seconds(val));
        module.set_func("min", |val: i64| Duration::minutes(val));
        module.set_func("hour", |val: i64| Duration::hours(val));
        module.set_func("day", |val: i64| Duration::days(val));
        module.set_func("week", |val: i64| Duration::weeks(val));
        module.set_func("month", |val: i64| Duration::days(val * 30));
        module.set_func("year", |val: i64| Duration::days(val * 365));
        let a: FasValue = FasValue::None;
        let b: FasValue = a.into();
        module
    }
}
