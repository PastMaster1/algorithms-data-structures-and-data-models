#ifndef LAPTOP_HPP
#define LAPTOP_HPP
#include "DataStructureLaptopOptions.hpp"
#include "DataStructureDisplay.hpp"

class Laptop : Display
{
private:
	int battery_capacity;
	int battery_life;
public:
	Laptop();
	Laptop(LaptopOptions options);
	const char* GetResolution();
	int GetDiagonal();
	bool SetResolution(ResolutionTypes new_resolution);
	bool SetDiagonal(int new_diagonal);
	int GetBatteryCapacity();
	int GetBatteryLife();
	bool SetBatteryCapacity(int new_battery_capacity);
	bool SetBatteryLife(int new_battery_life);
	void PrintInfo() override;
	bool operator==(Laptop& another_laptop);
	bool operator>(Laptop& another_laptop);
	bool operator<(Laptop& another_laptop);
	bool operator>=(Laptop& another_laptop);
	bool operator<=(Laptop& another_laptop);
};

#endif