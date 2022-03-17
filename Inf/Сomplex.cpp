#include "Ñomplex.h"

Complex::Complex()
{
	_reZ = NULL;
	_imZ = NULL;
}

Complex::Complex(int reZ, int imZ)
{
	_reZ = reZ;
	_imZ = imZ;
}

Complex::Complex(Fractions reZ, int imZ)
{
	_reZ = reZ;
	_imZ = imZ;
}

Complex::Complex(int reZ, Fractions imZ)
{
	_reZ = reZ;
	_imZ = imZ;
}

Complex::Complex(Fractions reZ, Fractions imZ)
{
	_reZ = reZ;
	_imZ = imZ;
}

Complex::Complex(const Complex& obj)
{
	_reZ = obj._reZ;
	_imZ = obj._imZ;
}

std::ostream& operator<<(std::ostream& out, const Complex& ñomplex)
{
	if (ñomplex._reZ == 0)
		return out << ñomplex._imZ << "i" << std::endl;

	if (ñomplex._imZ == 0)
		return out << ñomplex._reZ << std::endl;

	if (ñomplex._imZ < 0)
		return out << ñomplex._reZ << " - " << ñomplex._imZ * (-1) << "i" << std::endl;

	return out << ñomplex._reZ << " + " << ñomplex._imZ << "i" << std::endl;
}

std::istream& operator>>(std::istream& in, Complex& ñomplex)
{
	Fractions reZ, imZ;
	std::cout << "Real part:" << std::endl;
	in >> reZ;
	std::cout << "Imaginary part:" << std::endl;
	in >> imZ;

	ñomplex._reZ = reZ;
	ñomplex._imZ = imZ;
	return in;
}

Complex Complex::operator+(const Complex ñomplex) const
{
	Complex result;
	result._reZ = _reZ + ñomplex._reZ;
	result._imZ = _imZ + ñomplex._imZ;
	return result;
}
Complex  Complex::operator+(const Fractions fraction) const
{
	Complex result;
	result._reZ = _reZ + fraction;
	result._imZ = _imZ;
	return result;
}
Complex Complex::operator+(const int temp) const
{
	Complex result;
	result._reZ = _reZ + temp;
	result._imZ = _imZ;
	return result;
}

Complex Complex::operator-(const Complex ñomplex) const
{
	Complex result;
	result._reZ = _reZ - ñomplex._reZ;
	result._imZ = _imZ - ñomplex._imZ;
	return result;
}
Complex  Complex::operator-(const Fractions fraction) const
{
	Complex result;
	result._reZ = _reZ - fraction;
	result._imZ = _imZ;
	return result;
}
Complex Complex::operator-(const int temp) const
{
	Complex result;
	result._reZ = _reZ - temp;
	result._imZ = _imZ;
	return result;
}

Complex Complex::operator*(const Complex ñomplex) const
{
	Complex result;
	result._reZ = _reZ * ñomplex._reZ - _imZ * ñomplex._imZ;
	result._imZ = _reZ * ñomplex._imZ + _imZ * ñomplex._reZ;
	return result;
}
Complex  Complex::operator*(const Fractions fraction) const
{
	Complex result;
	result._reZ = _reZ * fraction;
	result._imZ = _imZ * fraction;
	return result;
}
Complex Complex::operator*(const int temp) const
{
	Complex result;
	result._reZ = _reZ * temp;
	result._imZ = _imZ * temp;
	return result;
}

Complex Complex::operator/(const Complex ñomplex) const
{
	Complex result;
	result._reZ = (_reZ * ñomplex._reZ + _imZ * ñomplex._imZ) / (ñomplex._reZ * ñomplex._reZ + ñomplex._imZ * ñomplex._imZ);
	result._imZ = (_imZ * ñomplex._reZ - _reZ * ñomplex._imZ) / (ñomplex._reZ * ñomplex._reZ + ñomplex._imZ * ñomplex._imZ);
	return result;
}
Complex Complex::operator/(const Fractions fraction) const
{
	Complex result;
	result._reZ = _reZ / fraction;
	result._imZ = _imZ / fraction;
	return result;
}
Complex Complex::operator/(const int temp) const
{
	Complex result;
	result._reZ = _reZ / temp;
	result._imZ = _imZ / temp;
	return result;
}

Complex& Complex::operator=(const Complex complex)
{
	_reZ = complex._reZ;
	_imZ = complex._imZ;
	return *this;
}
Complex& Complex::operator=(const Fractions fraction)
{
	_reZ = fraction;
	_imZ = 0;
	return *this;
}
Complex& Complex::operator=(const int temp)
{
	_reZ = temp;
	_imZ = 0;
	return *this;
}

Complex Complex::operator+() const
{
	return *this;
}

Complex Complex::operator-() const
{
	return Complex(-_reZ, -_imZ);
}

Complex& Complex::operator++()
{
	_reZ++;
	return *this;
}
Complex Complex::operator++(int)
{
	Complex complex = *this;
	++*this;
	return complex;
}

Complex& Complex::operator--()
{
	_reZ--;
	return *this;
}
Complex Complex::operator--(int)
{
	Complex complex = *this;
	--* this;
	return complex;
}

void Complex::operator+=(const Complex complex)
{
	*this = *this + complex;
}
void Complex::operator+=(const Fractions fraction)
{
	*this = *this + fraction;
}
void Complex::operator+=(const int term)
{
	*this = *this + term;
}

void Complex::operator-=(const Complex complex)
{
	*this = *this -+ complex;
}
void Complex::operator-=(const Fractions fraction)
{
	*this = *this - fraction;
}
void Complex::operator-=(const int term)
{
	*this = *this - term;
}

void Complex::operator*=(const Complex complex)
{
	*this = *this * +complex;
}
void Complex::operator*=(const Fractions fraction)
{
	*this = *this * fraction;
}
void Complex::operator*=(const int term)
{
	*this = *this * term;
}

void Complex::operator/=(const Complex complex)
{
	*this = *this / +complex;
}
void Complex::operator/=(const Fractions fraction)
{
	*this = *this / fraction;
}
void Complex::operator/=(const int term)
{
	*this = *this / term;
}

bool Complex::operator==(const Complex complex) const
{
	if (_reZ == complex._reZ and _imZ == complex._imZ)
		return true;
	return false;
}
bool Complex::operator==(const Fractions fraction) const
{
	if (_reZ == fraction and _imZ == 0)
		return true;
	return false;
}
bool Complex::operator==(const int term) const
{
	if (_reZ == term and _imZ == 0)
		return true;
	return false;
}

bool Complex::operator!=(const Complex complex) const
{
	if (_reZ == complex._reZ and _imZ == complex._imZ)
		return false;
	return true;
}
bool Complex::operator!=(const Fractions fraction) const
{
	if (_reZ == fraction and _imZ == 0)
		return false;
	return true;
}
bool Complex::operator!=(const int term) const
{
	if (_reZ == term and _imZ == 0)
		return false;
	return true;
}
