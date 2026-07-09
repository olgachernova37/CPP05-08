#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    private:
    // Helper methods to create each concrete form type
    AForm* createShrubbery(const std::string& target) const;
    AForm* createRobotomy(const std::string& target) const;
    AForm* createPresidential(const std::string& target) const;
    public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    AForm* makeForm(const std::string& formName, const std::string& target) const;

    class UnknownFormException : public std::exception
    {
        public:
        virtual const char* what() const throw();
    };
};

#endif