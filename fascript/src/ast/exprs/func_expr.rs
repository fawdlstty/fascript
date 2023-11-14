use crate::ast::blocks::func::AstFunc;

#[derive(Clone, Debug)]
pub struct AstFuncExpr {
    pub func: Box<AstFunc>,
}

impl AstFuncExpr {
    pub fn new(func: AstFunc) -> Self {
        AstFuncExpr {
            func: Box::new(func),
        }
    }
}
