#include "student.h"
#include "roster.h"
#include "degree.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
        "A5,Rosa,Perea,perearm@student.laccd.edu,29,60,58,57, SOFTWARE"};
    
    cout << "CS216 " << endl;
    cout << "Rosa Perea" << endl;

    Roster *classRoster = new Roster();
    for(int i = 0; i < 5; i++)
    {
        classRoster -> parse(studentData[i]);
    }

    classRoster->printAll();

    cout<< " Printing invalid emails " << endl;
    classRoster->printInvalidEmails();

    cout << "Print average days in course for the students " << endl;
    for (int i = 0; i < 5; i++)
    {
        Student s = classRoster -> findStudent(i);
        classRoster -> printAverageDaysInCourse(s.getStudentID());
    }

    cout << " Degree Program " << endl;
    classRoster -> printByDegreeProgram(DegreeProgram::SOFTWARE);

    cout << "Removing A3 " << endl;
    classRoster -> remove("A3");
    classRoster->printAll();

    delete classRoster;
    return 0;
}