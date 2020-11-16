//
//  Date.cpp
//  Assignment 2
//
//  Created by Kenta on 9/6/20.
//  Copyright © 2020 Kenta. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

#include "Date.h"

Date::Date() {} // Default constructor

Date::Date(unsigned day, unsigned month, unsigned year) { // Contructor to initialise day, month and year
    m_day = day; // Set the m_day to the value of day
    m_month = month; // Set the m_month to the value of m_month
    m_year = year; // Set the m_year to the value of m_year
}

Date::~Date() {} // Destructor

void Date::setDay(unsigned day) {
    m_day = day; // Set the m_day to the value of day
}

unsigned Date::getDay() const {
    return m_day; // Return m_day
}

void Date::setMonth(unsigned month) {
    m_month = month; // Set the m_month to the value of m_month
}

unsigned Date::getMonth() const {
    return m_month; // Return m_month
}

void Date::setYear(unsigned year) {
    m_year = year; // Set the m_year to the value of m_year
}

unsigned Date::getYear() const {
    return m_year; // Return m_year
}

bool Date::validate() {
    if (m_day > 31 || m_day < 1 || m_month < 1 || m_month > 12) { // if the day is more than 31 or month is more than 12, it is invalid
        return false;
    }
    return true;
}
