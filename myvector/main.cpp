#include <iostream>
#include "myvector.h"

using namespace std;

int main() {
    vector a;
    a.push_back("Hello, vanyacpp!");
    for (int i = 0; i < 20; i++) {
        a.insert(a.begin(),to_string(i));
    }
    a.insert(a.begin(), "dd");
    cout<<*a.erase(a.begin())<<"\n";
    a.erase(a.end());
    a.insert(a.begin() + 1, "d1");
    a.insert(a.begin() + 1, "d2");
   a.insert(a.begin() + 1, "d3");
    a.erase(a.erase(a.begin()));
    cout<<*a.erase(a.begin()+3,a.begin()+5)<<"\n";
    vector b=a;
    b.push_back("java");
    for (int i = 0; i < b.size(); i++) {
        cout << b[i] << " ";
    }
    cout<<"\n";
    a.clear();
    /*for (int i = 0; i < 20; i++) {
        a.push_back(to_string(i));
    }*/
    cout<<a[4];
    /*for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }*/
    return 0;
}