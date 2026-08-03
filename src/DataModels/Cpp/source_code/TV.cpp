#include <TV.hpp>
#include <iostream>

float TV::GetScore() const
{
	float value = CountDisplayScore() + IsThereSmartTV() + IsThereHDR();
	return value;
}

TV::TV()
	: Display(), smart_tv(false), HDR(false) {}

TV::TV(const Options& options)
	: Display(options.resolution, options.diagonal), smart_tv(options.smart_tv), HDR(options.HDR) {}

bool TV::IsThereSmartTV() const
{
	return smart_tv;
}

bool TV::IsThereHDR() const
{
	return HDR;
}

void TV::SetSmartTV(bool new_value_of_smart_tv)
{
	smart_tv = new_value_of_smart_tv;
}

void TV::SetHDR(bool new_value_of_HDR)
{
	HDR = new_value_of_HDR;
}

void TV::PrintInfo() const
{
	std::cout << "Характеристики телевизора" << std::endl;
	std::cout << "Разрешение экрана: " << GetResolution() << std::endl;
	std::cout << "Диагональ экрана: " << diagonal << std::endl;
	std::cout << "Поддержка Smart TV: " << (IsThereSmartTV() ? "да" : "нет") << std::endl;
	std::cout << "Поддержка HDR: " << (IsThereHDR() ? "да" : "нет") << std::endl;
}

bool TV::operator==(const TV& another_tv) const
{
	float value1 = GetScore();
	float value2 = another_tv.GetScore();
	return (value1 == value2);
}

bool TV::operator>(const TV& another_tv) const
{
	float value1 = GetScore();
	float value2 = another_tv.GetScore();
	return (value1 > value2);
}

bool TV::operator<(const TV& another_tv) const
{
	float value1 = GetScore();
	float value2 = another_tv.GetScore();
	return (value1 < value2);
}

bool TV::operator>=(const TV& another_tv) const
{
	return(!(*this < another_tv));
}

bool TV::operator<=(const TV& another_tv) const
{
	return (!(*this > another_tv));
}