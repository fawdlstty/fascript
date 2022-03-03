#ifndef __OPCODE_HPP__
#define __OPCODE_HPP__



namespace fas {
enum class OpCode {
	// 栈操作
	LOAD_NULL,			// 载入一个空值
	LOAD_BOOL,			// 载入一个 bool 类型值，后接1字节具体值
	LOAD_INT64,			// 载入一个 int64 类型值，后接8字节具体值
	LOAD_FLOAT64,		// 载入一个 double 类型值，后接8字节具体值
	LOAD_STRING,		// 载入一个 std::string 类型值，后接4字节长度及内容
	LOAD_FUNC,			// 载入一个函数类型值，后接4字节长度函数id
	LOAD_GLOBAL_VAR,	// 载入一个全局变量值，后接4字节ID
	LOAD_MEMBER_VAR,	// 载入一个象成员变量值，后接4字节ID
	LOAD_ARG_VAR,		// 载入一个参数值，后接4字节index
	LOAD_LOCAL_VAR,		// 载入一个局部变量值，后接4字节ID
	LOAD_VARIABLE,		// 载入一个局部变量值
	STORE_GLOBA_VAR,	// 存档一个值至全局变量
	STORE_MEMBER_VAR,	// 存档一个值至对象成员变量
	STORE_ARG_VAR,		// 存档一个值至参数
	STORE_LOCAL_VAR,	// 存档一个值至局部变量
	STORE,				// 存档一个值（忽略）

	// 访问成员
	LOAD_MEM_ID,		// 载入对象的某个已获取ID的成员，后接2字节ID	载入对象成员调用顺序示例：LOAD_GLOBAL、LOAD_MEM_ID 具体ID
	LOAD_MEM_NAME,		// 载入对象的某个成员（2->1）					载入对象成员调用顺序示例：LOAD_GLOBAL、LOAD_VARIABLE、LOAD_MEM_NAME
	LOAD_MEM_IMMNUM,	// 载入列表的某个元素，后接2字节具体值
	LOAD_MEM_NUM,		// 载入列表的某个元素（2->1）
	STORE_MEM_ID,		// 存档对象的某个已获取ID的成员，后接2字节ID	存档对象成员调用顺序示例：LOAD_GLOBAL、STORE_MEM_ID 具体ID
	STORE_MEM_NAME,		// 存档对象的某个成员（2->1）					存档对象成员调用顺序示例：LOAD_GLOBAL、LOAD_VARIABLE、STORE_MEM_NAME
	STORE_MEM_IMMNUM,	// 存档列表的某个元素，后接2字节具体值
	STORE_MEM_NUM,		// 存档列表的某个元素（2->1）

	// 运算
	NOT,			// 逻辑取反 （1->1）
	AND,			// 逻辑与运算（2->1）
	OR,				// 逻辑或运算（2->1）
	ADD,			// 算术加运算（2->1）
	SUB,			// 算术减运算（2->1）
	MUL,			// 算术乘运算（2->1）
	DIV,			// 算术除运算（2->1）
	MOD,			// 算术取余运算（2->1）

	// 函数调用
	INVOKE,			// 压入当前执行位置（4字节）并调用函数（顺序：从左至右将参数压栈，然后压函数ID，最后INVOKE）
	RET,			// 函数返回，恢复现场
	RET_VAL,		// 函数返回，恢复现场，并附带一个返回值

	OPCODE_END,		// 最后一个操作数，用于静态校验操作数长度不超255
};

static_assert ((int) OpCode::OPCODE_END <= 256, "操作数数量不能超256");
}



#endif //__OPCODE_HPP__
