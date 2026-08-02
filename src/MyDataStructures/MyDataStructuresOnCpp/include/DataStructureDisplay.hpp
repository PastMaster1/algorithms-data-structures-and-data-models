#pragma once
#include "ResolutionTypes.hpp"

class Display
{
protected:
	ResolutionTypes resolution;
	int diagonal;
	Display();
	Display(ResolutionTypes new_resolution, int new_diagonal);
	float CountDisplayScore() const;
public:
	virtual ~Display() = default;
	virtual void PrintInfo() const = 0;
	const char* GetResolution() const;
	int GetDiagonal() const;
	bool SetResolution(ResolutionTypes new_resolution);
	bool SetDiagonal(int new_diagonal);
};