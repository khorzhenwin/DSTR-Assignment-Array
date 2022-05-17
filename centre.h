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