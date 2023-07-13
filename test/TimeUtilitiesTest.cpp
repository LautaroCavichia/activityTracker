//
// Created by Lautaro Cavichia on 13/07/23.
//
#include <gtest/gtest.h>
#include "../TimeUtilities.h"

TEST(UtilitiesTest, timePointToStringTest)
{

    std::tm timeDefault = {};
    timeDefault.tm_mon = 7;
    timeDefault.tm_hour = 9;
    timeDefault.tm_min = 45;

    std::time_t time = std::mktime(&timeDefault);
    auto timePoint = std::chrono::system_clock::from_time_t(time);
    ASSERT_EQ(TimeUtilities::timePointToString(timePoint), "09:45");
}
TEST(UtilitiesTest, stringToTimePointTest)
{
    chrono::time_point<chrono::system_clock> timePoint = TimeUtilities::stringToTimePoint("08/06/2023 09:45:00");
    ASSERT_EQ(TimeUtilities::timePointToString(timePoint), "09:45");
}

TEST(UtilitiesTest, isEndAfterStartTest)
{
    ASSERT_TRUE(TimeUtilities::isEndAfterStart("08/06/2023 09:45:00", "08/06/2023 10:17:00"));
    ASSERT_FALSE(TimeUtilities::isEndAfterStart("08/06/2023 09:45:00", "08/06/2023 09:17:00"));
    ASSERT_FALSE(TimeUtilities::isEndAfterStart("08/06/2023 09:45:00", ""));
    ASSERT_FALSE(TimeUtilities::isEndAfterStart("", "08/06/2023 09:45:00"));
    ASSERT_TRUE(TimeUtilities::isEndAfterStart("", ""));
}

TEST(UtilitiesTest, dateToStringTest)
{
    std::tm timeDefault = {};
    timeDefault.tm_mon = 7;
    timeDefault.tm_mday = 8;
    timeDefault.tm_year = 123;

    std::time_t time = std::mktime(&timeDefault);
    auto timePoint = std::chrono::system_clock::from_time_t(time);
    ASSERT_EQ(TimeUtilities::dateToString(timePoint), "08/08/2023");
}