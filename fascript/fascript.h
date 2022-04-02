#ifndef __FASCRIPT_H__
#define __FASCRIPT_H__



#include "value.hpp"
#include "function.hpp"
#include "Generator.hpp"



namespace fas {
class IAstExpr;

class FAScript: public std::enable_shared_from_this<FAScript> {
public:
	Value RunCode (std::string _code);
	int32_t GetNameId (AstIdType _type, std::string _name);
	std::string GetVarNameFromId (int32_t _var_id);
	int32_t NewGlobalFuncId (std::shared_ptr<Function> _func);
	std::shared_ptr<Function> GetFuncFromId (int32_t _func_id);
	std::string GetFuncDespFromId (int32_t _func_id);

	// 注册待编译函数
	void RegisterUncompiledFunc (std::shared_ptr<IAstExpr> _ast_func) { m_uncompiled_funcs.push_back (_ast_func); }

	// 标记当前编译的函数
	void MarkEntryBlock (std::shared_ptr<IAstExpr> _func) { m_current_blocks.push_back (_func); }
	void MarkLeaveBlock () { m_current_blocks.erase (m_current_blocks.begin () + m_current_blocks.size () - 1); }
	AstIdType CheckIdType (std::string _id);

	void SetGlobalValue (int32_t _index, Value _val);
	Value GetGlobalValue (int32_t _index);

private:
	std::recursive_mutex m_mtx;
	Generator m_bc {};

	std::map<std::string, int32_t> m_name_to_id;
	int32_t m_next_id = 0;

	std::map<int32_t, Value> m_global_vars;

	std::map<int32_t, std::shared_ptr<Function>> m_id_to_func;
	int32_t m_next_func_id = 0;

	std::vector<std::shared_ptr<IAstExpr>> m_uncompiled_funcs;
	std::vector<std::shared_ptr<IAstExpr>> m_current_blocks;
};
}



#endif //__FASCRIPT_H__
