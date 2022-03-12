#include "Ñomplex.h"

Ñomplex::Ñomplex()
{
	_reZ = NULL;
	_imZ = NULL;
}

Ñomplex::Ñomplex(int reZ, int imZ)
{
	_reZ = reZ;
	_imZ = imZ;
}

Ñomplex::Ñomplex(Fractions reZ, int imZ)
{
	_reZ = reZ;
	_imZ = imZ;
}

Ñomplex::Ñomplex(int reZ, Fractions imZ)
{
	_reZ = reZ;
	_imZ = imZ;
}

Ñomplex::Ñomplex(Fractions reZ, Fractions imZ)
{
	_reZ = reZ;
	_imZ = imZ;
}

Ñomplex::Ñomplex(const Ñomplex& obj)
{
	_reZ = obj._reZ;
	_imZ = obj._imZ;
}

std::ostream& operator<<(std::ostream& out, const Ñomplex& ñomplex)
{
	if (ñomplex._reZ == 0)
		return out << ñomplex._imZ << "i" << std::endl;

	if (ñomplex._imZ == 0)
		return out << ñomplex._reZ << std::endl;

	return out << ñomplex._reZ << " + " << ñomplex._imZ << "i" << std::endl;
}