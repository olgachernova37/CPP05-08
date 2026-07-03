#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Form;

class Bureaucrat
{
    private:
    const std::string _name;
    int _grade;
    
    public:
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other); //creating new object ___copy constructor
    Bureaucrat& operator=(const Bureaucrat& other);//copy in already created object (2  of them alredy exist)___copy assignment operator 


    ~Bureaucrat();

    // Getters
    std::string getName() const;
    int getGrade() const;

    // Grade operations
    void incrementGrade(); // 3 -> 2
    void decrementGrade(); // 3 -> 4

    void signForm(Form& form);

    class GradeTooHighException : public std::exception //nested classes, so they are part of Bureaucrat.
    {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };

};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);//overloading operator <<




#endif
