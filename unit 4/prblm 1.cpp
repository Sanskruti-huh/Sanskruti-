#include <iostream>
using namespace std;
class Employee {
public:
virtual void salary() {
cout << "Standard Employee Salary" << endl;
}
};
class Manager : public Employee {
public:
void salary() override {
cout << "Manager Salary: $8000" << endl;
}
};
class Developer : public Employee {
public:
void salary() override {
cout << "Developer Salary: $6000" << endl;
}
};
int main() {
Employee* ptr;
Manager m;
Developer d;
ptr = &m;
ptr->salary(); // Calls Manager's salary
ptr = &d;
ptr->salary(); // Calls Developer's salary
return 0;
}