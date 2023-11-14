use super::AstExpr;
use crate::ast::types::AstType;

#[derive(Clone, Debug)]
pub struct AstTempExpr {
    pub otype: Option<AstType>,
    pub name: String,
}

impl AstTempExpr {
    pub fn new(otype: Option<AstType>, name: String) -> AstExpr {
        AstExpr::Temp(AstTempExpr { otype, name })
    }
}
