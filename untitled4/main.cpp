#include <iostream>

using namespace std;

struct A{
    virtual  void foo(){cout<<"Hello";}
    virtual ~A(){

    };
};

struct B : public A{
    void foo(){cout<<"world";}
};

int main() {
    A* a = new B();
    a->A::foo();
    delete a;
    return 0;
}