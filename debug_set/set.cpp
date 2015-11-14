//
// Created by Big Z on 14.11.2015.
//

#include <c++/iostream>
#include "set.h"

set::set() {
    mrk = new int();

    __begin = iterator(-1, mrk, 1);
    __last = __end = __begin;
    __root = __end.it;
    __sz = 0;
}

set::set(set const &other) {
    mrk = new int();
    __sz = other.__sz;
    iterator it = other.__begin;
    __begin = iterator(0, mrk, 1);
    __last = __end = __begin;
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
    /*if (__sz==1||x> __begin.it->i) {
        __last.it->r = ret;
    }*/
    return ret;
}

void set::erase(set::iterator x) {
    iterator n = x;
    n++;
    __sz--;
    if (__sz == 0) {
        __root = __end.it;
        __begin == __end;
        return;
    }
    if (n.it->e){
        x.it = x.it->r;
        return;;
    }
    if (x.it->l == nullptr && x.it->r == nullptr) {
        if (x == __begin) {
            __begin++;
        }
        if (x.it->p->r == x.it) {
            x.it->p->r = nullptr;
        } else {
            x.it->p->l = nullptr;
        }
        return;
    }
    if (x.it->l == nullptr && x.it->r != nullptr) {
        if (x == __begin) {
            __begin++;
        }
        x.it->p->r = x.it->r;
        //x.it = nullptr;
        //x = nullptr;
        return;
    }
    if (x.it->l != nullptr && x.it->r == nullptr) {
        if (x == __begin) {
            __begin++;
        }
        x.it->p->l = x.it->l;
        //x.it = nullptr;
        //x = nullptr;
        return;
    }
    x.it->i = n.it->i;
    //std::cout<<n.it->i;;
    n.it->p->r = n.it->r;
    return;
}

set::iterator set::find(value_type const &x) {
    point ret = __find(__root, x);
    return (ret == nullptr ? __end : iterator(ret, mrk));
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
        return makeptr(Node(x, nullptr, __end.it, p));
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
