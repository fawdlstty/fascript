#ifndef __AST_VALUE_HPP__
#define __AST_VALUE_HPP__



#include "IAstExpr.hpp"
#include "../common.hpp"



namespace fas {
class AstValue: IAstExpr {
	AstValue (): m_data (std::nullopt) {}
	template<AllowedCppType T>
	AstValue (T _val): m_data (_val) {}

public:
	ValueData m_data;

	static std::shared_ptr<IAstExpr> FromNull () { return std::shared_ptr<IAstExpr> ((IAstExpr *) new AstValue {}); }
	template<AllowedCppType T>
	static std::shared_ptr<IAstExpr> FromValue (T _val) { return std::shared_ptr<IAstExpr> ((IAstExpr *) new AstValue { _val }); }

	static std::shared_ptr<IAstExpr> FromCtx (FAScriptParser::LiteralContext *_ctx) {
		std::string _data = _ctx->getText ();
		if (_ctx->BoolLiteral ()) {
			return FromValue<bool> (_data == "true");
		} else if (_ctx->NumLiteral ()) {
			if (_data.find ('.') != std::string::npos) {
				return FromValue<double> (std::stod (_data));
			} else {
				return FromValue<int64_t> (std::stoll (_data));
			}
		} else if (_ctx->StringLiteral ()) {
			auto _odata = TransformMean (_data.substr (1, _data.size () - 2));
			if (!_odata.has_value ())
				throw Exception::NotImplement ();
			return FromValue<std::string> (_odata.value ());
		} else {
			throw Exception::NotImplement ();
		}
	}

	size_t GetBinaryCodeSize (FAScript &_s, OpType _type, size_t _start) override {
		if (_type == OpType::Load) {
			switch (m_data.index ()) {
			case 0: return 1;
			case 1: return 2;
			case 2: return 9;
			case 3: return 9;
			case 4: { size_t _size = std::get<std::string> (m_data).size (); return _size + (_size >= 65536 ? 4 : 2); }
			case 5: return 3;
			default: throw Exception::NotImplement ();
			}
		} else {
			throw Exception::NotImplement ();
		}
	}

	void GenerateBinaryCode (BinCode &_bc, FAScript &_s, OpType _type) override {
		// std::nullopt_t, bool, int64_t, double, std::string, std::shared_ptr<Function>, std::vector<Value>, std::map<MapKey, Value>
		if (_type == OpType::Load) {
			switch (m_data.index ()) {
			case 0: _bc.LoadNull (); break;
			case 1: _bc.LoadBool (std::get<bool> (m_data)); break;
			case 2: _bc.LoadInt64 (std::get<int64_t> (m_data)); break;
			case 3: _bc.LoadFloat64 (std::get<double> (m_data)); break;
			case 4: _bc.LoadString (std::get<std::string> (m_data)); break;
			case 5: _bc.LoadFunction (std::get<std::shared_ptr<Function>> (m_data)->Id); break;
			default: throw Exception::NotImplement ();
			}
		} else {
			throw Exception::NotImplement ();
		}
	}

private:
	static std::optional<char> _char_to_hex (char _ch) {
		if (_ch >= '0' && _ch <= '9') {
			return _ch - '0';
		} else if (_ch >= 'A' && _ch <= 'F') {
			return _ch - 'A' + 10;
		} else if (_ch >= 'a' && _ch <= 'f') {
			return _ch - 'a' + 10;
		}
		return std::nullopt;
	}

	static std::optional<std::string> TransformMean (std::string _s) {
		std::string _tmp = _s;
		std::optional<char> _c1, _c2;
		for (size_t i = 0; i < _s.size (); ++i) {
			if (_s [i] == '\\') {
				switch (_s [i + 1]) {
					case 'r':
						_s [i] = '\r';
						_s.erase (i + 1);
						break;
					case 'n':
						_s [i] = '\n';
						_s.erase (i + 1);
						break;
					case 't':
						_s [i] = '\t';
						_s.erase (i + 1);
						break;
					case '\'':
						_s [i] = '\'';
						_s.erase (i + 1);
						break;
					case '\"':
						_s [i] = '\"';
						_s.erase (i + 1);
						break;
					case '\\':
						_s [i] = '\\';
						_s.erase (i + 1);
						break;
					case 'x':
						_c1 = _char_to_hex (_s [i + 2]), _c2 = _char_to_hex (_s [i + 3]);
						if ((!_c1.has_value ()) || (!_c2.has_value ()))
							return std::nullopt;
						_s [i] = (_c1.value () << 4) + _c2.value ();
						_s.erase (i + 1, 3);
						break;
					case 'u':
						_c1 = _char_to_hex (_s [i + 2]), _c2 = _char_to_hex (_s [i + 3]);
						if ((!_c1.has_value ()) || (!_c2.has_value ()))
							return std::nullopt;
						_s [i] = (_c1.value () << 4) + _c2.value ();
						//
						_c1 = _char_to_hex (_s [i + 4]), _c2 = _char_to_hex (_s [i + 5]);
						if ((!_c1.has_value ()) || (!_c2.has_value ())) {
							return std::nullopt;
						}
						_s [i + 1] = (_c1.value () << 4) + _c2.value ();
						_s.erase (i + 2, 4);
						break;
					default:
						break;
				}
			}
		}
		return _s;
	}
};
}



#endif //__AST_VALUE_HPP__
