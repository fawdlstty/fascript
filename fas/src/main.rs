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
    println("hello world")
    "#;
    let mut runtime = FasRuntime::new();
    //runtime.set_func("hello".into(), |a: String, b: String| -> i64 {
    //    //println!("content: {}", content)
    //    42
    //});
    _ = runtime.run(code_str).await;
}
