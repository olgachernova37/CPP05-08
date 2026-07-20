#ifndef EASYFIND_HPP
#define EASYFIND_HPP

# include <algorithm>
# include <map>
#include <exception>


class NotFoundException : public std::exception {
    public:
        virtual const char* what() const throw();
};

// Шаблон функції 
template <typename T>
typename T::iterator easyfind(T& container, int value);

template <typename T>
typename T::const_iterator easyfind(const T& container, int value);

#include "easyfind.tpp"

#endif