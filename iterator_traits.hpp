#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

#include <iostream>
#include "iterator.hpp"
namespace ft{

    // struct input_iterator_tag  {};
    // struct output_iterator_tag {};
    // struct forward_iterator_tag       : public input_iterator_tag         {};
    // struct bidirectional_iterator_tag : public forward_iterator_tag       {};
    // struct random_access_iterator_tag : public bidirectional_iterator_tag {};

    template<class Category, class T, class Distance = ptrdiff_t,
            class Pointer = T*, class Reference = T&>
    struct iterator
    {
        typedef T         value_type;
        typedef Distance  difference_type;
        typedef Pointer   pointer;
        typedef Reference reference;
        typedef Category  iterator_category;
    };

    template <class Iterator>
    struct iterator_traits
    {
        typedef typename Iterator::difference_type difference_type;
        typedef typename Iterator::value_type value_type;
        typedef typename Iterator::pointer pointer;
        typedef typename Iterator::reference reference;
        typedef typename Iterator::iterator_category iterator_category;
    };

    template <class T>
    struct iterator_traits<T *>
    {
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
        typedef ptrdiff_t difference_type;
        typedef std::random_access_iterator_tag iterator_category;
    };

    template<class T>
    struct iterator_traits<const T *>
    {
        typedef const T value_type;
        typedef const T* pointer;
        typedef const T& reference;
        typedef ptrdiff_t difference_type;
        typedef std::random_access_iterator_tag iterator_category;
    };
};
#endif