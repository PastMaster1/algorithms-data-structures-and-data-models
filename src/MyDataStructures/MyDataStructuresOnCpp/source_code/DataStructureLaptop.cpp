#include <DataStructureLaptop.hpp>
#include <iostream>

float Laptop::GetScore() const
{
	float value = CountDisplayScore() + GetBatteryLife();
	return value;
}

Laptop::Laptop() : Display(), battery_capacity(0), battery_life(0) {}

Laptop::Laptop(const Options& options) : Display(options.resolution, options.diagonal)
{
	battery_capacity = options.battery_capacity * (options.battery_capacity > 0);
	battery_life = options.battery_life * (options.battery_life > 0);
}

int Laptop::GetBatteryCapacity() const
{
	return battery_capacity;
}

int Laptop::GetBatteryLife() const
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

void Laptop::PrintInfo() const
{
	std::cout << "Характеристики ноутбука" << std::endl;
	std::cout << "Разрешение экрана: " << GetResolution() << std::endl;
	std::cout << "Диагональ экрана: " << diagonal << std::endl;
	std::cout << "Емкость аккумулятора: " << GetBatteryCapacity() << std::endl;
	std::cout << "Время работы без подзарядки: " << GetBatteryLife() << std::endl;
}

bool Laptop::operator==(const Laptop& another_laptop) const
{
	return (GetScore() == another_laptop.GetScore());
}

bool Laptop::operator>(const Laptop& another_laptop) const
{
	return (GetScore() > another_laptop.GetScore());
}

bool Laptop::operator<(const Laptop& another_laptop) const
{
	return (GetScore() < another_laptop.GetScore());
}

bool Laptop::operator>=(const Laptop& another_laptop) const
{
	return(!(*this < another_laptop));
}

bool Laptop::operator<=(const Laptop& another_laptop) const
{
	return (!(*this > another_laptop));
}