#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#define _SILENCE_CXX20_CODECVT_HEADER_DEPRECATION_WARNING
#define _SILENCE_ALL_CXX20_DEPRECATION_WARNINGS

#pragma warning (disable: 4217)
#pragma warning (disable: 4286)

#include <iostream>
#include <string>

#include "../fascript/fascript.h"
#pragma comment (lib, "../Debug/fascript.lib")



int main () {
	auto _s = std::make_shared<fas::FAScript> ();
	_s->RunCode (R"(
fn test (a) {
	return a+1
}
test (3)
)");
	std::cout << "Hello World!\n";
	return 0;
}
