#pragma once
#include "includes.h"

class Subject
{
public:
    int index;
    int id;
    std::string subjectName;
    double hourlyPayRate;

    // constructor
    Subject()
    {
        index = -1;
        id = -1;
        subjectName = "";
        hourlyPayRate = 0;
    };

    Subject(int index, int id, std::string subjectName, double hourlyPayRate)
    {
        this->index = index;
        this->id = id;
        this->subjectName = subjectName;
        this->hourlyPayRate = hourlyPayRate;
    };
};

void displaySubjectList(Subject *&subjectArray, int &subjectSize, int page)
{
    system("cls");
    // paginate the list
    int pageSize = 10;
    int totalPages = (subjectSize / pageSize) + 1;
    int pageStart = (page - 1) * pageSize;
    int pageEnd = page * pageSize;
    if (pageEnd > subjectSize)
    {
        pageEnd = subjectSize;
    }
    // display the list
    std::cout << "Subject List" << std::endl;
    std::cout << "Page " << page << " of " << totalPages << std::endl;
    std::cout << "No.\tID\tSubject Name\tHourly Pay Rate" << std::endl;
    for (int i = pageStart; i < pageEnd; i++)
    {
        std::cout << i + 1 << "\t" << subjectArray[i].id << "\t" << subjectArray[i].subjectName << "\t\t" << subjectArray[i].hourlyPayRate << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Enter -1 to return to main menu." << std::endl;
    std::cout << "Page: ";
    std::cin >> page;
    if (page == -1)
    {
        system("cls");
        return;
    }
    while (page < 1 || page > totalPages)
    {
        if (page == -1)
        {
            system("cls");
            return;
        }
        std::cout << std::endl;
        std::cout << "Invalid page. Please try again." << std::endl;
        std::cout << "Page: ";
        std::cin >> page;
    }

    system("cls");
    displaySubjectList(subjectArray, subjectSize, page);
}

void displaySubject(Subject *&subjectArray, int index)
{
    system("cls");

    std::cout << "Subject ID: " << subjectArray[index].id << std::endl;
    std::cout << "Subject Name: " << subjectArray[index].subjectName << std::endl;
    std::cout << "Hourly Pay Rate: " << subjectArray[index].hourlyPayRate << std::endl;
    std::cout << std::endl;
}

void searchSubject(Subject *&subjectArray, int &size)
{
    std::cout << std::endl
              << "Enter the id of the subject to search: ";
    int id;
    std::cin >> id;
    while (!std::cin.good() || id < 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter the id of the subject to search: ";
        std::cin >> id;
    }
    std::cout << std::endl;
    int index = binarySearch(subjectArray, size, id);
    if (index == -1)
    {
        std::cout << "Subject not found." << std::endl;
    }
    else
    {
        displaySubject(subjectArray, index);
    }
    std::cout << std::endl;
}

void addSubject(Subject *&subjectArray, int &size)
{
    std::string subjectName;
    double hourlyPayRate;

    std::cout << "Please enter the following to add a subject: " << std::endl;
    std::cout << "Subject Name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, subjectName);
    std::cout << "Hourly Pay Rate: ";
    std::cin >> hourlyPayRate;
    while (!std::cin.good() || hourlyPayRate < 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Hourly Pay Rate: ";
        std::cin >> hourlyPayRate;
    }

    // create new user
    Subject *newSubject = new Subject(size, subjectArray[size - 1].id + 1, subjectName, hourlyPayRate);
    createObject(subjectArray, size, newSubject);
    std::cout << "Subject created successfully" << std::endl
              << std::endl;
}

void updateSubject(Subject *&subjectArray, int &size)
{
    // prompt for input to fill in constructor
    std::string subjectName;
    double hourlyPayRate;
    int adminId;
    std::cout << "Enter id of subject to update: ";
    int id;
    std::cin >> id;
    // check for invalid input for id
    while (!std::cin.good() || id < 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter id of the subject to update: ";
        std::cin >> id;
    }
    std::cout << std::endl;
    int index = binarySearch(subjectArray, size, id);
    if (index != -1)
    {
        std::cout << "Updating subject: " << subjectArray[index].subjectName << std::endl;
        std::cout << "Enter new Subject Name: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, subjectName);
        std::cout << "Enter New Hourly Pay Rate: ";
        std::cin >> hourlyPayRate;
        while (!std::cin.good() || hourlyPayRate < 0)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again." << std::endl;
            std::cout << "Hourly Pay Rate: ";
            std::cin >> hourlyPayRate;
        }
        subjectArray[index].subjectName = subjectName;
        subjectArray[index].hourlyPayRate = hourlyPayRate;
        std::cout << "Subject has been updated" << std::endl
                  << std::endl;
    }
    else
    {
        std::cout << "Subject not found." << std::endl;
    }
    std::cout << std::endl;
}

void deleteSubject(Subject *&subjectArray, int &size)
{
    std::cout << std::endl
              << "Enter the id of the subject to be deleted: ";
    int id;
    std::cin >> id;
    // check for invalid input for id
    while (!std::cin.good() || id < 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter the id of the subject to be deleted: ";
        std::cin >> id;
    }
    std::cout << std::endl;
    int index = binarySearch(subjectArray, size, id);
    deleteObject(subjectArray, size, index);
    std::cout << std::endl;
}
