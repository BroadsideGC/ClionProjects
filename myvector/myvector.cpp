//
// Created by Big Z on 20.06.2015.
//

#include "myvector.h"

vector::vector() {
    sz = 0;
    __size = 2;
    a = __reserve(2);
}

vector::vector(vector const &other) {
    sz = other.size();
    __size = sz;
    a = __reserve(sz);
    __copy(other);
}

vector::~vector() {
    delete[] a;
}

void vector::clear() {
    sz = 0;
}

void vector::push_back(value_type item) {
    if (sz == __size) {
        __enlarge();
    }
    *(a + sz) = item;
    sz++;
}

void vector::pop_back() {
    sz--;
}

value_type &vector::back() {
    return *(begin() + sz - 1);
}

value_type const &vector::back() const {
    return *(begin() + sz - 1);
}

size_t vector::size() const {
    return sz;
}

value_type &vector::operator[](size_t i) {
    return *(a + i);
}

value_type const &vector::operator[](size_t i) const {
    return *(a + i);
}

iterator vector::begin() {
    return a;
}

const_iterator vector::begin() const {
    return a;
}

iterator vector::end() {
    return a + sz;
}

const_iterator vector::end() const {
    return a + sz;
}

iterator vector::erase(iterator i) {
    for (iterator j = i; j != a + sz - 1; j++) {
        *j = *(j + 1);
    }
    sz--;
    return i;
}

iterator vector::erase(iterator i1, iterator i2) {
    int diff = (i2-i1);
    for (iterator j = i1; j != a+sz-diff; j++) {
        *j = *(j + diff+1);
    }
    sz -= diff;
    __size=sz;
    iterator tmp = a;
    a = __reserve(sz);
    for (int i = 0; i < sz; i++) {
        *(a + i) = *(tmp + i);
    }
    delete [] tmp;
    return i1;
}

iterator vector::insert(iterator i, value_type const &item) {
    if (sz == __size) {
        __enlarge();
    }
    for (iterator j = i + 1; j != a + sz; j++) {
        (*j) = *(j - 1);
    }
    return i;
}

iterator vector::__reserve(size_t size) {
    iterator buff = new value_type[size * sizeof(value_type)];
    return buff;
}


void vector::__copy(vector const &other) {
    for (int i = 0; i < other.size(); i++) {
        *(a + i) = other[i];
    }
}

void vector::__enlarge() {
    iterator tmp = __reserve(__size * 2);
    for (int i = 0; i < sz; i++) {
        *(tmp + i) = *(a + i);
    }
    delete[] a;
    a = tmp;
    __size *= 2;
}
