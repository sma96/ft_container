 #ifndef REVERSE_ITERATOR_HPP
 #define REVERSE_ITERATOR_HPP

 #include "iterator.hpp"
 #include "iterator_traits.hpp"
 
 namespace ft{
    template <class T>
        class reverse_iterator : public ft::iterator<std::random_access_iterator_tag, T>
        {

            public :
                typedef T iterator_type;
                // typedef typename ft::iterator_traits<T>::value_type iterator_type;
                typedef typename ft::iterator_traits<T>::pointer pointer;
                typedef typename ft::iterator_traits<T>::reference reference;
                typedef typename ft::iterator_traits<T>::difference_type difference_type;
                typedef typename ft::iterator_traits<T>::iterator_category iterator_catergory;

            protected :
                iterator_type current;
            
            public :
                reverse_iterator(){}
                explicit reverse_iterator(iterator_type p) : current(p) {}

                template <typename U>
                reverse_iterator(const reverse_iterator<U>& iter) : current(iter.base()){}
                
                iterator_type base() const { return (current); }

                template <typename U>
                reverse_iterator& operator=(const reverse_iterator<U>& iter)
                {
                    current = iter.base();
                    retunr (*this);
                }
                
                reference operator*() {iterator_type tmp = current; return (*--tmp); }
                pointer operator->() {return ( &(this->operator*())); }
                reverse_iterator operator+(difference_type n) { return (reverse_iterator(current - n)); }
                reverse_iterator& operator+=(difference_type n) { current -= n; return (*this); }
                reverse_iterator operator-(difference_type n) { return (reverse_iterator(current + n)); }
                reverse_iterator& operator-=(difference_type n) const { current += n; return (*this); }
                reverse_iterator& operator++() { --current; return (*this); }
                reverse_iterator operator++(int) { reverse_iterator tmp(*this); --current; return (tmp); }
                reverse_iterator& operator--() { ++current; return (*this); }
                reverse_iterator operator--(int) { reverse_iterator tmp(*this); ++current; return (tmp); }
                reference operator[](difference_type n) { return (*(*this + n)); }
        };

        template <typename iter1, typename iter2>
        bool operator==(const reverse_iterator<iter1>& x, const reverse_iterator<iter2>& y)
        { 
            return (x.base() == y.base());
        }

        template <typename iter1, typename iter2>
        bool operator!=(const reverse_iterator<iter1>& x, const reverse_iterator<iter2>& y)
        {
            return (x.base() != y.base());
        }

        template <typename iter1, typename iter2>
        bool operator<(const reverse_iterator<iter1>& x, const reverse_iterator<iter2>& y)
        { 
            return (x.base() > y.base());
        }

        template <typename iter1, typename iter2>
        bool operator>(const reverse_iterator<iter1>& x, const reverse_iterator<iter2>& y)
        {
            return (x.base() < y.base());
        }

        template <typename iter1, typename iter2>
        bool operator>=(const reverse_iterator<iter1>& x, const reverse_iterator<iter2>& y)
        {
            return (x.base() <= y.base());
        }

        template <typename iter1, typename iter2>
        bool operator<=(const reverse_iterator<iter1>& x, const reverse_iterator<iter2>& y)
        {
            return (x.base() >= y.base());
        }

        template <typename iter1, typename iter2>
        typename reverse_iterator<iter1>::difference_type operator-(const reverse_iterator<iter1>& x, const reverse_iterator<iter2>& y)
        {
            return (y.base() - x.base());
        }

        template <class iter>
        reverse_iterator<iter> operator+(typename reverse_iterator<iter>::difference_type& n, const reverse_iterator<iter>& x)
        {
            return (my_iterator<iter>(x.base() - n));
        }
 }

 #endif