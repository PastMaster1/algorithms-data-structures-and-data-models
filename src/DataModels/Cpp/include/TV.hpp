#pragma once
#include "Display.hpp"

class TV : public Display
{
private:
	bool smart_tv;
	bool HDR;
	float GetScore() const;
public:
	struct Options
	{
		ResolutionTypes resolution;
		int diagonal;
		bool smart_tv;
		bool HDR;
	};
	TV();
	TV(const Options& options);
	bool IsThereSmartTV() const;
	bool IsThereHDR() const;
	void SetSmartTV(bool new_value_of_smart_tv);
	void SetHDR(bool new_value_of_HDR);
	void PrintInfo() const override;
	bool operator==(const TV& another_tv) const;
	bool operator>(const TV& another_tv) const;
	bool operator<(const TV& another_tv) const;
	bool operator>=(const TV& another_tv) const;
	bool operator<=(const TV& another_tv) const;
};