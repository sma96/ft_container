#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <exception>
#include "iterator.hpp"
#include "enable_if.hpp"
#include "reverse_iterator.hpp"
#include "equal.hpp"
#include "lexicographical_compare.hpp"

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
            typedef ft::my_iterator<const_pointer>           const_iterator;
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
            explicit vector(const allocator_type& _alloc) :  alloc(_alloc), p(nullptr), _size(0), _capacity(0) {};
            explicit vector(size_type n) : p(nullptr), _size(n), _capacity(n)
            {
                p = alloc.allocate(_size);
            }

            vector(const vector& x) : alloc(allocator_type()), p(nullptr), _size(0), _capacity(0) 
            {
                *this = x;
            }

            vector(size_type n, const value_type& value, const allocator_type& _alloc = allocator_type()) : alloc(_alloc), p(nullptr), _size(0), _capacity(0) 
            {
                if (n > 0)
                {
                    this->assign(n, value);
                }
            }

            ~vector()
            {
                for (size_type i = 0; i < this->_size; i++)
                {
                    alloc.destroy(this->p + i);
                }
                alloc.deallocate(this->p, this->_capacity);
            }

            template <class InputIterator>
                vector(InputIterator first, InputIterator last, const allocator_type& _alloc = allocator_type(), 
                        typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
                        : alloc(_alloc), p(nullptr), _size(0), _capacity(0) 
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
                    this->alloc = x.alloc;
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
                return (this->front());
            }

            reference back()
            {
                return (this->p[this->_size - 1]);
            }

            const_reference back() const
            {
                return (this->back());
            }

            // clear 함수 모든 요소를 지우고 size를 0으로 초기화
            void clear()
            {
                for (size_type i = 0; i < this->_size; i++)
                {
                    this->alloc.destroy(p + i);
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

            size_type   max_size() const
            {
                return (std::min<size_type>((difference_type)alloc.max_size(), std::numeric_limits<difference_type>::max()));
            }

            void    reserve(size_type new_cap)
            {
                if (new_cap > this->_capacity)
                {
                    size_type   old_size = this->_size;
                    size_type   old_cap = this->_capacity;

                    if (this->_capacity * 2 > new_cap)
                        this->_capacity *= 2;
                    else
                        this->_capacity = new_cap;
                    pointer temp = alloc.allocate(this->_capacity);
                    for (size_type i = 0; i < this->_size; i++)
                    {
                        alloc.construct(temp + i, p[i]);
                    }
                    this->clear();
                    this->_size = old_size;
                    alloc.deallocate(p, old_cap);
                    p = temp;
                }
            }

            void    resize(size_type count, value_type value = value_type())
            {
                if (count > this->_size)
                {
                    this->reserve(count);
                    for (size_type i = this->_size; i < count; i++)
                    {
                        alloc.construct(p + i, value);
                    }
                    this->_size = count;
                }
                else if (count < this->_size)
                {
                    for (size_type i = this->_size - 1; i > count; i--)
                    {
                        alloc.destroy(p + i);
                    }
                    this->_size = count;
                }
            }

            // element 추가 , 삭제
            void    push_back(const value_type& value)
            {
                this->reserve(this->_size + 1);
                alloc.construct(&this->p[this->_size], value);
                this->_size++;
            }

            void    pop_back()
            {
                alloc.destroy(this->p + this->_size);
                this->_size--;
            }


            // assign 함수 first부터 last까지의 요소들로 벡터를 만든다.
            template <class InputIterator>
                void    assign(InputIterator first, InputIterator last, \
                        typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
                {
                    size_type new_size = static_cast<size_type>(std::distance(first, last));

                    if (new_size <= 0)
                        throw InvalidSize();
                    if (new_size <= _capacity)
                    {
                        this->clear();
                        for (size_type i = 0; i < new_size; i++)
                        {
                            alloc.construct(p + i, *first);
                            first++;
                        }
                        _size = new_size;
                    }
                    else if (new_size > _capacity)
                    {
                        size_type new_capacity;
                        if (_capacity == 0)
                            new_capacity = new_size;
                        else
                            new_capacity = _capacity * 2;
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
                    // size_type new_capacity = _capacity * 2;
                    this->clear();
                    p = alloc.allocate(_capacity);
                    for (size_type i = 0; i < n; i++)
                    {
                        alloc.construct(p + i, value);
                    }
                    _size = n;
                    // _capacity = new_capacity;
                }
                else if (n > _capacity)
                {
                    pointer temp;
                    size_type new_capacity;
                    if (_capacity == 0)
                        new_capacity = n;
                    else
                        new_capacity = _capacity * 2;
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

            iterator insert(iterator pos, const value_type& value)
            {
                size_type dist = static_cast<size_type>(std::distance(this->begin().base(), pos.base()));
                // size_type old_cap = this->_capacity;
                size_type new_size = this->_size + 1;

                if (dist < 0)
                    throw InvalidSize();
                if (this->_capacity < new_size)
                {
                    this->reserve(this->_capacity * 2);
                }
                for (size_type i = new_size; i > dist; i--)
                {
                    alloc.construct(this->p + i, p[i - 1]);
                    alloc.destroy(this->p + i - 1);
                }
                p[dist] = value;
                this->_size = new_size;
                return (iterator(p + dist));
            }

            void    insert(iterator pos, size_type count, const T& value)
            {
                size_type dist = static_cast<size_type>(std::distance(this->begin().base(), pos.base()));

                if (dist < 0)
                    throw OutofRange();
                if (this->_capacity <= this->_size + count)
                {
                    if ((this->_size * 2) < (this->_size + count))
						this->reserve(count + this->_size);
					else
						this->reserve(this->_capacity * 2);
                }
                for (size_type i = 0; i < count; i++)
                {
                    this->insert(this->begin() + dist + i, value);
                }

            }
            
            template<class InputIterator>
                void    insert(iterator pos, InputIterator first, InputIterator last, \
                            typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
                {
                    size_type dist = static_cast<size_type>(std::distance(this->begin().base(), pos.base()));
                    size_type count = static_cast<size_type>(std::distance(first.base(), last.base()));

                    if (dist < 0)
                        throw OutofRange();
                    else if (dist > this->_size)
                        throw OutofRange();
                    if (this->_capacity <= this->_size + count)
                    {
                        if ((this->_size * 2) < (this->_size + count))
                            this->reserve(count + this->_size);
                        else
                            this->reserve(this->_capacity * 2);
                    }
                    for (size_type i = 0; i < count; i++)
                    {
                        this->insert(this->begin() + dist + i, *first);
                        first++;
                    }
                }

            iterator erase(iterator pos)
            {
                size_type dist = static_cast<size_type>(std::distance(this->begin().base(), pos.base()));
                size_type new_size = this->_size - 1;

                alloc.destroy(p + dist);
                for (size_type i = dist; i < new_size; i++)
                {
                    alloc.construct(p + i, p[i + 1]);
                    alloc.destroy(p + i + 1);
                }
                this->_size = new_size;

                return (iterator(this->begin() + dist));
            }

            iterator erase(iterator first, iterator last)
            {
                size_type dist = static_cast<size_type>(std::distance(this->begin().base(), first.base()));
                size_type it_dist = static_cast<size_type>(std::distance(first.base(), last.base()));

                for (size_type i = 0; i < it_dist; i++)
                {
                    this->erase(first);
                }

                return (iterator(this->begin() + dist));
            }

            void    swap(vector& other)
            {
                pointer temp_p;
                size_type temp_size;
                size_type temp_cap;
                allocator_type temp_alloc;

                temp_p = other.p;
                temp_size = other.size();
                temp_cap = other.capacity();
                temp_alloc = other.alloc;

                other.p = this->p;
                other._size = this->_size;
                other._capacity = this->_capacity;
                other.alloc = this->alloc;

                this->p = temp_p;
                this->_size = temp_size;
                this->_capacity = temp_cap;
                this->alloc = temp_alloc; 
            }

            iterator begin()
            {
                return (iterator(this->p));
            }

            iterator end()
            {
                return (iterator((this->p + this->_size)));
            }

            const iterator begin() const
            {
                return (iterator(this->p));
            }

            const iterator end() const
            {
                return (iterator((this->p + this->_size)));
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
    template <class T, class Alloc>
        bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
        {
            return ((lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
        }

    template <class T, class Alloc>
        bool operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
        {
            return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
        }

    template <class T, class Alloc>
        bool operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
        {
            return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
        }
    template <class T, class Alloc>
        bool operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
        {
            return (!(lhs == rhs));
        }
    template <class T, class Alloc>
        bool operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
        {
            return ((lhs < rhs) || (lhs == rhs));
        }
    template <class T, class Alloc>
        bool operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
        {
            return ((lhs > rhs) || (lhs == rhs));
        }
    template <class T, class Alloc>
        void swap(vector<T, Alloc>& lhs, vector<T, Alloc>& rhs)
        {
            lhs.swap(rhs);
        }

};
#endif