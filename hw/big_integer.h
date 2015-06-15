//
// Created by Big Z on 04.06.2015.
//

#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H

#include <string>
#include <vector>

struct big_integer {
    big_integer();
    big_integer(int a);
    big_integer(big_integer const& a);
    explicit big_integer(std::string const& str);
    big_integer& operator = (big_integer const& a);

    big_integer& operator += (big_integer const& a);
    big_integer& operator -= (big_integer const& a);
    big_integer& operator *= (big_integer const& a);
    big_integer& operator /= (int const& a);
    big_integer& operator /= (big_integer const& a);
    big_integer& operator %= (big_integer const& a);
    big_integer& operator <<= (int a);
    big_integer& operator >>= (int a);

    big_integer& operator &= (big_integer const& a);
    big_integer& operator |= (big_integer const& a);
    big_integer& operator ^= (big_integer const& a);


    big_integer operator + () const;
    big_integer operator - () const;

    big_integer& operator ++ ();
    big_integer& operator -- ();

    friend bool operator == (big_integer const& a, big_integer const& b);
    friend bool operator != (big_integer const& a, big_integer const& b);
    friend bool operator < (big_integer const& a, big_integer const& b);
    friend bool operator > (big_integer const& a, big_integer const& b);
    friend bool operator <= (big_integer const& a, big_integer const& b);
    friend bool operator >= (big_integer const& a, big_integer const& b);

    friend std::string to_string(big_integer const& a);

    bool sign;
    std::vector <size_t > digits;
    static const size_t base = 4294967295;
};

big_integer operator + (big_integer a, big_integer const& b);
big_integer operator - (big_integer a, big_integer const& b);
big_integer operator * (big_integer a, big_integer const& b);
big_integer operator / (big_integer a, int const& b);
big_integer operator / (big_integer a, big_integer const& b);
big_integer operator % (big_integer a, big_integer const& b);

big_integer operator & (big_integer a, big_integer const& b);
big_integer operator | (big_integer a, big_integer const& b);
big_integer operator ^ (big_integer a, big_integer const& b);

big_integer operator << (big_integer a, int b);
big_integer operator >> (big_integer a, int b);

bool operator == (big_integer const& a, big_integer const& b);
bool operator != (big_integer const& a, big_integer const& b);
bool operator < (big_integer const& a, big_integer const& b);
bool operator > (big_integer const& a, big_integer const& b);
bool operator <= (big_integer const& a, big_integer const& b);
bool operator >= (big_integer const& a, big_integer const& b);

std::string to_string(big_integer const& a);
std::ostream& operator << (std::ostream& s, big_integer const& a);
#endif //BIG_INTEGER_H
