//
//  Date.h
//  Assignment 2
//
//  Created by Kenta on 9/6/20.
//  Copyright © 2020 Kenta. All rights reserved.
//
//---------------------------------------------------------------------------------

#ifndef Date_h
#define Date_h

//---------------------------------------------------------------------------------

using namespace std;

/**
 * @class Date
 * @brief Date format
 *
 * Date are constructed with day, month and year
 *
 * @author Kenta Toh
 * @version 01
 * @date 09/06/2020
 */
class Date {

public:
    /**
     * @brief Default constructor for Date
     */
    Date();
    // Default constructor
    
    /**
     * @brief Constructor to initalise Date with day, month and year
     *
     * @param day - the day of the date object
     * @param month - the month of the date object
     * @param year - the year of the date object
     */
    Date(unsigned day, unsigned month, unsigned year);
    // Constructor use to initalise date with day, month and year

    /**
     * @brief Destructor for date object
     */
    ~Date();
    // Destructor for date object
    
    /**
     * @brief Set the day of date object
     *
     * @param day - day of the date object
     */
    void setDay(unsigned day);
    // Setter method for day attribute
    
    /**
     * @brief Retrieve the day of the date object
     *
     * @return unsigned representing the day
     */
    unsigned getDay() const;
    // Getter method for day attribute

    /**
     * @brief Set the month of date object
     *
     * @param month - month of the date object
     */
    void setMonth(unsigned month);
    // Setter method for month attribute

    /**
     * @brief Retrieve the month of the date object
     *
     * @return unsigned representing the month
     */
    unsigned getMonth() const;
    // Getter method for month attribute
    
    /**
     * @brief Set the year of date object
     *
     * @param year - year of the date object
     */
    void setYear(unsigned year);
    // Setter method for year attribute

    /**
     * @brief Retrieve the year of the date object
     *
     * @return unsigned representing the year
     */
    unsigned getYear() const;
    // Getter method for year attribute
    
    /**
     * @brief Validate the date  object
     *
     * @return boolean that determines if the date object has pass the validation test or not
     */
    bool validate();
    // To validate the date object

protected:
    unsigned m_day; // Day of date object
    unsigned m_month; // Month of date object
    unsigned m_year; // Year of date object
};

#endif /* Date_h */
