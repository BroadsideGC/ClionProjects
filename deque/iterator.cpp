//
// Created by Big Z on 21.06.2015.
//

#include "deque.h"

using iterator = deque::iterator;

deque::value_type &deque::iterator::operator*() {
    return *__ptr;
}


deque::value_type *deque::iterator::operator->() {
    return __ptr;
}

deque::value_type const &deque::iterator::operator*() const {
    return *__ptr;
}

deque::iterator &deque::iterator::operator=(iterator const &other) {
    __ptr = other.__ptr;
    __parent = other.__parent;
    return *this;
}

deque::iterator::~iterator() {

}

deque::iterator::iterator() : __ptr(nullptr), __parent(nullptr) {

}

deque::iterator::iterator(value_type *const a) : __ptr(a), __parent(nullptr) {

}

deque::iterator::iterator(const deque::iterator &a) : __ptr(a.__ptr), __parent(a.__parent) {

}

bool deque::iterator::operator==(const deque::iterator &b) {
    return (__ptr == b.__ptr);
}

bool deque::iterator::operator!=(const deque::iterator &b) {
    return (__ptr != b.__ptr);
}

bool deque::iterator::operator<(const deque::iterator &b) {
    return __ptr < b.__ptr;
}

bool deque::iterator::operator<=(const deque::iterator &b) {
    return __ptr <= b.__ptr;
}

bool deque::iterator::operator>=(const deque::iterator &b) {
    return __ptr >= b.__ptr;
}

bool deque::iterator::operator>(const deque::iterator &b) {
    return __ptr > b.__ptr;
}

deque::iterator deque::iterator::operator++() {
    (__ptr == __parent->tail.__ptr) ? __ptr = __parent->head.__ptr : __ptr++;
    return __ptr;
}

deque::iterator deque::iterator::operator--() {
    (__ptr == __parent->head.__ptr) ? __ptr = __parent->tail.__ptr : __ptr--;
    return __ptr;
}

deque::iterator deque::iterator::operator+=(const int &a) {
    (__ptr + a > __parent->tail.__ptr) ? __ptr = __parent->head.__ptr + (__parent->tail.__ptr - __ptr) : __ptr += a;
    return *this;
}

deque::iterator deque::iterator::operator-=(const int &a) {
    (__ptr - a < __parent->head.__ptr) ? __ptr = __parent->tail.__ptr + (__ptr - __parent->head.__ptr) : __ptr -= a;
    return *this;
}

deque::iterator operator+(iterator b,size_t const &a) {
    return b += a;
}

deque::iterator operator-(iterator b,size_t const &a) {
    return b -= a;
}

deque::value_type &deque::const_iterator::operator*() const {
    return *__ptr;
}

deque::value_type *deque::const_iterator::operator->() const {
    return __ptr;
}

bool deque::const_iterator::operator==(const deque::const_iterator &b) {
    return __ptr == b.__ptr;
}

bool deque::const_iterator::operator!=(const deque::const_iterator &b) {
    return __ptr != b.__ptr;
}

bool deque::const_iterator::operator<(const deque::const_iterator &b) {
    return __ptr < b.__ptr;
}

bool deque::const_iterator::operator<=(const deque::const_iterator &b) {
    return __ptr <= b.__ptr;
}

bool deque::const_iterator::operator>=(const deque::const_iterator &b) {
    return __ptr >= b.__ptr;
}

bool deque::const_iterator::operator>(const deque::const_iterator &b) {
    return __ptr > b.__ptr;
}

deque::const_iterator::const_iterator() : __ptr(nullptr) {

}

deque::const_iterator::const_iterator(deque::iterator a) : __ptr(&*a) {

}

deque::const_iterator::const_iterator(deque::value_type *a) : __ptr(a) {

}

deque::iterator deque::iterator::operator++(int i) {
    return --(__ptr);
}

deque::iterator deque::iterator::operator--(int i) {
    return --(__ptr);
}