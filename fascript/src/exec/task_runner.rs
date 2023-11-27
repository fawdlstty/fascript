use super::op2_calc::Op2Calc;
use crate::ast::blocks::func::AstFunc;
use crate::ast::exprs::invoke_expr::AstInvokeExpr;
use crate::ast::exprs::op2_expr::AstOp2Expr;
use crate::ast::exprs::value_expr::FasValue;
use crate::ast::exprs::AstExpr;
use crate::ast::stmts::AstStmt;
use crate::built_in::BuiltIn;
use crate::utils::oper_utils::OperUtils;
use std::collections::HashMap;

macro_rules! process_loop_ctrl {
    ($self:expr, $stmt:expr) => {
        match &$self.loop_ctrl {
            LoopControl::None => {}
            LoopControl::Continue(label) => {
                if label == &$stmt.label {
                    $self.loop_ctrl = LoopControl::None;
                }
            }
            LoopControl::Break(label) => {
                if label == &$stmt.label {
                    $self.loop_ctrl = LoopControl::None;
                }
                break;
            }
            LoopControl::Return => break,
        };
    };
}

#[derive(PartialEq, Eq)]
pub enum LoopControl {
    None,
    Continue(String),
    Break(String),
    Return,
}

#[derive(Eq, PartialEq, Debug)]
pub enum VariablesType {
    IndentVariables,
    InvokeArguments,
}

#[derive(Debug)]
pub struct Variables {
    vars: HashMap<String, FasValue>,
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
    ret_value: Option<FasValue>,
    loop_ctrl: LoopControl,
}

impl TaskRunner {
    pub fn new() -> TaskRunner {
        let mut ret = TaskRunner {
            variabless: vec![],
            ret_value: None,
            loop_ctrl: LoopControl::None,
        };
        ret.add_level();
        for name in BuiltIn::init_modules() {
            let value = BuiltIn::get_module(name);
            ret.add_new_var(name.to_string(), value);
        }
        ret
    }

    pub fn eval_stmt(&mut self, stmt: AstStmt) {
        if self.loop_ctrl != LoopControl::None {
            return;
        }
        match stmt {
            AstStmt::Break(break_stmt) => self.loop_ctrl = LoopControl::Break(break_stmt.label),
            AstStmt::Continue(continue_stmt) => {
                self.loop_ctrl = LoopControl::Continue(continue_stmt.label)
            }
            AstStmt::DefVar(def_stmt) => {
                for def_item in def_stmt.def_vars {
                    let var_value = self.eval_expr(def_item.init_value.clone());
                    self.add_new_var(
                        def_item.var_name.clone(),
                        var_value.as_type(def_item.var_type.clone()),
                    )
                }
            }
            AstStmt::DoWhile(do_while_stmt) => loop {
                self.add_level();
                self.eval_stmts(do_while_stmt.stmts.clone());
                process_loop_ctrl!(self, do_while_stmt);
                self.sub_level();
                //
                let cond_expr = self.eval_expr(do_while_stmt.cond_expr.clone()).as_bool();
                if !cond_expr {
                    break;
                }
            },
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
                    //
                    for i in left..right {
                        self.add_level();
                        self.add_new_var(for_stmt.iter_name.clone(), FasValue::Int(i));
                        self.eval_stmts(for_stmt.stmts.clone());
                        process_loop_ctrl!(self, for_stmt);
                        self.sub_level();
                    }
                }
                _ => todo!(),
            },
            AstStmt::If(if_stmt) => {
                let mut is_cond = false;
                for (index, cond_expr) in if_stmt.con_exprs.iter().enumerate() {
                    let cond = self.eval_expr(cond_expr.clone()).as_bool();
                    if cond {
                        is_cond = true;
                        self.eval_stmts(if_stmt.stmtss[index].clone());
                        break;
                    }
                }
                if !is_cond && if_stmt.stmtss.len() > if_stmt.con_exprs.len() {
                    self.eval_stmts(if_stmt.stmtss.last().unwrap().clone());
                }
            }
            AstStmt::Return(expr) => {
                self.ret_value = Some(self.eval_expr(expr));
                self.loop_ctrl = LoopControl::Return;
            }
            AstStmt::While(while_stmt) => loop {
                let cond_expr = self.eval_expr(while_stmt.cond_expr.clone()).as_bool();
                if !cond_expr {
                    break;
                }
                //
                self.add_level();
                self.eval_stmts(while_stmt.stmts.clone());
                process_loop_ctrl!(self, while_stmt);
                self.sub_level();
            },
        }
    }

    pub fn eval_stmts(&mut self, stmts: Vec<AstStmt>) {
        for stmt in stmts {
            self.eval_stmt(stmt);
        }
    }

    pub fn eval_expr(&mut self, expr: AstExpr) -> FasValue {
        match expr {
            AstExpr::None => todo!(),
            AstExpr::Func(func_expr) => FasValue::Func(Box::new(func_expr)),
            AstExpr::Index(_) => unreachable!(),
            AstExpr::Invoke(invoke_expr) => self.eval_func_expr(&invoke_expr),
            AstExpr::Op1(_) => todo!(),
            AstExpr::Op2(op2_expr) => self.eval_op2_expr(&op2_expr),
            AstExpr::Switch(_) => todo!(),
            AstExpr::Temp(temp_expr) => match self.find_var(&temp_expr.name) {
                Some(var_item) => var_item.clone(),
                None => todo!(),
            },
            AstExpr::TypeWrap(_) => todo!(),
            AstExpr::Value(val) => val,
        }
    }

    fn eval_func_expr(&mut self, invoke_expr: &AstInvokeExpr) -> FasValue {
        let func: FasValue = self.eval_expr(*invoke_expr.func.clone());
        match func {
            FasValue::Func(func) => self.invoke_func(*func.func, invoke_expr.arguments.clone()),
            _ => {
                println!("{:?}", func);
                todo!()
            }
        }
    }

    fn eval_op2_expr(&mut self, op2_expr: &AstOp2Expr) -> FasValue {
        let op = &op2_expr.op[..];
        if OperUtils::is_assign_op2(op) {
            if op == "=" {
                let left_name = match &*op2_expr.left {
                    AstExpr::Temp(temp_expr) => temp_expr.name.clone(),
                    _ => unreachable!(),
                };
                let mut value = self.eval_expr(*op2_expr.right.clone());
                match self.find_var(&left_name) {
                    Some(value_ref) => std::mem::swap(&mut value, value_ref),
                    None => todo!(),
                };
                FasValue::None
            } else {
                let tmp_op2 = AstOp2Expr::new(
                    *op2_expr.left.clone(),
                    op[..(op.len() - 1)].to_string(),
                    *op2_expr.right.clone(),
                );
                let tmp_op2 = AstOp2Expr::new(
                    *op2_expr.left.clone(),
                    "=".to_string(),
                    AstExpr::Value(self.eval_expr(tmp_op2)),
                );
                self.eval_expr(tmp_op2)
            }
        } else if OperUtils::is_calc_op2(op) {
            let left_expr = self.eval_expr(*op2_expr.left.clone());
            let right_expr = self.eval_expr(*op2_expr.right.clone());
            Op2Calc::calc(left_expr, op, right_expr)
        } else {
            todo!()
        }
    }

    pub fn invoke_func(&mut self, func: AstFunc, args: Vec<AstExpr>) -> FasValue {
        self.add_level_invoke(&func, &args);
        let mut ret = FasValue::None;
        match func {
            AstFunc::AstNativeFunc(func) => {
                ret = func
                    .func_impl
                    .call(args.into_iter().map(|x| self.eval_expr(x)).collect());
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

    pub fn get_return_value(&mut self) -> Option<FasValue> {
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
                self.eval_expr(args[idx].clone())
                    .as_type(arg_types[idx].clone()),
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

    fn add_new_var(&mut self, var_name: String, mut var_value: FasValue) {
        let bindings = self.variabless.last_mut().unwrap();
        let vars = &mut bindings.vars;
        match vars.get_mut(&var_name) {
            Some(var) => std::mem::swap(var, &mut var_value),
            None => {
                vars.insert(var_name, var_value);
            }
        };
    }

    fn find_var(&mut self, var_name: &str) -> Option<&mut FasValue> {
        // find var in func
        let mut vars: Vec<&str> = var_name.split('.').collect();
        let var_name = vars[0];
        vars.remove(0);
        let mut current_value = None;
        let mut in_func = true;
        let vars_len = self.variabless.len();
        for (index, variables) in self.variabless.iter_mut().rev().enumerate() {
            if !in_func && index != vars_len - 1 {
                continue;
            }
            if index == vars_len - 1 {
                if !variables.vars.contains_key(var_name) {
                    let new_obj = match vars.is_empty() {
                        true => FasValue::None,
                        false => FasValue::SMap(HashMap::new()),
                    };
                    variables.vars.insert(var_name.to_string(), new_obj);
                }
                current_value = variables.vars.get_mut(var_name);
            } else {
                if let Some(item) = variables.vars.get_mut(var_name) {
                    current_value = Some(item);
                    break;
                }
                if variables.vtype == VariablesType::InvokeArguments {
                    in_func = false;
                }
            }
        }
        let mut current_value = current_value.unwrap();
        while vars.len() > 0 {
            let name = vars.remove(0);
            current_value = match current_value {
                FasValue::SMap(sm) => match sm.get_mut(name) {
                    Some(value) => value,
                    None => unreachable!(),
                },
                _ => unreachable!(),
            };
        }

        Some(current_value)
    }

    pub fn set_global_value(&mut self, name: String, mut value: FasValue) {
        match self.variabless[0].vars.get_mut(&name) {
            Some(var_item) => {
                std::mem::swap(var_item, &mut value);
            }
            None => {
                self.variabless[0].vars.insert(name, value);
                ()
            }
        }
    }
}
