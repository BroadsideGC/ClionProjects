//
// Created by Big Z on 04.06.2015.
//

#include "big_integer.h"

#include <cmath>
#include <algorithm>
#include <iostream>

const big_integer ZERO(0);
const big_integer ONE(1);

big_integer::big_integer() {
    digits.push_back(0);
    sign = 1;
}

big_integer::big_integer(int a) {
    digits.push_back(0);
    digits[0]=(abs(a));
    sign = ((a < 0) ? -1 : 1);
}

big_integer::big_integer(long long a) {
    if (!a) {
        sign = 1;
        digits.push_back(0);
        return;
    }
    sign = a > 0 ? 1 : (!a ? 0 : -1);
    if (a < 0)
        a = -a;
    digits.push_back(a % base);
    digits.push_back(a / base);
    while (digits.size() > 1 && digits.back() == 0)
        digits.pop_back();
}

big_integer::big_integer(big_integer const &a) {
    *this = a;
}

big_integer::big_integer(const std::string &str) {
    digits.push_back(0);
    sign = 1;
    int i = 0;
    if (str[0] == '-') {
        i++;
    }
    big_integer mul(10);
    for (; i<str.length();i++) {
        *this *= mul;
        *this += big_integer((int) (str[i]) - (int) ('0'));
    }
    if (str[0] == '-' && !(digits[0] == 0 && digits.size()== 1)) {
        sign = -1;
    }
}

big_integer &big_integer::operator=(big_integer const &a) {
    digits = a.digits;
    sign = a.sign;
    return *this;
}

big_integer::~big_integer() {
    sign = 0;
    digits.clear();
}

big_integer &big_integer::operator+=(big_integer const &a) {
    if ((*this) == -a) {
        return *this = ZERO;
    }
    if ((*this) ==  ZERO){
        return *this = a;
    }
    big_integer b(a);
    if (sign * a.sign > 0) {
        int carry = 0;
        for (unsigned int i = 0; i < std::max(digits.size(), a.digits.size()) || carry; ++i) {
            if (i == digits.size())
                digits.push_back(0);
            unsigned long long cnt = 1ull * digits[i] + carry + (i < a.digits.size() ? a.digits[i] : 0);
            carry = (cnt >= base);
            if (carry) cnt -= base;
            digits[i] = cnt;
        }
        while (digits.size() > 1 && digits.back() == 0)
            digits.pop_back();
        return *this;
    }
    if (b.sign == -1 && sign == 1) {
        b.sign = 1;
        *this -= b;
        b.sign = -1;
        return *this;
    }
    b.sign = -1;
    *this -= b;
    b.sign = -1;
    return *this;
}

big_integer &big_integer::operator-=(big_integer const &a) {

    if ((*this) == a)
        return *this = ZERO;

    if (sign == 1 && a.sign == -1)
        return (*this) += (-a);
    if (sign == -1 && a.sign == 1) {
        *this = -(*this);
        *this += a;
        return *this = -(*this);
    }

    if ((*this < a && sign == 1) || (*this > a && sign == -1)) {
        *this = -(a - *this);
        return *this;
    }

    int carry = 0;
    for (unsigned int i = 0; i < a.digits.size() || carry; ++i) {
        long long cur = 1ll * digits[i] - carry - (i < a.digits.size() ? a.digits[i] : 0);
        carry = cur < 0;
        if (carry) cur += base;
        digits[i] = cur;
    }
    while (digits.size() > 1 && digits.back() == 0)
        digits.pop_back();
    return *this;
}

big_integer &big_integer::operator*=(big_integer const &a) {
    big_integer c;
    c.digits.resize(digits.size() + a.digits.size());
    c.sign = sign * a.sign;
    if (*this == ZERO || a == ZERO) {
        return *this = ZERO;
    }

    if (digits.size()==1&&a.digits.size()>1){
        return *this = (a * (*this));
    }
    if (a.digits.size() == 1) {
        unsigned long long carry = 0;
        for (size_t i = 0; i < digits.size() || carry; ++i) {
            if (i == digits.size())
                digits.push_back(0);
            unsigned long long cur = carry + digits[i] * 1ull * a.digits[0];
            digits[i] = cur % base;
            carry = cur / base;
        }
        while (digits.size() > 1 && digits.back() == 0)
            digits.pop_back();
        sign = c.sign;
        return *this;
    }

    for (unsigned int i = 0; i < digits.size(); ++i)
        for (unsigned j = 0, carry = 0; j < a.digits.size() || carry; ++j) {
            unsigned long long cur =
                    c.digits[i + j] * 1Ull + 1Ull * digits[i] * 1ull * (j < a.digits.size() ? a.digits[j] : 0) + carry;
            c.digits[i + j] = cur % base;
            carry = cur / base;
        }
    while (c.digits.size() > 1 && c.digits.back() == 0)
        c.digits.pop_back();
    *this = c;
    return *this;
}

big_integer &big_integer::operator/=(big_integer const &a) {
    big_integer div;
    big_integer b(a);
    div.digits.clear();
    div.sign = sign * a.sign;
    sign = b.sign = 1;
    if (b == ONE || b == -ONE) {
        sign = div.sign;
        return *this;
    }

    if (*this == b) {
        *this = ONE;
        sign = div.sign;
        return *this;
    }
    if (*this < b) {
        div = ZERO;
        *this = div;
        return *this;
    }

    if (b.digits.size() == 1) {
        unsigned long long carry = 0;
        for (int i = (int) digits.size() - 1; i >= 0; --i) {
            unsigned long long cur = 1ull * digits[i] + carry * 1ull * base;
            digits[i] = (cur / (1Ull * b.digits[0]));
            carry = cur % (1ull * b.digits[0]);
        }
        while (digits.size() > 1 && digits.back() == 0)
            digits.pop_back();
        sign = div.sign;
        return *this;
    }

    int n = b.digits.size();
    int m = digits.size() - n;
    if (b.digits[n - 1] <= base / 2) {
        long long sc = base / (b.digits[n - 1] + 1);
        *this *= sc;
        b *= sc;
    }
    n = b.digits.size();
    m = digits.size() - n;
    for (long long i = m - 1; i >= 0; i--) {
        if (digits.size()==1 && digits[0]==0){
            div.digits.push_back(0);
            continue;
        }
        unsigned long long qc = (digits[n + i] * 1ull * base + 1ull * digits[n + i - 1]);
        qc /= (1ull * (b.digits[n - 1]));

        if (qc >= base) {
            i++;
            qc /= base;
            qc++;
        }
        big_integer y = (b * (long long) qc);
        y <<= (i * 32);
        *this -= y;
        while (sign < 0) {
            *this += y;
            qc--;
            y = b * (long long) qc;
            y <<= (i * 32);
            *this -= y;
        }
        div.digits.push_back(qc);
    }
    reverse(div.digits);
    *this = div;
    while (digits.size() > 1 && digits.back() == 0)
        digits.pop_back();
    return *this;
}

big_integer &big_integer::operator%=(big_integer const &a) {
    *this -= (*this / a) * a;
    return *this;
}

big_integer &big_integer::operator<<=(int a) {
    if (a < 0) {
        *this >>= -a;
        return *this;
    }
    if (sign < 0) {
        addcode();
    }
    unsigned int s = digits.size();

    unsigned int t = a / 32;
    unsigned rem = a - t * 32;
    if (rem) {
        long long carry = 0;
        for (size_t i = 0; i < digits.size() || carry; ++i) {
            if (i == digits.size())
                digits.push_back(0);
            long long current = ((1LL * digits[i]) << rem) + carry;
            digits[i] = current & (1ll * base);
            carry = current >> 32;
        }
    }
    digits.resize(digits.size() + t);
    for (int i = digits.size() - 1; i >= (int) t; i--) {
        digits[i] = digits[i-t];
    }
    for (int i = t - 1; i >= 0; --i)
        digits[i] = 0;
    if (sign < 0) {
        addcode();
    }
    while (digits.size() > 1 && digits.back() == 0) {

        digits.pop_back();
    }
    return *this;
}

big_integer &big_integer::operator>>=(int a) {
    if (a < 0) {
        *this <<= -a;
        return *this;
    }
    if (sign < 0) {
        addcode();
    }
    unsigned int s = digits.size();

    unsigned int t = a / 32;
    unsigned rem = a - t * 32;

    digits.resize(digits.size() - t);
    for (int i = t; i < digits.size(); i++)
        digits[i - t] = digits[i];
    for (int i = digits.size() - t; i < digits.size(); i++)
        digits[i] = 0;

    if (rem) {
        long long carry = 0;
        if (sign == -1)
            carry = base;
        for (int i = (int) digits.size() - 1; i >= 0; --i) {
            long long shl = (1LL * digits[i]) >> rem;
            long long current = shl + (carry << 32 - rem);
            carry = digits[i] - (shl << rem);
            digits[i] = current & (1ll * base);
        }
    }

    if (sign < 0) {
        addcode();
    }
    while (digits.size() > 1 && digits.back() == 0) {
        digits.pop_back();
    }
    return *this;
}

big_integer &big_integer::operator&=(big_integer const &a) {
    if (*this == ZERO || a == ZERO)
        return *this = ZERO;

    char nsign = (sign == -1 && a.sign == -1) ? -1 : 1;
    big_integer b = big_integer(a);
    (b.digits.size() > digits.size()) ? digits.resize(b.digits.size()) : b.digits.resize(digits.size());;
    if (sign == -1)
        addcode();
    if (b.sign == -1)
        b.addcode();
    for (size_t i = 0; i < digits.size(); ++i)
        digits[i] &= b.digits[i];
    sign = nsign;
    if (nsign == -1)
        addcode();

    while (digits.size() > 1 && digits.back() == 0) {
        digits.pop_back();
    }
    return *this;
}

big_integer &big_integer::operator|=(big_integer const &a) {
    if (*this == ZERO || a == ZERO)
        return *this = ZERO;

    char nsign = (sign == -1 || a.sign == -1) ? -1 : 1;
    big_integer b = big_integer(a);
    (b.digits.size() > digits.size()) ? digits.resize(b.digits.size()) : b.digits.resize(digits.size());;

    if (sign == -1)
        addcode();
    if (b.sign == -1)
        b.addcode();

    for (size_t i = 0; i < digits.size(); ++i)
        digits[i] |= b.digits[i];
    sign = nsign;
    if (nsign == -1)
        addcode();

    while (digits.size() > 1 && digits.back() == 0) {
        digits.pop_back();
    }
    return *this;
}

big_integer &big_integer::operator^=(big_integer const &a) {
    if (*this == ZERO || a == ZERO)
        return *this = ZERO;

    char nsign = ((sign == -1) ^ (a.sign == -1)) ? -1 : 1;
    big_integer b = big_integer(a);
    (b.digits.size() > digits.size()) ? digits.resize(b.digits.size()) : b.digits.resize(digits.size());;

    if (sign == -1)
        addcode();
    if (b.sign == -1)
        b.addcode();

    for (size_t i = 0; i < digits.size(); ++i)
        digits[i] ^= b.digits[i];
    sign = nsign;
    if (nsign == -1)
        addcode();

    while (digits.size() > 1 && digits.back() == 0) {
        digits.pop_back();
    }
    return *this;
}

big_integer big_integer::operator+() const {
    return *this;
}

big_integer big_integer::operator-() const {
    big_integer r(*this);
    if (r != ZERO)
        r.sign *= -1;
    return r;
}

big_integer &big_integer::operator++() {
    return *this += ONE;
}

big_integer big_integer::operator++(int) {
    big_integer r = *this;
    ++(*this);
    return r;
}

big_integer &big_integer::operator--() {
    return *this -= ONE;
}

big_integer big_integer::operator--(int) {
    big_integer r = *this;
    --(*this);
    return r;
}

bool operator!=(big_integer const &a, big_integer const &b) {
    return !(a == b);
}

bool operator<(big_integer const &a, big_integer const &b) {
    if (a.sign != b.sign)
        return a.sign < b.sign;
    if (a.digits.size() != b.digits.size())
        return a.sign == 1 ? a.digits.size() < b.digits.size() : a.digits.size() > b.digits.size();

    for (int i = (int) a.digits.size() - 1; i >= 0; --i)
        if (a.digits[i] != b.digits[i])
            return a.sign == 1 ? a.digits[i] < b.digits[i] : a.digits[i] > b.digits[i];
    return false;
}

bool operator>(big_integer const &a, big_integer const &b) {
    return !(a <= b);
}


std::string to_string(big_integer const &a) {
    std::string number = "";
    if (a == ZERO) {
        return "0";
    }
    char sign = a.sign;
    big_integer b = big_integer(a);
    big_integer div(10);
    while (b.digits[b.digits.size() - 1]) {
        big_integer last_digit(b % div);
        number.push_back((char)(last_digit.digits[0])+'0');
        b /= div;
    }
    if (sign == -1)
        number += '-';

    std::reverse(number.begin(), number.end());
    return number;
}

big_integer operator+(big_integer a, big_integer const &b) {
    return a += b;
}

big_integer operator-(big_integer a, big_integer const &b) {
    return a -= b;
}

big_integer operator*(big_integer a, big_integer const &b) {
    return a *= b;
}


big_integer operator/(big_integer a, big_integer const &b) {
    return a /= b;
}

big_integer operator%(big_integer a, big_integer const &b) {
    return a %= b;
}

big_integer operator&(big_integer a, big_integer const &b) {
    return a &= b;
}

big_integer operator|(big_integer a, big_integer const &b) {
    return a |= b;
}

big_integer operator^(big_integer a, big_integer const &b) {
    return a ^= b;
}

big_integer operator<<(big_integer a, int b) {
    return a <<= b;
}

big_integer operator>>(big_integer a, int b) {
    return a >>= b;
}

bool operator==(big_integer const &a, big_integer const &b) {
    if (a.sign != b.sign || a.digits.size() != b.digits.size())
        return false;

    for (unsigned int i = 0; i < a.digits.size(); ++i)
        if (a.digits[i] != b.digits[i])
            return false;
    return true;
}

std::ostream &operator<<(std::ostream &s, big_integer const &a) {
    return s << to_string(a);
}

bool operator<=(big_integer const &a, big_integer const &b) {
    return (a < b) || (a == b);
}

bool operator>=(big_integer const &a, big_integer const &b) {
    return !(a < b);
}

big_integer big_integer::operator~() const {
    return -(*this + 1);
}

void big_integer::addcode() {
    for (size_t i = 0; i < digits.size(); ++i) {
        digits[i] = (~digits[i] + 1);
    }
}

