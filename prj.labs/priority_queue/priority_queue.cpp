#include <algorithm>
#include <iostream>
#include <sstream>
#include "priority_queue.h"

PriorityQueue::PriorityQueue(int size)
        : size_(size) {
    if (size < 0) {
        throw std::exception("Size should be not negative");
    }
    values = new int[size];
    priots = new int[size];
}

PriorityQueue::PriorityQueue(const PriorityQueue &obj)
        : size_(obj.size_), end_(obj.end_) {

    values = new int[obj.size_];
    for (int i = 0; i < obj.size_; i++) {
        values[i] = obj.values[i];
    }

    priots = new int[obj.size_];
    for (int i = 0; i < obj.size_; i++) {
        priots[i] = obj.priots[i];
    }
}

PriorityQueue::~PriorityQueue() {
    delete[] values;
    delete[] priots;
}


bool PriorityQueue::isEmpty() const {
    return end_ == 0;
}

bool PriorityQueue::isFull() const {
    return size_ == end_;
}

int PriorityQueue::top() const {
    if (isEmpty()) {
        throw std::exception("Queue is empty");
    }
    return values[end_ - 1];
}

void PriorityQueue::pop() {
    if (isEmpty()) {
        throw std::exception("Queue is empty");
    }
    end_--;
}

void PriorityQueue::push(int value, int priority) {
    if (isFull()) {
        throw std::exception("Queue is full");
    }

    bool isPushed = false;

    for (int i(0); i < end_; i++) {
        if (priority >= priots[i]) {
            for (int j(end_); j > i; j--) {
                values[j] = values[j - 1];
                priots[j] = priots[j - 1];
            }
            values[i] = value;
            priots[i] = priority;
            isPushed = true;
            break;
        }
    }

    if (!isPushed) {
        values[end_] = value;
        priots[end_] = priority;
    }

    end_++;
}

std::ostream &PriorityQueue::writeTo(std::ostream &ostrm) const {
    ostrm << "( ";
    for (int i = 0; i < end_; i++) {
        ostrm << values[i] << " ";
    }
    ostrm << ")";
    return ostrm;
}

std::ostream &operator<<(std::ostream &ostrm, const PriorityQueue &rhs) {
    return rhs.writeTo(ostrm);
}