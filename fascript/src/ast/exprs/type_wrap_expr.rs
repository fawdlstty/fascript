use super::AstExpr;
use crate::ast::types::AstType;

#[derive(Clone, Debug)]
pub struct AstTypeWrapExpr {
    _item_type: AstType,
}

impl AstTypeWrapExpr {
    pub fn new(_item_type: AstType) -> AstExpr {
        AstExpr::TypeWrap(AstTypeWrapExpr { _item_type })
    }
}
