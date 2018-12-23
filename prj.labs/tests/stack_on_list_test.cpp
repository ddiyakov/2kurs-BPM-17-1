#include <iostream>
#include <sstream>
#include "stack_on_list/stack_on_list.h"

bool test1() {
	StackOnList<int> t1;
	try {
		t1.pop();
		std::cout << "not successful" << std::endl;
	}
	catch (const std::exception ex) {
		std::cout << "successful" << std::endl;
	}
	t1.push(5);
	t1.push(3);
	t1.pop();
	t1.push(-1);
	
	StackOnList<int> t2(t1);
	t2.pop();
	std::cout << t1 << std::endl;
	std::cout << t2 << std::endl;
	return -1 == t1.top() && 5 == t2.top();
}

int main()
{
	std::cout << test1() << std::endl;
}