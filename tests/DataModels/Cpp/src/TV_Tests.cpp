#include <gtest/gtest.h>
#include <TV.hpp>
#include <UtilityFunctions.hpp>

TEST(TV, DefaultInitialization)
{
	TV tv = TV();
	const char* resolution = tv.GetResolution();
	const char* expected_resolution = "Нет данных";
	EXPECT_EQ(CompareStrings(resolution, expected_resolution), true);
	EXPECT_EQ(tv.GetDiagonal(), 0);
	EXPECT_EQ(tv.IsThereSmartTV(), false);
	EXPECT_EQ(tv.IsThereHDR(), false);
}

TEST(TV, InitializationUsingOptionsForTV)
{
	TV::Options tv_options;
	tv_options.resolution = FullHD;
	tv_options.diagonal = 15;
	tv_options.smart_tv = true;
	tv_options.HDR = true;
	TV tv = TV(tv_options);
	const char* resolution = tv.GetResolution();
	const char* expected_resolution = "1080p(Full HD)";
	EXPECT_EQ(CompareStrings(resolution, expected_resolution), true);
	EXPECT_EQ(tv.GetDiagonal(), 15);
	EXPECT_EQ(tv.IsThereSmartTV(), true);
	EXPECT_EQ(tv.IsThereHDR(), true);
}

TEST(TV, EditOptions)
{
	TV tv = TV();
	EXPECT_EQ(tv.SetResolution(ResolutionTypesCount), false);
	const char* resolution = tv.GetResolution();
	const char* expected_resolution = "Нет данных";
	EXPECT_EQ(CompareStrings(resolution, expected_resolution), true);
	EXPECT_EQ(tv.SetResolution(HD), true);
	resolution = tv.GetResolution();
	expected_resolution = "720p(HD)";
	EXPECT_EQ(CompareStrings(resolution, expected_resolution), true);
	EXPECT_EQ(tv.SetDiagonal(-1), false);
	EXPECT_EQ(tv.GetDiagonal(), 0);
	EXPECT_EQ(tv.SetDiagonal(0), false);
	EXPECT_EQ(tv.GetDiagonal(), 0);
	EXPECT_EQ(tv.SetDiagonal(15), true);
	EXPECT_EQ(tv.GetDiagonal(), 15);
	tv.SetSmartTV(1);
	EXPECT_EQ(tv.IsThereSmartTV(), true);
	tv.SetHDR(1);
	EXPECT_EQ(tv.IsThereHDR(), true);
}

TEST(TV, ComparisonTV)
{
	TV tv1 = TV();
	TV tv2 = TV();
	EXPECT_EQ((tv1 < tv2), false);
	EXPECT_EQ((tv1 <= tv2), true);
	EXPECT_EQ((tv1 == tv2), true);
	EXPECT_EQ((tv1 >= tv2), true);
	EXPECT_EQ((tv1 > tv2), false);
	tv2.SetResolution(QuadHD);
	tv2.SetDiagonal(16);
	tv2.SetSmartTV(1);
	tv2.SetHDR(1);
	EXPECT_EQ((tv1 < tv2), true);
	EXPECT_EQ((tv1 <= tv2), true);
	EXPECT_EQ((tv1 == tv2), false);
	EXPECT_EQ((tv1 >= tv2), false);
	EXPECT_EQ((tv1 > tv2), false);
	tv1.SetResolution(UltraHD);
	tv1.SetDiagonal(15);
	tv1.SetSmartTV(1);
	tv1.SetHDR(1);
	EXPECT_EQ((tv1 < tv2), false);
	EXPECT_EQ((tv1 <= tv2), false);
	EXPECT_EQ((tv1 == tv2), false);
	EXPECT_EQ((tv1 >= tv2), true);
	EXPECT_EQ((tv1 > tv2), true);
}

TEST(TV, GetFunctions)
{
	TV tv = TV();
	const char* resolution = tv.GetResolution();
	const char* expected_resolution = "Нет данных";
	EXPECT_EQ(CompareStrings(resolution, expected_resolution), true);
	EXPECT_EQ(tv.GetDiagonal(), 0);
	EXPECT_EQ(tv.IsThereSmartTV(), false);
	EXPECT_EQ(tv.IsThereHDR(), false);
	tv.SetResolution(HD);
	tv.SetDiagonal(14);
	tv.SetSmartTV(1);
	tv.SetHDR(1);
	resolution = tv.GetResolution();
	expected_resolution = "720p(HD)";
	EXPECT_EQ(CompareStrings(resolution, expected_resolution), true);
	EXPECT_EQ(tv.GetDiagonal(), 14);
	EXPECT_EQ(tv.IsThereSmartTV(), true);
	EXPECT_EQ(tv.IsThereHDR(), true);
}