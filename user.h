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

void displayUserList(User *&userArray, int &size, int page)
{
    system("cls");
    std::string userRole;
    // paginate the list
    int pageSize = 10;
    int totalPages = (size / pageSize) + 1;
    int pageStart = (page - 1) * pageSize;
    int pageEnd = page * pageSize;
    if (pageEnd > size)
    {
        pageEnd = size;
    }
    // display the list
    std::cout << "User List" << std::endl;
    std::cout << "Page " << page << " of " << totalPages << std::endl;
    std::cout << "No.\tID\tUsername\tUser Type" << std::endl
              << std::endl;
    for (int i = pageStart; i < pageEnd; i++)
    {
        if (userArray[i].userType == 0)
        {
            userRole = "HR";
        }
        else if (userArray[i].userType == 1)
        {
            userRole = "Admin";
        }
        else
        {
            userRole = "Tutor";
        }
        std::cout << i + 1 << "\t" << userArray[i].id << "\t" << userArray[i].username << "\t\t" << userArray[i].userType << " - " << userRole << std::endl;
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
    displayUserList(userArray, size, page);
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
