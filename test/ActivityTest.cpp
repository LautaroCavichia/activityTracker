//
// Created by Lautaro Cavichia on 08/06/23.
//
#include <gtest/gtest.h>
#include "../activity.h"
#include "../TimeUtilities.h"

TEST(ActivityTests, Test1)
{
    Activity activity("Prova1", "08/06/2023 09:45:00", "08/06/2023 10:17:00", "Questa è una prova");

    ASSERT_EQ(activity.getName(), "Prova1");
    ASSERT_EQ(TimeUtilities::timePointToString(activity.getStartTime()), "09:45");
    ASSERT_EQ(TimeUtilities::timePointToString(activity.getEndTime()), "10:17");
    ASSERT_EQ(activity.getDescription(), "Questa è una prova");
}

TEST(ActivityTests, startTimeAfterEndTimeTest)
{
    Activity activity("Prova2", "08/06/2023 09:45:00", "08/06/2023 09:17:00", "Questa è una prova");

    ASSERT_EQ(activity.getName(), "Prova2");
    ASSERT_EQ(TimeUtilities::timePointToString(activity.getStartTime()), "09:45");
    ASSERT_EQ(TimeUtilities::timePointToString(activity.getEndTime()), "09:45");
    ASSERT_EQ(activity.getDescription(), "Questa è una prova");
}

TEST(ActivityTests , startTimeEmptyTest)
{
    Activity activity("Prova3", "", "08/06/2023 23:13:00", "Questa è una prova");

    ASSERT_EQ(activity.getName(), "Prova3");
    ASSERT_EQ(TimeUtilities::timePointToString(activity.getStartTime()), TimeUtilities::timePointToString(chrono::system_clock::now()));
    ASSERT_EQ(TimeUtilities::timePointToString(activity.getEndTime()), TimeUtilities::timePointToString(chrono::system_clock::now()));
    ASSERT_EQ(activity.getDescription(), "Questa è una prova");
}

TEST(ActivityTests , endTimeEmptyTest)
{
    Activity activity("Prova4", "08/06/2023 09:45:00", "", "Questa è una prova");

    ASSERT_EQ(activity.getName(), "Prova4");
    ASSERT_EQ(TimeUtilities::timePointToString(activity.getStartTime()), "09:45");
    ASSERT_EQ(TimeUtilities::timePointToString(activity.getEndTime()), "09:45");
    ASSERT_EQ(activity.getDescription(), "Questa è una prova");
}

TEST(ActivityTests , startTimeAndEndTimeEmptyTest)
{
    Activity activity("Prova5", "", "", "Questa è una prova");

    ASSERT_EQ(activity.getName(), "Prova5");
    ASSERT_EQ(TimeUtilities::timePointToString(activity.getStartTime()), TimeUtilities::timePointToString(chrono::system_clock::now()));
    ASSERT_EQ(TimeUtilities::timePointToString(activity.getEndTime()), TimeUtilities::timePointToString(chrono::system_clock::now()));
    ASSERT_EQ(activity.getDescription(), "Questa è una prova");
}

TEST(ActivityTests , descriptionEmptyTest)
{
    Activity activity("Prova6", "08/06/2023 09:45:00", "08/06/2023 10:17:00", "");

    ASSERT_EQ(activity.getName(), "Prova6");
    ASSERT_EQ(TimeUtilities::timePointToString(activity.getStartTime()), "09:45");
    ASSERT_EQ(TimeUtilities::timePointToString(activity.getEndTime()), "10:17");
    ASSERT_EQ(activity.getDescription(), "");
}
