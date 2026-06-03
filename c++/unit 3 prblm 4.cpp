#include <iostream>
using namespace std;

class Library
{
protected:
    int libraryID;
    string libraryName;
    string city;

public:
    static int libraryCount;

    // Parameterized constructor
    Library(int id, string name, string c)
    {
        libraryID = id;
        libraryName = name;
        city = c;
        libraryCount++;
    }

    // Copy constructor
    Library(const Library &l)
    {
        libraryID = l.libraryID;
        libraryName = l.libraryName;
        city = l.city;
        libraryCount++;
    }

    // Register library
    void registerLibrary()
    {
        cout << "Library registered successfully\n";
    }

    // Display library details
    void display()
    {
        cout << "\nLibrary ID: " << libraryID << endl;
        cout << "Library Name: " << libraryName << endl;
        cout << "City: " << city << endl;
    }

    // Static function
    static void showLibraries()
    {
        cout << "Total Libraries Registered: " << libraryCount << endl;
    }

    // Operator overloading (==)
    bool operator==(Library &l)
    {
        if (city == l.city)
            return true;
        else
            return false;
    }

    // Destructor
    ~Library()
    {
        cout << "Library record closed: " << libraryName << endl;
    }
};

// Static variable initialization
int Library::libraryCount = 0;


// Derived class
class Magazine : public Library
{
private:
    string magazineTitle;
    int issueNumber;
    string publisher;
    int monthlyCirculation;

public:

    // Constructor
    Magazine(int id, string name, string c,
             string title, int issue, string pub, int circulation)
        : Library(id, name, c)
    {
        magazineTitle = title;
        issueNumber = issue;
        publisher = pub;
        monthlyCirculation = circulation;
    }

    // Accept magazine details
    void acceptMagazine()
    {
        cout << "\nEnter Magazine Title: ";
        cin >> magazineTitle;

        cout << "Enter Issue Number: ";
        cin >> issueNumber;

        cout << "Enter Publisher: ";
        cin >> publisher;

        cout << "Enter Monthly Circulation: ";
        cin >> monthlyCirculation;
    }

    // Display magazine + library details
    void displayMagazine()
    {
        display();   // Base class function

        cout << "\nMagazine Title: " << magazineTitle << endl;
        cout << "Issue Number: " << issueNumber << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Monthly Circulation: " << monthlyCirculation << endl;
    }

    // Release new issue
    void releaseNewIssue()
    {
        issueNumber++;
        cout << "New issue released! Current Issue Number: " << issueNumber << endl;
    }
};


int main()
{
    Magazine m1(101, "CentralLibrary", "Pune",
                "TechWorld", 5, "ABC Publications", 2000);

    m1.registerLibrary();
    m1.displayMagazine();

    Library::showLibraries();

    m1.releaseNewIssue();

    return 0;
}