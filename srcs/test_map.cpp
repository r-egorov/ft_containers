#include "tests.hpp"

void    test_default_constructor_empty(
    test_result* test_res,
    std::vector<int>& std_res,
    std::vector<int>& ft_res
) {
    print_header("Testing default empty constructor", BLUE);
    Timer       timer;

    timer.start();
    std::map<int,int>   std_m;
    std_res.push_back(std_m.size());
    std_res.push_back(std_m.empty());
    timer.stop();
    test_res->std_time = timer.get_stop();

    
    timer.start();
    ft::map<int,int>   ft_m;
    ft_res.push_back(ft_m.size());
    ft_res.push_back(ft_m.empty());
    timer.stop();
    test_res->ft_time = timer.get_stop();

    test_res->passed = true;
}

void    test_range_constructor(
    test_result* test_res,
    std::vector<int>& std_res,
    std::vector<int>& ft_res
) {
    print_header("Testing range constructor", BLUE);
    Timer       timer;
    std::vector<std::pair<int, int> > std_pairs;
    std::vector<ft::pair<int, int> > ft_pairs;

    for (int i = 0; i < 300; i++) {
        std_pairs.push_back(std::make_pair(i, i * 100));
        ft_pairs.push_back(ft::make_pair(i, i * 100));
    }

    timer.start();
    std::map<int,int>   std_m(std_pairs.begin(), std_pairs.end());
    std_res.push_back(std_m.size());
    std_res.push_back(std_m.empty());
    std_res.push_back(std_m[100]);
    timer.stop();
    test_res->std_time = timer.get_stop();

    
    timer.start();
    ft::map<int,int>   ft_m(ft_pairs.begin(), ft_pairs.end());
    ft_res.push_back(ft_m.size());
    ft_res.push_back(ft_m.empty());
    ft_res.push_back(ft_m[100]);
    timer.stop();
    test_res->ft_time = timer.get_stop();

    test_res->passed = true;
}


void    test_assignation_operator(
    test_result* test_res,
    std::vector<int>& std_res,
    std::vector<int>& ft_res
) {
    print_header("Testing operator=", BLUE);
    Timer       timer;
    std::map<int, int>      std_reference;
    ft::map<int, int>       ft_reference;

    for (int i = 0; i < 300; i++) {
        ft_reference[i] = i * 100;
        std_reference[i] = i * 100;
    }

    timer.start();
    std::map<int,int>   std_m = std_reference;
    std_res.push_back(std_m.size());
    std_res.push_back(std_m.empty());
    std_res.push_back(std_m[100]);
    timer.stop();
    test_res->std_time = timer.get_stop();

    
    timer.start();
    ft::map<int,int>   ft_m = ft_reference;
    ft_res.push_back(ft_m.size());
    ft_res.push_back(ft_m.empty());
    ft_res.push_back(ft_m[100]);
    timer.stop();
    test_res->ft_time = timer.get_stop();

    test_res->passed = true;
}

void    test_swap(
    test_result* test_res,
    std::vector<int>& std_res,
    std::vector<int>& ft_res
) {
    print_header("Testing swap", BLUE);
    Timer       timer;
    std::map<int, int>      std_reference;
    ft::map<int, int>       ft_reference;

    for (int i = 0; i < 300; i++) {
        ft_reference[i] = i * 100;
        std_reference[i] = i * 100;
    }

    std::map<int,int>   std_m;
    ft::map<int,int>   ft_m;
    for (int i = 4000; i > 0; i--) {
        ft_m[i] = i * 100;
        std_m[i] = i * 100;
    }

    timer.start();
    std_res.push_back(std_m.size());
    std_m.swap(std_reference);
    std_res.push_back(std_m.size());
    std_res.push_back(std_reference.size());
    timer.stop();
    test_res->std_time = timer.get_stop();

    
    timer.start();
    ft_res.push_back(ft_m.size());
    ft_m.swap(ft_reference);
    ft_res.push_back(ft_m.size());
    ft_res.push_back(ft_reference.size());
    timer.stop();
    test_res->ft_time = timer.get_stop();

    test_res->passed = true;
}


#define NUM_MAP_TESTS 4 
bool    test_map() {
    typedef void    (*unittest)(test_result*, std::vector<int>&, std::vector<int>&);
    bool res = PASSED;

    print_header("Testing map", YELLOW);

    unittest    tests[NUM_MAP_TESTS] = {
        &test_default_constructor_empty,
        &test_range_constructor,
        &test_assignation_operator,
        &test_swap
    };

    for (size_t i = 0; i < NUM_MAP_TESTS; i++) {
        Timer   timer;
        bool res = PASSED;
        std::vector<int>     std_res;
        std::vector<int>     ft_res;
        test_result test_res;
        tests[i](&test_res, std_res, ft_res);
        if ((!test_res.passed) || (std_res != ft_res)) {
            res = FAILED;
        }
        print_test_result(res, test_res);
    }
    return (res);
}