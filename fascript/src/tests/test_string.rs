use crate::tests::test_utils::TestUtils;

#[test]
fn test_format() {
    let code = r#"$"a {12} c""#;
    println!("code: {}", code);
    let _value = TestUtils::eval_code(code).unwrap().as_type::<String>();
    assert_eq!(&_value, "a 12 c");
}
