#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cmath>
#include <iomanip>

class ScalarConverter {
private:
    // Private to prevent instantiation
    ScalarConverter();
    ScalarConverter(const ScalarConverter& src);
    ~ScalarConverter();
    ScalarConverter& operator=(const ScalarConverter& rhs);

public:
    // The only public endpoint
    static void convert(const std::string& literal);
};

#endif
#define SCALARCONVERTER_HPP