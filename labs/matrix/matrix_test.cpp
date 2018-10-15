#include <iostream>
#include <sstream>
#include "matrix.h"

using namespace std;

void testInit()
{
	Matrix test1();
	Matrix test2(5, 6);
	Matrix test3(test2);
	
	cout << test3.getSizeX() << test3.getSizeY() << endl;
}

int main() {
	testInit();
}