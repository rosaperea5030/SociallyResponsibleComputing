#include "roster.h"
#include "student.h"
#include "degree.h"

#include <iostream>

using namespace std;

int Roster::nextIndex = 0;

Roster::Roster()
{
    classRosterArray = new Student[5];
}

Roster::~Roster()
{
    delete[] classRosterArray;
}

void Roster::parse(string data){
    int records = 0;

    size_t rhs = data.find(",");
    string studentId = data.substr(0, rhs);

    size_t lhs = rhs +1;
    rhs = data.find(",", lhs);
    string firstName = data.substr(lhs, rhs - lhs);

    lhs = rhs +1;
    rhs = data.find(",", lhs);
    string lastName = data.substr(lhs, rhs - lhs);

    lhs = rhs +1;
    rhs = data.find(",", lhs);
    string emailAddress = data.substr(lhs, rhs - lhs);

    lhs = rhs +1;
    rhs = data.find(",", lhs);
    int age = stoi(data.substr(lhs, rhs - lhs));

    lhs = rhs +1;
    rhs = data.find(",", lhs);
    int daysInCourse1 = stoi(data.substr(lhs, rhs - lhs));

    lhs = rhs +1;
    rhs = data.find(",", lhs);
    int daysInCourse2 = stoi(data.substr(lhs, rhs - lhs));

    lhs = rhs +1;
    rhs = data.find(",", lhs);
    int daysInCourse3 = stoi(data.substr(lhs, rhs - lhs));

    lhs = rhs +1;
    rhs = data.find(",", lhs);
    string degreeProgram = data.substr(lhs);

    DegreeProgram degreeProgramOutput = DegreeProgram::SOFTWARE;
    if(degreeProgram == "SECURITY"){
        degreeProgramOutput = DegreeProgram::SECURITY;
    }
    else if (degreeProgram == "NETWORK"){
        degreeProgramOutput = DegreeProgram::NETWORK;
    }
    else if(degreeProgram == "SOFTWARE"){
        degreeProgramOutput = DegreeProgram::SOFTWARE;
    }

    add(studentId, firstName, lastName, emailAddress, age, daysInCourse1,
    daysInCourse2, daysInCourse3, degreeProgramOutput);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age,
    int daysInCourse, int daysInCourse2, int daysInCourse3, DegreeProgram dp){
        int days[3] = {daysInCourse, daysInCourse2, daysInCourse3};

        Student s(studentID, firstName, lastName, emailAddress, age, days, dp);
        classRosterArray[nextIndex++] = s;

    }

void Roster::remove(string studentID){
    for (int i = 0; i < 5; i++){
        Student s = classRosterArray[i];
        if (s.getStudentID() == studentID){
            classRosterArray[i].setStudentID("Invalid");
            return;
        }
    }
    cout << "Student with id " << studentID <<" not found"<<endl;
}

void Roster::printAll() {
    for (int i = 0; i < 5; i++){
        Student s = classRosterArray[i];
        if (s.getStudentID() != "Invalid") {
            s.print();
        }
    }
}

void Roster::printAverageDaysInCourse(string studentID) {
    int days[3];
    for (int i = 0; i < 5; i++) {
        Student s = classRosterArray[i];
        if (s.getStudentID() == studentID) {
            days[0] = s.getDaysToComplete()[0];
            days[1] = s.getDaysToComplete()[1];
            days[2] = s.getDaysToComplete()[2];

            int total = days[0] + days[1] + days[2];
            cout << "Average days in course = " << total/3.0 << endl;
            return;
        }
    }
}

Student Roster::findStudent(int i){
    return classRosterArray[i];
}

void Roster::printInvalidEmails(){
    for(int i = 0; i < 5; i++){
        string email = classRosterArray[i].getEmailAddress();

        if ( email.find('.') == string::npos){
            cout << "Invalid email " << email << endl;
        }
        else if ( email.find('@') == string::npos){
            cout << "Invalid email " << email << endl;
        }
        else if ( email.find(' ') != string::npos){
            cout << "Invalid email " << email << endl;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram dp){
    for (int i = 0; i < 5; i++){
        Student s = classRosterArray[i];
        if (s.getDegreeProgram() == dp)
        {
            s.print();
        }
    }
}