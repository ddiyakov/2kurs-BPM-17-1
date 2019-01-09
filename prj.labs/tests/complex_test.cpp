#include <iostream>
#include <sstream>
#include "complex/complex.h"

void testCreates() {
    Complex t1(1);
    std::cout << t1 << std::endl;
    Complex t2(1.0, 5.5);
    std::cout << t2 << std::endl;
    std::cout << std::endl;
}

void testAriphmeticsAndEquals() {
    Complex t1(1);
    Complex t2(1.0, 5.5);
    Complex t3(0);
    t3 = t1 + t2;
    t1 += t2;
    std::cout << (t1 == t3) << std::endl;
    std::cout << (t1 == t2) << std::endl;
    std::cout << (t1 != t2) << std::endl;
    std::cout << std::endl;
}

void testMultiple() {
    Complex t1(0);
    Complex t2(1.0, 5.5);
    Complex t3(2.0, 4.5);
    std::cout << t2 << std::endl;
    t2 *= t3;
    std::cout << t2 << std::endl;
    t2 /= t3;
    std::cout << t2 << std::endl;
    try {
        t2 /= t1;
        std::cout << "not successful" << std::endl;
    } catch (const std::exception &) {
        std::cout << "successful" << std::endl;
    }
    try {
        t2 /= 0;
        std::cout << "not successful" << std::endl;
    } catch (const std::exception &) {
        std::cout << "successful" << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    testCreates();
    testAriphmeticsAndEquals();
    testMultiple();
}