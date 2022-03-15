#ifndef TREE_HPP
#define TREE_HPP

#define BLACK 0
#define RED 1

#include <iostream>
#include <algorithm>
// #include "pair.hpp"
using namespace std;
//////////////////////////////////   comp 함수 value_comp로 수정할 것
namespace ft{

    template <class T>
        struct Node{
            T       data;
            Node    *parent;
            Node    *left;
            Node    *right;

            bool color;

            Node() : data(NULL), parent(NULL), left(NULL), right(NULL), color(BLACK) {};
            Node(const Node& tmp) : data(tmp.data), parent(tmp.parent), left(tmp.left), right(tmp.right), color(tmp.color) {};
            Node(T const& _data, Node* _parent = NULL, Node* _left = NULL, Node* _right = NULL, bool _color = RED) : data(_data), parent(_parent), left(_left), right(_right), color(_color) {};
        
            // Node& operator=(Node* _node)
            // {
            //     this->data = _node->data;
            //     this->parent = _node->parent;
            //     this->left = _node->left;
            //     this->right = _node->right;
            //     this->color = _node->color;

            //     return (*this);
            // }
        };

    template <class T, class Compare, class Node = Node<T>, class Allocator = std::allocator<Node> >
        class RBTree{
            
            public :
                typedef T           value_type;
                typedef Compare     value_compare;
                typedef size_t      size_type;
                typedef ptrdiff_t   difference_type;
                typedef Allocator   allocator_type;
                typedef Node        node;
                typedef Node*       node_ptr;

            private :
                node_ptr        root;
                node_ptr        nil;
                node_ptr        _end;
                allocator_type  _alloc;
                value_compare   _comp;
                size_type       _size;

            public :
                RBTree(const value_compare& comp = value_compare()) : root(NULL), _end(NULL), _alloc(allocator_type()), _comp(comp), _size(0) 
                {
                    this->nil = _alloc.allocate(1);
                    _alloc.construct(this->nil, value_type());
                    this->nil->color = BLACK;
                    this->_end = _alloc.allocate(1);
                    _alloc.construct(this->_end, value_type());
                    this->_end->parent = this->root;
                }
                ~RBTree()
                {
                    this->clear();
                    _alloc.destroy(this->nil);
                    _alloc.deallocate(this->nil, 1);
                    _alloc.destroy(this->_end);
                    _alloc.deallocate(this->_end, 1);
                }
                node_ptr    CreateNode(const value_type& val)
                {
                    node_ptr newnode;

                    newnode = _alloc.allocate(1);
                    _alloc.construct(newnode, val);
                    // cout << newnode->color << endl; 
                    return (newnode);
                }

                node_ptr    GetNil(void) const
                {
                    return (this->nil);
                }

                node_ptr    GetEnd(void) const
                {
                    return (this->_end);
                }

                allocator_type  GetAlloc(void) const
                {
                    return (this->_alloc);
                }

                void printnode()
                {
                    inorder(this->root);
                }

                void        swap(RBTree& x)
                {
                    size_type tmp_size = x._size;
                    allocator_type tmp_alloc = x._alloc;
                    node_ptr tmp_root = x.root;
                    node_ptr tmp_nil = x.nil;
                    node_ptr tmp_end = x._end;

                    x._size = this->_size;
                    x._alloc = this->_alloc;
                    x.root = this->root;
                    x.nil = this->nil;
                    x._end = this->_end;

                    this->_size = tmp_size;
                    this->_alloc = tmp_alloc;
                    this->root = tmp_root;
                    this->nil = tmp_nil;
                    this->_end = tmp_end;
                }
                
                void        clear(void)
                {
                    if (this->root)
                    {
                        clear(this->root);
                        this->root = NULL;
                    }
                    this->_size = 0;

                }

                void        clear(node_ptr node)
                {
                    if (node->left != this->nil)
                        clear(node->left);
                    if (node->right != this->nil)
                        clear(node->right);
                    _alloc.destroy(node);
                    _alloc.deallocate(node, 1);
                }

                size_type   GetSize(void) const
                {
                    return (this->_size);
                }
                
                size_type   GetMaxSize(void) const
                {
                    return (std::min<size_type>((difference_type)_alloc.max_size(), std::numeric_limits<difference_type>::max()));
                }

                void    inorder(node_ptr node)
                {
                    if (node == this->nil || node == NULL)
                        return ;
                    inorder(node->left);
                    std::cout << node->color << std::endl;
                    inorder(node->right);
                }

                node_ptr    Search(const value_type& val) const
                {
                    return (Search(this->root, val));
                }

                node_ptr    Search(node_ptr node, const value_type& val) const
                {
                    if (node == NULL || node == this->nil)
                        return (NULL);

                    if (node->data.first == val.first)
                        return (node);
                    if (!(_comp(node->data, val)))
                        return (Search(node->left, val));
                    else if (_comp(node->data, val))
                        return (Search(node->right, val));
                    return (NULL);
                }

                node_ptr    GetBegin() const
                {
                    if (this->_size == 0)
                        return (this->_end);
                    return (MinNode(this->root));
                }

                node_ptr MinNode(node_ptr node) const
                {
                    if (node == NULL)
                        return (NULL);

                    if (node->left == this->nil)
                        return (node);
                    return (MinNode(node->left));
                }

                node_ptr MaxNode(node_ptr node) const
                {
                    if (node == NULL)
                        return (NULL);

                    if (node->right == this->nil)
                        return (node);
                    return (MaxNode(node->right));
                }

                node_ptr    GrandParentNode(node_ptr node)
                {
                    if ((node->parent != NULL) && (node != NULL))
                            return (node->parent->parent);
                    return (NULL);
                }

                void    LeftRotate(node_ptr node)
                {
                    if (node == this->nil || node->right == this->nil)
                        return ;

                    node_ptr tmp;
                    
                    tmp = node->right;
                    node->right = node->right->left;
                    if (node->right != this->nil)
                        node->right->parent = node;
                    tmp->left = node;
                    tmp->parent = node->parent;
                    if (node->parent != this->nil)
                    {
                        if (node->parent->left == node)
                            node->parent->left = tmp;
                        else if (node->parent->right == node)
                            node->parent->right = tmp;
                    }
                    node->parent = tmp;
                    if (this->root == node)
                        this->root = tmp;
                    this->root->color = BLACK;

                }

                void    RightRotate(node_ptr node)
                {
                    if (node == this->nil || node->left == this->nil)
                        return ;
                    node_ptr tmp;

                    tmp = node->left;
                    node->left = node->left->right;
                    if (node->left != this->nil)
                        node->left->parent = node;
                    tmp->right = node;
                    tmp->parent = node->parent;
                    if (node->parent != this->nil)
                    {
                        if (node->parent->left == node)
                            node->parent->left = tmp;
                        else if (node->parent->right == node)
                            node->parent->right = tmp;
                    }
                    node->parent = tmp;
                    if (this->root == node)
                        this->root = tmp;
                    this->root->color = BLACK;
                }

                void    insert(const value_type& val)
                {
                    node_ptr newnode = CreateNode(val);

                    if (this->root == NULL)
                    {
                        this->root = newnode;
                        this->root->parent = this->nil;
                        this->root->left = this->nil;
                        this->root->right = this->nil;
                        this->root->color = BLACK;
                        this->_end->parent = this->root;
                    }
                    else
                    {
                        insert(newnode);
                        newnode->left = this->nil;
                        newnode->right = this->nil;
                        newnode->color = RED;
                        ReconstructTree(newnode);
                        if (!(_comp(newnode->data, this->_end->parent->data)))
                        {
                            this->_end->parent = newnode;
                            // std::cout << "end = " << this->_end->parent->data.first << std::endl;
                        }
                    }
                    this->_size += 1;
                    // cout << this->root->data.first << endl;
                }

                int    insert(node_ptr newnode)
                {
                    node_ptr currentnode = this->root;
                    node_ptr tmp = currentnode;

                    while (currentnode != this->nil)
                    {
                        tmp = currentnode;
                        if (!(_comp(currentnode->data, newnode->data)))
                            currentnode = currentnode->left;
                        else
                            currentnode = currentnode->right;
                    }
                    // newnode->parent = currentnode->parent;
                    if (!(_comp(tmp->data, newnode->data)))
                        tmp->left = newnode;
                    else
                        tmp->right = newnode;
                    currentnode = newnode;
                    newnode->parent = tmp;
                    return (0);
                    // cout << "hello" << endl;
                }

                void    ReconstructTree(node_ptr newnode)
                {
                    node_ptr parent = newnode->parent;
                    node_ptr uncle;
                    bool    leftParent;
                    node_ptr grandparent;

                    while (parent != this->nil && parent->color == RED)
                    {
                        grandparent = GrandParentNode(newnode);
                        if (grandparent == NULL)
                            return ;
                        leftParent = grandparent->left == parent;
                        uncle = leftParent ? grandparent->right : grandparent->left;
                        if (uncle != this->nil && uncle->color == RED)
                        {
                            uncle->color = BLACK;
                            parent->color = BLACK;
                            grandparent->color = RED;
                            this->root->color = BLACK;
                            parent = grandparent->parent;
                            newnode = grandparent;
                        }
                        else if (uncle == this->nil || uncle->color == BLACK)
                        {
                            if (leftParent)
                            {
                                if (newnode != parent->left) // LR case
                                {
                                    LeftRotate(parent);
                                    parent = newnode;
                                }
                                parent->color = BLACK;
                                grandparent->color = RED;
                                RightRotate(grandparent);
                            }
                            else
                            {
                                if (newnode != parent->right) // RL case
                                {
                                    RightRotate(parent);
                                    parent = newnode;
                                }
                                parent->color = BLACK;
                                grandparent->color = RED;
                                LeftRotate(grandparent);                            
                            }
                            break;
                        }
                    }
                    this->root->color = BLACK;
                }

                void        DeleteReconstruct(node_ptr parent, bool isLeft)
                {
                    node_ptr sibling = isLeft ? parent->right : parent->left;
                    int color_temp;

                    while (parent != this->nil)
                    {
                        if (sibling->color == RED)
                        {
                            color_temp = parent->color;
                            parent->color = sibling->color;
                            sibling->color = parent->color;
                            isLeft ? LeftRotate(parent) : RightRotate(parent);
                            sibling = isLeft ? parent->right : parent->left;
                        }
                        else if (sibling->color == BLACK)
                        {
                            if (sibling->left->color == BLACK && sibling->right->color == BLACK)
                            {   
                                sibling->color = RED;
                                if (parent->color == RED) // case 1
                                {
                                    parent->color = BLACK;
                                    break;
                                }
                                else if (parent->color == BLACK) // case 5
                                {
                                    if (parent->parent == this->nil)
                                        break;
                                    isLeft = parent == parent->parent->left ? true : false;
                                    parent = parent->parent;
                                    sibling = isLeft ? parent->right : parent->left;
                                }
                            }
                            else if (!(sibling->left->color == BLACK && sibling->right->color == BLACK) && isLeft)
                            {
                                if (sibling->left->color == RED && sibling->right->color == BLACK) // case 3
                                {
                                    color_temp = sibling->color;
                                    sibling->color = sibling->left->color;
                                    sibling->left->color = color_temp;
                                    RightRotate(sibling);
                                }
                                else if (sibling->right->color == RED)
                                {
                                    color_temp = parent->color;
                                    parent->color = sibling->color;
                                    sibling->color = color_temp;
                                    sibling->right->color = BLACK;
                                    LeftRotate(parent);
                                    break;
                                }   
                            }
                            else if (!(sibling->left->color == BLACK && sibling->right->color == BLACK) && !isLeft)
                            {
                                if (sibling->right->color == RED && sibling->left->color == BLACK) // case 2
                                {
                                    color_temp = sibling->color;
                                    sibling->color = sibling->right->color;
                                    sibling->right->color = color_temp;
                                    LeftRotate(sibling);
                                }
                                else if (sibling->left->color == RED)
                                {
                                    color_temp = parent->color;
                                    parent->color = sibling->color;
                                    sibling->color = color_temp;
                                    sibling->left->color = BLACK;
                                    RightRotate(parent);
                                    break;
                                }
                            }
                        }
                    }
                }

                void        DeleteNode(const value_type &val)
                {
                    node_ptr target = Search(val);
                    if (target == NULL)
                        return ;
                    DeleteNode(target);
                    if (this->_size == 0)
                        this->root = NULL;
                    if (this->root && this->root->right != this->nil)
                        this->_end->parent = MaxNode(this->root->right);
                    else
                        this->_end->parent = this->root;
                }

                void        DeleteNode(node_ptr target)
                {
                    int      target_color = target->color;
                    bool isLeft = target == target->parent->left ? true : false;

                    if (target->left == this->nil && target->right == this->nil)
                    {
                        if (target == this->root && this->_size == 1)
                        {
                            _alloc.destroy(target);
                            _alloc.deallocate(target, 1);
                            this->_size = 0;
                            return ;
                        }
                        if (isLeft == true)
                            target->parent->left = this->nil;
                        else if (isLeft == false)
                            target->parent->right = this->nil;
                        if (target_color == BLACK)
                            DeleteReconstruct(target->parent, isLeft);
                        _alloc.destroy(target);
                        _alloc.deallocate(target, 1);
                        this->_size -= 1;
                    }
                    else if (target->left == this->nil || target->right == this->nil)
                    {
                        node_ptr replace_node;
                        if (target->left == this->nil)
                        {
                            target->data = target->right->data;
                            replace_node = target->right;
                        }
                        else if (target->right == this->nil)
                        {
                            target->data = target->left->data;
                            replace_node = target->left;
                        }
                        if (target == target->parent->left)
                        {
                            target->parent->left = replace_node;
                            replace_node->parent = target->parent;
                        }
                        else if (target == target->parent->right)
                        {
                            target->parent->right = replace_node;
                            replace_node->parent = target->parent;
                        }
                        if (target_color == BLACK && replace_node->color == RED)
                            replace_node->color = BLACK;
                        if (target == this->root)
                            this->root = replace_node;
                        _alloc.destroy(target);
                        _alloc.deallocate(target, 1);
                        this->_size -= 1;
                    }
                    else if (target->left != this->nil && target->right != this->nil)
                    {
                        node_ptr replace_node = MaxNode(target->left);
                        target->data = replace_node->data;
                        if (replace_node->left != this->nil)
                        {
                            replace_node->parent->right = replace_node->left;
                            replace_node->left->parent = replace_node->parent;
                        }
                        DeleteNode(replace_node);
                    }
                }
        };
};

#endif