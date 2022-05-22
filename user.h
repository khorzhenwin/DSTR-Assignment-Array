#pragma once
#include "includes.h"

class User
{
public:
    int index;
    int id;
    std::string username;
    std::string password;
    unsigned int userType; // 0-HR, 1-Admin, 2- Tutor

    // constructor
    User()
    {
        index = -1;
        id = -1;
        username = "";
        password = "";
        userType = 0;
    };

    User(int index, int id, std::string username, std::string password, unsigned int userType)
    {
        this->index = index;
        this->id = id;
        this->username = username;
        this->password = password;
        this->userType = userType;
    };
};

void displayUserList(User *&userArray, int &size)
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
        std::cout << "User list - Page " << page << std::endl;
        std::cout << std::setw(60) << std::setfill('=') << "" << std::endl;
        std::cout << std::setw(6) << std::setfill(' ') << "No.";
        std::cout << std::setw(11) << std::setfill(' ') << "User ID";
        std::cout << std::setw(11) << std::setfill(' ') << "Username";
        std::cout << std::setw(11) << std::setfill(' ') << "Password";
        std::cout << std::setw(18) << std::setfill(' ') << "User Type " << std::endl;
        std::cout << std::setw(60) << std::setfill('=') << "" << std::endl;
        for (int i = start; i < end; ++i)
        {
            if (i < size)
            {
                if (userArray[i].userType == 0)
                {
                    userRole = " 0 - HR";
                }
                else if (userArray[i].userType == 1)
                {
                    userRole = "1 - Admin";
                }
                else
                {
                    userRole = "2 - Tutor";
                }
                std::cout << std::setw(5) << std::setfill(' ') << i + 1 << " ";
                std::cout << std::setw(10) << std::setfill(' ') << userArray[i].id << " ";
                std::cout << std::setw(10) << std::setfill(' ') << userArray[i].username << " ";
                std::cout << std::setw(10) << std::setfill(' ') << userArray[i].password << " ";
                std::cout << std::setw(17) << std::setfill(' ') << userRole << std::endl;
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
                    input = -1;
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
                    input = -1;
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

void displayUser(User *&userArray, int index)
{
    system("cls");
    std::string userRole;
    if (userArray[index].userType == 0)
    {
        userRole = "HR";
    }
    else if (userArray[index].userType == 1)
    {
        userRole = "Admin";
    }
    else
    {
        userRole = "Tutor";
    }

    std::cout << "User ID: " << userArray[index].id << std::endl;
    std::cout << "Username: " << userArray[index].username << std::endl;
    std::cout << "Password: " << userArray[index].password << std::endl;
    std::cout << "User Type: " << userArray[index].userType << " - " << userRole << std::endl;
}

void searchUser(User *&userArray, int &size)
{
    std::cout << std::endl
              << "Enter the id of the user to search: ";
    int id;
    std::cin >> id;
    while (!std::cin.good() || id < 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter the id of the user to search: ";
        std::cin >> id;
    }
    std::cout << std::endl;
    int index = binarySearch(userArray, size, id);
    if (index == -1)
    {
        std::cout << "User not found." << std::endl;
    }
    else
    {
        displayUser(userArray, index);
    }
    std::cout << std::endl;
}

void addUser(User *&userArray, int &size)
{
    std::string username;
    std::string password;
    unsigned int userType; // 0-HR, 1-Admin, 2- Tutor

    std::cout << "Please enter the following to create a new user account:" << std::endl;
    std::cout << "Enter Username: ";
    std::cin >> username;
    std::cout << "Enter Password: ";
    std::cin >> password;
    std::cout << "Enter User Type (0-HR, 1-Admin, 2- Tutor): ";
    // check for invalid input for userType
    std::cin >> userType;
    while (!std::cin.good() || userType < 0 || userType > 2)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter User Type (0-HR, 1-Admin, 2- Tutor): ";
        std::cin >> userType;
    }

    // create new user
    User *newUser = new User(size, userArray[size - 1].id + 1, username, password, userType);
    createObject(userArray, size, newUser);
    std::cout << "User created successfully" << std::endl
              << std::endl;
}

void updateUser(User *&userArray, int &size)
{
    // prompt for input to fill in constructor
    std::string username;
    std::string password;

    std::cout << "Enter id of user to update: ";
    int id;
    std::cin >> id;
    // check for invalid input for id
    while (!std::cin.good() || id < 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter id of the user to update: ";
        std::cin >> id;
    }
    std::cout << std::endl;
    int index = binarySearch(userArray, size, id);
    if (index != -1)
    {
        std::cout << "Updating user: " << userArray[index].username << std::endl;
        std::cout << "Enter new username: ";
        std::cin >> username;
        std::cout << "Enter new password: ";
        std::cin >> password;
        userArray[index].username = username;
        userArray[index].password = password;
        std::cout << "User updated successfully" << std::endl
                  << std::endl;
    }
    else
    {
        std::cout << "User not found." << std::endl;
    }
    std::cout << std::endl;
}

void deleteUser(User *&userArray, int &size)
{
    std::cout << std::endl
              << "Enter the id of the user to be deleted: ";
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
    int index = binarySearch(userArray, size, id);
    deleteObject(userArray, size, index);
    std::cout << std::endl;
}
