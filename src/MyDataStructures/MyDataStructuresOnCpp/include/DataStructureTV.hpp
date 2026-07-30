#ifndef TV_HPP
#define TV_HPP
#include "DataStructureDisplay.hpp"
#include "DataStructureOptionsForTV.hpp"

class TV : Display
{
private:
	bool smart_tv;
	bool HDR;
public:
	TV();
	TV(OptionsForTV options);
	const char* GetResolution();
	int GetDiagonal();
	bool SetResolution(ResolutionTypes new_resolution);
	bool SetDiagonal(int new_diagonal);
	bool IsThereSmartTV();
	bool IsThereHDR();
	void SetSmartTV(bool new_value_of_smart_tv);
	void SetHDR(bool new_value_of_HDR);
	void PrintInfo() override;
	bool operator==(TV& another_tv);
	bool operator>(TV& another_tv);
	bool operator<(TV& another_tv);
	bool operator>=(TV& another_tv);
	bool operator<=(TV& another_tv);
};

#endif