#include "pch.h"
#include "functions.h"
#include "user.h"
#include "centre.h"
#include "subject.h"
#include "tutor.h"
#include "archive.h"
#include "dashboard.h"

using namespace std;

void generateMockData(User *&userArray)
{
    // create mock data
    userArray[0] = User(0, "admin1", "123", 1);
    userArray[1] = User(1, "admin2", "123", 1);
    userArray[2] = User(2, "hr", "123", 0);
    userArray[3] = User(3, "tutor1", "123", 2);
    userArray[4] = User(4, "tutor2", "123", 2);
};

void archiveTerminated();

int main()
{
    User *user = new User[5];
    int userArraySize = 5;
    generateMockData(user);
    User *newUser = new User(userArraySize, "hr2", "123", 0);
    createObject(user, userArraySize, newUser);
    cout << "User Array Size: " << userArraySize << endl;
    for (int i = 0; i < userArraySize; i++)
    {
        cout << "User ID: " << user[i].id << endl;
        cout << "User Username: " << user[i].username << endl;
        cout << "User Password: " << user[i].password << endl;
        cout << "User Type: " << user[i].userType << endl;
        cout << "----------------------------------------------------" << endl;
    }
}
