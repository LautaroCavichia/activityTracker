//
// Created by Lautaro Cavichia on 04/04/23.
//

#include "activity.h"


Activity::Activity(const string &name, const string &startTimeString, const string &endTimeString, const string &description):
name(name), description(description){
    setStartTime(startTimeString); // Set the start time checking if it's valid
    setEndTime(endTimeString);     // Set the end time checking if it's valid
    duration = chrono::duration_cast<chrono::minutes>(endTime - startTime).count(); // Calculate the duration of the activity in minutes
}

void Activity::setName(const string &nameString) {
    this->name = nameString;
}

string Activity::getName() const {
    return this->name;
}

void Activity::setDescription(const string &descriptionString) {
    this->description = descriptionString;
}

string Activity::getDescription() const {
    return this->description;
}

int Activity::getDuration() const {
    return this->duration;
}

string Activity::getStartTimeString() {
    time_t startTime_t = chrono::system_clock::to_time_t(this->startTime);
    stringstream ss;
    ss << ctime(&startTime_t);
    return ss.str();
}

string Activity::getEndTimeString() {
    time_t endTime_t = chrono::system_clock::to_time_t(this->endTime); // Convert time_point to time_t
    stringstream ss; // Create a string stream
    ss << ctime(&endTime_t); // Convert time_t to string
    return ss.str();
}

void Activity::setStartTime(const string &startTimeString) {
    if (!startTimeString.empty())
        this->startTime = stringToTimePoint(startTimeString);
    else {
        this->startTime = chrono::system_clock::now();
        //TODO: Add a message to the user saying that the start time is invalid and was set to the current time
    }
}

void Activity::setEndTime(const string &endTimeString) {
    // check if the end time is valid and greater than the start time
    if(endTimeString.empty() || stringToTimePoint(endTimeString) < this->startTime)
        this->endTime = stringToTimePoint(endTimeString);
    else {
        //TODO: Add a message to the user saying that the end time is invalid
    }
}

chrono::system_clock::time_point Activity::stringToTimePoint(const string &timeString) {
    stringstream ss(timeString); // Convert string to string stream
    tm time = {}; // Initialize to all 0's
    ss >> get_time(&time, "%d/%m/%Y %H:%M:%S"); // Convert string stream to tm
    return chrono::system_clock::from_time_t(mktime(&time)); // Convert tm to time_point
}

