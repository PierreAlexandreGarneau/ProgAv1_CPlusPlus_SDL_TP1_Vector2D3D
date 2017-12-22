#include <iostream>
#include <math.h>

#include "Vector2D.h"

void main()
{
	float f = 0.0f;
	for (int i = 0; i < 10; i++)
	{
		f += 0.1f;
	}

	if (abs(1.0f - f) <= EPSILON)
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << "Failed" << std::endl;
	}

	std::cout << abs(1.0f - f) << std::endl;
}