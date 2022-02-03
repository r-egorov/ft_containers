#ifndef RBTREEPAIR_HPP
# define RBTREEPAIR_HPP

# define RED false
# define BLACK true

# include <memory>
# include "ft_utilities.hpp"
# include "pair.hpp"

# include <string>
# include <iostream>


namespace ft {

template<class Key, class Value>
class RBTreeNode;

template<class Key, class Value>
class RBTreeNode {
    /*
    ** Member types
    */
    public:
        typedef Key                                     key_type;
        typedef Value                                   mapped_type;
        typedef ft::pair<const key_type, mapped_type>   value_type;
        typedef value_type*                             pointer;

    /*
    ** Public fields
    */
    public:
        bool                                            is_nil;
        bool                                            color;
        pointer                                         value;
        RBTreeNode*                                     left;
        RBTreeNode*                                     right;
        RBTreeNode*                                     p;
        RBTreeNode()
            : is_nil(false), color(is_nil), value(NULL), left(NULL), right(NULL), p(NULL) {}

        explicit RBTreeNode(pointer value) : is_nil(false), color(RED), value(value), left(NULL), right(NULL), p(NULL) {}

        ~RBTreeNode() {}

        RBTreeNode(const RBTreeNode& other)
            : is_nil(other.is_nil), color(other.color), value(other.value), left(other.left), right(other.right), p(other.p) {}

        RBTreeNode&     operator=(const RBTreeNode& other) {
            if (this != &other) {
                is_nil = other.is_nil;
                color = other.color;
                value = other.value;
                left = other.left;
                right = other.right;
                p = other.p;
            }
            return (*this);
        }
    
    /*
    ** Helper functions
    */
    public:
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
        const RBTreeNode*     successor() const {
            if (!is_nil) {
                // if there is right subtree
                if (!right->is_nil) {
                    return (tree_min(right));
                }
                if (this->is_left_son()) {
                    return (this->p);
                }

                const RBTreeNode*     tmp = this;
                const RBTreeNode*     y = tmp->p;
                while (!y->is_nil && tmp == y->right) {
                    tmp = y;
                    y = y->p;
                }
                return (y);
            } else {
                return (this);
            }
        }
        
        RBTreeNode*     successor() {
            if (!is_nil) {
                // if there is right subtree
                if (!right->is_nil) {
                    return (tree_min(right));
                }
                if (this->is_left_son()) {
                    return (this->p);
                }

                RBTreeNode*     tmp = this;
                RBTreeNode*     y = tmp->p;
                while (!y->is_nil && tmp == y->right) {
                    tmp = y;
                    y = y->p;
                }
                return (y);
            } else {
                return (this);
            }
        }

        const RBTreeNode*     predecessor() const {
            if (!is_nil) {
                // if there is left subtree
                if (!left->is_nil) {
                    return (tree_max(left));
                }
                if (this->is_right_son()) {
                    return (this->p);
                }

                const RBTreeNode*     tmp = this;
                const RBTreeNode*     y = tmp->p;
                while (!y->is_nil && tmp == y->left) {
                    tmp = y;
                    y = y->p;
                }
                return (y);
            } else {
                return (this);
            }
        }
        
        RBTreeNode*     predecessor() {
            if (!is_nil) {
                // if there is left subtree
                if (!left->is_nil) {
                    return (tree_max(left));
                }
                if (this->is_right_son()) {
                    return (this->p);
                }

                RBTreeNode*     tmp = this;
                RBTreeNode*     y = tmp->p;
                while (!y->is_nil && tmp == y->left) {
                    tmp = y;
                    y = y->p;
                }
                return (y);
            } else {
                return (this);
            }
        }

        template<class Type>
        friend std::ostream	&operator << (std::ostream &o, RBTreeNode<Key, Value> const &obj);
};

template<class Key, class Value>
std::ostream	&operator << (std::ostream &o, RBTreeNode<Key, Value> const &obj) {
    if (obj.color == RED) {
        o << "\e[0;31m";
    }

    o << "Node(";

    if (obj.is_nil) {
        o << "NIL)";
    }
    else {
        o << *(obj.value) << ")";
    }
    o << "\e[0m";
    return (o);
}


template <class Key, class Value, bool is_const>
class RBTreeIterator {
    /*
    ** Member types
    */
    public:
        typedef RBTreeNode<const Key, Value>                                        node_type;
        typedef typename node_type::value_type                                      value_type;
        typedef typename std::bidirectional_iterator_tag                            iterator_category;
        typedef typename ft::iterator_traits<value_type*>::difference_type          difference_type;
        typedef typename choose<
            is_const,
            typename ft::iterator_traits<const value_type*>::pointer,
            typename ft::iterator_traits<value_type*>::pointer
        >::type                                                                     pointer;
        typedef typename choose<
            is_const,
            typename ft::iterator_traits<const value_type*>::reference,
            typename ft::iterator_traits<value_type*>::reference
        >::type                                                                     reference;
        typedef RBTreeNode<const Key, typename ft::non_const<Value>::type>*         node_pointer;

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
        RBTreeIterator(const RBTreeIterator<Key, Value, false>& other) : _p( other.getNodePtr() ) {}

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
        reference           operator*() const { return (*(_p->value)); }
        pointer             operator->() const { return (_p->value); }

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

        
        // Comparison operators 
        bool                operator==(const RBTreeIterator<Key, Value, is_const>& rhs) {
            return (this->_p == rhs._p);
        }

        bool                operator!=(const RBTreeIterator<Key, Value, is_const>& rhs) {
            return (this->_p != rhs._p);
        }

        bool                operator>=(const RBTreeIterator<Key, Value, is_const>& rhs) {
            return (this->_p >= rhs._p);
        }

        bool                operator<=(const RBTreeIterator<Key, Value, is_const>& rhs) {
            return (this->_p <= rhs._p);
        }

        bool                operator>(const RBTreeIterator<Key, Value, is_const>& rhs) {
            return (this->_p > rhs._p);
        }

        bool                operator<(const RBTreeIterator<Key, Value, is_const>& rhs) {
            return (this->_p < rhs._p);
        }
};


template <
    class Key,
    class Value,
    class Allocator = std::allocator<ft::pair<const Key, Value> >,
    class Compare = std::less<Key>
> class RBTree {
    /*
    ** Member types
    */
    public:
        typedef Key                                                         key_type;
        typedef Value                                                       mapped_type;
        typedef ft::pair<const Key, Value>                                  value_type;
        typedef Allocator                                                   allocator_type;
        typedef Compare                                                     comparator_type;
        typedef RBTreeNode<const key_type, mapped_type>                     node_type;
        typedef typename allocator_type::
            template rebind<node_type>::other                               node_allocator_type;
        typedef typename node_allocator_type::pointer                       node_pointer;
        typedef std::size_t                                                 size_type;
        typedef std::ptrdiff_t                                              difference_type;
        typedef mapped_type&                                                reference;
        typedef const mapped_type&                                          const_reference;
        typedef mapped_type*                                                pointer;
        typedef const mapped_type*                                          const_pointer;
        typedef ft::RBTreeIterator<const key_type, mapped_type, false>      iterator;
        typedef ft::RBTreeIterator<const key_type, mapped_type, true>       const_iterator;
        typedef ft::reverse_iterator<iterator>                              reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>                        const_reverse_iterator;

    private:
        node_pointer                    _nil;
        node_pointer                    _root;
        size_type                       _size;
        allocator_type                  _value_allocator;
        node_allocator_type             _node_allocator;
        comparator_type                 _comparator;
    
    /*
    ** Member functions
    */
    public:
        // Constructors
        RBTree(
            const allocator_type& alloc = allocator_type(),
            const comparator_type& compar = comparator_type()
        ) : _size(0), _value_allocator(alloc), _node_allocator(node_allocator_type()), _comparator(compar) {
            _nil = new node_type();
            _nil->is_nil = true;
            _nil->color = BLACK;
            _root = _nil;
        }

        //Copy constructor
        RBTree(const RBTree& other)
            : _size(other._size), _value_allocator(other._value_allocator),
              _node_allocator(other._node_allocator), _comparator(other._comparator) {
            _nil = new node_type();
            _nil->is_nil = true;
            _nil->color = BLACK;
            _root = _nil;
            // for (const_iterator it = other.begin(); it != other.end(); it++) {
            //     insert(*it);
            // }
        }

        ~RBTree() {
            //_destroyTree(this->_root);
            delete this->_nil;
        }
        
        // Operators
        RBTree&     operator=(const RBTree& other) {
            if (this != &other) {
                //_destroyTree(this->_root);
                this->root = this->_nil;
                this->_size = other._size;
                this->_value_allocator = other._value_allocator;
                this->_node_allocator = other._node_allocator;
                this->_comparator = other._comparator;
                // for (const_iterator it = other.begin(); it != other.end(); it++) {
                //     insert(*it);
                // }
            }
            return (*this);
        }

        iterator  insert(const value_type& val) {
            node_pointer  node;
            value_type*  val_copy = _value(val);
            node = _node_allocator.allocate(1);
            _node_allocator.construct(node, node_type(val_copy));
            _insertNode(node);
            _size++;
            return (iterator(node));
        }

        iterator    search_node(const key_type& key) const {
            return (_searchValueByKey(this->_root, key));
        }
           
        void    _deleteValueByKey(const key_type& key) {
            node_pointer    to_delete = _iterativeSearchByKey(_root, key);
            if (!to_delete->is_nil) {
                _deleteNode(to_delete);
                _value_allocator.destroy(to_delete->value);
                _value_allocator.deallocate(to_delete->value, 1);
                _node_allocator.destroy(to_delete);
                _node_allocator.deallocate(to_delete, 1);
            }
        }

        void    _deleteNode(node_pointer to_delete) {
            node_pointer   x;
            node_pointer   y = to_delete;
            bool    y_original_color = y->color;

            if (to_delete->left->is_nil) {
                x = to_delete->right;
                _transplant(to_delete, x);
            } else if (to_delete->right->is_nil) {
                x = to_delete->left;
                _transplant(to_delete, x);
            } else {
                y = _min(to_delete->right);
                y_original_color = y->color;
                x = y->right;
                if (y->p == to_delete) {
                    x->p = y;
                } else {
                    _transplant(y, y->right);
                    y->right = to_delete->right;
                    y->right->p = y;
                }
                _transplant(to_delete, y);
                y->left = to_delete->left;
                y->left->p = y;
                y->color = to_delete->color;
            }

            if (y_original_color == BLACK) {
                _deleteFixup(x);
            }
        }

        void    _deleteFixup(node_pointer x) {
            while (x != this->_root && x->color == BLACK) {
                if (x == x->p->left) {
                    node_pointer   w = x->p->right;
                    if (w->color == RED) {
                        w->color = BLACK;
                        x->p->color = RED;
                        _leftRotate(x->p);
                        w = x->p->right;
                    }
                    if (w->left->color == BLACK && w->right->color == BLACK) {
                        w->color = RED;
                        x = x->p;
                    } else {
                        if (w->right->color == BLACK) {
                            w->left->color = BLACK;
                            w->color = RED;
                            _rightRotate(w);
                            w = x->p->right;
                        }
                        w->color = x->p->color;
                        x->p->color = BLACK;
                        w->right->color = BLACK;
                        _leftRotate(x->p);
                        x = this->_root;
                    }
                } else {
                    node_pointer   w = x->p->left;
                    if (w->color == RED) {
                        w->color = BLACK;
                        x->p->color = RED;
                        _rightRotate(x->p);
                        w = x->p->left;
                    }
                    if (w->right->color == BLACK && w->left->color == BLACK) {
                        w->color = RED;
                        x = x->p;
                    } else {
                        if (w->left->color == BLACK) {
                            w->right->color = BLACK;
                            w->color = RED;
                            _leftRotate(w);
                            w = x->p->left;
                        }
                        w->color = x->p->color;
                        x->p->color = BLACK;
                        w->left->color = BLACK;
                        _rightRotate(x->p);
                        x = this->_root;
                    }
                }
            }
            x->color = BLACK;
        }
        
        void        remove(const key_type& key) {
            _deleteValueByKey(key);
            _size--;
        }
        
        size_type   size() const {
            return (_size);
        }

        iterator            end() {
            return (iterator(_nil));
        }

        const_iterator      end() const {
            return (const_iterator(_nil));
        }

        iterator            begin() {
            if (_size == 0) {
                return (iterator(_nil)); 
            }
            return(iterator(_min(_root)));
        }

        const_iterator           begin() const {
            if (_size == 0) {
                return (const_iterator(_nil)); 
            }
            return(const_iterator(_min(_root)));
        }

        reverse_iterator        rbegin() {
            if (_size == 0) {
                return (reverse_iterator(_nil));
            }
            return (reverse_iterator(_max(_root)));
        }

        const_reverse_iterator  rbegin() const {
            if (_size == 0) {
                return (const_reverse_iterator(_nil));
            }
            return (const_reverse_iterator(_max(_root)));
        }

        reverse_iterator        rend() {
            return (reverse_iterator(_nil));
        }	

        const_reverse_iterator  rend() const {
            return (const_reverse_iterator(_nil));
        }


        
        void    print() {
            std::cout << "=========TREE=========" << std::endl;
            _print(this->_root, 0);
            std::cout << "======================" << std::endl;
        }

    /*
    ** Helper functions
    */
    private:
        void    _print(node_type *head, int tabs_count) const {
            std::string tabs("");
            for (int i = 0; i < tabs_count; i++)
                tabs += " ";
            std::cout << tabs;

            if (!head->is_nil) {
                if (!head->p->is_nil) {
                    if (head == head->p->left) {
                        std::cout << "L: ";
                    } else {
                        std::cout << "R: ";
                    }
                } else {
                    std::cout << "*: ";
                }
                std::cout << *head << ", n: " << head << ", v: " << head->value << std::endl;

                tabs_count += 2;
                _print(head->left, tabs_count);
                _print(head->right, tabs_count);
            }
            else {
                std::cout << *head << std::endl;
            }
        }
        
        node_pointer   _min(node_pointer head) const {
            return (node_type::tree_min(head));
        }

        node_pointer   _max(node_pointer head) const {
            return (node_type::tree_max(head));
        }
        
        iterator    _searchValueByKey(node_pointer head, const key_type& key) const {
            return (iterator(_iterativeSearchByKey(head, key)));
        }

        node_pointer    _iterativeSearchByKey(node_pointer head, const key_type& key) const {
            while (!head->is_nil) {
                if (!(_comparator(key, head->value->first)) && !_comparator(head->value->first, key)) {
                    break ;
                }
                if (_comparator(key, head->value->first)) {
                    head = head->left;
                } else {
                    head = head->right;
                }
            }
            return (head);
        }

        void    _insertNode(node_pointer to_insert) {
            node_pointer   previous = this->_nil;
            node_pointer   current = this->_root;

            while (!current->is_nil) {
                previous = current;
                if (_comparator(to_insert->value->first, current->value->first)) {
                    current = current->left;
                } else {
                    current = current->right;
                }
            }
            
            to_insert->p = previous;

            if (previous->is_nil) {
                this->_root = to_insert;
            } else if (_comparator(to_insert->value->first, previous->value->first)) {
                previous->left = to_insert;
            } else {
                previous->right = to_insert;
            }
            to_insert->left = this->_nil;
            to_insert->right = this->_nil;
            to_insert->color = RED;
            _insertFixup(to_insert);
        }

        value_type*   _value(const value_type& val) {
            value_type*     created = _value_allocator.allocate(1);
            _value_allocator.construct(created, val);
            return (created);
        }
        
        void    _transplant(node_pointer u, node_pointer v) {
            if (u->p->is_nil) {
                this->_root = v;
            } else if (u == u->p->left) {
                u->p->left = v;
            } else {
                u->p->right = v;
            }
            v->p = u->p;
        }

        void    _leftRotate(node_pointer node) {
			node_pointer y = node->right;
			node->right = y->left;

			if (!y->left->is_nil)
				y->left->p = node;

			y->p = node->p;

			if (node->p->is_nil)
				this->_root = y;
			else if (node == node->p->left)
				node->p->left = y;
			else
				node->p->right = y;
			y->left = node;
			node->p = y;
		}

        void    _rightRotate(node_pointer node) {
			node_pointer y;

			y = node->left;
			node->left = y->right;
			if (!y->right->is_nil)
				y->right->p = node;
			y->p = node->p;
			if (node->p->is_nil)
				this->_root = y;
			else if (node == node->p->left)
				node->p->left = y;
			else
				node->p->right = y;
			y->right = node;
			node->p = y;
		}

        void    _insertFixup(node_pointer z) {
            while (z->p->color == RED) {
                if (z->p == z->p->p->left) {
                    node_pointer   uncle = z->p->p->right;
                    if (uncle->color == RED) {
                        z->p->color = BLACK;
                        uncle->color = BLACK;
                        z->p->p->color = RED;
                        z = z->p->p;
                    } else {
                        if (z == z->p->right) {
                            z = z->p;
                            _leftRotate(z);
                        }
                        z->p->color = BLACK;
                        z->p->p->color = RED;
                        _rightRotate(z->p->p);
                    }
                } else {
                    node_pointer   uncle = z->p->p->left;
                    if (uncle->color == RED) {
                        z->p->color = BLACK;
                        uncle->color = BLACK;
                        z->p->p->color = RED;
                        z = z->p->p;
                    } else {
                        if (z == z->p->left) {
                            z = z->p;
                            _rightRotate(z);
                        }
                        z->p->color = BLACK;
                        z->p->p->color = RED;
                        _leftRotate(z->p->p);
                    }
                }
            }
            this->_root->color = BLACK;
        }

        
    };

}  // Namespace brace

#endif