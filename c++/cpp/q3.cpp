#include <iostream>
using namespace std;
class HotelBill {
    public:
    int days, rentPerDay;
    HotelBill(){
        days= 2;
        rentPerDay= 1000;
    }
    void display(){
        cout << "total bill=" << days*rentPerDay << endl;
    }
    virtual void show(){
        cout <<"hotel bill=" << endl;
    }
};
class LuxuryRoom : public HotelBill{
    public:
    void show(){
        cout<<"fuel"<<endl;
    }
};

template <typename T>
T maxVal(T a, T b){
    return (a>b)? a:b;
}

int main (){
    HotelBill h;
    h. display();
    LuxuryRoom l;
    HotelBill *ptr = &l;
    ptr -> show();

    cout <<"max"<< maxVal(20,10);
    return 0;
}