//
// Created by Big Z on 20.06.2015.
//

#include "cyclebuf.h"

deque::deque() {
    sz = 0;
    head = tail=0;
    __size = 2;
    a = __reserve(2);
}

deque::deque(deque const &other) {
    sz = other.size();
    head = 0;
    tail = other.size()-1;
    __size = sz;
    __copy(other);
}

deque::~deque() {
    for (int i = head; i <= tail; (i++)%sz) {
        (a + i)->~basic_string();
    }
    operator delete(a);
}

void deque::clear() {
    sz = tail = head = 0;
    for (int i = head; i <= tail; i++) {
        (a + i)->~basic_string();
    }
}

void deque::push_back(value_type item) {
    if (sz == __size) {
        __enlarge();
    }
    try {
        new((void *) ((a + sz)%sz)) value_type(item);
        sz++;
    } catch (...) {
        ((a + sz)%sz)->~basic_string();
    }
}

void deque::pop_back() {
    sz--;
    iterator t = a + sz;
    t->~basic_string();
}

value_type &deque::back() {
    return *(begin() + sz - 1);
}

value_type const &deque::back() const {
    return *(begin() + sz - 1);
}

size_t deque::size() const {
    return sz;
}

value_type &deque::operator[](size_t i) {
    return *(a + i);
}

value_type const &deque::operator[](size_t i) const {
    return *(a + i);
}

iterator deque::begin() {
    return a;
}

const_iterator deque::begin() const {
    return a;
}

iterator deque::end() {
    return a + sz;
}

const_iterator deque::end() const {
    return a + sz;
}

iterator deque::erase(iterator i) {
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
    } catch (...) {
        for (int j = 0; j <= r; j++) {
            (tmp + j)->~basic_string();
        }
        operator delete(tmp);
    }
    return i;
}

iterator deque::erase(iterator i1, iterator i2) {
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
    } catch (...) {
        for (int i = 0; i <= r; i++) {
            (tmp + i)->~basic_string();
        }
        operator delete(tmp);
    }
    return i2;
}

iterator deque::insert(iterator i, value_type const &item) {
    iterator tmp = __reserve(__size);;
    size_t r = 0;
    try {
        for (int j = 0; j < sz; j++) {
            new((void *) (tmp + r)) value_type(((a + j != i) ? *(a + j) : item));
            r++;
        }
        operator delete(a);
        a = tmp;
        sz--;
    } catch (...) {
        for (int j = 0; j <= r; j++) {
            (tmp + j)->~basic_string();
        }
        operator delete(tmp);
    }
    return i;

}

iterator deque::__reserve(size_t size) {
    return static_cast<value_type *> (operator new(sizeof(value_type) * size));;
}

void deque::__copy(deque const &other) {
    iterator tmp = __reserve(other.sz);
    size_t r = 0;
    try {
        for (int i = 0; i < other.size(); i++) {
            new((void *) (tmp + i)) value_type(other[i]);
            r++;
        }
        operator delete(a);
        a = tmp;
    } catch (...) {
        for (int i = 0; i <= r; i++) {
            (tmp + i)->~basic_string();
        }
        operator delete(tmp);
    }
}

void deque::__enlarge() {
    iterator tmp = __reserve(__size * 2);
    size_t r = 0;
    try {
        for (int i = 0; i < sz; i++) {
            new((void *) (tmp + i)) value_type(*(a + i));
            r++;
        }
        operator delete(a);
        a = tmp;
        __size *= 2;
    } catch (...) {
        for (int i = 0; i <= r; i++) {
            (tmp + i)->~basic_string();
        }
        operator delete(tmp);
    }
}

void deque::push_front(value_type item) {

}

void deque::pop_front() {

}

value_type &deque::front() {
    return *(a+head);
}

value_type const &deque::front() const {
    return *(a+head);
}

bool deque::empty() const {
    return sz == 0;
}

