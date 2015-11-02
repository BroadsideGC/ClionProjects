//
// Created by Big Z on 03.10.2015.
//

#ifndef LRUCACHE_LRU_CACHE_H
#define LRUCACHE_LRU_CACHE_H

#include <iostream>
#include <memory>
#include <vector>
#include <list>


typedef int key_type;
typedef double mapped_type;

struct lru_cache {


    lru_cache(size_t capacity);

    lru_cache(lru_cache const &);

    lru_cache &operator=(lru_cache const &);

    std::pair<bool, mapped_type &> lookup(key_type const &);

    bool erase(key_type const &);

    ~lru_cache();

    struct Node;
    typedef Node *point;

    struct Node {
        key_type k;
        mapped_type i;
        point l;
        point r;
        point p;
        point n;
        point pr;

        Node() : l(nullptr), r(nullptr), p(nullptr), n(nullptr), pr(nullptr) { };

        Node(mapped_type i, point l, point r) : i(i), l(l), r(r), p(nullptr), n(nullptr), pr(nullptr) { };

        Node(mapped_type i) : i(i), l(nullptr), r(nullptr), p(nullptr), n(nullptr), pr(nullptr) { };

        ~Node() { }

        Node &operator=(Node const &other) {
            i = other.i;
            k = other.k;
            return *this;
        };
    };

    point root;

private:
    size_t __cap;
    size_t __size;
    point __first;

    std::pair<bool, point> __recerase(point n, key_type const &x);

    std::pair<bool, std::pair<point, point>> __lookup(point n, key_type const &x);

    point __minimum(point n);

    std::vector<Node *> __empty;


    void __copy(lru_cache const &);

};


#endif //LRUCACHE_LRU_CACHE_H
