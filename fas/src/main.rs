use fascript::Fascript;

#[tokio::main]
async fn main() {
    let code_str = r#"
    void main() {
        for i in 1..10 {
            println("hello world")
        }
    }
    main()
    "#;
    _ = Fascript::eval(code_str).await;
}
