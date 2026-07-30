#include <gtest/gtest.h>
#include <DataStructureLaptopOptions.hpp>

TEST(LAPTOP_OPTIONS, DefaultInitialization)
{
	LaptopOptions laptop_options = LaptopOptions();
	EXPECT_EQ(laptop_options.resolution, NO_INFO);
	EXPECT_EQ(laptop_options.diagonal, 0);
	EXPECT_EQ(laptop_options.battery_capacity, 0);
	EXPECT_EQ(laptop_options.battery_life, 0);
}