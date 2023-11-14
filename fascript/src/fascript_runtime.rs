use crate::{
    ast::{blocks::program::AstProgram, exprs::value_expr::AstValueExpr, FromStringExt},
    exec::task_runner::TaskRunner,
};

pub struct FascriptRuntime {
    runner: TaskRunner,
}

impl FascriptRuntime {
    pub fn new() -> FascriptRuntime {
        FascriptRuntime {
            runner: TaskRunner::new(),
        }
    }

    pub async fn eval(&mut self, code: &str) -> Option<AstValueExpr> {
        let stmts = match AstProgram::from_str(code) {
            Ok(program) => program.stmts,
            Err(err) => {
                println!("parse error: {}", err);
                return None;
            }
        };
        for stmt in stmts {
            //println!("stmt: {:?}", stmt);
            self.runner.eval_stmt(stmt);
        }
        self.runner.get_return_value()
    }
}
