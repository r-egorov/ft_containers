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

void    print_test_result(const bool& res, const test_result& test_res) {
	int margin = (40 - 21) / 2;

    std::cout << "STD TIME: " << test_res.std_time << " ms\t";
    std::cout << "FT TIME: " << test_res.ft_time << " ms" << std::endl;
    if (res == PASSED) {
	    std::cout << GREEN << "*" << std::string(margin, ' ')
        << " >>> TEST PASSED <<< " << std::string(margin, ' ') << "*" << RESET
        << std::endl;
    } else {
	    std::cout << RED << "*" << std::string(margin, ' ')
        << " >>> TEST FAILED <<< " << std::string(margin, ' ') << "*" << RESET
        << std::endl;
    }
}

bool        test_all() {
    test        tests[2] = {
        &test_vector,
        &test_stack
    };

    for (size_t i = 0; i < 2; i++) {
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
    tests["all"] = &test_all;

    tests[choice]();

    return (0);
}