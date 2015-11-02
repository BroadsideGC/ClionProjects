#include <iostream>
#include "set.h"

using namespace std;

int main() {
    set a;
    for (int i=0;i<10000;i++)
        a.insert(to_string(i));
    set b = a;
    for (int i=1;i<9990;i++)
        b.erase(to_string(i));
    a.print();
    cout<<"\n\n";
    b.print();
    return 0;
}