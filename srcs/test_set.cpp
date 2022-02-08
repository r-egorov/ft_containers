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
    ft::set<int>   ft_s;
    ft_res.push_back(ft_s.size());
    ft_res.push_back(ft_s.empty());
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

static void    test_single_insert(
    test_result* test_res,
    std::vector<int>& std_res,
    std::vector<int>& ft_res
) {
    print_header("Testing insert(single)", BLUE);
    Timer       timer;

    std::set<int>   std_s;
    ft::set<int>    ft_s;
    for (int i = 4000; i > 0; i--) {
        ft_s.insert(i * 100);
        std_s.insert(i * 100);
    }

    std::pair<std::set<int>::iterator, bool> std_pair;
    ft::pair<ft::set<int>::iterator, bool> ft_pair;
    timer.start();
    std_pair = std_s.insert(500);
    std_res.push_back(*(std_pair.first));
    std_res.push_back(std_pair.second);
    std_pair = std_s.insert(5000);
    std_res.push_back(*(std_pair.first));
    std_res.push_back(std_pair.second);
    std_pair = std_s.insert(1);
    std_res.push_back(*(std_pair.first));
    std_res.push_back(std_pair.second);
    std_pair = std_s.insert(333);
    std_res.push_back(*(std_pair.first));
    std_res.push_back(std_pair.second);
    std_pair = std_s.insert(333);
    std_res.push_back(*(std_pair.first));
    std_res.push_back(std_pair.second);
    timer.stop();
    test_res->std_time = timer.get_stop();

    
    timer.start();
    ft_pair = ft_s.insert(500);
    ft_res.push_back(*(ft_pair.first));
    ft_res.push_back(ft_pair.second);
    ft_pair = ft_s.insert(5000);
    ft_res.push_back(*(ft_pair.first));
    ft_res.push_back(ft_pair.second);
    ft_pair = ft_s.insert(1);
    ft_res.push_back(*(ft_pair.first));
    ft_res.push_back(ft_pair.second);
    ft_pair = ft_s.insert(333);
    ft_res.push_back(*(ft_pair.first));
    ft_res.push_back(ft_pair.second);
    ft_pair = ft_s.insert(333);
    ft_res.push_back(*(ft_pair.first));
    ft_res.push_back(ft_pair.second);
    timer.stop();
    test_res->ft_time = timer.get_stop();

    test_res->passed = true;
}

static void    test_hint_insert(
    test_result* test_res,
    std::vector<int>& std_res,
    std::vector<int>& ft_res
) {
    print_header("Testing insert(hint)", BLUE);
    Timer       timer;

    std::set<int>   std_s;
    ft::set<int>    ft_s;
    for (int i = 4000; i > 0; i--) {
        ft_s.insert(i * 100);
        std_s.insert(i * 100);
    }

    std::set<int>::iterator std_return;
    std::set<int>::iterator std_hint;
    ft::set<int>::iterator ft_return;
    ft::set<int>::iterator ft_hint;
    timer.start();
    std_hint = std_s.lower_bound(10000);
    std_return = std_s.insert(std_hint, 10000);
    std_res.push_back(*(std_return));

    std_hint = std_s.lower_bound(8888);
    std_return = std_s.insert(std_hint, 8888);
    std_res.push_back(*(std_return));

    std_return = std_s.insert(std_s.begin(), 8888);
    std_res.push_back(*(std_return));

    std_return = std_s.insert(std_s.end(), 8888);
    std_res.push_back(*(std_return));
    timer.stop();
    test_res->std_time = timer.get_stop();

    
    timer.start();
    ft_hint = ft_s.lower_bound(10000);
    ft_return = ft_s.insert(ft_hint, 10000);
    ft_res.push_back(*(ft_return));

    ft_hint = ft_s.lower_bound(8888);
    ft_return = ft_s.insert(ft_hint, 8888);
    ft_res.push_back(*(ft_return));

    ft_return = ft_s.insert(ft_s.begin(), 8888);
    ft_res.push_back(*(ft_return));

    ft_return = ft_s.insert(ft_s.end(), 8888);
    ft_res.push_back(*(ft_return));
    timer.stop();
    test_res->ft_time = timer.get_stop();

    test_res->passed = true;
}

static void    test_range_insert(
    test_result* test_res,
    std::vector<int>& std_res,
    std::vector<int>& ft_res
) {
    print_header("Testing insert(range)", BLUE);
    Timer       timer;

    std::set<int>   std_s;
    ft::set<int>    ft_s;
    for (int i = 4000; i > 0; i--) {
        ft_s.insert(i * 100);
        std_s.insert(i * 100);
    }

    std::set<int>    std_new_s;
    ft::set<int>   ft_new_s;
    timer.start();
    std_new_s.insert(std_s.begin(), std_s.find(500));
    std_res.push_back(std_new_s.size());
    std_res.push_back(*(std_new_s.find(400)));
    timer.stop();
    test_res->std_time = timer.get_stop();

    
    timer.start();
    ft_new_s.insert(ft_s.begin(), ft_s.find(500));
    ft_res.push_back(ft_new_s.size());
    ft_res.push_back(*(ft_new_s.find(400)));
    timer.stop();
    test_res->ft_time = timer.get_stop();

    test_res->passed = true;
}

static void    test_erase_position(
    test_result* test_res,
    std::vector<int>& std_res,
    std::vector<int>& ft_res
) {
    print_header("Testing erase(position)", BLUE);
    Timer       timer;

    std::set<int>   std_s;
    ft::set<int>    ft_s;
    for (int i = 4000; i > 0; i--) {
        ft_s.insert(i * 100);
        std_s.insert(i * 100);
    }

    std::set<int>::iterator    std_found;
    ft::set<int>::iterator    ft_found;
    timer.start();
    std_res.push_back(std_s.size());
    std_found = std_s.find(500);
    std_s.erase(std_found);
    std_res.push_back(std_s.size());
    std_s.erase(std_s.begin());
    std_res.push_back(std_s.size());
    timer.stop();
    test_res->std_time = timer.get_stop();

    
    timer.start();
    ft_res.push_back(ft_s.size());
    ft_found = ft_s.find(500);
    ft_s.erase(ft_found);
    ft_res.push_back(ft_s.size());
    ft_s.erase(ft_s.begin());
    ft_res.push_back(ft_s.size());
    timer.stop();
    test_res->ft_time = timer.get_stop();

    test_res->passed = true;
}

static void    test_erase_key(
    test_result* test_res,
    std::vector<int>& std_res,
    std::vector<int>& ft_res
) {
    print_header("Testing erase(key)", BLUE);
    Timer       timer;

    std::set<int>   std_s;
    ft::set<int>    ft_s;
    for (int i = 4000; i > 0; i--) {
        ft_s.insert(i * 100);
        std_s.insert(i * 100);
    }

    timer.start();
    std_res.push_back(std_s.size());
    std_s.erase(500);
    std_res.push_back(std_s.size());
    std_s.erase(80000);
    std_res.push_back(std_s.size());
    std_s.erase(-790);
    std_res.push_back(std_s.size());
    std_s.erase(100);
    std_res.push_back(std_s.size());
    timer.stop();
    test_res->std_time = timer.get_stop();

    
    timer.start();
    ft_res.push_back(ft_s.size());
    ft_s.erase(500);
    ft_res.push_back(ft_s.size());
    ft_s.erase(80000);
    ft_res.push_back(ft_s.size());
    ft_s.erase(-790);
    ft_res.push_back(ft_s.size());
    ft_s.erase(100);
    ft_res.push_back(ft_s.size());
    timer.stop();
    test_res->ft_time = timer.get_stop();

    test_res->passed = true;
}


#define NUM_SET_TESTS 11
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
        &test_begin_end,
        &test_single_insert,
        &test_hint_insert,
        &test_range_insert,
        &test_erase_position,
        &test_erase_key
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