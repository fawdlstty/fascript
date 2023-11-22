use fascript::FasRuntime;

#[tokio::main]
async fn main() {
    let code_str = r#"
    void main() {
        func()
    }
    void func() {
        int n = 0
        while true {
            n += 1
            if n == 4 {
                break
            }
            println("hello world")
        }
    }
    main()
    "#;
    let runtime = FasRuntime::new();
    runtime.set_func("hello".into(), |a: String, b: String| -> i64 {
        //println!("content: {}", content)
        42
    });
    _ = runtime.run(code_str).await;
}
