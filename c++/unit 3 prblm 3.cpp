#include <iostream>
using namespace std;

class Company
{
private:
    int companyID;
    string companyName;
    string industry;

protected:
    int stipendBase;

public:
    static int companyCount;

    // Default constructor
    Company()
    {
        companyID = 0;
        companyName = "Unknown";
        industry = "Unknown";
        stipendBase = 0;
        companyCount++;
    }

    // Parameterized constructor
    Company(int id, string name, string ind, int base)
    {
        companyID = id;
        companyName = name;
        industry = ind;
        stipendBase = base;
        companyCount++;
    }

    // Register company
    void registerCompany()
    {
        cout << "Company registered successfully\n";
    }

    // Display company details
    void display()
    {
        cout << "\nCompany ID: " << companyID << endl;
        cout << "Company Name: " << companyName << endl;
        cout << "Industry: " << industry << endl;
    }

    // Static function
    static void totalCompanies()
    {
        cout << "Total Companies Registered: " << companyCount << endl;
    }

    // Friend function
    friend void calculateStipend(Company &, int);

    // Destructor
    ~Company()
    {
        cout << "Company record archived: " << companyName << endl;
    }
};

// Static variable initialization
int Company::companyCount = 0;


// Friend function definition
void calculateStipend(Company &c, int months)
{
    cout << "Total stipend for internship: " << c.stipendBase * months << endl;
}


// Derived class
class Intern : public Company
{
private:
    int internID;
    string collegeName;
    int internshipDuration;
    int stipend;

public:

    // Constructor
    Intern(int cid, string cname, string ind, int base,
           int iid, string college, int duration, int st)
        : Company(cid, cname, ind, base)
    {
        internID = iid;
        collegeName = college;
        internshipDuration = duration;
        stipend = st;
    }

    // Accept intern details
    void acceptIntern()
    {
        cout << "\nEnter Intern ID: ";
        cin >> internID;

        cout << "Enter College Name: ";
        cin >> collegeName;

        cout << "Enter Internship Duration (months): ";
        cin >> internshipDuration;

        cout << "Enter Stipend: ";
        cin >> stipend;
    }

    // Display intern + company details
    void displayIntern()
    {
        display();   // Base class function

        cout << "\nIntern ID: " << internID << endl;
        cout << "College Name: " << collegeName << endl;
        cout << "Internship Duration: " << internshipDuration << " months\n";
        cout << "Stipend: " << stipend << endl;
    }

    // Assign mentor
    void assignMentor()
    {
        cout << "Mentor assigned to Intern ID " << internID << endl;
    }
};


int main()
{
    Intern i1(201, "TechSoft", "Software Development", 5000,
              101, "MITADT", 6, 5000);

    i1.registerCompany();
    i1.displayIntern();

    Company::totalCompanies();

    calculateStipend(i1, 6);

    i1.assignMentor();

    return 0;
}