#include "Circle.h"

#include <iostream>

#define EXIT_SUCCESS 0

abc::Circle a{ 1.0f };

auto main(void) -> int
{
	std::cout << "Area of obj a is " << a.Area() << std::endl;

	float radius{ 0.0f };
	std::cout << "Please enter the radius:" << std::endl;
	std::cin >> radius;

	abc::Circle b{ radius };
	std::cout << "Area of obj b is " << b.Area() << std::endl;
	
	// should be allocated using new operator
	abc::Circle c{ radius };
	abc::Circle* const p = &c;
	std::cout << "Area of obj that p points to is " << p->Area() << std::endl;
	//delete p
	
	abc::Circle d{ radius };
	abc::f(&d);

	abc::Circle *q = abc::g(radius);
	std::cout << "Area of obj that q points to is " << q->Area() << std::endl;
	delete q;

	return EXIT_SUCCESS;
}
