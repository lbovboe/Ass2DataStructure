//
//  Time.h
//  Assignment 2
//
//  Created by Kenta on 9/6/20.
//  Copyright © 2020 Kenta. All rights reserved.
//
//---------------------------------------------------------------------------------

#ifndef Time_h
#define Time_h

//---------------------------------------------------------------------------------

using namespace std;

/**
 * @class Time
 * @brief Time format
 *
 * Time are constructed with hour and min
 *
 * @author Kenta Toh
 * @version 01
 * @date 06/06/2020
 */
class Time {

public:
    
    /**
     * @brief Default constructor for Date
     */
    Time();
    
    /**
     * @brief Constructor to initialise Time with hour and min
     *
     * @param hour - the hour of the time object
     * @param min - the minute of the time object
     */
    Time(unsigned hour, unsigned min);
    // Constructor use to initialise time with hour and minute
    
    /**
     * @brief Destructor for time object
     */
    ~Time();
    // Destructor for time object
    
    /**
     * @brief Set the hour of time object
     *
     * @param hour - hour of time object
     */
    void setHour(unsigned hour);
    // Setter method for time attribute
    
    /**
     * @brief Retrieve the hour of the time object
     *
     * @return unsigned representing the hour
     */
    unsigned getHour() const;
    // Getter method for time attribute
    
    /**
     * @brief Set the minute of time object
     *
     * @param min - minunte of time object
     */
    void setMin(unsigned min);
    // Setter method for min attribute
    
    /**
     * @brief Retrieve the minute of time object
     *
     * @return unsigned representing the minute
     */
    unsigned getMin() const;
    // Getter method for min attribute
    
    /**
     * @brief Validate the time object
     *
     * @return boolean that determines if the time object has pass the validation test or not
     */
    bool validate();
    // To validate the time object

protected:
    unsigned m_hour; // Hour of time object
    unsigned m_min; // Minute of time object
};

#endif /* Time_h */
