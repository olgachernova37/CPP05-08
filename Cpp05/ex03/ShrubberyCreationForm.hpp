#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream> //files

class ShrubberyCreationForm : public AForm
{
    private:
        const std::string _target;
        ShrubberyCreationForm(); // denide def const
    public:
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        virtual ~ShrubberyCreationForm();
        // Перевизначення методу execute
        virtual void execute(Bureaucrat const & executor) const;
};

#endif