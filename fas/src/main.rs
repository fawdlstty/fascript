use clap::Parser;
use fascript::ast::exprs::value_expr::FasValue;
use fascript::FasRuntime;
use std::fs::File;
use std::io::{Read, Write};

/// Host program for the fascript language runtime
#[derive(Parser, Debug)]
#[command(author, version, about, long_about = None, disable_version_flag = true)]
struct Args {
    #[arg(short = 'v', short_alias = 'V', long, action = clap::builder::ArgAction::Version)]
    version: (),

    /// Path of the *.fas file
    #[arg(short, long, default_value_t = String::from(""))]
    path: String,
}

fn get_input(tip: &str) -> String {
    print!("{}", tip);
    _ = std::io::stdout().flush();
    let mut input = String::new();
    std::io::stdin()
        .read_line(&mut input)
        .expect("input failed");
    return input;
}

#[tokio::main]
async fn main() {
    let mut runtime = FasRuntime::new();
    let path = Args::parse().path;
    if path.is_empty() {
        // [cmd] cargo run
        println!("{} v{}", env!("CARGO_PKG_NAME"), env!("CARGO_PKG_VERSION"));
        runtime.set_func("my_println", |value: String| println!("{}", value));
        loop {
            let mut code_str = get_input(">>> ");
            if code_str.len() == 0 {
                continue;
            }
            let tmp = code_str.trim();
            let ch: &str = &tmp[(tmp.len() - 1)..];
            if ch == "{" {
                loop {
                    let tmp_code_str = get_input("... ");
                    if tmp_code_str.trim().len() == 0 {
                        break;
                    }
                    code_str.push_str(&tmp_code_str);
                }
            }
            let oval = runtime.run(&code_str).await;
            if let Some(val) = oval {
                if val != FasValue::None {
                    println!("{}", val.as_str());
                }
            }
        }
    } else {
        // [cmd] cargo run -- --path example/task.fas
        let mut file = File::open(&path).expect("open file failed");
        let mut code_str = String::new();
        file.read_to_string(&mut code_str)
            .expect("read file failed");
        drop(file);
        _ = runtime.run(&code_str).await;
    }
}
