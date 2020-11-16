//
//  Weather.h
//  Assignment 2
//
//  Created by Kenta on 9/6/20.
//  Copyright © 2020 Kenta. All rights reserved.
//
//---------------------------------------------------------------------------------

#ifndef Wind_h
#define Wind_h

//---------------------------------------------------------------------------------

using namespace std;

/**
 * @class Weather
 * @brief Weather format
 *
 * Weather are constructed with wind speed, solar radiation and temperature
 *
 * @author Kenta Toh
 * @version 01
 * @date 09/06/2020
*/
class Weather {
    
public:
    /**
     * @brief Default constructor for Weather
     */
    Weather();
    // Default constructor
    
    /**
     * @brief Constructor to initalise Weather with windSpeed, solarRadiation and temp
     *
     * @param windSpeed - The wind speed recorded
     * @param solarRadiation - The solar radiation recorded
     * @param temp - The temperature recorded
     */
    Weather(float windSpeed, float solarRadiation, float temp);
    // Constructor use to initalise weather with windspeed, solar radiation and temp
    
    /**
     * @brief Destructor for weather object
     */
    ~Weather();
    // Destructor for weather object
    
    /**
     * @brief Set the windspeed of weather object
     *
     * @param windSpeed - windspeed recorded
     */
    void setWindSpeed(float windSpeed);
    // Setter method for windSpeed attribute

    /**
     * @brief Retrieve the windspeed of the weather object
     *
     * @return unsigned representing the windspeed
     */
    float getWindSpeed() const;
    // Getter method for windspeed attribute
    
    /**
     * @brief Set the temperature of weather object
     *
     * @param temp - temperature recorded
     */
    void setTemp(float temp);
    // Setter method for temperature attribute
    
    /**
     * @brief Retrieve the temperature of the weather object
     *
     * @return unsigned representing the temperature
     */
    float getTemp() const;
    // Getter method for temperature attribute
    
    /**
     * @brief Set the solar radiation of weather object
     *
     * @param solarRadiation - solar radiation recorded
     */
    void setSolarRadiation(float solarRadiation);
    // Setter method for temperature attribute
    
    /**
     * @brief Retrieve the solar radiation of the weather object
     *
     * @return unsigned representing the solar radiation
     */
    float getSolarRadiation() const;
    // Getter method for solar radiation attribute
    
    /**
     * @brief Validate the weather object
     *
     * @return boolean that determines if the weather object has pass the validation test or not
     */
    bool validate();
    // To validate the time object
    
protected:
    float m_windSpeed; // Wind speed recorded
    float m_temp; // Temperature recorded
    float m_solarRadiation; // Solar radiation recorded
    
    void convertWind(float &windSpeed); // Method to convert windspeed from m/s to km/h
    void convertSolar(float &solarRadiation); // Method to convert solar radiation from W/m2 to kWh/m2

};

#endif /* Wind_h */
