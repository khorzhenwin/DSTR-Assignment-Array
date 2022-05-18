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

void displaySubjectList(Subject *&subjectArray, int &size)
{
    int page = 1;
    while (true)
    {
        bool arrayEnd = false;
        system("cls");
        // start
        int start = (page - 1) * 10;
        int end = page * 10;
        std::cout << "Subject list - Page " << page << std::endl;
        std::cout << std::setw(75) << std::setfill('=') << "" << std::endl;
        std::cout << std::setw(6) << std::setfill(' ') << "No.";
        std::cout << std::setw(16) << std::setfill(' ') << "Subject ID";
        std::cout << std::setw(16) << std::setfill(' ') << "Subject Name";
        std::cout << std::setw(21) << std::setfill(' ') << "Hourly Pay Rate" << std::endl;
        std::cout << std::setw(75) << std::setfill('=') << "" << std::endl;
        for (int i = start; i < end; ++i)
        {
            if (i < size)
            {
                std::cout << std::setw(5) << std::setfill(' ') << i + 1 << " ";
                std::cout << std::setw(15) << std::setfill(' ') << subjectArray[i].id << " ";
                std::cout << std::setw(15) << std::setfill(' ') << subjectArray[i].subjectName << " ";
                std::cout << std::setw(20) << std::setfill(' ') << subjectArray[i].hourlyPayRate << std::endl;
            }
            if (i == size)
            {
                arrayEnd = true;
                break;
            }
        }
        int input = -1;
        while ((input != 0 && input != 1 && input != 2) || !std::cin.good())
        {
            std::cout << "Press 1 to continue or 0 to exit or 2 to the previous page" << std::endl;
            int input = 10;
            std::cin >> input;
            if (input == 0)
            {
                return;
            }
            else if (input == 1)
            {
                if (arrayEnd)
                {
                    std::cout << "This is the last page!" << std::endl;
                    break;
                }
                else
                {
                    page++;
                    break;
                }
            }
            else if (input == 2)
            {
                if (page == 1)
                {
                    std::cout << "This is the first page!" << std::endl;
                    break;
                }
                else
                {
                    page--;
                    break;
                }
            }
            else
            {
                input = -1;
                std::cout << "Invalid input" << std::endl;
            }
        }
    }
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
