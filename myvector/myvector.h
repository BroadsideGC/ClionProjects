//
// Created by Big Z on 20.06.2015.
//

#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <string>

typedef std::string value_type;
typedef value_type *iterator;
typedef value_type const *const_iterator;

struct vector {
    vector();

    vector(vector const &other);

    ~vector();

    vector &operator=(vector const &other);

    void clear();

    void push_back(value_type item);

    void pop_back();

    value_type &back();

    value_type const &back() const;

    size_t size() const;

    value_type &operator[](size_t i);

    value_type const &operator[](size_t i) const;

    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;

    iterator erase(iterator i);

    iterator erase(iterator i1, iterator i2);

    iterator insert(iterator i, value_type const & item);

private:
    size_t sz;
    iterator a;
    size_t __size;
    void __enlarge();
    iterator __reserve(size_t size);
    void __copy(vector const &other);
};


#endif //MYVECTOR_MYVECTOR_H
