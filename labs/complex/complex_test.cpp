#include <iostream>
#include <sstream>
#include "complex.h"

using namespace std;

void testCreates()
{
	Complex t1(1);
	cout << t1 << endl;
	Complex t2(1.0, 5.5);
	cout << t2 << endl;
	cout << endl;
}

void testAriphmetics()
{
	Complex t1(1);
	Complex t2(1.0, 5.5);
	Complex t3(0);
	t3 = t1 + t2;
	t1 += t2;
	cout << (t1 == t3) << endl;
	cout << endl;
}

void testMultiple()
{
	Complex t1(1);
	Complex t2(1.0, 5.5);
	Complex t3(2.0, 4.5);
	cout << t2 << endl;
	t2 *= t3;
	cout << t2 << endl;
	t2 /= t3;
	cout << t2 << endl;
	cout << endl;
}

int main()
{
	testCreates();
	testAriphmetics();
	testMultiple();
}