use crate::{ast::types::AstType, tests::test_utils::TestUtils};

#[test]
fn test_op4() {
    for op in vec!["+", "-", "*", "/"] {
        let a = TestUtils::random::<i64>();
        let b = TestUtils::random::<i64>();
        let code = format!("{} {} {}", a, op, b);
        println!("code: {}", code);
        let value = TestUtils::eval_code(&code).unwrap();
        assert_eq!(value.get_type(), AstType::Int);
        let value2 = match op {
            "+" => a + b,
            "-" => a - b,
            "*" => a * b,
            "/" => a / b,
            _ => panic!(),
        };
        assert_eq!(value.as_int(), value2);
    }
}
