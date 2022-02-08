#include "tests.hpp"

static void    test_default_constructor_empty(
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

void    test_iterators(
    test_result* test_res,
    std::vector<int>& std_res,
    std::vector<int>& ft_res
) {
    print_header("Testing iterators", BLUE);
    Timer       timer;

    std::map<int,int>   std_m;
    ft::map<int,int>   ft_m;
    for (int i = 4000; i > 0; i--) {
        ft_m[i] = i * 100;
        std_m[i] = i * 100;
    }

    timer.start();
    std::map<int,int>::iterator std_it = std_m.begin();
    std::map<int,int>::const_iterator std_cit = std_m.begin();
    std_it++;
    ++std_it;
    std_cit++;
    std_cit++;
    ++std_cit;
    --std_cit;
    std_cit--;
    std_res.push_back(std_it->first);
    std_res.push_back(std_cit->first);
    std_res.push_back(std_it->second);
    std_res.push_back(std_cit->second);
    std_res.push_back(std_it == std_cit);
    std_res.push_back(std_it != std_cit);
    timer.stop();
    test_res->std_time = timer.get_stop();

    
    timer.start();
    ft::map<int,int>::iterator ft_it = ft_m.begin();
    ft::map<int,int>::const_iterator ft_cit = ft_m.begin();
    ft_it++;
    ++ft_it;
    ft_cit++;
    ft_cit++;
    ++ft_cit;
    --ft_cit;
    ft_cit--;
    ft_res.push_back(ft_it->first);
    ft_res.push_back(ft_cit->first);
    ft_res.push_back(ft_it->second);
    ft_res.push_back(ft_cit->second);
    ft_res.push_back(ft_it == ft_cit);
    ft_res.push_back(ft_it != ft_cit);
    timer.stop();
    test_res->ft_time = timer.get_stop();

    test_res->passed = true;
}


void    test_begin_end(
    test_result* test_res,
    std::vector<int>& std_res,
    std::vector<int>& ft_res
) {
    print_header("Testing begin() and end()", BLUE);
    Timer       timer;

    std::map<int,int>   std_m;
    ft::map<int,int>   ft_m;
    for (int i = 4000; i > 0; i--) {
        ft_m[i] = i * 100;
        std_m[i] = i * 100;
    }

    timer.start();
    std::map<int,int>::iterator std_it = std_m.begin();
    std::map<int,int>::const_iterator std_cit = std_m.begin();
    std::map<int,int>::iterator std_eit = std_m.begin();
    std::map<int,int>::const_iterator std_ceit = std_m.begin();
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
    std_res.push_back(std_eit->first);
    std_res.push_back(std_ceit->first);
    std_res.push_back(std_eit->second);
    std_res.push_back(std_ceit->second);
    std_res.push_back(std_it->first);
    std_res.push_back(std_cit->first);
    std_res.push_back(std_it->second);
    std_res.push_back(std_cit->second);
    std_res.push_back(std_eit == std_ceit);
    std_res.push_back(std_eit != std_ceit);
    std_res.push_back(std_it == std_cit);
    std_res.push_back(std_it != std_cit);
    timer.stop();
    test_res->std_time = timer.get_stop();

    
    timer.start();
    ft::map<int,int>::iterator ft_it = ft_m.begin();
    ft::map<int,int>::const_iterator ft_cit = ft_m.begin();
    ft::map<int,int>::iterator ft_eit = ft_m.begin();
    ft::map<int,int>::const_iterator ft_ceit = ft_m.begin();
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
    ft_res.push_back(ft_eit->first);
    ft_res.push_back(ft_ceit->first);
    ft_res.push_back(ft_eit->second);
    ft_res.push_back(ft_ceit->second);
    ft_res.push_back(ft_it->first);
    ft_res.push_back(ft_cit->first);
    ft_res.push_back(ft_it->second);
    ft_res.push_back(ft_cit->second);
    ft_res.push_back(ft_eit == ft_ceit);
    ft_res.push_back(ft_eit != ft_ceit);
    ft_res.push_back(ft_it == ft_cit);
    ft_res.push_back(ft_it != ft_cit);
    timer.stop();
    test_res->ft_time = timer.get_stop();

    test_res->passed = true;
}

void    test_brackets(
    test_result* test_res,
    std::vector<int>& std_res,
    std::vector<int>& ft_res
) {
    print_header("Testing operator[]", BLUE);
    Timer       timer;

    std::map<int,int>   std_m;
    ft::map<int,int>   ft_m;

    timer.start();
    std_m[5000] = 42;
    std_res.push_back(std_m[5000]);
    std_m[5000] = 777;
    std_res.push_back(std_m[5000]);
    std_m[15] = 7;
    std_res.push_back(std_m[15]);
    std_m[15] = 3000;
    std_res.push_back(std_m[15]);
    std_res.push_back(std_m.size());
    timer.stop();
    test_res->std_time = timer.get_stop();

    
    timer.start();
    ft_m[5000] = 42;
    ft_res.push_back(ft_m[5000]);
    ft_m[5000] = 777;
    ft_res.push_back(ft_m[5000]);
    ft_m[15] = 7;
    ft_res.push_back(ft_m[15]);
    ft_m[15] = 3000;
    ft_res.push_back(ft_m[15]);
    ft_res.push_back(ft_m.size());
    timer.stop();
    test_res->ft_time = timer.get_stop();

    test_res->passed = true;
}

void    test_single_insert(
    test_result* test_res,
    std::vector<int>& std_res,
    std::vector<int>& ft_res
) {
    print_header("Testing insert(single)", BLUE);
    Timer       timer;

    std::map<int,int>   std_m;
    ft::map<int,int>   ft_m;
    for (int i = 4000; i > 0; i--) {
        ft_m[i] = i * 100;
        std_m[i] = i * 100;
    }

    std::pair<std::map<int,int>::iterator, bool> std_pair;
    ft::pair<ft::map<int,int>::iterator, bool> ft_pair;
    timer.start();
    std_pair = std_m.insert(std::make_pair(500, 5000));
    std_res.push_back((std_pair.first)->first);
    std_res.push_back((std_pair.first)->second);
    std_res.push_back(std_pair.second);
    std_pair = std_m.insert(std::make_pair(10000, 5000));
    std_res.push_back((std_pair.first)->first);
    std_res.push_back((std_pair.first)->second);
    std_res.push_back(std_pair.second);
    std_pair = std_m.insert(std::make_pair(777, 1111));
    std_res.push_back((std_pair.first)->first);
    std_res.push_back((std_pair.first)->second);
    std_res.push_back(std_pair.second);
    std_pair = std_m.insert(std::make_pair(-777, 6578));
    std_res.push_back((std_pair.first)->first);
    std_res.push_back((std_pair.first)->second);
    std_res.push_back(std_pair.second);
    std_pair = std_m.insert(std::make_pair(-777, 33333));
    std_res.push_back((std_pair.first)->first);
    std_res.push_back((std_pair.first)->second);
    std_res.push_back(std_pair.second);
    timer.stop();
    test_res->std_time = timer.get_stop();

    
    timer.start();
    ft_pair = ft_m.insert(ft::make_pair(500, 5000));
    ft_res.push_back((ft_pair.first)->first);
    ft_res.push_back((ft_pair.first)->second);
    ft_res.push_back(ft_pair.second);
    ft_pair = ft_m.insert(ft::make_pair(10000, 5000));
    ft_res.push_back((ft_pair.first)->first);
    ft_res.push_back((ft_pair.first)->second);
    ft_res.push_back(ft_pair.second);
    ft_pair = ft_m.insert(ft::make_pair(777, 1111));
    ft_res.push_back((ft_pair.first)->first);
    ft_res.push_back((ft_pair.first)->second);
    ft_res.push_back(ft_pair.second);
    ft_pair = ft_m.insert(ft::make_pair(-777, 6578));
    ft_res.push_back((ft_pair.first)->first);
    ft_res.push_back((ft_pair.first)->second);
    ft_res.push_back(ft_pair.second);
    ft_pair = ft_m.insert(ft::make_pair(-777, 33333));
    ft_res.push_back((ft_pair.first)->first);
    ft_res.push_back((ft_pair.first)->second);
    ft_res.push_back(ft_pair.second);
    timer.stop();
    test_res->ft_time = timer.get_stop();

    test_res->passed = true;
}

void    test_hint_insert(
    test_result* test_res,
    std::vector<int>& std_res,
    std::vector<int>& ft_res
) {
    print_header("Testing insert(hint)", BLUE);
    Timer       timer;

    std::map<int,int>   std_m;
    ft::map<int,int>   ft_m;
    for (int i = 4000; i > 0; i--) {
        ft_m[i] = i * 100;
        std_m[i] = i * 100;
    }

    std::map<int,int>::iterator std_return;
    std::map<int,int>::iterator std_hint;
    ft::map<int,int>::iterator ft_return;
    ft::map<int,int>::iterator ft_hint;
    timer.start();
    std_hint = std_m.lower_bound(10000);
    std_return = std_m.insert(std_hint, std::make_pair(10000, 5000));
    std_res.push_back(std_return->first);
    std_res.push_back(std_return->second);

    std_hint = std_m.lower_bound(777);
    std_return = std_m.insert(std_hint, std::make_pair(777, 1111));
    std_res.push_back(std_return->first);
    std_res.push_back(std_return->second);

    std_return = std_m.insert(std_m.begin(), std::make_pair(-777, 6578));
    std_res.push_back(std_return->first);
    std_res.push_back(std_return->second);

    std_return = std_m.insert(std_m.end(), std::make_pair(-777, 33333));
    std_res.push_back(std_return->first);
    std_res.push_back(std_return->second);
    timer.stop();
    test_res->std_time = timer.get_stop();

    
    timer.start();
    ft_hint = ft_m.lower_bound(10000);
    ft_return = ft_m.insert(ft_hint, ft::make_pair(10000, 5000));
    ft_res.push_back(ft_return->first);
    ft_res.push_back(ft_return->second);

    ft_hint = ft_m.lower_bound(777);
    ft_return = ft_m.insert(ft_hint, ft::make_pair(777, 1111));
    ft_res.push_back(ft_return->first);
    ft_res.push_back(ft_return->second);

    ft_return = ft_m.insert(ft_m.begin(), ft::make_pair(-777, 6578));
    ft_res.push_back(ft_return->first);
    ft_res.push_back(ft_return->second);

    ft_return = ft_m.insert(ft_m.end(), ft::make_pair(-777, 33333));
    ft_res.push_back(ft_return->first);
    ft_res.push_back(ft_return->second);
    timer.stop();
    test_res->ft_time = timer.get_stop();

    test_res->passed = true;
}

void    test_range_insert(
    test_result* test_res,
    std::vector<int>& std_res,
    std::vector<int>& ft_res
) {
    print_header("Testing insert(range)", BLUE);
    Timer       timer;

    std::map<int,int>   std_m;
    ft::map<int,int>   ft_m;
    for (int i = 4000; i > 0; i--) {
        ft_m[i] = i * 100;
        std_m[i] = i * 100;
    }

    std::map<int,int>   std_new_m;
    ft::map<int,int>   ft_new_m;
    timer.start();
    std_new_m.insert(std_m.begin(), std_m.find(500));
    std_res.push_back(std_new_m.size());
    std_res.push_back(std_new_m[400]);
    timer.stop();
    test_res->std_time = timer.get_stop();

    
    timer.start();
    ft_new_m.insert(ft_m.begin(), ft_m.find(500));
    ft_res.push_back(ft_new_m.size());
    ft_res.push_back(ft_new_m[400]);
    timer.stop();
    test_res->ft_time = timer.get_stop();

    test_res->passed = true;
}

void    test_erase_position(
    test_result* test_res,
    std::vector<int>& std_res,
    std::vector<int>& ft_res
) {
    print_header("Testing erase(position)", BLUE);
    Timer       timer;

    std::map<int,int>   std_m;
    ft::map<int,int>   ft_m;
    for (int i = 4000; i > 0; i--) {
        ft_m[i] = i * 100;
        std_m[i] = i * 100;
    }

    std::map<int, int>::iterator    std_found;
    ft::map<int, int>::iterator    ft_found;
    timer.start();
    std_res.push_back(std_m.size());
    std_found = std_m.find(500);
    std_m.erase(std_found);
    std_res.push_back(std_m.size());
    std_m.erase(std_m.begin());
    std_res.push_back(std_m.size());
    timer.stop();
    test_res->std_time = timer.get_stop();

    
    timer.start();
    ft_res.push_back(ft_m.size());
    ft_found = ft_m.find(500);
    ft_m.erase(ft_found);
    ft_res.push_back(ft_m.size());
    ft_m.erase(ft_m.begin());
    ft_res.push_back(ft_m.size());
    timer.stop();
    test_res->ft_time = timer.get_stop();

    test_res->passed = true;
}

void    test_erase_key(
    test_result* test_res,
    std::vector<int>& std_res,
    std::vector<int>& ft_res
) {
    print_header("Testing erase(key)", BLUE);
    Timer       timer;

    std::map<int,int>   std_m;
    ft::map<int,int>   ft_m;
    for (int i = 4000; i > 0; i--) {
        ft_m[i] = i * 100;
        std_m[i] = i * 100;
    }

    timer.start();
    std_res.push_back(std_m.size());
    std_m.erase(500);
    std_res.push_back(std_m.size());
    std_m.erase(80000);
    std_res.push_back(std_m.size());
    std_m.erase(-790);
    std_res.push_back(std_m.size());
    std_m.erase(100);
    std_res.push_back(std_m.size());
    timer.stop();
    test_res->std_time = timer.get_stop();

    
    timer.start();
    ft_res.push_back(ft_m.size());
    ft_m.erase(500);
    ft_res.push_back(ft_m.size());
    ft_m.erase(80000);
    ft_res.push_back(ft_m.size());
    ft_m.erase(-790);
    ft_res.push_back(ft_m.size());
    ft_m.erase(100);
    ft_res.push_back(ft_m.size());
    timer.stop();
    test_res->ft_time = timer.get_stop();

    test_res->passed = true;
}

void    test_erase_range(
    test_result* test_res,
    std::vector<int>& std_res,
    std::vector<int>& ft_res
) {
    print_header("Testing erase(range)", BLUE);
    Timer       timer;

    std::map<int,int>   std_m;
    ft::map<int,int>   ft_m;
    for (int i = 4000; i > 0; i--) {
        ft_m[i] = i * 100;
        std_m[i] = i * 100;
    }

    timer.start();
    std_res.push_back(std_m.size());
    std_m.erase(std_m.begin(), std_m.find(1000));
    std_res.push_back(std_m.size());
    std_m.erase(std_m.find(1500), std_m.end());
    std_res.push_back(std_m.size());
    std_m.erase(std_m.begin(), std_m.end());
    std_res.push_back(std_m.size());
    timer.stop();
    test_res->std_time = timer.get_stop();

    
    timer.start();
    ft_res.push_back(ft_m.size());
    ft_m.erase(ft_m.begin(), ft_m.find(1000));
    ft_res.push_back(ft_m.size());
    ft_m.erase(ft_m.find(1500), ft_m.end());
    ft_res.push_back(ft_m.size());
    ft_m.erase(ft_m.begin(), ft_m.end());
    ft_res.push_back(ft_m.size());
    timer.stop();
    test_res->ft_time = timer.get_stop();

    test_res->passed = true;
}

void    test_clear(
    test_result* test_res,
    std::vector<int>& std_res,
    std::vector<int>& ft_res
) {
    print_header("Testing clear()", BLUE);
    Timer       timer;

    std::map<int,int>   std_m;
    ft::map<int,int>   ft_m;
    for (int i = 4000; i > 0; i--) {
        ft_m[i] = i * 100;
        std_m[i] = i * 100;
    }

    timer.start();
    std_res.push_back(std_m.size());
    std_m.clear();
    std_res.push_back(std_m.size());
    std_res.push_back(std_m.begin() == std_m.end());
    timer.stop();
    test_res->std_time = timer.get_stop();

    
    timer.start();
    ft_res.push_back(ft_m.size());
    ft_m.clear();
    ft_res.push_back(ft_m.size());
    ft_res.push_back(ft_m.begin() == ft_m.end());
    timer.stop();
    test_res->ft_time = timer.get_stop();

    test_res->passed = true;
}

void    test_count(
    test_result* test_res,
    std::vector<int>& std_res,
    std::vector<int>& ft_res
) {
    print_header("Testing count()", BLUE);
    Timer       timer;

    std::map<int,int>   std_m;
    ft::map<int,int>   ft_m;
    for (int i = 4000; i > 0; i--) {
        ft_m[i] = i * 100;
        std_m[i] = i * 100;
    }

    timer.start();
    std_res.push_back(std_m.count(1111111));
    std_res.push_back(std_m.count(500));
    std_res.push_back(std_m.count(-200));
    std_res.push_back(std_m.count(400));
    timer.stop();
    test_res->std_time = timer.get_stop();

    
    timer.start();
    ft_res.push_back(ft_m.count(1111111));
    ft_res.push_back(ft_m.count(500));
    ft_res.push_back(ft_m.count(-200));
    ft_res.push_back(ft_m.count(400));
    timer.stop();
    test_res->ft_time = timer.get_stop();

    test_res->passed = true;
}

void    test_lower_bound(
    test_result* test_res,
    std::vector<int>& std_res,
    std::vector<int>& ft_res
) {
    print_header("Testing lower_bound()", BLUE);
    Timer       timer;

    std::map<int,int>   std_m;
    ft::map<int,int>   ft_m;
    for (int i = 4000; i > 0; i--) {
        ft_m[i] = i * 100;
        std_m[i] = i * 100;
    }

    std::map<int,int>::iterator     std_it;
    std::map<int,int>::const_iterator     std_cit;
    timer.start();
    std_it = std_m.lower_bound(1111111);
    std_cit = std_m.lower_bound(500);
    std_res.push_back(std_it == std_m.end());
    std_res.push_back(std_cit->first);
    std_res.push_back(std_cit->second);
    std_it = std_m.lower_bound(10000);
    std_cit = std_m.lower_bound(800);
    std_res.push_back(std_it == std_m.end());
    std_res.push_back(std_cit->first);
    std_res.push_back(std_cit->second);
    std_it = std_m.lower_bound(1500);
    std_cit = std_m.lower_bound(1500);
    std_res.push_back(std_it->first);
    std_res.push_back(std_it->second);
    std_res.push_back(std_cit->first);
    std_res.push_back(std_cit->second);
    timer.stop();
    test_res->std_time = timer.get_stop();

    
    ft::map<int,int>::iterator     ft_it;
    ft::map<int,int>::const_iterator     ft_cit;
    timer.start();
    ft_it = ft_m.lower_bound(1111111);
    ft_cit = ft_m.lower_bound(500);
    ft_res.push_back(ft_it == ft_m.end());
    ft_res.push_back(ft_cit->first);
    ft_res.push_back(ft_cit->second);
    ft_it = ft_m.lower_bound(10000);
    ft_cit = ft_m.lower_bound(800);
    ft_res.push_back(ft_it == ft_m.end());
    ft_res.push_back(ft_cit->first);
    ft_res.push_back(ft_cit->second);
    ft_it = ft_m.lower_bound(1500);
    ft_cit = ft_m.lower_bound(1500);
    ft_res.push_back(ft_it->first);
    ft_res.push_back(ft_it->second);
    ft_res.push_back(ft_cit->first);
    ft_res.push_back(ft_cit->second);
    timer.stop();
    test_res->ft_time = timer.get_stop();

    test_res->passed = true;
}

void    test_upper_bound(
    test_result* test_res,
    std::vector<int>& std_res,
    std::vector<int>& ft_res
) {
    print_header("Testing upper_bound()", BLUE);
    Timer       timer;

    std::map<int,int>   std_m;
    ft::map<int,int>   ft_m;
    for (int i = 4000; i > 0; i--) {
        ft_m[i] = i * 100;
        std_m[i] = i * 100;
    }

    std::map<int,int>::iterator     std_it;
    std::map<int,int>::const_iterator     std_cit;
    timer.start();
    std_it = std_m.upper_bound(1111111);
    std_cit = std_m.upper_bound(500);
    std_res.push_back(std_it == std_m.end());
    std_res.push_back(std_cit->first);
    std_res.push_back(std_cit->second);
    std_it = std_m.upper_bound(10000);
    std_cit = std_m.upper_bound(800);
    std_res.push_back(std_it == std_m.end());
    std_res.push_back(std_cit->first);
    std_res.push_back(std_cit->second);
    std_it = std_m.upper_bound(1500);
    std_cit = std_m.upper_bound(1500);
    std_res.push_back(std_it->first);
    std_res.push_back(std_it->second);
    std_res.push_back(std_cit->first);
    std_res.push_back(std_cit->second);
    timer.stop();
    test_res->std_time = timer.get_stop();

    
    ft::map<int,int>::iterator     ft_it;
    ft::map<int,int>::const_iterator     ft_cit;
    timer.start();
    ft_it = ft_m.upper_bound(1111111);
    ft_cit = ft_m.upper_bound(500);
    ft_res.push_back(ft_it == ft_m.end());
    ft_res.push_back(ft_cit->first);
    ft_res.push_back(ft_cit->second);
    ft_it = ft_m.upper_bound(10000);
    ft_cit = ft_m.upper_bound(800);
    ft_res.push_back(ft_it == ft_m.end());
    ft_res.push_back(ft_cit->first);
    ft_res.push_back(ft_cit->second);
    ft_it = ft_m.upper_bound(1500);
    ft_cit = ft_m.upper_bound(1500);
    ft_res.push_back(ft_it->first);
    ft_res.push_back(ft_it->second);
    ft_res.push_back(ft_cit->first);
    ft_res.push_back(ft_cit->second);
    timer.stop();
    test_res->ft_time = timer.get_stop();

    test_res->passed = true;
}

void    test_equal_range(
    test_result* test_res,
    std::vector<int>& std_res,
    std::vector<int>& ft_res
) {
    print_header("Testing equal_range()", BLUE);
    Timer       timer;

    std::map<int,int>   std_m;
    ft::map<int,int>   ft_m;
    for (int i = 4000; i > 0; i--) {
        ft_m[i] = i * 100;
        std_m[i] = i * 100;
    }

    std::pair<std::map<int,int>::iterator,std::map<int,int>::iterator>     std_pair;
    std::pair<std::map<int,int>::const_iterator,std::map<int,int>::const_iterator>     std_cpair;
    timer.start();
    std_pair = std_m.equal_range(1000);
    std_res.push_back((std_pair.first)->first);
    std_res.push_back((std_pair.first)->second);
    std_pair = std_m.equal_range(1);
    std_res.push_back((std_pair.first)->first);
    std_res.push_back((std_pair.first)->second);
    std_pair = std_m.equal_range(4000);
    std_res.push_back(std_pair.first == std_m.end());
    std_res.push_back(std_pair.second == std_m.end());
    std_pair = std_m.equal_range(5000);
    std_res.push_back(std_pair.first == std_m.end());
    std_res.push_back(std_pair.second == std_m.end());
    timer.stop();
    test_res->std_time = timer.get_stop();

    
    ft::pair<ft::map<int,int>::iterator,ft::map<int,int>::iterator>     ft_pair;
    ft::pair<ft::map<int,int>::const_iterator,ft::map<int,int>::const_iterator>     ft_cpair;
    timer.start();
    ft_pair = ft_m.equal_range(1000);
    ft_res.push_back((ft_pair.first)->first);
    ft_res.push_back((ft_pair.first)->second);
    ft_pair = ft_m.equal_range(1);
    ft_res.push_back((ft_pair.first)->first);
    ft_res.push_back((ft_pair.first)->second);
    ft_pair = ft_m.equal_range(4000);
    ft_res.push_back(ft_pair.first == ft_m.end());
    ft_res.push_back(ft_pair.second == ft_m.end());
    ft_pair = ft_m.equal_range(5000);
    ft_res.push_back(ft_pair.first == ft_m.end());
    ft_res.push_back(ft_pair.second == ft_m.end());
    timer.stop();
    test_res->ft_time = timer.get_stop();

    test_res->passed = true;
}

#define NUM_MAP_TESTS 18
bool    test_map() {
    typedef void    (*unittest)(test_result*, std::vector<int>&, std::vector<int>&);
    bool res = PASSED;

    print_header("Testing map", YELLOW);

    unittest    tests[NUM_MAP_TESTS] = {
        &test_default_constructor_empty,
        &test_range_constructor,
        &test_assignation_operator,
        &test_begin_end,
        &test_brackets,
        &test_single_insert,
        &test_hint_insert,
        &test_range_insert,
        &test_erase_position,
        &test_erase_key,
        &test_erase_range,
        &test_clear,
        &test_count,
        &test_lower_bound,
        &test_upper_bound,
        &test_equal_range,
        &test_swap,
        &test_iterators
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