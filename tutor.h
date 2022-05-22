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

void displayTutorsList(Tutor *&tutorArray, int &size, Centre *&centreArray, int &centreArraySize, Subject *&subjectArray, int &subjectArraySize)
{
    int page = 1;
    float ratings;
    int index;
    while (true)
    {
        bool arrayEnd = false;
        system("cls");
        // start
        int start = (page - 1) * 10;
        int end = page * 10;
        std::cout << "Tutor list - Page " << page << std::endl;
        std::cout << std::setw(237) << std::setfill('=') << "" << std::endl;
        std::cout << std::setw(6) << std::setfill(' ') << "No.";
        std::cout << std::setw(11) << std::setfill(' ') << "Tutor ID";
        std::cout << std::setw(21) << std::setfill(' ') << "Tutor Name";
        std::cout << std::setw(31) << std::setfill(' ') << "Tutor Address";
        std::cout << std::setw(16) << std::setfill(' ') << "Phone Number";
        std::cout << std::setw(13) << std::setfill(' ') << "Dated Joined";
        std::cout << std::setw(17) << std::setfill(' ') << "Dated Terminated";
        std::cout << std::setw(11) << std::setfill(' ') << "Ratings";
        std::cout << std::setw(11) << std::setfill(' ') << "Centre ID";
        std::cout << std::setw(26) << std::setfill(' ') << "Centre Name";
        std::cout << std::setw(11) << std::setfill(' ') << "Subject ID";
        std::cout << std::setw(16) << std::setfill(' ') << "Subject Name";
        std::cout << std::setw(17) << std::setfill(' ') << "Hourly Pay Rate" << std::endl;
        std::cout << std::setw(237) << std::setfill('=') << "" << std::endl;
        for (int i = start; i < end; ++i)
        {
            if (i < size)
            {
                if (tutorArray[i].ratingCount == 0)
                {
                    ratings = 0;
                }
                else
                {
                    ratings = float(tutorArray[i].totalRatings) / float(tutorArray[i].ratingCount);
                }
                std::cout << std::setw(5) << std::setfill(' ') << i + 1 << " ";
                std::cout << std::setw(10) << std::setfill(' ') << tutorArray[i].id << " ";
                std::cout << std::setw(20) << std::setfill(' ') << tutorArray[i].tutorName << " ";
                std::cout << std::setw(30) << std::setfill(' ') << tutorArray[i].tutorAddress << " ";
                std::cout << std::setw(15) << std::setfill(' ') << tutorArray[i].tutorPhoneNumber << " ";
                std::cout << std::setw(12) << std::setfill(' ') << tutorArray[i].dateJoined << " ";
                std::cout << std::setw(16) << std::setfill(' ') << tutorArray[i].dateTerminated;
                std::cout << std::setw(10) << std::setfill(' ') << std::fixed << std::setprecision(2) << ratings << " ";
                std::cout << std::setw(10) << std::setfill(' ') << tutorArray[i].centreId << " ";
                index = binarySearch(centreArray, centreArraySize, tutorArray[i].centreId);
                std::cout << std::setw(25) << std::setfill(' ') << centreArray[index].centreName << " ";
                std::cout << std::setw(10) << std::setfill(' ') << tutorArray[i].subjectId << " ";
                index = binarySearch(subjectArray, subjectArraySize, tutorArray[i].subjectId);
                std::cout << std::setw(15) << std::setfill(' ') << subjectArray[index].subjectName << " ";
                std::cout << std::setw(16) << std::setfill(' ') << subjectArray[index].hourlyPayRate << std::endl;
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

void displayTutor(int index, Tutor *&tutorArray, int &tutorArraySize, Centre *&centreArray, int &centreArraySize, Subject *&subjectArray, int &subjectArraySize)
{
    int centreIndex = binarySearch(centreArray, centreArraySize, tutorArray[index].centreId);
    int subjectIndex = binarySearch(subjectArray, subjectArraySize, tutorArray[index].subjectId);

    system("cls");
    std::cout << "Tutor ID: " << tutorArray[index].id << std::endl;
    std::cout << "Tutor Name: " << tutorArray[index].tutorName << std::endl;
    std::cout << "Tutor Address: " << tutorArray[index].tutorAddress << std::endl;
    std::cout << "Tutor Phone Number: " << tutorArray[index].tutorPhoneNumber << std::endl;
    std::cout << "Date Joined: " << tutorArray[index].dateJoined << std::endl;
    std::cout << "Date Terminated: " << tutorArray[index].dateTerminated << std::endl;
    if (tutorArray[index].ratingCount == 0)
    {
        std::cout << "No ratings yet" << std::endl;
    }
    else
    {
        std::cout << "Tutor Rating: " << tutorArray[index].totalRatings / tutorArray[index].ratingCount << std::endl;
    }
    std::cout << "Centre ID: " << centreArray[centreIndex].id << " - " << centreArray[centreIndex].centreName << std::endl;
    std::cout << "Subject ID: " << subjectArray[subjectIndex].id << " - " << subjectArray[subjectIndex].subjectName << std::endl;
    std::cout << "Hourly Pay Rate: " << subjectArray[subjectIndex].hourlyPayRate << std::endl;
    std::cout << std::endl;
}

void searchTutorById(int centreId, Tutor *&tutorArray, int &tutorArraySize, Centre *&centreArray, int &centreArraySize, Subject *&subjectArray, int &subjectArraySize)
{
    std::cout << std::endl
              << "Enter the id of the tutor to search: ";
    int id;
    std::cin >> id;
    while (!std::cin.good() || id < 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter the id of the tutor to search: ";
        std::cin >> id;
    }
    std::cout << std::endl;
    int index = binarySearch(tutorArray, tutorArraySize, id);
    if (index != -1)
    {
        // for HR to view - no restrictions
        if (centreId == -1)
        {
            displayTutor(index, tutorArray, tutorArraySize, centreArray, centreArraySize, subjectArray, subjectArraySize);
        }
        // for admin to view - only show the tutor in the same centre
        else if (centreId != tutorArray[index].centreId)
        {
            std::cout << "Unable to view tutor info from another centre!" << std::endl
                      << std::endl;
            return;
        }
        else
        {
            displayTutor(index, tutorArray, tutorArraySize, centreArray, centreArraySize, subjectArray, subjectArraySize);
        }
    }
    else
    {
        std::cout << "Tutor not found." << std::endl;
    }
    std::cout << std::endl;
}

void addTutor(int adminCentreId, Tutor *&tutorArray, int &tutorArraySize, Centre *&centreArray, int &centreArraySize, Subject *&subjectArray, int &subjectArraySize)
{
    std::string tutorName;
    std::string tutorAddress;
    std::string tutorPhoneNumber;
    std::string dateJoined = getDateToday();
    std::string dateTerminated = "";
    int totalRatings = 0;
    int ratingCount = 0;
    int centreId;
    int subjectId;

    std::cout << "Please enter the following to create a new tutor profile: " << std::endl;
    std::cout << "Tutor Name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, tutorName);
    std::cout << "Tutor Address: ";
    std::getline(std::cin, tutorAddress);
    std::cout << "Tutor Phone Number: ";
    std::getline(std::cin, tutorPhoneNumber);

    // Only prompt for centre ID if HR is trying to add a tutor
    if (adminCentreId == -1)
    {
        std::cout << "Centre ID: ";
        std::cin >> centreId;

        while (!std::cin.good() || centreId < 0 || centreId > centreArray[centreArraySize - 1].id)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again." << std::endl;
            std::cout << "Centre ID: ";
            std::cin >> centreId;
        }
        bool centreFlag = true;
        while (centreFlag)
        {
            int centreIndex = binarySearch(centreArray, centreArraySize, centreId);
            if (centreIndex == -1)
            {
                std::cout << "Centre not found. Please try again." << std::endl;
                std::cout << "Centre ID: ";
                std::cin >> centreId;
            }
            else
            {
                centreFlag = false;
            }
        }
    }
    else
    {
        centreId = adminCentreId;
    }

    std::cout << "Subject ID: ";
    std::cin >> subjectId;
    while (!std::cin.good() || subjectId < 0 || subjectId > subjectArray[subjectArraySize - 1].id)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Subject ID: ";
        std::cin >> subjectId;
    }
    bool subjectFlag = true;
    while (subjectFlag)
    {
        int subjectIndex = binarySearch(subjectArray, subjectArraySize, subjectId);
        if (subjectIndex == -1)
        {
            std::cout << "Subject not found. Please try again." << std::endl;
            std::cout << "Subject ID: ";
            std::cin >> subjectId;
        }
        else
        {
            subjectFlag = false;
        }
    }

    // create a new tutor
    Tutor *newTutor = new Tutor(tutorArraySize, tutorArray[tutorArraySize - 1].id + 1, tutorName, tutorAddress, tutorPhoneNumber, dateJoined, dateTerminated, totalRatings, ratingCount, centreId, subjectId);
    createObject(tutorArray, tutorArraySize, newTutor);
    std::cout << "New tutor profile created successfully" << std::endl
              << std::endl;
}

void updateTutor(int adminCentreId, Tutor *&tutorArray, int &tutorArraySize, Centre *&centreArray, int &centreArraySize, Subject *&subjectArray, int &subjectArraySize)
{
    std::string tutorName;
    std::string tutorAddress;
    std::string tutorPhoneNumber;
    int centreId;
    int subjectId;

    std::cout << "Enter id of tutor to update: ";
    int id;
    std::cin >> id;
    // check for invalid input for id
    while (!std::cin.good() || id < 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter id of the tutor to update: ";
        std::cin >> id;
    }
    std::cout << std::endl;
    int tutorIndex = binarySearch(tutorArray, tutorArraySize, id);

    if (tutorIndex != -1)
    {
        if (adminCentreId != -1 && adminCentreId != tutorArray[tutorIndex].centreId)
        {
            std::cout << "Unable to update tutor info from another centre!" << std::endl
                      << std::endl;
            return;
        }
        std::cout << "Updating tutor: " << tutorArray[tutorIndex].tutorName << std::endl;
        std::cout << "New Tutor Name: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, tutorName);
        std::cout << "New Tutor Address: ";
        std::getline(std::cin, tutorAddress);
        std::cout << "New Tutor Phone Number: ";
        std::getline(std::cin, tutorPhoneNumber);
        if (adminCentreId == -1)
        {
            std::cout << "New Centre ID: ";
            std::cin >> centreId;

            while (!std::cin.good() || centreId < 0 || centreId > centreArray[centreArraySize - 1].id)
            {

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please try again." << std::endl;
                std::cout << "New Centre ID: ";
                std::cin >> centreId;
            }
            bool centreFlag = true;
            while (centreFlag)
            {
                int centreIndex = binarySearch(centreArray, centreArraySize, centreId);
                if (centreIndex == -1)
                {
                    std::cout << "Centre not found. Please try again." << std::endl;
                    std::cout << "New Centre ID: ";
                    std::cin >> centreId;
                }
                else
                {
                    centreFlag = false;
                }
            }
        }
        else
        {
            centreId = adminCentreId;
        }

        std::cout << "New Subject ID: ";
        std::cin >> subjectId;
        while (!std::cin.good() || subjectId < 0 || subjectId > subjectArray[subjectArraySize - 1].id)
        {

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again." << std::endl;
            std::cout << "New Subject ID: ";
            std::cin >> subjectId;
        }
        bool subjectFlag = true;
        while (subjectFlag)
        {
            int subjectIndex = binarySearch(subjectArray, subjectArraySize, subjectId);
            if (subjectIndex == -1)
            {
                std::cout << "Subject not found. Please try again." << std::endl;
                std::cout << "New Subject ID: ";
                std::cin >> subjectId;
            }
            else
            {
                subjectFlag = false;
            }
        }

        // update the tutor
        tutorArray[tutorIndex].tutorName = tutorName;
        tutorArray[tutorIndex].tutorAddress = tutorAddress;
        tutorArray[tutorIndex].tutorPhoneNumber = tutorPhoneNumber;
        tutorArray[tutorIndex].centreId = centreId;
        tutorArray[tutorIndex].subjectId = subjectId;
        std::cout << "Tutor profile updated successfully" << std::endl
                  << std::endl;
    }
    else
    {
        std::cout << "Tutor not found." << std::endl;
    }
    std::cout << std::endl;
}

void deleteTutor(Tutor *&tutorArray, int &tutorArraySize)
{
    std::cout << std::endl
              << "Enter the id of the tutor to be deleted: ";
    int id;
    std::cin >> id;
    // check for invalid input for id
    while (!std::cin.good() || id < 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter the id of the tutor to be deleted: ";
        std::cin >> id;
    }
    std::cout << std::endl;
    int index = binarySearch(tutorArray, tutorArraySize, id);
    deleteObject(tutorArray, tutorArraySize, index);
    std::cout << std::endl;
}

void addRating(int adminCentreId, Tutor *&tutorArray, int &tutorArraySize)
{
    std::cout << "Enter the id of the tutor to rate: ";
    int id;
    std::cin >> id;
    // check for invalid input for id
    while (!std::cin.good() || id < 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter the id of the tutor to rate: ";
        std::cin >> id;
    }
    int tutorIndex = binarySearch(tutorArray, tutorArraySize, id);
    if (tutorIndex == -1)
    {
        std::cout << "Tutor not found. Please try again." << std::endl;
        addRating(adminCentreId, tutorArray, tutorArraySize);
    }
    else
    {
        // if not HR and not in charge of the tutor's centre, cannot rate
        if (adminCentreId != -1 && adminCentreId != tutorArray[tutorIndex].centreId)
        {
            std::cout << "Unable to rate tutor from another centre!" << std::endl
                      << std::endl;
            addRating(adminCentreId, tutorArray, tutorArraySize);
        }
        std::cout << "Currently rating " << tutorArray[tutorIndex].tutorName << "." << std::endl;
        std::cout << "Enter the rating: ";
        int rating;
        std::cin >> rating;
        // check for invalid input for rating
        while (!std::cin.good() || rating < 0 || rating > 5)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please make sure rating are values between 1 and 5." << std::endl;
            std::cout << "Enter the rating: ";
            std::cin >> rating;
        }
        std::cout << std::endl;
        tutorArray[tutorIndex].totalRatings += rating;
        tutorArray[tutorIndex].ratingCount += 1;
        std::cout << "New rating has been added." << std::endl;
    }
}

void terminateTutor(int adminCentreId, Tutor *&tutorArray, int &tutorArraySize)
{
    std::cout << std::endl
              << "Enter the id of the tutor to be terminated: ";
    int id;
    std::cin >> id;
    // check for invalid input for id
    while (!std::cin.good() || id < 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter the id of the tutor to be terminated: ";
        std::cin >> id;
    }
    std::cout << std::endl;
    int tutorIndex = binarySearch(tutorArray, tutorArraySize, id);

    if (tutorIndex != -1)
    {
        // if not HR and not in charge of the tutor's centre, cannot terminate
        if (adminCentreId != -1 && adminCentreId != tutorArray[tutorIndex].centreId)
        {
            std::cout << "Unable to terminate tutor from another centre!" << std::endl
                      << std::endl;
            return;
        }
        else
        {
            if (tutorArray[tutorIndex].dateTerminated == "")
            {
                tutorArray[tutorIndex].dateTerminated = getDateToday();
                std::cout << "Tutor " << tutorArray[tutorIndex].tutorName << " has been terminated on " << tutorArray[tutorIndex].dateTerminated << std::endl;
            }
            else
            {
                std::cout << "Error Occured! Tutor " << tutorArray[tutorIndex].tutorName << " has already been terminated on " << tutorArray[tutorIndex].dateTerminated << std::endl;
            }
        }
    }
    else
    {
        std::cout << "Tutor not found. Please try again." << std::endl;
    }
}

// ---------------------------------------------------------------------------------- Filter Tutors ----------------------------------------------------------------------------------

Tutor *tutorFilterCentre(int centreID, Tutor *tutorArray, int tutorArraySize, int &filteredTutorArraySize)
{
    Tutor *filteredTutorArray = new Tutor[tutorArraySize];
    // filteredTutorArraySize = 0;
    for (int i = 0; i < tutorArraySize; i++)
    {
        if (tutorArray[i].centreId == centreID)
        {
            filteredTutorArray[filteredTutorArraySize] = tutorArray[i];
            filteredTutorArraySize++;
        }
    }
    return filteredTutorArray;
}

Tutor *tutorFilterSubject(int subjectID, Tutor *tutorArray, int tutorArraySize, int &filteredTutorArraySize)
{
    Tutor *filteredTutorArray = new Tutor[tutorArraySize];
    // filteredTutorArraySize = 0;
    for (int i = 0; i < tutorArraySize; i++)
    {
        if (tutorArray[i].subjectId == subjectID)
        {
            filteredTutorArray[filteredTutorArraySize] = tutorArray[i];
            filteredTutorArraySize++;
        }
    }
    return filteredTutorArray;
}

Tutor *tutorFilterRating(int rating, Tutor *tutorArray, int tutorArraySize, int &filteredTutorArraySize)
{
    Tutor *filteredTutorArray = new Tutor[tutorArraySize];
    float currentRatings;
    for (int i = 0; i < tutorArraySize; i++)
    {
        currentRatings = float(tutorArray[i].totalRatings) / float(tutorArray[i].ratingCount);
        if (std::round(currentRatings) == rating)
        {
            filteredTutorArray[filteredTutorArraySize] = tutorArray[i];
            filteredTutorArraySize++;
        }
    }
    return filteredTutorArray;
}

// ---------------------------------------------------------------------------------- Sorting Tutor Functions ----------------------------------------------------------------------------------

Tutor *cloneTutorArray(Tutor *array, int count)
{
    Tutor *ptr = new Tutor[count];
    for (int i = 0; i < count; ++i)
    {
        ptr[i] = array[i];
    }
    return ptr;
}

void swap(Tutor *a, Tutor *b)
{
    Tutor temp = *a;
    *a = *b;
    *b = temp;
}

// ---------------------------------------------------------------------------------- Sort by ratings ----------------------------------------------------------------------------------

int partitionRatings(Tutor *array, int low, int high)
{
    float pivot = float(array[high].totalRatings) / float(array[high].ratingCount);
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if ((float(array[j].totalRatings) / float(array[j].ratingCount)) <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSortRatings(Tutor *array, int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partitionRatings(array, low, high);
        quickSortRatings(array, low, partitionIndex - 1);
        quickSortRatings(array, partitionIndex + 1, high);
    }
}

// ---------------------------------------------------------------------------------- Sort by hourly pay rate ----------------------------------------------------------------------------------

int partitionHourlyPayRate(Tutor *array, int low, int high, Subject *subjectArray, int subjectArraySize)
{
    int pivot = subjectArray[binarySearch(subjectArray, subjectArraySize, array[high].subjectId)].hourlyPayRate;
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (subjectArray[binarySearch(subjectArray, subjectArraySize, array[j].subjectId)].hourlyPayRate <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSortHourlyPayRate(Tutor *array, int low, int high, Subject *subjectArray, int subjectArraySize)
{
    if (low < high)
    {
        int partitionIndex = partitionHourlyPayRate(array, low, high, subjectArray, subjectArraySize);
        quickSortHourlyPayRate(array, low, partitionIndex - 1, subjectArray, subjectArraySize);
        quickSortHourlyPayRate(array, partitionIndex + 1, high, subjectArray, subjectArraySize);
    }
}