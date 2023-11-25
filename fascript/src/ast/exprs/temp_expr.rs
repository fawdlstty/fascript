use super::AstExpr;

#[derive(Clone, Debug)]
pub struct AstTempExpr {
    pub name: String,
}

impl AstTempExpr {
    pub fn new(name: String) -> AstExpr {
        AstExpr::Temp(AstTempExpr { name })
    }
}
