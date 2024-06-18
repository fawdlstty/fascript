use crate::tests::test_utils::TestUtils;

#[test]
fn test_func() {
    let code = r#"
        func test_func(string s) {
            return s
        }

        test_func("hello world")
    "#;
    println!("code: {}", code);
    let _value = TestUtils::eval_code(code).unwrap().as_type::<String>();
    assert_eq!(&_value, "hello world");
}
