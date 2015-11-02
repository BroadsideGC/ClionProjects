#include <iostream>
#include <string>

template<typename Cont>
struct hnode {
    Cont cont;
    hnode *p;
    hnode *l;
    hnode *r;

    hnode() : p(), l(), r() { };

    hnode(Cont const &cont) : cont(cont), p(), l(), r() { };

    hnode *find(Cont const &key) {
        if (this == nullptr)
            return nullptr;
        if (key == cont)
            return this;
        if (key < cont)
            return l->find(key);
        else
            return r->find(key);
    }

    void insert(hnode<Cont>& target)
    {
        if (target.cont < cont) {
            if (l)
                l->insert(target);
            else
            {
                l = &target;
                target.p = this;
            }
        }
        else
        {
            if (r)
                r->insert(target);
            else
            {
                r = &target;
                target.p = this;
            }
        }
    }

    bool is_left() const
    {
        return p->l == this;
    }

    hnode* min()
    {
        hnode* t = this;
        while (t->l)
            t = t->l;
        return t;
    }

    hnode* max()
    {
        hnode*t = this;
        while (t->r)
            t = t->r;
        return t;
    }

    hnode* next()
    {
        if (r)
            return r->min();

        hnode* t = this;
        while (!t->is_left())
            t = t->p;

        return t->p;
    }

    hnode* prev()
    {
        if (l)
            return l->max();

        hnode* t = this;
        while (t->is_left())
            t = t->p;

        return t->p;
    }

    void delete_all()
    {
        if (this == nullptr)
            return;

        l->delete_all();
        r->delete_all();
        delete this;
    }

    size_t size()
    {
        if (this == nullptr)
            return 0;

        return 1 + l->size() + r->size();
    }

};

template <typename Left, typename Right>
struct node {
    node() { }

    node(Left left, Right right)
            : lhalf(left), rhalf(right) { }

    hnode <Left> lhalf;
    hnode <Right> rhalf;
};


struct bimap {
    typedef int left_type;
    typedef std::string right_type;
    struct left_iterator;
    struct right_iterator;


    template<bool IL>
    struct iterator{
        typedef hnode<right_type> hntype;
        typedef node<left_type , right_type> ntype;
        hntype* hn;
        bool il = IL;

        iterator(hntype* hn)
                : hn(hn)
        {}

        right_type const& operator*() const
        {
            return hn->cont;
        }

        right_type const* operator->() const
        {
            return &hn->cont;
        }

        iterator& operator++()
        {
            hn = hn->next();
            return *this;
        }

        iterator operator++(int)
        {
            iterator old = *this;
            ++*this;
            return old;
        }

        iterator& operator--()
        {
            hn = hn->prev();
            return *this;
        }

        iterator operator--(int)
        {
            iterator old = *this;
            --*this;
            return old;
        }

        iterator<!il> flip() const
        {
            return iterator<!il>(get_node());
        }

        ntype* get_node() const
        {
            return node_traits<left_t, right_t, is_left>::get_node(hnode);
        }

    };

    bimap();

    bimap(bimap const &);

    left_iterator insert(left_type const &, right_type const &);

    left_iterator erase(left_iterator);

    right_iterator erase(right_iterator);

    left_iterator find_left(left_type const &);

    right_iterator find_right(right_type const &);

    bool empty() const;
};