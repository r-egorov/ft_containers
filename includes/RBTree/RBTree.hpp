#ifndef RBTREE_HPP
# define RBTREE_HPP

# define RED false
# define BLACK true

# include <memory>

# include <string>
# include <iostream>

namespace ft {

template<class T>
class RBTreeNode {
    /*
    ** Member types
    */
    public:
        typedef T                                       value_type;
        typedef T*                                      pointer;

    /*
    ** Public fields
    */
    public:
        bool                                            is_nil;
        bool                                            color;
        pointer                                         key;
        RBTreeNode*                                     left;
        RBTreeNode*                                     right;
        RBTreeNode*                                     p;
        
        RBTreeNode(bool is_nil = false)
            : is_nil(is_nil), color(RED), key(NULL), left(NULL), right(NULL), p(NULL) {}

        RBTreeNode(pointer key)
            : is_nil(false), color(RED), key(key), left(NULL), right(NULL), p(NULL) {}

        ~RBTreeNode() {}

    private:  // Can't be copied
        RBTreeNode(const RBTreeNode& other)
            : is_nil(other.is_nil), color(other.color), key(other.key), left(other.left), right(other.right), p(other.p) {}

        RBTreeNode&     operator=(const RBTreeNode& other) {
            if (this != &other) {
                is_nil = other.is_nil;
                color = other.color;
                key = other.key;
                left = other.left;
                right = other.right;
                p = other.p;
            }
            return (*this);
        }
    
    /*
    ** Helper functions
    */
    private:
        static RBTreeNode*     tree_min(RBTreeNode* head) {
            if (!head->is_nil) {
                while (!head->left->is_nil) {
                    head = head->left;
                }
            }
            return (head);
        }

        static RBTreeNode*     tree_max(RBTreeNode* head) {
            if (!head->is_nil) {
                while (!head->right->is_nil) {
                    head = head->right;
                }
            }
            return (head);
        }

        bool    is_left_son() const {
            return (this == this->p->left);
        }
        
        bool    is_right_son() const {
            return (this == this->p->right);
        }

    /*
    ** Member functions
    */
    public:
        RBTreeNode*     successor() const {
            if (!is_nil) {
                // if there is right subtree
                if (!right->is_nil) {
                    return (tree_min(right));
                }
                if (this->is_left_son()) {
                    return (this->p);
                }

                RBTreeNode*     succ = this;
                while ((!succ->is_nil) && succ->is_a_right_son()) {
                    succ = succ->p;
                }
                return (succ);
            }
        }

    RBTreeNode*     predecessor() const {
            if (!is_nil) {
                // if there is left subtree
                if (!left->is_nil) {
                    return (tree_max(left));
                }
                if (this->is_right_son()) {
                    return (this->p);
                }

                RBTreeNode*     pred = this;
                while ((!pred->is_nil) && pred->is_a_left_son()) {
                    pred = pred->p;
                }
                return (pred);
            }
        }
};

template <class T, bool is_const>
class RBTreeIterator {
    /*
    ** Member types
    */
    public:
        typedef RBTreeNode<T>                                            node_type;
        typedef typename std::bidirectional_iterator_tag                 iterator_category;
        typedef typename ft::iterator_traits<T*>::value_type             value_type;
        typedef typename ft::iterator_traits<T*>::difference_type        difference_type;
        typedef typename choose<
            is_const,
            typename ft::iterator_traits<const T*>::pointer,
            typename ft::iterator_traits<T*>::pointer
        >::type                                                             pointer;
        typedef typename choose<
            is_const,
            typename ft::iterator_traits<const T*>::reference,
            typename ft::iterator_traits<T*>::reference
        >::type                                                             reference;
        typedef typename choose<
            is_const,
            const node_type*,
            node_type*
        >::type                                                             node_pointer;

    /*
    ** Member fields
    */
    protected:
        node_pointer      _p;

    /*
    ** Member functions
    */
    public:
        // Constructors
        RBTreeIterator() : _p(NULL) {}
        RBTreeIterator(node_pointer p) : _p(p) {}
        RBTreeIterator(const RBTreeIterator<T, false>& other) : _p( other._p ) {}

        // Destructor
        virtual ~RBTreeIterator() {}

        // Operators
        RBTreeIterator&     operator=(const RBTreeIterator& other) {
            if (this != &other) {
                this->_p = other._p;
            }
            return (*this);
        }

        // Access operators
        reference           operator*() const { return (*(_p->key)); }
        pointer             operator->() const { return (_p->key); }

        // Increment/Decrement
        RBTreeIterator&     operator++() {
            _p = _p->successor();
            return (*this);
        }

        RBTreeIterator      operator++(int) {
            RBTreeIterator  tmp(*this);
            _p = _p->successor();
            return (tmp);
        }
       
        RBTreeIterator&     operator--() {
            _p = _p->predecessor();
            return (*this);
        }

        RBTreeIterator      operator--(int) {
            RBTreeIterator  tmp(*this);
            _p = _p->predecessor();
            return (tmp);
        }

        node_pointer        getNodePtr() const {
            return (_p);
        }
};

template <
    class Key,
    class Allocator = std::allocator<Key>,
    class Compare = std::less<Key>
> class RBTree {
    /*
    ** Member types
    */
    public:
        typedef Key                                     value_type;
        typedef Allocator                               allocator_type;
        typedef Compare                                 comparator_type;
        typedef RBTreeNode<value_type>                  node_type;
        typedef typename allocator_type::
            template rebind<node_type>::other           node_allocator_type;
        typedef typename node_allocator_type::pointer   node_pointer;
        typedef std::size_t                             size_type;
        typedef std::ptrdiff_t                          difference_type;
        typedef value_type&                             reference;
        typedef const value_type&                       const_reference;
        typedef typename allocator_type::pointer        pointer;
        typedef typename allocator_type::const_pointer  const_pointer;
        typedef ft::RBTreeIterator<node_type, false>    iterator;
        typedef ft::vector_iterator<node_type, true>    const_iterator;
        typedef ft::reverse_iterator<iterator>          reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator;

    private:
        node_pointer                    _root;
        node_pointer                    _nil;
        size_type                       _size;
        allocator_type                  _key_allocator;
        node_allocator_type             _node_allocator;
        comparator_type                 _comparator;

    /*
    ** Member functions
    */
    public:
        // Constructors
        RBTree(
            const allocator_type& key_alloc = allocator_type(),
            const node_allocator_type& node_alloc = node_allocator_type(),
            const comparator_type& compar = comparator_type()
        ) : _size(0), _key_allocator(key_alloc), _node_allocator(node_alloc), _comparator(compar) {
            _nil = new node_type(true);
            _nil->color = BLACK;
            _root = _nil;
        }
        RBTree(const RBTree& other) : _nil(other._nil), _root(other._root) {}
        // Destructor
        ~RBTree() {
            delete this->_nil;
        }
        // Operators
        RBTree&     operator=(const RBTree& other) {
            if (this != &other) {
                delete this->_nil;
                _root = other._root;
                _nil = other._nil;
            }
            return (*this);
        }
};

// template<
//     class T,
//     class Allocator = std::allocator<T>
// > class RBTree {
//     public:
//         typedef RBTreeNode          Node;

//     private:
//         Node                        *root;
//         Node                        *nil;

        
//         Node*   _iterativeSearch(Node* head, int k) {
//             while (head != this->nil && k != head->key) {
//                 if (k < head->key) {
//                     head = head->left;
//                 } else {
//                     head = head->right;
//                 }
//             }
//             return (head);
//         }

//         void    _transplant(Node* u, Node* v) {
//             if (u->p == this->nil) {
//                 this->root = v;
//             } else if (u == u->p->left) {
//                 u->p->left = v;
//             } else {
//                 u->p->right = v;
//             }
//             v->p = u->p;
//         }

//         void    _leftRotate(Node* node) {
// 			Node* y = node->right;
// 			node->right = y->left;

// 			if (y->left != this->nil)
// 				y->left->p = node;

// 			y->p = node->p;

// 			if (node->p == this->nil)
// 				this->root = y;
// 			else if (node == node->p->left)
// 				node->p->left = y;
// 			else
// 				node->p->right = y;
// 			y->left = node;
// 			node->p = y;
// 		}

//         void    _rightRotate(Node* node) {
// 			Node* y;

// 			y = node->left;
// 			node->left = y->right;
// 			if (y->right != this->nil)
// 				y->right->p = node;
// 			y->p = node->p;
// 			if (node->p == this->nil)
// 				this->root = y;
// 			else if (node == node->p->left)
// 				node->p->left = y;
// 			else
// 				node->p->right = y;
// 			y->right = node;
// 			node->p = y;
// 		}

//         void    _insertFixup(Node* z) {
//             while (z->p->color == RED) {
//                 if (z->p == z->p->p->left) {
//                     Node*   uncle = z->p->p->right;
//                     if (uncle->color == RED) {
//                         z->p->color = BLACK;
//                         uncle->color = BLACK;
//                         z->p->p->color = RED;
//                         z = z->p->p;
//                     } else {
//                         if (z == z->p->right) {
//                             z = z->p;
//                             _leftRotate(z);
//                         }
//                         z->p->color = BLACK;
//                         z->p->p->color = RED;
//                         _rightRotate(z->p->p);
//                     }
//                 } else {
//                     Node*   uncle = z->p->p->left;
//                     if (uncle->color == RED) {
//                         z->p->color = BLACK;
//                         uncle->color = BLACK;
//                         z->p->p->color = RED;
//                         z = z->p->p;
//                     } else {
//                         if (z == z->p->left) {
//                             z = z->p;
//                             _rightRotate(z);
//                         }
//                         z->p->color = BLACK;
//                         z->p->p->color = RED;
//                         _leftRotate(z->p->p);
//                     }
//                 }
//             }
//             this->root->color = BLACK;
//         }

//         void    _deleteFixup(Node* x) {
//             while (x != this->root && x->color == BLACK) {
//                 if (x == x->p->left) {
//                     Node*   w = x->p->right;
//                     if (w->color == RED) {
//                         w->color = BLACK;
//                         x->p->color = RED;
//                         _leftRotate(x->p);
//                         w = x->p->right;
//                     }
//                     if (w->left->color == BLACK && w->right->color == BLACK) {
//                         w->color = RED;
//                         x = x->p;
//                     } else {
//                         if (w->right->color == BLACK) {
//                             w->left->color = BLACK;
//                             w->color = RED;
//                             _rightRotate(w);
//                             w = x->p->right;
//                         }
//                         w->color = x->p->color;
//                         x->p->color = BLACK;
//                         w->right->color = BLACK;
//                         _leftRotate(x->p);
//                         x = this->root;
//                     }
//                 } else {
//                     Node*   w = x->p->left;
//                     if (w->color == RED) {
//                         w->color = BLACK;
//                         x->p->color = RED;
//                         _rightRotate(x->p);
//                         w = x->p->left;
//                     }
//                     if (w->right->color == BLACK && w->left->color == BLACK) {
//                         w->color = RED;
//                         x = x->p;
//                     } else {
//                         if (w->left->color == BLACK) {
//                             w->right->color = BLACK;
//                             w->color = RED;
//                             _leftRotate(w);
//                             w = x->p->left;
//                         }
//                         w->color = x->p->color;
//                         x->p->color = BLACK;
//                         w->left->color = BLACK;
//                         _rightRotate(x->p);
//                         x = this->root;
//                     }
//                 }
//             }
//             x->color = BLACK;
//         }

//         Node*   _min(Node* head) {
//             while (head->left != this->nil) {
//                 head = head->left;
//             }
//             return (head);
//         }

//         Node*   _max(Node* head) {
//             while (head->right != this->nil) {
//                 head = head->right;
//             }
//             return (head);
//         }

//         void    _print(Node *head, int tabs_count) {
//             if (head != this->nil) {
//                 std::string tabs("");
//                 for (int i = 0; i < tabs_count; i++)
//                     tabs += " ";
                
//                 if (head->color == RED) {
//                     std::cout << "\e[0;31m";
//                 }

//                 std::cout << tabs;
//                 if (head->p != this->nil) {
//                     if (head == head->p->left) {
//                         std::cout << "L";
//                     } else {
//                         std::cout << "R";
//                     }
//                 } else {
//                     std::cout << "*";
//                 }
//                 std::cout
//                     << head->key
//                     << "\e[0m"
//                     << std::endl;

//                 tabs_count += 2;
//                 _print(head->left, tabs_count);
//                 _print(head->right, tabs_count);
//             }
//         }
    
//     public:
//         RBTree(void) : nil(new Node()) { root = this->nil; }
//         ~RBTree(void) {
//             delete this->nil;
//         }

//         void    insertNode(Node* to_insert) {
//             Node*   previous = this->nil;
//             Node*   current = this->root;

//             while (current != this->nil) {
//                 previous = current;
//                 if (to_insert->key < current->key) {
//                     current = current->left;
//                 } else {
//                     current = current->right;
//                 }
//             }

//             to_insert->p = previous;

//             if (previous == this->nil) {
//                 this->root = to_insert;
//             } else if (to_insert->key < previous->key) {
//                 previous->left = to_insert;
//             } else {
//                 previous->right = to_insert;
//             }

//             to_insert->left = this->nil;
//             to_insert->right = this->nil;
//             to_insert->color = RED;
//             _insertFixup(to_insert);
//         }

//         void    deleteNode(Node* to_delete) {
//             Node*   x;
//             Node*   y = to_delete;
//             bool    y_original_color = y->color;

//             if (to_delete->left == this->nil) {
//                 x = to_delete->right;
//                 _transplant(to_delete, x);
//             } else if (to_delete->right == this->nil) {
//                 x = to_delete->left;
//                 _transplant(to_delete, x);
//             } else {
//                 y = _min(to_delete->right);
//                 y_original_color = y->color;
//                 x = y->right;
//                 if (y->p == to_delete) {
//                     x->p = y;
//                 } else {
//                     _transplant(y, y->right);
//                     y->right = to_delete->right;
//                     y->right->p = y;
//                 }
//                 _transplant(to_delete, y);
//                 y->left = to_delete->left;
//                 y->left->p = y;
//                 y->color = to_delete->color;
//             }

//             if (y_original_color == BLACK) {
//                 _deleteFixup(x);
//             }
//         }

//         void    print() { return (_print(this->root, 0)); }
        
//         Node*   search(int k) { return (_iterativeSearch(this->root, k)); }
// };

}  // Namespace brace

#endif