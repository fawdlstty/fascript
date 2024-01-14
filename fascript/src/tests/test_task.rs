use crate::tests::test_utils::TestUtils;

#[test]
fn test_retry() {
    let code = r#"
        @on_abort_retry_count = 3
        @on_abort_retry_interval = 100.millisec
        task retry_func() {
            test.cache_str("a")
            abort
        }
        var str = ""
        var t = retry_func()
        await(50.millisec) t
        if test.get_cache() == "a" {
            str += "a"
        }
        await(100.millisec) t
        if test.get_cache() == "aa" {
            str += "a"
        }
        await(100.millisec) t
        if test.get_cache() == "aaa" {
            str += "a"
        }
        await(100.millisec) t
        if test.get_cache() == "aaaa" {
            str += "a"
        }
        str
    "#;
    println!("code: {}", code);
    let _value = TestUtils::eval_code(&code).unwrap().as_str();
    assert_eq!(&_value, "aaaa");
}
