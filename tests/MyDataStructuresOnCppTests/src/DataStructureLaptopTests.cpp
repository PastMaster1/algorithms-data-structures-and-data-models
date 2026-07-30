#include <gtest/gtest.h>
#include <DataStructureLaptop.hpp>
#include <UtilityFunctions.hpp>

TEST(LAPTOP, DefaultInitialization)
{
	Laptop laptop = Laptop();
	const char* resolution = laptop.GetResolution();
	const char* expected_resolution = "Нет данных";
	EXPECT_EQ(CompareStrings(resolution, expected_resolution), true);
	EXPECT_EQ(laptop.GetDiagonal(), 0);
	EXPECT_EQ(laptop.GetBatteryCapacity(), 0);
	EXPECT_EQ(laptop.GetBatteryLife(), 0);
}

TEST(LAPTOP, InitializationUsingLaptopOptions)
{
	LaptopOptions laptop_options = LaptopOptions();
	laptop_options.resolution = FullHD;
	laptop_options.diagonal = 15;
	laptop_options.battery_capacity = 5000;
	laptop_options.battery_life = 10;
	Laptop laptop = Laptop(laptop_options);
	const char* resolution = laptop.GetResolution();
	const char* expected_resolution = "1080p(Full HD)";
	EXPECT_EQ(CompareStrings(resolution, expected_resolution), true);
	EXPECT_EQ(laptop.GetDiagonal(), 15);
	EXPECT_EQ(laptop.GetBatteryCapacity(), 5000);
	EXPECT_EQ(laptop.GetBatteryLife(), 10);
}

TEST(LAPTOP, EditOptions)
{
	Laptop laptop = Laptop();
	EXPECT_EQ(laptop.SetResolution(ResolutionTypesCount), false);
	const char* resolution = laptop.GetResolution();
	const char* expected_resolution = "Нет данных";
	EXPECT_EQ(CompareStrings(resolution, expected_resolution), true);
	EXPECT_EQ(laptop.SetResolution(HD), true);
	resolution = laptop.GetResolution();
	expected_resolution = "720p(HD)";
	EXPECT_EQ(CompareStrings(resolution, expected_resolution), true);
	EXPECT_EQ(laptop.SetDiagonal(-1), false);
	EXPECT_EQ(laptop.GetDiagonal(), 0);
	EXPECT_EQ(laptop.SetDiagonal(0), false);
	EXPECT_EQ(laptop.GetDiagonal(), 0);
	EXPECT_EQ(laptop.SetDiagonal(15), true);
	EXPECT_EQ(laptop.GetDiagonal(), 15);
	EXPECT_EQ(laptop.SetBatteryCapacity(-1), false);
	EXPECT_EQ(laptop.GetBatteryCapacity(), 0);
	EXPECT_EQ(laptop.SetBatteryCapacity(0), false);
	EXPECT_EQ(laptop.GetBatteryCapacity(), 0);
	EXPECT_EQ(laptop.SetBatteryCapacity(5000), true);
	EXPECT_EQ(laptop.GetBatteryCapacity(), 5000);
	EXPECT_EQ(laptop.SetBatteryLife(-1), false);
	EXPECT_EQ(laptop.GetBatteryLife(), 0);
	EXPECT_EQ(laptop.SetBatteryLife(0), false);
	EXPECT_EQ(laptop.GetBatteryLife(), 0);
	EXPECT_EQ(laptop.SetBatteryLife(10), true);
	EXPECT_EQ(laptop.GetBatteryLife(), 10);
}

TEST(LAPTOP, LaptopComparison)
{
	Laptop laptop1 = Laptop();
	Laptop laptop2 = Laptop();
	EXPECT_EQ((laptop1 < laptop2), false);
	EXPECT_EQ((laptop1 <= laptop2), true);
	EXPECT_EQ((laptop1 == laptop2), true);
	EXPECT_EQ((laptop1 >= laptop2), true);
	EXPECT_EQ((laptop1 > laptop2), false);
	laptop2.SetResolution(QuadHD);
	laptop2.SetDiagonal(16);
	laptop2.SetBatteryCapacity(6000);
	laptop2.SetBatteryLife(7);
	EXPECT_EQ((laptop1 < laptop2), true);
	EXPECT_EQ((laptop1 <= laptop2), true);
	EXPECT_EQ((laptop1 == laptop2), false);
	EXPECT_EQ((laptop1 >= laptop2), false);
	EXPECT_EQ((laptop1 > laptop2), false);
	laptop1.SetResolution(UltraHD);
	laptop1.SetDiagonal(15);
	laptop1.SetBatteryCapacity(6000);
	laptop1.SetBatteryLife(10);
	EXPECT_EQ((laptop1 < laptop2), false);
	EXPECT_EQ((laptop1 <= laptop2), false);
	EXPECT_EQ((laptop1 == laptop2), false);
	EXPECT_EQ((laptop1 >= laptop2), true);
	EXPECT_EQ((laptop1 > laptop2), true);
}

TEST(LAPTOP, GetFunctions)
{
	Laptop laptop = Laptop();
	const char* resolution = laptop.GetResolution();
	const char* expected_resolution = "Нет данных";
	EXPECT_EQ(CompareStrings(resolution, expected_resolution), true);
	EXPECT_EQ(laptop.GetDiagonal(), 0);
	EXPECT_EQ(laptop.GetBatteryCapacity(), 0);
	EXPECT_EQ(laptop.GetBatteryLife(), 0);
	laptop.SetResolution(HD);
	laptop.SetDiagonal(14);
	laptop.SetBatteryCapacity(5000);
	laptop.SetBatteryLife(10);
	resolution = laptop.GetResolution();
	expected_resolution = "720p(HD)";
	EXPECT_EQ(CompareStrings(resolution, expected_resolution), true);
	EXPECT_EQ(laptop.GetDiagonal(), 14);
	EXPECT_EQ(laptop.GetBatteryCapacity(), 5000);
	EXPECT_EQ(laptop.GetBatteryLife(), 10);
}