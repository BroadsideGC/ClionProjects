//
// Created by Big Z on 04.06.2015.
//

#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H

#include <string>
#include <vector>
#include "myvector.h"

struct big_integer {
    big_integer();

    big_integer(int a);

    big_integer(big_integer const &a);

    big_integer(long long a);

    explicit big_integer(std::string const &str);

    big_integer &operator=(big_integer const &a);

    ~big_integer();

    big_integer &operator+=(big_integer const &a);

    big_integer &operator-=(big_integer const &a);

    big_integer &operator*=(big_integer const &a);

    big_integer &operator/=(big_integer const &a);

    big_integer &operator%=(big_integer const &a);

    big_integer &operator<<=(int a);

    big_integer &operator>>=(int a);

    big_integer &operator&=(big_integer const &a);

    big_integer &operator|=(big_integer const &a);

    big_integer &operator^=(big_integer const &a);

    big_integer operator~() const;


    big_integer operator+() const;

    big_integer operator-() const;

    big_integer &operator++();

    big_integer &operator--();

    big_integer operator++(int);

    big_integer operator--(int);

    friend bool operator==(big_integer const &a, big_integer const &b);

    friend bool operator!=(big_integer const &a, big_integer const &b);

    friend bool operator<(big_integer const &a, big_integer const &b);

    friend bool operator>(big_integer const &a, big_integer const &b);

    friend std::string to_string(big_integer const &a);

    void addcode();

    char sign;
    myvector digits;
    //static const size_t base = 10;
    //static const size_t base = 11;
    static const unsigned int base = 4294967295;
};

big_integer operator+(big_integer a, big_integer const &b);

big_integer operator-(big_integer a, big_integer const &b);

big_integer operator*(big_integer a, big_integer const &b);

big_integer operator/(big_integer a, big_integer const &b);

big_integer operator%(big_integer a, big_integer const &b);

big_integer operator&(big_integer a, big_integer const &b);

big_integer operator|(big_integer a, big_integer const &b);

big_integer operator^(big_integer a, big_integer const &b);

big_integer operator<<(big_integer a, int b);

big_integer operator>>(big_integer a, int b);

bool operator==(big_integer const &a, big_integer const &b);

bool operator!=(big_integer const &a, big_integer const &b);

bool operator<(big_integer const &a, big_integer const &b);

bool operator>(big_integer const &a, big_integer const &b);

bool operator<=(big_integer const &a, big_integer const &b);

bool operator>=(big_integer const &a, big_integer const &b);

std::string to_string(big_integer const &a);

std::ostream &operator<<(std::ostream &s, big_integer const &a);

#endif //BIG_INTEGER_H

