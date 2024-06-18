use crate::ast::{exprs::value_expr::FasValue, types::AstType};

pub struct Op2Calc {}

impl Op2Calc {
    pub fn calc(left: FasValue, op: &str, right: FasValue) -> FasValue {
        let left_type = left.get_type();
        let right_type = right.get_type();
        match (left_type, right_type) {
            (AstType::None, _) => todo!(),
            (_, AstType::None) => todo!(),
            (AstType::Array(ty1), AstType::Array(ty2)) => {
                let left = left.as_type::<Vec<FasValue>>();
                let right = right.as_type::<Vec<FasValue>>();
                Self::calc_array(left, op, right)
            }
            (AstType::Bool, AstType::Bool) => {
                Self::calc_bool(left.as_type::<bool>(), op, right.as_type::<bool>())
            }
            (AstType::Float, AstType::Float) => {
                Self::calc_float(left.as_type::<f64>(), op, right.as_type::<f64>())
            }
            (AstType::Float, AstType::Int) => {
                Self::calc_float(left.as_type::<f64>(), op, right.as_type::<f64>())
            }
            (AstType::Int, AstType::Float) => {
                Self::calc_float(left.as_type::<f64>(), op, right.as_type::<f64>())
            }
            (AstType::Int, AstType::Int) => {
                Self::calc_int(left.as_type::<i64>(), op, right.as_type::<i64>())
            }
            (AstType::String, AstType::String) => {
                Self::calc_string(left.as_type::<String>(), op, right.as_type::<String>())
            }
            (AstType::Void, _) if op == "??" => right,
            (_, _) => todo!(),
        }
    }

    // pub fn calc(left: FasValue, op: &str, right: FasValue) -> FasValue {
    //     match op {
    //         "+" => todo!(),
    //         "-" => todo!(),
    //         "*" => todo!(),
    //         "/" => todo!(),
    //         "**" => todo!(),
    //         "%" => todo!(),
    //         "|" => todo!(),
    //         "&" => todo!(),
    //         "^" => todo!(),
    //         "&&" => todo!(),
    //         "||" => todo!(),
    //         "<<" => todo!(),
    //         ">>" => todo!(),
    //         ">" => todo!(),
    //         ">=" => todo!(),
    //         "<" => todo!(),
    //         "<=" => todo!(),
    //         "==" => todo!(),
    //         "!=" => todo!(),
    //         "??" => todo!(),
    //         _ => unreachable!(),
    //     }
    // }

    fn calc_array(left: Vec<FasValue>, op: &str, right: Vec<FasValue>) -> FasValue {
        let mut left = left;
        let mut right = right;
        match op {
            "+" => left.extend(right),
            "-" => left.retain(|x| !right.contains(x)),
            "|" => {
                right.retain(|x| !left.contains(x));
                left.extend(right);
            }
            "&" => left.retain(|x| !right.contains(x)),
            "^" => {
                left.retain(|x| !right.contains(x));
                right.retain(|x| !left.contains(x));
                left.extend(right);
            }
            "==" => return FasValue::Bool(left == right),
            "!=" => return FasValue::Bool(left != right),
            "??" if left.len() == 0 => return FasValue::Array(right),
            "??" if left.len() != 0 => return FasValue::Array(left),
            _ => {}
        };
        FasValue::Array(left)
    }

    pub fn calc_bool(left: bool, op: &str, right: bool) -> FasValue {
        FasValue::Bool(match op {
            "&&" => left && right,
            "||" => left || right,
            "==" => left == right,
            "!=" => left != right,
            _ => unreachable!(),
        })
    }

    pub fn calc_float(left: f64, op: &str, right: f64) -> FasValue {
        FasValue::Float(match op {
            "+" => left + right,
            "-" => left - right,
            "*" => left * right,
            "/" => left / right,
            "**" => left.powf(right),
            ">" => return FasValue::Bool(left > right - 0.000001),
            ">=" => return FasValue::Bool(left >= right - 0.000001),
            "<" => return FasValue::Bool(left < right + 0.000001),
            "<=" => return FasValue::Bool(left <= right + 0.000001),
            "==" => return FasValue::Bool((left - right).abs() <= 0.000001),
            "!=" => return FasValue::Bool((left - right).abs() > 0.000001),
            _ => unreachable!(),
        })
    }

    pub fn calc_int(left: i64, op: &str, right: i64) -> FasValue {
        FasValue::Int(match op {
            "+" => left + right,
            "-" => left - right,
            "*" => left * right,
            "/" => left / right,
            "**" => match right >= 0 {
                true => left.pow(right as u32),
                false => return FasValue::Float((left as f64).powf(right as f64)),
            },
            "%" => left % right,
            "|" => left | right,
            "&" => left & right,
            "^" => left ^ right,
            "<<" => left << right,
            ">>" => left >> right,
            ">" => return FasValue::Bool(left > right),
            ">=" => return FasValue::Bool(left >= right),
            "<" => return FasValue::Bool(left < right),
            "<=" => return FasValue::Bool(left <= right),
            "==" => return FasValue::Bool(left == right),
            "!=" => return FasValue::Bool(left != right),
            _ => unreachable!(),
        })
    }

    pub fn calc_string(left: String, op: &str, right: String) -> FasValue {
        FasValue::String(match op {
            "+" => format!("{}{}", left, right),
            "==" => return FasValue::Bool(left == right),
            "!=" => return FasValue::Bool(left != right),
            _ => unreachable!(),
        })
    }
}
