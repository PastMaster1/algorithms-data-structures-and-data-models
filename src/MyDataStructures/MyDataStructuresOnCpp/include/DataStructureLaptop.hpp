#pragma once
#include "DataStructureDisplay.hpp"

class Laptop : public Display
{
private:
	int battery_capacity;
	int battery_life;
	float GetScore() const;
public:
	struct Options 
	{
		ResolutionTypes resolution = NO_INFO;
		int diagonal = 0;
		int battery_capacity = 0;
		int battery_life = 0;
	};
	Laptop();
	Laptop(const Options& options);
	int GetBatteryCapacity() const;
	int GetBatteryLife() const;
	bool SetBatteryCapacity(int new_battery_capacity);
	bool SetBatteryLife(int new_battery_life);
	void PrintInfo() const override;
	bool operator==(const Laptop& another_laptop) const;
	bool operator>(const Laptop& another_laptop) const;
	bool operator<(const Laptop& another_laptop) const;
	bool operator>=(const Laptop& another_laptop) const;
	bool operator<=(const Laptop& another_laptop) const;
};