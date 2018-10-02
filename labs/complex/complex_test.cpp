#include <iostream>
#include <sstream>
#include "complex.h"

using namespace std;

inline ostream& operator<<(ostream& ostrm, const Complex& rhs)
{
	return rhs.writeTo(ostrm);
}

inline istream& operator>>(istream& istrm, Complex& rhs)
{
	return rhs.readFrom(istrm);
}

int main()
{
	
}