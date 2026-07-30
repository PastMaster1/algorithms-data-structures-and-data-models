#include <gtest/gtest.h>
#include <DataStructureOptionsForTV.hpp>

TEST(OPTIONS_FOR_TV, DefaultInitialization)
{
	OptionsForTV tv_options = OptionsForTV();
	EXPECT_EQ(tv_options.resolution, NO_INFO);
	EXPECT_EQ(tv_options.diagonal, 0);
	EXPECT_EQ(tv_options.smart_tv, false);
	EXPECT_EQ(tv_options.HDR, false);
}