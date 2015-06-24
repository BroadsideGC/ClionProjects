//
// Created by Big Z on 24.06.2015.
//

#ifndef SET_SET_H
#define SET_SET_H

#include <string>
#include <memory>

typedef std::string value_type;
#define point std::shared_ptr<set::Node>
#define makeptr std::make_shared<set::Node>

struct set {

    struct Node;

    set();

    set(set const &other);

    ~set();

    set &operator=(set const &other);

    bool empty();

    void insert(value_type const &x);

    void erase(value_type const &x);

    bool contains(value_type const &x);

    void print();

    struct Node {
        value_type i;
        point l;
        point r;
        point p;

        Node() : i(0), l(nullptr), r(nullptr) { };

        Node(value_type i, point l, point r) : i(i), l(l), r(r) { };

        Node(value_type i) : i(i), l(nullptr), r(nullptr) { };

        ~Node() {
            l.reset();
            r.reset();
            p.reset();
        };

        Node &operator=(Node const &other) {
            i = other.i;
            l = makeptr(*other.l);
            r = makeptr(*other.r);
            return *this;
        };
    };

    point root;


private :
    size_t __size;

    Node ins(point n, value_type const &x);

    Node recerase(point n, value_type const &x);

    value_type minimum(point n);

    bool find(point n, value_type const &x);

    void dfs(point n);
};


#endif //SET_SET_H
