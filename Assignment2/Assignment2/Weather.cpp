

#include <stdio.h>
#include <iostream>

using namespace std;

#include "Weather.h"

Weather::Weather() {} // Default constructor


Weather::Weather(float windSpeed, float solarRadiation, float temp) { // Contructor to initialise windSpeed, solarRadiation and temp
    convertWind(windSpeed); // convert m/s to km/h
    m_windSpeed = windSpeed; // Set the m_windspeed to the value of windSpeed (converted)
    convertSolar(solarRadiation); // convert W/m2 to kWh/m2
    m_solarRadiation = solarRadiation; // Set the m_solarRadiation to the value of solarRadiation (converted)
    m_temp = temp; // Set the m_temp to the value of temp
}

Weather::~Weather() {} // Destructor

void Weather::setWindSpeed(float windSpeed) {
    convertWind(windSpeed); // convert m/s to km/h
    m_windSpeed = windSpeed; // Set the m_windspeed to the value of windSpeed (converted)
}

float Weather::getWindSpeed() const {
    return m_windSpeed; // return m_windSpeed
}

void Weather::convertWind(float &windSpeed) { // converts windspeed m/s to km/h
    windSpeed *= 3.6;
}

void Weather::setTemp(float temp) { // Set the m_temp to the value of temp
    m_temp = temp;
}

float Weather::getTemp() const {
    return m_temp; // return m_temp
}

void Weather::setSolarRadiation(float solarRadiation) {
    convertSolar(solarRadiation); // convert W/m2 to kWh/m2
    m_solarRadiation = solarRadiation; // Set the m_solarRadiation to the value of solarRadiation (converted)
}

float Weather::getSolarRadiation() const {
    return m_solarRadiation; // return m_solarRadiation
}

void Weather::convertSolar(float &solarRadiation) {
    solarRadiation /= 6000; // converts W/m2 to kWh/m2
}

bool Weather::validate() {
    if ((m_solarRadiation * 6000)< 100) { // is the solar radiation is less than 100 W/m2, it is not valid
        return false;
    }
    return true;
}
