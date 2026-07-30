#include <DataStructureLaptop.hpp>
#include <iostream>

Laptop::Laptop() : Display(), battery_capacity(0), battery_life(0) {}

Laptop::Laptop(LaptopOptions options) : Display(options.resolution, options.diagonal)
{
	battery_capacity = options.battery_capacity * (options.battery_capacity > 0);
	battery_life = options.battery_life * (options.battery_life > 0);
}

const char* Laptop::GetResolution()
{
	return Display::GetResolution();
}

int Laptop::GetDiagonal()
{
	return Display::GetDiagonal();
}

bool Laptop::SetResolution(ResolutionTypes new_resolution)
{
	return Display::SetResolution(new_resolution);
}

bool Laptop::SetDiagonal(int new_diagonal)
{
	return Display::SetDiagonal(new_diagonal);
}

int Laptop::GetBatteryCapacity()
{
	return battery_capacity;
}

int Laptop::GetBatteryLife()
{
	return battery_life;
}

bool Laptop::SetBatteryCapacity(int new_battery_capacity)
{
	if (new_battery_capacity <= 0)
	{
		return false;
	}
	battery_capacity = new_battery_capacity;
	return true;
}

bool Laptop::SetBatteryLife(int new_battery_life)
{
	if (new_battery_life <= 0)
	{
		return false;
	}
	battery_life = new_battery_life;
	return true;
}

void Laptop::PrintInfo()
{
	std::cout << "Характеристики ноутбука" << std::endl;
	std::cout << "Разрешение экрана: " << GetResolution() << std::endl;
	std::cout << "Диагональ экрана: " << diagonal << std::endl;
	std::cout << "Емкость аккумулятора: " << GetBatteryCapacity() << std::endl;
	std::cout << "Время работы без подзарядки: " << GetBatteryLife() << std::endl;
}

bool Laptop::operator==(Laptop& another_laptop)
{
	float value1 = Display::CountPPI() + GetBatteryLife();
	float value2 = another_laptop.Display::CountPPI() + another_laptop.GetBatteryLife();
	return (value1 == value2);
}

bool Laptop::operator>(Laptop& another_laptop)
{
	float value1 = Display::CountPPI() + GetBatteryLife();
	float value2 = another_laptop.Display::CountPPI() + another_laptop.GetBatteryLife();
	return (value1 > value2);
}

bool Laptop::operator<(Laptop& another_laptop)
{
	float value1 = Display::CountPPI() + GetBatteryLife();
	float value2 = another_laptop.Display::CountPPI() + another_laptop.GetBatteryLife();
	return (value1 < value2);
}

bool Laptop::operator>=(Laptop& another_laptop)
{
	return(!(*this < another_laptop));
}

bool Laptop::operator<=(Laptop& another_laptop)
{
	return (!(*this > another_laptop));
}