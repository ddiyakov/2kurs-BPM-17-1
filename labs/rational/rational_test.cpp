#include <iostream>
#include <sstream>
#include "rational.h"

using namespace std;

void testInit() {
	Rational test1(5);
	Rational test2(25, 5);
	cout << (test1 == test2) << endl;
	cout << endl;
}

void testSum() {
	Rational test1(5);
	Rational test2(2, 5);
	test2 += test1;
	cout << test2 << endl;
	test2 += test2;
	cout << test2 << endl;
	cout << endl;
}

void testMul() {
	Rational test1(5);
	Rational test2(2, 5);
	test2 *= test1;
	cout << test2 << endl;
	test2 *= test2;
	cout << test2 << endl;
	test2 /= test1;	
	cout << test2 << endl;
	cout << endl;
}

int main()
{
	testInit();
	testMul();
	testSum();
}