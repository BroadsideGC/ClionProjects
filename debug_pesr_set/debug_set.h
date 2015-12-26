//
// Created by Big Z on 14.11.2015.
//

#ifndef DEBUG_SET_SET_H
#define DEBUG_SET_SET_H

#include <string>
#include <memory>
#include <assert.h>

typedef int value_type;
#define point std::shared_ptr<set::Node>
#define makeptr std::make_shared<set::Node>

struct set {
    struct Node;
    struct iterator;

    set();

    set(set const &other);

    ~set();

    bool empty();

    const size_t size() {
        return __sz;
    }

    iterator insert(value_type const &x);

    iterator erase(iterator x);

    iterator find(value_type const &x);

    void print();

    void clear();

    iterator begin();

    iterator end();


    struct Node {
        value_type i;
        point l;
        point r;
        point p;
        bool e;

        Node() : i(-1), l(nullptr), r(nullptr), p(nullptr) { };

        Node(bool e = 0) : e(e) { };

        Node(value_type i, point l, point r, point p, bool e = 0) : i(i), l(l), r(r), p(p), e(e) { };

        Node(value_type i, bool e = 0) : i(i), l(nullptr), r(nullptr), p(nullptr), e(e) { };

        ~Node() { }

        friend bool operator==(Node a, Node b) {
            return a.l == b.l && a.r == b.r && a.p == b.p && a.i == b.i && a.e == b.e;
        }

        friend bool operator!=(Node a, Node b) {
            return !(a == b);
        }
    };

    struct iterator {
        friend struct set;
        point it;
        set *cur;

        iterator() : it(makeptr(0)) { }

        iterator(set *lst, bool e = 0) : it(makeptr(e)), cur(lst) { }

        iterator(point n, set *lst) : it(n), cur(lst) { }

        iterator(value_type k, set *lst, bool e = 0) : it(makeptr(k, e)), cur(lst) { }

        ~iterator() { };

        point get() {
            return it;
        }

        value_type const &operator*() const {
            assert(it != nullptr && "No valid iterator");
            return it->i;
        }

        value_type const *operator->() const {
            assert(it != nullptr && "No valid iterator");
            return &it->i;
        }

        iterator &operator++() {
            assert(!it->e && "End iterator");
           assert((it->r != nullptr || it->p != nullptr) && "Not valid iterator");
            it = __next(it);
            return *this;
        }

        iterator operator++(int) {
            assert(!it->e && "End iterator");
           assert((it->r != nullptr || it->p != nullptr) && "Not valid iterator");
            iterator old = *this;
            ++*this;
            return old;
        }

        iterator &operator--() {
            assert(it->l != nullptr || it->p != nullptr && "Begin iterator or not valid");
            it = __prev(it);
            return *this;
        }

        iterator operator--(int) {
          assert(it->l != nullptr || it->p != nullptr && "Begin iterator or not valid");
            iterator old = *this;
            --*this;
            return old;
        }

        friend bool operator==(iterator a, iterator b) {
            assert(a.cur == b.cur && "Iterators from different places");
            return a.it->i == b.it->i && a.cur && b.cur;
        }

        friend bool operator!=(iterator a, iterator b) {
            assert(a.cur == b.cur && "Iterators from different places");
            return !(a == b);
        }

    private:
        point __minimum(point n) {
            return ((n->l == nullptr) ? n : __minimum(n->l));
        }

        point __maximum(point n) {
            return ((n->r == nullptr) ? n : __maximum(n->r));
        }

        point __next(point n) {
            point cr = cur->__root, suc = nullptr;
            while (cr != nullptr) {
                if (cr->e){
                    return cr;
                }
                if (cr->i > n->i) {
                    suc = cr;
                    cr = cr->l;
                }
                else {
                    cr = cr->r;
                }
            }

            return suc;
        }

        point __prev(point n) {
            point cr = cur->__root, suc = nullptr;
            while (cr != nullptr) {
                if (cr->e){
                    return suc;
                }
                if (cr->i < n->i || n->e) {
                    suc = cr;
                    cr = cr->r;
                }
                else {
                    cr = cr->l;
                }
            }
            return suc;
        }
    };

    point __root;

private:
    size_t __sz;
    iterator __begin;
    iterator __end;

    point __ins(point n, value_type const &x, point p);

    point __find(point n, value_type const &x);

    point __recerase(point n, value_type const &x);

    value_type __minimum(point n);

    void __clear(point n);

    void __dfs(point n);

};


#endif //DEBUG_SET_SET_H
