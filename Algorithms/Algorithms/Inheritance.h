#pragma once
#include <iostream>

class Base {
protected:
	virtual void func() {
		cout << "BASE";
	}
};

class Child : public Base {
public:
	virtual void func() override {
		cout << "CHILD \n";
}

	void childFunc() {
		cout << "only child can do this! \n";
	}
};

class Unrelated {

};