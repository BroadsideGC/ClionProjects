#include <iostream>
#include "lru_cache.h"

using namespace std;

int main() {
    lru_cache a(5);
    a.lookup(6).second=9.0;
    a.lookup(7).second=4.4;
    a.lookup(-1).second=5;
    cout<<a.lookup(6).second;
    cout<<" "<<a.lookup(7).second;
    cout<<" "<<a.lookup(-1).second;
    return 0;
}