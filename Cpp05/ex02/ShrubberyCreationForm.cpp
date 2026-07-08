#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubberry is created", 145, 137, false), _target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) 
{
    // Ми викликаємо конструктор копіювання базового класу AForm(other)
}

// Оператор присвоювання
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        // Викликаємо оператор присвоювання базового класу для копіювання _isSigned
        AForm::operator=(other);
        // _target є const std::string, тому ми не можемо його змінити тут.
        // Це нормально для об'єктів із константними полями.
    }
    return *this;
}

void  ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
        if(!this->getIsSigned())
        {
            throw AForm::FormNotSignedException();
        }
        if (executor.getGrade() > this->getGradeToExecute()) 
        {
            throw AForm::GradeTooLowException();
        }

        std::ofstream outfile((this->_target + "_shrubbery").c_str());
        if (!outfile.is_open()) {
            std::cerr << "Error: cannot open file" << std::endl;
            return;
        }

        // Записуємо твою ялинку у файл
        outfile << "    *" << std::endl;
        outfile << "   ***" << std::endl;
        outfile << "  *****" << std::endl;
        outfile << " *******" << std::endl;
        outfile << "   |||" << std::endl;

        outfile.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}