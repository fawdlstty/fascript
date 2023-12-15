use super::AstExpr;

#[derive(Clone, Debug)]
pub struct AstReportExpr {
    pub value: Box<AstExpr>,
}

impl AstReportExpr {
    pub fn new(value: AstExpr) -> AstExpr {
        let value = Box::new(value);
        AstExpr::Fail(AstReportExpr { value })
    }
}
