#pragma once
#ifndef DYNAMICALARRAY_H
#define DYNAMICALARRAY_H

#include <iostream>
#include <sstream>

class DynamicalArray {
public:
	DynamicalArray();
	DynamicalArray(const int size);
	DynamicalArray(const DynamicalArray& rhs);

	DynamicalArray& operator=(DynamicalArray&& rhs);

	int getSize();

	int& operator[](const int i);
	
	~DynamicalArray();

	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrim);

private:
	int size_{ 0 };
	int* data_{ nullptr };
};

std::istream& operator>>(std::istream& istrm, DynamicalArray& rhs);
std::ostream& operator<<(std::ostream& ostrm, const DynamicalArray& rhs);

#endif