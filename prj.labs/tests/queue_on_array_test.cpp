#include <iostream>
#include <sstream>
#include "queue_on_array.h"

bool test1() {
	QueueOnArray t1;
	t1.push(5);
	t1.push(3);
	t1.pop();
	t1.push(-1);

	QueueOnArray t2(t1);
	t2.pop();
	std::cout << t1 << std::endl;
	std::cout << t2 << std::endl;
	
	return 3 == t1.top() && -1 == t2.top();
}

bool test2() {
	QueueOnArray t1;
	t1.push(5);
	t1.push(6);
	t1.push(5);
	t1.pop();
	t1.push(5);
	t1.push(5);
	t1.push(5);
	t1.push(5);
	t1.push(5);
	t1.push(5);
	t1.push(6);
	return 6 == t1.top();
}

int main()
{
	std::cout << test1() << std::endl;
	std::cout << test2() << std::endl;
	
}

