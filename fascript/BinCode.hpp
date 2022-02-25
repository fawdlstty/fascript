#ifndef __BIN_CODE_HPP__
#define __BIN_CODE_HPP__



#include "opcode.hpp"



namespace fas {
struct BinCode {
	void PushNull () { m_data.push_back ((uint8_t) OpCode::PUSH_NULL); }
	void PushBool (bool _val) { m_data.push_back ((uint8_t) OpCode::PUSH_BOOL); m_data.push_back (_val ? 1 : 0); }
	void PushInt64 (int64_t _val) { m_data.push_back ((uint8_t) OpCode::PUSH_INT64); _store_int64 (_val); }
	void PushFloat64 (double _val) { m_data.push_back ((uint8_t) OpCode::PUSH_FLOAT64); _store_float64 (_val); }
	void PushGlobal (std::shared_ptr<FAScript> _s, std::string _name) { m_data.push_back ((uint8_t) OpCode::PUSH_GLOBAL); _store_int16 (_s->GetGlobalNameId (_name)); }

private:
	union DataType2 { uint8_t uint8 [2]; uint16_t uint16; };
	void _store_int16 (uint16_t _val) { DataType2 _d { .uint16 = _val, }; m_data.push_back (_d.uint8 [0]); m_data.push_back (_d.uint8 [1]); }

	union DataType8 { uint8_t uint8 [8]; uint64_t uint64; double float64; };
	void _store_int64 (int64_t _val) { DataType8 _d { .uint64 = _val, }; for (size_t i = 0; i < 8; ++i) m_data.push_back (_d.uint8 [i]); }
	void _store_float64 (double _val) { DataType8 _d { .float64 = _val, }; for (size_t i = 0; i < 8; ++i) m_data.push_back (_d.uint8 [i]); }

	std::vector<uint8_t> m_data;

};
}



#endif //__BIN_CODE_HPP__
