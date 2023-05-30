//
// Created by Lautaro Cavichia on 04/04/23.
//

#include "activity.h"
#include "TimeUtilities.h"

Activity::Activity(const string &name, const string &startTimeString, const string &endTimeString, const string &description):
name(name), description(description){
    setStartTime(startTimeString); // Set the start time checking if it's valid
    setEndTime(startTimeString,endTimeString);     // Set the end time checking if it's valid
}

string Activity::getName() const {
    return this->name;
}

string Activity::getDescription() const {
    return this->description;
}

void Activity::setStartTime(const string &startTimeString) {
    if (!startTimeString.empty())
        this->startTime = TimeUtilities::stringToTimePoint(startTimeString);
    else {
        this->startTime = chrono::system_clock::now();
    }
}

void Activity::setEndTime(const string &startTimeString, const string &endTimeString) {
    // check if the end time is valid and greater than the start time
    if(TimeUtilities::isEndAfterStart(startTimeString, endTimeString))
        this->endTime = TimeUtilities::stringToTimePoint(endTimeString);
    else {
        this->endTime = this->startTime;
    }
}

const chrono::system_clock::time_point &Activity::getStartTime() const {
    return startTime;
}
const chrono::system_clock::time_point &Activity::getEndTime() const {
    return endTime;
}



