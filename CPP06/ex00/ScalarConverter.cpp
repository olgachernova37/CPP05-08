#include "ScalarConverter.hpp"

// Private Orthodox Canonical Form elements
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& src) { (void)src; }
ScalarConverter::~ScalarConverter() {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) { (void)rhs; return *this; }

void ScalarConverter::convert(const std::string& literal) {
    // 1. Handle explicit single character literal exception
    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        char c = literal[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
        return;
    }

    // 2. Explicitly handle pseudo-literals to bypass compiler/strtod variance
    if (literal == "nan" || literal == "nanf") {
        std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan" << std::endl;
        return;
    }
    if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff") {
        std::cout << "char: impossible\nint: impossible\nfloat: inff\ndouble: inf" << std::endl;
        return;
    }
    if (literal == "-inf" || literal == "-inff") {
        std::cout << "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf" << std::endl;
        return;
    }

    // 3. Normalize standard floats for strtod (strip trailing 'f')
    std::string str = literal;
    if (str.length() > 1 && str[str.length() - 1] == 'f') {
        str = str.substr(0, str.length() - 1);
    }

    // 4. Parse using strtod
    char* endptr;
    double val = std::strtod(str.c_str(), &endptr);

    // If parsing didn't consume the entire string, it's garbage input
    if (*endptr != '\0') {
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
        return;
    }

    // 5. Output Character
    if (val < CHAR_MIN || val > CHAR_MAX) {
        std::cout << "char: impossible" << std::endl;
    } else {
        char c = static_cast<char>(val);
        if (std::isprint(c)) std::cout << "char: '" << c << "'" << std::endl;
        else std::cout << "char: Non displayable" << std::endl;
    }

    // 6. Output Integer
    if (val < INT_MIN || val > INT_MAX) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(val) << std::endl;
    }

    // 7. Dynamic Precision Calculation
    // Find how many numbers are after the decimal point to preserve user precision
    size_t dotPos = literal.find('.');
    int precision = 1; // Default requirement
    if (dotPos != std::string::npos) {
        precision = 0;
        for (size_t i = dotPos + 1; i < literal.length(); ++i) {
            if (std::isdigit(literal[i])) precision++;
        }
        if (precision == 0) precision = 1; // Safeguard for "42."
    }

    // 8. Output Float and Double with absolute precision control
    std::cout << std::fixed << std::setprecision(precision);
    std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
    std::cout << "double: " << val << std::endl;
}
