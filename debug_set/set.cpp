//
// Created by Big Z on 14.11.2015.
//

#include <iostream>
#include "set.h"

set::set() {
    __begin = iterator(-1, this, 1);
    __end = __begin;
    __root = __end.it;
    __sz = 0;
}

set::set(set const &other) {
    __sz = other.__sz;
    iterator it = other.__begin;
    __begin = iterator(0, this, 1);
    __end = __begin;
    __root = __end.it;
    for (int i = 0; i < __sz; i++) {
        insert(*it);;
        it++;
    }
}

set::~set() {

}

bool set::empty() {
    return __sz == 0;
}

set::iterator set::insert(value_type const &x) {
    __sz++;
    __root = __ins(__root, x, nullptr);
    iterator ret = find(x);
    if (__sz == 1 || x < __begin.it->i) {
        __begin = ret;
    }
    return ret;
}

set::iterator set::erase(set::iterator x) {
    assert(x != __end && "End iterator");
    assert(x.cur == this && x.it != nullptr && "Invalid iterator");
    iterator n = x;
    n++;
    __sz--;
    if (__sz == 0) {
        __root = __end.it;
        __begin = __end;
        return n;
    }
    if (x.it->l == nullptr && (x.it->r == nullptr || x.it->r->e)) {
        if (x == __begin) {
            __begin++;
        }
        if (x.it->p->r == x.it) {
            x.it->p->r = x.it->r;
        } else {
            x.it->p->l = nullptr;
        }

        return n;
    }
    if (x.it->l == nullptr && x.it->r != nullptr && !x.it->r->e) {
        if (x == __begin) {
            __begin++;
        }

        if (x.it->p != nullptr) {
            if (x.it->p->l == x.it) {
                x.it->p->l = x.it->r;
            } else {
                x.it->p->r = x.it->r;
            }
        } else {
            __root = x.it->r;
        }
        x.it->r->p = x.it->p;
        return n;
    }
    if (x.it->l != nullptr && (x.it->r == nullptr || x.it->r->e)) {
        iterator p = x;
        if (n == __end && x != begin()) {
            p--;
        }
        if (x == __begin) {
            __begin++;
        }
        if (x.it->p != nullptr) {
            if (x.it->p->l == x.it) {
                x.it->p->l = x.it->l;
            } else {
                x.it->p->r = x.it->l;
            }
        } else {
            __root = x.it->l;
        }
        x.it->l->p = x.it->p;
        p.it->r = __end.it;
        return n;
    }
    x.it->i = n.it->i;
    if (n.it->r != nullptr && !n.it->e) {
        n.it->r->p = n.it->p;
    }
    if (n.it->p != nullptr) {
        if (n.it->p->l == n.it) {
            n.it->p->l = n.it->r;
        } else {
            n.it->p->r = n.it->r;
        }
    } else {
        __root = n.it->l;
    }

    return n;
}

set::iterator set::find(value_type const &x) {
    point ret = __find(__root, x);
    return (ret == nullptr ? __end : iterator(ret, this));
}

void set::print() {
    __dfs(__root);
}

set::iterator set::begin() {
    return __begin;
}

set::iterator set::end() {
    return __end;
}

point set::__ins(point n, value_type const &x, point p = nullptr) {
    if (n == nullptr) {
        return makeptr(Node(x, nullptr, nullptr, p));
    }
    if (n->e) {
        return __end.it->p = makeptr(Node(x, nullptr, __end.it, p));
    }
    if (x < n->i) {
        n->l = __ins(n->l, x, n);
    } else if (x > n->i) {
        n->r = __ins(n->r, x, n);
    }
    return n;
}

point set::__find(point n, value_type const &x) {
    if (n == nullptr || n->e)
        return nullptr;
    if (x == n->i)
        return n;
    if (x < n->i)
        return __find(n->l, x);
    else return __find(n->r, x);
}

void set::clear() {
    __sz = 0;
    __begin = __end;
    __clear(__root);
    __root == __end.it;
}

void set::__clear(point n) {
    if (n == nullptr)
        return;
    if (n->l != nullptr) {
        __clear(n->l);
    }
    n->l = nullptr;
    if (n->r != nullptr) {
        __clear(n->r);
    }
    n->r = nullptr;
    n->p = nullptr;
    if (!n->e) {
        n = nullptr;
    }
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
