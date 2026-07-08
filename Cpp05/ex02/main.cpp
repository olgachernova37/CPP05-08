#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <ctime>   // для time()
#include <cstdlib> // для srand()
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main ()
{
    std::srand(std::time(NULL));
    try
    {
        Bureaucrat b2("Germi", 1);
        std::cout <<b2<<std::endl;
        Bureaucrat b1("Ron", 160);
        std::cout <<b1<<std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << "Error:" <<e.what()<< std::endl;
    }

        try
    {
        Bureaucrat b2("Germi", 1);
        Bureaucrat b1("Ron", 145);
        

        std::cout <<b1<<std::endl;
        std::cout <<b2<<std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << "Error of Bureaucrat:" <<e.what()<< std::endl;
    }
std::cout <<"______________________________________________"<<std::endl;
 //tests for shrubbery
    try
    {
        Bureaucrat b2("Germi", 1);
        ShrubberyCreationForm shrub("home");
        std::cout << shrub << std::endl;
        shrub.beSigned(b2);
        shrub.execute(b2);
    }
    catch(const std::exception& e) {
        std::cerr << "Error of Shrubbery:" <<e.what()<< std::endl;
    }
    std::cout <<"__________"<<std::endl;
    try
    {
        Bureaucrat b2("Ron", 149);
        ShrubberyCreationForm shrub("home");
        std::cout << shrub << std::endl;
        shrub.beSigned(b2);
        shrub.execute(b2);
    }
    catch(const std::exception& e) {
        std::cerr << "Error of Shrubbery:" <<e.what()<< std::endl;
    }
    std::cout <<"______________________________________________"<<std::endl;
    //tests for robotomy
    try
    {
        Bureaucrat b2("Germi", 1);
        RobotomyRequestForm robot("home");
        std::cout << robot << std::endl;
        robot.beSigned(b2);
        robot.execute(b2);
    }
    catch(const std::exception& e) {
        std::cerr << "Error of Robotomy:" <<e.what()<< std::endl;
    }
    std::cout <<"__________"<<std::endl;
    try
    {
        Bureaucrat b2("Ron", 149);
        RobotomyRequestForm robot("home");
        std::cout << robot << std::endl;
        robot.beSigned(b2);
        robot.execute(b2);
    }
    catch(const std::exception& e) {
        std::cerr << "Error of Robotomy:" <<e.what()<< std::endl;
    }
    std::cout <<"______________________________________________"<<std::endl;
    //tests for presidential
    try
    {
        Bureaucrat b2("Germi", 1);
        PresidentialPardonForm pres("home");
        std::cout << pres << std::endl;
        pres.beSigned(b2);
        pres.execute(b2);
    }
    catch(const std::exception& e) {
        std::cerr << "Error of Presidential:" <<e.what()<< std::endl;
    }
    std::cout <<"________________"<<std::endl;
    try
    {
        Bureaucrat b2("Ron", 149);
        PresidentialPardonForm pres("home");
        std::cout << pres << std::endl;
        pres.beSigned(b2);
        pres.execute(b2);
    }
    catch(const std::exception& e) {
        std::cerr << "Error of Presidential:" <<e.what()<< std::endl;
    }   


    return(0);
}