#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "includes.h"
#include "pch.h"

// ---------------------------------------------- General Functions ----------------------------------------------
// get date today in DD/MM/YYYY
std::string getDateToday()
{
    struct tm now;
    time_t t = time(0);
    localtime_s(&now, &t);
    std::string day = (now.tm_mday < 10) ? "0" + std::to_string(now.tm_mday) : std::to_string(now.tm_mday);
    std::string month = (now.tm_mon + 1 < 10) ? "0" + std::to_string(now.tm_mon + 1) : std::to_string(now.tm_mon + 1);
    std::string dateToday = day + "/" + month + "/" + std::to_string(now.tm_year + 1900);
    return dateToday;
}

// get date difference of 2 dates in DD/MM/YYYY format in days
int getDateDifference(std::string date1, std::string date2)
{
    // get date1 in DD/MM/YYYY format
    std::string day1 = date1.substr(0, 2);
    std::string month1 = date1.substr(3, 2);
    std::string year1 = date1.substr(6, 4);
    int day1Int = std::stoi(day1);
    int month1Int = std::stoi(month1);
    int year1Int = std::stoi(year1);

    // get date2 in DD/MM/YYYY format
    std::string day2 = date2.substr(0, 2);
    std::string month2 = date2.substr(3, 2);
    std::string year2 = date2.substr(6, 4);
    int day2Int = std::stoi(day2);
    int month2Int = std::stoi(month2);
    int year2Int = std::stoi(year2);

    // get date1 in seconds
    time_t t1 = time(0);
    struct tm now1;
    localtime_s(&now1, &t1);
    now1.tm_mday = day1Int;
    now1.tm_mon = month1Int - 1;
    now1.tm_year = year1Int - 1900;
    time_t t1Seconds = mktime(&now1);

    // get date2 in seconds
    time_t t2 = time(0);
    struct tm now2;
    localtime_s(&now2, &t2);
    now2.tm_mday = day2Int;
    now2.tm_mon = month2Int - 1;
    now2.tm_year = year2Int - 1900;
    time_t t2Seconds = mktime(&now2);

    // get difference in seconds
    int difference = t2Seconds - t1Seconds;

    // get difference in days
    int differenceDays = difference / 86400;

    return differenceDays;
}

// grow array
template <class T>
void growArray(T *&array, int &size)
{
    T *newArray = new T[size + 1];
    for (int i = 0; i < size; i++)
    {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
    size++;
}

// ---------------------------------------------- Searching Alorithm ----------------------------------------------

// ---------------------------------------------- CRUD Functions ----------------------------------------------

// create new Object at the end of the array from class template using growArray helper function
template <class T>
void createObject(T *&array, int &size, T *newObject)
{
    growArray(array, size);
    array[size - 1] = *newObject;
}

#endif // PCH_H