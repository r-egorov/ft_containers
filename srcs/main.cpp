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


template <class C>
void    print_vector(const C &vec, typename C::iterator& in_it) {
    size_t i = 0;
    std::cout << "+-------------------PRINTING VECTOR-------------------+" << std::endl;
    std::cout << "ft::vector, s = " << vec.size() << ", c = " << vec.capacity() << std::endl;
    for (typename C::const_iterator it = vec.begin(); it != vec.end(); it++) {
        if (&(*in_it) == &(*it)) {
            std::cout << "|" << i++ << "\t| " << *it << " <------ INPUT ITERATOR \n";
        } else {
            std::cout << "|" << i++ << "\t| " << *it << "\n";
        }
    }
    if (&(*in_it) == &(*vec.end())) {
        std::cout << "end() <------ INPUT ITERATOR"  << std::endl;
    }
    std::cout << "+-----------------------------------------------------+"  << std::endl;
}




class B {
public:
	char *l;
	int i;
	B():l(nullptr), i(1) {};
	B(const int &ex) {
		this->i = ex;
		this->l = new char('a');
	};
	virtual ~B() {
		delete this->l;
		this->l = nullptr;
	};
};

class A : public B {
public:
	A():B(){};
	A(const B* ex){
		this->l = new char(*(ex->l));
		this->i = ex->i;
		if (ex->i == -1) throw "n";
	}
	~A() {
		delete this->l;
		this->l = nullptr;
	};
};

template <class C>
void    print_vector(const C &vec) {
    size_t i = 0;
    std::cout << "+-------------------PRINTING VECTOR-------------------+" << std::endl;
    std::cout << "ft::vector, s = " << vec.size() << ", c = " << vec.capacity() << std::endl;
    for (typename C::const_iterator it = vec.begin(); it != vec.end(); it++) {
        std::cout << "|" << i++ << "\t| " << *it << "\n";
    }
    std::cout << "+-----------------------------------------------------+"  << std::endl;
}


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
    // std::map<int, int>      std_map;
    // ft::map<int, int>       ft_map;

	// std_map.insert(std::make_pair(16, 3));
	// std_map.insert(std::make_pair(8, 3));
	// std_map.insert(std::make_pair(23, 3));
	// std_map.insert(std::make_pair(7, 3));
	// std_map.insert(std::make_pair(19, 3));
	// std_map.insert(std::make_pair(29, 3));
	// std_map.insert(std::make_pair(41, 3));
	// std_map.insert(std::make_pair(4, 3));
	// std_map.insert(std::make_pair(11, 3));
    
	// ft_map.insert(ft::make_pair(16, 3));
	// ft_map.insert(ft::make_pair(8, 3));
	// ft_map.insert(ft::make_pair(23, 3));
	// ft_map.insert(ft::make_pair(7, 3));
	// ft_map.insert(ft::make_pair(19, 3));
	// ft_map.insert(ft::make_pair(29, 3));
	// ft_map.insert(ft::make_pair(41, 3));
	// ft_map.insert(ft::make_pair(4, 3));
	// ft_map.insert(ft::make_pair(11, 3));

    // print_map(std_map);
    // print_map(ft_map);

    // std::map<int, int>::reverse_iterator std_rit = std_map.rbegin();
    // std::map<int, int>::reverse_iterator std_rit2 = std_map.rend();

    // ft::map<int, int>::reverse_iterator ft_rit = ft_map.rbegin();
    // ft::map<int, int>::reverse_iterator ft_rit2 = ft_map.rend();

    // std_rit++;
    // std_rit2--;
    // ft_rit++;
    // ft_rit2--;

    // std::cout << "std it = k:" << std_rit->first << " v:" << std_rit->second << std::endl;
    // std::cout << "ft it = k:" << ft_rit->first << " v:" << ft_rit->second << std::endl;

    // std_rit++;
    // ft_rit++;

    // std::cout << "Std:\t"<< (*std_rit == *std_rit2) << std::endl;
    // std::cout << "FT:\t" << (*ft_rit == *ft_rit2) << std::endl;

    // std_rit2--;
    // ft_rit2--;

    // std::cout << "std:\t" << std_rit->first << ", " << std_rit2->first << std::endl;
    // std::cout << "ft:\t" << ft_rit->first << ", " << ft_rit2->first << std::endl;

    // std::cout << "Std:\t"<< (*std_rit < *std_rit2) << std::endl;
    // std::cout << "FT:\t" << (*ft_rit < *ft_rit2) << std::endl;

    // std::cout << "Std:\t"<< (*std_rit > *std_rit2) << std::endl;
    // std::cout << "FT:\t" << (*ft_rit > *ft_rit2) << std::endl;


    // std::cout << "Std:\t"<< (*std_rit2 < *std_rit) << std::endl;
    // std::cout << "FT:\t" << (*ft_rit2 < *ft_rit) << std::endl;


    // std::cout << "Std:\t"<< (*std_rit2 > *std_rit) << std::endl;
    // std::cout << "FT:\t" << (*ft_rit2 > *ft_rit) << std::endl;


    // --std_rit;
    // --ft_rit;
    
    // std::cout << "std it = k:" << std_rit->first << " v:" << std_rit->second << std::endl;
    // std::cout << "ft it = k:" << ft_rit->first << " v:" << ft_rit->second << std::endl;

    ft::vector<int> ft_v;
    ft_v.reserve(1000);
}