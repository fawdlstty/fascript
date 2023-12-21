use chrono::Duration;
use chrono::NaiveDateTime;
use std::sync::Mutex;

lazy_static::lazy_static! {
    pub static ref NOW_MICROS: Mutex<i64> = Mutex::new(-1);
}

pub trait NaiveDateTimeExt {
    fn now() -> Self;
    fn now_unique() -> Self;
}

impl NaiveDateTimeExt for NaiveDateTime {
    fn now() -> Self {
        let now = chrono::Utc::now().naive_local().timestamp_micros();
        NaiveDateTime::from_timestamp_micros(now).unwrap_or(chrono::Utc::now().naive_local())
    }

    fn now_unique() -> Self {
        let mut guard = NOW_MICROS.lock().unwrap();
        let now = chrono::Utc::now().naive_local().timestamp_micros();
        *guard = match *guard >= now {
            true => *guard + 1,
            false => now,
        };
        NaiveDateTime::from_timestamp_micros(*guard).unwrap_or(chrono::Utc::now().naive_local())
    }
}

pub trait DurationExt {
    fn format(&self) -> String;
    fn to_dur(&self) -> std::time::Duration;
}

impl DurationExt for Duration {
    fn format(&self) -> String {
        let d = self.num_microseconds().unwrap_or(0) as f64;
        match 0 {
            _ if d < 1000.0 => format!("{:.02} microsecond", d),
            _ if d < 1_000_000.0 => format!("{:.02} millisecond", d / 1000.0),
            _ if d < 60_000_000.0 => format!("{:.02} second", d / 1_000_000.0),
            _ if d < 3_600_000_000.0 => format!("{:.02} minute", d / 60_000_000.0),
            _ if d < 86_400_000_000.0 => format!("{:.02} hour", d / 3_600_000_000.0),
            _ if d < 86_400_000_000.0 * 30.0 => format!("{:.02} day", d / 86_400_000_000.0),
            _ if d < 86_400_000_000.0 * 360.0 => {
                format!("{:.02} month", d / 86_400_000_000.0 / 30.0)
            }
            _ => format!("{:.02} year", d / 86_400_000_000.0 / 365.0),
        }
    }

    fn to_dur(&self) -> std::time::Duration {
        std::time::Duration::from_nanos(self.num_nanoseconds().unwrap_or(0) as u64)
    }
}
