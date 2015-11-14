#include <iostream>
#include "set.h"
using namespace std;

int main() {
    set s;
    for (int i=0;i<1000;i++){
        //if (i!=7) {
            s.insert(i);
       // }
    }
   // s.insert(7);
    ///cout<<s.size()<<" "<<*s.begin()<<"\n";
    set::iterator it1 = s.find(0);
    //it1++;
    //cout<<*it1;
    //it1++;
    for (int i=0;i<10;i++){
        s.erase(s.find(i));
    }
   // s.clear();
    cout<<s.size()<<"\n";
    for (set::iterator it = s.begin();it!=s.end();it++){
        printf("%d ", *it);
    }
    //s.print();
    return 0;
}