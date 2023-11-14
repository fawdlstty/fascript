mod ast;
mod exec;
mod fascript;
mod fascript_runtime;
mod utils;

use ast::{blocks::program::AstProgram, *};
use exec::task_runner::TaskRunner;

fn main() {
    let code_str = r#"
    void main() {
        //println("hello world")
        int a = 1 + 1
    }
    main()
    "#;
    let stmts = match AstProgram::from_str(code_str) {
        Ok(program) => program.stmts,
        Err(err) => {
            println!("parse error: {}", err);
            return;
        }
    };
    let mut runner = TaskRunner::new();
    for stmt in stmts {
        //println!("stmt: {:?}", stmt);
        runner.eval_stmt(stmt);
    }
}
