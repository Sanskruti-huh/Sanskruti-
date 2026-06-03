#include <iostream>
using namespace std;

class Hospital
{
protected:
    int hospitalID;
    string hospitalName;
    string location;
    int beds;

    static int hospitalCount;

public:
    // Parameterized constructor
    Hospital(int id, string name, string loc, int b)
    {
        hospitalID = id;
        hospitalName = name;
        location = loc;
        beds = b;
        hospitalCount++;
    }

    // Function to register hospital
    void registerHospital()
    {
        cout << "Hospital Registered Successfully\n";
    }

    // Display hospital details
    void display()
    {
        cout << "\nHospital ID: " << hospitalID << endl;
        cout << "Hospital Name: " << hospitalName << endl;
        cout << "Location: " << location << endl;
        cout << "Beds Available: " << beds << endl;
    }

    // Static function
    static void showHospitals()
    {
        cout << "Total Hospitals Registered: " << hospitalCount << endl;
    }

    // Operator Overloading (+) to add beds
    Hospital operator+(int extraBeds)
    {
        beds = beds + extraBeds;
        return *this;
    }

    // Destructor
    ~Hospital()
    {
        cout << "Hospital record removed: " << hospitalName << endl;
    }
};

// Initialize static variable
int Hospital::hospitalCount = 0;


// Derived class
class Patient : public Hospital
{
private:
    int patientID;
    string disease;
    string admissionDate;
    string doctorAssigned;

public:

    // Constructor for derived class
    Patient(int hid, string hname, string loc, int beds,
            int pid, string dis, string date, string doc)
        : Hospital(hid, hname, loc, beds)
    {
        patientID = pid;
        disease = dis;
        admissionDate = date;
        doctorAssigned = doc;
    }

    // Accept patient details
    void acceptPatient()
    {
        cout << "\nEnter Patient ID: ";
        cin >> patientID;

        cout << "Enter Disease: ";
        cin >> disease;

        cout << "Enter Admission Date: ";
        cin >> admissionDate;

        cout << "Enter Doctor Assigned: ";
        cin >> doctorAssigned;
    }

    // Display patient + hospital info
    void displayPatient()
    {
        display(); // base class function

        cout << "\nPatient ID: " << patientID << endl;
        cout << "Disease: " << disease << endl;
        cout << "Admission Date: " << admissionDate << endl;
        cout << "Doctor Assigned: " << doctorAssigned << endl;
    }

    // Discharge patient
    void dischargePatient()
    {
        cout << "Patient " << patientID << " discharged successfully.\n";
    }
};


int main()
{
    Patient p1(101, "CityCare", "Pune", 50, 201, "Fever", "10-03-2026", "Dr.Smith");

    p1.registerHospital();
    p1.displayPatient();

    // Demonstrating operator overloading
    p1 = p1 + 10;

    cout << "\nAfter adding beds:\n";
    p1.displayPatient();

    // Static function
    Hospital::showHospitals();

    // Derived class function
    p1.dischargePatient();

    return 0;
}