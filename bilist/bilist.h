//
// Created by Big Z on 31.10.2015.
//

#ifndef BILIST_BILIST_H
#define BILIST_BILIST_H

#include <stdio.h>
#include <memory>
#include <assert.h>
#include <string>

typedef int value_type;
#define point std::shared_ptr<bilist::Node>
#define makeptr std::make_shared<bilist::Node>

struct bilist;
struct bilist {
    struct Node;
    struct iterator;
    int* mrk;
    struct Node {
        value_type k;
        point p;
        point n;

        Node() : k(),p(nullptr), n(nullptr) { };

        Node(value_type k) : k(k), p(nullptr), n(nullptr) { };

        Node(value_type k, point p, point n) : k(k), p(p), n(n) { };


    };

    struct iterator {
        point it;
        int * cur;
        iterator() : it(makeptr()){ }
        iterator(int* lst) : it(makeptr()), cur(lst){ }
        iterator(point n, int* lst) : it(n), cur(lst) { }


        iterator(value_type k, int* lst) : it(makeptr(k)), cur(lst){ }

        point get() {
            return it;
        }

        iterator(value_type k, point p, point n,int * lst) : it(makeptr(Node(k, p, n))),cur(lst) { }

        value_type const &operator*() const {
            assert(it != nullptr);
            return it->k;
        }

        value_type const *operator->() const {
            assert(it != nullptr);
            return &it->k;
        }

        iterator &operator++() {
            assert(it->n!= nullptr);
            it = it->n;
            return *this;
        }

        iterator operator++(int) {
            assert(it->n!= nullptr);
            iterator old = *this;
            ++*this;
            return old;
        }

        iterator &operator--() {
            assert(it->p!= nullptr);
            it = it->p;
            return *this;
        }

        iterator operator--(int) {
            assert(it->p!= nullptr);
            iterator old = *this;
            --*this;
            return old;
        }

        friend bool operator==(iterator a, iterator b) {
            assert(a.cur == b.cur);
            return a.it->k == b.it->k&&a.it->n == b.it->n&&a.it->k == b.it->k;
        }

        friend bool operator!=(iterator a, iterator b) {
            assert(a.cur == b.cur);
            return !(a==b);
        }


    };

    bilist();

    bilist(const bilist &l);

    ~bilist();

    iterator insert(iterator it, const value_type &k);

    iterator erase(iterator it);

    const bool empty();

    void clear();

    void push_front(const value_type &k);

    void pop_front();

    value_type front();

    void push_back(const value_type &k);

    void pop_back();

    value_type back();

    iterator begin();

    iterator end();

private:
    size_t __sz;
    iterator __begin;
    iterator __end;
    iterator
};


#endif //BILIST_BILIST_H
