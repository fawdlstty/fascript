use crate::ast::exprs::AstExpr;
use crate::ast::ParseExt;
use crate::ast::PestApiExt;
use crate::ast::Rule;

pub struct AbortProc {
    pub retry_count: Option<AstExpr>,
    pub retry_interval: Option<AstExpr>,
    pub on_abort: Option<AstExpr>,
}

impl AbortProc {
    pub fn new() -> AbortProc {
        AbortProc {
            retry_count: None,
            retry_interval: None,
            on_abort: None,
        }
    }
}

#[derive(Clone, Debug)]
pub enum AstAnnoPart {
    Atomic,
    OnAbort(AstExpr),
    OnAbortRetryCount(AstExpr),
    OnAbortRetryInterval(AstExpr),
    OnCancel(AstExpr),
    OnPause(AstExpr),
    OnResume(AstExpr),
    OnRollback(AstExpr),
    RemainingTime(AstExpr),
}

unsafe impl Send for AstAnnoPart {}

impl ParseExt for AstAnnoPart {
    fn parse(root: pest::iterators::Pair<'_, Rule>) -> Self {
        let mut anno_type = "".to_string();
        let mut anno_expr = AstExpr::None;
        for root_item in root.into_inner() {
            match root_item.as_rule() {
                Rule::Id => anno_type = root_item.get_id(),
                Rule::MiddleExpr => {
                    let expr = AstExpr::parse_middle_expr(root_item);
                    if expr.0.len() + expr.2.len() > 0 {
                        panic!()
                    }
                    anno_expr = expr.1;
                }
                _ => unreachable!(),
            }
        }
        match &anno_type[..] {
            "atomic" => AstAnnoPart::Atomic,
            "on_abort" => AstAnnoPart::OnAbort(anno_expr),
            "on_abort_retry_count" => AstAnnoPart::OnAbortRetryCount(anno_expr),
            "on_abort_retry_interval" => AstAnnoPart::OnAbortRetryInterval(anno_expr),
            "on_cancel" => AstAnnoPart::OnCancel(anno_expr),
            "on_pause" => AstAnnoPart::OnPause(anno_expr),
            "on_resume" => AstAnnoPart::OnResume(anno_expr),
            "on_rollback" => AstAnnoPart::OnRollback(anno_expr),
            "remaining_time" => AstAnnoPart::RemainingTime(anno_expr),
            _ => unreachable!(),
        }
    }
}

#[derive(Clone, Debug)]
pub struct AstAnnoParts {
    pub annos: Vec<AstAnnoPart>,
}

unsafe impl Send for AstAnnoParts {}

impl AstAnnoParts {
    pub fn new() -> AstAnnoParts {
        AstAnnoParts { annos: vec![] }
    }

    pub fn push(&mut self, anno: AstAnnoPart) {
        self.annos.push(anno);
    }

    pub fn is_atomic(&self) -> bool {
        for anno in self.annos.iter() {
            if let AstAnnoPart::Atomic = anno {
                return true;
            }
        }
        false
    }

    pub fn get_abort_expr(&mut self) -> AbortProc {
        let mut proc = AbortProc::new();
        for anno in self.annos.iter_mut() {
            if let AstAnnoPart::OnAbort(expr) = anno {
                proc.on_abort = Some(expr.clone());
            } else if let AstAnnoPart::OnAbortRetryCount(expr) = anno {
                proc.retry_count = Some(expr.clone());
            } else if let AstAnnoPart::OnAbortRetryInterval(expr) = anno {
                proc.retry_interval = Some(expr.clone());
            }
        }
        proc
    }

    pub fn get_cancel_expr(&mut self) -> Option<AstExpr> {
        for anno in self.annos.iter() {
            if let AstAnnoPart::OnCancel(expr) = anno {
                return Some(expr.clone());
            }
        }
        None
    }

    pub fn get_pause_expr(&mut self) -> Option<AstExpr> {
        for anno in self.annos.iter() {
            if let AstAnnoPart::OnPause(expr) = anno {
                return Some(expr.clone());
            }
        }
        None
    }

    pub fn get_resume_expr(&mut self) -> Option<AstExpr> {
        for anno in self.annos.iter() {
            if let AstAnnoPart::OnResume(expr) = anno {
                return Some(expr.clone());
            }
        }
        None
    }

    pub fn get_rollback_expr(&mut self) -> Option<AstExpr> {
        for anno in self.annos.iter() {
            if let AstAnnoPart::OnRollback(expr) = anno {
                return Some(expr.clone());
            }
        }
        None
    }

    pub fn get_remaining_time_expr(&mut self) -> Option<AstExpr> {
        for anno in self.annos.iter() {
            if let AstAnnoPart::RemainingTime(expr) = anno {
                return Some(expr.clone());
            }
        }
        None
    }
}
