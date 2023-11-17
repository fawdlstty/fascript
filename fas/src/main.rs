use fascript::Fascript;

#[tokio::main]
async fn main() {
    let code_str = r#"
    void main() {
        for i in 0..5 {
            println("hello world")
        }
    }
    main()
    "#;
    _ = Fascript::eval(code_str).await;
}
