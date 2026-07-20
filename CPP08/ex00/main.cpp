#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    // Test 1: std::vector
    std::vector<int> vec;
    for (int i = 1; i <= 5; ++i) {
        vec.push_back(i * 10); // [10, 20, 30, 40, 50]
    }

    std::cout << "--- Testing std::vector ---" << std::endl;
    try {
        std::vector<int>::iterator it = easyfind(vec, 30);
        std::cout << "Found value: " << *it << std::endl;

        std::cout << "Searching for non-existent value..." << std::endl;
        easyfind(vec, 99); // Throws exception
    } 
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Test 2: std::list
    std::list<int> lst;
    lst.push_back(100);
    lst.push_back(200);

    std::cout << "\n--- Testing std::list ---" << std::endl;
    try {
        std::list<int>::iterator it = easyfind(lst, 100);
        std::cout << "Found value: " << *it << std::endl;

        easyfind(lst, 500); // Throws exception
    } 
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}