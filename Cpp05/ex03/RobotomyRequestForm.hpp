#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <cstdlib> // Потрібно для rand() та srand()

class RobotomyRequestForm : public AForm
{
private:
    const std::string _target;
    RobotomyRequestForm(); // Забороняємо дефолтний конструктор

public:
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    virtual ~RobotomyRequestForm();

    // Перевизначення методу execute
    virtual void execute(Bureaucrat const & executor) const;
};

#endif