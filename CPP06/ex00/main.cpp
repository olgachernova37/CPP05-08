#include "ScalarConverter.hpp"

void runTest(const std::string& testCase) {
    std::cout << "=============================" << std::endl;
    std::cout << "Input: \"" << testCase << "\"" << std::endl;
    std::cout << "=============================" << std::endl;
    ScalarConverter::convert(testCase);
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    if (argc == 2) {
        ScalarConverter::convert(argv[1]);
        return 0;
    }

    std::cout << "No arguments provided. Running test suite..." << std::endl << std::endl;

    // Char tests
    runTest("a");
    runTest("0"); // Edge case: '0' as a string is treated as number 0, not char '0'
    
    // Int tests
    runTest("42");
    runTest("-42");
    runTest("2147483647");  // INT_MAX
    runTest("2147483648");  // INT_MAX + 1 (Overflow test)

    // Float tests
    runTest("0.0f");
    runTest("4.2f");
    runTest("-4.2f");

    // Double tests
    runTest("0.0");
    runTest("4.2");
    runTest("-3.14159");

    // Pseudo-literal tests
    runTest("nan");
    runTest("nanf");
    runTest("+inf");
    runTest("-inff");

    // Garbage checks
    runTest("42.0ff");
    runTest("abc");
    runTest("42a");

    return 0;
}