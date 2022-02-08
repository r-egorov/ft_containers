#include "tests.hpp"

void    test_default_constructor_empty(
    test_result* test_res,
    std::vector<int>& std_res,
    std::vector<int>& ft_res
) {
    print_header("Testing default empty constructor", BLUE);
    Timer       timer;

    timer.start();
    std::set<int>   std_s;
    std_res.push_back(std_s.size());
    std_res.push_back(std_s.empty());
    timer.stop();
    test_res->std_time = timer.get_stop();

    
    timer.start();
    ft::set<int>   ft_m;
    ft_res.push_back(ft_m.size());
    ft_res.push_back(ft_m.empty());
    timer.stop();
    test_res->ft_time = timer.get_stop();

    test_res->passed = true;
}

template <class Set>
void    print_set(const Set& set) {
    typename Set::iterator   it;
    while (it != set.end()) {
        std::cout << *it++ << ", ";
    }
    std::cout << std::endl;
}

static void    test_range_constructor(
    test_result* test_res,
    std::vector<int>& std_res,
    std::vector<int>& ft_res
) {
    print_header("Testing range constructor", BLUE);
    Timer       timer;
    std::set<int> reference;

    for (int i = 0; i < 10; i++) {
        reference.insert(i);
    }

    timer.start();
    std::set<int> std_s(reference.begin(), reference.end());
    std_res.push_back(std_s.size());
    std_res.push_back(std_s.empty());
    timer.stop();
    test_res->std_time = timer.get_stop();

    
    timer.start();
    ft::set<int> ft_s(reference.begin(), reference.end());
    ft_res.push_back(ft_s.size());
    ft_res.push_back(ft_s.empty());
    timer.stop();
    test_res->ft_time = timer.get_stop();
    
    //print_set(std_s);
    //print_set(ft_s);

    test_res->passed = true;
}

static void    test_assignation_operator(
    test_result* test_res,
    std::vector<int>& std_res,
    std::vector<int>& ft_res
) {
    print_header("Testing operator=", BLUE);
    Timer       timer;
    std::set<int>      std_reference;
    ft::set<int>       ft_reference;

    for (int i = 0; i < 300; i++) {
        ft_reference.insert(i * 100);
        std_reference.insert(i * 100);
    }

    timer.start();
    std::set<int>   std_s = std_reference;
    std_res.push_back(std_s.size());
    std_res.push_back(std_s.empty());
    timer.stop();
    test_res->std_time = timer.get_stop();

    
    timer.start();
    ft::set<int>   ft_s = ft_reference;
    ft_res.push_back(ft_s.size());
    ft_res.push_back(ft_s.empty());
    timer.stop();
    test_res->ft_time = timer.get_stop();

    test_res->passed = true;
}

static void    test_swap(
    test_result* test_res,
    std::vector<int>& std_res,
    std::vector<int>& ft_res
) {
    print_header("Testing swap", BLUE);
    Timer       timer;
    std::set<int>      std_reference;
    ft::set<int>       ft_reference;

    for (int i = 0; i < 300; i++) {
        ft_reference.insert(i * 100);
        std_reference.insert(i * 100);
    }

    std::set<int>   std_s;
    ft::set<int>   ft_s;
    for (int i = 4000; i > 0; i--) {
        ft_s.insert(i * 100);
        std_s.insert(i * 100);
    }

    timer.start();
    std_res.push_back(std_s.size());
    std_s.swap(std_reference);
    std_res.push_back(std_s.size());
    std_res.push_back(std_reference.size());
    timer.stop();
    test_res->std_time = timer.get_stop();

    
    timer.start();
    ft_res.push_back(ft_s.size());
    ft_s.swap(ft_reference);
    ft_res.push_back(ft_s.size());
    ft_res.push_back(ft_reference.size());
    timer.stop();
    test_res->ft_time = timer.get_stop();

    test_res->passed = true;
}

static void    test_iterators(
    test_result* test_res,
    std::vector<int>& std_res,
    std::vector<int>& ft_res
) {
    print_header("Testing iterators", BLUE);
    Timer       timer;

    std::set<int>   std_s;
    ft::set<int>   ft_s;
    for (int i = 4000; i > 0; i--) {
        ft_s.insert(i * 100);
        std_s.insert(i * 100);
    }

    timer.start();
    std::set<int>::iterator std_it = std_s.begin();
    std::set<int>::const_iterator std_cit = std_s.begin();
    std_it++;
    ++std_it;
    std_cit++;
    std_cit++;
    ++std_cit;
    --std_cit;
    std_cit--;
    std_res.push_back(*std_it);
    std_res.push_back(*std_cit);
    std_res.push_back(std_it == std_cit);
    std_res.push_back(std_it != std_cit);
    timer.stop();
    test_res->std_time = timer.get_stop();

    
    timer.start();
    ft::set<int>::iterator ft_it = ft_s.begin();
    ft::set<int>::const_iterator ft_cit = ft_s.begin();
    ft_it++;
    ++ft_it;
    ft_cit++;
    ft_cit++;
    ++ft_cit;
    --ft_cit;
    ft_cit--;
    ft_res.push_back(*ft_it);
    ft_res.push_back(*ft_cit);
    ft_res.push_back(ft_it == ft_cit);
    ft_res.push_back(ft_it != ft_cit);
    timer.stop();
    test_res->ft_time = timer.get_stop();

    test_res->passed = true;
}

static void    test_begin_end(
    test_result* test_res,
    std::vector<int>& std_res,
    std::vector<int>& ft_res
) {
    print_header("Testing begin() and end()", BLUE);
    Timer       timer;

    std::set<int>   std_s;
    ft::set<int>    ft_s;
    for (int i = 4000; i > 0; i--) {
        ft_s.insert(i * 100);
        std_s.insert(i * 100);
    }

    timer.start();
    std::set<int>::iterator std_it = std_s.begin();
    std::set<int>::const_iterator std_cit = std_s.begin();
    std::set<int>::iterator std_eit = std_s.begin();
    std::set<int>::const_iterator std_ceit = std_s.begin();
    std_it++;
    ++std_it;
    std_cit++;
    std_cit++;
    ++std_cit;
    --std_cit;
    std_cit--;
    std_eit--;
    --std_eit;
    --std_ceit;
    std_ceit--;
    std_res.push_back(*std_eit);
    std_res.push_back(*std_ceit);
    std_res.push_back(*std_it);
    std_res.push_back(*std_cit);
    std_res.push_back(std_eit == std_ceit);
    std_res.push_back(std_eit != std_ceit);
    std_res.push_back(std_it == std_cit);
    std_res.push_back(std_it != std_cit);
    timer.stop();
    test_res->std_time = timer.get_stop();

    
    timer.start();
    ft::set<int>::iterator ft_it = ft_s.begin();
    ft::set<int>::const_iterator ft_cit = ft_s.begin();
    ft::set<int>::iterator ft_eit = ft_s.begin();
    ft::set<int>::const_iterator ft_ceit = ft_s.begin();
    ft_it++;
    ++ft_it;
    ft_cit++;
    ft_cit++;
    ++ft_cit;
    --ft_cit;
    ft_cit--;
    ft_eit--;
    --ft_eit;
    --ft_ceit;
    ft_ceit--;
    ft_res.push_back(*ft_eit);
    ft_res.push_back(*ft_ceit);
    ft_res.push_back(*ft_it);
    ft_res.push_back(*ft_cit);
    ft_res.push_back(ft_eit == ft_ceit);
    ft_res.push_back(ft_eit != ft_ceit);
    ft_res.push_back(ft_it == ft_cit);
    ft_res.push_back(ft_it != ft_cit);
    timer.stop();
    test_res->ft_time = timer.get_stop();

    test_res->passed = true;
}

#define NUM_SET_TESTS 6
bool    test_set() {
    typedef void    (*unittest)(test_result*, std::vector<int>&, std::vector<int>&);
    bool res = PASSED;

    print_header("Testing set", YELLOW);

    unittest    tests[NUM_SET_TESTS] = {
        &test_default_constructor_empty,
        &test_range_constructor,
        test_assignation_operator,
        &test_swap,
        &test_iterators,
        &test_begin_end
    };

    for (size_t i = 0; i < NUM_SET_TESTS; i++) {
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