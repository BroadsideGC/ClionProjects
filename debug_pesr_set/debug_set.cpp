//
// Created by Big Z on 14.11.2015.
//

#include <iostream>
#include "debug_set.h"

set::set() {
    __begin = iterator(-1, this, 1);
    __end = __begin;
    __root = __end.it;
    __sz = 0;
}

set::set(set const &other) {
    __sz = other.__sz;
    iterator it = other.__begin;
    iterator e = other.__end;
    point r = other.__root;
    __begin = iterator(it.get(), this);
    __end = iterator(e.get(), this);
    __root = r;

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
    } else {
        __begin = find(*__begin);
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
    if (x == __begin) {
        __begin++;
    }
    __root = __recerase(__root, *x);
    __begin = find(__begin.it->i);
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
        n = makeptr(Node(x, nullptr, __end.it, p));
        __end.it->p = n;
        return n;
    }
    if (x < n->i) {
        n = makeptr(Node(n->i, __ins(n->l, x, n), n->r, p, n->e));
    } else if (x > n->i) {
        n = makeptr(Node(n->i, n->l, __ins(n->r, x, n), p, n->e));
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
    if (n.unique()) {
        if (n->l.unique() && n->l != nullptr) {
            __clear(n->l);
        }
        n->l = nullptr;
        if (n->r.unique() && n->r != nullptr) {
            __clear(n->r);
        }
        n->r = nullptr;
        n->p = nullptr;
    }
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

value_type set::__minimum(point n) {
    return ((n->l == nullptr) ? n->i : __minimum(n->l));
}

point set::__recerase(point n, value_type const &x) {
    if (n == nullptr) {
        return n;
    }
    if (n == __end.it){
        return n;
    }
    if (x < n->i) {
        point t = __recerase(n->l, x);
        n = makeptr(Node(n->i, (t == nullptr) ? t : makeptr(*t), n->r, n->p, n->e));
    } else if (x > n->i ) {
        point t = __recerase(n->r, x);
        n = makeptr(Node(n->i, n->l, (t == nullptr) ? t : makeptr(*t), n->p, n->e));
    } else if (n->l != nullptr && n->r != nullptr && !n->r->e) {
        value_type t = __minimum(n->r);
        point tmp = __recerase(n->r, t);
        n = makeptr(Node(t, n->l, (tmp == nullptr) ? tmp : makeptr(*tmp), n->p, n->e));
    } else if (n->l != nullptr) {
        point p = n->p;
        iterator last = __end;
        last--;
        if (x==*last){
            last--;
        }
        __end.it->p = last.it;
        last.it->r = __end.it;
        n = makeptr(*(n->l));
        n->p = p;
    } else if (n->r != nullptr) {
        point p = n->p;
        n = makeptr(*(n->r));
        if (n->e)__end.it = n;
        n->p = p;
    } else n = nullptr;
    return n;
}
