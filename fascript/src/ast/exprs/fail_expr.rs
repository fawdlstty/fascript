use super::AstExpr;

#[derive(Clone, Debug)]
pub struct AstFailExpr {
    pub value: Box<AstExpr>,
}

impl AstFailExpr {
    pub fn new(value: AstExpr) -> AstExpr {
        let value = Box::new(value);
        AstExpr::Fail(AstFailExpr { value })
    }
}
