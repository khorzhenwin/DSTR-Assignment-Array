#pragma once
#include "functions.h"

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
    while (!std::cin.good() || binarySearch(subjectArray, subjectArraySize, subjectId) != -1)
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
    while (!std::cin.good() || binarySearch(centreArray, centreArraySize, centreId) != -1)
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
                   int &userArraySize,
                   int &subjectArraySize,
                   int &centreArraySize,
                   int &tutorArraySize)
{
    int choice, tutorViewChoice, searchTutorChoice;
    std::cout << "1 - Manage Users" << std::endl;
    std::cout << "2 - Manage Centres" << std::endl;
    std::cout << "3 - Manage Subjects" << std::endl;
    std::cout << "4 - Manage Tutors" << std::endl;
    std::cout << "5 - Add Ratings" << std::endl;
    std::cout << "6 - View Tutor Archive" << std::endl;
    std::cout << "7 - Exit Program" << std::endl;

    int input;
    std::cout << "Enter your choice: ";
    std::cin >> input;

    while (!std::cin.good() || input < 1 || input > 7)
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
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
        }
        // search user
        else if (choice == 2)
        {
            searchUser(userArray, userArraySize);
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
        }
        // add user
        else if (choice == 3)
        {
            addUser(userArray, userArraySize);
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
        }
        // edit user
        else if (choice == 4)
        {
            updateUser(userArray, userArraySize);
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
        }
        // delete user
        else if (choice == 5)
        {
            deleteUser(userArray, userArraySize);
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
        }
        else if (choice == 6)
        {
            system("cls");
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
        }
        // ---------------------------------------------------------------------------------- Manage Centres ----------------------------------------------------------------------------------
    case 2:
        choice = manageObject(2);
        // view all centres
        if (choice == 1)
        {
            std::cout << std::endl;
            displayCentreList(centreArray, centreArraySize);
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
        }
        // search centre
        else if (choice == 2)
        {
            searchCentre(centreArray, centreArraySize);
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
        }
        // add Centre
        else if (choice == 3)
        {
            addCentre(centreArray, centreArraySize, userArray, userArraySize);
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
        }
        // edit centre
        else if (choice == 4)
        {
            updateCentre(centreArray, centreArraySize, userArray, userArraySize);
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
        }
        // delete centre
        else if (choice == 5)
        {
            deleteCentre(centreArray, centreArraySize);
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
        }
        else if (choice == 6)
        {
            system("cls");
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
        }
    case 3:
        // ---------------------------------------------------------------------------------- Manage Subjects ----------------------------------------------------------------------------------
        choice = manageObject(3);
        // view all subjects
        if (choice == 1)
        {
            std::cout << std::endl;
            displaySubjectList(subjectArray, subjectArraySize);
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
        }
        // search subject
        else if (choice == 2)
        {
            searchSubject(subjectArray, subjectArraySize);
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
        }
        // add Subject
        else if (choice == 3)
        {
            addSubject(subjectArray, subjectArraySize);
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
        }
        // edit subject
        else if (choice == 4)
        {
            updateSubject(subjectArray, subjectArraySize);
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
        }
        // delete subject
        else if (choice == 5)
        {
            deleteSubject(subjectArray, subjectArraySize);
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
        }
        else if (choice == 6)
        {
            system("cls");
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
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
                displayHrMenu(userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
            }
            // view tutors sorted by hourly pay rate
            else if (tutorViewChoice == 2)
            {
                displayHrMenu(userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
            }
            // view tutors sorted by rating
            else if (tutorViewChoice == 3)
            {
                displayHrMenu(userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
            }
            // back to main menu
            else
            {
                displayHrMenu(userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
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
                displayHrMenu(userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
            }
            // filter by Rating
            else if (searchTutorChoice == 2)
            {
                int ratingFiltered = ratingValidation();
                int filteredTutorArraySize = 0;
                Tutor *filteredTutorArray = tutorFilterRating(ratingFiltered, tutorArray, tutorArraySize, filteredTutorArraySize);
                displayTutorsList(filteredTutorArray, filteredTutorArraySize, centreArray, centreArraySize, subjectArray, subjectArraySize);
                displayHrMenu(userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
            }
            // filter by Subject ID
            else if (searchTutorChoice == 3)
            {
                int centreIDFiltered = centreValidation(centreArray, centreArraySize);
                int filteredTutorArraySize = 0;
                Tutor *filteredTutorArray = tutorFilterSubject(centreIDFiltered, tutorArray, tutorArraySize, filteredTutorArraySize);
                displayTutorsList(filteredTutorArray, filteredTutorArraySize, centreArray, centreArraySize, subjectArray, subjectArraySize);
                displayHrMenu(userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
            }
            // filter by Centre ID
            else if (searchTutorChoice == 4)
            {
                int centreIDFiltered = centreValidation(centreArray, centreArraySize);
                int filteredTutorArraySize = 0;
                Tutor *filteredTutorArray = tutorFilterCentre(centreIDFiltered, tutorArray, tutorArraySize, filteredTutorArraySize);
                displayTutorsList(filteredTutorArray, filteredTutorArraySize, centreArray, centreArraySize, subjectArray, subjectArraySize);
                displayHrMenu(userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
            }
            // back to main menu
            else
            {
                displayHrMenu(userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
            }
        }
        // add Tutor
        else if (choice == 3)
        {
            addTutor(-1, tutorArray, tutorArraySize, centreArray, centreArraySize, subjectArray, subjectArraySize);
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
        }
        // edit tutor
        else if (choice == 4)
        {
            updateTutor(-1, tutorArray, tutorArraySize, centreArray, centreArraySize, subjectArray, subjectArraySize);
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
        }
        // delete tutor
        else if (choice == 5)
        {
            deleteTutor(tutorArray, tutorArraySize);
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
        }
        // terminate tutor
        else if (choice == 6)
        {
            terminateTutor(-1, tutorArray, tutorArraySize);
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
        }
        else if (choice == 7)
        {
            system("cls");
            displayHrMenu(userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
        }
    case 5:
        // ---------------------------------------------------------------------------------- Add Ratings ----------------------------------------------------------------------------------
        addRating(-1, tutorArray, tutorArraySize);
        displayHrMenu(userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
    case 6:
        displayHrMenu(userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
    case 7:
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
                      int &userArraySize,
                      int &subjectArraySize,
                      int &centreArraySize,
                      int &tutorArraySize)
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
                displayAdminMenu(loginID, userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
            }
            // view tutors sorted by hourly pay rate
            else if (tutorViewChoice == 2)
            {
                displayAdminMenu(loginID, userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
            }
            // view tutors sorted by rating
            else if (tutorViewChoice == 3)
            {
                displayAdminMenu(loginID, userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
            }
            else
            {
                displayAdminMenu(loginID, userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
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
                displayAdminMenu(loginID, userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
            }
            // filter by Rating
            else if (searchTutorChoice == 2)
            {
                displayAdminMenu(loginID, userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
            }
            // filter by Subject ID
            else if (searchTutorChoice == 3)
            {
                displayAdminMenu(loginID, userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
            }
            else
            {
                displayAdminMenu(loginID, userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
            }
        }
        // add Tutor
        else if (choice == 3)
        {
            addTutor(centreArray[centreIndex].id, tutorArray, tutorArraySize, centreArray, centreArraySize, subjectArray, subjectArraySize);
            displayAdminMenu(loginID, userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
        }
        // edit tutor
        else if (choice == 4)
        {
            updateTutor(centreArray[centreIndex].id, tutorArray, tutorArraySize, centreArray, centreArraySize, subjectArray, subjectArraySize);
            displayAdminMenu(loginID, userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
        }
        // delete tutor
        else if (choice == 5)
        {
            system("cls");
            std::cout << "The delete function is not accessible by Admins. Please contact HR for support." << std::endl
                      << std::endl;
            displayAdminMenu(loginID, userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
        }
        else if (choice == 6)
        {
            terminateTutor(centreArray[centreIndex].id, tutorArray, tutorArraySize);
            displayAdminMenu(loginID, userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
        }
        else if (choice == 7)
        {
            system("cls");
            displayAdminMenu(loginID, userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
        }
    case 2:
        displayCentre(centreArray, centreIndex);
        displayAdminMenu(loginID, userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
    case 3:
        std::cout << std::endl;
        displaySubjectList(subjectArray, subjectArraySize);
        displayAdminMenu(loginID, userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
    case 4:
        addRating(centreArray[centreIndex].id, tutorArray, tutorArraySize);
        displayAdminMenu(loginID, userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
    case 5:
        displayAdminMenu(loginID, userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
    case 6:
        std::cout << "Exiting program..." << std::endl;
        exit(0);
        break;
        return;
    }
}
