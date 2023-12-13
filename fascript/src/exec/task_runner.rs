use chrono::NaiveDateTime;

use super::op2_calc::Op2Calc;
use super::runtime_base::RuntimeBase;
use super::runtime_base::Variables;
use super::runtime_base::VariablesType;
use crate::ast::blocks::func::AstFunc;
use crate::ast::blocks::func::FasFunc;
use crate::ast::exprs::invoke_expr::AstInvokeExpr;
use crate::ast::exprs::op1_expr::AstOp1Expr;
use crate::ast::exprs::op2_expr::AstOp2Expr;
use crate::ast::exprs::value_expr::FasValue;
use crate::ast::exprs::value_expr::TaskReply;
use crate::ast::exprs::value_expr::TaskValue;
use crate::ast::exprs::AstExpr;
use crate::ast::stmts::AstStmt;
use crate::ast::types::AstType;
use crate::utils::oper_utils::OperUtils;
use crate::utils::time_utils::NaiveDateTimeExt;

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

#[derive(PartialEq, Eq, Debug, Clone)]
pub enum LoopControl {
    None,
    Continue(String),
    Break(String),
    Return,
}

pub struct TaskRunner {
    base: RuntimeBase,
    stack: Vec<Variables>,
    ret_value: Option<FasValue>,
    loop_ctrl: LoopControl,
}

impl TaskRunner {
    pub fn new(base: RuntimeBase) -> TaskRunner {
        TaskRunner {
            base,
            stack: vec![],
            ret_value: None,
            loop_ctrl: LoopControl::None,
        }
    }

    pub async fn eval_stmt(&mut self, stmt: AstStmt) {
        if self.loop_ctrl != LoopControl::None {
            return;
        }
        if self.stack.len() == 0 {
            self.ret_value = None;
        }
        match stmt {
            AstStmt::Break(break_stmt) => self.loop_ctrl = LoopControl::Break(break_stmt.label),
            AstStmt::Continue(continue_stmt) => {
                self.loop_ctrl = LoopControl::Continue(continue_stmt.label)
            }
            AstStmt::DefVar(def_stmt) => {
                for def_item in def_stmt.def_vars {
                    let var_value = self.eval_expr(def_item.init_value.clone()).await;
                    self.set_var(def_item.var_name.clone(), var_value);
                }
            }
            AstStmt::DoWhile(do_while_stmt) => loop {
                self.add_level();
                self.eval_stmts(do_while_stmt.stmts.clone());
                process_loop_ctrl!(self, do_while_stmt);
                self.sub_level();
                //
                let cond_expr = self
                    .eval_expr(do_while_stmt.cond_expr.clone())
                    .await
                    .as_bool();
                if !cond_expr {
                    break;
                }
            },
            AstStmt::Expr(expr) => {
                let ret = self.eval_expr(expr).await;
                if self.stack.len() == 0 {
                    self.ret_value = Some(ret);
                }
            }
            AstStmt::For(for_stmt) => match for_stmt.iter_items {
                AstExpr::Index(index_expr) => {
                    let left = match index_expr.left {
                        Some(left) => *left,
                        None => todo!(),
                    };
                    let left = self.eval_expr(left).await.as_int();
                    let right = match index_expr.right {
                        Some(right) => *right,
                        None => todo!(),
                    };
                    let right = self.eval_expr(right).await.as_int();
                    //
                    for i in left..right {
                        self.add_level();
                        self.set_var(for_stmt.iter_name.clone(), FasValue::Int(i));
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
                    let cond = self.eval_expr(cond_expr.clone()).await.as_bool();
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
                self.ret_value = Some(self.eval_expr(expr).await);
                self.loop_ctrl = LoopControl::Return;
            }
            AstStmt::While(while_stmt) => loop {
                let cond_expr = self.eval_expr(while_stmt.cond_expr.clone()).await.as_bool();
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
            if self.ret_value.is_some() {
                break;
            }
        }
    }

    pub async fn eval_expr(&mut self, expr: AstExpr) -> FasValue {
        match expr {
            AstExpr::None => FasValue::None,
            AstExpr::Await(await_expr) => {
                let task = self.eval_expr(*await_expr.value).await.as_task();
                match await_expr.wait {
                    Some(wait) => {
                        let wait = self.eval_expr(*wait).await;
                        let ts = wait.as_timespan();
                        let dest_time = NaiveDateTime::now() + ts;
                        while NaiveDateTime::now() < dest_time {
                            match task.result_rx.try_recv() {
                                Ok(TaskReply::TaskResult(result)) => {
                                    // TODO
                                    todo!()
                                }
                                Ok(TaskReply::TaskProgress(step)) => {
                                    // TODO
                                    todo!()
                                }
                                Err(_) => {
                                    tokio::task::yield_now().await;
                                }
                            }
                        }
                    }
                    None => {
                        loop {
                            //
                        }
                    }
                };
                // TODO
                todo!()
            }
            AstExpr::Func(func_expr) => FasValue::Func(Box::new(func_expr)),
            AstExpr::Index(_) => unreachable!(),
            AstExpr::Invoke(invoke_expr) => self.eval_func_expr(&invoke_expr).await,
            AstExpr::Op1(op1_expr) => self.eval_op1_expr(&op1_expr).await,
            AstExpr::Op2(op2_expr) => self.eval_op2_expr(&op2_expr).await,
            AstExpr::Switch(_) => todo!(),
            AstExpr::Temp(temp_expr) => self.get_var(&temp_expr.name).unwrap_or(FasValue::None),
            AstExpr::TypeWrap(_) => todo!(),
            AstExpr::Value(val) => val,
            _ => todo!(),
        }
    }

    async fn eval_func_expr(&mut self, invoke_expr: &AstInvokeExpr) -> FasValue {
        let func: FasValue = self.eval_expr(*invoke_expr.func.clone()).await;
        match func {
            FasValue::Func(func) => {
                self.invoke_func(*func.func, invoke_expr.arguments.clone())
                    .await
            }
            _ => todo!(),
        }
    }

    async fn eval_op1_expr(&mut self, op1_expr: &AstOp1Expr) -> FasValue {
        let left = self.eval_expr(*op1_expr.left.clone()).await;
        match op1_expr.is_prefix {
            true => match &op1_expr.op[..] {
                "-" => match left.get_type() {
                    AstType::Int => FasValue::Int(-left.as_int()),
                    AstType::Float => FasValue::Float(-left.as_float()),
                    _ => panic!(),
                },
                "~" => match left.get_type() {
                    AstType::Int => {
                        let n = left.as_int();
                        FasValue::Int(-1 - n)
                    }
                    _ => panic!(),
                },
                "!" => match left.get_type() {
                    AstType::Bool => FasValue::Bool(!left.as_bool()),
                    _ => panic!(),
                },
                _ => panic!(),
            },
            false => {
                panic!()
            }
        }
    }

    async fn eval_op2_expr(&mut self, op2_expr: &AstOp2Expr) -> FasValue {
        let op = &op2_expr.op[..];
        if OperUtils::is_assign_op2(op) {
            if op == "=" {
                let left_name = match &*op2_expr.left {
                    AstExpr::Temp(temp_expr) => temp_expr.name.clone(),
                    _ => unreachable!(),
                };
                let mut value = self.eval_expr(*op2_expr.right.clone()).await;
                self.set_var(left_name, value);
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
                    AstExpr::Value(self.eval_expr(tmp_op2).await),
                );
                self.eval_expr(tmp_op2).await
            }
        } else if OperUtils::is_calc_op2(op) {
            let left_expr = self.eval_expr(*op2_expr.left.clone()).await;
            let right_expr = self.eval_expr(*op2_expr.right.clone()).await;
            Op2Calc::calc(left_expr, op, right_expr)
        } else {
            todo!()
        }
    }

    pub async fn invoke_func(&mut self, func: AstFunc, args: Vec<AstExpr>) -> FasValue {
        match func {
            AstFunc::NativeFunc(func) => {
                let mut new_args = vec![];
                for arg in args {
                    new_args.push(self.eval_expr(arg).await);
                }
                func.call(new_args)
                //func.call(args.into_iter().map(|x| self.eval_expr(x).await).collect())
            }
            AstFunc::FasFunc(func) => self.call_fas_func(&func, &args),
            AstFunc::FasTask(task) => {
                let (ret, shadow) = TaskValue::create();
                let task = task.clone();
                let base2 = self.base.clone();
                tokio::spawn(async move {
                    let runner = TaskRunner::new(base2);

                    // let mut ret = FasValue::None;
                    // let loop_ctrl = self.loop_ctrl.clone();
                    // self.loop_ctrl = LoopControl::None;
                    // self.add_level_invoke(&func, &args);
                    // self.eval_stmts(func.body_stmts.clone());
                    // if self.ret_value.is_some() {
                    //     let mut ret_value = None;
                    //     std::mem::swap(&mut ret_value, &mut self.ret_value);
                    //     ret = ret_value.unwrap();
                    // }
                    // self.sub_level();
                    // self.loop_ctrl = loop_ctrl;
                    // ret
                });
                FasValue::Task(ret)
            }
        }
    }

    pub fn call_fas_func(&mut self, func: &FasFunc, args: &Vec<AstExpr>) -> FasValue {
        let mut ret = FasValue::None;
        let loop_ctrl = self.loop_ctrl.clone();
        self.loop_ctrl = LoopControl::None;
        self.add_level_invoke(&func, &args);
        self.eval_stmts(func.body_stmts.clone());
        if self.ret_value.is_some() {
            let mut ret_value = None;
            std::mem::swap(&mut ret_value, &mut self.ret_value);
            ret = ret_value.unwrap();
        }
        self.sub_level();
        self.loop_ctrl = loop_ctrl;
        ret
    }

    pub fn get_return_value(&mut self) -> Option<FasValue> {
        let mut ret_value = None;
        std::mem::swap(&mut ret_value, &mut self.ret_value);
        ret_value
    }

    fn add_level(&mut self) {
        self.stack
            .push(Variables::new(VariablesType::IndentVariables));
    }

    async fn add_level_invoke(&mut self, func: &FasFunc, args: &Vec<AstExpr>) {
        let mut variables = Variables::new(VariablesType::InvokeArguments);
        for (idx, var_name) in func.arg_names.iter().enumerate() {
            let value = self.eval_expr(args[idx].clone()).await;
            variables.set_var(var_name.clone(), value);
        }
        self.stack.push(variables);
        self.stack
            .push(Variables::new(VariablesType::IndentVariables));
    }

    fn sub_level(&mut self) {
        self.stack.pop();
        if let Some(last) = self.stack.last() {
            if last.get_var_type() == VariablesType::InvokeArguments {
                self.stack.pop();
            }
        }
    }

    fn set_var(&mut self, var_name: String, mut var_value: FasValue) {
        let ret = match self.stack.last_mut() {
            Some(bindings) => bindings.set_var(var_name, var_value),
            None => self.base.set_var(var_name, var_value),
        };
        if !ret {
            todo!()
        }
    }

    fn get_var(&mut self, var_name: &str) -> Option<FasValue> {
        for variables in self.stack.iter_mut().rev() {
            let ret = variables.get_var(var_name);
            if ret.is_some() {
                return ret;
            }
        }
        self.base.get_var(var_name)
    }

    pub fn set_global_value(&mut self, name: String, mut value: FasValue) {
        self.base.set_var(name, value);
    }
}
