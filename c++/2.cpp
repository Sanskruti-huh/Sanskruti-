#include <iostream>
using namespace std;
class Vehicle {
public:
virtual void showSpeed() {
cout << "General Vehicle Speed" << endl;
}
};
class Car : public Vehicle {
public:
void showSpeed() override {
cout << "Car Speed: 120 km/h" << endl;
}
};
class Bike : public Vehicle {
public:
void showSpeed() override {
cout << "Bike Speed: 80 km/h" << endl;
}
};
int main() {
Vehicle* v;
Car c;
Bike b;
v = &c; v->showSpeed();
v = &b; v->showSpeed();
return 0;
}