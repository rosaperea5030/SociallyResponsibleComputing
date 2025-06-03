
#include <iostream>
#include "degree.h"
#include "student.h"
using namespace std;

void Student::print()
{
    cout << studentID << "\t";
    cout << "First Name: " << firstName << "\t";
    cout << "Last Name: " << lastName << "\t";
    cout << "Age: " << age << "\t";
    cout << "Days in course: {" << daysToComplete[0] << ", " << daysToComplete[1] << ", " <<
    daysToComplete[2] << "} ";
    cout << "Degree Program: " << printDegree(this->getDegreeProgram()) << endl;
}

string Student::printDegree(DegreeProgram dp)
{
    if (dp == SECURITY)
    {
        return "Security";
    }
    else if (dp == NETWORK)
    {
        return "Networking";
    }
    else if (dp == SOFTWARE)
    {
        return "Software";
    }
    else
    {
        return "Unknown";
    }
}