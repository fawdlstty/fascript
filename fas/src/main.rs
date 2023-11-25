use fascript::FasRuntime;

#[tokio::main]
async fn main() {
    let code_str = r#"
    void main() {
        os.println("hello world")
        //os.println = (string s) => os.print(s)
        //os.println("hello")
        //os.println("hello")
        //os.println("hello")
    }
    main()
    "#;
    let mut runtime = FasRuntime::new();
    //runtime.set_func("my_println", |value: String| println!("{}", value));
    _ = runtime.run(code_str).await;
}
