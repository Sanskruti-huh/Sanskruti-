#include <iostream>
using namespace std;
class Recharge {
    public:
    long long number;
    int amount;

    Recharge(){
        number = 9021018365;
        amount = 199;
    }
    void display (){
        cout<< "details" << endl;
        cout << "number" << number << endl;
        cout << "amount"<< amount << endl;
    }

    virtual void show(){
        cout << "recharge!"<< endl;
    }
};

class SpecialRecharge : public Recharge {
    public:
    void show(){
        cout <<"Special Recharge"<<endl;
    }
};

template <typename T>
T divi(T a, T b){
    return a / b ;
};

int main(){
    Recharge r;
    r. display();
    
    SpecialRecharge s;
    Recharge *ptr = & s;
    ptr-> show();

    cout << "div" << divi(20,4) << endl;

    return 0;
}