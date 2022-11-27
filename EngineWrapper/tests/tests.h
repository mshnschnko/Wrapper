#include <iostream>

class SumSubject {
public:
	int	sum(int const a, int const b) {
		return a + b;
	}
};

class MultiplySubject {
public:
	int	multiply(int const a, int const b) {
		return a * b;
	}
};

class GetMaxSubject {
public:
	int	getMax(int const a, int const b) {
		return std::max(a, b);
	}
};