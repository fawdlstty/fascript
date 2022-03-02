#ifndef __FASCRIPT_H__
#define __FASCRIPT_H__



#include "value.hpp"
#include "function.hpp"



namespace fas {
class IAstExpr;

class FAScript: std::enable_shared_from_this<FAScript> {
public:
	Value RunCode (std::string _code);
	uint16_t GetNameId (AstIdType _type, std::string _name);
	uint16_t NewGlobalFuncId (std::shared_ptr<Function> _func);

	// 注册待编译函数
	void RegisterUncompiledFunc (std::shared_ptr<IAstExpr> _ast_func) { m_uncompiled_funcs.push_back (_ast_func); }

	// 标记当前编译的函数
	void MarkEntryBlock (std::shared_ptr<IAstExpr> _func) { m_current_blocks.push_back (_func); }
	void MarkLeaveBlock () { m_current_blocks.erase (m_current_blocks.begin () + m_current_blocks.size () - 1); }
	AstIdType CheckIdType (std::string _id);

private:
	std::recursive_mutex m_mtx;
	std::map<std::string, uint16_t> m_name_to_id;
	std::map<uint16_t, Value> m_id_to_var;
	uint16_t m_next_id = 0;

	std::vector<std::shared_ptr<IAstExpr>> m_uncompiled_funcs;
	std::map<uint16_t, std::shared_ptr<Function>> m_id_to_func;
	uint16_t m_next_func_id = 0;

	std::vector<std::shared_ptr<IAstExpr>> m_current_blocks;
};
}



#endif //__FASCRIPT_H__
