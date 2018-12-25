#pragma once
#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

class PriorityQueue {
public:

    explicit PriorityQueue(int size);
    PriorityQueue(const PriorityQueue &obj);
    ~PriorityQueue();

    bool isEmpty() const;
    bool isFull() const;
    int top() const;
    void pop();
    void push(int value, int priority);

    std::ostream& writeTo(std::ostream& ostrm) const;

private:
    int* values;
    int* priots;
    int size_{ 0 };
    int end_{ 0 };
};

std::ostream& operator<<(std::ostream& ostrm, const PriorityQueue& rhs);

#endif