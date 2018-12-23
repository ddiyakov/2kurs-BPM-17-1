#include <iostream>
#include <sstream>
#include "dynamical_array/dynamical_array.h"

using namespace std;

void testInit() {
	DynamicalArray test2(5);
	DynamicalArray test3(test2);
	cout << test2.getSize() << endl;
	cout << test3.getSize() << endl;
	test2.setSize(7);
	cout << test2.getSize() << endl;
	cout << test3.getSize() << endl;

	for (int i = 0; i < test2.getSize(); i++) {
		test2[i] = i + 1;
	}
	cout << test2 << endl;
}

void testExceptions() {
	try {
		DynamicalArray test(-5);
	}
	catch (const std::exception ex) {
		cout << "successful" << endl;
	}
	DynamicalArray test(5);
	try {
		test.setSize(-5);
	}
	catch (const std::exception ex) {
		cout << "successful" << endl;
	}
}

int main() {
	testInit();
	testExceptions();
}