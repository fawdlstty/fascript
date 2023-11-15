use fascript::fascript::Fascript;

#[tokio::main]
async fn main() {
    let code_str = r#"
    void main() {
        println("hello world")
    }
    main()
    "#;
    _ = Fascript::eval(code_str).await;
}
