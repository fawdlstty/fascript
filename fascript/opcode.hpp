#ifndef __OPCODE_HPP__
#define __OPCODE_HPP__



namespace fas {
enum class OpCode {
	// 栈操作
	PUSH_NULL,		// 压入一个空值
	PUSH_BOOL,		// 压入一个 bool 类型值，后接1字节具体值
	PUSH_INT64,		// 压入一个 int64 类型值，后接8字节具体值
	PUSH_FLOAT64,	// 压入一个 double 类型值，后接8字节具体值
	PUSH_GLOBAL,	// 压入一个全局变量值，后接2字节ID
	PUSH_MEMBER,	// 压入一个象成员变量值，后接2字节ID
	PUSH_ARGUMENT,	// 压入一个参数值
	PUSH_VARIABLE,	// 压入一个局部变量值
	POP_GLOBAL,		// 弹出一个值至全局变量
	POP_MEMBER,		// 弹出一个值至对象成员变量
	POP_ARGUMENT,	// 弹出一个值至参数
	POP_VARIABLE,	// 弹出一个值至局部变量
	POP,			// 弹出一个值（忽略）

	// 运算
	NOT,			// 取反 （1->1）
	AND,			// 与运算（2->1）
	OR,				// 或运算（2->1）

	// 函数调用
	INVOKE,			// 压入当前执行位置（4字节）并调用函数（顺序：从左至右将参数压栈，然后压函数ID，最后INVOKE）
	RET,			// 函数返回，恢复现场

	OPCODE_END,		// 最后一个操作数，用于静态校验操作数长度不超255
};

static_assert ((int) OpCode::OPCODE_END <= 256, "操作数数量不能超256");
}



#endif //__OPCODE_HPP__
