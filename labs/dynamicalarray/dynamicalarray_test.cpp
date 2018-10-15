#include <iostream>
#include <sstream>
#include "dynamicalarray.h"

using namespace std;

void testInit() {
	DynamicalArray test1();
	DynamicalArray test2(5);
	DynamicalArray test3(test2);
	cout << test2.getSize();
}

int main() {
	testInit();
}