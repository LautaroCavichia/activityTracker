//
// Created by Lautaro Cavichia on 04/04/23.
//

#ifndef ACTIVITYTRACKER_ACTIVITY_H
#define ACTIVITYTRACKER_ACTIVITY_H

#include <string>
#include <chrono>

using namespace std;

class Activity{
public:
    Activity(const string &nameString, const string &startTimeString, const string &endTimeString, const string &descriptionString);
    string getName() const;
    string getDescription() const;
    void setStartTime(const string &startTimeString);
    void setEndTime(const string &startTimeString, const string &endTimeString);
    const chrono::system_clock::time_point &getStartTime() const;
    const chrono::system_clock::time_point &getEndTime() const;

private:
    string name;
    string description;
    chrono::system_clock::time_point startTime;
    chrono::system_clock::time_point endTime;
};

#endif //ACTIVITYTRACKER_ACTIVITY_H
