#ifndef TREE_ITERATOR_HPP
#define TREE_ITERATOR_HPP

#include "tree.hpp"
#include "iterator.hpp"

namespace ft {

    template <class T, class Node>
        class   tree_iterator : public ft::iterator<std::bidirectional_iterator_tag, T>{
            
            public :
                typedef typename ft::iterator_traits<T>::value_type value_type;
                typedef typename ft::iterator_traits<T>::pointer pointer;
                typedef typename ft::iterator_traits<T>::reference reference;
                typedef typename ft::iterator_traits<T>::difference_type difference_type;
                typedef typename ft::iterator_traits<T>::iterator_category iterator_catergory;
            
            public :
                typedef Node*   node_ptr;

            private :
                node_ptr current;
                node_ptr nil;
                node_ptr _end;
            
            public :
                tree_iterator(void) : current(NULL), nil(NULL), _end(NULL) {};
                explicit tree_iterator(const node_ptr tmp, const node_ptr _nil, const node_ptr end) : current(tmp), nil(_nil), _end(end) {};

                template <class T2, class Node2>
                    tree_iterator(const tree_iterator<T2, Node2>& x) : current(x.base()), nil(x.nilbase()), _end(x.endbase()) {};

                ~tree_iterator(void){};

                node_ptr base(void) const { return (current); }
                node_ptr nilbase(void) const { return (nil); }
                node_ptr endbase(void) const { return (_end); }

                template <class U>
                    tree_iterator&  operator=(const tree_iterator<U, Node> it)
                    {
                        current = it.base();
                        nil = it.nilbase();
                        _end = it.endbase();
                        return (*this);
                    }

                reference       operator*() const
                {
                    return (this->current->data);
                }

                pointer         operator->() const
                {
                    return (&(this->operator*()));
                }

                tree_iterator&   operator++()
                {
                    node_ptr tmp;
                    
                    if (current == this->_end->parent || current == this->_end)
                    {
                        current = this->_end;
                        return (*this);
                    }
                    if (current->right != this->nil)
                    {
                        tmp = MinNode(current->right);
                        this->current = tmp;
                    }
                    else if (current->right == this->nil)
                    {
                        node_ptr parent = current->parent;
                        while (parent != this->nil && parent->right == current)
                        {
                            current = parent;
                            parent = parent->parent;
                        }
                        current = parent;
                    }
                    return (*this);
                }

                tree_iterator    operator++(int)
                {
                    tree_iterator tmp = *this;

                    this->operator++();
                    return (tmp);
                }

                tree_iterator&   operator--()
                {
                    node_ptr tmp;

                    
                    if (current == this->_end)
                    {
                        this->current = this->_end->parent;
                        return (*this);
                    }
                    if (current->left != this->nil)
                    {
                        tmp = MaxNode(current->left);
                        this->current = tmp;
                    }
                    else if (current->left == this->nil)
                    {
                        node_ptr parent = current->parent;
                        while (parent != this->nil && parent->left == current)
                        {
                            current = parent;
                            parent = parent->parent;
                        }
                        current = parent;
                    }
                    return (*this);
                }

                tree_iterator    operator--(int)
                {
                    tree_iterator tmp = *this;
                    this->operator--();
                    return (tmp);
                }

                Node*   MinNode(node_ptr node)
                {
                    if (node == NULL)
                        return (NULL);
                    while (node->left != this->nil)
                    {
                        node = node->left;
                    }
                    return (node);
                }

                Node*   MaxNode(node_ptr node)
                {
                    if (node == NULL)
                        return (NULL);
                    while (node->right != this->nil)
                    {
                        node = node->right;
                    }
                    return (node);
                }
        };
        template <class T, class Node>
            bool operator==(const tree_iterator<T, Node>& x, const tree_iterator<T, Node>& y)
            {
                return (x.base() == y.base());
            }
        template <class T, class Node>
            bool operator!=(const tree_iterator<T, Node>& x, const tree_iterator<T, Node>& y)
            {
                return (x.base() != y.base());
            }
}

#endif