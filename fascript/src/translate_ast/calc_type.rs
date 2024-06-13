use crate::ast::{
    blocks::func::*,
    exprs::{temp_expr::AstTempExpr, value_expr::FasValue, AstExpr},
    stmts::{break_stmt::AstBreakStmt, dec_var_stmt::AstDefVarStmt, if_stmt::AstIfStmt, AstStmt},
};

impl AstFunc {
    fn calc_type_get_vars(&mut self) -> Result<(), String> {
        let mut stmtss = vec![];
        let mut calc_type_data = CalcTypeData::new();
        match self {
            AstFunc::NativeFunc(nfunc) => panic!(),
            AstFunc::FasFunc(ffunc) => {
                for stmt in ffunc.body_stmts.clone().into_iter() {
                    match stmt.calc_type_get_vars(&mut calc_type_data) {
                        Ok(stmts) => stmtss.extend(stmts),
                        Err(e) => return Err(e),
                    }
                }
                ffunc.body_stmts = stmtss;
            }
            AstFunc::FasTask(ftask) => {
                for stmt in ftask.body_stmts.clone().into_iter() {
                    match stmt.calc_type_get_vars(&mut calc_type_data) {
                        Ok(stmts) => stmtss.extend(stmts),
                        Err(e) => return Err(e),
                    }
                }
                ftask.body_stmts = stmtss;
            }
        }
        Ok(())
    }
}

pub struct CalcTypeData {
    loop_labels: Vec<String>,
}

impl CalcTypeData {
    pub fn new() -> CalcTypeData {
        CalcTypeData {
            loop_labels: vec![],
        }
    }
}

impl AstStmt {
    fn calc_type_get_vars(self, data: &mut CalcTypeData) -> Result<Vec<Self>, String> {
        match self {
            AstStmt::Abort(expr) => match expr.calc_type_get_vars(data) {
                Ok((pre_stmts, expr, post_stmts)) => {
                    let mut ret = vec![];
                    ret.extend(pre_stmts);
                    ret.push(AstStmt::Abort(expr));
                    ret.extend(post_stmts);
                    Ok(ret)
                }
                Err(e) => return Err(e),
            },
            AstStmt::Break(stmt) => match data.loop_labels.iter().any(|s| s == &stmt.label) {
                true => AstStmt::Break(stmt).make_ret(),
                false => Err(format!("label[{}] not found in this scope", stmt.label)),
            },
            AstStmt::Continue(stmt) => match data.loop_labels.iter().any(|s| s == &stmt.label) {
                true => AstStmt::Continue(stmt).make_ret(),
                false => Err(format!("label[{}] not found in this scope", stmt.label)),
            },
            AstStmt::DefVar(stmt) => {
                let mut stmts = vec![];
                for var_part in stmt.def_vars {
                    let (pre_stmts, expr, post_stmts) =
                        var_part.init_value.calc_type_get_vars(data)?;
                    let default_type = var_part.var_otype.unwrap_or(expr.get_type());
                    stmts.extend(pre_stmts);
                    stmts.push(AstDefVarStmt::new(
                        Some(default_type),
                        var_part.var_name,
                        expr,
                    ));
                    stmts.extend(post_stmts);
                }
                Ok(stmts)
            }
            AstStmt::DoWhile(mut stmt) => {
                let (pre_stmts, expr, post_stmts) = stmt.cond_expr.calc_type_get_vars(data)?;
                let mut tmp_stmts = vec![];
                for stmt in stmt.stmts {
                    let stmt_items = stmt.calc_type_get_vars(data)?;
                    tmp_stmts.extend(stmt_items);
                }
                stmt.stmts = tmp_stmts;
                stmt.stmts.extend(pre_stmts);
                if !post_stmts.is_empty() {
                    let if_stmt = {
                        let mut if_stmt = AstIfStmt::new();
                        if_stmt.con_exprs.push(expr);
                        if_stmt
                            .stmtss
                            .push(vec![AstStmt::Break(AstBreakStmt::new("".to_string()))]);
                        if_stmt
                    };
                    stmt.cond_expr = AstExpr::Value(FasValue::Bool(true));
                    stmt.stmts.push(AstStmt::If(if_stmt));
                    stmt.stmts.extend(post_stmts);
                } else {
                    stmt.cond_expr = expr;
                }
                Ok(vec![AstStmt::DoWhile(stmt)])
            }
            AstStmt::Expr(expr) => {
                let (pre_stmts, expr, post_stmts) = expr.calc_type_get_vars(data)?;
                let mut tmp_stmts = vec![];
                tmp_stmts.extend(pre_stmts);
                tmp_stmts.push(AstStmt::Expr(expr));
                tmp_stmts.extend(post_stmts);
                Ok(tmp_stmts)
            }
            AstStmt::FinishTime(stmt) => todo!(),
            AstStmt::For(stmt) => todo!(),
            AstStmt::If(stmt) => todo!(),
            AstStmt::Return(expr) => {
                let (pre_stmts, expr, post_stmts) = expr.calc_type_get_vars(data)?;
                let mut tmp_stmts = vec![];
                tmp_stmts.extend(pre_stmts);
                tmp_stmts.push(AstDefVarStmt::new(
                    Some(expr.get_type()),
                    "__ret".to_string(),
                    expr,
                ));
                tmp_stmts.extend(post_stmts);
                tmp_stmts.push(AstStmt::Return(AstTempExpr::new("__ret".to_string())));
                Ok(tmp_stmts)
            }
            AstStmt::While(mut stmt) => {
                let (pre_stmts, expr, post_stmts) = stmt.cond_expr.calc_type_get_vars(data)?;
                let mut tmp_stmts = vec![];
                for stmt in stmt.stmts {
                    let stmt_items = stmt.calc_type_get_vars(data)?;
                    tmp_stmts.extend(stmt_items);
                }
                stmt.cond_expr = expr;
                stmt.stmts = tmp_stmts;
                let mut ret_stmts = vec![];
                ret_stmts.extend(pre_stmts);
                ret_stmts.push(AstStmt::While(stmt));
                ret_stmts.extend(post_stmts);
                Ok(ret_stmts)
            }
        }
    }

    fn make_ret(self) -> Result<Vec<AstStmt>, String> {
        Ok(vec![self])
    }
}

impl AstExpr {
    fn calc_type_get_vars(
        self,
        data: &mut CalcTypeData,
    ) -> Result<(Vec<AstStmt>, AstExpr, Vec<AstStmt>), String> {
        // TODO
        panic!()
    }

    fn make_ret(self) -> Result<(Vec<AstStmt>, AstExpr, Vec<AstStmt>), String> {
        Ok((vec![], self, vec![]))
    }
}
