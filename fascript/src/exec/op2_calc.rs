use crate::ast::{exprs::value_expr::FasValue, types::AstType};

pub struct Op2Calc {}

impl Op2Calc {
    pub fn calc(left: FasValue, op: &str, right: FasValue) -> FasValue {
        let left_type = left.get_type();
        let right_type = right.get_type();
        match (left_type, right_type) {
            (AstType::None, _) => todo!(),
            (_, AstType::None) => todo!(),
            (AstType::Array(a), AstType::Array(b)) if a == b => {
                let base_type = *a.base_type.clone();
                Self::calc_array(
                    left.as_array(base_type.clone()),
                    op,
                    right.as_array(base_type.clone()),
                )
            }
            (AstType::Bool, AstType::Bool) => Self::calc_bool(left.as_bool(), op, right.as_bool()),
            (AstType::Float, AstType::Float) => {
                Self::calc_float(left.as_float(), op, right.as_float())
            }
            (AstType::Float, AstType::Int) => {
                Self::calc_float(left.as_float(), op, right.as_float())
            }
            (AstType::Int, AstType::Float) => {
                Self::calc_float(left.as_float(), op, right.as_float())
            }
            (AstType::Int, AstType::Int) => Self::calc_int(left.as_int(), op, right.as_int()),
            (AstType::String, AstType::String) => {
                Self::calc_string(left.as_str(), op, right.as_str())
            }
            (AstType::String, AstType::Int) => {
                Self::calc_string2(left.as_str(), op, right.as_int())
            }
            //AstType::Map(_) => todo!(),
            //AstType::Tuple(_) => todo!(),
            (AstType::Void, _) if op == "??" => right,
            _ => todo!(),
            //AstType::Dynamic => todo!(),
            //AstType::Func(_) => todo!(),
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

    pub fn calc_string2(left: String, op: &str, right: i64) -> FasValue {
        FasValue::String(match op {
            "**" => left.repeat(right as usize),
            _ => unreachable!(),
        })
    }
}
