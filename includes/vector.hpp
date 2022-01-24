#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include "iterator_traits.hpp"
# include "reverse_iterator.hpp"
# include "ft_utilities.hpp" // enable_if

namespace ft {

template <class T, bool is_const>
class vector_iterator {
    /*
    ** Member types
    */
    public:
        typedef typename ft::iterator_traits<T*>::iterator_category   iterator_category;
        typedef typename ft::iterator_traits<T*>::value_type          value_type;
        typedef typename ft::iterator_traits<T*>::difference_type     difference_type;
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

    protected:
        pointer      _p;

    /*
    ** Member functions
    */
    public:
        // Constructors
        vector_iterator() : _p(NULL) {}
        vector_iterator(pointer p) : _p(p) {}
        vector_iterator(const vector_iterator<T, false>& other) : _p( &(*other) ) {}
        
        // Destructor
        virtual ~vector_iterator() {}

        // Operators
        vector_iterator&    operator=(const vector_iterator& other) {
            if (this != &other) {
                this->_p = other._p;
            }
            return (*this);
        }

        // Access operators
        reference           operator*() const { return *_p; }
        pointer             operator->() const { return _p; }
        reference           operator[](const difference_type n) const { return (_p + n); }

        // Increment/Decrement
        vector_iterator&    operator++() {
            ++_p;
            return (*this);
        }

        vector_iterator     operator++(int) {
            vector_iterator tmp(*this);
            ++_p;
            return (tmp);
        }

        vector_iterator&    operator--() {
            --_p;
            return (*this);
        }

        vector_iterator     operator--(int) {
            vector_iterator tmp(*this);
            --_p;
            return (tmp);
        }

        vector_iterator     operator+(const difference_type n) {
            return (vector_iterator(_p + n));
        }

        vector_iterator     operator-(const difference_type n) {
            return (vector_iterator(_p - n));
        }

        difference_type     operator-(const vector_iterator& other) {
            return (_p - other._p);
        }

        vector_iterator&     operator+=(const difference_type n) {
            _p += n;
            return (*this);
        }

        vector_iterator     operator-=(const difference_type n) {
            _p -= n;
            return (*this);
        }

        // Comparison operators 
        bool                operator==(const vector_iterator<T, is_const>& rhs) {
            return (this->_p == rhs._p);
        }

        bool                operator!=(const vector_iterator<T, is_const>& rhs) {
            return (this->_p != rhs._p);
        }

        bool                operator>=(const vector_iterator<T, is_const>& rhs) {
            return (this->_p >= rhs._p);
        }

        bool                operator<=(const vector_iterator<T, is_const>& rhs) {
            return (this->_p <= rhs._p);
        }

        bool                operator>(const vector_iterator<T, is_const>& rhs) {
            return (this->_p > rhs._p);
        }

        bool                operator<(const vector_iterator<T, is_const>& rhs) {
            return (this->_p < rhs._p);
        }
};

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
        typedef ft::vector_iterator<T, false>           iterator;
        typedef ft::vector_iterator<T, true>            const_iterator;
        typedef ft::reverse_iterator<iterator>          reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator;
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

        ~vector() {
            for (size_type i = 0; i < _size; i++) {
                _allocator.destroy(_array + i);
            }
            _allocator.deallocate(_array, _capacity);
        }

        /*
        ** Iterators
        */
        iterator                 begin() {
            return (iterator(_array));
        }

        const_iterator           begin() const {
            return (const_iterator(_array));
        }
        
        iterator                 end() {
            return (iterator(_array + _size));
        }

        const_iterator           end() const {
            return (const_iterator(_array + _size));
        }

        reverse_iterator     rbegin() {
            return ( reverse_iterator(end()) );
        }

        const_reverse_iterator     rbegin() const {
            return ( const_reverse_iterator(end()) );
        }

        reverse_iterator     rend() {
            return ( reverse_iterator(begin()) );
        }

        const_reverse_iterator     rend() const {
            return ( const_reverse_iterator(begin()) );
        }

        /*
        ** Capacity
        */
        size_type   size() const {
            return (_size);
        }

        void        resize(size_type n, value_type val = value_type()) {
            if (n == _size)
                return ;
            
            if (n < _size) {
                // reduces to its firs n elements, destroying elements beyond
                for (size_type i = _size - 1; i > n - 1; --i) {
                    _allocator.destroy(_array + i);
                }
            } else {
                if (n > _capacity) {
                    // reallocates the storage to fit n elements
                    reserve(n);
                }
                // content expanded, inserting n-_size elements at the end (copies of val)
                for (size_type i = _size; i < n; ++i) {
                    _allocator.construct(_array + i, val);
                }
            }
            _size = n;
        }

        size_type   max_size() const {
            return (_allocator.max_size());
        }

        size_type   capacity() const {
            return (_capacity);
        }

        bool        empty() const {
            return (_size == 0);
        }

        void        reserve(size_type n) {
            if (n <= _capacity)
                return ;
            
            pointer new_array = _allocator.allocate(n);
            try {
                std::uninitialized_copy(_array, _array + _size, new_array);
            } catch (std::exception &e) {
                _allocator.deallocate(new_array, n);
                throw;
            }

            for (size_type i = 0; i < _size; i++) {
                _allocator.destroy(_array + i);
            }
            _allocator.deallocate(_array, _capacity);

            _capacity = n;
            _array = new_array;
        }   

        /*
        ** Element access
        */
        reference       operator[] (size_type n) {
			return(_array[n]);
		}

		const_reference operator[] (size_type n) const {
			return(_array[n]);
		}

        reference at (size_type n) {
            if (n >= _size)
                throw std::out_of_range("No element with such index!");
            return (_array[n]);
        }

        const_reference at (size_type n) const {
            if (n >= _size)
                throw std::out_of_range("No element with such index!");
            return (_array[n]);
        }

        reference front() {
            return (*_array);
        }

        const_reference front() const {
            return (*_array);
        }

        reference back() {
            return ( *(_array + _size - 1) );
        }

        const_reference back() const {
            return ( *(_array + _size - 1) );
        }
        
        /*
        ** Modifiers
        */
        template <class InputIterator>
        void       assign (InputIterator first, InputIterator last) {
            clear();

            size_type   new_size = static_cast<size_type>(last - first);

            if (new_size > _capacity) {
                _allocator.deallocate(_array, _capacity);
                _array = _allocator.allocate(new_size);
                _capacity = new_size;
            }

            size_type   i = 0;
            for (; first != last; ++first) {
                _allocator.construct(_array + i, *first);
                i++;
            }
            _size = new_size;
        }
        
        void    assign (size_type n, const value_type& val) {
            clear();
            _size = n;

            if (n > _capacity) {
                _allocator.deallocate(_array, _capacity);
                _array = _allocator.allocate(n);
                _capacity = n;
            }

            for (size_type i = 0; i < _size; ++i) {
                _allocator.construct(_array + i, val);
            }
        }
    
        void    clear() {
            for (size_type i = 0; i < _size; i++) {
                _allocator.destroy(_array + i);
            }
            _size = 0;
        }

        void    push_back (const value_type& val) {
            if (_size == _capacity) {
                reserve(_capacity == 0 ? 1 : _capacity * 2);
            }
            _allocator.construct(_array + _size, val);
            _size++;
        }

        void    pop_back() {
            _allocator.destroy(_array + _size - 1);
            _size--;
        }

        // Insert single element
        iterator    insert(iterator position, const value_type& val) {
            if (position < begin() || position > end())
                throw std::out_of_range("inserting position is out of range");

            size_type   border = static_cast<size_type>(position - begin());

            if (_size < _capacity) {
                size_type   i = _size;
                while (i > border) {
                    --i;
                    _allocator.construct(_array + i + 1, *(_array + i));
                    _allocator.destroy(_array + i);
                }
                _allocator.construct(_array + i, val);
            } else {  // _size == _capacity, needs to reallocate array
                size_type   new_capacity =  (_capacity == 0) ? 1 : _capacity * 2;
                pointer new_array = _allocator.allocate(new_capacity);

                try {
                    std::uninitialized_copy(begin(), position, new_array);
                    _allocator.construct(new_array + border, val);
                    std::uninitialized_copy(position, end(), new_array + border + 1);
                } catch (std::exception &e) {
                    _allocator.deallocate(new_array, new_capacity);
                    throw ;
                }

                for (size_type i = 0; i < _size; i++) {
                    _allocator.destroy(_array + i);
                }
                _allocator.deallocate(_array, _capacity);

                _array = new_array;
                _capacity = new_capacity;
            }
            _size++;

            return (begin() + border);
        }

        // Fill-type insert
        void        insert(iterator position, size_type n, const value_type& val) {
            if (position < begin() || position > end())
                throw std::out_of_range("inserting position is out of range");

            size_type   border = static_cast<size_type>(position - begin());

            if (_size + n <= _capacity) {
                size_type i = _size; // index of the last element
                while (i > border) {
                    _allocator.construct(_array + i + n - 1, *(_array + i - 1));
                    _allocator.destroy(_array + i + n - 1);
                    i--;
                }
                i = 0;
                while (i < n) {
                    _allocator.construct(_array + border + i, val);
                    i++;
                }
            } else {
                // reallocate, construct new array
                size_type   new_capacity;
                pointer     new_array;

                new_capacity = (_capacity * 2 < _capacity + n) ?
                               _capacity + n : new_capacity = _capacity * 2;

                new_array = _allocator.allocate(new_capacity);
                try {
                    std::uninitialized_copy(begin(), position, new_array);
                    for (size_type i = border; i < border + n; i++) {
                        _allocator.construct(new_array + i, val);
                    }
                    std::uninitialized_copy(position, end(), new_array + border + n);
                } catch (std::exception &e) {
                    _allocator.deallocate(new_array, new_capacity);
                    throw ;
                }
                
                for (size_type i = 0; i < _size; i++) {
                    _allocator.destroy(_array + i);
                }
                _allocator.deallocate(_array, _capacity);

                _array = new_array;
                _capacity = new_capacity;
            }
            _size += n;
        }

        // template <class InputIterator>
        // void        insert(
        //     iterator position,
        //     InputIterator first,
        //     InputIterator last,
        //     typename ft::enable_if<!is_integral<InputIterator>::value>::type* = 0)
        // {
        //     if (position < begin() || position > end())
        //         throw std::out_of_range("inserting position is out of range");
                
        //     size_type   border = static_cast<size_type>(position - begin());
        //     size_type   n = static_cast<size_type>(last - first);

        //     if (_size + n <= _capacity) {
        //         size_type i = _size; // index of the last element
        //         while (i > border) {
        //             _allocator.construct(_array + i + n - 1, *(_array + i - 1));
        //             _allocator.destroy(_array + i - 1);
        //             i--;
        //         }
        //         i = 0;
        //         while (i < n) {
        //             _allocator.construct(_array + border + i, val);
        //             i++;

        //     }
        // }

        
};

}  // namespace brace

#endif