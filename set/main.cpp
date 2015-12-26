#include <iostream>
#include <vector>
#include "set.h"
#include <algorithm>

using namespace std;

int main() {
    set a;
    vector<string>u;
    for (int i=0;i<100;i++)
        u.push_back(to_string(i));
    random_shuffle(u.begin(), u.end());
    for (int i=0;i<100;i++)
        a.insert(u[i]);
    set b = a;
    for (int i=0;i<99;i++)
        b.erase(u[i]);
    a.print();
    cout<<"\n\n";
    b.print();
    return 0;
}