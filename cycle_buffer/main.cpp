#include <iostream>
#include "myvector.h"

using namespace std;

int main() {
    vector a;
    a.push_back("Hello, world!");
    for (int i = 0; i < 10; i++) {
        a.push_back(to_string(i));
    }
    a.insert(a.begin() + 1, "dd");
    a.erase(a.begin());
    a.insert(a.begin() + 1, "dd");
    a.insert(a.begin() + 1, "dd");
   a.insert(a.begin() + 1, "dd");
    a.erase(a.begin()+1,a.begin()+5);
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }

    return 0;
}