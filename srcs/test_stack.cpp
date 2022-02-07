#include "tests.hpp"
#define NUM_STACK_TESTS 4


void    test_default_constructor(
    test_result* test_res,
    std::vector<int>& std_res,
    std::vector<int>& ft_res
) {
    print_header("Testing default constructor", BLUE);
    Timer       timer;

    timer.start();
    std::stack<int>    std_st;
    std_st.push(5);
    timer.stop();
    test_res->std_time = timer.get_stop();
    std_res.push_back(std_st.size());
    std_res.push_back(std_st.top());

    
    timer.start();
    ft::stack<int>     ft_st;
    ft_st.push(5);
    timer.stop();
    test_res->ft_time = timer.get_stop();
    ft_res.push_back(ft_st.size());
    ft_res.push_back(ft_st.top());

    test_res->passed = true;
}

void    test_empty(
    test_result* test_res,
    std::vector<int>& std_res,
    std::vector<int>& ft_res
) {
    print_header("Testing empty()", BLUE);
    Timer       timer;

    timer.start();
    std::stack<int>    std_st;
    std_res.push_back(std_st.empty());
    std_st.push(5);
    std_res.push_back(std_st.empty());
    timer.stop();
    test_res->std_time = timer.get_stop();

    
    timer.start();
    ft::stack<int>    ft_st;
    ft_res.push_back(ft_st.empty());
    ft_st.push(5);
    ft_res.push_back(ft_st.empty());
    timer.stop();
    test_res->ft_time = timer.get_stop();

    test_res->passed = true;
}

void    test_pop(
    test_result* test_res,
    std::vector<int>& std_res,
    std::vector<int>& ft_res
) {
    print_header("Testing pop()", BLUE);
    Timer       timer;

    timer.start();
    std::stack<int>    std_st;
    std_res.push_back(std_st.empty());
    std_st.push(5);
    std_st.push(10);
    std_st.push(15);
    std_res.push_back(std_st.top());
    std_st.pop();
    std_res.push_back(std_st.top());
    std_res.push_back(std_st.empty());
    std_st.pop();
    std_st.pop();
    std_res.push_back(std_st.empty());
    timer.stop();
    test_res->std_time = timer.get_stop();

    
    timer.start();
    ft::stack<int>    ft_st;
    ft_res.push_back(ft_st.empty());
    ft_st.push(5);
    ft_st.push(10);
    ft_st.push(15);
    ft_res.push_back(ft_st.top());
    ft_st.pop();
    ft_res.push_back(ft_st.top());
    ft_res.push_back(ft_st.empty());
    ft_st.pop();
    ft_st.pop();
    ft_res.push_back(ft_st.empty());
    timer.stop();
    test_res->ft_time = timer.get_stop();

    test_res->passed = true;
}

void    test_comparision(
    test_result* test_res,
    std::vector<int>& std_res,
    std::vector<int>& ft_res
) {
    print_header("Testing comparision operators", BLUE);
    Timer       timer;

    std::stack<int>    std_st1;
    std::stack<int>    std_st2;
    ft::stack<int>    ft_st1;
    ft::stack<int>    ft_st2;

    for (int i = 0; i < 10; i++) {
        std_st1.push(i);
        std_st2.push(i * 10);
        ft_st1.push(i);
        ft_st2.push(i * 10);
    }
    timer.start();
    std_res.push_back(std_st1 == std_st2);
    std_res.push_back(std_st1 < std_st2);
    std_res.push_back(std_st1 > std_st2);
    std_res.push_back(std_st1 <= std_st2);
    std_res.push_back(std_st1 >= std_st2);
    std_res.push_back(std_st1 != std_st2);
    timer.stop();
    test_res->std_time = timer.get_stop();

    
    timer.start();
    ft_res.push_back(ft_st1 == ft_st2);
    ft_res.push_back(ft_st1 < ft_st2);
    ft_res.push_back(ft_st1 > ft_st2);
    ft_res.push_back(ft_st1 <= ft_st2);
    ft_res.push_back(ft_st1 >= ft_st2);
    ft_res.push_back(ft_st1 != ft_st2);
    test_res->ft_time = timer.get_stop();

    test_res->passed = true;
}

bool    test_stack() {
    typedef void    (*unittest)(test_result*, std::vector<int>&, std::vector<int>&);
    bool res = PASSED;

    print_header("Testing stack", YELLOW);

    unittest    tests[NUM_STACK_TESTS] = {
        &test_default_constructor,
        &test_empty,
        &test_pop,
        &test_comparision
    };

    for (size_t i = 0; i < NUM_STACK_TESTS; i++) {
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