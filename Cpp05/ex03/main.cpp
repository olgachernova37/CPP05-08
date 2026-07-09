#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <ctime>   // для time()
#include <cstdlib> // для srand()
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main ()
{
    std::srand(std::time(NULL));

    std::cout << "=== Test 1: Bureaucrat Grade Bounds ===" << std::endl;
    try {
        Bureaucrat b2("Germi", 1);
        std::cout << b2 << std::endl;
        Bureaucrat b1("Ron", 160); // Should fail (grade too low)
        std::cout << b1 << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: Shrubbery Creation Form ===" << std::endl;
    try {
        Bureaucrat boss("Hermione", 1);
        Bureaucrat lowRank("Ron", 140); 
        ShrubberyCreationForm shrub("garden");

        std::cout << shrub << std::endl;
        boss.executeForm(shrub); 
        boss.signAForm(shrub);
        std::cout << shrub << std::endl;
        lowRank.executeForm(shrub);
        boss.executeForm(shrub);
    }
    catch(const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Robotomy Request Form ===" << std::endl;
    try {
        Bureaucrat boss("Hermione", 1);
        RobotomyRequestForm robot("Bender");

        std::cout << robot << std::endl;
        robot.beSigned(boss);
        
        boss.executeForm(robot);
        boss.executeForm(robot);
        boss.executeForm(robot);
    }
    catch(const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Presidential Pardon Form ===" << std::endl;
    try {
        Bureaucrat boss("Hermione", 1);
        Bureaucrat peasant("Ron", 149);
        PresidentialPardonForm pres("Arthur Weasley");

        std::cout << pres << std::endl;
        boss.signAForm(pres);
        peasant.executeForm(pres);
        boss.executeForm(pres);
    }
    catch(const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    } 

    std::cout << "\n=== Test 5: Intern Tests ===" << std::endl;
    {
        Intern someRandomIntern;
        Bureaucrat boss("Hermione", 1);
        AForm* rrf = NULL;

        // 1. Successful test (Robotomy Request)
        std::cout << "--- Intern Test: Good Form ---" << std::endl;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf) {
            std::cout << *rrf << std::endl;
            boss.signAForm(*rrf);
            boss.executeForm(*rrf);
            delete rrf; // Clean up memory!
            rrf = NULL;
        }

        std::cout << "----------------------------------" << std::endl;

        // 2. Successful test (Presidential Pardon)
        std::cout << "--- Intern Test: Another Good Form ---" << std::endl;
        rrf = someRandomIntern.makeForm("presidential pardon", "Harry Potter");
        if (rrf) {
            boss.signAForm(*rrf);
            boss.executeForm(*rrf);
            delete rrf; // Clean up memory!
            rrf = NULL;
        }

        std::cout << "----------------------------------" << std::endl;

        // 3. Bad test (Form name doesn't exist)
        std::cout << "--- Intern Test: Bad Form ---" << std::endl;
        rrf = someRandomIntern.makeForm("invalid tax form", "Voldemort");
        if (rrf == NULL) {
            std::cout << "Success: Intern correctly returned NULL for an invalid form name!" << std::endl;
        } else {
            delete rrf; // Defensive fallback
        }
    }

    return (0);
}