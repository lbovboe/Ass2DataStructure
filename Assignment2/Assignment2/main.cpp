//
//  main.cpp
//  Assignment 1
//
//  Created by Kenta on 9/6/20.
//  Copyright © 2020 Kenta. All rights reserved.
//
//---------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

//---------------------------------------------------------------------------------

using namespace std;

#include "Date.h"
#include "Time.h"
#include "Weather.h"
#include "vector.h"
#include "iostream.h"
#include "map.h"
#include "Bst.h"

//---------------------------------------------------------------------------------

void printFileSelection();
void printMenu(); // Method to print menu
void inputOne(map<Date, Weather>); // Menu input 1
void inputTwo(map<Date, Weather>); // Menu input 2
void inputThree(map<Date, Weather>); // Menu input 3
void inputFour(map<Date, Weather>); // Menu input 4
void inputFive(map<Date, Weather>, map<Time, Date>); // Menu input 5
string convertMonth(int inputMonth); // To convert month from int to string; 1 to January

//---------------------------------------------------------------------------------

int main(void) {

    
    Date dateObj; // Initialise a date object
    Time timeObj; // Initialise a time object
    Weather weatherObj; // Initialise a weather object
    string skip; // String skip, to skip unwanted data
              
    vector<Date> dateVector;
    map<Date, Weather> dateWeatherMap;
    map<Time, Date> timeDateMap;
    Bst<Date> dateBst;
    
    ifstream metFile ("data/met_index.txt");
    string fileName;
    
    if (metFile.is_open()) { // If the met file is open
        while (metFile.peek() != EOF) { // And the next char is not end of file
            getline(metFile,fileName); // Get line inside the store into the file name
            fileName = "data/" + fileName; // Concatenate the file name by adding data/ to the front (directory)
            cout << "Loading: " <<  fileName << endl; // Loading the file name
            
            ifstream infile (fileName.c_str()); // Stream the file
            if (infile.is_open()) { // If it can be opened
            
                getline(infile,skip);
                while (infile.peek() != EOF) { // And while the next char is not the end of file
                    infile >> dateObj >> timeObj; // Stream into date object and time object (overloaded)


                    for (int i = 0; i < 9; i++) { // For loop to skip unwanted data
                        getline(infile, skip, ','); // skip to store all the unwanted data
                    }
                    
                    infile >> weatherObj; // Stream into weather object (overload)
              
                    if (dateObj.validate() && timeObj.validate() && weatherObj.validate()) { // To validate for date, time and weather object. If it passes the validation test, store it into the map, else ignore it
                        if (!dateVector.search(dateObj)) {
                            dateVector.push_back(dateObj);
                        }
                        dateWeatherMap.insert(myPair<Date, Weather>(dateObj, weatherObj));
                        timeDateMap.insert(myPair<Time, Date>(timeObj, dateObj));

                    }
                }
                infile.close();
            } else {
                cout << "Error reading from file" << endl; // File not found
            }
        }
        metFile.close();
    } else {
        cout << "Error reading from file" << endl; // File not found
    }
    
    dateVector.shuffle();
    for (int i = 0; i < dateVector.size(); i++) {
        dateBst.insert(dateVector.at(i));
    }
    
    cout << endl;
    char userInput = '6'; // User's input (default)
    do { // To ensure that loop runs at least once
        printMenu(); // Print the menu
        cout << "Selection: "; // Display purpose
        cin >> userInput; // Take in userinputs
        cout << endl; // Display purpose

        switch (userInput) { // Switch case for user's input
            case '1': // If input is 1
                inputOne(dateWeatherMap); // Run this function
                break; // break
            case '2': // And so on
                inputTwo(dateWeatherMap);
                break;
            case '3':
                inputThree(dateWeatherMap);
                break;
            case '4':
                inputFour(dateWeatherMap);
                break;
            case '5':
                inputFive(dateWeatherMap, timeDateMap);
                break;
            case '6':
                break;
            default: // Print out enter 1 to 6
                cout << "Please enter 1 to 6 only" << endl;
                break;
        }
    } while (userInput != '6'); // User input 5 will just break the loop

    return 0; // End of file
}

//---------------------------------------------------------------------------------

void printMenu() { // Print menu
    cout << "********************************************************  Menu  *********************************************************************" << endl << endl;
    cout << "1. The average wind speed and average ambient air temperature for a specified month and year." << endl;
    cout << "2. Average wind speed and average ambient air temperature for each month of a specified year." << endl;
    cout << "3. Total solar radiation in kWh/m2 for each month of a specified year." << endl;
    cout << "4. Average wind speed (km/h), average ambient air temperature and total solar radiation in kWh/m2 for each month of a specified year." << endl;
    cout << "5. The maximum solar radiation for the given date and the corresponding time." << endl;
    cout << "6. Exit the program" << endl << endl;
    cout << "*************************************************************************************************************************************" << endl << endl;
}

//---------------------------------------------------------------------------------

void inputOne(map<Date, Weather> dateWeatherMap) { // Input One
    unsigned inputMonth; // user to input month
    unsigned inputYear; // user to input year

    cout << "Please enter year: "; // Prompt
    cin >> inputYear;
    cout << "Please enter month: "; // Prompt
    cin >> inputMonth;

    float totalWindSpeed = 0; // Variable to store total wind speed
    float totalTemp = 0; // Variable to store total temperature
    float count = 0; // Count for number of times something is stored to calculate average


    for (int i = 0; i < dateWeatherMap.size(); i++) { // while loop to iterate throught the vector of date

        if (dateWeatherMap.key(i).getYear() == inputYear) { // If the year is equals to the input year
            if (dateWeatherMap.key(i).getMonth() == inputMonth) { // And if the month is equals to the input month
                totalWindSpeed += dateWeatherMap.at(i).second.getWindSpeed(); // Store the wind speed into total wind speed at the index i
                totalTemp += dateWeatherMap.at(i).second.getTemp(); // Store the temperature into total temperature at the index i
                count++; // Add 1 to count
            }
        }
    }
    if (count == 0) { // If there isnt any count, means that no data was matched/found
        cout << convertMonth(inputMonth) << " " << inputYear << ": No Data" << endl; // Print out no data
    } else { // else print out the average wind and temperature at 2 decimal place
        cout << convertMonth(inputMonth) << " " << inputYear << ": " << fixed << setprecision(2) << totalWindSpeed/count << " km/h, "
        << fixed << setprecision(2) << totalTemp/count << " degrees C" << endl;
    }
    // convert month used to convert month from int to string (1 to January (display purpose))
    cout << endl; // display purpose
}

//---------------------------------------------------------------------------------

void inputTwo(map<Date, Weather> dateWeatherMap) { // Input two
    int inputYear; // user to input year
    cout << "Please enter year: ";
    cin >> inputYear;

    float monthlyWindSpeed[12] = {0}; // Create a monthly wind speed array with the size 12 (for each month) to store in monthly total wind speed
    float monthlyTemp[12] = {0}; // Create a monthly temperature array with the size 12 (for each month) to store in monthly total temperature
    int monthlyCount[12] = {0}; // Create a monthly count array with size 12 (for each month) to store the number of count in each month

    for (int i = 0; i < dateWeatherMap.size(); i++) { // Iterating through the date vector
        if (dateWeatherMap.key(i).getYear() == inputYear) { // if the year of the data matches input
            monthlyWindSpeed[(dateWeatherMap.key(i).getMonth())-1] += dateWeatherMap.at(i).second.getWindSpeed(); // Get the wind speed of the weather at index i and stored it into its corresponding month (-1 due to array starting from 0)
            monthlyTemp[(dateWeatherMap.key(i).getMonth())-1] += dateWeatherMap.at(i).second.getTemp(); // Get the temperature of the weather at index i and stored it into its corresponding month (-1 due to array starting from 0)
            monthlyCount[(dateWeatherMap.key(i).getMonth())-1] += 1; // increase the count of that month
        }
    }

    cout << inputYear << endl; // Output user input year
    for(int j = 0; j < 12; j++) { // for loop for each month
        if (monthlyCount[j] != 0) { // While the monthly count is not empty (no match/data found)
            cout << convertMonth(j+1) << ": " << fixed << setprecision(2) << monthlyWindSpeed[j]/monthlyCount[j] << " km/h, " // output the monthly average in 2 d.p of wind speed and temperature
            << fixed << setprecision(2) << monthlyTemp[j]/monthlyCount[j] << " degrees C" << endl; // convert month j+1 as arrays starts from 0
        } else {
            cout << convertMonth(j+1) << ": No Data" << endl; // Else print out no data for that month
        }
    }
    cout << endl; // display purpose
}

//---------------------------------------------------------------------------------

void inputThree(map<Date, Weather> dateWeatherMap) {
    int inputYear; // user to input year
    cout << "Please enter year: ";
    cin >> inputYear;

    float monthlySolarRadiation[12] = {0};// Create a monthly solar radiation array with the size 12 (for each month) to store in monthly total wind speed
    int monthlyCount[12] = {0}; // Create a monthly count array with size 12 (for each month) to store the number of count in each month

    for (int i = 0; i < dateWeatherMap.size(); i++) { // Iterating through the date vector
        if (dateWeatherMap.key(i).getYear() == inputYear) { // if the year of the data matches input
            monthlySolarRadiation[(dateWeatherMap.key(i).getMonth())-1] += dateWeatherMap.at(i).second.getSolarRadiation();// Get the solar radiation of the weather at index i and stored it into its corresponding month (-1 due to array starting from 0)
            monthlyCount[(dateWeatherMap.key(i).getMonth())-1] += 1; // increase the count of that month
        }
    }

    cout << inputYear << endl; // Output user input year
    for(int j = 0; j < 12; j++) { // for loop for each month
        if (monthlyCount[j] != 0) { // While the monthly count is not empty (no match/data found)
            cout << convertMonth(j+1) << ": " << fixed << setprecision(2) << monthlySolarRadiation[j]/monthlyCount[j] << " kWh/m2" << endl; // output the monthly average in 2 d.p of solar radiation
        } else {
            cout << convertMonth(j+1) << ": No Data" << endl; // Else print out no data for that month
        }
    }
    cout << endl; // display purpose
}

//---------------------------------------------------------------------------------

void inputFour(map<Date, Weather> dateWeatherMap) {
    int inputYear; // user to input year
    cout << "Please enter year: ";
    cin >> inputYear;
    cout << endl;

    float monthlyWindSpeed[12] = {0}; // Create a monthly wind speed array with the size 12 (for each month) to store in monthly total wind speed
    float monthlyTemp[12] = {0}; // Create a monthly temperature array with the size 12 (for each month) to store in monthly total temperature
    float monthlySolarRadiation[12] = {0};// Create a monthly solar radiation array with the size 12 (for each month) to store in monthly total wind speed
    int monthlyCount[12] = {0}; // Create a monthly count array with size 12 (for each month) to store the number of count in each month

    for (int i = 0; i < dateWeatherMap.size(); i++) { // Iterating through the date vector
        if (dateWeatherMap.key(i).getYear() == inputYear) { // if the year of the data matches input
            monthlyWindSpeed[(dateWeatherMap.key(i).getMonth())-1] += dateWeatherMap.at(i).second.getWindSpeed(); // Get the wind speed of the weather at index i and stored it into its corresponding month (-1 due to array starting from 0)
            monthlyTemp[(dateWeatherMap.key(i).getMonth())-1] += dateWeatherMap.at(i).second.getTemp(); // Get the temperature of the weather at index i and stored it into its corresponding month (-1 due to array starting from 0)
            monthlySolarRadiation[(dateWeatherMap.key(i).getMonth())-1] += dateWeatherMap.at(i).second.getSolarRadiation();// Get the solar radiation of the weather at index i and stored it into its corresponding month (-1 due to array starting from 0)            monthlyCount[(dateWeatherMap.key(i).getMonth())-1] += 1; // increase the count of that month
        }
    }

    ofstream outfile ("output/WindTempSolar.csv"); // Output to this file <<
    if (outfile.is_open()) { // While the file is open
        outfile << inputYear << "\n"; // Stream the user's input and break line
        for (int j = 0; j < 12; j++) { // for loop for each month
            if (monthlyCount[j] != 0) { // While the count for the month is not empty
                outfile << convertMonth(j+1) << "," // Output format of month, windspeed, temperature and solar radiation in 2 decimal place
                << fixed << setprecision(2) << monthlyWindSpeed[j]/monthlyCount[j] << ","
                << fixed << setprecision(2) << monthlyTemp[j]/monthlyCount[j] << ","
                << fixed << setprecision(2) << monthlySolarRadiation[j]/monthlyCount[j] << "\n";
            }
        }
        cout << "Data output to 'output/WindTempSolar.csv'" << endl; // Inform user that data has been output
    }
    outfile.close(); // close file
    cout << endl; // display purpose
}

//---------------------------------------------------------------------------------

void inputFive(map<Date, Weather> dateWeatherMap, map<Time, Date> timeDateMap) {
    int inputYear, inputMonth, inputDay; // Prompt for year, month and day
    cout << "Enter year: "; // Get year month and day
    cin >> inputYear;
    cout << "Enter month: ";
    cin >> inputMonth;
    cout << "Enter day: ";
    cin >> inputDay;
    
    float highestRadiation = 0; // Highest radiation, to be compared for the highest value
    int highestIndex = -1; // Set index -1 to check if date had data or not
    
    for (int i = 0; i < dateWeatherMap.size(); i++) { // Iterate through the map
        if (dateWeatherMap.key(i).getYear() == inputYear && dateWeatherMap.key(i).getMonth() == inputMonth && dateWeatherMap.key(i).getDay() == inputDay) { // If the date at index i year, month and day is the same as input
            if (dateWeatherMap.at(i).second.getSolarRadiation() > highestRadiation) { // If the solar radiation at index i is higher then the highest solar radiation
                highestRadiation = dateWeatherMap.at(i).second.getSolarRadiation(); // Set highest solar radiation to the one at index i
                highestIndex = i; // Set the highest index as i
            }
        }
    }
    
    if (highestIndex == -1) { // If date not found
        cout << "Date not found" << endl;
    } else {
        cout << "Date entered: " << dateWeatherMap.key(highestIndex) << endl;
        cout << "Highest solar radiation: " << fixed << setprecision(2) << highestRadiation << " kWh/m2" << endl;
        cout << "Time: " << timeDateMap.key(highestIndex) << endl;
    }
    
}


//---------------------------------------------------------------------------------

string convertMonth(int inputMonth) { // To convert mont from int to string
    string monthInString = "";
    switch(inputMonth) {
        case 1:
            monthInString = "January";
            break;
        case 2:
            monthInString = "Febuary";
            break;
        case 3:
            monthInString = "March";
            break;
        case 4:
            monthInString = "April";
            break;
        case 5:
            monthInString = "May";
            break;
        case 6:
            monthInString = "June";
            break;
        case 7:
            monthInString = "July";
            break;
        case 8:
            monthInString = "August";
            break;
        case 9:
            monthInString = "September";
            break;
        case 10:
            monthInString = "October";
            break;
        case 11:
            monthInString = "November";
            break;
        case 12:
            monthInString = "December";
            break;
        default:
            monthInString = "Invalid";
    }
    return monthInString;
}

//---------------------------------------------------------------------------------

// END OF MAIN
