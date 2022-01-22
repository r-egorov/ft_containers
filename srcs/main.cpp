#include <iostream>
#include <stack>
#include <memory>
#include "vector.hpp"
#include "stack.hpp"
#include "MyClass.hpp"
#include "Timer.hpp"
#include "iterator_traits.hpp"
#include "ft_utilities.hpp"
#include "pair.hpp"

#include "reverse_iterator.hpp"

#include <vector>
#include <unistd.h>

// a case-insensitive comparison function:
bool mycomp (char c1, char c2)
{ return std::tolower(c1)<std::tolower(c2); }

int main(void)
{
    Timer   timer;

    std::cout
        << "=======================\nTESTING STACK\n======================="
        << std::endl;
    
    typedef ft::stack<MyClass> myclass_stack;
    myclass_stack   st;

    timer.start();
    
    std::cout << "st.empty() = " << st.empty() << std::endl;

    std::string     strs[10] = {
        "I",
        "hope",
        "my",
        "stack",
        "is",
        "working",
        "as",
        "it",
        "should",
        ".",
    };

    for (int i = 0; i < 10; i++)
    {
        MyClass     obj(i, strs[i]);
        st.push(MyClass(obj));
        std::cout << "pushing my_class = " << obj << std::endl;
    }
    std::cout << "st.size() = " << st.size() << std::endl;
    std::cout << "st.empty() = " << st.empty() << std::endl;

    for (int i = 0; i < 5; i++)
    {
        std::cout << "popping last = " << st.top() << std::endl;
        st.pop();
    }
    std::cout << "st.size() = " << st.size() << std::endl;
    std::cout << "st.empty() = " << st.empty() << std::endl;

    for (int i = 0; i < 5; i++)
    {
        std::cout << "popping last = " << st.top() << std::endl;
        st.pop();
    }
    std::cout << "st.size() = " << st.size() << std::endl;
    std::cout << "st.empty() = " << st.empty() << std::endl;
    
    timer.stop();

    typedef ft::stack<int>  int_stack;
    int_stack               int_st_1;
    int_stack               int_st_2;

    for(int i = 1; i < 100; i *= 10)
    {
        int_st_1.push(i);
        int_st_2.push(i);
    }
    if (int_st_1 == int_st_2)
    {
        std::cout << "IDENTICAL: int_st_1 == int_st_2" << std::endl;
    } else {
        std::cout << "DIFF: int_st_1 == int_st_2" << std::endl;
    }

    int_st_2.pop();
    std::cout << "int_st_2.pop()" << std::endl;
    
    if (int_st_1 == int_st_2)
    {
        std::cout << "IDENTICAL: int_st_1 == int_st_2" << std::endl;
    } else {
        std::cout << "DIFF: int_st_1 == int_st_2" << std::endl;
    }

    std::cout
        << "========================\n"
        << std::endl;

    std::cout
        << "=======================\nTESTING VECTOR\n======================="
        << std::endl;

    timer.start();

    ft::vector<int>     my_vector_default;
    
    // Should be working with enable_if
    // ft::vector<int>*     my_vector_second = new ft::vector<int>(4, 100);
    

    ft::vector<int>*     my_vector_second = new ft::vector<int>(4, 100);
    
    for (int i = 0; i < 4; i++) {
        std::cout << *(my_vector_second->_array + i) << " ";
    }
    std::cout << std::endl;

    // Test constructor with iterators
    int a[4] = {1, 2, 3, 5};
    std::vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
    ft::vector<int> my (v.begin(), v.end());

    for (int i = 0; i < 4; i++) {
        std::cout << *(my._array + i) << " ";
    }
    std::cout << std::endl;

    // Test copy constructor
    ft::vector<int> my_copy(my);
    for (int i = 0; i < 4; i++) {
        std::cout << *(my_copy._array + i) << " ";
    }
    std::cout << std::endl;

    ft::vector<int> new_copy = my_copy;
    for (int i = 0; i < 4; i++) {
        std::cout << *(new_copy._array + i) << " ";
    }
    std::cout << std::endl;

    ft::vector<int> *n_copy = new ft::vector<int>(new_copy);

    for (int i = 0; i < 4; i++) {
        std::cout << *(n_copy->_array + i) << " ";
    }
    std::cout << std::endl;

    std::cout << "s = " << n_copy->size() << " c = " << n_copy->capacity() << std::endl;
    n_copy->resize(10, 100);
    for (ft::vector<int>::iterator it = n_copy->begin(); it != n_copy->end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    n_copy->reserve(100);
    std::cout << "s = " << n_copy->size() << " c = " << n_copy->capacity() << std::endl;

    delete n_copy;
    sleep(10);
}