#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
#include <vector>
#include "iterator_traits.hpp"

namespace ft{

    template <class T>
    class my_iterator : public ft::iterator<std::random_access_iterator_tag, T>
    {
        public :
            typedef typename ft::iterator_traits<T>::value_type value_type;
            typedef typename ft::iterator_traits<T>::pointer pointer;
            typedef typename ft::iterator_traits<T>::reference reference;
            typedef typename ft::iterator_traits<T>::difference_type difference_type;
            typedef typename ft::iterator_traits<T>::iterator_category iterator_catergory;

        private :
            pointer pos;
        
        public :
            my_iterator() : pos(nullptr) {};
            explicit my_iterator(pointer p) : pos(p) {};

            pointer base() const { return (pos); }

            template <typename U>
                my_iterator(const my_iterator<U>& iter) : pos(iter.base()) {};
            ~my_iterator(){};

            template <typename U>
                my_iterator& operator=(const my_iterator<U>& iter)
                {
                    pos = iter.base();
                    retunr (*this);
                }

            reference operator*() const {return ( *this->pos); }
            pointer operator->() const {return ( &(this->operator*())); }
            my_iterator operator+(difference_type n) const { return (my_iterator(pos + n)); }
            my_iterator& operator+=(difference_type n) { pos += n; return (*this); }
            my_iterator operator-(difference_type n) const { return (my_iterator(pos - n)); }
            my_iterator& operator-=(difference_type n) { pos -= n; return (*this); }
            my_iterator& operator++() { ++pos; return (*this); }
            my_iterator operator++(int) { my_iterator tmp(*this); ++pos; return (tmp); }
            my_iterator& operator--() { --pos; return (*this); }
            my_iterator operator--(int) { my_iterator tmp(*this); --pos; return (tmp); }
            reference operator[](difference_type n) const { return (*(*this + n)); }
    };

    template <typename iter1, typename iter2>
    bool operator==(const my_iterator<iter1>& x, const my_iterator<iter2>& y)
    { 
        return (x.base() == y.base());
    }

    template <typename iter1, typename iter2>
    bool operator!=(const my_iterator<iter1>& x, const my_iterator<iter2>& y)
    {
        return (x.base() != y.base());
    }

    template <typename iter1, typename iter2>
    bool operator<(const my_iterator<iter1>& x, const my_iterator<iter2>& y)
    { 
        return (x.base() < y.base());
    }

    template <typename iter1, typename iter2>
    bool operator>(const my_iterator<iter1>& x, const my_iterator<iter2>& y)
    {
        return (x.base() > y.base());
    }

    template <typename iter1, typename iter2>
    bool operator>=(const my_iterator<iter1>& x, const my_iterator<iter2>& y)
    {
        return (x.base() >= y.base());
    }

    template <typename iter1, typename iter2>
    bool operator<=(const my_iterator<iter1>& x, const my_iterator<iter2>& y)
    {
        return (x.base() <= y.base());
    }

    template <typename iter>
    typename my_iterator<iter>::difference_type operator-(const my_iterator<iter>& x, const my_iterator<iter>& y)
    {
        return (x.base() - y.base());
    }

    template <class iter>
    my_iterator<iter> operator+(typename my_iterator<iter>::difference_type n, const my_iterator<iter>& x)
    {
        return (my_iterator<iter>(x.base() + n));
    }
//////

//////
}

#endif