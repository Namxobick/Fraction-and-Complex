#pragma once
#include <iostream>
#include <cassert>
#include "Fractions.h"

class Complex
{
private:
	Fractions _reZ;
	Fractions _imZ;

	friend std::ostream& operator << (std::ostream& out, const Complex& ñomplex);
	friend std::istream& operator >> (std::istream& in, Complex& ñomplex);

public:
	Complex();
	Complex(int reZ, int imZ);
	Complex(Fractions reZ, int imZ);
	Complex(int reZ, Fractions imZ);
	Complex(Fractions reZ, Fractions imZ);
	Complex(const Complex& obj);

	Complex operator+(const Complex complex) const;
	Complex operator+(const Fractions fractions) const;
	Complex operator+(const int term) const;

	Complex operator-(const Complex complex) const;
	Complex operator-(const Fractions fractions) const;
	Complex operator-(const int term) const;

	Complex operator*(const Complex complex) const;
	Complex operator*(const Fractions fractions) const;
	Complex operator*(const int term) const;

	Complex operator/(const Complex complex) const;
	Complex operator/(const Fractions fractions) const;
	Complex operator/(const int term) const;

	Complex& operator=(const Complex complex);
	Complex& operator=(const Fractions fractions);
	Complex& operator=(const int term);

	Complex operator+() const;
	Complex operator-() const;

	Complex& operator++();
	Complex operator++(int);

	Complex& operator--();
	Complex operator--(int);

	void operator+=(const Complex complex);
	void operator+=(const Fractions fraction);
	void operator+=(const int term);

	void operator-=(const Complex complex);
	void operator-=(const Fractions fraction);
	void operator-=(const int term);

	void operator*=(const Complex complex);
	void operator*=(const Fractions fraction);
	void operator*=(const int term);

	void operator/=(const Complex complex);
	void operator/=(const Fractions fraction);
	void operator/=(const int term);

	bool operator==(const Complex complex) const;
	bool operator==(const Fractions fraction) const;
	bool operator==(const int term) const;

	bool operator!=(const Complex complex) const;
	bool operator!=(const Fractions fraction) const;
	bool operator!=(const int term) const;
};

