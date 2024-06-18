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
            FasValue::Array(arr) => {
                if arr.len() == 0 {
                    panic!();
                }
                arr[0].get_type()
            }
            FasValue::Bool(_) => AstType::Bool,
            FasValue::DateTime(_) => AstType::DateTime,
            FasValue::Float(_) => AstType::Float,
            FasValue::Func(f) => f.func.get_type(),
            FasValue::IMap(_) => AstType::Map((Box::new(AstType::Int), Box::new(AstType::Any))),
            FasValue::Int(_) => AstType::Int,
            FasValue::None => AstType::Void,
            FasValue::SMap(_) => AstType::Map((Box::new(AstType::String), Box::new(AstType::Any))),
            FasValue::String(_) => AstType::String,
            FasValue::Task(_) => AstType::Task,
            FasValue::TaskResult(_) => AstType::TaskResult,
            FasValue::TimeSpan(_) => AstType::TimeSpan,
            FasValue::Future(_) => AstType::Future(Box::new(AstType::Any)),
        }
    }

    pub fn as_type<T: AsTypeTrait>(self) -> T {
        T::as_type(self)
    }
}

pub trait AsTypeTrait {
    fn as_type(val: FasValue) -> Self;
}

impl AsTypeTrait for String {
    fn as_type(val: FasValue) -> Self {
        match val {
            FasValue::Array(v) => {
                let items: Vec<String> = v.into_iter().map(|x| x.as_type::<String>()).collect();
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
                    .map(|x| format!("{}: {}", x.0, x.1.clone().as_type::<String>()))
                    .collect();
                format!("{{ {} }}", items.join(", "))
            }
            FasValue::Int(n) => format!("{}", n),
            FasValue::None => "(null)".to_string(),
            FasValue::String(s) => s.to_string(),
            FasValue::SMap(sm) => {
                let items: Vec<String> = sm
                    .iter()
                    .map(|x| format!("{}: {}", x.0, x.1.clone().as_type::<String>()))
                    .collect();
                format!("{{ {} }}", items.join(", "))
            }
            FasValue::Task(_) => "(task)".to_string(),
            FasValue::TaskResult(_) => "(task_result)".to_string(),
            FasValue::TimeSpan(ts) => ts.format(),
            FasValue::Future(_) => "(future)".to_string(),
        }
    }
}

impl AsTypeTrait for Vec<FasValue> {
    fn as_type(val: FasValue) -> Self {
        match val {
            FasValue::Array(arr) => arr,
            _ => unreachable!(),
        }
    }
}

impl AsTypeTrait for Vec<String> {
    fn as_type(val: FasValue) -> Self {
        match val {
            FasValue::Array(arr) => arr.into_iter().map(|x| x.as_type::<String>()).collect(),
            _ => unreachable!(),
        }
    }
}

impl AsTypeTrait for bool {
    fn as_type(val: FasValue) -> Self {
        match val {
            FasValue::Bool(b) => b,
            _ => unreachable!(),
        }
    }
}

impl AsTypeTrait for f64 {
    fn as_type(val: FasValue) -> Self {
        match val {
            FasValue::Float(f) => f,
            FasValue::Int(i) => i as f64,
            _ => unreachable!(),
        }
    }
}

impl AsTypeTrait for crossbeam::channel::Receiver<FasValue> {
    fn as_type(val: FasValue) -> Self {
        match val {
            FasValue::Future(f) => f,
            _ => unreachable!(),
        }
    }
}

impl AsTypeTrait for i64 {
    fn as_type(val: FasValue) -> Self {
        match val {
            FasValue::Float(f) => f.round() as i64,
            FasValue::Int(i) => i,
            _ => unreachable!(),
        }
    }
}

impl AsTypeTrait for HashMap<i64, FasValue> {
    fn as_type(val: FasValue) -> Self {
        match val {
            FasValue::IMap(map) => map,
            _ => unreachable!(),
        }
    }
}

impl AsTypeTrait for HashMap<String, FasValue> {
    fn as_type(val: FasValue) -> Self {
        match val {
            FasValue::SMap(map) => map,
            _ => unreachable!(),
        }
    }
}

impl AsTypeTrait for NaiveDateTime {
    fn as_type(val: FasValue) -> Self {
        match val {
            FasValue::DateTime(dt) => dt,
            _ => unreachable!(),
        }
    }
}

impl AsTypeTrait for TaskValue {
    fn as_type(val: FasValue) -> Self {
        match val {
            FasValue::Task(t) => t,
            _ => unreachable!(),
        }
    }
}

impl AsTypeTrait for TaskResult {
    fn as_type(val: FasValue) -> Self {
        match val {
            FasValue::TaskResult(tr) => tr,
            _ => unreachable!(),
        }
    }
}

impl AsTypeTrait for Duration {
    fn as_type(val: FasValue) -> Self {
        match val {
            FasValue::TimeSpan(ts) => ts,
            _ => unreachable!(),
        }
    }
}

pub trait GetAstTypeTrait {
    fn get_ast_type() -> AstType;
}

// pub trait MyFrom<T>: Sized {
//     fn from(value: T) -> Self;
// }

macro_rules! define_cast {
    ($type:ty, $type2:tt) => {
        impl From<FasValue> for $type {
            fn from(v: FasValue) -> Self {
                v.as_type::<Self>()
            }
        }

        impl From<$type> for FasValue {
            fn from(v: $type) -> Self {
                FasValue::$type2(v)
            }
        }

        impl GetAstTypeTrait for $type {
            fn get_ast_type() -> AstType {
                AstType::$type2
            }
        }
    };
}

//define_cast2!((), as_void, None);
define_cast!(bool, Bool);
define_cast!(f64, Float);
define_cast!(i64, Int);
define_cast!(String, String);
define_cast!(NaiveDateTime, DateTime);
define_cast!(Duration, TimeSpan);

// void

impl From<FasValue> for () {
    fn from(_: FasValue) -> Self {
        ()
    }
}

impl From<()> for FasValue {
    fn from(_: ()) -> Self {
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
    fn from(s: &str) -> Self {
        FasValue::String(s.into())
    }
}

impl GetAstTypeTrait for &str {
    fn get_ast_type() -> AstType {
        AstType::String
    }
}

// Array

impl From<FasValue> for Vec<String> {
    fn from(v: FasValue) -> Self {
        v.as_type::<Self>()
    }
}

impl From<Vec<String>> for FasValue {
    fn from(v: Vec<String>) -> Self {
        FasValue::Array(v.into_iter().map(|x| FasValue::String(x)).collect())
    }
}

impl GetAstTypeTrait for Vec<String> {
    fn get_ast_type() -> AstType {
        AstType::Array(Box::new(AstType::String))
    }
}

// FasValue

// impl From<FasValue> for FasValue {
//     fn from(v: FasValue) -> Self {
//         v
//     }
// }

impl GetAstTypeTrait for FasValue {
    fn get_ast_type() -> AstType {
        AstType::Any
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
