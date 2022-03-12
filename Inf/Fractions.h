#pragma once
#include <iostream>
#include <cassert>
class Fractions
{
private:
	int _numerator;
	int _denominator;
	
	int GCD(int first, int second) const;
	int LCM(int first, int second) const;

	void Reduction(int &numerator, int &denominator);

	friend std::ostream& operator << (std::ostream& out, const Fractions& fraction);
	friend std::istream& operator >> (std::istream& in, Fractions& fraction);


public:
	Fractions();
	Fractions(int numerator, int denominator);
	Fractions(const Fractions& obj);

	Fractions operator+(const Fractions fraction) const;
	Fractions operator+(const int term) const;

	Fractions operator-(const Fractions fraction) const;
	Fractions operator-(const int subtrahend) const;

	Fractions operator*(const Fractions fraction) const;
	Fractions operator*(const int factor) const;

	Fractions operator/(const Fractions fraction) const;
	Fractions operator/(const int divider) const;

	Fractions& operator=(const Fractions fraction);
	Fractions& operator=(const int number);

	bool operator==(const Fractions fraction) const;
	bool operator==(const int temp) const;


};