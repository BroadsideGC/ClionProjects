//
// Created by Big Z on 12.09.2015.
//

#include "bimap.h"

bimap::Node &bimap::left_iterator::operator*() {
    return *__ptr;
}

const bimap::Node &bimap::left_iterator::operator*() const {
    return *__ptr;
}

bimap::Node *bimap::left_iterator::operator->() {
    return __ptr;
}

bimap::left_iterator::left_iterator(const bimap::left_iterator &other) : __ptr(other.__ptr) {

}

bimap::left_iterator::left_iterator() : __ptr(nullptr) {

}

bimap::left_iterator::left_iterator(bimap::Node *ptr) : __ptr(ptr) {

}

bimap::left_iterator::~left_iterator() {

}

bimap::left_iterator &bimap::left_iterator::operator=(const bimap::left_iterator &other) {
    __ptr = other.__ptr;
    return *this;
}

bool bimap::left_iterator::operator==(const bimap::left_iterator &other) const {
    return (__ptr == other.__ptr);
}

bool bimap::left_iterator::operator!=(const bimap::left_iterator &other) const {
    return (__ptr == other.__ptr);
}


bimap::left_iterator &bimap::left_iterator::operator++() {
    if (__ptr->lr != nullptr) {
        return mini(__ptr->lr);
    }
    point y = __ptr->lp;
    while (y != nullptr && __ptr == y->lr) {
        __ptr = y;
        y = y->lp;
    }
    __ptr = y;
    return *this;
}

bimap::left_iterator &bimap::left_iterator::operator--() {

    if (__ptr->lr != nullptr) {
        return maxi(__ptr->lr);
    }
    point y = __ptr->lp;
    while (y != nullptr && __ptr == y->lr) {
        __ptr = y;
        y = y->lp;
    }
    __ptr = y;
    return *this;
}


const bimap::left_iterator &bimap::left_iterator::mini(bimap::left_iterator const &x) {
    if (x->lr == nullptr)
        return x;
    return mini(x->lr);
}
const bimap::left_iterator &bimap::left_iterator::maxi(bimap::left_iterator const &x) {
    if (x->ll== nullptr)
        return x;
    return maxi(x->ll);
}



