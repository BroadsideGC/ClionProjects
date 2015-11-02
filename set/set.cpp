//
// Created by Big Z on 24.06.2015.
//

#include <iostream>
#include "set.h"


set::set() {
    root = nullptr;
    __size = 0;
}

set::set(set const &other) {
    __size = other.__size;
    root = other.root;
}

set::~set(){
}

set &set::operator=(set const &other) {
    __size = other.__size;
    root = other.root;;
    return *this;
}

bool set::empty() {
    return __size == 0;;
}

void set::insert(value_type const &x) {
    if (contains(x)) {
        return;;
    }
    root = makeptr(__ins(root, x));
    __size++;
}


void set::erase(value_type const &x) {
    if (!contains(x)) {
        return;
    }
    root = __recerase(root, x);
    __size--;
}

set::Node set::__ins(point n, value_type const &x) {
    if (n == nullptr) {
        return set::Node(x);
    }
    if (x < n->i) {
        n = makeptr(Node(n->i, makeptr(__ins(n->l, x)), n->r));
    } else if (x > n->i) {
        n = makeptr(Node(n->i, n->l, makeptr(__ins(n->r, x))));
    }
    return *n;
}

point set::__recerase(point n, value_type const &x) {
    if (n == nullptr) {
        return n;
    }
    if (x < n->i) {
        point t = __recerase(n->l, x);
        n = makeptr(Node(n->i, (t == nullptr) ? t : makeptr(*t), n->r));
    } else if (x > n->i) {
        point t = __recerase(n->r, x);
        n = makeptr(Node(n->i, n->l, (t == nullptr) ? t : makeptr(*t)));
    } else if (n->l != nullptr && n->r != nullptr) {
        value_type t = __minimum(n->r);
        point tmp = __recerase(n->r, t);
        n = makeptr(Node(t, n->l, (tmp == nullptr) ? tmp : makeptr(*tmp)));
    } else if (n->l != nullptr) {
        n = makeptr(*(n->l));
    } else if (n->r != nullptr) {
        n = makeptr(*(n->r));
    } else n = nullptr;
    return n;
}

bool set::contains(value_type const &x) {
    return __find(root, x);
}

bool set::__find(point n, value_type const &x) {
    if (n == nullptr)
        return 0;
    if (x == n->i)
        return 1;
    if (x < n->i)
        return __find(n->l, x);
    else return __find(n->r, x);
}

value_type set::__minimum(point n) {
    return ((n->l == nullptr) ? n->i : __minimum(n->l));
}

void set::print() {
    __dfs(root);
}

void set::__dfs(point n) {
    if (n == nullptr)
        return;
    if (n->l != nullptr) {
        __dfs(n->l);
    }
    std::cout << (n->i) << " ";
    if (n->r != nullptr) {
        __dfs(n->r);
    }
}