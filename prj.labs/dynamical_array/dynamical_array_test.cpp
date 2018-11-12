#include <iostream>
#include <sstream>
#include "dynamical_array.h"

using namespace std;

void testInit() {
	DynamicalArray test1;
	DynamicalArray test2(5);
	DynamicalArray test3(test2);
	cout << test2.getSize();
	test1 = test2;
	cout << test1.getSize();
	cout << test3.getSize();
}

void testExceptions() {
	try {
		DynamicalArray test(-5);
	}
	catch (const std::exception ex) {

	}
}

int main() {
	testInit();
	testExceptions();
}