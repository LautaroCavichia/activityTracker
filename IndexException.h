//
// Created by Lautaro Cavichia on 13/07/23.
//

#ifndef ACTIVITYTRACKER_INDEXEXCEPTION_H
#define ACTIVITYTRACKER_INDEXEXCEPTION_H

#include <stdexcept>

class IndexException: public std::exception {
public:
    const char* what () const noexcept override {
        return "Index out of bounds";
    }

};


#endif //ACTIVITYTRACKER_INDEXEXCEPTION_H
