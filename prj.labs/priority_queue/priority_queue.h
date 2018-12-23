#pragma once
#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

class PriorityQueue {
public:
	PriorityQueue() = default;
	explicit PriorityQueue(int size);
	PriorityQueue(const PriorityQueue &obj);
	~PriorityQueue();

	bool isEmpty() const;
	bool isFull() const;
	int top() const;
	int pop();

	void enqueue(int value, int priority);

	PriorityQueue &operator=(const PriorityQueue &rhs);

private:
	int *data_;
	int *priorities_;
	int size_;
	int end_;
};

#endif