#include <iostream>
#include <sstream>
#include "matrix/matrix.h"

using namespace std;

void testInit()
{
    Matrix test1;
    Matrix test2(5, 6);
    Matrix test3(test2);
    
    cout << test3.getSizeX() << test3.getSizeY() << endl;
}

void testCout()
{
    Matrix test(3, 3);

    for (int i(0); i < 3; i++)
    {
        for (int j(0); j < 3; j++)
        {
            test.at(i, j) = 1;
        }
    }

    cout << test << endl;
}

void testException()
{
    try
    {
        Matrix test(-5, 6);
        cout << "not successful" << endl;
    }
    catch (const std::exception&)
    {
        cout << "successful" << endl;
    }
    try
    {
        Matrix test(5, -6);
        cout << "not successful" << endl;
    }
    catch (const std::exception&)
    {
        cout << "successful" << endl;
    }
    try
    {
        Matrix test(-5, -6);
        cout << "not successful" << endl;
    }
    catch (const std::exception&)
    {
        cout << "successful" << endl;
    }
    try
    {
        Matrix test(5, 6);
        cout << "successful" << endl;
    }
    catch (const std::exception&)
    {
        cout << "not successful" << endl;
    }
}

int main() {
    testInit();
    testCout();
    testException();
}