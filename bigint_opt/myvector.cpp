//
// Created by Big Z on 17.06.2015.
//

#include "myvector.h"


myvector::myvector() {
    sz = 0;
    n = 0;
    cpd = 1;
}

myvector::myvector(size_t size) {
    sz = size;
    cpd = 1;
    if (sz < 2) {
        n = 0;
    } else {
        v = std::make_shared<std::vector<unsigned int>>(sz);
    }
}

myvector::myvector(myvector const &other) {
    sz = other.size();
    cpd = (sz < 2);
    if (sz < 2) {
        n = other.n;
    } else {
        v = other.v;
    }
}

myvector::~myvector() {
    v.reset();
}

void myvector::clear() {
    resize(0);
}

void myvector::push_back(unsigned int item) {
    if (!cpd)
        make_copy();
    sz++;
    if (sz < 2) {
        n = item;
        return;
    }
    if (sz == 2) {
        v = std::make_shared<std::vector<unsigned int>>(1);
        (*v)[0] = n;
        (*v).push_back(item);
        return;
    }
    (*v).push_back(item);
}

void myvector::pop_back() {
    if (!cpd)
        make_copy();
    sz--;
    if (sz < 1) {
        return;
    }
    if (sz == 1) {
        n = (*v)[0];
        v.reset();
        return;
    }
    (*v).pop_back();
}

void myvector::resize(size_t size) {
    if (!cpd)
        make_copy();
    if (sz == size)return;
    if (size == 0) {
        n = 0;
        v.reset();
        sz = size;
        return;
    }
    if (sz < 2 && size > 1) {
        v = std::make_shared<std::vector<unsigned int>>(size);
        (*v)[0] = n;
        sz = size;
        return;
    }
    if (sz > 1 && size < 2) {
        n = (*v)[0];
        sz = size;
        v.reset();
        return;
    }
    sz = size;
    (*v).resize(size);
}

unsigned int const &myvector::operator[](int i) const {
    if (i < 0 || i> sz){
        throw std::out_of_range("Index out of range");
    }
    if (sz < 2)return n;
    return ((*v)[i]);
}

unsigned int &myvector::operator[](int i) {
    if (i < 0 || i> sz){
        throw std::out_of_range("Index out of range");
    }
    if (!cpd)
        make_copy();
    if (sz < 2)return n;
    return ((*v)[i]);
}

myvector &myvector::operator=(myvector const &other) {
    if (*this == other) {
        return *this;
    }
    if (sz < 2) {
        if (other.size() > 1) {
            sz = other.size();
            v = other.v;
            cpd = 0;
        } else {
            sz = other.size();
            n = other.n;
            cpd = 1;
        }
    } else {
        if (other.size() > 1) {
            sz = other.size();
            v = other.v;
            cpd = 0;
        } else {
            sz = other.size();
            n = other.n;
            v.reset();
            cpd = 1;
        }
    }
    return *this;
}

void reverse(myvector &a) {
    if (a.sz < 2) {
        return;
    }
    a.make_copy();
    std::reverse((*a.v).begin(), (*a.v).end());
}

bool operator==(myvector const &a, myvector const &b) {
    if (a.size() != b.size()) {
        return 0;
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i])return 0;
    }
    return 1;
}

void myvector::make_copy() {
    cpd = 1;
    if (sz > 1) {
        std::shared_ptr<std::vector<unsigned int>> t = std::make_shared<std::vector<unsigned int>>(*v);
        v = t;
    }
}



