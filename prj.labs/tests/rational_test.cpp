#include <iostream>
#include "rational/rational.h"

using namespace std;

void testInit() {
    Rational test1(5);
    Rational test2(25, 5);
    Rational test3(25, -5);
    Rational test4(-25, -5);
    Rational test5(-25, 5);
    try {
        Rational test6(5, 0);
        cout << "not successful" << endl;
    }
    catch (const std::exception &) {
        cout << "successful" << endl;
    }
    cout << (test1 == test2) << endl;
    cout << (test1 == test3) << endl;
    cout << (test1 == test4) << endl;
    cout << (test1 == test5) << endl;
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
    Rational test2(2, -5);
    Rational test3(0);
    test2 *= 2;
    cout << test2 << endl;
    test2 *= test2;
    cout << test2 << endl;
    test2 /= test1;
    cout << test2 << endl;
    test2 *= -1;
    cout << test2 << endl;
    try {
        test1 /= 0;
        cout << "not successful" << endl;
    }
    catch (const std::exception &) {
        cout << "successful";
    }
    try {
        test1 /= test3;
        cout << "not successful" << endl;
    }
    catch (const std::exception &) {
        cout << "successful";
    }
    cout << endl;
}

int main() {
    testInit();
    testMul();
    testSum();
}