use crate::ast::{exprs::AstExpr, Rule};
use rand::{distributions::Alphanumeric, Rng};

enum NextProcessType {
    Normal,
    Escape,
    Hex1,
    Hex2,
}

pub struct StrUtils {}

impl StrUtils {
    pub fn rand_str(length: usize) -> String {
        let mut rng = rand::thread_rng();
        let ret: Vec<_> = std::iter::repeat(())
            .map(|()| rng.sample(Alphanumeric))
            .take(length)
            .collect();
        format!("_{}", String::from_utf8(ret).unwrap_or("a".to_string()))
    }

    pub fn code_to_str(code: &str) -> String {
        const S_HEXSTR: &str = "0123456789ABCDEF0123456789abcdef";
        let code = &code[1..(code.len() - 1)];
        let mut ret = String::new();
        let mut next_proc = NextProcessType::Normal;
        let mut last_hex = 0;
        for ch in code.chars() {
            ret.push(match (&next_proc, &ch) {
                (NextProcessType::Normal, '\\') => {
                    next_proc = NextProcessType::Escape;
                    continue;
                }
                (NextProcessType::Escape, '\\') => '\\',
                (NextProcessType::Escape, 'r') => '\r',
                (NextProcessType::Escape, 'n') => '\n',
                (NextProcessType::Escape, 't') => '\t',
                (NextProcessType::Escape, '0') => '\0',
                (NextProcessType::Escape, 'x') => {
                    next_proc = NextProcessType::Hex1;
                    continue;
                }
                (NextProcessType::Hex1, _) => {
                    next_proc = NextProcessType::Hex2;
                    last_hex = (S_HEXSTR.find(ch).unwrap() % 16) * 16;
                    continue;
                }
                (NextProcessType::Hex2, _) => {
                    next_proc = NextProcessType::Normal;
                    last_hex += S_HEXSTR.find(ch).unwrap() % 16;
                    last_hex as u8 as char
                }
                _ => ch,
            });
        }
        ret
    }

    pub fn code_to_fmt_strs(root: pest::iterators::Pair<'_, Rule>) -> (Vec<String>, Vec<AstExpr>) {
        let mut strs = vec![];
        let mut exprs = vec![];
        for root_item in root.into_inner() {
            match root_item.as_rule() {
                Rule::FmtStringLiteral1 => strs.push(Self::code_to_str(&root_item.as_str()[1..])),
                Rule::FmtStringLiteral2 => strs.push(Self::code_to_str(root_item.as_str())),
                Rule::FmtStringLiteral3 => strs.push(Self::code_to_str(root_item.as_str())),
                Rule::Expr1 => {
                    let root_item2 = root_item.into_inner().next().unwrap();
                    exprs.push(AstExpr::parse_base_expr(root_item2));
                }
                _ => unreachable!(),
            }
        }
        (strs, exprs)
    }
}
