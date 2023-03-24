#include <iostream>
using namespace std;
class Student
{
private:
    int stdID;
    string Name;
    string *courseCodes;
    int numCourses;
    int *courseGrades;
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
        int i = 0;
        while (courseCodes[i] != courseCode)
        {
            i++;
        }
        courseGrades[i] = grade;
    }
    void addCourse(string courseCode, int grade)
    {
        numCourses++;
        courseCodes[numCourses] = courseCode;
        courseGrades[numCourses] = grade;
    }
    void calcGPA()
    {
        float GPA;
        for (int i = 0; courseCodes[i] == courseCodes[numCourses]; i++)
        {
            GPA = GPA + courseGrades[i];
        }
        gpa = GPA / numCourses;
    }
};

Student getStudentAt(Student students[], int index)
{
    Student StudentAt;
    StudentAt = students[index];
    return StudentAt;
}
float calcClassGPA(Student students[], int numStudents)
{
    float classGPA;
    for (int i = 0; i < numStudents; i++)
    {
        classGPA = classGPA + students[i].getGPA();
    }
    float avgCLassGPA;
    avgCLassGPA = classGPA / numStudents;
    return avgCLassGPA;
}
float getMaxGPA(Student students[], int numStudents)
{
    float MaxGPA = -1;
    for (int i = 0; i < numStudents; i++)
    {
        if (MaxGPA < students[i].getGPA())
        {
            MaxGPA = students[i].getGPA();
        }
    }
    return MaxGPA;
}
float getMinGPA(Student students[], int numStudents)
{

    float MinGPA = -1;
    for (int i = 0; i < numStudents; i++)
    {
        if (MinGPA > students[i].getGPA())
        {
            MinGPA = students[i].getGPA();
        }
    }
    return MinGPA;
}
void printStudentRecord(Student student)
{
    cout << "Student ID: " << student.getStdID() << endl;
    cout << "Name: " << student.getName() << endl;
    for (int i = 0; i < student.getNumCourses(); i++)
    {
        cout << "Course code: " << student.getCourseCode(i);
        cout << ", Grade: " << student.getCourseGrade(i);
    }
    cout << "GPA" << student.getGPA();
}
void printAllStudentRecords(Student students[], int numStudents)
{
    for (int i = 0; i < numStudents; i++)
    {
        cout << "Student ID: " << students[i].getStdID() << endl;
        cout << "Name: " << students[i].getName() << endl;
        for (int j = 0; j < students[i].getNumCourses(); j++)
        {
            cout << "Course code: " << students[i].getCourseCode(j);
            cout << ", Grade: " << students[i].getCourseGrade(j);
        }
        cout << "GPA" << students[i].getGPA();
    }
}