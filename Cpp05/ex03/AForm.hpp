#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include <string>
#include <exception>

// Forward declaration (випереджаюче оголошення), щоб клас AForm знав, що клас Bureaucrat існує
class Bureaucrat;

class AForm
{
    private:
    const std::string _name;
    const int _gradeToSign;
    const int _gradeToExecute;
    bool _isSigned;

    public:
    AForm();
    AForm(const std::string& name, int gradeToSign, int gradeToExecute, bool isSigned);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);

    virtual ~AForm();

    std::string getName() const; //Getters
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(const Bureaucrat& bureaucrat);


    virtual void execute(Bureaucrat const & executor) const = 0;
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
    // Додаємо сюди, поруч із іншими винятками:
    class FormNotSignedException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
}; 

std::ostream& operator<<(std::ostream& out, const AForm& f);

#endif