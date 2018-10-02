#pragma once

#include <iostream>
#include <sstream>

class Rational
{
public:
	Rational() = default;
	explicit Rational(const int chis);
	Rational(const int chis, const int znam);

	int getChislitel();
	void setChislitel(int chis);

	int getZnamenatel();
	void setZnamenatel(int znam);

	bool operator==(const Rational& rhs) const;
	bool operator!=(const Rational& rhs) const;

	Rational& operator+=(const Rational& rhs);
	Rational& operator+=(const int rhs);

	Rational& operator-=(const Rational& rhs);
	Rational& operator-=(const int rhs);

	Rational& operator*=(const Rational& rhs);
	Rational& operator*=(const int rhs);

	Rational& operator/=(const Rational& rhs);
	Rational& operator/=(const int rhs);

	void normalize();

	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrim);

	static const char leftBrace{ '{' };
	static const char separator{ '/' };
	static const char rightBrace{ '}' };
private:
	int chis{ 0 };
	int znam{ 1 };
};

Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const Rational& rhs);
