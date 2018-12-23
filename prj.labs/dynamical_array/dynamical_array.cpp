#include <iostream>
#include <sstream>
#include "dynamical_array.h"

using namespace std;

DynamicalArray::DynamicalArray() 
{
	size_ = 0;
	data_ = new int[size_];
}

DynamicalArray::DynamicalArray(const int size)
{
	if (size < 0)
	{
		throw std::exception("Size should be not negative");
	}
	size_ = size;
	data_ = new int[size_];
}

DynamicalArray::DynamicalArray(const DynamicalArray& rhs)
{
	size_ = rhs.size_;
	data_ = new int[size_];

	for (int i(0); i < size_; i++)
	{
		data_[i] = rhs.data_[i];
	}
}

int DynamicalArray::getSize()
{
	return size_;
}

void DynamicalArray::setSize(const int size) 
{
	int* T = new int[size];
	for (int i = 0; i < size_; i++) {
		T[i] = data_[i];
	}
	delete[] data_;
	data_ = T;
	size_ = size;
}

int& DynamicalArray::operator[](const int i)
{
	return data_[i];
}

DynamicalArray::~DynamicalArray()
{
	delete[] data_;
}

std::ostream& DynamicalArray::writeTo(std::ostream& ostrm) const 
{
	ostrm << "{ ";
	for (int i(0); i < size_; i++)
	{
		ostrm << data_[i] << " ";
	}
	ostrm << "}" << endl;
	return ostrm;
}

std::istream& DynamicalArray::readFrom(std::istream& istrim)
{
	return istrim;
}

ostream& operator<<(ostream& ostrm, const DynamicalArray& rhs)
{
	return rhs.writeTo(ostrm);
}

istream& operator>>(istream& istrm, DynamicalArray& rhs)
{
	return rhs.readFrom(istrm);
}
