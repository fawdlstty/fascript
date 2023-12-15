pub mod await_expr;
pub mod fail_expr;
pub mod func_expr;
pub mod index_expr;
pub mod invoke_expr;
pub mod op1_expr;
pub mod op2_expr;
pub mod report_expr;
pub mod switch_expr;
pub mod temp_expr;
pub mod type_wrap_expr;
pub mod value_expr;

use self::await_expr::AstAwaitExpr;
use self::fail_expr::AstFailExpr;
use self::func_expr::AstFuncExpr;
use self::index_expr::AstIndexExpr;
use self::invoke_expr::AstInvokeExpr;
use self::op1_expr::AstOp1Expr;
use self::op2_expr::AstOp2Expr;
use self::report_expr::AstReportExpr;
use self::switch_expr::AstSwitchExpr;
use self::temp_expr::AstTempExpr;
use self::type_wrap_expr::AstTypeWrapExpr;
use self::value_expr::FasValue;
use super::blocks::func::AstFunc;
use super::stmts::AstStmt;
use super::types::AstType;
use super::Parse2Ext;
use super::PestApiExt;
use super::Rule;
use crate::utils::oper_utils::OperUtils;
use crate::utils::str_utils::StrUtils;

#[derive(Clone, Debug)]
pub enum AstExpr {
    None,
    Await(AstAwaitExpr),
    Fail(AstFailExpr),
    Func(AstFuncExpr),
    Index(AstIndexExpr),
    Invoke(AstInvokeExpr),
    Op1(AstOp1Expr),
    Op2(AstOp2Expr),
    Report(AstReportExpr),
    Switch(AstSwitchExpr),
    Temp(AstTempExpr),
    TypeWrap(AstTypeWrapExpr),
    Value(FasValue),
}

impl AstExpr {
    pub fn parse_middle_expr(
        root: pest::iterators::Pair<'_, Rule>,
    ) -> (Vec<AstStmt>, Self, Vec<AstStmt>) {
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

    fn parse_op3_expr(root: pest::iterators::Pair<'_, Rule>) -> (Vec<AstStmt>, Self, Vec<AstStmt>) {
        let mut exprs = vec![];
        for root_item in root.into_inner() {
            match root_item.as_rule() {
                Rule::StrongExpr => {
                    let expr = Self::parse_strong_expr(root_item);
                    if expr.0.len() + expr.2.len() > 0 {
                        panic!()
                    }
                    exprs.push(expr.1);
                }
                _ => unreachable!(),
            }
        }
        let expr = AstExpr::Switch(AstSwitchExpr {
            expr: Box::new(exprs.remove(0)),
            conds: vec![
                AstExpr::Value(FasValue::Bool(true)),
                AstExpr::Value(FasValue::Bool(false)),
            ],
            values: exprs,
        });
        (vec![], expr, vec![])
    }

    fn parse_op2_expr(root: pest::iterators::Pair<'_, Rule>) -> (Vec<AstStmt>, Self, Vec<AstStmt>) {
        let mut pre_stmts = vec![];
        let mut post_stmts = vec![];
        let mut exprs = vec![];
        let mut ops = vec![];
        for root_item in root.into_inner() {
            match root_item.as_rule() {
                Rule::StrongExpr => {
                    let expr = AstExpr::parse_strong_expr(root_item);
                    pre_stmts.extend(expr.0);
                    exprs.push(expr.1);
                    post_stmts.extend(expr.2);
                }
                Rule::CalcOp => ops.push(root_item.as_str().to_string()),
                _ => unreachable!(),
            }
        }
        let expr = Self::parse_op2_expr_impl(&mut exprs, &mut ops);
        (pre_stmts, expr, post_stmts)
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

    fn parse_strong_expr(
        root: pest::iterators::Pair<'_, Rule>,
    ) -> (Vec<AstStmt>, Self, Vec<AstStmt>) {
        enum StringOrExpr {
            String(String),
            OExpr(Option<AstExpr>),
        }
        let mut pre_stmts = vec![];
        let mut post_stmts = vec![];
        let mut prefixs = vec![];
        let mut oexpr = None;
        let mut suffix_ctxs = vec![];
        for root_item in root.into_inner() {
            match root_item.as_rule() {
                Rule::BaseExprPrefix => {
                    let root_item = root_item.into_inner().next().unwrap();
                    match root_item.as_rule() {
                        Rule::BaseExprPrefixBase => {
                            prefixs.push(StringOrExpr::String(root_item.as_str().to_string()))
                        }
                        Rule::BaseExprPrefixAwait => {
                            match root_item.into_inner().next() {
                                Some(root_item) => {
                                    let expr = AstExpr::parse_middle_expr(root_item);
                                    if expr.0.len() + expr.2.len() > 0 {
                                        panic!()
                                    }
                                    prefixs.push(StringOrExpr::OExpr(Some(expr.1)));
                                }
                                None => {}
                            };
                        }
                        _ => unreachable!(),
                    }
                    //
                }
                Rule::BaseExpr => oexpr = Some(AstExpr::parse_base_expr(root_item)),
                Rule::BaseExprSuffix => {
                    let suffix_ctx = root_item.into_inner().next().unwrap();
                    suffix_ctxs.push(suffix_ctx);
                }
                _ => unreachable!(),
            }
        }
        let mut expr = oexpr.unwrap();
        while let Some(prefix_op) = prefixs.pop() {
            match prefix_op {
                StringOrExpr::String(op_str) => match &op_str[..] {
                    "++" => {
                        pre_stmts.push(AstStmt::Expr(AstOp2Expr::new(
                            expr.clone(),
                            "+=".to_string(),
                            AstExpr::Value(FasValue::Int(1)),
                        )));
                    }
                    "--" => {
                        pre_stmts.push(AstStmt::Expr(AstOp2Expr::new(
                            expr.clone(),
                            "-=".to_string(),
                            AstExpr::Value(FasValue::Int(1)),
                        )));
                    }
                    "fail" => expr = AstFailExpr::new(expr),
                    "fail" => expr = AstFailExpr::new(expr),
                    _ => expr = AstOp1Expr::new(expr, op_str, true),
                },
                StringOrExpr::OExpr(op_expr) => todo!(),
            }
        }
        for suffix_ctx in suffix_ctxs {
            match suffix_ctx.as_rule() {
                Rule::BaseExprSuffixBase => {
                    let suffix_op = suffix_ctx.get_id();
                    match &suffix_op[..] {
                        "++" => {
                            post_stmts.push(AstStmt::Expr(AstOp2Expr::new(
                                expr.clone(),
                                "+=".to_string(),
                                AstExpr::Value(FasValue::Int(1)),
                            )));
                        }
                        "--" => {
                            post_stmts.push(AstStmt::Expr(AstOp2Expr::new(
                                expr.clone(),
                                "-=".to_string(),
                                AstExpr::Value(FasValue::Int(1)),
                            )));
                        }
                        _ => expr = AstOp1Expr::new(expr, suffix_op, false),
                    };
                }
                Rule::BaseExprSuffixInvoke => {
                    let args = Self::parse_exprs(suffix_ctx);
                    pre_stmts.extend(args.0);
                    expr = AstInvokeExpr::new(expr, args.1);
                    post_stmts.extend(args.2);
                }
                Rule::BaseExprSuffixArrayAccess => unreachable!(),
                Rule::BaseExprSuffixAccess => {
                    if let AstExpr::Temp(temp) = &expr {
                        expr = AstTempExpr::new(format!("{}.{}", temp.name, suffix_ctx.get_id()));
                    } else {
                        expr = AstOp1Expr::new(expr, suffix_ctx.get_id(), false);
                    }
                }
                _ => unreachable!(),
            }
        }
        (pre_stmts, expr, post_stmts)
    }

    fn parse_base_expr(root: pest::iterators::Pair<'_, Rule>) -> Self {
        let root_item = root.into_inner().next().unwrap();
        match root_item.as_rule() {
            Rule::Literal => Self::parse_literal_expr(root_item),
            Rule::NewExpr => unreachable!(),
            Rule::LambdaExpr => AstExpr::Func(AstFuncExpr::new(AstFunc::parse_lambda(root_item))),
            Rule::TupleExpr => unreachable!(),
            Rule::QuotExpr => unreachable!(),
            Rule::Id => AstTempExpr::new(root_item.get_id()),
            Rule::ArrayExpr => unreachable!(),
            _ => unreachable!(),
        }
    }

    fn parse_literal_expr(root: pest::iterators::Pair<'_, Rule>) -> Self {
        let root_item = root.into_inner().next().unwrap();
        match root_item.as_rule() {
            Rule::NumberLiteral => {
                let num_str = root_item.as_str();
                AstExpr::Value(match num_str.contains('.') {
                    true => FasValue::Float(num_str.parse().unwrap()),
                    false => FasValue::Int(num_str.parse().unwrap()),
                })
            }
            Rule::BoolLiteral => AstExpr::Value(FasValue::Bool(root_item.as_str() == "true")),
            Rule::StringLiteral => {
                let str_value = StrUtils::code_to_str(root_item.as_str());
                AstExpr::Value(FasValue::String(str_value))
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

    fn parse_exprs(
        root: pest::iterators::Pair<'_, Rule>,
    ) -> (Vec<AstStmt>, Vec<Self>, Vec<AstStmt>) {
        let mut pre_stmts = vec![];
        let mut post_stmts = vec![];
        let mut exprs = vec![];
        for root_item in root.into_inner() {
            match root_item.as_rule() {
                Rule::Expr => {
                    let expr = Self::parse(root_item);
                    pre_stmts.extend(expr.0);
                    exprs.push(expr.1);
                    post_stmts.extend(expr.2);
                }
                _ => unreachable!(),
            }
        }
        (pre_stmts, exprs, post_stmts)
    }

    pub fn get_type(&self) -> AstType {
        match self {
            AstExpr::None => AstType::None,
            AstExpr::Await(_) => AstType::Future,
            AstExpr::Fail(_) => AstType::TaskResult,
            AstExpr::Func(func_expr) => func_expr.func.get_type(),
            AstExpr::Index(_) => AstType::Index,
            AstExpr::Invoke(invoke_expr) => todo!(),
            AstExpr::Op1(_) => todo!(),
            AstExpr::Op2(op2_expr) => op2_expr.get_type(),
            AstExpr::Report(_) => AstType::TaskResult,
            AstExpr::Switch(_) => todo!(),
            AstExpr::Temp(_) => todo!(),
            AstExpr::TypeWrap(_) => todo!(),
            AstExpr::Value(value_expr) => value_expr.get_type(),
        }
    }
}

impl Parse2Ext for AstExpr {
    fn parse(root: pest::iterators::Pair<'_, Rule>) -> (Vec<AstStmt>, Self, Vec<AstStmt>) {
        let mut name_exprs = vec![];
        let mut assign_ops = vec![];
        let mut middle_expr = None;
        for root_item in root.into_inner() {
            match root_item.as_rule() {
                Rule::NameExpr => name_exprs.push(AstTempExpr::new(root_item.get_id())),
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
            middle_expr = Some((right.0, AstOp2Expr::new(left, op, right.1), right.2));
        }
        match middle_expr {
            Some(middle_expr) => middle_expr,
            None => unreachable!(),
        }
    }
}
