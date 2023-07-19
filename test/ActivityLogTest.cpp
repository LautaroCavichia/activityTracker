//
// Created by Lautaro Cavichia on 12/07/23.
//
#include <gtest/gtest.h>
#include "../activity.h"
#include "../activity_log.h"

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