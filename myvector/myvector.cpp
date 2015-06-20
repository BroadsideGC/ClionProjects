//
// Created by Big Z on 20.06.2015.
//

#include "myvector.h"

vector::vector() {
    sz = 0;
    __size = 2;
    a = __reserve(2);
    new((void *) a) value_type;
}

vector::vector(vector const &other) {
    sz = other.size();
    __size = sz;
    a = __reserve(sz);
    __copy(other);
}

vector::~vector() {
    operator delete[](a);
}

void vector::clear() {
    sz = 0;
}

void vector::push_back(value_type item) {
    if (sz == __size) {
        __enlarge();
    }
    new((void *) (a + sz)) value_type;
    *(a + sz) = item;
    sz++;
}

void vector::pop_back() {
    sz--;
    //operator delete[]((a + sz));
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
        std::swap(*j,*(j + 1));
    }
    pop_back();
    return i;
}

iterator vector::erase(iterator i1, iterator i2) {
    int diff = (i2 - i1);
    for (iterator j = i1; j != a + sz - diff ; j++) {
        *j = *(j + diff);
    }
    //for ()
    sz -= diff;
    return i2;
}

iterator vector::insert(iterator i, value_type const &item) {
    push_back(item);
    for (iterator j = a + sz - 1; j != i; j--) {
        std::swap((*j),*(j - 1));
    }
    return i;
}

iterator vector::__reserve(size_t size) {
    return static_cast<value_type *> (operator new(sizeof(value_type) * size));;
}

void vector::__copy(vector const &other) {

    for (int i = 0; i < other.size(); i++) {
        new((void *) (a + i)) value_type(other[i]);
    }
}

void vector::__enlarge() {
    iterator tmp = __reserve(__size * 2);
    for (int i = 0; i < sz; i++) {
        new((void *) (tmp + i)) value_type(*(a+i));
    }
    operator delete[](a);
    a = tmp;
    __size *= 2;
}
