#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

// Forward declaration (випереджаюче оголошення), щоб клас Form знав, що клас Bureaucrat існує
class Bureaucrat;

class Form
{
    private:
    const std::string _name;
    const int _gradeToSign;
    const int _gradeToExecute;
    bool _isSigned;

    public:
    Form();
    Form(const std::string& name, int gradeToSign, int gradeToExecute, bool isSigned);
    Form(const Form& other);
    Form& operator=(const Form& other);

    ~Form();

    std::string getName() const; //Getters
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(const Bureaucrat& bureaucrat);

    // Exceptions
    class GradeTooHighException : public std::exception
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

std::ostream& operator<<(std::ostream& out, const Form& f);

#endif