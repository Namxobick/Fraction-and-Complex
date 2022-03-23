#pragma once
#include <iostream>
#include <cassert>
#include "Fractions.h"

template<class T1, class T2>
class Tcomplex
{
private:
    T1 _reZ;
    T2 _imZ;

	template<class A, class B>
    friend std::ostream& operator << (std::ostream& out, const Tcomplex<A, B>& ñomplex);
	template<class A, class B>
	friend std::istream& operator >> (std::istream& in, Tcomplex<A, B>& complex);
public:
    Tcomplex();
    Tcomplex(T1 reZ);
    Tcomplex(T1 reZ, T2 imZ);
    Tcomplex(const Tcomplex& complex);

	Tcomplex<T1, T2> operator+(const Tcomplex& complex) const;
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
std::ostream& operator<<(std::ostream& out, const Tcomplex<T1, T2>& ñomplex)
{
	if (ñomplex._reZ == 0)
		return out << ñomplex._imZ << "i" << std::endl;

	if (ñomplex._imZ == 0)
		return out << ñomplex._reZ << std::endl;

	if (ñomplex._imZ < 0)
		return out << ñomplex._reZ << " - " << ñomplex._imZ * (-1) << "i" << std::endl;

	return out << ñomplex._reZ << " + " << ñomplex._imZ << "i" << std::endl;
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
Tcomplex<T1, T2> Tcomplex<T1, T2>::operator+(const Tcomplex& complex) const
{
	return { _reZ + complex._reZ, _imZ + complex._imZ };
}
