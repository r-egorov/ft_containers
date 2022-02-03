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
#include "map.hpp"

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

//typedef ft::RBTree::Node Node;


namespace ft{
    template<class T1, class T2>
    std::ostream	&operator << (std::ostream &o, ft::pair<T1, T2> const &obj) {
        o << "ft::pair(first = " << obj.first << ", second = " << obj.second << ")" ;
        return (o);
    }
}

int main(void) {
    ft::RBTreeNode<int>     node;

    int six = 6;
    ft::RBTreeNode<int>     node6(&six);

    std::string str = "string";
    ft::RBTreeNode<std::string> node_str(&str);

    ft::pair<std::string, int>  p("six", 6);
    ft::RBTreeNode<ft::pair<std::string, int> > node_pair(&p);

    ft::RBTreeNode<int> node_def;
    node_def.is_nil = true;
    node_def.color = BLACK;

    std::cout << node6 << std::endl;
    std::cout << node_str << std::endl;
    std::cout << node_pair << std::endl;
    std::cout << node_def << std::endl;

    ft::RBTree<int> tree;

    tree.print();
    tree.insert(41);
    tree.insert(38);
    tree.insert(31);
    tree.insert(12);
    tree.insert(19);
    tree.insert(8);
    tree.print();
    
    
    ft::RBTree<int> copy(tree);
    copy.print();

    for (ft::RBTree<int>::iterator it = tree.begin(); it != tree.end(); it++) {
        std::cout << (*it) << ", ";
    }
    std::cout << std::endl;

    for (ft::RBTree<int>::iterator it = copy.begin(); it != copy.end(); it++) {
        std::cout << (*it) << ", ";
    }
    std::cout << std::endl;
    // std::cout << "\n\nremoving 8" << std::endl;
    // tree.remove(8);
    // tree.print();
    // std::cout << "\n\nremoving 12" << std::endl;
    // tree.remove(12);
    // tree.print();
    // std::cout << "\n\nremoving 19" << std::endl;
    // tree.remove(19);
    // tree.print();
    // std::cout << "\n\nremoving 31" << std::endl;
    // tree.remove(31);
    // tree.print();
    // std::cout << "\n\nremoving 38" << std::endl;
    // tree.remove(38);
    // tree.print();
    // std::cout << "\n\nremoving 41" << std::endl;
    // tree.remove(41);

    std::map<std::string, int> map1;
    map1["something"] = 69;
    map1["anything"] = 199;
    map1["that thing"] = 50;
    std::cout << "map1 = "; print_map(map1);
    std::map<std::string, int> iter(map1.find("anything"), map1.end());
    std::cout << "\niter = "; print_map(iter);
    std::cout << "map1 = "; print_map(map1);

    // ft::RBTree< ft::pair<std::string, int> > pair_tree;
    // std::string strings[10] = {
    //     "zero",
    //     "one",
    //     "two",
    //     "three",
    //     "four",
    //     "five",
    //     "six",
    //     "seven",
    //     "eight",
    //     "nine",
    // };
    // for (int i = 0; i < 10; i++) {
    //     pair_tree.insert(ft::pair<std::string, int>(strings[i], i));
    // }
    // pair_tree.print();
    // ft::RBTree< ft::pair<std::string, int> >::iterator it = pair_tree.search(ft::pair<std::string, int>("five", 5));
    // std::cout << *it << "addr, " << &(*it) << std::endl;

    // ft::pair<std::string, int> pairs[3] = {
    //     ft::pair<std::string, int>("something", 69),
    //     ft::pair<std::string, int>("anything", 199),
    //     ft::pair<std::string, int>("that thing", 50),
    // };
    // ft::map<std::string, int> iter1(pairs, pairs + 3);
    // // for (ft::map<std::string, int>::iterator it = iter1.begin(); it != iter1.end(); it++) {
    // //     std::cout << *(it) << std::endl;
    // // }
    
    // // for (ft::map<std::string, int>::reverse_iterator it = iter1.rbegin(); it != iter1.rend(); it++) {
    // //     std::cout << *(it) << std::endl;
    // // }


    // ft::map<std::string, int>::iterator it = iter1.begin();
    // const ft::map<std::string, int> iter2(pairs, pairs + 3);
    // ft::map<std::string, int>::const_iterator it2 = it;

}