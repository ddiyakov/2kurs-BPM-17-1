#include <iostream>
#include <sstream>
#include "queue_on_array.h"

QueueOnArray::QueueOnArray(const int size) {
    size_ = size;
    data_ = new int[size_]{0};
}

QueueOnArray::QueueOnArray(const QueueOnArray &rhs) {
    size_ = rhs.size_;
    data_ = new int[size_]{0};
    i_first = rhs.i_first % size_;
    i_last = rhs.i_last % size_;

    for (int i(0); i < size_; i++) {
        data_[i] = rhs.data_[i];
    }
}

QueueOnArray::~QueueOnArray() {
    delete[] data_;
}

QueueOnArray &QueueOnArray::operator=(const QueueOnArray &rhs) {
    if (this != &rhs) {
        if (size_ < rhs.size_) {
            int *newData(new int[rhs.size_]);
            delete[] data_;
            data_ = newData;
        }
        std::copy(rhs.data_, rhs.data_ + rhs.size_, data_);
        size_ = rhs.size_;
    }
    return *this;
}

void QueueOnArray::push(int a) {
    if (!((i_last - i_first) == size_)) {
        data_[i_last % size_] = a;
        i_last++;
    } else {
        int* data_new = new int[size_ * 2];

		for (int i = 0; i < size_; i++) {
			data_new[i] = data_[(i_first + i) % size_];
		}
		delete[] data_;

		data_ = data_new;
		i_first = 0;
		i_last = size_;
		size_ = size_ * 2;
		data_[i_last++] = a;
    }
}

bool QueueOnArray::isEmpty() {
    return (i_last - i_first) == 0;
}

void QueueOnArray::pop() {
    if (!isEmpty()) {
        i_first++;
    } else {
        throw std::exception("Empty queue exception");
    }
}

int QueueOnArray::top() {
    if (!isEmpty()) {
        return data_[i_first];
    } else {
        throw std::exception("Empty queue exception");
    }
}

std::ostream &QueueOnArray::writeTo(std::ostream &ostrm) const {
    ostrm << "( ";
    for (int i = i_first; i < i_last; i++) {
        ostrm << data_[i % size_] << " ";
    }
    ostrm << ")";
    return ostrm;
}

std::ostream &operator<<(std::ostream &ostrm, const QueueOnArray &rhs) {
    return rhs.writeTo(ostrm);
}


