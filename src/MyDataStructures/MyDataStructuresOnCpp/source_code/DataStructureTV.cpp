#include <DataStructureTV.hpp>
#include <iostream>

TV::TV()
	: Display(), smart_tv(false), HDR(false) {}

TV::TV(OptionsForTV options)
	: Display(options.resolution, options.diagonal), smart_tv(options.smart_tv), HDR(options.HDR) {}

const char* TV::GetResolution()
{
	return Display::GetResolution();
}

int TV::GetDiagonal()
{
	return Display::GetDiagonal();
}

bool TV::SetResolution(ResolutionTypes new_resolution)
{
	return Display::SetResolution(new_resolution);
}

bool TV::SetDiagonal(int new_diagonal)
{
	return Display::SetDiagonal(new_diagonal);
}

bool TV::IsThereSmartTV()
{
	return smart_tv;
}

bool TV::IsThereHDR()
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

void TV::PrintInfo()
{
	std::cout << "Характеристики телевизора" << std::endl;
	std::cout << "Разрешение экрана: " << GetResolution() << std::endl;
	std::cout << "Диагональ экрана: " << diagonal << std::endl;
	std::cout << "Поддержка Smart TV: " << (IsThereSmartTV() ? "да" : "нет") << std::endl;
	std::cout << "Поддержка HDR: " << (IsThereHDR() ? "да" : "нет") << std::endl;
}

bool TV::operator==(TV& another_tv)
{
	float value1 = Display::CountPPI() + IsThereSmartTV() + IsThereHDR();
	float value2 = another_tv.Display::CountPPI() + another_tv.IsThereSmartTV() + another_tv.IsThereHDR();
	return (value1 == value2);
}

bool TV::operator>(TV& another_tv)
{
	float value1 = Display::CountPPI() + IsThereSmartTV() + IsThereHDR();
	float value2 = another_tv.Display::CountPPI() + another_tv.IsThereSmartTV() + another_tv.IsThereHDR();
	return (value1 > value2);
}

bool TV::operator<(TV& another_tv)
{
	float value1 = Display::CountPPI() + IsThereSmartTV() + IsThereHDR();
	float value2 = another_tv.Display::CountPPI() + another_tv.IsThereSmartTV() + another_tv.IsThereHDR();
	return (value1 < value2);
}

bool TV::operator>=(TV& another_tv)
{
	return(!(*this < another_tv));
}

bool TV::operator<=(TV& another_tv)
{
	return (!(*this > another_tv));
}