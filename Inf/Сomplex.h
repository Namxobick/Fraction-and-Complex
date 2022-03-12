#pragma once
#include <iostream>
#include <cassert>
#include "Fractions.h"

class Ñomplex
{
private:
	Fractions _reZ;
	Fractions _imZ;

	friend std::ostream& operator << (std::ostream& out, const Ñomplex& ñomplex);


public:
	Ñomplex();
	Ñomplex(int reZ, int imZ);
	Ñomplex(Fractions reZ, int imZ);
	Ñomplex(int reZ, Fractions imZ);
	Ñomplex(Fractions reZ, Fractions imZ);
	Ñomplex(const Ñomplex& obj);
};

