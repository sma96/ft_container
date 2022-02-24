#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <exception>
#include "iterator.hpp"
#include "enable_if.hpp"
#include "reverse_iterator.hpp"

namespace ft{

    template <class T, class Allocator = std::allocator<T> >
    class vector{

        public :
            typedef T                                        value_type;
            typedef Allocator                                allocator_type;
            typedef typename allocator_type::reference       reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::size_type       size_type;
            typedef typename allocator_type::difference_type difference_type;
            typedef typename allocator_type::pointer         pointer;
            typedef typename allocator_type::const_pointer   const_pointer;
            typedef ft::my_iterator<pointer>                 iterator;
            typedef ft::my_iterator<const pointer>           const_iterator;
            typedef ft::reverse_iterator<iterator>           reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>     const_reverse_iterator;
        
        private :
            allocator_type  alloc;
            pointer         p;
            size_t          _size;
            size_t          _capacity;
        
        public :

            class OutofRange: public std::exception{
                const char* what() const throw()
                {
                    return ("out of range");
                }
            };

            class InvalidSize: public std::exception{
                const char* what() const throw()
                {
                    return ("invalid size");
                }
            };

            vector(void): p(nullptr), _size(0), _capacity(0) {};
            explicit vector(const allocator_type& _alloc) : p(nullptr), _size(0), _capacity(0), alloc(_alloc) {};
            explicit vector(size_type n) : p(nullptr), _size(n), _capacity(n * 2)
            {
                p = alloc.allocate(_size);
            }

            vector(const vector& x) : p(nullptr), _size(0), _capacity(0), alloc(allocator_type())
            {
                *this = x;
            }

            vector(size_type n, const value_type& value, const allocator_type& _alloc = allocator_type()) : p(nullptr), _size(0), _capacity(0), alloc(_alloc)
            {
                if (n > 0)
                {
                    this->assign(n, value);
                }
            }

            template <class InputIterator>
                vector(InputIterator first, InputIterator last, const allocator_type& _alloc = allocator_type(), 
                        typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
                        : p(nullptr), _size(0), _capacity(0), alloc(_alloc)
                {
                    this->assign(first, last);
                }

            vector& operator=(const vector& x)
            {
                if (this != &x)
                {
                    this->clear();
                    alloc.deallocate(p, _capacity);
                    this->_size = x._size;
                    this->_capacity = x._capacity;
                    this->alloc = x.alloc();
                    this->p = alloc.allocate(this->_capacity);
                    for (size_type i = 0; i < this->_size; i++)
                    {
                        alloc.construct(p + i, x.p[i]);
                    }
                }
                return (*this);
            }


            reference       operator[](size_type n)
            {
                return (this->p[n]);
            }

            const_reference  operator[](size_type n) const
            {
                return (this->operator[](n));
            }

            reference       at(size_type n)
            {
                if (n >= _size || n < 0)
                    throw OutofRange();
                return (this->p[n]);
            }

            const_reference       at(size_type n) const
            {
                return (this->at(n));
            }

            reference   front()
            {
                return (this->p[0]);
            }

            const_reference   front() const
            {
                std::cout << "const" << std::endl;
                return (this->front());
            }

            // clear 함수 모든 요소를 지우고 size를 0으로 초기화
            void clear()
            {
                for (size_type i = 0; i < this->_size; i++)
                {
                    alloc.destroy(p + i);
                }
                this->_size = 0;
            }

            // 멤버 변수 관련
            size_type size() const
            {
                return (this->_size);
            }

            size_type capacity() const
            {
                return (this->_capacity);
            }

            bool empty() const
            {
                return (this->_size == 0);
            }











            // assign 함수 first부터 last까지의 요소들로 벡터를 만든다.
            template <class InputIterator>
                void    assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
                {
                    size_type new_size = static_cast<size_type>(std::distance(first, last));
                    if (new_size <= 0)
                        throw InvalidSize();
                    if (new_size <= _capacity)
                    {
                        size_type new_capacity = new_size * 2;
                        this->clear();
                        for (size_type i = 0; i < new_size; i++)
                        {
                            alloc.construct(p + i, *first);
                            first++;
                        }
                        _size = new_size;
                        _capacity = new_capacity;
                    }
                    else if (new_size > _capacity)
                    {
                        size_type new_capacity = new_size * 2;
                        pointer t_iter = alloc.allocate(new_capacity);
                        this->clear();
                        alloc.deallocate(p, _capacity);
                        for (size_type i = 0; i < new_size; i++)
                        {
                            alloc.construct(t_iter + i, *first);
                            first++;
                        }
                        p = t_iter;
                        _size = new_size;
                        _capacity = new_capacity;
                    }
                }
                // n만큼의 value값으로 벡터를 만든다.
            void assign(size_type n, const value_type& value)
            {
                if (n <= _capacity)
                {
                    size_type new_capacity = n * 2;
                    this->clear();
                    p = alloc.allocate(_capacity);
                    for (size_type i = 0; i < n; i++)
                    {
                        alloc.construct(p + i, value);
                    }
                    _size = n;
                    _capacity = new_capacity;
                }
                else if (n > _capacity)
                {
                    pointer temp;
                    size_type new_capacity = n * 2;
                    temp = alloc.allocate(new_capacity);
                    this->clear();
                    alloc.deallocate(p, _capacity);
                    for (size_type i = 0; i < n; i++)
                    {
                        alloc.construct(temp + i, value);
                    }
                    p = temp;
                    _size = n;
                    _capacity = new_capacity;
                }
            }

            iterator begin()
            {
                return (iterator(this->p));
            }

            iterator end()
            {
                return (iterator(this->p + this->_size));
            }

            const_iterator cbegin() const
            {
                return (const_iterator(this->p));
            }

            const_iterator cend() const
            {
                return (const_iterator(this->p + this->size));
            }

            reverse_iterator rbegin()
            {
                return (reverse_iterator(this->end()));
            }

            reverse_iterator rend()
            {
                return (reverse_iterator(this->begin()));
            }

            reverse_iterator crbegin()
            {
                return (reverse_iterator(this->end()));
            }

            const_reverse_iterator crend()
            {
                return (const_reverse_iterator(this->begin()));
            }
    };
};
#endif