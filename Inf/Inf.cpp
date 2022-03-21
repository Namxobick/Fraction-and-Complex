#include <iostream>
#include "Fractions.h"
#include "Сomplex.h"

int main()
{
	Fractions fr1(7, 4), fr2(3, 5), fr3(7, 4);
	Complex cm1, cm2(-6, 7);
	Complex Test = 5;
	Complex Test2 = Test + (Complex)5;
	Complex Test3 = Test + (Complex)5.5;
	Complex Test4 = Test * Test;
	//std::cout << fr1;
	std::cout << Test4;

	

}

