#include <iostream>
#include <sstream>
#include "stack_on_list.h"

bool test1() {
	StackOnList<int> t1;
	t1.push(5);
	t1.push(3);
	t1.pop();
	t1.push(-1);
	
	StackOnList<int> t2(t1);
	return t2.top() == t1.top() && t2.top() == -1;
}

int main()
{
	if (test1()) {
		std::cout << "Oh";
	}
}