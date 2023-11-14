use std::collections::HashMap;
use std::collections::HashSet;

macro_rules! hashset {
    ( $( $x:expr ),* ) => {{
        let mut tmp = HashSet::new();
            $(
                tmp.insert($x);
            )*
            tmp
    }};
}

macro_rules! hashmap {
    ( $( ($a:expr, $b:expr) ),* ) => {{
        let mut tmp = HashMap::new();
            $(
                tmp.insert($a, $b);
            )*
            tmp
    }};
}

pub struct OperUtils {}

impl OperUtils {
    pub fn is_assign_op2(op: &str) -> bool {
        let assign_op2s = hashset![
            "=", "+=", "-=", "*=", "/=", "**=", "%=", "|=", "&=", "^=", "&&=", "||=", "<<=", ">>=",
            "??="
        ];
        assign_op2s.contains(op)
    }

    pub fn is_calc_op2(op: &str) -> bool {
        let calc_op2s = hashset![
            "+", "-", "*", "/", "**", "%", "|", "&", "^", "&&", "||", "<<", ">>", ">", ">=", "<",
            "<=", "==", "!=", "??"
        ];
        calc_op2s.contains(op)
    }

    pub fn get_op2_privilege(op: &str) -> i32 {
        let priv_calc_op2s = hashmap![
            ("||", 0),
            ("&&", 1),
            (">", 2),
            (">=", 2),
            ("<", 2),
            ("<=", 2),
            ("==", 3),
            ("!=", 3),
            ("??", 4),
            ("&", 5),
            ("|", 5),
            ("^", 5),
            ("<<", 6),
            (">>", 6),
            ("+", 7),
            ("-", 7),
            ("*", 8),
            ("/", 8),
            ("%", 8),
            ("**", 9)
        ];
        return *priv_calc_op2s.get(op).unwrap();
    }
}
