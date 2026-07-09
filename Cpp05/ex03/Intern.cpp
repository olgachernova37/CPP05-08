#include "Intern.hpp"
#include <iostream>

Intern::Intern() {}
Intern::Intern(const Intern& other) { (void)other; }
Intern& Intern::operator=(const Intern& other) { (void)other; return *this; }
Intern::~Intern() {}

// Helper function implementations
AForm* Intern::createShrubbery(const std::string& target) const {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target) const {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string& target) const {
    return new PresidentialPardonForm(target);
}

// The clean, non-if/else makeForm implementation
AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    
    // 1. Define a type definition for our member function pointers
    typedef AForm* (Intern::*FormFactory)(const std::string& target) const;

    // 2. Create an array of the exact form names requested by the subject
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    // 3. Create a matching array of member function pointers
    FormFactory factories[] = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidential
    };

    // 4. Loop through the array to find a match
    for (int i = 0; i < 3; i++) {
        if (formNames[i] == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            // Execute the matching factory function using pointer-to-member-function syntax
            return (this->*factories[i])(target);
        }
    }

    // 5. If no match was found, print an error and return NULL
    std::cout << "Error: Intern cannot create form '" << formName 
              << "' because it doesn't exist." << std::endl;
    return NULL;
}