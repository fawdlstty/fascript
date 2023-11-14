use crate::ast::types::AstType;

use super::{func_expr::AstFuncExpr, AstExpr};

#[derive(Clone, Debug)]
pub struct AstTypeWrapExpr {
    item_type: AstType,
}

impl AstTypeWrapExpr {
    pub fn new(item_type: AstType) -> AstExpr {
        AstExpr::TypeWrap(AstTypeWrapExpr { item_type })
    }
}
