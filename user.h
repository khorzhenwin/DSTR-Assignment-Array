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
