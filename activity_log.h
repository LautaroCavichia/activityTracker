//
// Created by Lautaro Cavichia on 04/04/23.
//

#ifndef ACTIVITYTRACKER_ACTIVITY_LOG_H
#define ACTIVITYTRACKER_ACTIVITY_LOG_H

#include <vector>
#include <string>
#include "activity.h"

using namespace std;

class ActivityLog{
public:
    ActivityLog(): activities(vector<Activity>()){}
    void addActivity(const Activity &activity);
    void removeActivity(int index);
    Activity &getActivity(int index); // Returns a reference to the activity at the given index
    [[nodiscard]] vector<Activity> searchByDate(const string &dateString)const; // Returns a vector of activities that match the date (Project requirement)

    //TODO: Add sorting methods and log to file methods

private:
    vector<Activity> activities;
};



#endif //ACTIVITYTRACKER_ACTIVITY_LOG_H
