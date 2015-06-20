//
// Created by Big Z on 05.06.2015.
//

#include "big_integer.h"
#include <ctime>
#include "myvector.h"
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
   myvector a(10);
    myvector b;

    b = a;
    a.clear();
    b[5]=22;
    std::cout << b[5];
    return 0;
}