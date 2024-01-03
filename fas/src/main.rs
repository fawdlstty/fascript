use fascript::FasRuntime;

#[tokio::main]
async fn main() {
    let code_str = r#"
    // func main() {
    //    os.println("hello world")
    //    os.pppp = (string s) => os.println(s)
    //    os.pppp("aaa")
    //    os.pppp("bbb")
    // }
    @on_abort_retry_count = 3
    @on_abort_retry_interval = 40.millisec
    task retry_method() {
        test.cache_str("a")
        abort
    }
    func main() {
        var str = ""
        var t = retry_method()
        await(20.millisec) t
        os.println(test.get_cache())
        await(40.millisec) t
        os.println(test.get_cache())
        await(40.millisec) t
        os.println(test.get_cache())
        await(40.millisec) t
        os.println(test.get_cache())
    }
    main()
    "#;
    let mut runtime = FasRuntime::new();
    //runtime.set_func("my_println", |value: String| println!("{}", value));
    _ = runtime.run(code_str).await;
    //let _ret = runtime.run(code_str).await;
    //println!("{:?}", _ret);
}
