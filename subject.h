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