#ifndef DISPLAY_HPP
#define DISPLAY_HPP
#include "ResolutionTypes.hpp"

class Display
{
protected:
	ResolutionTypes resolution;
	int diagonal;
	Display();
	Display(ResolutionTypes new_resolution, int new_diagonal);
	const char* GetResolution();
	int GetDiagonal();
	bool SetResolution(ResolutionTypes new_resolution);
	bool SetDiagonal(int new_diagonal);
	float CountPPI();
public:
	virtual ~Display() = default;
	virtual void PrintInfo() = 0;
};

#endif