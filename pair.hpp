#ifndef PAIR_HPP
#define PAIR_HPP

#include <iostream>
#include <memory>
namespace ft{

    template <class T1, class T2>
    struct pair{

        typedef T1 first_type;
        typedef T2 second_type;

        T1 first;
        T2 second;

        pair() : first(), second() {};
        pair(T1 const& t1, T2 const& t2) : first(t1), second(t2) {};

        template <typename U1, typename U2>
        pair(const pair<U1, U2>& p) : first(p.first), second(p.second) {};

        pair& operator=(pair const& p)
        {
            first = p.first;
            second = p.second;
            return (*this);
        }


    };
    template <typename U1, typename U2> 
    bool operator==(const pair<U1, U2>& lhs, const pair<U1, U2>& rhs)
    {
        return (lhs.first == rhs.first && lhs.second == rhs.second);
    };

    template <typename U1, typename U2>
    bool operator!=(const pair<U1, U2>& lhs, const pair<U1, U2>& rhs)
    {
        return !(lhs == rhs);
    };

    template <typename U1, typename U2>
    bool operator<(const pair<U1, U2>& lhs, const pair<U1, U2>& rhs)
    {
        return (lhs.first < rhs.first || (!(lhs.first < rhs.first) && lhs.second < rhs.second));
    };

    template <typename U1, typename U2>
    bool operator>(const pair<U1, U2>& lhs, const pair<U1, U2>& rhs)
    {
        return (rhs < lhs);
    };

    template <typename U1, typename U2>
    bool operator>=(const pair<U1, U2>& lhs, const pair<U1, U2>& rhs)
    {
        return !(lhs < rhs);
    };

    template <typename U1, typename U2>
    bool operator<=(const pair<U1, U2>& lhs, const pair<U1, U2>& rhs)
    {
        return !(rhs < lhs);
    };

    template <typename T1, typename T2>
    pair<T1, T2> make_pair(T1 t, T2 u)
    {
        return (pair<T1, T2>(t, u));
    };
}

#endif