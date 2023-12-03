use rand::Rng;

use crate::ast::exprs::value_expr::FasValue;
use crate::FasRuntime;

pub struct TestUtils {}

impl TestUtils {
    pub fn eval_code(code: &str) -> Option<FasValue> {
        let runtime = tokio::runtime::Builder::new_multi_thread()
            .enable_all()
            .build()
            .unwrap();
        runtime.block_on(async move { FasRuntime::new().run(code).await })
    }

    pub fn random<T: RandomExt>() -> T {
        T::generate()
    }
}

pub trait RandomExt {
    fn generate() -> Self;
}

impl RandomExt for bool {
    fn generate() -> Self {
        rand::thread_rng().gen_bool(0.5)
    }
}

impl RandomExt for i64 {
    fn generate() -> Self {
        rand::thread_rng().gen_range(-100000..=100000)
    }
}

impl RandomExt for f64 {
    fn generate() -> Self {
        rand::thread_rng().gen_range(-100000.0..=100000.0)
    }
}

impl RandomExt for String {
    fn generate() -> Self {
        let mut rng = rand::thread_rng();
        let count = i64::generate() % 128;
        (0..count)
            .map(|_| {
                let ascii_code = rng.gen_range(97..123);
                ascii_code as u8 as char
            })
            .collect()
    }
}
