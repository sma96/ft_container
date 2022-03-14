#ifndef MAP_HPP
#define MAP_HPP

#include <functional>
#include <iostream>
#include <memory>
#include "reverse_iterator.hpp"
#include "pair.hpp"
#include "tree_iterator.hpp"
#include "tree.hpp"
#include "enable_if.hpp"
#include "lexicographical_compare.hpp"
#include "equal.hpp"

namespace ft{
    template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<Key, T> > >
        class map{

            public :

                typedef Key                                      key_type;
                typedef T                                        mapped_type;
                typedef ft::pair<key_type, mapped_type>    value_type;
                typedef Compare                                  key_compare;
                typedef Allocator                                allocator_type;
                typedef typename allocator_type::reference       reference;
                typedef typename allocator_type::const_reference const_reference;
                typedef typename allocator_type::pointer         pointer;
                typedef typename allocator_type::const_pointer   const_pointer;
                typedef typename allocator_type::size_type       size_type;
                typedef typename allocator_type::difference_type difference_type;


            public :
                class value_compare //: public std::binary_function<value_type,value_type,bool>
                {
                    // friend class map;
                    friend  class map;
                    
                    protected:
                        Compare comp;
                        value_compare(Compare c) : comp(c) {};
                    public:
                        bool operator()(const value_type& x, const value_type& y) const
                        {
                            return (comp(x.first, y.first));
                        }
                };

            public :
                // typedef ft::RBTree<value_type, value_compare>        tree;
                // typedef typename ft::Node<value_type>                         node;
                typedef typename ft::Node<value_type>*   node_ptr;

            public :
                typedef ft::tree_iterator<pointer, ft::Node<value_type> >               iterator;
                typedef ft::tree_iterator<const_pointer, ft::Node<value_type> >           const_iterator;
                typedef ft::reverse_iterator<iterator>                       reverse_iterator;
                typedef ft::reverse_iterator<const_iterator>                 const_reverse_iterator;

            private :
                ft::RBTree<value_type, value_compare>   _tree;
                allocator_type  _alloc;
                key_compare     _comp;

            public :
                explicit map(const key_compare& comp = key_compare(), const allocator_type alloc = allocator_type()) 
                : _tree(value_compare(comp)), _alloc(alloc),_comp(comp)  {};

                template <class InputIterator>
                    map(InputIterator first, InputIterator last, const key_compare comp = key_compare(), const allocator_type alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
                        : _tree(value_compare(comp)), _alloc(alloc), _comp(comp) 
                    {
                        this->insert(first, last);
                    }
                
                map(const map& x) : _tree(value_compare(x._comp)), _alloc(x._alloc),_comp(x._comp) 
                {
                    *this = x;
                }

                ~map() {};

                map&    operator=(const map& tmp)
                {
                    this->_tree.clear();
                    insert(tmp.begin(), tmp.end()); 
                    return (*this);
                }

                void    print()
                {
                    _tree.printnode();
                }


                iterator    begin()
                {
                    return (iterator(_tree.GetBegin(), _tree.GetNil(), _tree.GetEnd()));
                }

                iterator    begin() const
                {
                    return (iterator(_tree.GetBegin(), _tree.GetNil(), _tree.GetEnd()));
                }


                iterator   end()
                {
                    return (iterator(_tree.GetEnd(), _tree.GetNil(), _tree.GetEnd()));
                }
                  
                iterator   end() const
                {
                    return (iterator(_tree.GetEnd(), _tree.GetNil(), _tree.GetEnd()));
                }

                reverse_iterator    rbegin()
                {
                    return (reverse_iterator(this->end()));
                }

                const_reverse_iterator  rbegin() const
                {
                    return (const_reverse_iterator(this->end()));
                }

                reverse_iterator    rend()
                {
                    return (reverse_iterator(this->begin()));
                }

                const_reverse_iterator    rend() const
                {
                    return (const_reverse_iterator(this->begin()));
                }

                bool    empty() const
                {
                    return (this->_tree.GetSize() == 0);
                }

                size_type   size() const
                {
                    return (this->_tree.GetSize());
                }

                size_type   max_size() const
                {
                    return (this->_tree.GetMaxSize());
                }

                void    clear()
                {
                    _tree.clear();
                }

                void    swap(map& x)
                {
                    _tree.swap(x._tree);
                }

                allocator_type  get_allocator() const
                {
                    return (_tree.GetAlloc());
                }

                mapped_type&    operator[](const key_type& x)
                {
                    return (insert(ft::make_pair(x, mapped_type())).first->second);
                }

                key_compare     key_comp() const
                {
                    return (this->_comp);
                }

                value_compare   value_comp() const
                {
                    return (value_comp(this->_comp));
                }

                ft::pair<iterator, bool> insert(const value_type& val)
                {
                    node_ptr node = _tree.Search(val);

                    if (node != NULL)
                    {
                        return (ft::make_pair<iterator, bool>(iterator(node, _tree.GetNil(), _tree.GetEnd()), false));
                    }
                    _tree.insert(val);
                    return (ft::make_pair<iterator, bool>(iterator(_tree.Search(val), _tree.GetNil(), _tree.GetEnd()), true));
                }

                iterator    insert(iterator position, const value_type& val)
                {
                    node_ptr node = _tree.Search(val);

                    if (node != NULL)
                        return (iterator(node, _tree.GetNil(), _tree.GetEnd()));
                    (void)position;
                    _tree.insert(val);
                    return (iterator(_tree.Search(val), _tree.GetNil(), _tree.GetEnd()));
                }

                template <class InputIterator>
                    void insert(InputIterator first, InputIterator last)
                    {
                        for (; first != last; first++)
                        {
                            insert(*first);
                        }
                    }
                
                void    erase(iterator position)
                {
                    _tree.DeleteNode(*position);
                }

                size_type    erase(const key_type& x)
                {
                    node_ptr node = _tree.Search(ft::make_pair(x, mapped_type()));

                    if (node != NULL)
                    {
                        _tree.DeleteNode(ft::make_pair(x, mapped_type()));
                        return (1);
                    }
                    return (0);
                }

                void    erase(iterator first, iterator last)
                {
                    while (first != last)
                    {
                        erase(first++);
                    }
                }

                iterator find(const key_type& x)
                {
                    node_ptr node = this->_tree.Search(ft::make_pair(x, mapped_type()));

                    if (node == NULL)
                        return (this->end());
                    return (iterator(node, _tree.GetNil(), _tree.GetEnd()));
                }

                const_iterator find(const key_type& x) const
                {
                    node_ptr node = this->_tree.Search(ft::make_pair(x, mapped_type()));

                    if (node == NULL)
                        return (this->end());
                    return (const_iterator(node, _tree.GetNil(), _tree.GetEnd()));
                }

                size_type count(const key_type& x) const
                {
                    iterator it = this->find(x);

                    return (it == this->end() ? 0 : 1);
                }

                iterator lower_bound(const key_type& x)// x 보다 크거나 같은 첫번째 원소를 반환
                {
                    iterator b = this->begin();
                    iterator e = this->end();

                    while (b != e)
                    {
                        if (!(_comp((*b).first,  x)))
                            break;
                        b++;
                    }
                    return (b);
                }

                iterator lower_bound(const key_type& x) const // x 보다 크거나 같은 첫번째 원소를 반환
                {
                    const iterator b = this->begin();
                    const iterator e = this->end();

                    while (b != e)
                    {
                        if (!(_comp((*b).first,  x)))
                            break;
                        b++;
                    }
                    return (b);
                }

                iterator upper_bound(const key_type& x) // x 보다 큰 첫번째 원소를 반환
                {
                    iterator b = this->lower_bound(x);
                    iterator e = this->end();

                    if (b != e && (*b).first == x)
                        return (++b);
                    return (b);
                }

                iterator upper_bound(const key_type& x) const // x 보다 큰 첫번째 원소를 반환
                {
                    const iterator b = this->lower_bound(x);
                    const iterator e = this->end();

                    if (b != e && (*b).first == x)
                        return (++b);
                    return (b);
                }

                ft::pair<iterator, iterator> equal_range(const key_type& x)
                {
                    return (ft::make_pair(lower_bound(x), upper_bound(x)));
                }

                ft::pair<const iterator, const iterator> equal_range(const key_type& x) const
                {
                    return (ft::make_pair(lower_bound(x), upper_bound(x)));
                }
        };

        template <class Key, class T, class Compare, class Alloc>
            bool    operator==(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
            {
                return ((lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
            }

        template <class Key, class T, class Compare, class Alloc>
            bool    operator<(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
            {
                return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
            }

        template <class Key, class T, class Compare, class Alloc>
            bool    operator!=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
            {
                return (!(lhs == rhs));
            }

        template <class Key, class T, class Compare, class Alloc>
            bool    operator>(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
            {
                return (rhs < lhs);
            }

        template <class Key, class T, class Compare, class Alloc>
            bool    operator<=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
            {
                return ((lhs < rhs) || (lhs == rhs));
            }

        template <class Key, class T, class Compare, class Alloc>
            bool    operator>=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
            {
                return ((lhs > rhs) || (lhs == rhs));
            }
        
        template <class Key, class T, class Compare, class Alloc>
            bool    swap(map<Key, T, Compare, Alloc>& lhs, map<Key, T, Compare, Alloc>& rhs)
            {
                lhs.swap(rhs);
            }
}       
#endif