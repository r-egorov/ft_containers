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


template <typename T>
void    print_vector(const ft::vector<T> &vec, typename ft::vector<T>::iterator& in_it) {
    size_t i = 0;
    std::cout << "+-------------------PRINTING VECTOR-------------------+" << std::endl;
    std::cout << "ft::vector, s = " << vec.size() << ", c = " << vec.capacity() << std::endl;
    for (typename ft::vector<T>::const_iterator it = vec.begin(); it != vec.end(); it++) {
        if (&(*in_it) == &(*it)) {
            std::cout << "|" << i++ << "\t| " << *it << " <------ INPUT ITERATOR \n";
        } else {
            std::cout << "|" << i++ << "\t| " << *it << "\n";
        }
    }
    std::cout << "+-----------------------------------------------------+"  << std::endl;
}

template <typename T>
void    print_vector(const ft::vector<T> &vec) {
    size_t i = 0;
    std::cout << "+-------------------PRINTING VECTOR-------------------+" << std::endl;
    std::cout << "ft::vector, s = " << vec.size() << ", c = " << vec.capacity() << std::endl;
    for (typename ft::vector<T>::const_iterator it = vec.begin(); it != vec.end(); it++) {
        std::cout << "|" << i++ << "\t| " << *it << "\n";
    }
    std::cout << "+-----------------------------------------------------+"  << std::endl;
}

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

    ft::vector<MyClass> vector_myclass1(10);

    MyClass& mc = vector_myclass1.front();
    mc.setN(15);
    mc.setS("front");

    MyClass& mc1 = vector_myclass1.back();
    mc1.setN(51);
    mc1.setS("back");

    ft::vector<MyClass> vector_myclass(vector_myclass1);

    std::cout << vector_myclass1.at(5) << std::endl;

    ft::vector<MyClass> vector_myclass_2(5);
    for (ft::vector<MyClass>::const_iterator it = vector_myclass_2.begin(); it != vector_myclass_2.end(); it++) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
    

    std::cout << "SSSSSSSSSSSSSSS" << std::endl;

    ft::vector<MyClass> newnewnew;
    for (int i = 0; i < 15; i++) {
        newnewnew.push_back(MyClass(i, strs[i % 10]));
    }
    vector_myclass_2.assign(newnewnew.begin(), newnewnew.end());
    for (ft::vector<MyClass>::const_iterator it = vector_myclass_2.begin(); it != vector_myclass_2.end(); it++) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;

    std::cout << "SSSSSSSSSSSSSSS" << std::endl;
    print_vector(vector_myclass_2);

    MyClass     new_val(7777, "new Class value!");
    // ft::vector<MyClass>::iterator ps = vector_myclass_2.insert(vector_myclass_2.begin() + 4, new_val);
    // print_vector(vector_myclass_2, ps);

    // print_vector(vector_myclass_2);
    vector_myclass = ft::vector<MyClass>();
    vector_myclass.push_back(MyClass(189, "Kvartira"));
    vector_myclass.push_back(MyClass(40, "Dom"));
    vector_myclass.push_back(MyClass(2, "Korpus"));
    print_vector(vector_myclass);
    print_vector(vector_myclass_2);
    vector_myclass.insert(vector_myclass.end(), vector_myclass_2.begin(), vector_myclass_2.begin() + 2);
    print_vector(vector_myclass);
    // ft::vector<MyClass>::iterator p = vector_myclass_2.insert(vector_myclass_2.end(), new_val);
    // print_vector(vector_myclass_2, p);

    
    // std::cout << "aaaaa" << std::endl;
    
    // print_vector(vector_myclass_2); 
    // vector_myclass_2.insert(vector_myclass_2.begin() + 5, 20, MyClass(999, "SOMETHING NEW"));
    // print_vector(vector_myclass_2); 
}
