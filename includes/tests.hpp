#ifndef TESTS_HPP
# define TESTS_HPP

# define PASSED true
# define FAILED false

# define RESET "\e[0m"
# define GREEN "\e[92m"
# define YELLOW "\e[93m"
# define BLUE "\e[94m"
# define BOLD "\e[1m"
# define RED "\e[31m"

# include <map>
# include <vector>
# include <stack>
# include <string>
# include <iostream>
# include <iomanip>
# include <sstream>

# include "Timer.hpp"
# include "vector.hpp"

struct  test_result {
    long int    std_time;
    long int    ft_time;
    bool        passed;
};
typedef void (*unittest)(test_result*);
typedef bool (*test)();

bool    test_vector();
void    print_header(const std::string& str, const char* color);
void    print_test_result(const bool& res, const test_result& test_res);



#endif