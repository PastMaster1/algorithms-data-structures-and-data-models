#include <iostream>
#include <Laptop_Demo.hpp>
#include <TV_Demo.hpp>

void PrintHelp()
{
	std::cout << "0 - Выход" << std::endl;
	std::cout << "1 - Повтор команд" << std::endl;
	std::cout << "2 - DataStructureLaptop.cpp" << std::endl;
	std::cout << "3 - DataStructureTV.cpp" << std::endl;
}

int main()
{
	setlocale(LC_ALL, ".UTF8");
	int error_code = 0;
	PrintHelp();
	std::cout << std::endl;
	int user_choice;
	std::cout << "Выберите какую программу запустить: ";
	std::cin >> user_choice;
	while (user_choice != 0)
	{
		switch (user_choice)
		{
			case 1: PrintHelp(); break;
			case 2: LaptopDemo(); break;
			case 3: TVDemo(); break;
			default: std::cout << "Некорректный ввод!" << std::endl;
		}
		std::cout << std::endl;
		std::cout << "Выберите какую программу запустить: ";
		std::cin >> user_choice;
	}
	return error_code;
}