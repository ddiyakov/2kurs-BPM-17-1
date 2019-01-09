#pragma once

#ifndef QUEUE_ON_ARRAY
#define QUEUE_ON_ARRAY

class QueueOnArray {
 public:
    explicit QueueOnArray(const int size);

    QueueOnArray(const QueueOnArray &rhs);

    QueueOnArray &operator=(const QueueOnArray &rhs);

    bool isEmpty();

    bool isFull();

    void push(int a);

    void pop();

    int top();

    std::ostream &writeTo(std::ostream &ostrm) const;

    ~QueueOnArray();

 private:
    int *data_{nullptr};
    int size_{0};
    int i_first{0};
    int i_last{0};
};

std::ostream &operator<<(std::ostream &ostrm, const QueueOnArray &rhs);

#endif 
