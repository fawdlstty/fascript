pub mod func_expr;
pub mod index_expr;
pub mod invoke_expr;
pub mod op1_expr;
pub mod op2_expr;
pub mod switch_expr;
pub mod temp_expr;
pub mod type_wrap_expr;
pub mod value_expr;

use self::invoke_expr::AstInvokeExpr;
use self::op1_expr::AstOp1Expr;
use self::op2_expr::AstOp2Expr;
use self::switch_expr::AstSwitchExpr;
use self::temp_expr::AstTempExpr;
use self::type_wrap_expr::AstTypeWrapExpr;
use self::value_expr::AstValueExpr;
use self::{func_expr::AstFuncExpr, index_expr::AstIndexExpr};
use super::{types::AstType, ParseExt, PestApiExt, Rule};
use crate::utils::{oper_utils::OperUtils, str_utils::StrUtils};

#[derive(Clone, Debug)]
pub enum AstExpr {
    None,
    Func(AstFuncExpr),
    Index(AstIndexExpr),
    Invoke(AstInvokeExpr),
    Op1(AstOp1Expr),
    Op2(AstOp2Expr),
    Switch(AstSwitchExpr),
    Temp(AstTempExpr),
    TypeWrap(AstTypeWrapExpr),
    Value(AstValueExpr),
}

impl AstExpr {
    fn parse_middle_expr(root: pest::iterators::Pair<'_, Rule>) -> Self {
        let mut expr = None;
        for root_item in root.into_inner() {
            match root_item.as_rule() {
                Rule::Middle3OpExpr => match expr {
                    Some(_) => unreachable!(),
                    None => expr = Some(Self::parse_op3_expr(root_item)),
                },
                Rule::Middle2OpExpr => match expr {
                    Some(_) => unreachable!(),
                    None => expr = Some(Self::parse_op2_expr(root_item)),
                },
                _ => unreachable!(),
            }
        }
        expr.unwrap()
    }

    fn parse_op3_expr(root: pest::iterators::Pair<'_, Rule>) -> Self {
        let mut exprs = vec![];
        for root_item in root.into_inner() {
            match root_item.as_rule() {
                Rule::StrongExpr => exprs.push(Self::parse_strong_expr(root_item)),
                _ => unreachable!(),
            }
        }
        let expr = exprs.remove(0);
        AstExpr::Switch(AstSwitchExpr {
            expr: Box::new(expr),
            conds: vec![
                AstValueExpr::from_bool(true),
                AstValueExpr::from_bool(false),
            ],
            values: exprs,
        })
    }

    fn parse_op2_expr(root: pest::iterators::Pair<'_, Rule>) -> Self {
        let mut exprs = vec![];
        let mut ops = vec![];
        for root_item in root.into_inner() {
            match root_item.as_rule() {
                Rule::StrongExpr => exprs.push(AstExpr::parse_strong_expr(root_item)),
                Rule::CalcOp => ops.push(root_item.as_str().to_string()),
                _ => unreachable!(),
            }
        }
        Self::parse_op2_expr_impl(&mut exprs, &mut ops)
    }

    fn parse_op2_expr_impl(exprs: &mut [AstExpr], ops: &mut [String]) -> AstExpr {
        if ops.len() > 0 {
            let mut p = 0;
            let mut level = OperUtils::get_op2_privilege(&ops[0]);
            for (index, op) in ops.iter().enumerate() {
                let new_level = OperUtils::get_op2_privilege(&ops[index]);
                if new_level > level {
                    level = new_level;
                    p = index;
                }
            }
            let left = Self::parse_op2_expr_impl(&mut exprs[..p + 1], &mut ops[..p]);
            let right = Self::parse_op2_expr_impl(&mut exprs[p + 1..], &mut ops[p + 1..]);
            AstOp2Expr::new(left, ops[p].to_string(), right)
        } else {
            let mut expr = AstExpr::None;
            std::mem::swap(&mut expr, &mut exprs[0]);
            expr
        }
    }

    fn parse_strong_expr(root: pest::iterators::Pair<'_, Rule>) -> Self {
        let mut prefixs = vec![];
        let mut oexpr = None;
        let mut suffix_ctxs = vec![];
        for root_item in root.into_inner() {
            match root_item.as_rule() {
                Rule::BaseExprPrefix => prefixs.push(root_item.as_str().to_string()),
                Rule::BaseExpr => oexpr = Some(AstExpr::parse_base_expr(root_item)),
                Rule::BaseExprSuffix => {
                    let suffix_ctx = root_item.into_inner().next().unwrap();
                    suffix_ctxs.push(suffix_ctx);
                }
                _ => unreachable!(),
            }
        }
        let mut expr = oexpr.unwrap();
        while let Some(prefix) = prefixs.pop() {
            expr = AstOp1Expr::new(expr, prefix, true);
        }
        for suffix_ctx in suffix_ctxs {
            match suffix_ctx.as_rule() {
                Rule::BaseExprSuffixInvoke => {
                    expr = AstInvokeExpr::new(expr, Self::parse_exprs(suffix_ctx));
                }
                Rule::BaseExprSuffixArrayAccess => unreachable!(),
                Rule::BaseExprSuffixAccess => {
                    if let AstExpr::Temp(temp) = &expr {
                        if let None = temp.otype {
                            let _type = AstType::parse_str(temp.name.clone());
                            expr = AstTempExpr::new(Some(_type), suffix_ctx.get_id());
                            continue;
                        }
                    }
                    expr = AstOp1Expr::new(expr, suffix_ctx.get_id(), false);
                }
                _ => unreachable!(),
            }
        }
        expr
    }

    fn parse_base_expr(root: pest::iterators::Pair<'_, Rule>) -> Self {
        let root_item = root.into_inner().next().unwrap();
        match root_item.as_rule() {
            Rule::Literal => Self::parse_literal_expr(root_item),
            Rule::NewExpr => unreachable!(),
            Rule::LambdaExpr => unreachable!(),
            Rule::TupleExpr => unreachable!(),
            Rule::QuotExpr => unreachable!(),
            Rule::Id => AstTempExpr::new(None, root_item.get_id()),
            Rule::ArrayExpr => unreachable!(),
            _ => unreachable!(),
        }
    }

    fn parse_literal_expr(root: pest::iterators::Pair<'_, Rule>) -> Self {
        let root_item = root.into_inner().next().unwrap();
        match root_item.as_rule() {
            Rule::NumberLiteral => {
                let num_str = root_item.as_str();
                if num_str.contains('.') {
                    AstValueExpr::from_float(num_str.parse().unwrap())
                } else {
                    AstValueExpr::from_int(num_str.parse().unwrap())
                }
            }
            Rule::BoolLiteral => AstValueExpr::from_bool(root_item.as_str() == "true"),
            Rule::StringLiteral => {
                AstValueExpr::from_string(StrUtils::code_to_str(root_item.as_str()))
            }
            _ => unreachable!(),
        }
    }

    pub fn parse_index_expr(root: pest::iterators::Pair<'_, Rule>) -> Self {
        let mut index_expr = AstIndexExpr {
            left: None,
            right: None,
        };
        for root_item in root.into_inner() {
            match root_item.as_rule() {
                Rule::Expr1 => {
                    let root_item2 = root_item.into_inner().next().unwrap();
                    index_expr.left = Some(Box::new(AstExpr::parse_base_expr(root_item2)));
                }
                Rule::Expr2 => {
                    let root_item2 = root_item.into_inner().next().unwrap();
                    index_expr.right = Some(Box::new(AstExpr::parse_base_expr(root_item2)));
                }
                _ => unreachable!(),
            }
        }
        AstExpr::Index(index_expr)
    }

    fn parse_exprs(root: pest::iterators::Pair<'_, Rule>) -> Vec<Self> {
        let mut exprs = vec![];
        for root_item in root.into_inner() {
            match root_item.as_rule() {
                Rule::Expr => exprs.push(Self::parse(root_item)),
                _ => unreachable!(),
            }
        }
        exprs
    }

    pub fn get_type(&self) -> AstType {
        match self {
            AstExpr::None => AstType::None,
            AstExpr::Func(func_expr) => func_expr.func.get_type(),
            AstExpr::Index(_) => AstType::Index,
            AstExpr::Invoke(invoke_expr) => todo!(),
            AstExpr::Op1(_) => todo!(),
            AstExpr::Op2(op2_expr) => op2_expr.get_type(),
            AstExpr::Switch(_) => todo!(),
            AstExpr::Temp(_) => todo!(),
            AstExpr::TypeWrap(_) => todo!(),
            AstExpr::Value(value_expr) => value_expr.get_type(),
        }
    }
}

impl ParseExt for AstExpr {
    fn parse(root: pest::iterators::Pair<'_, Rule>) -> Self {
        let mut name_exprs = vec![];
        let mut assign_ops = vec![];
        let mut middle_expr = None;
        for root_item in root.into_inner() {
            match root_item.as_rule() {
                Rule::NameExpr => name_exprs.push(AstTempExpr::new(None, root_item.get_id())),
                Rule::AssignOp => assign_ops.push(root_item.as_str().to_string()),
                Rule::MiddleExpr => middle_expr = Some(Self::parse_middle_expr(root_item)),
                _ => unreachable!(),
            }
        }
        while let Some(left) = name_exprs.pop() {
            let op = assign_ops.pop().unwrap_or("".to_string());
            let right = match middle_expr {
                Some(middle_expr) => middle_expr,
                None => unreachable!(),
            };
            middle_expr = Some(AstOp2Expr::new(left, op, right));
        }
        match middle_expr {
            Some(middle_expr) => middle_expr,
            None => unreachable!(),
        }
    }
}
