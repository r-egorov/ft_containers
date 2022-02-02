#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include "ft_utilities.hpp"
# include "pair.hpp"
# include "RBTree.hpp"

namespace ft {

template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Alloc = std::allocator<ft::pair<const Key,T> >
> class map {

    /*
    ** Member types, part I
    */
    public:
        typedef Key                                         key_type;
        typedef T                                           mapped_type;
        typedef ft::pair<const key_type, mapped_type>       value_type;
        typedef Compare                                     key_compare;
        typedef Alloc                                       allocator_type;
        typedef std::size_t                                 size_type;
        typedef std::ptrdiff_t                              difference_type;
        typedef typename allocator_type::reference          reference;
        typedef typename allocator_type::const_reference    const_reference;
        typedef typename allocator_type::pointer            pointer;
        typedef typename allocator_type::const_pointer      const_pointer;
    /*
    ** Nested value_comp class
    */
    private:
        class value_comp : public std::binary_function<value_type, value_type, bool> {
            protected:
                Compare                                     comp;
            public:
                typedef bool                                result_type;
                typedef value_type                          first_argument_type;
                typedef value_type                          second_argument_type;

                value_comp(Compare c) : comp(c) {}
                bool operator() (const value_type& x, const value_type& y) const {
                    return comp(x.first, y.first);
                }
        };
    /*
    ** Member types, part II
    */
    public:
        typedef value_comp                              value_compare;
    private:
        typedef RBTree<value_type, allocator_type, value_compare>   tree_type;
    public:
        typedef typename tree_type::iterator                iterator;
        typedef typename tree_type::const_iterator          const_iterator;
        typedef typename tree_type::reverse_iterator        reverse_iterator;
        typedef typename tree_type::const_reverse_iterator  const_reverse_iterator;
    /*
    ** Private fields
    */
    private:
        tree_type                                       _tree;
        key_compare                                     _comparator;
        allocator_type                                  _allocator;

    public:
        /*
        ** Constructors
        */
        // Default
        explicit map(
            const key_compare& comp = key_compare(),
            const allocator_type& alloc = allocator_type()
        ) : _tree(tree_type(alloc, comp)), _comparator(comp), _allocator(alloc) {}

        // Range
        template <class InputIterator>
        map(
            InputIterator first, InputIterator last,
            const key_compare& comp = key_compare(),
            const allocator_type& alloc = allocator_type()
        ) : _tree(tree_type(alloc, comp)), _comparator(comp), _allocator(alloc) {
            for (; first != last; first++) {
                _tree.insert(*first);
            }
            _tree.print();
        }

        // Copy
        map (const map& x);
};

} // Namespace brace

#endif