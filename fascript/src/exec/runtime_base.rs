use crate::ast::exprs::value_expr::FasValue;
use crate::built_in::BuiltIn;
use std::collections::HashMap;
use std::sync::{Arc, Mutex};

#[derive(Eq, PartialEq, Debug, Clone)]
pub enum VariablesType {
    IndentVariables,
    InvokeArguments,
}

pub struct Variables {
    vars: HashMap<String, FasValue>,
    var_type: VariablesType,
}

impl Variables {
    pub fn new(var_type: VariablesType) -> Variables {
        Variables {
            vars: HashMap::new(),
            var_type,
        }
    }

    pub fn get_var(&self, name: &str) -> Option<FasValue> {
        let mut vars: Vec<&str> = name.split('.').collect();
        if vars.len() == 1 {
            match self.vars.get(name) {
                Some(val) => Some(val.clone()),
                None => None,
            }
        } else {
            let mut ref_value = match self.vars.get(vars.remove(0)) {
                Some(ref_value) => ref_value,
                None => return None,
            };
            while !vars.is_empty() {
                match ref_value {
                    FasValue::SMap(sm) => ref_value = sm.get(vars.remove(0)).unwrap(),
                    _ => panic!(),
                }
            }
            Some(ref_value.clone())
        }
    }

    pub fn get_var_cb(&mut self, name: &str, cb: impl Fn(&mut FasValue)) -> bool {
        let mut vars: Vec<&str> = name.split('.').collect();
        if vars.len() == 1 {
            match self.vars.get_mut(name) {
                Some(val) => {
                    cb(val);
                    true
                }
                None => false,
            }
        } else {
            let mut ref_value = match self.vars.get_mut(vars.remove(0)) {
                Some(ref_value) => ref_value,
                None => return false,
            };
            while !vars.is_empty() {
                match ref_value {
                    FasValue::SMap(sm) => ref_value = sm.get_mut(vars.remove(0)).unwrap(),
                    _ => panic!(),
                }
            }
            cb(ref_value);
            true
        }
    }

    pub fn set_var(&mut self, name: String, mut val: FasValue) -> bool {
        let mut vars: Vec<&str> = name.split('.').collect();
        if vars.len() == 1 {
            self.vars.insert(name, val);
            true
        } else {
            let mut ref_value = match self.vars.get_mut(vars.remove(0)) {
                Some(ref_value) => ref_value,
                None => return false,
            };
            while !vars.is_empty() {
                match ref_value {
                    FasValue::SMap(sm) => ref_value = sm.get_mut(vars.remove(0)).unwrap(),
                    _ => panic!(),
                }
            }
            std::mem::swap(ref_value, &mut val);
            true
        }
    }

    pub fn get_var_type(&self) -> VariablesType {
        self.var_type.clone()
    }
}

#[derive(Clone)]
pub struct RuntimeBase {
    base_vars: Arc<Mutex<Variables>>,
}

impl RuntimeBase {
    pub fn new() -> RuntimeBase {
        let mut vars = Variables::new(VariablesType::IndentVariables);
        for name in BuiltIn::init_modules() {
            vars.set_var(name.to_string(), BuiltIn::get_module(name));
        }
        RuntimeBase {
            base_vars: Arc::new(Mutex::new(vars)),
        }
    }

    pub fn get_var(&self, name: &str) -> Option<FasValue> {
        let vars = self.base_vars.lock().unwrap();
        vars.get_var(name)
    }

    pub fn get_var_cb(&mut self, name: &str, cb: impl Fn(&mut FasValue)) -> bool {
        let mut vars = self.base_vars.lock().unwrap();
        vars.get_var_cb(name, cb)
    }

    pub fn set_var(&mut self, name: String, val: FasValue) -> bool {
        let mut vars = self.base_vars.lock().unwrap();
        vars.set_var(name, val)
    }
}
