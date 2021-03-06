#pragma once
#include "functions.h"

void generateReport(User *userArray,
                    Subject *subjectArray,
                    Centre *centreArray,
                    Tutor *tutorArray,
                    Archive *archiveArray,
                    int &userArraySize,
                    int &subjectArraySize,
                    int &centreArraySize,
                    int &tutorArraySize,
                    int &archiveArraySize)
{
    system("cls");
    int activeTutors = 0;

    for (int i = 0; i < tutorArraySize; ++i)
    {
        if (tutorArray[i].dateTerminated == "")
        {
            activeTutors++;
        }
    }

    std::cout << "eXcel Tuition Centre Report on " << getDateToday() << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "Total number of users: " << userArraySize << std::endl;
    std::cout << "Total number of centres: " << centreArraySize << std::endl;
    std::cout << "Total number of subjects: " << subjectArraySize << std::endl;
    std::cout << "Total number of tutors " << std::endl;
    std::cout << "   Active: " << activeTutors << std::endl;
    std::cout << "   Terminated: " << tutorArraySize - activeTutors << std::endl;
    std::cout << "   Archived: " << archiveArraySize << std::endl;
    std::cout << std::endl
              << "-----------------------------------------------------" << std::endl;
    std::cout << "Centre Details" << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;

    int activeTutorsByCentre = 0;
    int terminatedTutorsByCentre = 0;
    int activeTutorsBySubject = 0;
    int terminatedTutorsBySubject = 0;

    for (int i = 0; i < centreArraySize; ++i)
    {
        std::cout << std::endl
                  << "-----------------------------------------------------" << std::endl;
        std::cout << "Centre Name : " << centreArray[i].centreName << std::endl;
        std::cout << "-----------------------------------------------------" << std::endl;
        std::cout << "   Tutors by Subjects" << std::endl;
        for (int s = 0; s < subjectArraySize; ++s)
        {
            for (int t = 0; t < tutorArraySize; ++t)
            {
                if (tutorArray[t].centreId == centreArray[i].id && tutorArray[t].dateTerminated == "" && tutorArray[t].subjectId == subjectArray[s].id)
                {
                    activeTutorsBySubject++;
                    activeTutorsByCentre++;
                }
                else if (tutorArray[t].centreId == centreArray[i].id && tutorArray[t].dateTerminated != "" && tutorArray[t].subjectId == subjectArray[s].id)
                {
                    terminatedTutorsBySubject++;
                    terminatedTutorsByCentre++;
                }
            }
            //------ print out statements for each subject here ------
            std::cout << "      Subject Name : " << subjectArray[s].subjectName << std::endl;
            std::cout << "         Active Tutors: " << activeTutorsBySubject << std::endl;
            std::cout << "         Terminated Tutors: " << terminatedTutorsBySubject << std::endl;
            std::cout << "-----------------------------------------------------" << std::endl;
            // reset for next iteration
            activeTutorsBySubject = 0;
            terminatedTutorsBySubject = 0;
        }
        //------ print out statements for each centre here ------
        std::cout << "Total Tutors in Centre" << std::endl;
        std::cout << "   Active: " << activeTutorsByCentre << std::endl;
        std::cout << "   Terminated: " << terminatedTutorsByCentre << std::endl;
        std::cout << "-----------------------------------------------------" << std::endl
                  << std::endl;
        // re-initializing for next iteration
        activeTutorsByCentre = 0;
        terminatedTutorsByCentre = 0;
    }
    std::cout << std::endl
              << std::endl
              << std::endl;
}

int manageObject(int choice)
{
    std::string object = "";
    if (choice == 1)
    {
        object = "User";
    }
    else if (choice == 2)
    {
        object = "Centre";
    }
    else if (choice == 3)
    {
        object = "Subject";
    }
    else if (choice == 4)
    {
        object = "Tutor";
    }
    system("cls");
    // view user
    std::cout << "1 - View All " << object << "s" << std::endl;
    // search user
    std::cout << "2 - Search " << object << std::endl;
    // add user
    std::cout << "3 - Add " << object << std::endl;
    // edit user
    std::cout << "4 - Edit " << object << std::endl;
    // delete user
    std::cout << "5 - Delete " << object << std::endl;
    if (choice == 4)
    {
        // terminate tutor
        std::cout << "6 - Terminate Tutor" << std::endl;
        // exit
        std::cout << "7 - Back" << std::endl;
    }
    else
    {
        // exit
        std::cout << "6 - Back" << std::endl;
    }

    int input;
    std::cout << "Enter your choice: ";
    std::cin >> input;

    if (choice == 4)
    {
        while (!std::cin.good() || input < 1 || input > 7)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again." << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> input;
        }
    }
    else
    {
        while (!std::cin.good() || input < 1 || input > 6)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again." << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> input;
        }
    }
    return input;
}

int viewTutorSorted()
{
    system("cls");
    std::cout << "1 - View Tutors sorted by ID" << std::endl;
    std::cout << "2 - View Tutors sorted by Hourly Pay Rate" << std::endl;
    std::cout << "3 - View Tutors sorted by Rating" << std::endl;
    std::cout << "4 - Back" << std::endl;

    int input;
    std::cout << "Enter your choice: ";
    std::cin >> input;

    while (!std::cin.good() || input < 1 || input > 4)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> input;
    }
    return input;
}

int searchTutorDashboard(int userType)
{
    system("cls");
    std::cout << "1 - Search Tutor by ID" << std::endl;
    std::cout << "2 - Filter Tutors by Rating" << std::endl;
    std::cout << "3 - Filter Tutors by Subject ID" << std::endl;
    if (userType == 0)
    {
        std::cout << "4 - Filter Tutors by Centre ID" << std::endl;
        std::cout << "5 - Back" << std::endl;
    }
    else
    {
        std::cout << "4 - Back" << std::endl;
    }

    int input;
    std::cout << "Enter your choice: ";
    std::cin >> input;

    if (userType == 0)
    {
        while (!std::cin.good() || input < 1 || input > 5)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again." << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> input;
        }
    }
    else
    {
        while (!std::cin.good() || input < 1 || input > 4)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again." << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> input;
        }
    }
    return input;
}

int ratingValidation()
{
    int rating;
    std::cout << "Enter your rating: ";
    std::cin >> rating;
    while (!std::cin.good() || rating < 1 || rating > 5)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter your rating: ";
        std::cin >> rating;
    }
    return rating;
}

int subjectValidation(Subject *&subjectArray, int &subjectArraySize)
{
    int subjectId;
    std::cout << "Enter your subject ID: ";
    std::cin >> subjectId;
    while (!std::cin.good() || binarySearch(subjectArray, subjectArraySize, subjectId) == -1)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter your subject ID: ";
        std::cin >> subjectId;
    }
    return subjectId;
}

int centreValidation(Centre *&centreArray, int &centreArraySize)
{
    int centreId;
    std::cout << "Enter your centre ID: ";
    std::cin >> centreId;
    while (!std::cin.good() || binarySearch(centreArray, centreArraySize, centreId) == -1)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter your centre ID: ";
        std::cin >> centreId;
    }
    return centreId;
}
// ---------------------------------------------- Dashboards ----------------------------------------------
void displayHrMenu(User *userArray,
                   Subject *subjectArray,
                   Centre *centreArray,
                   Tutor *tutorArray,
                   Archive *archiveArray,
                   int &userArraySize,
                   int &subjectArraySize,
                   int &centreArraySize,
                   int &tutorArraySize,
                   int &archiveArraySize)
{
    int choice, tutorViewChoice, searchTutorChoice;
    std::cout << "1 - Manage Users" << std::endl;
    std::cout << "2 - Manage Centres" << std::endl;
    std::cout << "3 - Manage Subjects" << std::endl;
    std::cout << "4 - Manage Tutors" << std::endl;
    std::cout << "5 - Add Ratings" << std::endl;
    std::cout << "6 - View Tutor Archive" << std::endl;
    std::cout << "7 - Generate Report" << std::endl;
    std::cout << "8 - Exit Program" << std::endl;

    int input;
    std::cout << "Enter your choice: ";
    std::cin >> input;

    while (!std::cin.good() || input < 1 || input > 8)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> input;
    }

    switch (input)
    {
        // ---------------------------------------------------------------------------------- Manage Users ----------------------------------------------------------------------------------
    case 1:
        choice = manageObject(1);
        // view all users
        if (choice == 1)
        {
            std::cout << std::endl;
            displayUserList(userArray, userArraySize);
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
        }
        // search user
        else if (choice == 2)
        {
            searchUser(userArray, userArraySize);
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
        }
        // add user
        else if (choice == 3)
        {
            addUser(userArray, userArraySize);
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
        }
        // edit user
        else if (choice == 4)
        {
            updateUser(userArray, userArraySize);
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
        }
        // delete user
        else if (choice == 5)
        {
            deleteUser(userArray, userArraySize);
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
        }
        else if (choice == 6)
        {
            system("cls");
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
        }
        // ---------------------------------------------------------------------------------- Manage Centres ----------------------------------------------------------------------------------
    case 2:
        choice = manageObject(2);
        // view all centres
        if (choice == 1)
        {
            std::cout << std::endl;
            displayCentreList(centreArray, centreArraySize);
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
        }
        // search centre
        else if (choice == 2)
        {
            searchCentre(centreArray, centreArraySize);
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
        }
        // add Centre
        else if (choice == 3)
        {
            addCentre(centreArray, centreArraySize, userArray, userArraySize);
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
        }
        // edit centre
        else if (choice == 4)
        {
            updateCentre(centreArray, centreArraySize, userArray, userArraySize);
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
        }
        // delete centre
        else if (choice == 5)
        {
            deleteCentre(centreArray, centreArraySize);
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
        }
        else if (choice == 6)
        {
            system("cls");
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
        }
    case 3:
        // ---------------------------------------------------------------------------------- Manage Subjects ----------------------------------------------------------------------------------
        choice = manageObject(3);
        // view all subjects
        if (choice == 1)
        {
            std::cout << std::endl;
            displaySubjectList(subjectArray, subjectArraySize);
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
        }
        // search subject
        else if (choice == 2)
        {
            searchSubject(subjectArray, subjectArraySize);
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
        }
        // add Subject
        else if (choice == 3)
        {
            addSubject(subjectArray, subjectArraySize);
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
        }
        // edit subject
        else if (choice == 4)
        {
            updateSubject(subjectArray, subjectArraySize);
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
        }
        // delete subject
        else if (choice == 5)
        {
            deleteSubject(subjectArray, subjectArraySize);
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
        }
        else if (choice == 6)
        {
            system("cls");
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
        }
    case 4:
        // ---------------------------------------------------------------------------------- Manage Tutors ----------------------------------------------------------------------------------
        choice = manageObject(4);
        // view all tutors
        if (choice == 1)
        {
            tutorViewChoice = viewTutorSorted();
            system("cls");
            // view tutors sorted by ID
            if (tutorViewChoice == 1)
            {
                displayTutorsList(tutorArray, tutorArraySize, centreArray, centreArraySize, subjectArray, subjectArraySize);
                displayHrMenu(userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
            }
            // view tutors sorted by hourly pay rate
            else if (tutorViewChoice == 2)
            {
                Tutor *sortedTutorArray = cloneTutorArray(tutorArray, tutorArraySize);
                quickSortHourlyPayRate(sortedTutorArray, 0, tutorArraySize - 1, subjectArray, subjectArraySize);
                displayTutorsList(sortedTutorArray, tutorArraySize, centreArray, centreArraySize, subjectArray, subjectArraySize);
                displayHrMenu(userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
            }
            // view tutors sorted by rating
            else if (tutorViewChoice == 3)
            {
                Tutor *sortedTutorArray = cloneTutorArray(tutorArray, tutorArraySize);
                quickSortRatings(sortedTutorArray, 0, tutorArraySize - 1);
                displayTutorsList(sortedTutorArray, tutorArraySize, centreArray, centreArraySize, subjectArray, subjectArraySize);
                displayHrMenu(userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
            }
            // back to main menu
            else
            {
                displayHrMenu(userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
            }
        }
        // search tutor
        else if (choice == 2)
        {
            searchTutorChoice = searchTutorDashboard(0);
            system("cls");
            // search tutor by ID
            if (searchTutorChoice == 1)
            {
                searchTutorById(-1, tutorArray, tutorArraySize, centreArray, centreArraySize, subjectArray, subjectArraySize);
                displayHrMenu(userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
            }
            // filter by Rating
            else if (searchTutorChoice == 2)
            {
                int ratingFiltered = ratingValidation();
                int filteredTutorArraySize = 0;
                Tutor *filteredTutorArray = tutorFilterRating(ratingFiltered, tutorArray, tutorArraySize, filteredTutorArraySize);
                displayTutorsList(filteredTutorArray, filteredTutorArraySize, centreArray, centreArraySize, subjectArray, subjectArraySize);
                displayHrMenu(userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
            }
            // filter by Subject ID
            else if (searchTutorChoice == 3)
            {
                int subjectIDFiltered = subjectValidation(subjectArray, subjectArraySize);
                int filteredTutorArraySize = 0;
                Tutor *filteredTutorArray = tutorFilterSubject(subjectIDFiltered, tutorArray, tutorArraySize, filteredTutorArraySize);
                displayTutorsList(filteredTutorArray, filteredTutorArraySize, centreArray, centreArraySize, subjectArray, subjectArraySize);
                displayHrMenu(userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
            }
            // filter by Centre ID
            else if (searchTutorChoice == 4)
            {
                int centreIDFiltered = centreValidation(centreArray, centreArraySize);
                int filteredTutorArraySize = 0;
                Tutor *filteredTutorArray = tutorFilterCentre(centreIDFiltered, tutorArray, tutorArraySize, filteredTutorArraySize);
                displayTutorsList(filteredTutorArray, filteredTutorArraySize, centreArray, centreArraySize, subjectArray, subjectArraySize);
                displayHrMenu(userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
            }
            // back to main menu
            else
            {
                displayHrMenu(userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
            }
        }
        // add Tutor
        else if (choice == 3)
        {
            addTutor(-1, tutorArray, tutorArraySize, centreArray, centreArraySize, subjectArray, subjectArraySize);
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
        }
        // edit tutor
        else if (choice == 4)
        {
            updateTutor(-1, tutorArray, tutorArraySize, centreArray, centreArraySize, subjectArray, subjectArraySize);
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
        }
        // delete tutor
        else if (choice == 5)
        {
            deleteTutor(tutorArray, tutorArraySize);
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
        }
        // terminate tutor
        else if (choice == 6)
        {
            terminateTutor(-1, tutorArray, tutorArraySize);
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
        }
        else if (choice == 7)
        {
            system("cls");
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
        }
    case 5:
        // ---------------------------------------------------------------------------------- Add Ratings ----------------------------------------------------------------------------------
        addRating(-1, tutorArray, tutorArraySize);
        displayHrMenu(userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
    case 6:
        displayArchiveList(archiveArray, archiveArraySize);
        displayHrMenu(userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
    case 7:
        generateReport(userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
        displayHrMenu(userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
    case 8:
        std::cout << "Exiting program..." << std::endl;
        exit(0);
        break;
        return;
    }
}

void displayAdminMenu(int loginID,
                      User *userArray,
                      Subject *subjectArray,
                      Centre *centreArray,
                      Tutor *tutorArray,
                      Archive *archiveArray,
                      int &userArraySize,
                      int &subjectArraySize,
                      int &centreArraySize,
                      int &tutorArraySize,
                      int &archiveArraySize)
{
    int choice, tutorViewChoice, searchTutorChoice;
    int centreIndex = linearSearchCentre(centreArray, centreArraySize, loginID);
    std::cout << "1 - Manage Tutors" << std::endl;
    std::cout << "2 - View Centre Details" << std::endl;
    std::cout << "3 - View All Subjects" << std::endl;
    std::cout << "4 - Add Ratings" << std::endl;
    std::cout << "5 - View Tutor Archive" << std::endl;
    std::cout << "6 - Exit Program" << std::endl;

    int input;
    std::cout << "Enter your choice: ";
    std::cin >> input;

    while (!std::cin.good() || input < 1 || input > 6)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> input;
    }

    switch (input)
    {
    // ---------------------------------------------------------------------------------- Manage Tutors ----------------------------------------------------------------------------------
    case 1:
        choice = manageObject(4);
        // view all tutors
        if (choice == 1)
        {
            tutorViewChoice = viewTutorSorted();
            system("cls");
            // view tutors sorted by ID
            if (tutorViewChoice == 1)
            {
                int filteredTutorArraySize = 0;
                Tutor *filteredTutorArray = tutorFilterCentre(centreArray[centreIndex].id, tutorArray, tutorArraySize, filteredTutorArraySize);
                displayTutorsList(filteredTutorArray, filteredTutorArraySize, centreArray, centreArraySize, subjectArray, subjectArraySize);
                displayAdminMenu(loginID, userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
            }
            // view tutors sorted by hourly pay rate
            else if (tutorViewChoice == 2)
            {
                Tutor *sortedTutorArray = cloneTutorArray(tutorArray, tutorArraySize);
                quickSortHourlyPayRate(sortedTutorArray, 0, tutorArraySize - 1, subjectArray, subjectArraySize);
                int centreFilteredSortedTutorArraySize = 0;
                Tutor *centreFilteredSortedTutorArray = tutorFilterCentre(centreArray[centreIndex].id, sortedTutorArray, tutorArraySize, centreFilteredSortedTutorArraySize);
                displayTutorsList(centreFilteredSortedTutorArray, centreFilteredSortedTutorArraySize, centreArray, centreArraySize, subjectArray, subjectArraySize);
                displayAdminMenu(loginID, userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
            }
            // view tutors sorted by rating
            else if (tutorViewChoice == 3)
            {
                Tutor *sortedTutorArray = cloneTutorArray(tutorArray, tutorArraySize);
                quickSortRatings(sortedTutorArray, 0, tutorArraySize - 1);
                int centreFilteredSortedTutorArraySize = 0;
                Tutor *centreFilteredSortedTutorArray = tutorFilterCentre(centreArray[centreIndex].id, sortedTutorArray, tutorArraySize, centreFilteredSortedTutorArraySize);
                displayTutorsList(centreFilteredSortedTutorArray, centreFilteredSortedTutorArraySize, centreArray, centreArraySize, subjectArray, subjectArraySize);
                displayAdminMenu(loginID, userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
            }
            else
            {
                displayAdminMenu(loginID, userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
            }
        }
        // search tutor
        else if (choice == 2)
        {
            searchTutorChoice = searchTutorDashboard(1);
            system("cls");
            // search tutor by ID
            if (searchTutorChoice == 1)
            {
                searchTutorById(centreArray[centreIndex].id, tutorArray, tutorArraySize, centreArray, centreArraySize, subjectArray, subjectArraySize);
                displayAdminMenu(loginID, userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
            }
            // filter by Rating
            else if (searchTutorChoice == 2)
            {
                int centreFilteredTutorArraySize = 0;
                Tutor *centreFilteredTutorArray = tutorFilterCentre(centreArray[centreIndex].id, tutorArray, tutorArraySize, centreFilteredTutorArraySize);
                int ratingFiltered = ratingValidation();
                int filteredTutorArraySize = 0;
                Tutor *filteredTutorArray = tutorFilterRating(ratingFiltered, centreFilteredTutorArray, centreFilteredTutorArraySize, filteredTutorArraySize);
                displayTutorsList(filteredTutorArray, filteredTutorArraySize, centreArray, centreArraySize, subjectArray, subjectArraySize);
                displayAdminMenu(loginID, userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
            }
            // filter by Subject ID
            else if (searchTutorChoice == 3)
            {
                int centreFilteredTutorArraySize = 0;
                Tutor *centreFilteredTutorArray = tutorFilterCentre(centreArray[centreIndex].id, tutorArray, tutorArraySize, centreFilteredTutorArraySize);
                int subjectIDFiltered = subjectValidation(subjectArray, subjectArraySize);
                int filteredTutorArraySize = 0;
                Tutor *filteredTutorArray = tutorFilterSubject(subjectIDFiltered, centreFilteredTutorArray, centreFilteredTutorArraySize, filteredTutorArraySize);
                displayTutorsList(filteredTutorArray, filteredTutorArraySize, centreArray, centreArraySize, subjectArray, subjectArraySize);
                displayAdminMenu(loginID, userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
            }
            else
            {
                displayAdminMenu(loginID, userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
            }
        }
        // add Tutor
        else if (choice == 3)
        {
            addTutor(centreArray[centreIndex].id, tutorArray, tutorArraySize, centreArray, centreArraySize, subjectArray, subjectArraySize);
            displayAdminMenu(loginID, userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
        }
        // edit tutor
        else if (choice == 4)
        {
            updateTutor(centreArray[centreIndex].id, tutorArray, tutorArraySize, centreArray, centreArraySize, subjectArray, subjectArraySize);
            displayAdminMenu(loginID, userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
        }
        // delete tutor
        else if (choice == 5)
        {
            system("cls");
            std::cout << "The delete function is not accessible by Admins. Please contact HR for support." << std::endl
                      << std::endl;
            displayAdminMenu(loginID, userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
        }
        else if (choice == 6)
        {
            terminateTutor(centreArray[centreIndex].id, tutorArray, tutorArraySize);
            displayAdminMenu(loginID, userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
        }
        else if (choice == 7)
        {
            system("cls");
            displayAdminMenu(loginID, userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
        }
    case 2:
        displayCentre(centreArray, centreIndex);
        displayAdminMenu(loginID, userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
    case 3:
        std::cout << std::endl;
        displaySubjectList(subjectArray, subjectArraySize);
        displayAdminMenu(loginID, userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
    case 4:
        addRating(centreArray[centreIndex].id, tutorArray, tutorArraySize);
        displayAdminMenu(loginID, userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
    case 5:
        displayArchiveList(archiveArray, archiveArraySize);
        displayAdminMenu(loginID, userArray, subjectArray, centreArray, tutorArray, archiveArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize, archiveArraySize);
    case 6:
        std::cout << "Exiting program..." << std::endl;
        exit(0);
        break;
        return;
    }
}

void displayTutorMenu(int loginID,
                      User *userArray,
                      Subject *subjectArray,
                      Centre *centreArray,
                      Tutor *tutorArray,
                      int &userArraySize,
                      int &subjectArraySize,
                      int &centreArraySize,
                      int &tutorArraySize)
{
    int userIndex = binarySearch(userArray, userArraySize, loginID);
    int tutorId = std::stoi(userArray[userIndex].username);
    int tutorIndex = binarySearch(tutorArray, tutorArraySize, tutorId);
    int centreId = tutorArray[tutorIndex].centreId;
    int subjectId = tutorArray[tutorIndex].subjectId;
    int centreIndex = binarySearch(centreArray, centreArraySize, centreId);
    int subjectIndex = binarySearch(subjectArray, subjectArraySize, subjectId);

    std::cout << "1 - View Centre Details" << std::endl;
    std::cout << "2 - View Subject Details" << std::endl;
    std::cout << "3 - View Tutor Details" << std::endl;
    std::cout << "4 - Exit Program" << std::endl;

    int input;
    std::cout << "Enter your choice: ";
    std::cin >> input;

    while (!std::cin.good() || input < 1 || input > 4)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> input;
    }

    switch (input)
    {
    case 1:
        displayCentre(centreArray, centreIndex);
        displayTutorMenu(loginID, userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
    case 2:
        displaySubject(subjectArray, subjectIndex);
        displayTutorMenu(loginID, userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
    case 3:
        displayTutor(tutorIndex, tutorArray, tutorArraySize, centreArray, centreArraySize, subjectArray, subjectArraySize);
        displayTutorMenu(loginID, userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
    case 4:
        std::cout << "Exiting program..." << std::endl;
        exit(0);
        break;
        return;
    }
}