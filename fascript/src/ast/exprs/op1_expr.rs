use super::AstExpr;

#[derive(Clone, Debug)]
pub struct AstOp1Expr {
    pub left: Box<AstExpr>,
    pub op: String,
    pub is_prefix: bool,
}

impl AstOp1Expr {
    pub fn new(left: AstExpr, op: String, is_prefix: bool) -> AstExpr {
        AstExpr::Op1(AstOp1Expr {
            left: Box::new(left),
            op,
            is_prefix,
        })
    }
}
