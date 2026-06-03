#include <iostream>
using namespace std;
class Shopping {
public:
int price, quantity;
Shopping() {
price = 100;
quantity = 3;
}
void display() {
cout << "Total Cost = " << price * quantity << endl;
}
virtual void show() {
cout << "Shopping" << endl;
}
};
class OnlineShopping : public Shopping {
public:
void show() {
cout << "Online Shopping" << endl;
}
};
template <typename T>
T mul(T a, T b) {
return a * b;
}
int main() {
Shopping s;
s.display();
OnlineShopping o;
Shopping *ptr = &o;
ptr->show();

cout << "Mul: " << mul(4, 5) << endl;
return 0;
}