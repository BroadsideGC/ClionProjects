//
// Created by Big Z on 20.06.2015.
//

#include "deque.h"

using value_type = deque::value_type;
using iterator=deque::iterator;
using const_iterator=deque::const_iterator;

deque::deque() {
    sz = 0;
    __size = 2;
    a = __reserve(2);
    head = a;
    tail = a;
}

deque::deque(deque const &other) {
    sz = other.size();;
    __size = sz;
    __copy(other);
    head = a;
    tail = a + sz;
}

deque::~deque() {
    for (iterator i = head; i != tail; i++) {
        (i)->~basic_string();
    }
    operator delete(&*a);
}

void deque::clear() {
    sz = 0;
    head = tail = a;
    for (iterator i = head; i != tail+1; i++) {
        (&*i)->~basic_string();
    }
}

void deque::push_back(value_type item) {
    if (sz == __size) {
        __enlarge();
    }
    try {
        new((void *) ((&*(tail + 1)))) value_type(item);
        sz++;
        tail++;
    } catch (...) {
        (&*(tail + 1))->~basic_string();
    }
}

void deque::pop_back() {
    sz--;
    (&*tail)->~basic_string();
    tail--;
}

value_type &deque::back() {
    return *tail;
}

value_type const &deque::back() const {
    return *const_iterator(tail);
}

size_t deque::size() const {
    return sz;
}

value_type &deque::operator[](size_t i) {
    return *(head + i);
}

value_type const &deque::operator[](size_t i) const {
    return *(head + i);
}

iterator deque::begin() {
    return head;
}

const_iterator deque::begin() const {
    return head;
}

iterator deque::end() {
    return tail + 1;
}

const_iterator deque::end() const {
    return tail + 1;
}

iterator deque::erase(iterator i) {
    iterator tmp = __reserve(__size);;
    size_t r = 0;
    try {
        for (iterator j = head; j != tail+1; j++) {
            if (j != i) {
                new((void *) (&*(tmp + r))) value_type(*j);
                r++;
            }
        }
        operator delete(&*a);
        a = tmp;
        head = a;
        sz--;
        tail = (a + (sz-1));
    } catch (...) {
        for (int j = 0; j <= r; j++) {
            (&*(tmp + j))->~basic_string();
        }
        operator delete(&*tmp);
    }
    return i;
}


iterator deque::insert(iterator i, value_type const &item) {
    iterator tmp = __reserve(__size);;
    size_t r = 0;
    try {
        for (iterator j = head; j != tail+1; j++) {
            new((void *) (&*(tmp + r))) value_type(((j != i) ? *(j) : item));
            r++;
        }
        operator delete(&*a);
        a = tmp;
        head = a;
        tail = a+sz;
        sz++;
    } catch (...) {
        for (int j = 0; j <= r; j++) {
            (&*(tmp + j))->~basic_string();
        }
        operator delete(&*tmp);
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
            new((void *) (&*(tmp + i))) value_type(other[i]);
            r++;
        }
        operator delete(&*a);
        a = tmp;
        head =a;
        tail = a+(sz-1);
    } catch (...) {
        for (int i = 0; i <= r; i++) {
            (&*(tmp + i))->~basic_string();
        }
        operator delete(&*tmp);
    }
}

void deque::__enlarge() {
    iterator tmp = __reserve(__size * 2);
    size_t r = 0;
    try {
        for (int i = 0; i < sz; i++) {
            new((void *) (&*(tmp + i))) value_type(*(a + i));
            r++;
        }
        operator delete(&*a);
        a = tmp;
        head =a;
        tail = a+(sz-1);
        __size *= 2;
    } catch (...) {
        for (int i = 0; i <= r; i++) {
            (tmp + i)->~basic_string();
        }
        operator delete(&*tmp);
    }
}

void deque::push_front(value_type item) {

}

void deque::pop_front() {

}

value_type &deque::front() {
    return *head;
}

value_type const &deque::front() const {
    return *head;
}

bool deque::empty() const {
    return sz == 0;
}


