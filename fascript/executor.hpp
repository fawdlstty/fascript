#ifndef __EXECUTOR_HPP__
#define __EXECUTOR_HPP__



#include "opcode.hpp"



namespace fas {
class Executor {
	std::shared_ptr<FAScript> m_s;
	std::vector<uint8_t> &m_code;
	int32_t m_code_pos;
	std::vector<Value> m_stack {};

public:
	Executor (std::shared_ptr<FAScript> _s, std::vector<uint8_t> &_code, int32_t _code_start):
		m_s (_s), m_code (_code), m_code_pos (_code_start) {}

	Value Exec () {
		//int32_t _tmp_i32;
		size_t _tmp_sz;
		while (true) {
			switch (GetOpcode ()) {
			case OpCode::LOAD_NULL:				m_stack.push_back (Value { m_s }); break;
			case OpCode::LOAD_BOOL:				m_stack.push_back (Value { m_s, !!GetInt<uint8_t> () }); break;
			case OpCode::LOAD_INT64:			m_stack.push_back (Value { m_s, GetInt<int64_t> () }); break;
			case OpCode::LOAD_FLOAT64:			m_stack.push_back (Value { m_s, GetFloat64 () }); break;
			case OpCode::LOAD_STRING:			m_stack.push_back (Value { m_s, GetString () }); break;
			case OpCode::LOAD_FUNC:				m_stack.push_back (Value { m_s, m_s->GetFuncFromId (GetInt<int32_t> ()) }); break;
			case OpCode::LOAD_GLOBAL_VAR:		m_stack.push_back (m_s->GetGlobalValue (GetInt<int32_t> ())); break;
			case OpCode::LOAD_MEMBER_VAR:		break;
			case OpCode::LOAD_ARG_VAR:			break;
			case OpCode::LOAD_LOCAL_VAR:		break;
			case OpCode::LOAD_VARIABLE:			break;
			case OpCode::STORE_GLOBA_VAR:		m_s->SetGlobalValue (GetInt<int32_t> (), *m_stack.rbegin ()); m_stack.pop_back (); break;
			case OpCode::STORE_MEMBER_VAR:		break;
			case OpCode::STORE_ARG_VAR:			break;
			case OpCode::STORE_LOCAL_VAR:		break;
			case OpCode::IGNORE:				m_stack.erase (m_stack.end () - 1); break;
			case OpCode::LOAD_MEMBER_ID:		break;
			case OpCode::LOAD_MEMBER_NAME:		break;
			case OpCode::LOAD_MEMBER_IMMNUM:	break;
			case OpCode::LOAD_MEMBER_NUM:		break;
			case OpCode::STORE_MEMBER_ID:		break;
			case OpCode::STORE_MEMBER_NAME:		break;
			case OpCode::STORE_MEMBER_IMMNUM:	break;
			case OpCode::STORE_MEMBER_NUM:		break;
			case OpCode::NOT:					break;
			case OpCode::AND:					break;
			case OpCode::OR:					break;
			case OpCode::ADD:					break;
			case OpCode::SUB:					break;
			case OpCode::MUL:					break;
			case OpCode::DIV:					break;
			case OpCode::MOD:					break;
			case OpCode::LOAD_POS:				m_stack.push_back (Value { m_s, m_s->GetFuncFromId (GetInt<int32_t> ()) }); break;
			case OpCode::GOTO:					m_code_pos = GetInt<int32_t> (); break;
			case OpCode::RET:
				_tmp_sz = m_stack.size () - 2 - GetInt<uint8_t> ();
				m_code_pos = m_stack [_tmp_sz].Get<int32_t> ();
				m_stack.erase (m_stack.begin () + _tmp_sz, m_stack.end () - 1);
				break;
			default:
				throw Exception::NotImplement ();
			}
		}
	}

private:
	OpCode GetOpcode () { return (OpCode) m_code [m_code_pos++]; }

	template<OpIntType T>
	T GetInt () {
		if constexpr (std::is_same<T, int8_t>::value || std::is_same<T, uint8_t>::value) {
			return (T) m_code [m_code_pos++];
		} else if constexpr (std::is_same<T, int16_t>::value || std::is_same<T, uint16_t>::value) {
			IntDataType2 _d { .uint8 = { m_code [m_code_pos], m_code [m_code_pos + 1] } };
			m_code_pos += 2;
			if constexpr (std::is_same<T, int16_t>::value) { return _d.int16; } else { return _d.uint16; }
		} else if constexpr (std::is_same<T, int32_t>::value || std::is_same<T, uint32_t>::value) {
			IntDataType4 _d;
			memcpy (_d.uint8, &m_code [m_code_pos], sizeof (T));
			m_code_pos += sizeof (T);
			if constexpr (std::is_same<T, int32_t>::value) { return _d.int32; } else { return _d.uint32; }
		} else if constexpr (std::is_same<T, int64_t>::value || std::is_same<T, uint64_t>::value) {
			IntDataType8 _d;
			memcpy (_d.uint8, &m_code [m_code_pos], sizeof (T));
			m_code_pos += sizeof (T);
			if constexpr (std::is_same<T, int64_t>::value) { return _d.int64; } else { return _d.uint64; }
		} else {
			throw Exception::NotImplement ();
		}
	}

	double GetFloat64 () {
		IntDataType8 _d;
		memcpy (_d.uint8, &m_code [m_code_pos], sizeof (double));
		m_code_pos += sizeof (double);
		return _d.float64;
	}

	std::string GetString () {
		int32_t _size = GetInt<int32_t> ();
		int32_t _start = m_code_pos;
		m_code_pos += _size;
		return std::string ((char *) &m_code [_start], (char *) &m_code [m_code_pos]);
	}
};
}



#endif //__EXECUTOR_HPP__
