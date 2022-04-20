#include <iostream>
#include <exception>

template<class T>
class VariableWithBoolean {
public:


	VariableWithBoolean() {	}
	VariableWithBoolean(const T& In) :V(In) {}

	operator const T() {
		Crash();
		return V;
	}
	const T& operator = (const T& In) {
		Crash();
		V = In;
		return In;
	}
	bool Crash() {
		if (!F) { throw std::logic_error("Value is disabled."); }
		return false;
	}

	bool Set(bool In) {
		F = In;
		return true;
	}

	bool IsSet() {
		return F;
	}

	bool Turn() {
		F = !F;
		return true;
	}

protected:
	T V{0};
	bool F = false;
};

int main() {
	VariableWithBoolean<int> V=10;
	V.Set(true);

	V = 20;
	//V.Turn();
	V = 40;

	return 0; 


}