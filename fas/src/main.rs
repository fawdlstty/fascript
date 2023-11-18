use fascript::Fascript;

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
    _ = Fascript::eval(code_str).await;
}
