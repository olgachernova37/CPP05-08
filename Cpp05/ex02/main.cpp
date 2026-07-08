#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main ()
{

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

 


    return(0);
}