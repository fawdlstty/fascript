grammar FAScript;



//
// keyword
//

Break:						'break';
Continue:					'continue';
Do:							'do';
Else:						'else';
For:						'for';
If:							'if';
Return:						'return';
Switch:						'switch';
When:						'when';
While:						'while';
Fn:							'fn';



//
// element
//

// ��ֵ����
Assign:						'=';
AddAssign:					AddOp Assign;
SubAssign:					SubOp Assign;
StarAssign:					StarOp Assign;
DivAssign:					DivOp Assign;
ModAssign:					ModOp Assign;
OrAssign:					OrOp Assign;
AndAssign:					AndOp Assign;
XorAssign:					XorOp Assign;
StarStarAssign:				StarStarOp Assign;
AndAndAssign:				AndAndOp Assign;
OrOrAssign:					OrOrOp Assign;
shiftLAssign:				shiftLOp Assign; // ������
shiftRAssign:				shiftROp Assign;
allAssign:					Assign | AddAssign | SubAssign | StarAssign | StarStarAssign | DivAssign | ModAssign | AndAssign | OrAssign | XorAssign | AndAndAssign | OrOrAssign | shiftLAssign | shiftRAssign;

// һԪ����
ReverseOp:					'~';
AddAddOp:					'++';
SubSubOp:					'--';
Exclam:						'!';

// ��Ԫ����
PointPoint:					'..';
PointOp:					'.';
AddOp:						'+';
SubOp:						'-';
StarOp:						'*';
DivOp:						'/';
ModOp:						'%';
OrOp:						'|';
AndOp:						'&';
XorOp:						'^';
StarStarOp:					StarOp StarOp;
AndAndOp:					AndOp AndOp;
OrOrOp:						OrOp OrOp;
shiftLOp:					QuotJianL QuotJianL;
shiftROp:					QuotJianR QuotJianR;

// ��Ԫ������
Comma:						',';
ColonColon:					'::';
Colon:						':';
Semi:						';';
Underline:					'_';

// ����
QuotFangL:					'[';
QuotFangR:					']';
QuotJianL:					'<';
QuotJianR:					'>';
QuotHuaL:					'{';
QuotHuaR:					'}';
QuotYuanL:					'(';
QuotYuanR:					')';

// �Ƚ�
ltOp:						QuotJianL;
ltEqualOp:					QuotJianL Assign;
gtOp:						QuotJianR;
gtEqualOp:					QuotJianR Assign;
equalOp:					Assign Assign;
notEqualOp:					Exclam Assign;
exprFuncDef:				Assign QuotJianR;

selfOp2:					AddOp | SubOp | StarOp | DivOp | StarStarOp | ModOp | AndOp | OrOp | XorOp | AndAndOp | OrOrOp | shiftLOp | shiftROp;
compareOp2:					ltOp | ltEqualOp | gtOp | gtEqualOp | equalOp | notEqualOp;
allOp2:						selfOp2 | compareOp2;



//
// Literal
//
fragment SimpleEscape:		'\\\'' | '\\"' | '\\\\' | '\\n' | '\\r' | ('\\' ('\r' '\n'? | '\n')) | '\\t';
fragment HexEscape:			'\\x' HEX HEX;
fragment UniEscape:			'\\u' HEX HEX HEX HEX;
//
BoolLiteral:				'true' | 'false';
NumLiteral:					SubOp? ((PointOp NUMs) | (NUMs (PointOp (NUMs)?)?));
String1Literal:				'"' (SimpleEscape | HexEscape | UniEscape | ~["\\\r\n])* '"';
String2Literal:				'\'' (SimpleEscape | HexEscape | UniEscape | ~['\\\r\n])* '\'';
StringLiteral:				String1Literal | String2Literal;
literal:					BoolLiteral | NumLiteral | StringLiteral;

fragment NUM:				[0-9];
fragment NUMs:				NUM ('_' | NUM)*;
fragment HEX:				NUM | [a-fA-F];
fragment ID_BEGIN:			[a-zA-Z_] | ('\\u' HEX HEX HEX HEX);
fragment ID_AFTER:			NUM | [a-zA-Z_] | ('\\u' HEX HEX HEX HEX);
Id:							ID_BEGIN ID_AFTER*;



//
// if
//
quotStmtPart:				QuotHuaL stmt* QuotHuaR;
ifStmt:						If expr quotStmtPart (Else If expr quotStmtPart)* (Else quotStmtPart)?;



//
// loop
//
whileStmt:					While expr QuotHuaL stmt* QuotHuaR;
whileStmt2:					Do QuotHuaL stmt* QuotHuaR While expr;
forStmt:					For stmt expr Semi (expr (Comma expr)*)? QuotHuaL stmt* QuotHuaR;
forStmt2:					For Id Colon expr QuotHuaL stmt* QuotHuaR;



//
// switch
//
switchStmtPart:				expr (When expr)? exprFuncDef stmt;
switchStmt:					Switch expr QuotHuaL switchStmtPart* QuotHuaR;



//
// expr
//

exprOpt:					expr?;
quotExpr:					QuotYuanL expr QuotYuanR;
fnExpr:						Fn QuotYuanL Id* QuotYuanR QuotHuaL stmt* QuotHuaR;
classExprItem:				(Id Assign middleExpr) | fnStmt;
classExpr:					QuotHuaL (classExprItem ('\n' classExprItem)*)? QuotHuaR;
strongExprBase:				(ColonColon? Id) | literal | quotExpr | fnExpr;
strongExprPrefix:			SubOp | AddAddOp | SubSubOp | ReverseOp | Exclam;								// ǰ׺ - ++ -- ~ !
strongExprSuffix			: AddAddOp | SubSubOp															// ��׺ ++ --
							| (QuotYuanL (expr (Comma expr)*)? QuotYuanR)									//     Write ("")
							| (QuotFangL (exprOpt (PointPoint exprOpt)?) QuotFangR)							//     list [12]
							| (PointOp Id)																	//     wnd.Name
							;
strongExpr:					strongExprPrefix* strongExprBase strongExprSuffix*;
middleExpr:					strongExpr (allOp2 strongExpr)*;												//     a == 24    a + b - c
expr:						middleExpr (allAssign middleExpr)*;



//
// stmt
//
fnStmt:						Fn Id QuotYuanL Id* QuotYuanR QuotHuaL stmt* QuotHuaR;
stmt:						(fnStmt | expr) '\n';
program:					stmt* EOF;



//
// skips
//
Comment1:					'/*' .*? '*/' -> channel (HIDDEN);
Comment2:					'//' ~ [\r\n]* -> channel (HIDDEN);
WS:							[ \t\r\n]+ -> channel (HIDDEN);


