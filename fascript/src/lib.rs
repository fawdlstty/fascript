pub mod ast;
pub mod exec;
pub mod fascript_runtime;
pub mod utils;

use crate::{ast::exprs::value_expr::AstValueExpr, fascript_runtime::FascriptRuntime};
use lazy_static::lazy_static;
use tokio::sync::Mutex;

lazy_static! {
    pub static ref RUNTIME_INST: Mutex<FascriptRuntime> = Mutex::new(FascriptRuntime::new());
}

pub struct Fascript {}

impl Fascript {
    pub async fn eval(code: &str) -> Option<AstValueExpr> {
        let mut runtime_inst = RUNTIME_INST.lock().await;
        runtime_inst.eval(code).await
    }

    pub fn create_runtime() -> FascriptRuntime {
        FascriptRuntime::new()
    }
}
