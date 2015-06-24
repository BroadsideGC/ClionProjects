//
// Created by Big Z on 21.06.2015.
//

#ifndef CYCLEBUF_CYCLEBUF_H
#define CYCLEBUF_CYCLEBUF_H


#include <string>

typedef std::string value_type;
using value_type = deque::value_type;
using iterator = deque::iterator;
struct deque {

    deque();

    deque(deque const &other);

    ~deque();

    deque &operator=(deque const &other);

    void clear();

    void push_back(value_type item);

    void pop_back();

    value_type &back();

    value_type const &back() const;

    void push_front(value_type item);

    void pop_front();

    value_type &front();

    value_type const &front() const;

    size_t size() const;

    bool empty() const;

    value_type &operator[](size_t i);

    value_type const &operator[](size_t i) const;

    iterator begin();

    const_iterator begin() const;

    iterator end();

    const_iterator end() const;

    iterator erase(iterator i);

    iterator erase(iterator i1, iterator i2);

    iterator insert(iterator i, value_type const &item);

    static iterator head;
    static iterator tail;
private:
    size_t sz;
    iterator a;
    size_t __size;

    void __enlarge();

    iterator __reserve(size_t size);

    void __copy(deque const &other);
};

struct deque::iterator {
    value_type &operator*();

    value_type *operator->();

    iterator();

    bool operator==(iterator const &a, iterator const &b) const;

    bool operator!=(iterator const &a, iterator const &b) const;

    bool operator<(iterator const &a, iterator const &b);

    bool operator<=(iterator const &a, iterator const &b);

    bool operator>=(iterator const &a, iterator const &b);

    bool operator>(iterator const &a, iterator const &b);

    iterator operator++();

    iterator operator--();

    iterator &operator+=(iterator const &a);

    iterator &operator-=(iterator const &a);

    iterator &operator+(iterator const &a);

    iterator &operator-(iterator const &a);

private:
    value_type *__ptr;
};

struct const_iterator {
    value_type &operator*();

    value_type *operator->();

    bool operator==(const_iterator const &a, const_iterator const &b);

    bool operator!=(const_iterator const &a, const_iterator const &b);

    bool operator<(const_iterator const &a, const_iterator const &b);

    bool operator<=(const_iterator const &a, const_iterator const &b);

    bool operator>=(const_iterator const &a, const_iterator const &b);

    bool operator>(const_iterator const &a, const_iterator const &b);

private:
    value_type *__ptr;
};

#endif //CYCLEBUF_CYCLEBUF_H
