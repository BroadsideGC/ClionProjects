//
// Created by Big Z on 20.06.2015.
//

#include "myvector.h"

vector::vector() {
    __sz = 0;
    __size = 2;
    __a = __reserve(2);
}

vector::vector(vector const &other) {
    __a = __reserve(1);
    __sz = other.size();
    __size = __sz;
    __copy(other);
}

vector &vector::operator=(vector const &other) {
    __sz = other.size();
    __size = __sz;
    __copy(other);
    return *this;
}

vector::~vector() {
    for (int i = 0; i < __sz; i++) {
        (__a + i)->~basic_string();
    }
    operator delete(__a);
}

void vector::clear() {
    __sz = 0;
    iterator tmp = __reserve(2);
    operator delete(__a);
    __a = tmp;
}

void vector::push_back(value_type item) {
    if (__sz == __size) {
        __enlarge();
    }
    try {
        new((void *) (__a + __sz)) value_type(item);
        __sz++;
    } catch (...) {
        (__a + __sz)->~basic_string();
        throw;
    }
}

void vector::pop_back() {
    __sz--;
    iterator t = __a + __sz;
    t->~basic_string();
}

value_type &vector::back() {
    return *(begin() + __sz - 1);
}

value_type const &vector::back() const {
    return *(begin() + __sz - 1);
}

size_t vector::size() const {
    return __sz;
}

value_type &vector::operator[](size_t i) {
    return *(__a + i);
}

value_type const &vector::operator[](size_t i) const {
    return *(__a + i);
}

iterator vector::begin() {
    return __a;
}

const_iterator vector::begin() const {
    return __a;
}

iterator vector::end() {
    return __a + __sz;
}

const_iterator vector::end() const {
    return __a + __sz;
}

iterator vector::erase(iterator i) {
    iterator tmp = __reserve(__size);;
    size_t r = 0;
    iterator ret = end();
    try {
        for (size_t j = 0; j < __sz; j++) {
            if (__a + j != i) {
                new((void *) (tmp + r)) value_type(*(__a + j));
                r++;
            }
        }
        ret = tmp + (i - __a);
        operator delete(__a);
        __a = tmp;
        __sz--;

    } catch (...) {
        for (int j = 0; j <= r; j++) {
            (tmp + j)->~basic_string();
        }
        operator delete(tmp);
        throw;
    }
    return ret;
}

iterator vector::erase(iterator i1, iterator i2) {
    ptrdiff_t diff = (i2 - i1);
    iterator tmp = __reserve(__size);;
    size_t r = 0;
    iterator ret = end();
    try {
        for (size_t i = 0; i < __sz; i++) {
            if (__a + i < i1 || __a + i >= i2) {
                new((void *) (tmp + r)) value_type(*(__a + i));
                r++;
            }
        }
        ret = tmp + (i2 - __a);
        operator delete(__a);
        __a = tmp;
        __sz -= diff;
    } catch (...) {
        for (size_t i = 0; i <= r; i++) {
            (tmp + i)->~basic_string();
        }
        operator delete(tmp);
        throw;
    }
    return i2;
}

iterator vector::insert(iterator i, value_type const &item) {
    ptrdiff_t diff = (i - __a);
    push_back(item);
    i = __a + diff;
    size_t r = 0;
    try {
        for (iterator j = __a + __sz - 1; j != i; j--) {
            std::swap((*j), *(j - 1));
            r++;
        }
    } catch (...) {
        for (iterator j = __a + __sz - 1 - r; j != __a + __sz; j++) {
            std::swap((*j), *(j - 1));
        }
        throw;
    }
    return i;
}

iterator vector::__reserve(size_t size) {
    return static_cast<value_type *> (operator new(sizeof(value_type) * size));;
}

void vector::__copy(vector const &other) {
    iterator tmp = __reserve(other.__sz);
    size_t r = 0;
    try {
        for (int i = 0; i < other.size(); i++) {
            new((void *) (tmp + i)) value_type(other[i]);
            r++;
        }
        operator delete(__a);
        __a = tmp;
    } catch (...) {
        for (int i = 0; i <= r; i++) {
            (tmp + i)->~basic_string();
        }
        operator delete(tmp);
        throw;
    }
}

void vector::__enlarge() {
    iterator tmp = __reserve(__size * 2);
    size_t r = 0;
    try {
        for (int i = 0; i < __sz; i++) {
            new((void *) (tmp + i)) value_type(*(__a + i));
            r++;
        }
        operator delete(__a);
        __a = tmp;
        __size *= 2;
    } catch (...) {
        for (int i = 0; i <= r; i++) {
            (tmp + i)->~basic_string();
        }
        operator delete(tmp);
        throw;
    }
}
