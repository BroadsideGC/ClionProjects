//
// Created by Big Z on 31.10.2015.
//

#include <c++/iostream>
#include "bilist.h"

bilist::~bilist() {

}

bilist::iterator bilist::insert(bilist::iterator it, const value_type &k) {
    assert(it.cur == mrk);
    iterator bg = __begin;
    iterator neww = iterator(k, it.it->p, it.it, mrk);
    if (it == bg) {
        __begin = neww;
    } else {
        neww.it->p->n = neww.get();
    }
    //std::cout << *neww << "\n";
    neww.it->n->p = neww.get();
    __sz++;
    return neww;
}

bilist::iterator bilist::erase(bilist::iterator it) {
    assert(it.cur == mrk && it != __end);
    if (it != __begin) {
        it.it->p->n = it.it->n;
    } else {
        __begin++;
    }
    it.it->n->p = it.it->p;
    __sz--;
    it.cur = nullptr;
    return ++it;
}

const bool bilist::empty() {
    return __sz == 0;
}

void bilist::clear() {
    while (__sz>0){
        pop_front();
    }
}

void bilist::push_front(const value_type &k) {
    insert(__begin, k);
}

void bilist::pop_front() {
    erase(__begin);
}

value_type bilist::front() {
    return *__begin;
}

void bilist::push_back(const value_type &k) {
    insert(__end, k);
}

void bilist::pop_back() {
    erase(--__end);
}

value_type bilist::back() {
    return __end.it->p->k;
}

bilist::bilist() {
    mrk = new int();
    __begin = iterator(0, mrk);
    __end = __begin;

    __sz = 0;
}

bilist::bilist(const bilist &l) {
    mrk = new int();
    __sz = l.__sz;
    iterator it = l.__begin;
    __begin = iterator(0, mrk);
    __end = __begin;
    for (int i = 0; i < __sz; i++) {
        push_back(*it);;
        it++;
    }
}

bilist::iterator bilist::begin() {
    return __begin;
}

bilist::iterator bilist::end() {
    return __end;
}
