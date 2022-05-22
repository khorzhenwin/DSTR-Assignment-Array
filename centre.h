#pragma once
#include "includes.h"

class Centre
{
public:
    int index;
    int id;
    std::string centreName;
    std::string centreLocation;
    int adminId;

    // constructor
    Centre()
    {
        index = -1;
        id = -1;
        centreName = "";
        centreLocation = "";
        adminId = -1;
    };

    Centre(int index, int id, std::string centreName, std::string centreLocation, int adminId)
    {
        this->index = index;
        this->id = id;
        this->centreName = centreName;
        this->centreLocation = centreLocation;
        this->adminId = adminId;
    };
};

void displayCentreList(Centre *&centreArray, int &size)
{
    int page = 1;
    while (true)
    {
        bool arrayEnd = false;
        system("cls");
        // start
        int start = (page - 1) * 10;
        int end = page * 10;
        std::string userRole;
        std::cout << "Centre list - Page " << page << std::endl;
        std::cout << std::setw(90) << std::setfill('=') << "" << std::endl;
        std::cout << std::setw(6) << std::setfill(' ') << "No.";
        std::cout << std::setw(11) << std::setfill(' ') << "Centre ID";
        std::cout << std::setw(31) << std::setfill(' ') << "Centre Name";
        std::cout << std::setw(21) << std::setfill(' ') << "Centre Location";
        std::cout << std::setw(11) << std::setfill(' ') << "Admin ID" << std::endl;
        std::cout << std::setw(90) << std::setfill('=') << "" << std::endl;
        for (int i = start; i < end; ++i)
        {
            // if not end of dynamic array
            if (i < size)
            {
                std::cout << std::setw(5) << std::setfill(' ') << i + 1 << " ";
                std::cout << std::setw(10) << std::setfill(' ') << centreArray[i].id << " ";
                std::cout << std::setw(30) << std::setfill(' ') << centreArray[i].centreName << " ";
                std::cout << std::setw(20) << std::setfill(' ') << centreArray[i].centreLocation << " ";
                std::cout << std::setw(10) << std::setfill(' ') << centreArray[i].adminId << " " << std::endl;
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
                    input = -1;
                    std::cout << "This is the last page!" << std::endl;
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
                    input = -1;
                    std::cout << "This is the first page!" << std::endl;
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

void displayCentre(Centre *&centreArray, int index)
{
    system("cls");

    std::cout << "Centre ID: " << centreArray[index].id << std::endl;
    std::cout << "Centre Name: " << centreArray[index].centreName << std::endl;
    std::cout << "Centre Location: " << centreArray[index].centreLocation << std::endl;
    std::cout << "Admin ID: " << centreArray[index].adminId << std::endl;
    std::cout << std::endl;
}

void searchCentre(Centre *&centreArray, int &size)
{
    std::cout << std::endl
              << "Enter the id of the centre to search: ";
    int id;
    std::cin >> id;
    while (!std::cin.good() || id < 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter the id of the centre to search: ";
        std::cin >> id;
    }
    std::cout << std::endl;
    int index = binarySearch(centreArray, size, id);
    if (index == -1)
    {
        std::cout << "Centre not found." << std::endl;
    }
    else
    {
        displayCentre(centreArray, index);
    }
    std::cout << std::endl;
}

void addCentre(Centre *&centreArray, int &centreSize, User *&userArray, int &userSize)
{
    std::string centreName;
    std::string centreLocation;
    int adminId;
    std::cout << "Please enter the following to create a new centre:" << std::endl;
    std::cout << "Enter the centre name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, centreName);
    std::cout << "Enter the centre location: ";
    std::getline(std::cin, centreLocation);
    std::cout << "Enter the admin id: ";
    std::cin >> adminId;

    // adminId must be an existing admin
    while (!std::cin.good() || adminId < 0 || adminId > userArray[userSize - 1].id)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter the admin id: ";
        std::cin >> adminId;
    }
    bool flag = true;
    while (flag)
    {
        int userExist = binarySearch(userArray, userSize, adminId);
        int adminExist = linearSearchCentre(centreArray, centreSize, adminId);

        if (userExist == -1)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "User does not exist" << std::endl;
            std::cout << "Enter the admin id: ";
            std::cin >> adminId;
        }
        else if (adminExist != -1)
        {
            std::cout << "Admin is already in charge of a centre" << std::endl;
            std::cout << "Enter the admin id: ";
            std::cin >> adminId;
        }
        else if (userArray[userExist].userType != 1)
        {
            std::cout << "User is not an admin" << std::endl;
            std::cout << "Enter the admin id: ";
            std::cin >> adminId;
        }

        else
        {
            flag = false;
        }
    }
    Centre *newCentre = new Centre(centreSize, userArray[centreSize - 1].id + 1, centreName, centreLocation, adminId);
    createObject(centreArray, centreSize, newCentre);
    std::cout << "Centre created successfully" << std::endl
              << std::endl;
}

void updateCentre(Centre *&centreArray, int &centreSize, User *&userArray, int &userSize)
{
    // prompt for input to fill in constructor
    std::string centreName;
    std::string centreLocation;
    int adminId;

    std::cout << "Enter id of centre to update: ";
    int id;
    std::cin >> id;
    // check for invalid input for id
    while (!std::cin.good() || id < 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter id of the centre to update: ";
        std::cin >> id;
    }
    std::cout << std::endl;
    int index = binarySearch(centreArray, centreSize, id);
    if (index != -1)
    {
        std::cout << "Updating centre: " << centreArray[index].centreName << std::endl;
        std::cout << "Enter new centre name: ";
        std::cin.ignore();
        std::getline(std::cin, centreName);
        std::cout << "Enter new centre location: ";
        std::getline(std::cin, centreLocation);
        std::cout << "Enter new admin id: ";
        std::cin >> adminId;

        // adminId must be an existing admin
        while (!std::cin.good() || adminId < 0 || adminId > userArray[userSize - 1].id)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again." << std::endl;
            std::cout << "Enter the admin id: ";
            std::cin >> adminId;
        }
        bool flag = true;
        while (flag)
        {
            int userExist = binarySearch(userArray, userSize, adminId);
            int adminExist = linearSearchCentre(centreArray, centreSize, adminId);

            if (userExist == -1)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "User does not exist" << std::endl;
                std::cout << "Enter the admin id: ";
                std::cin >> adminId;
            }
            else if (adminExist != -1)
            {
                std::cout << "Admin is already in charge of a centre" << std::endl;
                std::cout << "Enter the admin id: ";
                std::cin >> adminId;
            }
            else if (userArray[userExist].userType != 1)
            {
                std::cout << "User is not an admin" << std::endl;
                std::cout << "Enter the admin id: ";
                std::cin >> adminId;
            }

            else
            {
                flag = false;
            }
        }
        centreArray[index].centreName = centreName;
        centreArray[index].centreLocation = centreLocation;
        centreArray[index].adminId = adminId;
        std::cout << "Centre updated successfully" << std::endl
                  << std::endl;
    }
    else
    {
        std::cout << "Centre not found." << std::endl;
    }
    std::cout << std::endl;
}

void deleteCentre(Centre *&centreArray, int &size)
{
    std::cout << std::endl
              << "Enter the id of the centre to be deleted: ";
    int id;
    std::cin >> id;
    // check for invalid input for id
    while (!std::cin.good() || id < 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter the id of the user to be deleted: ";
        std::cin >> id;
    }
    std::cout << std::endl;
    int index = binarySearch(centreArray, size, id);
    deleteObject(centreArray, size, index);
    std::cout << std::endl;
}