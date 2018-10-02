#include <iostream>
#include <sstream>
#include "rational.h"

using namespace std;

inline ostream& operator<<(ostream& ostrm, const Rational& rhs)
{
	return rhs.writeTo(ostrm);
}

inline istream& operator>>(istream& istrm, Rational& rhs)
{
	return rhs.readFrom(istrm);
}

void testSum() {
	Rational test1(5);
	Rational test2(2, 5);
	test2 += test1;
	test2 += test2;
	cout << test2 << endl;
}

void testMul() {
	Rational test1(5);
	Rational test2(2, 5);
	test2 *= test1;
	test2 *= test2;
	test2 /= test1;	
	cout << test2 << endl;
}

int main()
{

}