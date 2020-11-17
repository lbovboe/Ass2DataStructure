


#ifndef iostream_h
#define iostream_h

#include <iostream>

//---------------------------------------------------------------------------------

using namespace std;

//---------------------------------------------------------------------------------

#include "Date.h"
#include "Time.h"
#include "Weather.h"
#include "vector.h"


/**
 * @class iostream
 * @brief Associative class to overload input and output stream
 *
 * @author Kenta Toh
 * @version 01
 * @date 09/06/2020
 */
class iostream {
    
public:
    /**
     * @brief Overloading output stream for date class
     */
    ostream & operator << (const Date & dateObj);
    // Output stream overloading for date
    
    /**
     * @brief Overloading input stream for date class
     */
    istream & operator >> (Date & dateObj);
    // Input stream overloading for date
    
    /**
     * @brief Overloading the less than comparison for date class
     */
    bool operator < (const Date& dateObj);
    // Less than overloading for comparison of date objects
    
    /**
     * @brief Overloading the more than comparison for date class
     */
    bool operator > (const Date& dateObj);
    // more than overloading for comparison of date objects

    /**
     * @brief Overloading the equals comparison for date class
     */
    bool operator == (const Date& dateObj);
    // equals overloading for comparison of date objects
    
    /**
     * @brief Overloading output stream for time class
     */
    ostream & operator << (const Time & timeObj);
    // Output stream overloading for time

    /**
     * @brief Overloading input stream for time class
     */
    istream & operator >> (Time & timeObj);
    // Input stream overloading for time
    
    /**
     * @brief Overloading output stream for weather class
     */
    ostream & operator << (const Weather & weatherObj);
    // Output stream overloading for weather
    
    /**
     * @brief Overloading input stream for time class
     */
    istream & operator >> (Weather & weatherObj);
    // Input stream overloading for weather
};

//---------------------------------------------------------------------------------

ostream & operator << (ostream & os, const Date & dateObj) {
    os << dateObj.getDay()
       << "/" << dateObj.getMonth()
       << "/" << dateObj.getYear(); // Format to output date object
    return os;
}

istream & operator >> (istream & is, Date & dateObj) {
    string day, month, year; // Initialise as string to use getline function

    getline(is, day, '/'); // Get line with delimiter
    getline(is, month, '/');
    getline(is, year, ' ');

    dateObj.setDay(stoi(day)); // Set attributes with stoi (string to integer)
    dateObj.setMonth(stoi(month));
    dateObj.setYear(stoi(year));

    return is;
}

bool operator < (const Date& date1, const Date& date2) { // Date1 < Date2
    if (date1.getYear() < date2.getYear()) { // If the year of date 1 is less than the year of date 2
        return true; // Return true
    } else if (date1.getYear() == date2.getYear()) { // Else if the years are equal
            if (date1.getMonth() < date2.getMonth()) { // if the month of date 1 is less than the month of date 2
                return true; // Return true
            } else if (date1.getMonth() == date2.getMonth()) { // Else if the months are equal
                    if (date1.getDay() < date2.getDay()) { // If the day of date 1 is less than the day of date 2
                        return true; // Return true
                    }
                }
        }
    return false; // Else just return false (Not less than)
}

bool operator > (const Date& date1, const Date& date2) { // Date1 > Date2
    if (date1.getYear() > date2.getYear()) { // If the year of date 1 is more than the year of date 2
        return true; // Return true
    } else if (date1.getYear() == date2.getYear()) { // Else if the years are equal
            if (date1.getMonth() > date2.getMonth()) { // if the month of date 1 is more than the month of date 2
                return true; // Return true
            } else if (date1.getMonth() == date2.getMonth()) { // Else if the months are equal
                    if (date1.getDay() > date2.getDay()) { // If the day of date 1 is more than the day of date 2
                        return true; // Return true
                    }
                }
        }

    return false; // Else just return false (Not more than)
}

bool operator == (const Date& date1, const Date& date2) { // date1 == date2
    if (date1.getYear() == date2.getYear()) { // If the years are equals
        if (date1.getMonth() == date2.getMonth()) { // If the months are equals
            if (date1.getDay() == date2.getDay()) { // If the days are equals
                return true; // Return true
            }
        }
    }
    return false;
}

vector<int> operator - (vector<int> v1, vector<int> v2) {
    vector<int> v3;
    int v1Index  = 0;
    int v2Index = 0;
    while (v1Index < v1.size()) {
        if (v1.at(v1Index) == v2.at(v2Index)) {
            v3.push_back(v1.at(v1Index));
            v1Index++;
            v2Index++;
        } else if (v1.at(v1Index) < v2.at(v2Index)) {
            v1Index++;
        } else {
            v2Index++;
        }
    }
    return v3;
}


 

//---------------------------------------------------------------------------------

ostream & operator << (ostream & os, const Time & timeObj) {
    os << "Time: " << timeObj.getHour()
       << ":" << timeObj.getMin()
       << "\n"; // Format to output time object
    return os;
}


istream & operator >> (istream & is, Time & timeObj) {
    string hour, min; // Initialise as string to use getline function

    getline(is, hour, ':'); // Get line with delimiter
    getline(is, min, ',');
    
    timeObj.setHour(stoi(hour)); // Set attributes with stoi (string to integer)
    timeObj.setMin(stoi(min));

    return is;
}

bool operator == (const Time& time1, const Time& time2) { // time1 == time2
    if (time1.getHour() == time2.getHour()) { // If the years are equals
        if (time1.getMin() == time2.getMin()) { // If the months are equals
            return true; // Return true
        }
    }
    return false;
}
//---------------------------------------------------------------------------------

ostream & operator << (ostream & os, const Weather & weatherObj) {
    os << "Wind Speed: " << weatherObj.getWindSpeed() << " km/h\n"
    << "Solar Radiation: " << weatherObj.getSolarRadiation()<< " kWh/m2\n"
    << "Temperature: " << weatherObj.getTemp() << " degrees C\n"; // Format to output weather object
    return os;
}

istream & operator >> (istream & is, Weather & weatherObj) {
    string windSpeed; // Initialise as string to use getline function
    string solarRadiation;
    string temp;
    string skip; // Use to skip unwanted data
    
    getline(is, windSpeed, ','); // Get line with delimiter
    getline(is, solarRadiation, ',');
    
    for (int i = 0; i < 5; i++) { // For loop to skip unwanted data
        getline(is, skip, ',');
    }
    
    getline(is, temp, '\n');
    

    weatherObj.setWindSpeed(stof(windSpeed)); // Set attributes with stof (string to float)
    weatherObj.setSolarRadiation(stof(solarRadiation));
    weatherObj.setTemp(stof(temp));
    
    return is;
}

//---------------------------------------------------------------------------------



        
#endif /* iostream_h */
