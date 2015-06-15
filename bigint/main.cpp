//
// Created by Big Z on 05.06.2015.
//

#include "big_integer.h"
#include <ctime>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    big_integer a("-20");
    big_integer b("5");
    std::cout << a / b;
    return 0;
}