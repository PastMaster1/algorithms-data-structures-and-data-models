#ifndef OPTIONS_FOR_TV_HPP
#define OPTIONS_FOR_TV_HPP
#include "ResolutionTypes.hpp"

class OptionsForTV
{
public:
	ResolutionTypes resolution;
	int diagonal;
	bool smart_tv;
	bool HDR;
	OptionsForTV();
};

#endif