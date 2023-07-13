//
// Created by Lautaro Cavichia on 04/04/23.
//
#include "activity_log.h"
#include "TimeUtilities.h"

void ActivityLog::addActivity(const Activity &activity) {
    this->activities.push_back(activity);
}

Activity &ActivityLog::getActivity(int index) {
    return this->activities[index];
}

void ActivityLog::removeActivity(int index) {
    if(index < this->activities.size() && index >= 0)
    this->activities.erase(this->activities.begin() + index);
    else throw IndexException();
}

[[nodiscard]] vector<Activity> ActivityLog::searchByDate(const string &dateString) const {
    vector<Activity> activitiesOnDate;
    for (const Activity& activity : this->activities) { // For each activity in the activities vector
        if (TimeUtilities::dateToString(activity.getStartTime()).find(dateString) != string::npos) {  // If the date string is found in the activity date string. npos means not found in the string
            activitiesOnDate.push_back(activity); // Add the activity to the vector
        }
    }
    return activitiesOnDate; //Return a reference to the vector? is it possible?
}