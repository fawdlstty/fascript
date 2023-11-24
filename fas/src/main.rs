use fascript::FasRuntime;

#[tokio::main]
async fn main() {
    let code_str = r#"
    // void main() {
    //     int n = 0
    //     while true {
    //         n += 1
    //         if n == 4 {
    //             break
    //         }
    //         println("hello world")
    //     }
    // }
    // main()
    my_println("hello world")
    "#;
    let mut runtime = FasRuntime::new();
    runtime.set_func("my_println".into(), |value: String| println!("{}", value));
    _ = runtime.run(code_str).await;
}
