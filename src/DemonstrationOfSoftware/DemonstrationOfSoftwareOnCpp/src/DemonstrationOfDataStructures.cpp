#include <iostream>
#include <DemonstrationOfDataStructureLaptop.hpp>
#include <DemonstrationOfDataStructureTV.hpp>

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
		if (user_choice == 1)
		{
			PrintHelp();
		}
		else if (user_choice == 2)
		{
			LaptopDemo();
		}
		else if (user_choice == 3)
		{
			TVDemo();
		}
		else
		{
			std::cout << "Некорректный ввод!" << std::endl;
		}
		std::cout << std::endl;
		std::cout << "Выберите какую программу запустить: ";
		std::cin >> user_choice;
	}
	return error_code;
}