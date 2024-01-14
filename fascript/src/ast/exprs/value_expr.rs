use super::func_expr::AstFuncExpr;
use crate::ast::types::AstType;
use crate::utils::time_utils::DurationExt;
use chrono::Duration;
use chrono::NaiveDateTime;
use crossbeam::channel;
use std::collections::HashMap;

#[derive(Clone, Debug)]
pub enum TaskControl {
    Pause,
    Resume,
    Cancel,
    Rollback,
}

#[derive(Clone, Debug)]
pub enum TaskResult {
    Success(Box<FasValue>),
    Failure(Box<FasValue>),
    Canceled,
    Rolledbacked,
}

pub enum TaskReply {
    TaskResult(TaskResult),
    TaskProgress(NaiveDateTime),
}

#[derive(Clone, Debug)]
pub struct TaskValue {
    pub ctrl_tx: channel::Sender<TaskControl>,
    pub result_rx: channel::Receiver<TaskReply>,
}

#[derive(Clone, Debug)]
pub struct TaskValueShadow {
    pub ctrl_rx: channel::Receiver<TaskControl>,
    pub result_tx: channel::Sender<TaskReply>,
}

impl TaskValue {
    pub fn create() -> (TaskValue, TaskValueShadow) {
        let (ctrl_tx, ctrl_rx) = channel::unbounded();
        let (result_tx, result_rx) = channel::unbounded();
        (
            TaskValue { ctrl_tx, result_rx },
            TaskValueShadow { ctrl_rx, result_tx },
        )
    }
}

#[derive(Clone, Debug)]
pub enum FasValue {
    Array(Vec<FasValue>),
    Bool(bool),
    DateTime(NaiveDateTime),
    Float(f64),
    Func(Box<AstFuncExpr>),
    IMap(HashMap<i64, FasValue>),
    Int(i64),
    None,
    SMap(HashMap<String, FasValue>),
    String(String),
    Task(TaskValue),
    TaskResult(TaskResult),
    TimeSpan(Duration),
    Future(crossbeam::channel::Receiver<FasValue>),
}

unsafe impl Send for FasValue {}

impl PartialEq for FasValue {
    fn eq(&self, other: &Self) -> bool {
        match (self, other) {
            (Self::Bool(l0), Self::Bool(r0)) => l0 == r0,
            (Self::Int(l0), Self::Int(r0)) => l0 == r0,
            (Self::Float(l0), Self::Float(r0)) => (l0 - r0).abs() <= 0.000001,
            (Self::String(l0), Self::String(r0)) => l0 == r0,
            (Self::Array(l0), Self::Array(r0)) => l0 == r0,
            (Self::IMap(l0), Self::IMap(r0)) => l0 == r0,
            (Self::SMap(l0), Self::SMap(r0)) => l0 == r0,
            (Self::Func(_l0), Self::Func(_r0)) => false, //*l0.func == *r0.func,
            (Self::Future(_l0), Self::Future(_r0)) => false, //*l0.func == *r0.func,
            _ => core::mem::discriminant(self) == core::mem::discriminant(other),
        }
    }
}

impl Eq for FasValue {}

impl FasValue {
    pub fn get_type(&self) -> AstType {
        match self {
            FasValue::Array(v) => AstType::Array,
            FasValue::Bool(_) => AstType::Bool,
            FasValue::DateTime(_) => AstType::DateTime,
            FasValue::Float(_) => AstType::Float,
            FasValue::Func(f) => f.func.get_type(),
            FasValue::IMap(im) => AstType::IMap,
            FasValue::Int(_) => AstType::Int,
            FasValue::None => AstType::Void,
            FasValue::SMap(sm) => AstType::SMap,
            FasValue::String(_) => AstType::String,
            FasValue::Task(_) => AstType::Task,
            FasValue::TaskResult(_) => AstType::TaskResult,
            FasValue::TimeSpan(_) => AstType::TimeSpan,
            FasValue::Future(_) => AstType::Future,
        }
    }

    pub fn as_str(&self) -> String {
        match self {
            FasValue::Array(v) => {
                let items: Vec<String> = v.iter().map(|x| x.as_str()).collect();
                format!("[ {} ]", items.join(", "))
            }
            FasValue::Bool(b) => match b {
                true => "true".to_string(),
                false => "false".to_string(),
            },
            FasValue::DateTime(dt) => dt.format("%Y-%m-%d %H:%M:%S").to_string(),
            FasValue::Float(f) => format!("{:.4}", f),
            FasValue::Func(_) => "(func)".to_string(),
            FasValue::IMap(im) => {
                let items: Vec<String> = im
                    .iter()
                    .map(|x| format!("{}: {}", x.0, x.1.as_str()))
                    .collect();
                format!("{{ {} }}", items.join(", "))
            }
            FasValue::Int(n) => format!("{}", n),
            FasValue::None => "(null)".to_string(),
            FasValue::String(s) => s.to_string(),
            FasValue::SMap(sm) => {
                let items: Vec<String> = sm
                    .iter()
                    .map(|x| format!("{}: {}", x.0, x.1.as_str()))
                    .collect();
                format!("{{ {} }}", items.join(", "))
            }
            FasValue::Task(_) => "(task)".to_string(),
            FasValue::TaskResult(_) => "(task_result)".to_string(),
            FasValue::TimeSpan(ts) => ts.format(),
            FasValue::Future(ts) => "(future)".to_string(),
        }
    }

    pub fn as_array(&self) -> Vec<FasValue> {
        match self {
            FasValue::Array(arr) => arr.clone(),
            _ => unreachable!(),
        }
    }

    pub fn as_bool(&self) -> bool {
        match self {
            FasValue::Bool(b) => b.clone(),
            _ => unreachable!(),
        }
    }

    pub fn as_float(&self) -> f64 {
        match self {
            FasValue::Float(f) => f.clone(),
            FasValue::Int(i) => i.clone() as f64,
            _ => unreachable!(),
        }
    }

    pub fn as_future(&self) -> crossbeam::channel::Receiver<FasValue> {
        match self {
            FasValue::Future(f) => f.clone(),
            _ => unreachable!(),
        }
    }

    pub fn as_int(&self) -> i64 {
        match self {
            FasValue::Float(f) => f.round() as i64,
            FasValue::Int(i) => i.clone(),
            _ => unreachable!(),
        }
    }

    pub fn as_imap(&self) -> HashMap<i64, FasValue> {
        match self {
            FasValue::IMap(map) => map.clone(),
            _ => unreachable!(),
        }
    }

    pub fn as_smap(&self) -> HashMap<String, FasValue> {
        match self {
            FasValue::SMap(map) => map.clone(),
            _ => unreachable!(),
        }
    }

    pub fn as_datetime(&self) -> NaiveDateTime {
        match self {
            FasValue::DateTime(dt) => dt.clone(),
            _ => unreachable!(),
        }
    }

    pub fn as_task(self) -> TaskValue {
        match self {
            FasValue::Task(t) => t,
            _ => unreachable!(),
        }
    }

    pub fn as_taskresult(self) -> TaskResult {
        match self {
            FasValue::TaskResult(tr) => tr,
            _ => unreachable!(),
        }
    }

    pub fn as_timespan(&self) -> Duration {
        match self {
            FasValue::TimeSpan(ts) => ts.clone(),
            _ => unreachable!(),
        }
    }

    pub fn as_type(&self, dest_type: AstType) -> FasValue {
        if self.get_type() != dest_type {
            match dest_type {
                AstType::None => FasValue::None,
                AstType::Array => FasValue::Array(self.as_array()),
                AstType::Bool => self.as_bool().into(),
                AstType::DateTime => self.clone(),
                AstType::Float => self.as_float().into(),
                AstType::Func(_) => todo!(),
                AstType::Future => FasValue::Future(self.as_future()),
                AstType::Index => unreachable!(),
                AstType::Int => self.as_int().into(),
                AstType::IMap => todo!(),
                AstType::SMap => todo!(),
                AstType::String => self.as_str().into(),
                AstType::TimeSpan => self.clone(),
                AstType::Tuple(_) => todo!(),
                AstType::Void => FasValue::None,
                AstType::Task => todo!(),
                AstType::TaskResult => todo!(),
            }
        } else {
            self.clone()
        }
    }
}

pub trait GetAstTypeTrait {
    fn get_ast_type() -> AstType;
}

macro_rules! define_cast {
    ($type:ty, $v2t:tt, $t2v:tt) => {
        impl From<FasValue> for $type {
            fn from(v: FasValue) -> $type {
                v.$v2t()
            }
        }

        impl From<$type> for FasValue {
            fn from(v: $type) -> FasValue {
                FasValue::$t2v(v)
            }
        }

        impl GetAstTypeTrait for $type {
            fn get_ast_type() -> AstType {
                AstType::$t2v
            }
        }
    };
}

//define_cast2!((), as_void, None);
define_cast!(bool, as_bool, Bool);
define_cast!(f64, as_float, Float);
define_cast!(i64, as_int, Int);
define_cast!(String, as_str, String);
define_cast!(NaiveDateTime, as_datetime, DateTime);
define_cast!(Duration, as_timespan, TimeSpan);

// void

impl From<FasValue> for () {
    fn from(_: FasValue) -> () {
        ()
    }
}

impl From<()> for FasValue {
    fn from(_: ()) -> FasValue {
        FasValue::None
    }
}

impl GetAstTypeTrait for () {
    fn get_ast_type() -> AstType {
        AstType::None
    }
}

// &str

impl From<&str> for FasValue {
    fn from(s: &str) -> FasValue {
        FasValue::String(s.into())
    }
}

impl GetAstTypeTrait for &str {
    fn get_ast_type() -> AstType {
        AstType::String
    }
}

// // future    ?Sized + Future + Unpin

// impl<T> From<FasValue> for dyn Future<Output = T>
// where
//     T: Into<FasValue>,
//     dyn Future<Output = T>: Sized,
// {
//     fn from(val: FasValue) -> Self {
//         if let FasValue::Future(fut) = val {
//             async fn _async_wrap(fut: Receiver<FasValue>) -> FasValue {
//                 loop {
//                     match fut.try_recv() {
//                         Ok(val) => return val,
//                         Err(_) => tokio::time::sleep(Duration::milliseconds(1).to_dur()).await,
//                     }
//                 }
//             }
//             let ret = _async_wrap(fut);
//             ret
//         } else {
//             async fn async_value(value: FasValue) -> FasValue {
//                 value
//             }
//             let ret = async_value(val);
//             ret
//         }
//     }
// }

// //unsafe impl<T> Send for dyn Future<Output = T> where T: Into<FasValue> {}

// impl<T> From<dyn Future<Output = T>> for FasValue
// where
//     T: Into<FasValue> + Sized,
//     dyn Future<Output = T>: Sized + Send,
//     T: 'static,
// {
//     fn from(val: dyn Future<Output = T>) -> FasValue {
//         let (cx, rx) = crossbeam::channel::unbounded();
//         tokio::task::spawn(async move {
//             let val = val.await.into();
//             _ = cx.send(val);
//         });
//         FasValue::Future(rx)
//     }
// }

// impl<T> GetAstTypeTrait for dyn Future<Output = T>
// where
//     T: Into<FasValue>,
// {
//     fn get_ast_type() -> AstType {
//         AstType::Future
//     }
// }
