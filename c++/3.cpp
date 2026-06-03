#include <iostream>
using namespace std;
class Food{
    public:
    virtual void type()
    {
        cout << "type of foods"<<endl;
    }
};
class Veg : public Food {
    public:
    void type(){
        cout <<" food is veg" << endl;
    }
};
class Nonveg : public Food {
    public:
    void type(){
        cout <<" food is  nonveg" << endl;
    }
};

int main (){
    Food* ptr;
    Veg v;
    Nonveg nv;

    ptr = &v;
    ptr-> type();
    ptr = &nv;
    ptr -> type();
    return 0;
}
