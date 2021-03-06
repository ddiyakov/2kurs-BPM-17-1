#pragma once
#ifndef STACK_ON_LIST
#define STACK_ON_LIST

#include <iostream>
#include <sstream>

template<class T>
class StackOnList {
 public:
    StackOnList() = default;

    StackOnList(const StackOnList &rhs);

    bool isEmpty();

    void pop();

    T top();

    void push(T rhs);

    void clear();

    StackOnList &operator=(const StackOnList &obj);

    ~StackOnList();

    std::ostream &writeTo(std::ostream &ostrm) const;

 private:
    struct Node {
        Node *next_{nullptr};
        T data_{nullptr};

        Node(Node *p, const T v)
                : next_(p), data_(v) {
        }
    };

 private:
    Node *node_{nullptr};
};

template<class T>
StackOnList<T>::StackOnList(const StackOnList &rhs) {
    StackOnList<T> other;
    Node *node_rhs = rhs.node_;
    while (nullptr != node_rhs) {
        other.push((*node_rhs).data_);
        node_rhs = (*node_rhs).next_;
    }
    while (!other.isEmpty()) {
        push(other.top());
        other.pop();
    }
}

template<class T>
StackOnList<T>::~StackOnList() {
    clear();
}

template<class T>
bool StackOnList<T>::isEmpty() {
    return nullptr == node_;
}

template<class T>
void StackOnList<T>::push(T rhs) {
    node_ = new Node(node_, rhs);
}

template<class T>
void StackOnList<T>::pop() {
    if (isEmpty()) {
        throw std::logic_error("Your stack is empty.");
    }
    Node *deleted(node_);
    node_ = (*node_).next_;
    delete deleted;
}

template<class T>
T StackOnList<T>::top() {
    if (isEmpty()) {
        throw std::logic_error("Your stack is empty.");
    }
    return (*node_).data_;
}

template<class T>
void StackOnList<T>::clear() {
    while (!isEmpty()) {
        pop();
    }
}

template<class T>
StackOnList<T> &StackOnList<T>::operator=(const StackOnList<T> &obj) {
    if (this != &obj) {
        clear();
        StackOnList<T> other;
        Node *node_rhs = rhs.node_;
        while (nullptr != node_rhs) {
            other.push((*node_rhs).data_);
            node_rhs = (*node_rhs).next_;
        }
        while (!other.isEmpty()) {
            push(other.top());
            other.pop();
        }
    }
    return *this;
}

template<class T>
std::ostream &StackOnList<T>::writeTo(std::ostream &ostrm) const {
    Node *node_pr = node_;
    ostrm << "(";
    while (nullptr != node_pr) {
        ostrm << (*node_pr).data_;
        node_pr = (*node_pr).next_;
        if (nullptr != node_pr) {
            ostrm << ",";
        }
    }
    ostrm << ")";
    return ostrm;
}

template<class T>
inline std::ostream &operator<<(std::ostream &ostrm, const StackOnList<T> &stack) {
    return stack.writeTo(ostrm);
}

#endif