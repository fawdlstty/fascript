use std::collections::HashMap;

use crate::ast::types::{array_type::AstArrayType, map_type::AstMapType, AstType};

use super::{func_expr::AstFuncExpr, AstExpr};

#[derive(Clone, Debug)]
pub enum AstValueExpr {
    None,
    Bool(bool),
    Int(i64),
    Float(f64),
    String(String),
    Array(Vec<AstValueExpr>),
    IMap(HashMap<i64, AstValueExpr>),
    SMap(HashMap<String, AstValueExpr>),
    Func(Box<AstFuncExpr>),
}

impl PartialEq for AstValueExpr {
    fn eq(&self, other: &Self) -> bool {
        match (self, other) {
            (Self::Bool(l0), Self::Bool(r0)) => l0 == r0,
            (Self::Int(l0), Self::Int(r0)) => l0 == r0,
            (Self::Float(l0), Self::Float(r0)) => (l0 - r0).abs() <= 0.000001,
            (Self::String(l0), Self::String(r0)) => l0 == r0,
            (Self::Array(l0), Self::Array(r0)) => l0 == r0,
            (Self::IMap(l0), Self::IMap(r0)) => l0 == r0,
            (Self::SMap(l0), Self::SMap(r0)) => l0 == r0,
            (Self::Func(l0), Self::Func(r0)) => todo!(), //*l0.func == *r0.func,
            _ => core::mem::discriminant(self) == core::mem::discriminant(other),
        }
    }
}

impl Eq for AstValueExpr {}

impl AstValueExpr {
    pub fn from_bool(value: bool) -> AstExpr {
        AstExpr::Value(AstValueExpr::Bool(value))
    }

    pub fn from_int(value: i64) -> AstExpr {
        AstExpr::Value(AstValueExpr::Int(value))
    }

    pub fn from_float(value: f64) -> AstExpr {
        AstExpr::Value(AstValueExpr::Float(value))
    }

    pub fn from_string(value: String) -> AstExpr {
        AstExpr::Value(AstValueExpr::String(value))
    }

    pub fn from_func(func: AstFuncExpr) -> AstExpr {
        AstExpr::Value(AstValueExpr::Func(Box::new(func)))
    }

    pub fn get_type(&self) -> AstType {
        match self {
            AstValueExpr::None => AstType::Void,
            AstValueExpr::Bool(_) => AstType::Bool,
            AstValueExpr::Int(_) => AstType::Int,
            AstValueExpr::Float(_) => AstType::Float,
            AstValueExpr::String(_) => AstType::String,
            AstValueExpr::Array(v) => {
                let base_type = match v.first() {
                    Some(item) => item.get_type(),
                    None => AstType::None,
                };
                AstArrayType::new(base_type)
            }
            AstValueExpr::IMap(im) => {
                let value_type = match im.values().last() {
                    Some(item) => item.get_type(),
                    None => AstType::None,
                };
                AstMapType::new(AstType::Int, value_type)
            }
            AstValueExpr::SMap(sm) => {
                let value_type = match sm.values().last() {
                    Some(item) => item.get_type(),
                    None => AstType::None,
                };
                AstMapType::new(AstType::String, value_type)
            }
            AstValueExpr::Func(f) => todo!(),
        }
    }

    pub fn as_str(&self) -> String {
        match self {
            AstValueExpr::None => "(null)".to_string(),
            AstValueExpr::Bool(b) => match b {
                true => "true".to_string(),
                false => "false".to_string(),
            },
            AstValueExpr::Int(n) => format!("{}", n),
            AstValueExpr::Float(f) => format!("{:.4}", f),
            AstValueExpr::String(s) => s.to_string(),
            AstValueExpr::Array(v) => todo!(),
            AstValueExpr::IMap(im) => todo!(),
            AstValueExpr::SMap(sm) => todo!(),
            AstValueExpr::Func(_) => "(func)".to_string(),
        }
    }

    pub fn as_array(&self) -> Vec<AstValueExpr> {
        match self {
            AstValueExpr::Array(arr) => arr.clone(),
            _ => unreachable!(),
        }
    }

    pub fn as_bool(&self) -> bool {
        match self {
            AstValueExpr::Bool(b) => b.clone(),
            _ => unreachable!(),
        }
    }

    pub fn as_float(&self) -> f64 {
        match self {
            AstValueExpr::Float(f) => f.clone(),
            AstValueExpr::Int(i) => i.clone() as f64,
            _ => unreachable!(),
        }
    }

    pub fn as_int(&self) -> i64 {
        match self {
            AstValueExpr::Float(f) => f.round() as i64,
            AstValueExpr::Int(i) => i.clone(),
            _ => unreachable!(),
        }
    }
}
