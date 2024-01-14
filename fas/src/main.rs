use clap::Parser;
use fascript::ast::exprs::value_expr::FasValue;
use fascript::FasRuntime;
use std::fs::File;
use std::io::{Read, Write};

/// Host program for the fascript language runtime
#[derive(Parser, Debug)]
#[command(author, version, about, long_about = None)]
struct Args {
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
    return input.trim().to_string();
}

#[tokio::main]
async fn main() {
    let mut runtime = FasRuntime::new();
    let path = Args::parse().path;
    if path.is_empty() {
        // [cmd] cargo run
        println!("{} v{}", env!("CARGO_PKG_NAME"), env!("CARGO_PKG_VERSION"));
        loop {
            let mut code_str = get_input(">>> ");
            if code_str.len() == 0 {
                continue;
            }
            let ch: &str = &code_str[(code_str.len() - 1)..];
            if ch == "{" {
                let mut level = 1;
                while level > 0 {
                    let tmp_code_str = get_input("... ");
                    if tmp_code_str.len() == 0 {
                        continue;
                    }
                    let ch: &str = &tmp_code_str[(tmp_code_str.len() - 1)..];
                    match ch {
                        "{" => level += 1,
                        "}" => level -= 1,
                        _ => {}
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
        // [cmd] cargo run -- --path a.fas
        let mut file = File::open(&path).expect("open file failed");
        let mut code_str = String::new();
        file.read_to_string(&mut code_str)
            .expect("read file failed");
        drop(file);
        _ = runtime.run(&code_str).await;
    }
    ////runtime.set_func("my_println", |value: String| println!("{}", value));
}
