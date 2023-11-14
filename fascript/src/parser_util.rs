use crate::ast::{
    blocks::{class::AstClass, program::AstProgram},
    stmts::ProcessStmtExt,
    types::AstType,
};
use std::{
    cell::RefCell,
    collections::{HashMap, HashSet},
    rc::Rc,
};

pub struct AstClassFuncAndVars {
    program_file: String,
    funcs: HashSet<String>,
    vars: HashSet<String>,
}

pub struct ParserUtil {}

impl ParserUtil {
    pub fn process_programs(
        mut programs: HashMap<String, AstProgram>,
    ) -> HashMap<String, AstProgram> {
        let mut class_member_names: HashMap<String, AstClassFuncAndVars> = HashMap::new();
        for (program_file, program) in programs.iter() {
            for (class_name, class) in program.classes.iter() {
                class_member_names.insert(
                    class_name.clone(),
                    AstClassFuncAndVars {
                        program_file: program_file.clone(),
                        funcs: class.funcs.keys().map(|name| name.clone()).collect(),
                        vars: HashSet::new(),
                    },
                );
            }
        }
        for (class_name, class_member_name) in class_member_names {
            let program = programs.get_mut(&class_member_name.program_file).unwrap();
            let class = program.classes.get_mut(&class_name).unwrap();
        }
        // let file_names: Vec<String> = programs.keys().map(|name| name.clone()).collect();
        // for file_name in file_names {
        //     //let cur_program = programs.remove(&file_name).unwrap();
        //     let class_names: Vec<String> = programs
        //         .get_mut(&file_name)
        //         .unwrap()
        //         .classes
        //         .keys()
        //         .map(|name| name.clone())
        //         .collect();
        //     for class_name in class_names {
        //         // let cur_class = cur_program.classes.remove(&class_name).unwrap();

        //         // // process variables
        //         // // TODO

        //         // // process methods
        //         // let func_names = cur_class.funcs.keys().clone();
        //         // for func_name in func_names {
        //         //     let cur_func = cur_class.funcs.remove(func_name).unwrap();

        //         //     // process func ret type
        //         //     let mut ret_type = AstType::None;
        //         //     std::mem::swap(&mut ret_type, &mut cur_func.ret_type);
        //         //     ret_type.process_type(&cur_class, &cur_program, &programs);

        //         //     // process func arg types
        //         //     let mut arg_types = vec![];
        //         //     std::mem::swap(&mut arg_types, &mut cur_func.arg_types);
        //         //     cur_func.arg_types = arg_types
        //         //         .into_iter()
        //         //         .map(|x| x.process_type(&cur_class, &cur_program, &programs))
        //         //         .collect();

        //         //     // process func stmts
        //         //     let mut body_stmts = vec![];
        //         //     std::mem::swap(&mut body_stmts, &mut cur_func.body_stmts);
        //         //     cur_class.funcs.insert(func_name.clone(), cur_func.into());
        //         //     for stmt in body_stmts {
        //         //         stmt.process_stmt(&cur_func, &cur_class, &cur_program, &programs);
        //         //     }
        //         //     std::mem::swap(
        //         //         &mut body_stmts,
        //         //         &mut cur_class.funcs.get_mut(func_name).unwrap().body_stmts,
        //         //     );
        //         // }
        //         // cur_program
        //         //     .classes
        //         //     .insert(class_name.clone(), cur_class.into());
        //     }
        //     //programs.insert(file_name.clone(), cur_program.into());
        // }
        programs
    }
}
