#include <iostream>
#include "myvector.h"

using namespace std;

int main() {
    vector a;
    a.push_back("Hello, world!");
    for (int i=0;i<10;i++){
        a.push_back(to_string(i));
    }
    //a.erase(a.begin()+5);
    a.erase(a.begin()+5, a.begin()+6);
    a[1]="10";
    for (int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }

    return 0;
}