//
// Created by Big Z on 24.06.2015.
//

#include <c++/iostream>
#include "set.h"


set::set() {
    root = nullptr;
    __size = 0;
}

set::set(set const &other) {
    __size = other.__size;
    root = other.root;
}

set::~set() {

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
        return;
    }
    root = makeptr(ins(root, x));
    __size++;
}


void set::erase(value_type const &x) {
    if (!contains(x)) {
        return;
    }
    root = makeptr(recerase(root, x));
    __size--;
}

set::Node set::ins(point n, value_type const &x) {
    if (n == nullptr) {
        return set::Node(x);
    }
    if (x < n->i) {
        n = makeptr(Node(n->i, makeptr(ins(n->l, x)), n->r));
    } else if (x > n->i) {
        n = makeptr(Node(n->i, n->l, makeptr(ins(n->r, x))));
    }
    return *n;
}

set::Node set::recerase(point n, value_type const &x) {
    if (n == nullptr) {
        return *n;
    }
    if (x < n->i) {
        n = makeptr(Node(n->i, makeptr(recerase(n->l, x)), n->r));
    } else if (x > n->i) {
        n = makeptr(Node(n->i, n->l, makeptr(recerase(n->r, x))));
    } else if (n->l != nullptr && n->r != nullptr) {
        value_type t = minimum(n->r);
        n = makeptr(Node(t, n->l, makeptr(recerase(n->r, t))));
    } else if (n->l != nullptr) {
        n = makeptr(*(n->l));
    } else {
        n = makeptr(*(n->r));
    }
    return *n;
}

bool set::contains(value_type const &x) {
    return find(root, x);
}

bool set::find(point n, value_type const &x) {
    if (n == nullptr)
        return 0;
    if (x == n->i)
        return 1;
    if (x < n->i)
        return find(n->l, x);
    else return find(n->r, x);
}

value_type set::minimum(point n) {
    return ((n->l == nullptr) ? n->i : minimum(n->l));
}

void set::print() {
    dfs(root);
}

void set::dfs(point n) {
    if (n == nullptr)
        return;
    if (n->l != nullptr) {
        dfs(n->l);
    }
    std::cout << (n->i) << " ";
    if (n->r != nullptr) {
        dfs(n->r);
    }
}
