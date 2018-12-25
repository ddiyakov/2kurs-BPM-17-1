#include <iostream>
#include <sstream>
#include "priority_queue/priority_queue.h"

void testCreature() {
    try {
        PriorityQueue test1(-3);
        std::cout << "unsuccessful" << std::endl;
    }
    catch (const std::exception ex) {
        std::cout << "successful" << std::endl;
    }

    PriorityQueue test1(3);
    try {
        test1.pop();
        std::cout << "unsuccessful" << std::endl;
    }
    catch (const std::exception ex) {
        std::cout << "successful" << std::endl;
    }

    test1.push(1, 5);
    test1.push(2, 4);
    test1.push(5, 5);

    try {
        test1.push(3, 4);
        std::cout << "unsuccessful" << std::endl;
    }
    catch (const std::exception ex) {
        std::cout << "successful" << std::endl;
    }

    std::cout << test1 << std::endl;
}

void testAndrey() {
    PriorityQueue queue1(10);
    try {
        queue1.push(1, 3);
        queue1.push(2, 5);
        queue1.push(3, 10);
        queue1.push(4, 1);
        queue1.push(9, 0);
    }
    catch (const std::exception&) {
        std::cout << "Queue is full" << std::endl;
    }

    PriorityQueue queue2(queue1);
    std::cout << queue1 << std::endl;
    std::cout << queue2 << std::endl;

    std::cout << "queue2.top() = " << queue2.top() << std::endl;

    PriorityQueue queue3(10);
    try {
        queue3.pop();
    }
    catch (const std::exception&) {
        std::cout << "queue3 is empty" << std::endl;
    }
}

int main()
{
    testCreature();
    testAndrey();
}