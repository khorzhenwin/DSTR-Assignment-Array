#pragma once
#pragma warning(disable : 4996)
#include "includes.h"

class Archive
{
public:
    int index;
    int id;
    std::string tutorName;
    std::string tutorAddress;
    std::string tutorPhoneNumber;
    std::string dateJoined;
    std::string dateTerminated;
    int totalRatings;
    int ratingCount;
    int centreId;
    int subjectId;

    // constructor
    Archive()
    {
        index = -1;
        id = -1;
        tutorName = "";
        tutorAddress = "";
        tutorPhoneNumber = "";
        dateJoined = "";
        dateTerminated = "";
        totalRatings = 0;
        ratingCount = 0;
        centreId = -1;
        subjectId = -1;
    };

    Archive(int index, int id, std::string tutorName, std::string tutorAddress, std::string tutorPhoneNumber,
            std::string dateJoined, std::string dateTerminated, int totalRatings, int ratingCount, int centreId,
            int subjectId)
    {
        this->index = index;
        this->id = id;
        this->tutorName = tutorName;
        this->tutorAddress = tutorAddress;
        this->tutorPhoneNumber = tutorPhoneNumber;
        this->dateJoined = dateJoined;
        this->dateTerminated = dateTerminated;
        this->totalRatings = totalRatings;
        this->ratingCount = ratingCount;
        this->centreId = centreId;
        this->subjectId = subjectId;
    };
};
    void displayArchiveList(Archive* archiveArray, int &archiveArraySize)
    {
        int page = 1;
        while (true)
        {
            bool arrayEnd = false;
            system("cls");
            // start
            int start = (page - 1) * 10;
            int end = page * 10;
            std::cout << "Archive Tutor list - Page " << page << std::endl;
            std::cout << std::setw(180) << std::setfill('=') << "" << std::endl;
            std::cout << std::setw(6) << std::setfill(' ') << "No.";
            std::cout << std::setw(16) << std::setfill(' ') << "Archive ID";
            std::cout << std::setw(16) << std::setfill(' ') << "Tutor Name";
            std::cout << std::setw(30) << std::setfill(' ') << "Tutor Address";
            std::cout << std::setw(22) << std::setfill(' ') << "Tutor Phone Number";
            std::cout << std::setw(16) << std::setfill(' ') << "Date Joined";
            std::cout << std::setw(16) << std::setfill(' ') << "Date Terminated";
            std::cout << std::setw(16) << std::setfill(' ') << "Total Ratings";
            std::cout << std::setw(16) << std::setfill(' ') << "Rating Count";
            std::cout << std::setw(12) << std::setfill(' ') << "Center Id";
            std::cout << std::setw(12) << std::setfill(' ') << "Subject Id" << std::endl;
            std::cout << std::setw(180) << std::setfill('=') << "" << std::endl;
            for (int i = start; i < end; ++i)
            {
                if (i < archiveArraySize)
                {
                    std::cout << std::setw(5) << std::setfill(' ') << i + 1 << " ";
                    std::cout << std::setw(15) << std::setfill(' ') << archiveArray[i].id << " ";
                    std::cout << std::setw(15) << std::setfill(' ') << archiveArray[i].tutorName << " ";
                    std::cout << std::setw(29) << std::setfill(' ') << archiveArray[i].tutorAddress << " ";
                    std::cout << std::setw(21) << std::setfill(' ') << archiveArray[i].tutorPhoneNumber << " ";
                    std::cout << std::setw(15) << std::setfill(' ') << archiveArray[i].dateJoined << " ";
                    std::cout << std::setw(15) << std::setfill(' ') << archiveArray[i].dateTerminated << " ";
                    std::cout << std::setw(15) << std::setfill(' ') << archiveArray[i].totalRatings << " ";
                    std::cout << std::setw(15) << std::setfill(' ') << archiveArray[i].ratingCount << " ";
                    std::cout << std::setw(11) << std::setfill(' ') << archiveArray[i].centreId << " ";
                    std::cout << std::setw(11) << std::setfill(' ') << archiveArray[i].subjectId << std::endl;
                }
                if (i == archiveArraySize)
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
