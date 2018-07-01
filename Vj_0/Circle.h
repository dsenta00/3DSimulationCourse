#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

#define PI 3.1415926535897

namespace abc
{
	class Circle
	{
	private:
		float _radius;

	public:
		Circle(float r = 0.0f)
        : _radius{ r }
		{
		}

		~Circle(void)
		{
		}

		virtual float Area(void)
		{
			return ( pow(_radius, 2.0f) * PI );
		}

		virtual std::string ToString(void)
		{
			std::stringstream ss;
			ss << this->_radius;
			return ss.str();
		}
	};

	void f(Circle* const c)
	{
		float buffer = c->Area();
		std::cout << buffer << std::endl;
	}

	Circle* g(const float r = 0.0f)
	{
		Circle *target = new Circle(r);
		return target;
	}
}
