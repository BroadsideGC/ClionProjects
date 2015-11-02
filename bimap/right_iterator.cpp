//
// Created by Big Z on 12.09.2015.
//

#include "bimap.h"

bimap::Node &bimap::right_iterator::operator*() {
    return *__ptr;
}

const bimap::Node &bimap::right_iterator::operator*() const {
    return *__ptr;
}

bimap::Node *bimap::right_iterator::operator->() {
    return __ptr;
}

bimap::right_iterator::right_iterator(const bimap::right_iterator &other) : __ptr(other.__ptr) {

}

bimap::right_iterator::right_iterator() : __ptr(nullptr) {

}

bimap::right_iterator::right_iterator(bimap::Node *ptr) : __ptr(ptr) {

}

bimap::right_iterator::~right_iterator() {

}

bimap::right_iterator &bimap::right_iterator::operator=(const bimap::right_iterator &other) {
    __ptr = other.__ptr;
    return *this;
}

bool bimap::right_iterator::operator==(const bimap::right_iterator &other) const {
    return (__ptr == other.__ptr);
}

bool bimap::right_iterator::operator!=(const bimap::right_iterator &other) const {
    return (__ptr == other.__ptr);
}


bimap::right_iterator &bimap::right_iterator::operator++() {
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

bimap::right_iterator &bimap::right_iterator::operator--() {

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


const bimap::right_iterator &bimap::right_iterator::mini(bimap::right_iterator const &x) {
    if (x->rr == nullptr)
        return x;
    return mini(x->rr);
}
const bimap::right_iterator &bimap::right_iterator::maxi(bimap::right_iterator const &x) {
    if (x->rl== nullptr)
        return x;
    return maxi(x->rl);
}



