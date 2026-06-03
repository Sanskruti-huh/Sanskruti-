#include <iostream>
using namespace std;
class Student
{
    int roll_no;
    int marks;
    public:
      void getdata()
      {
        cout << "Enter the roll number:";
        cin>>roll_no;
        cout<< "Enter the marks:"<< endl;
    cin>>marks;
      }
      void displaydata()
      {
        cout<<"Roll number: "<<roll_no<< endl;
        cout <<"Marks=" << marks<< endl;

      }
};
int main()
{
    cout <<"Welcome to object orientated programming" << endl;
    Student s;
    s. getdata ();
    s .displaydata();
}