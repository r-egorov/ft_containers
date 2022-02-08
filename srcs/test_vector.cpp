#include "tests.hpp"
#define NUM_VECTOR_TESTS 22

void    test_default_constructor(test_result* test_res) {
    print_header("Testing default constructor", BLUE);
    Timer   timer;
    bool res = PASSED;
    std::vector<int>     std_res;
    std::vector<int>     std_v;

    timer.start();
    std_res.push_back(std_v.size());
    std_v.push_back(1);
    std_v.push_back(3);
    std_v.push_back(6);
    std_res.push_back(std_v.size());
    timer.stop();
    test_res->std_time = timer.get_stop();

    std::vector<int>     ft_res;
    ft::vector<int>      ft_v;

    timer.start();
    ft_res.push_back(ft_v.size());
    ft_v.push_back(1);
    ft_v.push_back(3);
    ft_v.push_back(6);
    ft_res.push_back(ft_v.size());
    timer.stop();
    test_res->ft_time = timer.get_stop();

    if (std_res != ft_res) {
        res = FAILED;
    }

    for (size_t i = 0; i < ft_v.size(); i++) {
        if (std_v[i] != ft_v[i]) {
            res = FAILED;
        }
    }

    test_res->passed = res;
}

void    test_fill_constructor(test_result* test_res) {
    print_header("Testing fill constructor", BLUE);
    Timer   timer;
    bool res = PASSED;
    std::vector<int>     std_res;
    std::vector<int>     ft_res;
    
    timer.start();
    std::vector<int>     std_v(5, 100);
    timer.stop();
    test_res->std_time = timer.get_stop();

    timer.start();
    ft::vector<int>      ft_v(5, 100);
    timer.stop();
    test_res->ft_time = timer.get_stop();

    std_res.push_back(std_v.size());
    ft_res.push_back(ft_v.size());

    if (std_res != ft_res) {
        res = FAILED;
    }

    for (size_t i = 0; i < ft_v.size(); i++) {
        if (std_v[i] != ft_v[i]) {
            res = FAILED;
        }
    }
    test_res->passed = res;
}

void    test_range_constructor(test_result* test_res) {
    print_header("Testing range constructor", BLUE);
    Timer   timer;
    bool res = PASSED;
    std::vector<int>     std_res;
    std::vector<int>     ft_res;
    
    std::vector<int>     reference(5, 1000);
    
    timer.start();
    std::vector<int>     std_v(reference.begin(), reference.end());
    timer.stop();
    test_res->std_time = timer.get_stop();

    timer.start();
    ft::vector<int>      ft_v(reference.begin(), reference.end());
    timer.stop();
    test_res->ft_time = timer.get_stop();

    std_res.push_back(std_v.size());
    ft_res.push_back(ft_v.size());

    if (std_res != ft_res) {
        res = FAILED;
    }

    for (size_t i = 0; i < ft_v.size(); i++) {
        if (std_v[i] != ft_v[i]) {
            res = FAILED;
        }
    }
    test_res->passed = res;
}

void    test_copy_constructor(test_result* test_res) {
    print_header("Testing copy constructor", BLUE);
    Timer   timer;
    bool res = PASSED;
    std::vector<int>     std_res;
    std::vector<int>     ft_res;
    
    std::vector<int>     std_reference(5, 1000);
    ft::vector<int>      ft_reference(5, 1000);

    timer.start();
    std::vector<int>     std_v(std_reference);
    timer.stop();
    test_res->std_time = timer.get_stop();

    timer.start();
    ft::vector<int>      ft_v(ft_reference);
    timer.stop();
    test_res->ft_time = timer.get_stop();

    std_res.push_back(std_v.size());
    ft_res.push_back(ft_v.size());

    if (std_res != ft_res) {
        res = FAILED;
    }

    for (size_t i = 0; i < ft_v.size(); i++) {
        if (std_v[i] != ft_v[i] || &(ft_v[i]) == &(ft_reference[i])) {
            res = FAILED;
        }
    }
    test_res->passed = res;
}

void    test_assignation(test_result* test_res) {
    print_header("Testing operator=", BLUE);
    Timer   timer;
    bool res = PASSED;
    std::vector<int>     std_res;
    std::vector<int>     ft_res;
    
    std::vector<int>     std_reference(5, 1000);
    ft::vector<int>      ft_reference(5, 1000);

    timer.start();
    std::vector<int>     std_v = std_reference;
    timer.stop();
    test_res->std_time = timer.get_stop();

    timer.start();
    ft::vector<int>      ft_v = ft_reference;
    timer.stop();
    test_res->ft_time = timer.get_stop();

    std_res.push_back(std_v.size());
    ft_res.push_back(ft_v.size());

    if (std_res != ft_res) {
        res = FAILED;
    }

    for (size_t i = 0; i < ft_v.size(); i++) {
        if (std_v[i] != ft_v[i] || &(ft_v[i]) == &(ft_reference[i])) {
            res = FAILED;
        }
    }
    test_res->passed = res;
}

void    test_empty(test_result* test_res) {
    print_header("Testing empty()", BLUE);
    Timer   timer;
    bool res = PASSED;
    std::vector<int>     std_res;
    std::vector<int>     ft_res;

    timer.start();
    std::vector<int>     std_v;
    std_res.push_back(std_v.empty());
    std_v.push_back(111);
    std_res.push_back(std_v.empty());
    timer.stop();
    test_res->std_time = timer.get_stop();

    timer.start();
    ft::vector<int>     ft_v;
    ft_res.push_back(ft_v.empty());
    ft_v.push_back(111);
    ft_res.push_back(ft_v.empty());
    timer.stop();
    test_res->ft_time = timer.get_stop();

    std_res.push_back(std_v.size());
    ft_res.push_back(ft_v.size());

    if (std_res != ft_res) {
        res = FAILED;
    }

    for (size_t i = 0; i < ft_v.size(); i++) {
        if (std_v[i] != ft_v[i]) {
            res = FAILED;
        }
    }
    test_res->passed = res;
}

void    test_begin(test_result* test_res) {
    print_header("Testing begin", BLUE);
    Timer   timer;
    bool res = PASSED;
    std::vector<int>     std_res;
    std::vector<int>     ft_res;

    std::vector<int>     std_v;
    ft::vector<int>     ft_v;
    for (int i = 0; i < 10; i++) {
        std_v.push_back(i);
        ft_v.push_back(i);
    }

    // Tesing std
    timer.start();
    std::vector<int>::iterator std_it = std_v.begin();
    std_res.push_back(*std_it);
    ++std_it;
    std_it++;
    --std_it;
    std_it += 2;
    std_res.push_back(*std_it);
    timer.stop();
    test_res->std_time = timer.get_stop();

    // Testing ft
    timer.start();
    ft::vector<int>::iterator ft_it = ft_v.begin();
    ft_res.push_back(*ft_it);
    ++ft_it;
    ft_it++;
    --ft_it;
    ft_it += 2;
    ft_res.push_back(*ft_it);
    timer.stop();
    test_res->ft_time = timer.get_stop();

    std_res.push_back(std_v.size());
    ft_res.push_back(ft_v.size());

    if (std_res != ft_res) {
        res = FAILED;
    }

    for (size_t i = 0; i < ft_v.size(); i++) {
        if (std_v[i] != ft_v[i]) {
            res = FAILED;
        }
    }
    test_res->passed = res;
}

void    test_end(test_result* test_res) {
    print_header("Testing end()", BLUE);
    Timer   timer;
    bool res = PASSED;
    std::vector<int>     std_res;
    std::vector<int>     ft_res;

    std::vector<int>     std_v;
    ft::vector<int>     ft_v;
    for (int i = 0; i < 10; i++) {
        std_v.push_back(i);
        ft_v.push_back(i);
    }

    // Tesing std
    timer.start();
    std::vector<int>::iterator std_it = std_v.end();
    std_res.push_back(*std_it);
    --std_it;
    std_it--;
    ++std_it;
    std_it -= 2;
    std_res.push_back(*std_it);
    timer.stop();
    test_res->std_time = timer.get_stop();

    // Testing ft
    timer.start();
    ft::vector<int>::iterator ft_it = ft_v.end();
    ft_res.push_back(*ft_it);
    --ft_it;
    ft_it--;
    ++ft_it;
    ft_it -= 2;
    ft_res.push_back(*ft_it);
    timer.stop();
    test_res->ft_time = timer.get_stop();

    std_res.push_back(std_v.size());
    ft_res.push_back(ft_v.size());

    if (std_res != ft_res) {
        res = FAILED;
    }

    for (size_t i = 0; i < ft_v.size(); i++) {
        if (std_v[i] != ft_v[i]) {
            res = FAILED;
        }
    }
    test_res->passed = res;
}


void    test_rbegin(test_result* test_res) {
    print_header("Testing rbegin", BLUE);
    Timer   timer;
    bool res = PASSED;
    std::vector<int>     std_res;
    std::vector<int>     ft_res;

    std::vector<int>     std_v;
    ft::vector<int>     ft_v;
    for (int i = 0; i < 10; i++) {
        std_v.push_back(i);
        ft_v.push_back(i);
    }

    // Tesing std
    timer.start();
    std::vector<int>::reverse_iterator std_it = std_v.rbegin();
    std_res.push_back(*std_it);
    ++std_it;
    std_it++;
    --std_it;
    std_it += 2;
    std_res.push_back(*std_it);
    timer.stop();
    test_res->std_time = timer.get_stop();

    // Testing ft
    timer.start();
    ft::vector<int>::reverse_iterator ft_it = ft_v.rbegin();
    ft_res.push_back(*ft_it);
    ++ft_it;
    ft_it++;
    --ft_it;
    ft_it += 2;
    ft_res.push_back(*ft_it);
    timer.stop();
    test_res->ft_time = timer.get_stop();

    std_res.push_back(std_v.size());
    ft_res.push_back(ft_v.size());

    if (std_res != ft_res) {
        res = FAILED;
    }

    for (size_t i = 0; i < ft_v.size(); i++) {
        if (std_v[i] != ft_v[i]) {
            res = FAILED;
        }
    }
    test_res->passed = res;
}

void    test_rend(test_result* test_res) {
    print_header("Testing rend()", BLUE);
    Timer   timer;
    bool res = PASSED;
    std::vector<int>     std_res;
    std::vector<int>     ft_res;

    std::vector<int>     std_v;
    ft::vector<int>     ft_v;
    for (int i = 0; i < 10; i++) {
        std_v.push_back(i);
        ft_v.push_back(i);
    }

    // Tesing std
    timer.start();
    std::vector<int>::reverse_iterator std_it = std_v.rend();
    --std_it;
    std_res.push_back(*std_it);
    std_it--;
    ++std_it;
    std_it -= 2;
    std_res.push_back(*std_it);
    timer.stop();
    test_res->std_time = timer.get_stop();

    // Testing ft
    timer.start();
    ft::vector<int>::reverse_iterator ft_it = ft_v.rend();
    --ft_it;
    ft_res.push_back(*ft_it);
    ft_it--;
    ++ft_it;
    ft_it -= 2;
    ft_res.push_back(*ft_it);
    timer.stop();
    test_res->ft_time = timer.get_stop();

    std_res.push_back(std_v.size());
    ft_res.push_back(ft_v.size());

    if (std_res != ft_res) {
        res = FAILED;
    }

    for (size_t i = 0; i < ft_v.size(); i++) {
        if (std_v[i] != ft_v[i]) {
            res = FAILED;
        }
    }
    test_res->passed = res;
}

void    test_resize(test_result* test_res) {
    print_header("Testing resize()", BLUE);
    Timer   timer;
    bool res = PASSED;
    std::vector<int>     std_res;
    std::vector<int>     ft_res;

    std::vector<int>     std_v;
    ft::vector<int>     ft_v;
    for (int i = 0; i < 10; i++) {
        std_v.push_back(i);
        ft_v.push_back(i);
    }

    // Tesing std
    timer.start();
    std_v.resize(20);
    std_res.push_back(std_v.size());
    std_res.push_back(std_v[15]);
    std_v.resize(3);
    std_res.push_back(std_v.size());
    std_res.push_back(std_v[2]);
    std_v.resize(1000, 42);
    std_res.push_back(std_v.size());
    std_res.push_back(std_v[513]);
    timer.stop();
    test_res->std_time = timer.get_stop();

    // Testing ft
    timer.start();
    ft_v.resize(20);
    ft_res.push_back(ft_v.size());
    ft_res.push_back(ft_v[15]);
    ft_v.resize(3);
    ft_res.push_back(ft_v.size());
    ft_res.push_back(ft_v[2]);
    ft_v.resize(1000, 42);
    ft_res.push_back(ft_v.size());
    ft_res.push_back(ft_v[513]);
    timer.stop();
    test_res->ft_time = timer.get_stop();

    std_res.push_back(std_v.size());
    ft_res.push_back(ft_v.size());

    if (std_res != ft_res) {
        res = FAILED;
    }

    for (size_t i = 0; i < ft_v.size(); i++) {
        if (std_v[i] != ft_v[i]) {
            res = FAILED;
        }
    }
    test_res->passed = res;
}

void    test_front_back(test_result* test_res) {
    print_header("Testing front(), back()", BLUE);
    Timer   timer;
    bool res = PASSED;
    std::vector<int>     std_res;
    std::vector<int>     ft_res;

    std::vector<int>     std_v;
    ft::vector<int>     ft_v;
    for (int i = 0; i < 10; i++) {
        std_v.push_back(i);
        ft_v.push_back(i);
    }

    // Tesing std
    timer.start();
    std_res.push_back(std_v.front());
    std_res.push_back(std_v.back());
    timer.stop();
    test_res->std_time = timer.get_stop();

    // Testing ft
    timer.start();
    ft_res.push_back(ft_v.front());
    ft_res.push_back(ft_v.back());
    timer.stop();
    test_res->ft_time = timer.get_stop();

    std_res.push_back(std_v.size());
    ft_res.push_back(ft_v.size());

    if (std_res != ft_res) {
        res = FAILED;
    }

    for (size_t i = 0; i < ft_v.size(); i++) {
        if (std_v[i] != ft_v[i]) {
            res = FAILED;
        }
    }
    test_res->passed = res;
}

void    test_fill_assign(test_result* test_res) {
    print_header("Testing fill-assign()", BLUE);
    Timer   timer;
    bool res = PASSED;
    std::vector<int>     std_res;
    std::vector<int>     ft_res;

    std::vector<int>     std_v;
    ft::vector<int>     ft_v;
    for (int i = 0; i < 10; i++) {
        std_v.push_back(i);
        ft_v.push_back(i);
    }

    // Tesing std
    timer.start();
    std_v.assign(5000, 42);
    std_res.push_back(std_v[1000]);
    timer.stop();
    test_res->std_time = timer.get_stop();

    // Testing ft
    timer.start();
    ft_v.assign(5000, 42);
    ft_res.push_back(ft_v[1000]);
    timer.stop();
    test_res->ft_time = timer.get_stop();

    std_res.push_back(std_v.size());
    ft_res.push_back(ft_v.size());

    if (std_res != ft_res) {
        res = FAILED;
    }

    for (size_t i = 0; i < ft_v.size(); i++) {
        if (std_v[i] != ft_v[i]) {
            res = FAILED;
        }
    }
    test_res->passed = res;
}

void    test_range_assign(test_result* test_res) {
    print_header("Testing range-assign()", BLUE);
    Timer   timer;
    bool res = PASSED;
    std::vector<int>     std_res;
    std::vector<int>     ft_res;

    std::vector<int>     std_v;
    ft::vector<int>     ft_v;
    for (int i = 0; i < 10; i++) {
        std_v.push_back(i);
        ft_v.push_back(i);
    }

    std::vector<int>    reference;
    for (int i = 0; i < 5000; i++) {
        reference.push_back(i);
    }

    // Tesing std
    timer.start();
    std_v.assign(reference.begin(), reference.end());
    std_res.push_back(std_v[1000]);
    timer.stop();
    test_res->std_time = timer.get_stop();

    // Testing ft
    timer.start();
    ft_v.assign(reference.begin(), reference.end());
    ft_res.push_back(ft_v[1000]);
    timer.stop();
    test_res->ft_time = timer.get_stop();

    std_res.push_back(std_v.size());
    ft_res.push_back(ft_v.size());

    if (std_res != ft_res) {
        res = FAILED;
    }

    for (size_t i = 0; i < ft_v.size(); i++) {
        if (std_v[i] != ft_v[i]) {
            res = FAILED;
        }
    }
    test_res->passed = res;
}

void    test_single_insert(test_result* test_res) {
    print_header("Testing single insert()", BLUE);
    Timer   timer;
    bool res = PASSED;
    std::vector<int>     std_res;
    std::vector<int>     ft_res;

    std::vector<int>     std_v;
    ft::vector<int>     ft_v;
    for (int i = 0; i < 10; i++) {
        std_v.push_back(i);
        ft_v.push_back(i);
    }

    // Tesing std
    timer.start();
    std_v.insert(std_v.begin() + 5, 42);
    std_res.push_back(std_v[5]);
    timer.stop();
    test_res->std_time = timer.get_stop();

    // Testing ft
    timer.start();
    ft_v.insert(ft_v.begin() + 5, 42);
    ft_res.push_back(ft_v[5]);
    timer.stop();
    test_res->ft_time = timer.get_stop();

    std_res.push_back(std_v.size());
    ft_res.push_back(ft_v.size());

    if (std_res != ft_res) {
        res = FAILED;
    }

    for (size_t i = 0; i < ft_v.size(); i++) {
        if (std_v[i] != ft_v[i]) {
            res = FAILED;
        }
    }
    test_res->passed = res;
}

void    test_fill_insert(test_result* test_res) {
    print_header("Testing fill insert()", BLUE);
    Timer   timer;
    bool res = PASSED;
    std::vector<int>     std_res;
    std::vector<int>     ft_res;

    std::vector<int>     std_v;
    ft::vector<int>     ft_v;
    for (int i = 0; i < 10; i++) {
        std_v.push_back(i);
        ft_v.push_back(i);
    }

    // Tesing std
    timer.start();
    std_v.insert(std_v.begin() + 5, 5, 42);
    std_res.push_back(std_v[7]);
    timer.stop();
    test_res->std_time = timer.get_stop();

    // Testing ft
    timer.start();
    ft_v.insert(ft_v.begin() + 5, 5, 42);
    ft_res.push_back(ft_v[7]);
    timer.stop();
    test_res->ft_time = timer.get_stop();

    std_res.push_back(std_v.size());
    ft_res.push_back(ft_v.size());

    if (std_res != ft_res) {
        res = FAILED;
    }

    for (size_t i = 0; i < ft_v.size(); i++) {
        if (std_v[i] != ft_v[i]) {
            res = FAILED;
        }
    }
    test_res->passed = res;
}

void    test_range_insert(test_result* test_res) {
    print_header("Testing range insert()", BLUE);
    Timer   timer;
    bool res = PASSED;
    std::vector<int>     std_res;
    std::vector<int>     ft_res;

    std::vector<int>     std_v;
    ft::vector<int>     ft_v;
    for (int i = 0; i < 10; i++) {
        std_v.push_back(i);
        ft_v.push_back(i);
    }
    std::vector<int> reference;
    for (int i = 500; i < 5000; i++) {
        reference.push_back(i);
    }

    // Tesing std
    timer.start();
    std_v.insert(std_v.begin() + 5, reference.begin(), reference.end());
    std_res.push_back(std_v[500]);
    timer.stop();
    test_res->std_time = timer.get_stop();

    // Testing ft
    timer.start();
    ft_v.insert(ft_v.begin() + 5, reference.begin(), reference.end());
    ft_res.push_back(ft_v[500]);
    timer.stop();
    test_res->ft_time = timer.get_stop();

    std_res.push_back(std_v.size());
    ft_res.push_back(ft_v.size());

    if (std_res != ft_res) {
        res = FAILED;
    }

    for (size_t i = 0; i < ft_v.size(); i++) {
        if (std_v[i] != ft_v[i]) {
            res = FAILED;
        }
    }
    test_res->passed = res;
}

void    test_erase_position(test_result* test_res) {
    print_header("Testing position erase()", BLUE);
    Timer   timer;
    bool res = PASSED;
    std::vector<int>     std_res;
    std::vector<int>     ft_res;

    std::vector<int>     std_v;
    ft::vector<int>     ft_v;
    for (int i = 0; i < 10; i++) {
        std_v.push_back(i);
        ft_v.push_back(i);
    }

    // Tesing std
    timer.start();
    std_v.erase(std_v.begin() + 3);
    std_res.push_back(std_v[3]);
    timer.stop();
    test_res->std_time = timer.get_stop();

    // Testing ft
    timer.start();
    ft_v.erase(ft_v.begin() + 3);
    ft_res.push_back(ft_v[3]);
    timer.stop();
    test_res->ft_time = timer.get_stop();

    std_res.push_back(std_v.size());
    ft_res.push_back(ft_v.size());

    if (std_res != ft_res) {
        res = FAILED;
    }

    for (size_t i = 0; i < ft_v.size(); i++) {
        if (std_v[i] != ft_v[i]) {
            res = FAILED;
        }
    }
    test_res->passed = res;
}

void    test_erase_range(test_result* test_res) {
    print_header("Testing range erase()", BLUE);
    Timer   timer;
    bool res = PASSED;
    std::vector<int>     std_res;
    std::vector<int>     ft_res;

    std::vector<int>     std_v;
    ft::vector<int>     ft_v;
    for (int i = 0; i < 10; i++) {
        std_v.push_back(i);
        ft_v.push_back(i);
    }

    // Tesing std
    timer.start();
    std_v.erase(std_v.begin() + 1, std_v.begin() + 5);
    std_res.push_back(std_v[2]);
    timer.stop();
    test_res->std_time = timer.get_stop();

    // Testing ft
    timer.start();
    ft_v.erase(ft_v.begin() + 1, ft_v.begin() + 5);
    ft_res.push_back(ft_v[2]);
    timer.stop();
    test_res->ft_time = timer.get_stop();

    std_res.push_back(std_v.size());
    ft_res.push_back(ft_v.size());

    if (std_res != ft_res) {
        res = FAILED;
    }

    for (size_t i = 0; i < ft_v.size(); i++) {
        if (std_v[i] != ft_v[i]) {
            res = FAILED;
        }
    }
    test_res->passed = res;
}

void    test_swap(test_result* test_res) {
    print_header("Testing swap()", BLUE);
    Timer   timer;
    bool res = PASSED;
    std::vector<int>     std_res;
    std::vector<int>     ft_res;

    std::vector<int>     std_v;
    ft::vector<int>     ft_v;
    for (int i = 0; i < 10; i++) {
        std_v.push_back(i);
        ft_v.push_back(i);
    }
    std::vector<int>     std_v_1;
    ft::vector<int>     ft_v_1;
    for (int i = 100; i > 0; i--) {
        std_v_1.push_back(i);
        ft_v_1.push_back(i);
    }

    // Tesing std
    timer.start();
    std::vector<int>::iterator it = std_v.begin();
    it++;
    it++;
    std_res.push_back(*it);
    std_v.swap(std_v_1);
    std_res.push_back(std_v_1.size());
    std_res.push_back(std_v_1[5]);
    std_res.push_back(std_v[50]);
    it++;
    std_res.push_back(*it);
    timer.stop();
    test_res->std_time = timer.get_stop();

    // Testing ft
    timer.start();
    ft::vector<int>::iterator ftit = ft_v.begin();
    ftit++;
    ftit++;
    ft_res.push_back(*ftit);
    ft_v.swap(ft_v_1);
    ft_res.push_back(ft_v_1.size());
    ft_res.push_back(ft_v_1[5]);
    ft_res.push_back(ft_v[50]);
    ftit++;
    ft_res.push_back(*ftit);
    timer.stop();
    test_res->ft_time = timer.get_stop();

    std_res.push_back(std_v.size());
    ft_res.push_back(ft_v.size());

    if (std_res != ft_res) {
        res = FAILED;
    }

    for (size_t i = 0; i < ft_v.size(); i++) {
        if (std_v[i] != ft_v[i]) {
            res = FAILED;
        }
    }
    test_res->passed = res;
}

void    test_iterators(test_result* test_res) {
    print_header("Testing iterators", BLUE);
    Timer   timer;
    bool res = PASSED;
    std::vector<int>     std_res;
    std::vector<int>     ft_res;

    std::vector<int>     std_v;
    ft::vector<int>     ft_v;
    for (int i = 0; i < 10; i++) {
        std_v.push_back(i);
        ft_v.push_back(i);
    }

    // Tesing std
    timer.start();
    std::vector<int>::iterator it = std_v.begin();
    std::vector<int>::const_iterator cit = std_v.begin();
    it++;
    it++;
    std_res.push_back(*it);
    std_res.push_back(*cit);
    std_res.push_back(it == cit);
    std_res.push_back(it > cit);
    std_res.push_back(it < cit);
    std_res.push_back(it <= cit);
    std_res.push_back(it >= cit);
    std_res.push_back(it != cit);
    cit++;
    std_res.push_back(*cit);
    timer.stop();
    test_res->std_time = timer.get_stop();

    // Testing ft
    timer.start();
    ft::vector<int>::iterator ftit = ft_v.begin();
    ft::vector<int>::const_iterator ftcit = ft_v.begin();
    ftit++;
    ftit++;
    ft_res.push_back(*ftit);
    ft_res.push_back(*ftcit);
    ft_res.push_back(ftit == ftcit);
    ft_res.push_back(ftit > ftcit);
    ft_res.push_back(ftit < ftcit);
    ft_res.push_back(ftit <= ftcit);
    ft_res.push_back(ftit >= ftcit);
    ft_res.push_back(ftit != ftcit);
    ftcit++;
    ft_res.push_back(*ftcit);
    timer.stop();
    test_res->ft_time = timer.get_stop();

    std_res.push_back(std_v.size());
    ft_res.push_back(ft_v.size());

    if (std_res != ft_res) {
        res = FAILED;
    }

    for (size_t i = 0; i < ft_v.size(); i++) {
        if (std_v[i] != ft_v[i]) {
            res = FAILED;
        }
    }
    test_res->passed = res;
}

void    test_comparision(test_result* test_res) {
    print_header("Testing comparision operators", BLUE);
    Timer   timer;
    bool res = PASSED;
    std::vector<int>     std_res;
    std::vector<int>     ft_res;

    std::vector<int>     std_reference;
    ft::vector<int>     ft_reference;
    for (int i = 400; i > 0; i--) {
        std_reference.push_back(i);
        ft_reference.push_back(i);
    }

    std::vector<int>     std_v;
    ft::vector<int>     ft_v;
    for (int i = 0; i < 10; i++) {
        std_v.push_back(i);
        ft_v.push_back(i);
    }

    // Tesing std
    timer.start();
    std_res.push_back(std_v == std_reference);
    std_res.push_back(std_v != std_reference);
    std_res.push_back(std_v < std_reference);
    std_res.push_back(std_v <= std_reference);
    std_res.push_back(std_v >= std_reference);
    std_res.push_back(std_v > std_reference);
    timer.stop();
    test_res->std_time = timer.get_stop();

    // Testing ft
    timer.start();
    ft_res.push_back(ft_v == ft_reference);
    ft_res.push_back(ft_v != ft_reference);
    ft_res.push_back(ft_v < ft_reference);
    ft_res.push_back(ft_v <= ft_reference);
    ft_res.push_back(ft_v >= ft_reference);
    ft_res.push_back(ft_v > ft_reference);
    timer.stop();
    test_res->ft_time = timer.get_stop();

    std_res.push_back(std_v.size());
    ft_res.push_back(ft_v.size());

    if (std_res != ft_res) {
        res = FAILED;
    }

    for (size_t i = 0; i < ft_v.size(); i++) {
        if (std_v[i] != ft_v[i]) {
            res = FAILED;
        }
    }
    test_res->passed = res;
}


bool    test_vector() {
    typedef void (*unittest)(test_result*);
    bool res = PASSED;

    print_header("Testing vector", YELLOW);
    unittest    tests[NUM_VECTOR_TESTS] = {
        &test_default_constructor,
        &test_fill_constructor,
        &test_range_constructor,
        &test_copy_constructor,
        &test_assignation,
        &test_empty,
        &test_begin,
        &test_end,
        &test_rbegin,
        &test_rend,
        &test_resize,
        &test_front_back,
        &test_fill_assign,
        &test_range_assign,
        &test_single_insert,
        &test_fill_insert,
        &test_range_insert,
        &test_erase_position,
        &test_erase_range,
        &test_swap,
        &test_iterators,
        &test_comparision
    };

    for (size_t i = 0; i < NUM_VECTOR_TESTS; i++) {
        test_result test_res;
        tests[i](&test_res);
        if (!test_res.passed) {
            res = FAILED;
        }
        print_test_result(res, test_res);
    }
    return (res);
}