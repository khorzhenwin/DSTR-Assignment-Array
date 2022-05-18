#include "pch.h"
#include "functions.h"
#include "user.h"
#include "centre.h"
#include "subject.h"
#include "tutor.h"
#include "archive.h"
#include "dashboard.h"

using namespace std;

void generateMockData(User *&userArray, Subject *&subjectArray, Centre *&centreArray, Tutor *&tutorArray)
{
    // create mock data
    userArray[0] = User(0, 0, "hr1", "123", 0);
    userArray[1] = User(1, 1, "hr2", "123", 0);
    userArray[2] = User(2, 2, "hr3", "123", 0);
    userArray[3] = User(3, 3, "hr4", "123", 0);
    userArray[4] = User(4, 4, "admin1", "123", 1);
    userArray[5] = User(5, 5, "admin2", "123", 1);
    userArray[6] = User(6, 6, "admin3", "123", 1);
    userArray[7] = User(7, 7, "admin4", "123", 1);
    userArray[8] = User(8, 8, "admin5", "123", 1);
    userArray[9] = User(9, 9, "admin6", "123", 1);
    userArray[10] = User(10, 10, "tutor1", "123", 2);
    userArray[11] = User(11, 11, "tutor2", "123", 2);
    userArray[12] = User(12, 12, "tutor3", "123", 2);
    userArray[13] = User(13, 13, "tutor4", "123", 2);
    userArray[14] = User(14, 14, "tutor5", "123", 2);

    subjectArray[0] = Subject(0, 0, "Math", 20);
    subjectArray[1] = Subject(1, 1, "English", 18);
    subjectArray[2] = Subject(2, 2, "Science", 22);
    subjectArray[3] = Subject(3, 3, "History", 16);
    subjectArray[4] = Subject(4, 4, "Music", 15);

    centreArray[0] = Centre(0, 0, "Centre 1", "Bukit Jalil", 4);
    centreArray[1] = Centre(1, 1, "Centre 2", "Sri Petaling", 5);
    centreArray[2] = Centre(2, 2, "Centre 3", "Kuchai Lama", 6);

    tutorArray[0] = Tutor(0, 0, "Alan Doe", "ParkHill, Bukit Jalil", "+60123456789", "15/03/2020", "15/03/2021", 100, 20, 0, 0);
    tutorArray[1] = Tutor(1, 1, "Alfred Wyoming", "Pinnacle, Sri Petaling", "+60123456788", "03/08/2021", "", 80, 20, 0, 1);
    tutorArray[2] = Tutor(2, 2, "Alfonso Lee", "Old Klang Road, Kuchai Lama", "+60123456787", "15/03/2020", "", 95, 20, 0, 2);
    tutorArray[3] = Tutor(3, 3, "Altaria Lim", "SS15, Subang Jaya", "+60123456786", "15/03/2020", "15/03/2021", 75, 20, 0, 3);
    tutorArray[4] = Tutor(4, 4, "Anthony Tan", "Taman OUG, Kuala Lumpur", "+60123456785", "03/08/2021", "", 82, 20, 0, 4);

    tutorArray[5] = Tutor(5, 5, "Benjamin Lim", "ParkHill, Bukit Jalil", "+60123456709", "15/03/2020", "15/03/2021", 100, 20, 1, 0);
    tutorArray[6] = Tutor(6, 6, "Brother John", "Pinnacle, Sri Petaling", "+60123456708", "03/08/2021", "", 80, 20, 1, 1);
    tutorArray[7] = Tutor(7, 7, "Betty Yeet", "Old Klang Road, Kuchai Lama", "+60123456707", "15/03/2020", "", 95, 20, 1, 2);
    tutorArray[8] = Tutor(8, 8, "Brendan Kok", "SS15, Subang Jaya", "+60123456706", "15/03/2020", "15/03/2021", 75, 20, 1, 3);
    tutorArray[9] = Tutor(9, 9, "Bennette Tan", "Taman OUG, Kuala Lumpur", "+60123456705", "03/08/2021", "", 82, 20, 1, 4);

    tutorArray[10] = Tutor(10, 10, "Clarence Tee", "ParkHill, Bukit Jalil", "+60123456719", "15/03/2020", "15/03/2021", 100, 20, 2, 0);
    tutorArray[11] = Tutor(11, 11, "Cassandrea Teo", "Pinnacle, Sri Petaling", "+60123456718", "03/08/2021", "", 80, 20, 2, 1);
    tutorArray[12] = Tutor(12, 12, "Christina Tan", "Old Klang Road, Kuchai Lama", "+60123456717", "15/03/2020", "", 95, 20, 2, 2);
    tutorArray[13] = Tutor(13, 13, "Chrysan Kok", "SS15, Subang Jaya", "+60123456716", "15/03/2020", "15/03/2021", 75, 20, 2, 3);
    tutorArray[14] = Tutor(14, 14, "Coconut Tree", "Taman OUG, Kuala Lumpur", "+60123456715", "03/08/2021", "", 82, 20, 2, 4);
};

void archiveTerminated();

int main()
{
    User *userArray = new User[15];
    Subject *subjectArray = new Subject[5];
    Centre *centreArray = new Centre[5];
    Tutor *tutorArray = new Tutor[15];
    int userArraySize = 15;
    int subjectArraySize = 5;
    int centreArraySize = 3;
    int tutorArraySize = 15;

    generateMockData(userArray, subjectArray, centreArray, tutorArray);

    User userLogin = login(userArray, userArraySize);
    if (userLogin.userType == 0)
    {
        displayHrMenu(userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
    }
    else if (userLogin.userType == 1)
    {
        displayAdminMenu(userLogin.id, userArray, subjectArray, centreArray, tutorArray, userArraySize, subjectArraySize, centreArraySize, tutorArraySize);
    }
    else
    {
    }

    return 0;
}
