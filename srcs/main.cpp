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

#include <map>
#include <vector>
#include <unistd.h>
template<typename Map>
void print_map(Map& m)
{
   std::cout << '{';
   for(typename Map::iterator it = m.begin(); it != m.end(); it++)
        std::cout << (*it).first << ':' << (*it).second << ", ";
   std::cout << "}\n";
}
// // a case-insensitive comparison function:
// bool mycomp (char c1, char c2)
// { return std::tolower(c1)<std::tolower(c2); }


// template <class C>
// void    print_vector(const C &vec, typename C::iterator& in_it) {
//     size_t i = 0;
//     std::cout << "+-------------------PRINTING VECTOR-------------------+" << std::endl;
//     std::cout << "ft::vector, s = " << vec.size() << ", c = " << vec.capacity() << std::endl;
//     for (typename C::const_iterator it = vec.begin(); it != vec.end(); it++) {
//         if (&(*in_it) == &(*it)) {
//             std::cout << "|" << i++ << "\t| " << *it << " <------ INPUT ITERATOR \n";
//         } else {
//             std::cout << "|" << i++ << "\t| " << *it << "\n";
//         }
//     }
//     if (&(*in_it) == &(*vec.end())) {
//         std::cout << "end() <------ INPUT ITERATOR"  << std::endl;
//     }
//     std::cout << "+-----------------------------------------------------+"  << std::endl;
// }

// template <class C>
// void    print_vector(const C &vec) {
//     size_t i = 0;
//     std::cout << "+-------------------PRINTING VECTOR-------------------+" << std::endl;
//     std::cout << "ft::vector, s = " << vec.size() << ", c = " << vec.capacity() << std::endl;
//     for (typename C::const_iterator it = vec.begin(); it != vec.end(); it++) {
//         std::cout << "|" << i++ << "\t| " << *it << "\n";
//     }
//     std::cout << "+-----------------------------------------------------+"  << std::endl;
// }

// int main(void)
// {
//     Timer   timer;

//     std::cout
//         << "=======================\nTESTING STACK\n======================="
//         << std::endl;
    
//     typedef ft::stack<MyClass> myclass_stack;
//     myclass_stack   st;

//     timer.start();
    
//     std::cout << "st.empty() = " << st.empty() << std::endl;
//     std::string     strs[10] = {
//         "I",
//         "hope",
//         "my",
//         "stack",
//         "is",
//         "working",
//         "as",
//         "it",
//         "should",
//         ".",
//     };

//     for (int i = 0; i < 10; i++)
//     {
//         MyClass     obj(i, strs[i]);
//         st.push(MyClass(obj));
//         std::cout << "pushing my_class = " << obj << std::endl;
//     }
//     std::cout << "st.size() = " << st.size() << std::endl;
//     std::cout << "st.empty() = " << st.empty() << std::endl;

//     for (int i = 0; i < 5; i++)
//     {
//         std::cout << "popping last = " << st.top() << std::endl;
//         st.pop();
//     }
//     std::cout << "st.size() = " << st.size() << std::endl;
//     std::cout << "st.empty() = " << st.empty() << std::endl;

//     for (int i = 0; i < 5; i++)
//     {
//         std::cout << "popping last = " << st.top() << std::endl;
//         st.pop();
//     }
//     std::cout << "st.size() = " << st.size() << std::endl;
//     std::cout << "st.empty() = " << st.empty() << std::endl;
    
//     timer.stop();

//     typedef ft::stack<int>  int_stack;
//     int_stack               int_st_1;
//     int_stack               int_st_2;

//     for(int i = 1; i < 100; i *= 10)
//     {
//         int_st_1.push(i);
//         int_st_2.push(i);
//     }
//     if (int_st_1 == int_st_2)
//     {
//         std::cout << "IDENTICAL: int_st_1 == int_st_2" << std::endl;
//     } else {
//         std::cout << "DIFF: int_st_1 == int_st_2" << std::endl;
//     }

//     int_st_2.pop();
//     std::cout << "int_st_2.pop()" << std::endl;
    
//     if (int_st_1 == int_st_2)
//     {
//         std::cout << "IDENTICAL: int_st_1 == int_st_2" << std::endl;
//     } else {
//         std::cout << "DIFF: int_st_1 == int_st_2" << std::endl;
//     }

//     std::cout
//         << "========================\n"
//         << std::endl;


//     std::cout
//         << "=======================\nTESTING VECTOR\n======================="
//         << std::endl;

//     timer.start();

//     ft::vector<int>     my_vector_default;
    
//     // Should be working with enable_if
//     // ft::vector<int>*     my_vector_second = new ft::vector<int>(4, 100);
    

//     ft::vector<int>*     my_vector_second = new ft::vector<int>(4, 100);
    
//     for (ft::vector<int>::iterator it = my_vector_second->begin(); it != my_vector_second->end(); it++) {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;

//     // Test constructor with iterators
//     int a[4] = {1, 2, 3, 5};
//     std::vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
//     ft::vector<int> my (v.begin(), v.end());

//     for (ft::vector<int>::iterator it = my.begin(); it != my.end(); it++) {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;

//     // Test copy constructor
//     ft::vector<int> my_copy(my);
//     for (ft::vector<int>::iterator it = my_copy.begin(); it != my_copy.end(); it++) {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;

//     ft::vector<int> new_copy = my_copy;
//     for (ft::vector<int>::iterator it = new_copy.begin(); it != new_copy.end(); it++) {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;

//     ft::vector<int> *n_copy = new ft::vector<int>(new_copy);

//     for (ft::vector<int>::iterator it = n_copy->begin(); it != n_copy->end(); it++) {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;

//     ft::vector<MyClass> vector_myclass1(10);

//     MyClass& mc = vector_myclass1.front();
//     mc.setN(15);
//     mc.setS("front");

//     MyClass& mc1 = vector_myclass1.back();
//     mc1.setN(51);
//     mc1.setS("back");

//     ft::vector<MyClass> vector_myclass(vector_myclass1);

//     std::cout << vector_myclass1.at(5) << std::endl;

//     ft::vector<MyClass> vector_myclass_2(5);
//     for (ft::vector<MyClass>::const_iterator it = vector_myclass_2.begin(); it != vector_myclass_2.end(); it++) {
//         std::cout << *it << ", ";
//     }
//     std::cout << std::endl;
    

//     std::cout << "SSSSSSSSSSSSSSS" << std::endl;

//     ft::vector<MyClass> newnewnew;
//     for (int i = 0; i < 15; i++) {
//         newnewnew.push_back(MyClass(i, strs[i % 10]));
//     }
//     vector_myclass_2.assign(newnewnew.begin(), newnewnew.end());
//     for (ft::vector<MyClass>::const_iterator it = vector_myclass_2.begin(); it != vector_myclass_2.end(); it++) {
//         std::cout << *it << ", ";
//     }
//     std::cout << std::endl;

//     std::cout << "SSSSSSSSSSSSSSS" << std::endl;
//     print_vector(vector_myclass_2);

//     MyClass     new_val(7777, "new Class value!");
//     // ft::vector<MyClass>::iterator ps = vector_myclass_2.insert(vector_myclass_2.begin() + 4, new_val);
//     // print_vector(vector_myclass_2, ps);

//     // print_vector(vector_myclass_2);
//     vector_myclass = ft::vector<MyClass>();
//     vector_myclass.push_back(MyClass(189, "Kvartira"));
//     vector_myclass.push_back(MyClass(40, "Dom"));
//     vector_myclass.push_back(MyClass(2, "Korpus"));
//     print_vector(vector_myclass);
//     print_vector(vector_myclass_2);
//     vector_myclass.insert(vector_myclass.end(), vector_myclass_2.begin(), vector_myclass_2.begin() + 2);
//     print_vector(vector_myclass_2);

//     // ft::vector<MyClass>::iterator erit = vector_myclass_2.erase(vector_myclass_2.begin() + 4, vector_myclass_2.begin() + 10);
    
//     ft::vector<MyClass>::iterator erit = vector_myclass_2.erase(vector_myclass_2.end() - 1);
//     print_vector(vector_myclass_2, erit);

//     ft::vector<MyClass>::const_iterator const_erit = vector_myclass_2.begin();
//     const_erit = erit;
// }


#include "RBTree.hpp"
#include <iostream>
#include "map.hpp"

//typedef ft::RBTree::Node Node;


namespace ft{
    template<class T1, class T2>
    std::ostream	&operator << (std::ostream &o, ft::pair<T1, T2> const &obj) {
        o << "ft::pair(first = " << obj.first << ", second = " << obj.second << ")" ;
        return (o);
    }
}

int main(void) {
    ft::pair<const int, int> pairs[6] = {
        ft::pair<const int, int>(41, 41),
        ft::pair<const int, int>(38, 38),
        ft::pair<const int, int>(31, 31),
        ft::pair<const int, int>(12, 12),
        ft::pair<const int, int>(19, 19),
        ft::pair<const int, int>(8,8),
    };
    ft::map<int, int> ftmap(pairs, pairs + 6);
    for (ft::map<int, int>::iterator it = ftmap.begin(); it != ftmap.end(); it++) {
        std::cout << *it << std::endl;
    }

    ft::map<int, int>::iterator pos;
    pos = ftmap.insert(ft::pair<const int, int>(8,25)).first;
    std::cout << *pos << std::endl;

    pos = ftmap.insert(ft::pair<const int, int>(25,25)).first;
    std::cout << *pos << std::endl;

    ft::map<int, int>::iterator inserted = ftmap.insert(pos, ft::pair<const int, int>(8,25));
    std::cout << *inserted << std::endl;

    ft::pair<const int, int> another[3] = {
        ft::pair<const int, int>(1, 1),
        ft::pair<const int, int>(38, 256),
        ft::pair<const int, int>(45, 45)
    };
    ft::map<int, int> ftmap2(another, another + 3);
    ftmap.insert(another, another + 3);
    print_map(ftmap);
    ft::map<int, int>::iterator position = ftmap.begin();
    position++;
    position++;
    position++;
    position++;
    
    //ftmap.erase(ftmap.begin(), ftmap.end());
    print_map(ftmap);
    ftmap.print_tree();

    ftmap.insert(ft::pair<const int, int>(361,361));
    ftmap.insert(ft::pair<const int, int>(-25,-25));
    ftmap.print_tree();

    ftmap.erase(361);
    ftmap.print_tree();
    ftmap.erase(-25);
    ftmap.print_tree();

    // for (ft::map<int, int>::iterator it = ftmap.begin(); it != ftmap.end(); it++) {
    //     std::cout << (*it) << std::endl;
    // }
    ft::map<int, int>::iterator itt = ftmap.begin();
    itt++;
    itt++;
    itt++;
    itt++;

    print_map(ftmap);
    std::cout << ftmap.size() << std::endl;
    print_map(ftmap2);
    std::cout << ftmap2.size() << std::endl;
    ftmap.swap(ftmap2);
    print_map(ftmap);
    std::cout << ftmap.size() << std::endl;
    print_map(ftmap2);
    std::cout << ftmap2.size() << std::endl;

    ftmap.clear();
    print_map(ftmap);
    std::cout << ftmap.size() << std::endl;

    ft::map<int, int>::key_compare kc = ftmap.key_comp();
    ft::map<int, int>::value_compare vc = ftmap.value_comp();

    std::cout << kc(1, 2) << std::endl;
    std::cout << vc(ft::pair<const int, int>(361,361), ft::pair<const int, int>(1000,361)) << std::endl;
}