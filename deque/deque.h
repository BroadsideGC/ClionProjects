//
// Created by Big Z on 21.06.2015.
//

#ifndef DEQUE_H
#define DEQUE_H


#include <string>


struct deque {

    typedef std::string value_type;
    struct iterator;
    struct const_iterator;

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


    iterator insert(iterator i, value_type const &item);



    void __enlarge();

    iterator __reserve(size_t size);

    void __copy(deque const &other);

    struct iterator {
        value_type &operator*();

        value_type const &operator*() const;

        value_type *operator->();

        iterator();

        iterator(value_type *const a);

        iterator(const iterator &a);

        ~iterator();

        iterator &operator=(iterator const &other);

        bool operator==(iterator const &b);

        bool operator!=(iterator const &b);

        bool operator<(iterator const &b);

        bool operator<=(iterator const &b);

        bool operator>=(iterator const &b);

        bool operator>(iterator const &b);

        iterator operator++();

        iterator operator--();

        iterator operator++(int);


        iterator operator--(int);


        iterator operator+=(int const &a);

        iterator operator-=(int const &a);

    private:
        value_type *__ptr;
        deque *__parent;
    };

    struct const_iterator {
        value_type &operator*() const;

        value_type *operator->() const;

        const_iterator() ;

        const_iterator(iterator a);

        const_iterator(value_type *a);

        bool operator==(const_iterator const &b);

        bool operator!=(const_iterator const &b);

        bool operator<(const_iterator const &b);

        bool operator<=(const_iterator const &b);

        bool operator>=(const_iterator const &b);

        bool operator>(const_iterator const &b);

    private:
        value_type *__ptr;

    };
    iterator head;
    iterator tail;
    iterator final;
private:
    size_t sz;
    iterator a;
    size_t __size;

};

deque::iterator operator+(deque::iterator b,size_t const &a);

deque::iterator operator+(deque::iterator b,size_t const &a);

#endif //CYCLEBUF_CYCLEBUF_H
