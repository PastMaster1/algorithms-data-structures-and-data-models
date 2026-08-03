#include <TV.hpp>
#include <TV_Demo.hpp>
#include <iostream>

void TVDemo()
{
	std::cout << "ДЕМОНСТРАЦИЯ ВОЗМОЖНОСТЕЙ КЛАССА TV" << std::endl;
	std::cout << "Объявление первого телевизора без параметров" << std::endl;
	TV tv1 = TV();
	tv1.PrintInfo();
	std::cout << "Объявление второго телевизора с помощью структуры Options" << std::endl;
	TV::Options tv_options;
	tv_options.resolution = FullHD;
	tv_options.diagonal = 43;
	tv_options.smart_tv = true;
	tv_options.HDR = false;
	TV tv2 = TV(tv_options);
	tv2.PrintInfo();
	std::cout << "Сравнение телевизоров: " << std::endl;
	std::cout << "tv1 < tv2 ? " << (tv1 < tv2) << std::endl;
	std::cout << "tv1 <= tv2 ? " << (tv1 <= tv2) << std::endl;
	std::cout << "tv1 == tv2 ? " << (tv1 == tv2) << std::endl;
	std::cout << "tv1 >= tv2 ? " << (tv1 >= tv2) << std::endl;
	std::cout << "tv1 > tv2 ? " << (tv1 > tv2) << std::endl;
	std::cout << "Изменение характеристик первого телевизора" << std::endl;
	tv1.SetResolution(QuadHD);
	tv1.SetDiagonal(65);
	tv1.SetSmartTV(true);
	tv1.SetHDR(true);
	tv1.PrintInfo();
	std::cout << "Сравнение телевизоров: " << std::endl;
	std::cout << "tv1 < tv2 ? " << (tv1 < tv2) << std::endl;
	std::cout << "tv1 <= tv2 ? " << (tv1 <= tv2) << std::endl;
	std::cout << "tv1 == tv2 ? " << (tv1 == tv2) << std::endl;
	std::cout << "tv1 >= tv2 ? " << (tv1 >= tv2) << std::endl;
	std::cout << "tv1 > tv2 ? " << (tv1 > tv2) << std::endl;
}