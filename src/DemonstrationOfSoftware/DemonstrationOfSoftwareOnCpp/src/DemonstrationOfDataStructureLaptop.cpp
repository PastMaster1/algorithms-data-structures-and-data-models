#include <DataStructureLaptop.hpp>
#include <DemonstrationOfDataStructureLaptop.hpp>
#include <iostream>

void LaptopDemo()
{
	std::cout << "ДЕМОНСТРАЦИЯ ВОЗМОЖНОСТЕЙ КЛАССА Laptop" << std::endl;
	std::cout << "Объявление первого ноутбука без параметров" << std::endl;
	Laptop laptop1 = Laptop();
	laptop1.PrintInfo();
	std::cout << "Объявление второго ноутбука с помощью структуры Options" << std::endl;
	Laptop::Options laptop_options;
	laptop_options.resolution = FullHD;
	laptop_options.diagonal = 15;
	laptop_options.battery_capacity = 5000;
	laptop_options.battery_life = 10;
	Laptop laptop2 = Laptop(laptop_options);
	laptop2.PrintInfo();
	std::cout << "Сравнение ноутбуков: " << std::endl;
	std::cout << "laptop1 < laptop2 ? " << (laptop1 < laptop2) << std::endl;
	std::cout << "laptop1 <= laptop2 ? " << (laptop1 <= laptop2) << std::endl;
	std::cout << "laptop1 == laptop2 ? " << (laptop1 == laptop2) << std::endl;
	std::cout << "laptop1 >= laptop2 ? " << (laptop1 >= laptop2) << std::endl;
	std::cout << "laptop1 > laptop2 ? " << (laptop1 > laptop2) << std::endl;
	std::cout << "Изменение характеристик первого ноутбука" << std::endl;
	laptop1.SetResolution(UltraHD);
	laptop1.SetDiagonal(16);
	laptop1.SetBatteryCapacity(6000);
	laptop1.SetBatteryLife(12);
	laptop1.PrintInfo();
	std::cout << "Сравнение ноутбуков: " << std::endl;
	std::cout << "laptop1 < laptop2 ? " << (laptop1 < laptop2) << std::endl;
	std::cout << "laptop1 <= laptop2 ? " << (laptop1 <= laptop2) << std::endl;
	std::cout << "laptop1 == laptop2 ? " << (laptop1 == laptop2) << std::endl;
	std::cout << "laptop1 >= laptop2 ? " << (laptop1 >= laptop2) << std::endl;
	std::cout << "laptop1 > laptop2 ? " << (laptop1 > laptop2) << std::endl;
}