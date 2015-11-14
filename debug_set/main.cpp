#include <iostream>
#include "set.h"
using namespace std;

int main() {
    set s;
    s.insert(1);
    s.insert(0);
    s.insert(2);
   // s.insert(7);
    //cout<<s.size()<<" "<<*s.begin()<<"\n";
    set::iterator it1 = s.find(2);
    //it1++;
    cout<<(it1.it->r == nullptr);
    s.erase(s.find(1));
    //it1++;
    //s.erase(s.find(16));
   // s.clear();
    cout<<s.size()<<"\n";

    for (set::iterator it = s.begin();it!=s.end();it++){
        printf("%d ", *it);
    }
    //s.print();
    return 0;
}