use super::AstExpr;
use crate::ast::types::AstType;

#[derive(Clone, Debug)]
pub struct AstIndexExpr {
    pub left: Option<Box<AstExpr>>,
    pub right: Option<Box<AstExpr>>,
}

impl AstIndexExpr {
    pub fn new(left: Option<AstExpr>, right: Option<AstExpr>) -> AstExpr {
        let left = match left {
            Some(left) => Some(Box::new(left)),
            None => None,
        };
        let right = match right {
            Some(right) => Some(Box::new(right)),
            None => None,
        };
        AstExpr::Index(AstIndexExpr { left, right })
    }

    pub fn get_type(&self) -> AstType {
        AstType::Index
    }
}
