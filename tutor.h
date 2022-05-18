#pragma once
#pragma warning(disable : 4996)
#include "includes.h"

class Tutor
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
    Tutor()
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

    Tutor(int index, int id, std::string tutorName, std::string tutorAddress, std::string tutorPhoneNumber,
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

void filterTutors() {}

void displayTutor() {}

void searchTutorById() {}

void addTutor() {}

void updateTutor() {}

void deleteTutor() {}

void addRating() {}

void terminateTutor() {}
