#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "Bureaucrat.hpp"
#include "AForm.hpp"
class PresidentialPardonForm : public AForm
{
    private:
        const std::string _target;
        PresidentialPardonForm();
    public:
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        virtual ~PresidentialPardonForm();

        virtual void execute(Bureaucrat const & executor) const;

};



#endif