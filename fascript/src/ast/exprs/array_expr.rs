use super::AstExpr;

#[derive(Clone, Debug)]
pub struct AstArrayExpr {
    pub values: Vec<AstExpr>,
}

impl AstArrayExpr {
    pub fn new(values: Vec<AstExpr>) -> AstExpr {
        AstExpr::Array(AstArrayExpr { values })
    }
}
