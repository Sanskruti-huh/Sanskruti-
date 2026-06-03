#include <iostream>
using namespace std;
 class Petrol {
    public:
    int liters, pricePerLiter;
    Petrol(){
        liters = 5;
        pricePerLiter = 100;
    }
    void display (){
        cout <<"total cost ="<< liters*pricePerLiter <<endl;
    }
    virtual void show(){
        cout <<"fuel"<< endl;
    }
 };
 class Diesel : public Petrol{
    public:
    void show(){
        cout<<"diesel fuel"<<endl;
    }
 };

 template <typename T>
 T minVal (T a, T b){
    return (a<b)? a: b;
 }

 int main() {
    Petrol p;
    p. display();
    Diesel d;
    Petrol *ptr =& d;
    ptr -> show();

    cout << "min=" << minVal (10,20)<<endl;
    return 0;
 }