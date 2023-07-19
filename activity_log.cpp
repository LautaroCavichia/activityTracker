//
// Created by Lautaro Cavichia on 04/04/23.
//
#include "activity_log.h"
#include "TimeUtilities.h"

void ActivityLog::addActivity(const Activity &activity) {
    this->activities.push_back(activity);
}

Activity &ActivityLog::getActivity(int index) {
    if (index < this->activities.size() && index >= 0)
        return this->activities[index];
    else throw IndexException();
}

void ActivityLog::removeActivity(int index) {
    if (index < this->activities.size() && index >= 0)
            this->activities.erase(this->activities.begin() + index);
    else throw IndexException();
}

[[nodiscard]] vector<Activity> ActivityLog::searchByDate(const string &dateString) const {
    vector<Activity> activitiesOnDate;
    for (const Activity& activity : this->activities) {
        if (TimeUtilities::dateToString(activity.getStartTime()).find(dateString) != string::npos) {  //npos means not found in the string
            activitiesOnDate.push_back(activity);
        }
    }
    return activitiesOnDate;
}

void ActivityLog::exportActivities(const string &fileName) const {
    ofstream file;
    file.open(fileName);
    if(file.is_open()) {
        if(this->activities.empty())
            file << "No activities to export" << endl;
        else{
        for (const Activity &activity: this->activities) {
            file << activity.getName() + " - " + TimeUtilities::timePointToString(activity.getStartTime()) + " to " +
                    TimeUtilities::timePointToString(activity.getEndTime()) + "\n" << endl;
        }
        file.close();
    }}
    else
        cout << "Unable to open file";

}

void ActivityLog::editActivity(int index, const Activity &activity) {
    if (index < this->activities.size() && index >= 0) {
        this->activities.erase(this->activities.begin() + index);
        this->activities.insert(this->activities.begin() + index, activity);
    }
    else {
        throw IndexException();
    }
}

