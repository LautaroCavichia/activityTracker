//
// Created by Lautaro Cavichia on 04/04/23.
//

#include "activity.h"

Activity::Activity(const string &name, const string &startTimeString, const string &endTimeString, const string &description):
name(name), description(description){
    setStartTime(startTimeString); // Set the start time checking if it's valid
    setEndTime(startTimeString,endTimeString);     // Set the end time checking if it's valid
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

string Activity::getStartTimeString(bool onlyTime)const {
    if(onlyTime) {  // If onlyTime is true, return the time in the format HH:MM
        time_t startTime_t = chrono::system_clock::to_time_t(this->startTime);
        stringstream ss;
        ss.imbue(std::locale(""));
        ss << put_time(localtime(&startTime_t), "%H:%M");
        return ss.str();
    }
    else {  // If onlyTime is false, return the date and time in the format DD/MM/YYYY HH:MM:SS
        time_t startTime_t = chrono::system_clock::to_time_t(this->startTime);
        stringstream ss;
        ss << ctime(&startTime_t);
        return ss.str();
    }
}

string Activity::getEndTimeString(bool onlyTime)const {
    if(onlyTime) { // If onlyTime is true, return the time in the format HH:MM
        time_t endTime_t = chrono::system_clock::to_time_t(this->endTime);
        stringstream ss;
        ss.imbue(std::locale(""));
        ss << put_time(localtime(&endTime_t), "%H:%M");
        return ss.str();
    }
    else {  // If onlyTime is false, return the date and time in the format DD/MM/YYYY HH:MM:SS
        time_t endTime_t = chrono::system_clock::to_time_t(this->endTime);
        stringstream ss;
        ss << ctime(&endTime_t);
        return ss.str();
    }
}

void Activity::setStartTime(const string &startTimeString) {
    if (!startTimeString.empty())
        this->startTime = stringToTimePoint(startTimeString);
    else {
        this->startTime = chrono::system_clock::now();
    }
}

void Activity::setEndTime(const string &startTimeString, const string &endTimeString) {
    // check if the end time is valid and greater than the start time
    if(isEndAfterStart(startTimeString, endTimeString))
        this->endTime = stringToTimePoint(endTimeString);
    else {
        this->endTime = this->startTime;
    }
}

bool Activity::isEndAfterStart(const string &startTimeString, const string &endTimeString) { // Check if the end time is greater than the start time and if they are in the same day
    tm startTime_tm = {};
    istringstream ssStart(startTimeString);
    ssStart >> get_time(&startTime_tm, "%d/%m/%Y %H:%M:%S");

    tm endTime_tm = {};
    istringstream ssEnd(endTimeString);
    ssEnd >> get_time(&endTime_tm, "%d/%m/%Y %H:%M:%S");

    //check if the end time is greater than the start time
    std::time_t startTime_t = mktime(&startTime_tm);
    std::time_t endTime_t = mktime(&endTime_tm);

    if ((startTime_tm.tm_year != endTime_tm.tm_year) || (startTime_tm.tm_mon != endTime_tm.tm_mon) || (startTime_tm.tm_mday != endTime_tm.tm_mday) || (startTime_t > endTime_t))
        return false;
    else
        return true;
}

chrono::system_clock::time_point Activity::stringToTimePoint(const string &timeString) {
    stringstream ss(timeString); // Convert string to string stream to use get_time
    tm time = {}; // Initialize to all 0
    ss >> get_time(&time, "%d/%m/%Y %H:%M:%S"); // Convert string stream to tm
    return chrono::system_clock::from_time_t(mktime(&time))- chrono::minutes(60); // Convert tm to time_point and subtract 1 hour (offset)
}

string Activity::getDateString() const {  // Returns the date of the activity in the format dd/mm/yyyy
        time_t startTime_t = chrono::system_clock::to_time_t(this->startTime); // Convert time_point to time_t
        tm time = *localtime(&startTime_t); // Convert time_t to tm
        char buffer[80];
        strftime(buffer, 80, "%d/%m/%Y", &time); // Convert tm to string
        return string(buffer);
    }

