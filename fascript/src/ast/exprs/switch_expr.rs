use super::AstExpr;

#[derive(Clone, Debug)]
pub struct AstSwitchExpr {
    pub expr: Box<AstExpr>,
    pub conds: Vec<AstExpr>,
    pub values: Vec<AstExpr>,
}
