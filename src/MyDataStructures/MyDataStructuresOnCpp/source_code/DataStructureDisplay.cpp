#include <iostream>
#include <DataStructureDisplay.hpp>

Display::Display(ResolutionTypes new_resolution, int new_diagonal)
{
	if (int(new_resolution) < 0 || int(new_resolution) >= int(ResolutionTypesCount))
	{
		resolution = NO_INFO;
	}
	else
	{
		resolution = new_resolution;
	}
	diagonal = (new_diagonal >= 0) * new_diagonal;
}

Display::Display() : resolution(NO_INFO), diagonal(0) {}

const char* Display::GetResolution()
{
	const char* res;
	switch (resolution)
	{
		case HD: res = "720p(HD)"; break;
		case FullHD: res = "1080p(Full HD)"; break;
		case QuadHD: res = "2K(Quad HD)"; break;
		case UltraHD: res = "4K(Ultra HD)"; break;
		default: res = "Нет данных";
	}
	return res;
}

int Display::GetDiagonal()
{
	return diagonal;
}

bool Display::SetResolution(ResolutionTypes new_resolution)
{
	if (int(new_resolution) < 0 || int(new_resolution) >= int(ResolutionTypesCount))
	{
		return false;
	}
	resolution = new_resolution;
	return true;
}

bool Display::SetDiagonal(int new_diagonal)
{
	if (new_diagonal <= 0)
	{
		return false;
	}
	diagonal = new_diagonal;
	return true;
}

float Display::CountPPI()
{
	float res = 0;
	if (diagonal != 0)
	{
		res = float(resolution) / float(diagonal);
	}
	return res;
}