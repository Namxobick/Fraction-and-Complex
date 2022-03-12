#pragma once
#include <iostream>
#include <cassert>
#include "Fractions.h"

class �omplex
{
private:
	Fractions _reZ;
	Fractions _imZ;

	friend std::ostream& operator << (std::ostream& out, const �omplex& �omplex);


public:
	�omplex();
	�omplex(int reZ, int imZ);
	�omplex(Fractions reZ, int imZ);
	�omplex(int reZ, Fractions imZ);
	�omplex(Fractions reZ, Fractions imZ);
	�omplex(const �omplex& obj);
};

