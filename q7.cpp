#include <iostream>
using namespace std;
class Student
{
private:
    int stdID;
    string Name;
    string *courseCodes;
    int *courseGrades;
    int numCourses;
    float gpa;

public:
    Student()
    {
        stdID = 0;
        Name = "";
        courseCodes = NULL;
        courseGrades = 0;
        numCourses = 0;
        gpa = 0.0;
    }
    ~Student()
    {
    }
    int getStdID()
    {
        return stdID;
    }
    string getName()
    {
        return Name;
    }
    int getNumCourses()
    {
        return numCourses;
    }
    string getCourseCode(int i)
    {
        return courseCodes[i];
    }
    int getCourseGrade(int i)
    {
        return courseGrades[i];
    }
    float getGPA()
    {
        return gpa;
    }
    void setStdID(int id)
    {
        stdID = id;
    }
    void setName(string firstName)
    {
        Name = firstName;
    }
    void setCourseGrade(string courseCode, int grade)
    {
        for (int i = 0; i < numCourses; i++)
        {
            if (courseCodes[i] == courseCode)
            {
                courseGrades[i] = grade;
                break;
            }
        }
    }
};