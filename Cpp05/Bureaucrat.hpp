#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
    private:
    const std::string _name;
    int _grade;
    
    public:
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other); //creating new object
    
    ~Bureaucrat();

     // Getters
    std::string getName() const;
    int getGrade() const;
};




#endif
