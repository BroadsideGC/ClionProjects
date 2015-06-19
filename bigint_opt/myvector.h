//
// Created by Big Z on 17.06.2015.
//

#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <vector>
#include <algorithm>
#include <memory>

struct myvector
{

public:
    myvector();
    myvector(size_t size);
    myvector(myvector const& other);
    ~myvector();
    void clear();
    void push_back(unsigned int item);
    void pop_back();
    void resize(size_t size);

    size_t size() const {
        return sz;
    }

    unsigned int const& operator [] (int i) const;
    unsigned int& operator [] (int i);

    myvector& operator = (myvector const& other);

    unsigned int const& back() const{
        if (sz < 2) {
            return n;
        }
        return (*v).back();
    }
    friend bool operator == (myvector const& a, myvector const& b);
    friend void reverse(myvector& a);
    void make_copy();

private:
    size_t sz;
    bool cpd;
    std::shared_ptr<std::vector <unsigned int>> v;
    unsigned int n;
};


bool operator == (myvector const& a, myvector const& b);
void reverse(myvector& a);


#endif //BIGINT_MYVECTOR_H



