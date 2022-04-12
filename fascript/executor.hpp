#ifndef __EXECUTOR_HPP__
#define __EXECUTOR_HPP__



#include <magic_enum.hpp>
#include "opcode.hpp"



namespace fas {
class Executor {
	std::shared_ptr<FAScript> m_s;
	std::vector<uint8_t> &m_code;
	int32_t m_code_pos = 0;
	std::vector<Value> m_stack {};

public:
	Executor (std::shared_ptr<FAScript> _s, std::vector<uint8_t> &_code): m_s (_s), m_code (_code) {}

	Value Exec (int32_t _pos) {
		m_code_pos = _pos;
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
				case OpCode::LOAD_MEMBER_VAR:		/*TODO*/break;
				case OpCode::LOAD_ARG_VAR:			/*TODO*/break;
				case OpCode::LOAD_LOCAL_VAR:		/*TODO*/break;
				case OpCode::LOAD_VARIABLE:			/*TODO*/break;
				case OpCode::STORE_GLOBA_VAR:		m_s->SetGlobalValue (GetInt<int32_t> (), *m_stack.rbegin ()); m_stack.pop_back (); break;
				case OpCode::STORE_MEMBER_VAR:		/*TODO*/break;
				case OpCode::STORE_ARG_VAR:			/*TODO*/break;
				case OpCode::STORE_LOCAL_VAR:		/*TODO*/break;
				case OpCode::IGNORE:				m_stack.erase (m_stack.end () - 1); break;
				case OpCode::LOAD_MEMBER_ID:		/*TODO*/break;
				case OpCode::LOAD_MEMBER_NAME:		/*TODO*/break;
				case OpCode::LOAD_MEMBER_IMMNUM:	/*TODO*/break;
				case OpCode::LOAD_MEMBER_NUM:		/*TODO*/break;
				case OpCode::STORE_MEMBER_ID:		/*TODO*/break;
				case OpCode::STORE_MEMBER_NAME:		/*TODO*/break;
				case OpCode::STORE_MEMBER_IMMNUM:	/*TODO*/break;
				case OpCode::STORE_MEMBER_NUM:		/*TODO*/break;
				case OpCode::NOT:					*m_stack.rbegin () = Value { m_s, !m_stack.rbegin ()->Get<bool> () }; break;
				case OpCode::AND:
					_tmp_sz = m_stack.size () - 2;
					m_stack [_tmp_sz] = Value { m_s, m_stack [_tmp_sz].Get<bool> () && m_stack [_tmp_sz + 1].Get<bool> () };
					m_stack.erase (m_stack.end () - 1);
					break;
				case OpCode::OR:
					_tmp_sz = m_stack.size () - 2;
					m_stack [_tmp_sz] = Value { m_s, m_stack [_tmp_sz].Get<bool> () || m_stack [_tmp_sz + 1].Get<bool> () };
					m_stack.erase (m_stack.end () - 1);
					break;
				case OpCode::ADD:					DoNumOp2 ('+'); break;
				case OpCode::SUB:					DoNumOp2 ('-'); break;
				case OpCode::MUL:					DoNumOp2 ('*'); break;
				case OpCode::DIV:					DoNumOp2 ('/'); break;
				case OpCode::MOD:					DoNumOp2 ('%'); break;
				case OpCode::LOAD_POS:				m_stack.push_back (Value { m_s, GetInt<int32_t> () }); break;
				case OpCode::GOTO:
					if (m_stack.rbegin ()->IsType<int32_t> ()) {
						m_code_pos = m_stack.rbegin ()->Get<int32_t> ();
					} else if (m_stack.rbegin ()->IsType<std::shared_ptr<Function>> ()) {
						m_code_pos = m_stack.rbegin ()->Get<std::shared_ptr<Function>> ()->m_start_pos;
					} else {
						throw Exception::NotImplement ();
					}
					m_stack.pop_back ();
					break;
				case OpCode::RET:
					_tmp_sz = m_stack.size () - 2 - GetInt<uint8_t> ();
					m_code_pos = m_stack [_tmp_sz].Get<int32_t> ();
					m_stack.erase (m_stack.begin () + _tmp_sz, m_stack.end () - 1);
					break;
				default:							throw Exception::NotImplement ();
			}
		}
	}

	std::string Print (int32_t _pos) {
		std::stringstream _ss;

		m_code_pos = _pos;
		while ((size_t) m_code_pos < m_code.size ()) {
			_ss << std::format ("{:08X}        ", m_code_pos);
			auto _opcode = GetOpcode ();
			_ss << std::format ("{:20}", magic_enum::enum_name (_opcode));
			switch (_opcode) {
				case OpCode::LOAD_NULL:				break;
				case OpCode::LOAD_BOOL:				_ss << !!GetInt<uint8_t> () ? "true" : "false"; break;
				case OpCode::LOAD_INT64:			_ss << std::format ("{}", GetInt<int64_t> ()); break;
				case OpCode::LOAD_FLOAT64:			_ss << std::format ("{}", GetFloat64 ()); break;
				case OpCode::LOAD_STRING:			_ss << std::format ("\"{}\"", GetString ()); break;
				case OpCode::LOAD_FUNC:				_ss << m_s->GetFuncDespFromId (GetInt<int32_t> ()); break;
				case OpCode::LOAD_GLOBAL_VAR:		_ss << m_s->GetVarNameFromId (GetInt<int32_t> ()); break;
				case OpCode::LOAD_MEMBER_VAR:		_ss << "TODO"; break;
				case OpCode::LOAD_ARG_VAR:			_ss << "TODO"; break;
				case OpCode::LOAD_LOCAL_VAR:		_ss << "TODO"; break;
				case OpCode::LOAD_VARIABLE:			_ss << "TODO"; break;
				case OpCode::STORE_GLOBA_VAR:		_ss << m_s->GetVarNameFromId (GetInt<int32_t> ()); break;
				case OpCode::STORE_MEMBER_VAR:		_ss << "TODO"; break;
				case OpCode::STORE_ARG_VAR:			_ss << "TODO"; break;
				case OpCode::STORE_LOCAL_VAR:		_ss << "TODO"; break;
				case OpCode::IGNORE:				break;
				case OpCode::LOAD_MEMBER_ID:		_ss << "TODO"; break;
				case OpCode::LOAD_MEMBER_NAME:		_ss << "TODO"; break;
				case OpCode::LOAD_MEMBER_IMMNUM:	_ss << "TODO"; break;
				case OpCode::LOAD_MEMBER_NUM:		_ss << "TODO"; break;
				case OpCode::STORE_MEMBER_ID:		_ss << "TODO"; break;
				case OpCode::STORE_MEMBER_NAME:		_ss << "TODO"; break;
				case OpCode::STORE_MEMBER_IMMNUM:	_ss << "TODO"; break;
				case OpCode::STORE_MEMBER_NUM:		_ss << "TODO"; break;
				case OpCode::NOT:					break;
				case OpCode::AND:					break;
				case OpCode::OR:					break;
				case OpCode::ADD:					break;
				case OpCode::SUB:					break;
				case OpCode::MUL:					break;
				case OpCode::DIV:					break;
				case OpCode::MOD:					break;
				case OpCode::LOAD_POS:				_ss << std::format ("0x{:X}", GetInt<int32_t> ()); break;
				case OpCode::INVOKE:				_ss << std::format ("{} (need check arg count)", GetInt<uint8_t> ()); break;
				case OpCode::GOTO:					break;
				case OpCode::RET:					_ss << std::format ("{} (clear arg count)", GetInt<uint8_t> ()); break;
				default:							throw Exception::NotImplement ();
			}
			_ss << "\n";
		}
		return _ss.str ();
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

	void DoNumOp2 (char _op) {
		int64_t _tmp_i64 = 0, _tmp2_i64 = 0;
		double _tmp_f64 = 0, _tmp2_f64 = 0;
		size_t _tmp_sz = m_stack.size () - 2;
		bool _b1 = m_stack [_tmp_sz].IsType<int64_t> (), _b2 = m_stack [_tmp_sz + 1].IsType<int64_t> ();
		if (_b1) {
			_tmp_i64 = m_stack [_tmp_sz].Get<int64_t> ();
		} else {
			_tmp_f64 = m_stack [_tmp_sz].Get<double> ();
		}
		if (_b2) {
			_tmp2_i64 = m_stack [_tmp_sz].Get<int64_t> ();
		} else {
			_tmp2_f64 = m_stack [_tmp_sz].Get<double> ();
		}
		int8_t _n = (_b1 ? 1 : 0) + (_b2 ? 2 : 0);
		switch (_n) {
			case 3:		m_stack [_tmp_sz] = Value { m_s, DoNumOp2Calc<int64_t> (_op, _tmp_i64, _tmp2_i64)};
			case 1:		m_stack [_tmp_sz] = Value { m_s, DoNumOp2Calc<double> (_op, (double) _tmp_i64, _tmp2_f64)};
			case 2:		m_stack [_tmp_sz] = Value { m_s, DoNumOp2Calc<double> (_op, _tmp_f64, (double) _tmp2_i64)};
			case 0:		m_stack [_tmp_sz] = Value { m_s, DoNumOp2Calc<double> (_op, _tmp_f64, _tmp2_f64)};
		}
		m_stack.erase (m_stack.end () - 1);
	}

	template<Int64OrFloat64 T>
	static T DoNumOp2Calc (char _op, T _t1, T _t2) {
		switch (_op) {
			case '+':		return _t1 + _t2;
			case '-':		return _t1 - _t2;
			case '*':		return _t1 * _t2;
			case '/':		return _t1 / _t2;
			case '%':
				if constexpr (std::is_same<T, int64_t>::value)
					return _t1 % _t2;
			default:		break;
		}
		throw Exception::NotImplement ();
	}
};
}



#endif //__EXECUTOR_HPP__
