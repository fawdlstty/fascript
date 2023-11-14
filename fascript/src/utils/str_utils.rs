enum NextProcessType {
    Normal,
    Escape,
    Hex1,
    Hex2,
}

pub struct StrUtils {}

impl StrUtils {
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
}
