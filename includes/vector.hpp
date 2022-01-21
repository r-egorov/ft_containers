#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include "ft_utilities.hpp" // enable_if

namespace ft {

template <
    class T,
    class Allocator = std::allocator<T>
    > class vector {
    /*
    ** Member types
    */
    public:
        typedef T                                       value_type;
        typedef Allocator                               allocator_type;
        typedef std::size_t                             size_type;
        typedef std::ptrdiff_t                          difference_type;
        typedef value_type&                             reference;
        typedef const value_type&                       const_reference;
        typedef typename allocator_type::pointer        pointer;
        typedef typename allocator_type::const_pointer  const_pointer;
        /* FIXME
        typedef iterator
        typedef const_iterator
        typedef reverse_iterator
        typedef const_reverse_iterator
        */  
    
    /*
    ** Private fields
    */
    private:
        //pointer                                 _array;
        size_type                               _capacity;
        size_type                               _size;
        allocator_type                          _allocator;

    /*
    ** Member functions
    */
    public:
        pointer                                 _array; // FIXME

        // Default constructor
        explicit vector(const allocator_type& alloc = allocator_type()) :
            _capacity(0), _size(0), _allocator(alloc) {
            _array = _allocator.allocate(_capacity);
        }
        
        
        // Fill constructor
        explicit vector(
            size_type n,
            const value_type& val = value_type(),
            const allocator_type& alloc = allocator_type()
        ) : _capacity(n), _size(n), _allocator(alloc) {
            _array = _allocator.allocate(_capacity);
            for (size_type i = 0; i < _size; i++) {
                _allocator.construct(_array + i, val);
            }
        }

        // Range constructor
        template <class InputIterator>
        vector(
            InputIterator first,
            InputIterator last,
            const allocator_type& alloc = allocator_type(),
            typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0
        ) : _allocator(alloc) {
            _size = last - first;
            _capacity = last - first;
            _array = _allocator.allocate(_capacity);
            for (size_type i = 0; first != last; first++, i++) {
                _allocator.construct(_array + i, *first);
            }
        }
        
        // Operator= (needed for copy constructor)
        vector& operator= (const vector& x) {
            if (this == &x)
                return (*this);

            allocator_type      old_alloc = _allocator;
             _allocator = x._allocator;

            for (size_type i = 0; i < _size; i++) {
                old_alloc.destroy(_array + i);
            }

            _size = x._size;
            if (_capacity < _size) {
                if (_capacity != 0) {
                    old_alloc.deallocate(_array, _capacity);
                }
                _capacity = _size;
                _array = _allocator.allocate(_capacity);
            }

            for (size_type i = 0; i < _size; i++) {
                _allocator.construct(_array + i, x[i]);
            }
            return (*this);

        }

        // Copy constructor
        vector(const vector& x) : _capacity(0), _size(0) {
            *this = x;
        }

        reference       operator[] (size_type n) {
			return(_array[n]);
		}
		const_reference operator[] (size_type n) const {
			return(_array[n]);
		}
        
        
    
};

}  // namespace brace

#endif