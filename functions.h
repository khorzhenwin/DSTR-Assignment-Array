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

// shrink array
template <class T>
void shrinkArray(T *&array, int &size)
{
    T *newArray = new T[size - 1];
    for (int i = 0; i < size - 1; i++)
    {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
    size--;
}

// login function that uses linearSearchlogin
template <class User>
User login(User *userArray, int size)
{
    std::string username;
    std::string password;
    std::cout << "Welcome to eXcel Tuition Management System" << std::endl;
    std::cout << "Please login to proceed" << std::endl;
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;
    std::cout << std::endl;
    int index = linearSearchLogin(userArray, size, username, password);
    while (index == -1)
    {
        system("cls");
        std::cout << "Username or password is incorrect. Please try again." << std::endl;
        std::cout << "Username: ";
        std::cin >> username;
        std::cout << "Password: ";
        std::cin >> password;
        std::cout << std::endl;
        index = linearSearchLogin(userArray, size, username, password);
    }
    std::cout << "Login Successful!" << std::endl;
    std::cout << "Welcome User: " << userArray[index].username << "!" << std::endl;
    std::cout << std::endl;
    return userArray[index];
}

// ---------------------------------------------- Searching Alorithm ----------------------------------------------
// binary search for int id in array and return object
template <class T>
int binarySearch(T *array, int size, int id)
{
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (array[mid].id == id)
        {
            return array[mid];
        }
        else if (array[mid].id < id)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return T.id;
}

// linear search for login username and password in array and return object
template <class T>
int linearSearchLogin(T *array, int size, std::string username, std::string password)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i].username == username && array[i].password == password)
        {
            return array[i].index;
        }
    }
    return -1;
}

// ---------------------------------------------- CRUD Functions ----------------------------------------------

// create new Object at the end of the array from class template using growArray helper function
template <class T>
void createObject(T *&array, int &size, T *newObject)
{
    growArray(array, size);
    array[size - 1] = *newObject;
}

// delete object
template <class T>
void deleteObject(T *&array, int &size, int index)
{
    if (index > size - 1 || index < 0)
    {
        std::cout << "Error: index out of range" << std::endl;
        return;
    }
    for (int i = index; i < size; i++)
    {
        array[i] = array[i + 1];
        array[i].index = i;
    }
    shrinkArray(array, size);
}

#endif // PCH_H