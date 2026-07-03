#include "Bureaucrat.hpp"
#include "Form.hpp"

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

    try
    {
       Form f1("Blank", 50, 100, false);
       std::cout <<f1<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr <<"Form error"<< e.what() << '\n';
    }
    
        try
    {
       Form f1("Blank", 50, 140, false);
       std::cout <<f1<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr <<"Form error: "<< e.what() << '\n';
    }


    Bureaucrat b3("Harry", 110);
    Form f3("Blank", 100, 75, false);
    b3.signForm(f3);


    return(0);
}