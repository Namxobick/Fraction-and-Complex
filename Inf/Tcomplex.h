#pragma once
#include <iostream>
#include <cassert>
#include <complex>
#include "Fractions.h"

template<class T1, class T2>
class Tcomplex
{
private:
	Fractions _reZ;
	Fractions _imZ;

	template<class A, class B>
    friend std::ostream& operator << (std::ostream& out, const Tcomplex<A, B>& complex);

	template<class A, class B>
	friend std::istream& operator >> (std::istream& in, Tcomplex<A, B>& complex);

public:

	Fractions GetReZ() { return _reZ; };
	Fractions GetImZ() { return _imZ; };

    Tcomplex();
    Tcomplex(T1 reZ);
    Tcomplex(T1 reZ, T2 imZ);
    Tcomplex(const Tcomplex& complex);

	template<class T3, class T4>
	Tcomplex<Fractions, Fractions> operator+ (Tcomplex<T3, T4> complex) const;

	template<class T3, class T4>
	Tcomplex<Fractions, Fractions> operator- (Tcomplex<T3, T4> complex) const;

	template<class T3, class T4>
	Tcomplex<Fractions, Fractions> operator* (Tcomplex<T3, T4> complex) const;

	template<class T3, class T4>
	Tcomplex<Fractions, Fractions> operator/ (Tcomplex<T3, T4> complex) const;
};

template<class T1, class T2>
inline Tcomplex<T1, T2>::Tcomplex()
{
	_reZ = 0;
	_imZ = 0;
}

template<class T1, class T2>
Tcomplex<T1, T2>::Tcomplex(T1 reZ, T2 imZ)
{
	_reZ = reZ;
	_imZ = imZ;
}

template<class T1, class T2>
Tcomplex<T1, T2>::Tcomplex(const Tcomplex& complex)
{
	_reZ = complex._reZ;
	_imZ = complex._imZ;
}

template<class T1, class T2>
Tcomplex<T1, T2>::Tcomplex(T1 reZ)
{
	_reZ = reZ;
	_imZ = 0;
}

template<class T1, class T2>
std::ostream& operator<<(std::ostream& out, const Tcomplex<T1, T2>& complex)
{
	if (complex._reZ == 0)
		return out << complex._imZ << "i" << std::endl;

	if (complex._imZ == 0)
		return out << complex._reZ << std::endl;

	if (complex._imZ < 0)
		return out << complex._reZ << " - " << complex._imZ * (-1) << "i" << std::endl;

	return out << complex._reZ << " + " << complex._imZ << "i" << std::endl;
}

template<class T1, class T2>
std::istream& operator>>(std::istream& in, Tcomplex<T1, T2>& complex)
{
	Fractions reZ, imZ;
	std::cout << "Real part:" << std::endl;
	in >> reZ;
	std::cout << "Imaginary part:" << std::endl;
	in >> imZ;

	complex._reZ = reZ;
	complex._imZ = imZ;
	return in;
}

template<class T1, class T2>
template <class T3, class T4>
Tcomplex<Fractions, Fractions> Tcomplex<T1, T2>::operator+(Tcomplex<T3, T4> complex) const
{
	return { this->_reZ + complex.GetReZ(), this->_imZ + complex.GetImZ() };
}

template<class T1, class T2>
template<class T3, class T4>
Tcomplex<Fractions, Fractions> Tcomplex<T1, T2>::operator-(Tcomplex<T3, T4> complex) const
{
	return { this->_reZ - complex.GetReZ(), this->_imZ - complex.GetImZ() };
}

template<class T1, class T2>
template<class T3, class T4>
Tcomplex<Fractions, Fractions> Tcomplex<T1, T2>::operator*(Tcomplex<T3, T4> complex) const
{
	Fractions reZ = this->_reZ * complex.GetReZ() - this->_imZ * complex.GetImZ();
	Fractions imZ = _reZ * complex.GetImZ() + _imZ * complex.GetReZ();

	return { reZ,  imZ };
}

template<class T1, class T2>
template<class T3, class T4>
Tcomplex<Fractions, Fractions> Tcomplex<T1, T2>::operator/(Tcomplex<T3, T4> complex) const
{
	Fractions reZ = (_reZ * complex.GetReZ() + _imZ * complex.GetImZ()) / (complex.GetReZ() * complex.GetReZ() + complex.GetImZ() * complex.GetImZ());
	Fractions imZ = (_imZ * complex.GetReZ() - _reZ * complex.GetImZ()) / (complex.GetReZ() * complex.GetReZ() + complex.GetImZ() * complex.GetImZ());
	return { reZ, imZ };
}


