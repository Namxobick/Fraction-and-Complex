#include "�omplex.h"

�omplex::�omplex()
{
	_reZ = NULL;
	_imZ = NULL;
}

�omplex::�omplex(int reZ, int imZ)
{
	_reZ = reZ;
	_imZ = imZ;
}

�omplex::�omplex(Fractions reZ, int imZ)
{
	_reZ = reZ;
	_imZ = imZ;
}

�omplex::�omplex(int reZ, Fractions imZ)
{
	_reZ = reZ;
	_imZ = imZ;
}

�omplex::�omplex(Fractions reZ, Fractions imZ)
{
	_reZ = reZ;
	_imZ = imZ;
}

�omplex::�omplex(const �omplex& obj)
{
	_reZ = obj._reZ;
	_imZ = obj._imZ;
}

std::ostream& operator<<(std::ostream& out, const �omplex& �omplex)
{
	if (�omplex._reZ == 0)
		return out << �omplex._imZ << "i" << std::endl;

	if (�omplex._imZ == 0)
		return out << �omplex._reZ << std::endl;

	return out << �omplex._reZ << " + " << �omplex._imZ << "i" << std::endl;
}