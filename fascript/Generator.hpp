#ifndef __BIN_CODE_HPP__
#define __BIN_CODE_HPP__



#include "opcode.hpp"
#include "function.hpp"



namespace fas {
struct Generator {
	void LoadNull () { m_data.push_back ((uint8_t) OpCode::LOAD_NULL); }
	void LoadBool (bool _val) { m_data.push_back ((uint8_t) OpCode::LOAD_BOOL); m_data.push_back (_val ? 1 : 0); }
	void LoadInt64 (int64_t _val) { m_data.push_back ((uint8_t) OpCode::LOAD_INT64); _put_int (_val); }
	void LoadFloat64 (double _val) { m_data.push_back ((uint8_t) OpCode::LOAD_FLOAT64); _put_float64 (_val); }
	void LoadString (std::string _val) {
		m_data.push_back ((uint8_t) OpCode::LOAD_STRING);
		_put_int ((int32_t) _val.size ());
		for (size_t i = 0; i < _val.size (); ++i)
			m_data.push_back ((uint8_t) (_val [i]));
	}
	void LoadFunction (int32_t _func_id) { m_data.push_back ((uint8_t) OpCode::LOAD_FUNC); _put_int (_func_id); }
	void LoadVariable (AstIdType _type, int32_t _var_id) {
		if (_type == AstIdType::Global) {
			m_data.push_back ((uint8_t) OpCode::LOAD_GLOBAL_VAR);
		} else if (_type == AstIdType::Argument) {
			m_data.push_back ((uint8_t) OpCode::LOAD_ARG_VAR);
		} else if (_type == AstIdType::Local) {
			m_data.push_back ((uint8_t) OpCode::LOAD_LOCAL_VAR);
		} else {
			throw Exception::NotImplement ();
		}
		_put_int (_var_id);
	}
	void LoadPos (int32_t _pos) { m_data.push_back ((uint8_t) OpCode::LOAD_POS); _put_int (_pos); }
	void StoreVariable (AstIdType _type, int32_t _var_id) {
		if (_type == AstIdType::Global) {
			m_data.push_back ((uint8_t) OpCode::STORE_GLOBA_VAR);
		} else if (_type == AstIdType::Argument) {
			m_data.push_back ((uint8_t) OpCode::STORE_ARG_VAR);
		} else if (_type == AstIdType::Local) {
			m_data.push_back ((uint8_t) OpCode::STORE_LOCAL_VAR);
		} else {
			throw Exception::NotImplement ();
		}
		_put_int (_var_id);
	}
	void GoTo () { m_data.push_back ((uint8_t) OpCode::GOTO); }
	void Ignore () { m_data.push_back ((uint8_t) OpCode::IGNORE); }
	void Return (uint8_t _arg_num) { m_data.push_back ((uint8_t) OpCode::RET); m_data.push_back (_arg_num); }
	void DoOp2 (std::string _op) {
		if (_op.size () == 1) {
			switch (_op [0]) {
			case '+': m_data.push_back ((uint8_t) OpCode::ADD); return;
			case '-': m_data.push_back ((uint8_t) OpCode::SUB); return;
			case '*': m_data.push_back ((uint8_t) OpCode::MUL); return;
			case '/': m_data.push_back ((uint8_t) OpCode::DIV); return;
			case '%': m_data.push_back ((uint8_t) OpCode::MOD); return;
			}
		}
		throw Exception::NotImplement ();
	}

	int32_t GetCodePos () { return (int32_t) m_data.size (); }
	std::vector<uint8_t> &GetCodes () { return m_data; }

private:
	template<OpIntType T>
	void _put_int (T _val) {
		if constexpr (std::is_same<T, int8_t>::value) { m_data.push_back ((uint8_t) _val); }
		else if constexpr (std::is_same<T, uint8_t>::value) { m_data.push_back (_val); }
		else if constexpr (std::is_same<T, int16_t>::value) { IntDataType2 _d { .int16 = _val, }; m_data.push_back (_d.uint8 [0]); m_data.push_back (_d.uint8 [1]); }
		else if constexpr (std::is_same<T, uint16_t>::value) { IntDataType2 _d { .uint16 = _val, }; m_data.push_back (_d.uint8 [0]); m_data.push_back (_d.uint8 [1]); }
		else if constexpr (std::is_same<T, int32_t>::value) { IntDataType4 _d { .int32 = _val, }; for (size_t i = 0; i < 4; ++i) m_data.push_back (_d.uint8 [i]); }
		else if constexpr (std::is_same<T, uint32_t>::value) { IntDataType4 _d { .uint32 = _val, }; for (size_t i = 0; i < 4; ++i) m_data.push_back (_d.uint8 [i]); }
		else if constexpr (std::is_same<T, int64_t>::value) { IntDataType8 _d { .int64 = _val, }; for (size_t i = 0; i < 8; ++i) m_data.push_back (_d.uint8 [i]); }
		else if constexpr (std::is_same<T, uint64_t>::value) { IntDataType8 _d { .uint64 = _val, }; for (size_t i = 0; i < 8; ++i) m_data.push_back (_d.uint8 [i]); }
		else { static_assert (false, "未处理的整数类型"); }
	}

	void _put_float64 (double _val) { IntDataType8 _d { .float64 = _val, }; for (size_t i = 0; i < 8; ++i) m_data.push_back (_d.uint8 [i]); }

	std::vector<uint8_t> m_data;
};
}



#endif //__BIN_CODE_HPP__
