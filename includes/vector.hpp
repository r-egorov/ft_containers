#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>

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

        explicit vector(const allocator_type& alloc = allocator_type()) :
            _capacity(0), _size(0), _allocator(alloc) {
            _array = _allocator.allocate(_capacity);
        }
        
        
        // FIXME
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
/*
        vector(size_type count, 
        const T & value = T(), 
        const allocator_type & alloc = allocator_type())
		: _capacity(count), _size(count), _allocator(alloc) {
			_array = _allocator.allocate(_capacity);
			for (size_type i = 0; i < _size; i++)
				_allocator.construct(&(_array[i]), value);
		};

        template<class InputIt>
		vector(InputIt first, 
                InputIt last, 
                const allocator_type & alloc = allocator_type())
		: _size(0), _allocator(alloc) {
			InputIt tmp(first);
			while(tmp++ != last)
				_size++;

			_capacity = _size;
			_array = _allocator.allocate(_capacity);
			for(size_type i = 0;first != last; first++, i++)
				_allocator.construct(&(_array[i]), *first);
		}
        */

        template <class InputIterator>
        vector (
            InputIterator first,
            InputIterator last,
            const allocator_type& alloc = allocator_type()
        ) : _allocator(alloc) {
            _size = last - first;
            _capacity = last - first;
            _array = _allocator.allocate(_capacity);
            for (size_type i = 0; first != last; first++, i++) {
                _allocator.construct(_array + i, *first);
            }
        }
        

        vector (const vector& x);
        
        
    
};

}  // namespace brace

#endif