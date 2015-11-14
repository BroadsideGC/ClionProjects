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
    int *mrk;

    set();

    set(set const &other);

    ~set();

    bool empty();

    const size_t size() {
        return __sz;
    }

    iterator insert(value_type const &x);

    void erase(iterator x);

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

        Node(bool e=0):e(e){};

        Node(value_type i, point l, point r, point p, bool e=0) : i(i), l(l), r(r), p(p), e(e) { };

        Node(value_type i,bool e=0) : i(i), l(nullptr), r(nullptr), p(nullptr),e(e) { };

        ~Node() { }

        friend bool operator==(Node a, Node b) {
            // assert(a.cur == b.cur);
            return a.l == b.l && a.r == b.r && a.p == b.p && a.i == b.i&&a.e == b.e;
        }

        friend bool operator!=(Node a, Node b) {
            // assert(a.cur == b.cur);
            return !(a==b);
        }

        /*Node &operator=(Node const &other) {
            i = other.i;
            l = makeptr(*other.l);
            r = makeptr(*other.r);
            return *this;
        };*/
    };

    struct iterator {
        point it;
        int *cur;

        iterator() : it(makeptr(0)) { }

        iterator(int *lst, bool e=0) : it(makeptr(e)), cur(lst) { }

        iterator(point n, int *lst) : it(n), cur(lst) { }

        iterator(value_type k, int *lst, bool e=0) : it(makeptr(k,e)), cur(lst) { }

        point get() {
            return it;
        }

        value_type const &operator*() const {
            assert(it != nullptr);
            return it->i;
        }

        value_type const *operator->() const {
            assert(it != nullptr);
            return &it->i;
        }

        iterator &operator++() {
            //assert(it->n!= nullptr);
            it = __next(it);
            return *this;
        }

        iterator operator++(int) {
            //assert(it->n!= nullptr);
            iterator old = *this;
            ++*this;
            return old;
        }

        iterator &operator--() {
            //assert(it->p!= nullptr);
            it = __prev(it);
            return *this;
        }

        iterator operator--(int) {
            //assert(it->p!= nullptr);
            iterator old = *this;
            --*this;
            return old;
        }

        friend bool operator==(iterator a, iterator b) {
            // assert(a.cur == b.cur);
            return a.it->i == b.it->i && a.cur && b.cur;
        }

        friend bool operator!=(iterator a, iterator b) {
            //assert(a.cur == b.cur);
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
            if (n->r != nullptr) {
                return __minimum(n->r);
            }
            point p = n->p;
            while (p != nullptr && n == p->r) {
                n = p;
                p = p->p;
            }
            return p;
        }

        point __prev(point n) {
            if (n->l != nullptr) {
                return __maximum(n->l);
            }
            point p = n->p;
            while (p != nullptr && n == p->l) {
                n = p;
                p = p->p;
            }
            return p;
        }
    };

private:
    size_t __sz;
    iterator __begin;
    iterator __end;
    iterator __last;
    point __root;

    point __ins(point n, value_type const &x, point p);

    point __find(point n, value_type const &x);

    void __clear(point n);

    void __dfs(point n);
};


#endif //DEBUG_SET_SET_H
