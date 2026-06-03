#include <iostream>
using namespace std;

class School
{
private:
    int schoolCode;
    string schoolName;
    string board;
    int students;

public:
    static int schoolCount;

    // Default constructor
    School()
    {
        schoolCode = 0;
        schoolName = "Unknown";
        board = "Unknown";
        students = 0;
        schoolCount++;
    }

    // Parameterized constructor
    School(int code, string name, string b, int s)
    {
        schoolCode = code;
        schoolName = name;
        board = b;
        students = s;
        schoolCount++;
    }

    // Register school
    void registerSchool()
    {
        cout << "School registered successfully\n";
    }

    // Display school details
    void display()
    {
        cout << "\nSchool Code: " << schoolCode << endl;
        cout << "School Name: " << schoolName << endl;
        cout << "Board: " << board << endl;
        cout << "Total Students: " << students << endl;
    }

    // Static function
    static void showSchools()
    {
        cout << "Total Schools Registered: " << schoolCount << endl;
    }

    // Friend function
    friend void compareStudents(School &, School &);

    // Destructor
    ~School()
    {
        cout << "School record deleted: " << schoolName << endl;
    }
};

// Initialize static variable
int School::schoolCount = 0;


// Friend function definition
void compareStudents(School &s1, School &s2)
{
    if (s1.students > s2.students)
        cout << s1.schoolName << " has more students.\n";
    else if (s1.students < s2.students)
        cout << s2.schoolName << " has more students.\n";
    else
        cout << "Both schools have equal number of students.\n";
}


// Derived class
class Classroom : public School
{
private:
    int classNumber;
    string section;
    int studentStrength;
    string classTeacher;

public:

    // Constructor
    Classroom(int code, string name, string board, int totalStudents,
              int cno, string sec, int strength, string teacher)
        : School(code, name, board, totalStudents)
    {
        classNumber = cno;
        section = sec;
        studentStrength = strength;
        classTeacher = teacher;
    }

    // Accept classroom details
    void acceptClassroom()
    {
        cout << "\nEnter Class Number: ";
        cin >> classNumber;

        cout << "Enter Section: ";
        cin >> section;

        cout << "Enter Student Strength: ";
        cin >> studentStrength;

        cout << "Enter Class Teacher Name: ";
        cin >> classTeacher;
    }

    // Display classroom + school details
    void displayClassroom()
    {
        display(); // Base class function

        cout << "\nClass Number: " << classNumber << endl;
        cout << "Section: " << section << endl;
        cout << "Student Strength: " << studentStrength << endl;
        cout << "Class Teacher: " << classTeacher << endl;
    }

    // Derived class method
    void conductExam()
    {
        cout << "Exam conducted for Class " << classNumber << " Section " << section << endl;
    }
};


int main()
{
    Classroom c1(101, "Green Valley School", "CBSE", 1200,
                 10, "A", 40, "Mrs.Sharma");

    c1.registerSchool();
    c1.displayClassroom();

    School::showSchools();

    c1.conductExam();

    // Creating another object to demonstrate friend function
    School s2(102, "City Public School", "ICSE", 900);

    compareStudents(c1, s2);

    return 0;
}