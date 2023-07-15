//
// Created by Lautaro Cavichia on 30/05/23.
//

#include "TimeUtilities.h"
#include <sstream>
#include <iomanip>

chrono::system_clock::time_point TimeUtilities::stringToTimePoint(const string &timeString) {
    stringstream ss(timeString); // Convert string to string stream to use get_time
    tm time = {}; // Initialize to all 0
    ss >> get_time(&time, "%d/%m/%Y %H:%M:%S"); // Convert string stream to tm
    return chrono::system_clock::from_time_t(mktime(&time))- chrono::minutes(60); // Convert tm to time_point and subtract 1 hour (offset)
}

bool TimeUtilities::isEndAfterStart(const string &startTimeString, const string &endTimeString) {
    tm startTime_tm = {};
    istringstream ssStart(startTimeString);
    ssStart >> get_time(&startTime_tm, "%d/%m/%Y %H:%M:%S");

    tm endTime_tm = {};
    istringstream ssEnd(endTimeString);
    ssEnd >> get_time(&endTime_tm, "%d/%m/%Y %H:%M:%S");

    // Check if the end time is greater than the start time
    std::time_t startTime_t = mktime(&startTime_tm);
    std::time_t endTime_t = mktime(&endTime_tm);

    if ((startTime_tm.tm_year != endTime_tm.tm_year) || (startTime_tm.tm_mon != endTime_tm.tm_mon) || (startTime_tm.tm_mday != endTime_tm.tm_mday) || (startTime_t > endTime_t))
        return false;
    else
        return true;
}



 string TimeUtilities::timePointToString(const chrono::system_clock::time_point &timePoint ,bool onlyTime) {
    if(onlyTime) {  // If onlyTime is true, return the time in the format HH:MM
        time_t startTime_t = chrono::system_clock::to_time_t(timePoint);
        stringstream ss;
        ss.imbue(std::locale(""));
        ss << put_time(localtime(&startTime_t), "%H:%M");
        return ss.str();
    }
    else {  // If onlyTime is false, return the date and time in the format DD/MM/YYYY HH:MM:SS
        time_t startTime_t = chrono::system_clock::to_time_t(timePoint);
        stringstream ss;
        ss << ctime(&startTime_t);
        return ss.str();
    }
}

string TimeUtilities::dateToString(const chrono::system_clock::time_point &timePoint) {
    time_t startTime_t = chrono::system_clock::to_time_t(timePoint); // Convert time_point to time_t
    tm time = *localtime(&startTime_t); // Convert time_t to tm
    char buffer[80];
    strftime(buffer, 80, "%d/%m/%Y", &time); // Convert tm to string
    return buffer;
}
