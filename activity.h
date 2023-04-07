//
// Created by Lautaro Cavichia on 04/04/23.
//

#ifndef ACTIVITYTRACKER_ACTIVITY_H
#define ACTIVITYTRACKER_ACTIVITY_H

#include <string>
#include <ctime>     // For time_t
#include <sstream>  // For string stream
#include <chrono>   // For time_point
#include <iomanip> // For get_time


using namespace std;

class Activity{
public:
    Activity(const string &nameString, const string &startTimeString, const string &endTimeString, const string &descriptionString);
    void setName(const string &nameString);
    string getName() const;
    void setDescription(const string &descriptionString);
    string getDescription() const;
    int getDuration() const;
    void setStartTime(const string &startTimeString);
    string getStartTimeString(bool onlyTime = true) const;
    void setEndTime(const string &startTimeString, const string &endTimeString);
    string getEndTimeString(bool onlyTime = true) const;
    string getDateString() const;

private:
    string description;
    string name;
    long duration;
    chrono::system_clock::time_point startTime; // Time point of the start of the activity
    chrono::system_clock::time_point endTime;   // Time point of the end of the activity

    static chrono::system_clock::time_point stringToTimePoint(const string &timeString);  // Converts a string to a time point
    static bool isEndAfterStart(const string &startTimeString, const string &endTimeString) ;
};

#endif //ACTIVITYTRACKER_ACTIVITY_H
