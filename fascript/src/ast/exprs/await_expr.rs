use super::AstExpr;

#[derive(Clone, Debug)]
pub struct AstAwaitExpr {
    pub wait: Option<Box<AstExpr>>,
    pub value: Box<AstExpr>,
}

impl AstAwaitExpr {
    pub fn new(wait: Option<AstExpr>, value: AstExpr) -> AstExpr {
        let wait = match wait {
            Some(wait) => Some(Box::new(wait)),
            None => None,
        };
        let value = Box::new(value);
        AstExpr::Await(AstAwaitExpr { wait, value })
    }
}
