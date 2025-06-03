#include "student.h"
#include "degree.h"
class Roster
{
private:
    Student* classRosterArray;
    static int nextIndex;

public:
    Roster();
    ~Roster();

    void add(string studentID, string firstName, string lastName, string emailAddress, int age,
         int daysInCourse, int daysInCourse2, int daysInCourse3, DegreeProgram dp );

    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    Student findStudent(int index);
    void parse(string);
};