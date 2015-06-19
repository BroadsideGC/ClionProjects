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
    big_integer a("10000000000000000000000000000000000000000000000000000");
    big_integer b("10000000000");
    /*for (int i=0;i<a.digits.size();i++) {
        std::cout << a.digits[i]<<" ";
    }*/
    std::cout << a / b;
    return 0;
}