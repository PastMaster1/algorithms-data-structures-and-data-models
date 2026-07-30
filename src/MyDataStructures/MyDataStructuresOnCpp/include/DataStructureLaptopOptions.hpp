#ifndef LAPTOP_OPTIONS_HPP
#define LAPTOP_OPTIONS_HPP
#include "ResolutionTypes.hpp"

class LaptopOptions
{
public:
	ResolutionTypes resolution;
	int diagonal;
	int battery_capacity;
	int battery_life;
	LaptopOptions();
};

#endif