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
    __copy(other);
}

vector::~vector() {
    for (int i= 0;i<sz;i++){
        (a+i)->~basic_string();
    }
    operator delete(a);
}

void vector::clear() {
    sz = 0;
}

void vector::push_back(value_type item) {
    if (sz == __size) {
        __enlarge();
    }
    try {
        new((void *) (a + sz)) value_type(item);
        sz++;
    }catch(...){
        (a+sz)->~basic_string();
    }
}

void vector::pop_back() {
    sz--;
    iterator t=a+sz;
    t->~basic_string();
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
    iterator tmp = __reserve(__size);;
    size_t r = 0;
    try {
        for (int j = 0; j < sz; j++) {
            if (a + j != i) {
                new((void *) (tmp + r)) value_type(*(a + j));
                r++;
            }
        }
        operator delete(a);
        a = tmp;
        sz--;
    }catch(...){
        for (int j=0;j<=r;j++){
            (tmp+j)->~basic_string();
        }
        operator delete(tmp);
    }
    return i;
}

iterator vector::erase(iterator i1, iterator i2) {
    ptrdiff_t diff = (i2 - i1);
    iterator tmp = __reserve(__size);;
    size_t r = 0;
    try {
        for (int i = 0; i < sz; i++) {
            if (a + i < i1 || a + i >= i2) {
                new((void *) (tmp + r)) value_type(*(a + i));
                r++;
            }
        }
        operator delete(a);
        a = tmp;
        sz -= diff;
    }catch(...){
        for (int i=0;i<=r;i++){
            (tmp+i)->~basic_string();
        }
        operator delete (tmp);
    }
    return i2;
}

iterator vector::insert(iterator i, value_type const &item) {
    push_back(item);
    size_t r=0;
    try {
        for (iterator j = a + sz - 1; j != i; j--) {
            std::swap((*j), *(j - 1));
            r++;
        }
    } catch(...){
        for (iterator j = a + sz - 1 - r; j != a+sz; j++) {
            std::swap((*j), *(j - 1));
        }
    }
    return i;
}

iterator vector::__reserve(size_t size) {
    return static_cast<value_type *> (operator new(sizeof(value_type) * size));;
}

void vector::__copy(vector const &other) {
    iterator tmp = __reserve(other.sz);
    size_t r =0;
    try {
        for (int i = 0; i < other.size(); i++) {
            new((void *) (tmp + i)) value_type(other[i]);
            r++;
        }
        operator delete(a);
        a = tmp;
    } catch(...){
        for (int i=0;i<=r;i++){
            (tmp+i)->~basic_string();
        }
        operator delete (tmp);
    }
}

void vector::__enlarge() {
    iterator tmp = __reserve(__size * 2);
    size_t r=0;
    try {
        for (int i = 0; i < sz; i++) {
            new((void *) (tmp + i)) value_type(*(a + i));
            r++;
        }
        operator delete(a);
        a = tmp;
        __size *= 2;
    }catch(...){
        for (int i=0;i<=r;i++){
            (tmp+i)->~basic_string();
        }
        operator delete(tmp);
    }
}
