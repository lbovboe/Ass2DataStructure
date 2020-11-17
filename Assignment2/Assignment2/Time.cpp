
#include <stdio.h>
#include <iostream>

using namespace std;

#include "Time.h"

Time::Time() {} // Default constructor

Time::Time(unsigned hour, unsigned min) { // Contructor to initialise hour and min
    m_hour = hour; // Set the m_hour to the value of hour
    m_min = min; // Set the m_min to the value of min
}

Time::~Time() {} // Destructor

void Time::setHour(unsigned hour) {
    m_hour = hour; // Set the m_hour to the value of hour

}

unsigned Time::getHour() const {
    return m_hour; // Return m_hour
}

void Time::setMin(unsigned min) {
    m_min = min; // Set the m_min to the value of min
}

unsigned Time::getMin() const {
    return m_min; // Return m_min
}

bool Time::validate() {
    if (m_hour > 23 || m_hour < 1 || m_min < 1 || m_min > 60) {
        return false; // if hour is more than 23 or min is more than 60, it will be invalid
    }
    return true;
}
