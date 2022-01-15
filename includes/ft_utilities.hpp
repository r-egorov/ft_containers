#ifndef FT_UTILITIES_HPP
# define FT_UTILITIES_HPP

namespace ft {

/*
** enable_if implementation
*/ 
template<bool Cond, class T = void>
struct enable_if {};

template<class T>
struct enable_if<true, T> { typedef T type; };

/*
** is_integral implementation
*/ 
template <class T, T v>
struct integral_constant {
    static constexpr T          value = v;
    typedef                     value_type;
    typedef                     integral_constant<T,v> type;

    constexpr   operator T() { return v; }
};

typedef ft::integral_constant<bool, true>   true_type;
typedef ft::integral_constant<bool, false>  false_type;

template<typename> struct is_integral : ft::false_type {};
template<> struct is_integral<bool> : ft::true_type {};
template<> struct is_integral<short> : ft::true_type {};
template<> struct is_integral<char> : ft::true_type {};
template<> struct is_integral<int> : ft::true_type {};
template<> struct is_integral<long> : ft::true_type {};
template<> struct is_integral<long long> : ft::true_type {};
template<> struct is_integral<unsigned short> : ft::true_type {};
template<> struct is_integral<unsigned char> : ft::true_type {};
template<> struct is_integral<unsigned int> : ft::true_type {};
template<> struct is_integral<unsigned long> : ft::true_type {};
template<> struct is_integral<unsigned long long> : ft::true_type {};
template<> struct is_integral<char16_t> : ft::true_type {};
template<> struct is_integral<char32_t> : ft::true_type {};
template<> struct is_integral<wchar_t> : ft::true_type {};
template<> struct is_integral<const bool> : ft::true_type {};
template<> struct is_integral<const short> : ft::true_type {};
template<> struct is_integral<const char> : ft::true_type {};
template<> struct is_integral<const int> : ft::true_type {};
template<> struct is_integral<const long> : ft::true_type {};
template<> struct is_integral<const long long> : ft::true_type {};
template<> struct is_integral<const unsigned short> : ft::true_type {};
template<> struct is_integral<const unsigned char> : ft::true_type {};
template<> struct is_integral<const unsigned int> : ft::true_type {};
template<> struct is_integral<const unsigned long> : ft::true_type {};
template<> struct is_integral<const unsigned long long> : ft::true_type {};
template<> struct is_integral<const char16_t> : ft::true_type {};
template<> struct is_integral<const char32_t> : ft::true_type {};
template<> struct is_integral<const wchar_t> : ft::true_type {};


/*
** equal implementation
*/
template <class InputIterator1, class InputIterator2>
bool equal(InputIterator1 first1, InputIterator1 last1,
           InputIterator2 first2) {
    while (first1 != last1) {
        if (!(*first1 == *first2))
            return (false);
        ++first1; ++first2;
    }
  return true;
}

template <class InputIterator1, class InputIterator2, class BinaryPredicate>
bool equal (InputIterator1 first1, InputIterator1 last1,
            InputIterator2 first2, BinaryPredicate pred); {
    while (first1 != last1) {
        if (!pred(*first1,*first2))
            return (false);
        ++first1; ++first2;
    }
  return true;
}

} // namespace brace

#endif