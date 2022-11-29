// EngineWrapper.cpp: определяет точку входа для приложения.
//
#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#include "EngineWrapper.h"

void MemoryLeaks(void)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
}

int main() {
	Engine engine;

	// SUM
	SumSubject sub1;
	Wrapper wrapper1(&sub1, &SumSubject::sum, { {"arg1", 1},{"arg2", 2} });

	try {
		engine.register_command(&wrapper1, "sum");
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << engine.execute("sum", { {"arg1", 1},{"arg2", 2} }) << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	// ANOTHER SUM
	try {
		std::cout << engine.execute("sum", { {"arg1", 3},{"arg2", 2} }) << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	// MULTIPLY
	MultiplySubject sub2;
	Wrapper wrapper2(&sub2, &MultiplySubject::multiply, { {"arg1", 1},{"arg2", 2} });
	try {
		engine.register_command(&wrapper2, "mult");
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << engine.execute("mult", { {"arg1", 4},{"arg2", 2} }) << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	// GET MAX
	GetMaxSubject sub3;
	Wrapper wrapper3(&sub3, &GetMaxSubject::getMax, { {"arg1", 1},{"arg2", 2} });

	try {
		engine.register_command(&wrapper3, "max");
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << engine.execute("max", { {"arg1", 1},{"arg2", 2} }) << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	MemoryLeaks();
	return 0;
}
