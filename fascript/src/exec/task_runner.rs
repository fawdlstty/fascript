use crate::ast::blocks::func::AstFunc;
use crate::ast::exprs::invoke_expr::AstInvokeExpr;
use crate::ast::exprs::op2_expr::AstOp2Expr;
use crate::ast::exprs::{value_expr::AstValueExpr, AstExpr};
use crate::ast::stmts::AstStmt;
use crate::ast::types::AstType;
use crate::utils::oper_utils::OperUtils;
use std::collections::HashMap;

use super::native_exprs::NativeExprs;
use super::op2_calc::Op2Calc;

#[derive(Clone)]
pub struct VariableItem {
    var_type: AstType,
    var_value: AstValueExpr,
}

impl VariableItem {
    pub fn new(var_type: AstType, var_value: AstValueExpr) -> VariableItem {
        if var_value.get_type() != var_type {
            todo!()
        }
        VariableItem {
            var_type,
            var_value,
        }
    }
}

#[derive(Eq, PartialEq)]
pub enum VariablesType {
    IndentVariables,
    InvokeArguments,
}

pub struct Variables {
    vars: HashMap<String, VariableItem>,
    vtype: VariablesType,
}

impl Variables {
    pub fn new(vtype: VariablesType) -> Variables {
        Variables {
            vars: HashMap::new(),
            vtype,
        }
    }
}

pub struct TaskRunner {
    variabless: Vec<Variables>,
    ret_value: Option<AstValueExpr>,
}

impl TaskRunner {
    pub fn new() -> TaskRunner {
        let mut ret = TaskRunner {
            variabless: vec![],
            ret_value: None,
        };
        ret.add_level();
        ret
    }

    pub fn eval_stmt(&mut self, stmt: AstStmt) {
        match stmt {
            AstStmt::DefVar(def_stmt) => {
                for def_item in def_stmt.def_vars {
                    self.add_var(
                        def_item.var_name.clone(),
                        def_item.var_type.clone(),
                        def_item.init_value.clone(),
                    )
                }
            }
            AstStmt::Expr(expr) => {
                self.eval_expr(expr);
                ()
            }
            AstStmt::For(for_stmt) => match for_stmt.iter_items {
                AstExpr::Index(index_expr) => {
                    let left = match index_expr.left {
                        Some(left) => *left,
                        None => todo!(),
                    };
                    let left = self.eval_expr(left).as_int();
                    let right = match index_expr.right {
                        Some(right) => *right,
                        None => todo!(),
                    };
                    let right = self.eval_expr(right).as_int();
                    for i in left..right {
                        // TODO
                        todo!()
                    }
                }
                _ => todo!(),
            },
        }
    }

    pub fn eval_expr(&mut self, expr: AstExpr) -> AstValueExpr {
        match expr {
            AstExpr::None => todo!(),
            AstExpr::Func(func_expr) => AstValueExpr::Func(Box::new(func_expr)),
            AstExpr::Index(_) => unreachable!(),
            AstExpr::Invoke(invoke_expr) => self.eval_func_expr(&invoke_expr),
            AstExpr::Op1(_) => todo!(),
            AstExpr::Op2(op2_expr) => self.eval_op2_expr(&&op2_expr),
            AstExpr::Switch(_) => todo!(),
            AstExpr::Temp(_) => todo!(),
            AstExpr::TypeWrap(_) => todo!(),
            AstExpr::Value(val) => val,
        }
    }

    fn eval_func_expr(&mut self, invoke_expr: &AstInvokeExpr) -> AstValueExpr {
        match *invoke_expr.func.clone() {
            AstExpr::Temp(_temp) => match _temp.otype {
                Some(_type) => {
                    //_type _temp.name
                    todo!()
                }
                None => {
                    let _expr = match self.find_var(&_temp.name) {
                        Some(_var) => _var.var_value.clone(),
                        None => NativeExprs::get_expr(&_temp.name),
                    };
                    if let AstValueExpr::Func(_func_expr) = _expr {
                        self.invoke_func(*_func_expr.func, invoke_expr.arguments.clone())
                    } else {
                        todo!();
                    }
                }
            },
            _ => todo!(),
        }
    }

    fn eval_op2_expr(&mut self, invoke_expr: &AstOp2Expr) -> AstValueExpr {
        let op = &invoke_expr.op[..];
        if OperUtils::is_assign_op2(op) {
            if op == "=" {
                let left_expr = *invoke_expr.left.clone();
                println!("left_expr: {:?}", left_expr);
                todo!()
            } else {
                let tmp_op2 = AstOp2Expr::new(
                    *invoke_expr.left.clone(),
                    op[..op.len()].to_string(),
                    *invoke_expr.right.clone(),
                );
                let tmp_op2 = AstOp2Expr::new(
                    *invoke_expr.left.clone(),
                    "=".to_string(),
                    AstExpr::Value(self.eval_expr(tmp_op2)),
                );
                self.eval_expr(tmp_op2)
            }
        } else if OperUtils::is_calc_op2(op) {
            let left_expr = self.eval_expr(*invoke_expr.left.clone());
            let right_expr = self.eval_expr(*invoke_expr.right.clone());
            Op2Calc::calc(left_expr, op, right_expr)
        } else {
            todo!()
        }
    }

    pub fn invoke_func(&mut self, func: AstFunc, args: Vec<AstExpr>) -> AstValueExpr {
        self.add_level_invoke(&func, &args);
        let mut ret = AstValueExpr::None;
        match func {
            AstFunc::AstNativeFunc(func) => {
                ret = (*func.func_impl)(args.into_iter().map(|x| self.eval_expr(x)).collect());
            }
            AstFunc::AstManagedFunc(func) => {
                for stmt in func.body_stmts {
                    self.eval_stmt(stmt);
                    if self.ret_value.is_some() {
                        let mut ret_value = None;
                        std::mem::swap(&mut ret_value, &mut self.ret_value);
                        ret = ret_value.unwrap();
                        break;
                    }
                }
            }
        }
        self.sub_level();
        ret
    }

    pub fn get_return_value(&mut self) -> Option<AstValueExpr> {
        let mut ret_value = None;
        std::mem::swap(&mut ret_value, &mut self.ret_value);
        ret_value
    }

    fn add_level(&mut self) {
        self.variabless
            .push(Variables::new(VariablesType::IndentVariables));
    }

    fn add_level_invoke(&mut self, func: &AstFunc, args: &Vec<AstExpr>) {
        let args = args;
        let mut variables = Variables::new(VariablesType::InvokeArguments);
        let arg_types = func.get_arg_types();
        for (idx, var_name) in func.get_arg_names().iter().enumerate() {
            variables.vars.insert(
                var_name.clone(),
                VariableItem {
                    var_type: arg_types[idx].clone(),
                    var_value: self.eval_expr(args[idx].clone()),
                },
            );
        }
        self.variabless.push(variables);
        self.variabless
            .push(Variables::new(VariablesType::IndentVariables));
    }

    fn sub_level(&mut self) {
        self.variabless.pop();
        if let Some(last) = self.variabless.last() {
            if last.vtype == VariablesType::InvokeArguments {
                self.variabless.pop();
            }
        }
    }

    fn add_var(&mut self, var_name: String, var_type: AstType, var_value: AstExpr) {
        let var_value = self.eval_expr(var_value);
        let bindings = self.variabless.last_mut().unwrap();
        let vars = &mut bindings.vars;
        match vars.get_mut(&var_name) {
            Some(var) => {
                var.var_type = var_type;
                var.var_value = var_value;
            }
            None => {
                vars.insert(
                    var_name,
                    VariableItem {
                        var_type,
                        var_value,
                    },
                );
                ()
            }
        }
    }

    fn find_var(&mut self, name: &str) -> Option<VariableItem> {
        for variables in self.variabless.iter().rev() {
            if let Some(item) = variables.vars.get(name) {
                return Some(item.clone());
            }
            if variables.vtype == VariablesType::InvokeArguments {
                return None;
            }
        }
        return None;
    }
}
