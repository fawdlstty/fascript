use super::AstExpr;
use crate::{ast::types::AstType, utils::oper_utils::OperUtils};

#[derive(Clone, Debug)]
pub struct AstOp2Expr {
    pub left: Box<AstExpr>,
    pub op: String,
    pub right: Box<AstExpr>,
}

impl AstOp2Expr {
    pub fn new(left: AstExpr, op: String, right: AstExpr) -> AstExpr {
        AstExpr::Op2(AstOp2Expr {
            left: Box::new(left),
            op,
            right: Box::new(right),
        })
    }

    pub fn get_type(&self) -> AstType {
        let left_type = self.left.get_type();
        let right_type = self.right.get_type();
        if OperUtils::is_assign_op2(&self.op) {
            return left_type;
        }
        if OperUtils::is_calc_op2(&self.op) {
            return match &self.op[..] {
                ">" => AstType::Bool,
                ">=" => AstType::Bool,
                "<" => AstType::Bool,
                "<=" => AstType::Bool,
                "==" => AstType::Bool,
                "!=" => AstType::Bool,
                "??" => right_type,
                _ => left_type,
            };
        }
        todo!()
    }
}
