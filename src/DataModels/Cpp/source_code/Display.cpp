#include <iostream>
#include <cmath>
#include <Display.hpp>

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

const char* Display::GetResolution() const
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

int Display::GetDiagonal() const
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

float Display::CountDisplayScore() const
{
	float res = 0;
	if (diagonal != 0)
	{
		float width, height;
		switch (resolution)
		{
			case HD: { width = 1280; height = 720; break; }
			case FullHD: { width = 1920; height = 1080; break; }
			case QuadHD: { width = 2560; height = 1440; break; }
			case UltraHD: { width = 3840; height = 2160; break; }
			default: { width = 0; height = 0; break; }
		}
		res = sqrt(pow(width, 2) + pow(height, 2)) / diagonal;
	}
	return res;
}