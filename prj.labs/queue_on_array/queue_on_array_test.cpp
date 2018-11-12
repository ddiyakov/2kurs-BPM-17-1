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
	return t1.top() == t2.top() && t2.top() == 3;
}

int main()
{
	std::cout << test1();
}

