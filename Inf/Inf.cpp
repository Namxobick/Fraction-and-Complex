#include <iostream>
#include "Fractions.h"
#include "Сomplex.h"

int main()
{
	Fractions fr1(1, 2), fr2(3, 5), fr3;
	Сomplex cm1(fr2, fr1);
	std::cout << cm1;
	

}

