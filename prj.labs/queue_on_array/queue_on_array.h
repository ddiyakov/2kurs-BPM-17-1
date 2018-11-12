#pragma once

#ifndef QUEUE_ON_ARRAY
#define QUEUE_ON_ARRAY

class QueueOnArray {
public:
	QueueOnArray();
	QueueOnArray(const QueueOnArray& rhs);
	QueueOnArray& operator=(const QueueOnArray& rhs);
	bool isEmpty();
	void push(int a);
	void pop();
	int top();

	~QueueOnArray();
private:
	int* data_{ nullptr };
	int size_{ 0 };
	int i_first{ 0 };
	int i_last{ 1 };	
};

#endif 
