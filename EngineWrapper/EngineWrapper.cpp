// EngineWrapper.cpp: определяет точку входа для приложения.
//

#include "EngineWrapper.h"


int main() {
	Engine engine;
	SumSubject* sub1 = new SumSubject;
	Wrapper* wrapper1 = new Wrapper(sub1, &SumSubject::sum, { {"arg1", 1},{"arg2", 2} });
	MultiplySubject* sub2 = new MultiplySubject;
	Wrapper* wrapper2 = new Wrapper(sub2, &MultiplySubject::multiply, { {"arg1", 1},{"arg2", 2} });
	GetMaxSubject* sub3 = new GetMaxSubject;
	Wrapper* wrapper3 = new Wrapper(sub3, &GetMaxSubject::getMax, { {"arg1", 1},{"arg2", 2} });

	// SUM
	try {
		engine.register_сommand(wrapper1, "sum");
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
	try {
		engine.register_сommand(wrapper2, "mult");
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
	try {
		engine.register_сommand(wrapper3, "max");
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
	return 0;
}
