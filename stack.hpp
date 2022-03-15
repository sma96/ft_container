#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <algorithm>
#include "vector.hpp"

namespace ft
{
    template <class T, class Container = ft::vector<T> >
        class stack: public ft::vector<T>{
            public:
                // typedef typename Container::iterator iterator;
                typedef Container                                container_type;
                typedef typename container_type::value_type      value_type;
                typedef typename container_type::reference       reference;
                typedef typename container_type::const_reference const_reference;
                typedef typename container_type::size_type       size_type;

            protected :
                container_type c;

            public :
                explicit stack(const container_type& _c = container_type()) : c(_c) {};

                stack(const stack &x)
                {
                    *this = x;
                }
                ~stack(void){}

                stack &operator=(const stack &x)
                {
                    this->c = x.c;
                    return (*this);
                }

                bool emtpy() const { return (this->c.empty()); }
                size_type   size() const { return (this->c.size()); }
                reference   top() { return (this->c.back()); };
                const_reference top() const { return (this->c.back()); }
                void    push(const value_type & val) { this->c.push_back(val); }
                void    pop() { this->c.pop_back(); }
            template <class _T, class _Container>
                friend    bool    operator==(const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs);
            template <class _T, class _Container>
                friend    bool    operator<(const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs);
            template <class _T, class _Container>
                friend    bool    operator>(const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs);
            template <class _T, class _Container>
                friend    bool    operator<=(const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs);
            template <class _T, class _Container>
                friend    bool    operator>=(const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs);
            template <class _T, class _Container>
                friend    bool    operator!=(const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs);
        };
    template <class _T, class _Container>
        bool    operator==(const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs)
        {
            return (lhs.c == rhs.c);
        }
    template <class _T, class _Container>
        bool    operator<(const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs)
        {
            return (lhs.c < rhs.c);
        }
    template <class _T, class _Container>
        bool    operator!=(const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs)
        {
            return (lhs.c != rhs.c);
        }
    template <class _T, class _Container>
        bool    operator>(const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs)
        {
            return (lhs.c > rhs.c);
        }
    template <class _T, class _Container>
        bool    operator<=(const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs)
        {
            return (lhs.c <= rhs.c);
        }
    template <class _T, class _Container>
        bool    operator>=(const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs)
        {
            return (lhs.c >= rhs.c);
        }
}

#endif
