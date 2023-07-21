//
// Created by Lautaro Cavichia on 12/07/23.
//
#include <gtest/gtest.h>
#include "../activity.h"
#include "../activity_log.h"
#include "../TimeUtilities.h"

TEST(logTest, vectorSize1)
{
    ActivityLog log;
    Activity activity("Prova1", "08/06/2023 09:45:00", "08/06/2023 10:17:00", "Questa è una prova");
    log.addActivity(activity);

    ASSERT_EQ(log.searchByDate("08/06/2023").size(), 1);
}

TEST(logTest, vectorSize2)
{
    ActivityLog log;
    Activity activity("Prova1", "08/06/2023 09:45:00", "08/06/2023 10:17:00", "Questa è una prova");
    Activity activity2("Prova2", "08/06/2023 09:45:00", "08/06/2023 10:17:00", "Questa è una prova");
    log.addActivity(activity);
    log.addActivity(activity2);

    ASSERT_EQ(log.searchByDate("08/06/2023").size(), 2);
}

TEST(logTest, emptyVector)
{
    ActivityLog log;

    ASSERT_EQ(log.searchByDate("08/06/2023").size(), 0);
}

TEST(logTest, wrongDate)
{
    ActivityLog log;
    Activity activity("Prova1", "08/06/2023 09:45:00", "08/06/2023 10:17:00", "Questa è una prova");
    log.addActivity(activity);

    ASSERT_EQ(log.searchByDate("08/06/2024").size(), 0);
}

TEST(logTest, multipleDates)
{
    ActivityLog log;
    Activity activity("Prova1", "08/06/2023 09:45:00", "08/06/2023 10:17:00", "Questa è una prova");
    Activity activity2("Prova2", "08/06/2023 09:45:00", "08/06/2023 10:17:00", "Questa è una prova");
    Activity activity3("Prova3", "08/06/2024 09:45:00", "08/06/2024 10:17:00", "Questa è una prova");
    log.addActivity(activity);
    log.addActivity(activity2);
    log.addActivity(activity3);

    ASSERT_EQ(log.searchByDate("08/06/2023").size(), 2);
    ASSERT_EQ(log.searchByDate("08/06/2024").size(), 1);
}

TEST(logTest, removeActivity)
{
    ActivityLog log;
    Activity activity("Prova1", "08/06/2023 09:45:00", "08/06/2023 10:17:00", "Questa è una prova");
    Activity activity2("Prova2", "08/06/2023 09:45:00", "08/06/2023 10:17:00", "Questa è una prova");
    Activity activity3("Prova3", "08/06/2024 09:45:00", "08/06/2024 10:17:00", "Questa è una prova");
    log.addActivity(activity);
    log.addActivity(activity2);
    log.addActivity(activity3);

    ASSERT_EQ(log.searchByDate("08/06/2023").size(), 2);
    ASSERT_EQ(log.searchByDate("08/06/2024").size(), 1);

    log.removeActivity(0);

    ASSERT_EQ(log.searchByDate("08/06/2023").size(), 1);
    ASSERT_EQ(log.searchByDate("08/06/2024").size(), 1);
}

TEST(logTest, removingMoreThanOneActivity)
{
    ActivityLog log;
    Activity activity("Prova1", "08/06/2023 09:45:00", "08/06/2023 10:17:00", "Questa è una prova");
    Activity activity2("Prova2", "08/06/2023 09:45:00", "08/06/2023 10:17:00", "Questa è una prova");
    Activity activity3("Prova3", "08/06/2024 09:45:00", "08/06/2024 10:17:00", "Questa è una prova");
    log.addActivity(activity);
    log.addActivity(activity2);
    log.addActivity(activity3);

    ASSERT_EQ(log.searchByDate("08/06/2023").size(), 2);
    ASSERT_EQ(log.searchByDate("08/06/2024").size(), 1);

    log.removeActivity(0);
    log.removeActivity(0);

    ASSERT_EQ(log.searchByDate("08/06/2023").size(), 0);
    ASSERT_EQ(log.searchByDate("08/06/2024").size(), 1);
}

TEST(logTest, removingNegativeIndex) {
    ActivityLog log;
    Activity activity("Prova1", "08/06/2023 09:45:00", "08/06/2023 10:17:00", "Questa è una prova");
    log.addActivity(activity);

    ASSERT_EQ(log.searchByDate("08/06/2023").size(), 1);

    ASSERT_THROW(log.removeActivity(-1), IndexException);

    ASSERT_EQ(log.searchByDate("08/06/2023").size(), 1);
}

TEST(logTest, removingOutOfBoundIndex){
    ActivityLog log;
    Activity activity("Prova1", "08/06/2023 09:45:00", "08/06/2023 10:17:00", "Questa è una prova");
    log.addActivity(activity);

    ASSERT_EQ(log.searchByDate("08/06/2023").size(), 1);

    ASSERT_THROW(log.removeActivity(19), IndexException);

    ASSERT_EQ(log.searchByDate("08/06/2023").size(), 1);
}

TEST(logTest, searchOutOfRange){
    ActivityLog log;
    Activity activity("Prova1", "08/06/2023 09:45:00", "08/06/2023 10:17:00", "Questa è una prova");
    log.addActivity(activity);

    ASSERT_THROW(log.getActivity(-1), IndexException);
    ASSERT_THROW(log.getActivity(19), IndexException);

}

TEST(logTest, editTest){
    ActivityLog log;
    Activity activity("Prova1", "08/06/2023 09:45:00", "08/06/2023 09:45:00", "Questa è una prova");
    log.addActivity(activity);

    ASSERT_EQ(log.searchByDate("08/06/2023").size(), 1);

    Activity tempActivity("temp", "08/06/2023 10:45:00", "08/06/2023 11:45:00", "temp2");
    log.editActivity(0,tempActivity);

    ASSERT_EQ(log.searchByDate("08/06/2023").size(), 1);
    ASSERT_EQ(log.getActivity(0).getName(), "temp");
    ASSERT_EQ(log.getActivity(0).getDescription(), "temp2");
    ASSERT_EQ(TimeUtilities::timePointToString(log.getActivity(0).getStartTime()), "10:45");
    ASSERT_EQ(TimeUtilities::timePointToString(log.getActivity(0).getEndTime()), "11:45");
}

TEST(logTest, editingMultipleTimesTest){
    ActivityLog log;
    Activity activity("Prova1", "08/06/2023 09:45:00", "08/06/2023 09:45:00", "Questa è una prova");
    log.addActivity(activity);

    ASSERT_EQ(log.searchByDate("08/06/2023").size(), 1);

    Activity tempActivity("temp", "08/06/2023 10:45:00", "08/06/2023 11:45:00", "temp2");
    log.editActivity(0,tempActivity);

    ASSERT_EQ(log.searchByDate("08/06/2023").size(), 1);
    ASSERT_EQ(log.getActivity(0).getName(), "temp");
    ASSERT_EQ(log.getActivity(0).getDescription(), "temp2");
    ASSERT_EQ(TimeUtilities::timePointToString(log.getActivity(0).getStartTime()), "10:45");
    ASSERT_EQ(TimeUtilities::timePointToString(log.getActivity(0).getEndTime()), "11:45");

    Activity tempActivity2("temp4", "08/06/2023 12:45:00", "08/06/2023 13:45:00", "temp5");
    log.editActivity(0,tempActivity2);

    ASSERT_EQ(log.searchByDate("08/06/2023").size(), 1);
    ASSERT_EQ(log.getActivity(0).getName(), "temp4");
    ASSERT_EQ(log.getActivity(0).getDescription(), "temp5");
    ASSERT_EQ(TimeUtilities::timePointToString(log.getActivity(0).getStartTime()), "12:45");
    ASSERT_EQ(TimeUtilities::timePointToString(log.getActivity(0).getEndTime()), "13:45");
}
TEST(logTest, editingNotTheFirstActivity){
    ActivityLog log;
    Activity activity("Prova1", "08/06/2023 09:45:00", "08/06/2023 09:45:00", "Questa è una prova");
    Activity activity2("Prova2", "08/06/2023 09:45:00", "08/06/2023 09:45:00", "Questa è una prova");
    log.addActivity(activity);
    log.addActivity(activity2);

    ASSERT_EQ(log.searchByDate("08/06/2023").size(), 2);

    Activity tempActivity("temp", "08/06/2023 10:45:00", "08/06/2023 11:45:00", "temp2");
    log.editActivity(1,tempActivity);

    ASSERT_EQ(log.searchByDate("08/06/2023").size(), 2);
    ASSERT_EQ(log.getActivity(1).getName(), "temp");
    ASSERT_EQ(log.getActivity(1).getDescription(), "temp2");
    ASSERT_EQ(TimeUtilities::timePointToString(log.getActivity(1).getStartTime()), "10:45");
    ASSERT_EQ(TimeUtilities::timePointToString(log.getActivity(1).getEndTime()), "11:45");
}

TEST(logTest, editingOutOfBoundIndex) {
    ActivityLog log;
    Activity activity("Prova1", "08/06/2023 09:45:00", "08/06/2023 10:17:00", "Questa è una prova");
    log.addActivity(activity);

    ASSERT_EQ(log.searchByDate("08/06/2023").size(), 1);

    ASSERT_THROW(log.editActivity(-1,activity), IndexException);
    ASSERT_THROW(log.editActivity(19,activity),IndexException);

    ASSERT_EQ(log.searchByDate("08/06/2023").size(), 1);
}
