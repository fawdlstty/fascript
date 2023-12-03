use super::AstStmt;
use crate::ast::{exprs::AstExpr, types::AstType, Parse3Ext, ParseExt, Rule};

#[derive(Clone, Debug)]
pub struct DefVarItemPart {
    pub var_type: AstType,
    pub var_name: String,
    pub init_value: AstExpr,
}

#[derive(Clone, Debug)]
pub struct AstDefVarStmt {
    pub def_vars: Vec<DefVarItemPart>,
}

impl AstDefVarStmt {
    pub fn new(var_type: AstType, var_name: String, init_value: AstExpr) -> AstStmt {
        AstStmt::DefVar(AstDefVarStmt {
            def_vars: vec![DefVarItemPart {
                var_type,
                var_name,
                init_value,
            }],
        })
    }
}

impl Parse3Ext for AstDefVarStmt {
    fn parse(root: pest::iterators::Pair<'_, Rule>) -> Vec<AstStmt> {
        let mut pre_stmts = vec![];
        let mut post_stmts = vec![];
        let mut stmt = AstDefVarStmt { def_vars: vec![] };
        let mut var_type = None;
        for root_item in root.into_inner() {
            match root_item.as_rule() {
                Rule::Type => var_type = Some(AstType::parse(root_item)),
                Rule::DefVarItemPart => {
                    let mut var_name = "";
                    let mut init_value = AstExpr::None;
                    for def_var_item in root_item.into_inner() {
                        match def_var_item.as_rule() {
                            Rule::Id => var_name = def_var_item.as_str(),
                            Rule::MiddleExpr => {
                                let expr = AstExpr::parse_middle_expr(def_var_item);
                                pre_stmts.extend(expr.0);
                                init_value = expr.1;
                                post_stmts.extend(expr.2);
                            }
                            _ => unreachable!(),
                        }
                    }
                    stmt.def_vars.push(DefVarItemPart {
                        var_type: var_type.clone().unwrap_or(init_value.get_type()),
                        var_name: var_name.to_string(),
                        init_value,
                    });
                }
                _ => unreachable!(),
            }
        }
        pre_stmts.push(AstStmt::DefVar(stmt));
        pre_stmts.extend(post_stmts);
        pre_stmts
    }
}
