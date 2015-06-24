#include <iostream>
#include "set.h"

using namespace std;

int main() {
    set a;
    a.insert("1");
    a.insert("vanyahuisosi");
    set b(a);
    a.insert("hello world");
    a.insert("sorokinpidor");
    a.insert("6");
    a.erase("1");
    b.insert("a");
    b.insert("v");
    b.insert("y");
    a.erase("y");
    a.print();
    std::cout<<"\n";
    b.print();
    return 0;
}