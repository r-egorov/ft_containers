#include "tests.hpp"

void    print_header(const std::string& str, const char* color) {
	int margin = (40 - str.length()) / 2;
	int width = (margin * 2 + str.length()) + 2;

	std::cout << color << std::endl;
	std::cout << std::string(width, '*') << std::endl;
	std::cout << "*" << std::string(margin, ' ') << str << std::string(margin, ' ') << "*" << std::endl;
	std::cout << std::string(width, '*') << std::endl;
	std::cout << RESET;
}

void    print_passed_failed(const bool& res) {
	int margin = (40 - 21) / 2;

    if (res == PASSED) {
	    std::cout << GREEN << "*" << std::string(margin, ' ')
        << " >>> TEST PASSED <<< " << std::string(margin, ' ') << "*" << RESET
        << std::endl;
    } else {
	    std::cout << RED_PRINT << "*" << std::string(margin, ' ')
        << " >>> TEST FAILED <<< " << std::string(margin, ' ') << "*" << RESET
        << std::endl;
    }
}

void    print_test_result(const bool& res, const test_result& test_res) {
    std::cout << "STD TIME: " << test_res.std_time << " ms\t";
    std::cout << "FT TIME: " << test_res.ft_time << " ms" << std::endl;
    print_passed_failed(res);
}

bool        test_all() {
    test        tests[4] = {
        &test_vector,
        &test_stack,
        &test_map,
        &test_set
    };

    for (size_t i = 0; i < 4; i++) {
        bool res = tests[i]();
        if (!res) {
            return (false);
        }
    }
    return (true);
}


int         main(int argc, char** argv) {
    std::string     choice;

    if (argc != 2) {
        std::cout << ">> Testing all <<" << std::endl;
        choice = "all";
    }
    else {
        choice = std::string(argv[1]);
    }

    std::map<std::string, test>     tests;

    tests["vector"] = &test_vector;
    tests["stack"] = &test_stack;
    tests["map"] = &test_map;
    tests["set"] = &test_set;
    tests["all"] = &test_all;

    bool res;
    res = tests[choice]();
    print_passed_failed(res);

    return (0);
}