#include <iostream>
using  namespace std;
class School 
{
    private:
    int schoolCode;
    string schoolName;
    string board;
    int student;

    public:
    static int schoolCount;
    School()
    {
       schoolCode= 0;
       schoolName = "Unknown";
       board = "Unknown";
       student = 0;
       schoolCount++;
    }

    School(int code, string name , string b , int s)
    {
       schoolCode= code;
       schoolName = name;
       board = b;
       student = s;
       schoolCount++;
    }
    void registerSchool()
    {
    cout<<"School Registered Successfully"<<endl;
    }
    void display()
    {
        cout<< "School Code " << schoolCode   <<endl;
         cout<<" School Name "<< schoolName  <<endl;
          cout<< "Board " << board  <<endl;
           cout<< "Student" << student  <<endl;
    }
    static void showSchool()
    {
    cout <<" Total Registered School" << schoolCount << endl;
    }


    friend void compareStudents (School & , School &);

    ~School()
    {
      cout<<" School Record Deleted :" << schoolName << endl;
    }
};

    int School :: schoolCount=0;
    void compareStudents (School &s1 , School &s2)
    {
        if (s1.student > s2.student)
        cout<< s1.schoolName << "has more students" << endl;
        else if (s1. student < s2. student)
        cout << s2.schoolName <<" has more students" << endl;
        else 
        cout << "Both has same no of students" << endl; 
    }

    class Classroom : public School 
    { private:
      int classNumber;
      string section;
      int studentStrenght;
      string classTeacher;

      public:
      Classroom (int code , string name , string board , int totalstudent, int cno, string sec, int strenght , string teacher) 
      :School (code, name, board, totalstudent) 
      {
        classNumber = cno;
        section = sec;
        studentStrenght= strenght;
        classTeacher = teacher;
      }
      void acceptClassrooms()
      {
      cout << "enter class number :";
      cin>>classNumber;
      cout << "enter section :";
      cin>> section;
      cout << "total strenght :";
      cin>>studentStrenght;
      cout << "class teacher:";
      cin>> classTeacher;
      }

      void display(){
      cout << "class number" << classNumber << endl;
      cout <<"section " << section << endl;
      cout << " strenght"<< studentStrenght << endl;
      cout << "class teacher " << classTeacher << endl;
      }
       
      void conductExam()
      {
        cout << "exam conducted for "<< classNumber << endl;
      }
    };

    int main()
    {
        Classroom c1(101, "xxx yyy zzz" , "cbse" , 700 ,
                       20 ," b" ,500, "hhbvfbdfb ");
         c1.registerSchool();
         c1.display();
         
         School::showSchool();
          c1.conductExam();
          School s2(102, "City Public School", "ICSE", 900);

    compareStudents(c1, s2);
    }

