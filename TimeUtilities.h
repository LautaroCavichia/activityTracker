//
// Created by Lautaro Cavichia on 30/05/23.
//

#ifndef ACTIVITYTRACKER_TIMEUTILITIES_H
#define ACTIVITYTRACKER_TIMEUTILITIES_H

#include <chrono>
#include <string>

using namespace std;

namespace TimeUtilities {
     chrono::system_clock::time_point stringToTimePoint(const string &timeString);
     bool isEndAfterStart(const string &startTimeString, const string &endTimeString) ;
     string timePointToString(const chrono::system_clock::time_point &timePoint,bool onlyTime = true);
     string dateToString(const chrono::system_clock::time_point &timePoint);

};


#endif //ACTIVITYTRACKER_TIMEUTILITIES_H
