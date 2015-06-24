//
// Created by Big Z on 21.06.2015.
//

#include "cyclebuf.h"

value_type &iterator::operator*() {
    return *__ptr;
}

value_type *iterator::operator->() {
    return __ptr;
}

iterator::iterator():__ptr(nullptr) {
}

bool iterator::operator==(iterator const &a, iterator const &b) const {
    return (a.__ptr==b.__ptr);
}

bool iterator::operator!=(iterator const &a, iterator const &b) const {
    return (a.__ptr==b.__ptr);;
}

bool iterator::operator<(iterator const &a, iterator const &b) {
    return (a.__ptr<b.__ptr);
}

bool iterator::operator<=(iterator const &a, iterator const &b) {
    return false;
}

bool iterator::operator>=(iterator const &a, iterator const &b) {
    return false;
}

bool iterator::operator>(iterator const &a, iterator const &b) {
    return false;
}

iterator iterator::operator++() {
    __ptr++;
    if (__ptr > deque::tail)
    return __ptr++;
}

iterator &iterator::operator--() {
    return <#initializer#>;
}

iterator &iterator::operator+=(iterator const &a) {
    return <#initializer#>;
}

iterator &iterator::operator-=(iterator const &a) {
    return <#initializer#>;
}

iterator &iterator::operator+(iterator const &a) {
    return <#initializer#>;
}

iterator &iterator::operator-(iterator const &a) {
    return <#initializer#>;
}
