#include "AForm.hpp"
#include "Bureaucrat.hpp" //щоб бачити b.getGrade()


AForm::AForm():_name("Default Bureaucrat"),_gradeToSign(50), _gradeToExecute(100) {};

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute, bool isSigned) 
:_name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSigned(isSigned)
{  
    if (_gradeToSign > 150 || _gradeToExecute >150)
            throw AForm::GradeTooLowException();
    if (_gradeToSign < 1 || _gradeToExecute < 1)
            throw AForm::GradeTooHighException();
}


// Конструктор копіювання:
AForm::AForm(const AForm& other)
    : _name(other._name),
    _gradeToSign(other._gradeToSign),
    _gradeToExecute(other._gradeToExecute),
    _isSigned(other._isSigned){}

// Оператор присвоювання
AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        this->_isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const { return this->_name; }
bool AForm::getIsSigned() const { return this->_isSigned; }
int AForm::getGradeToSign() const { return this->_gradeToSign; }
int AForm::getGradeToExecute() const { return this->_gradeToExecute; }

// =============================================================================
// 3. ОСНОВНА ЛОГІКА: МЕТОД beSigned
// =============================================================================

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    // Пам'ятаємо: ранг 1 вищий за ранг 2.
    // Якщо ранг бюрократа більший (наприклад, 50) за необхідний (наприклад, 20),
    // це означає, що його ранг занадто НИЗЬКИЙ для цього підпису.
    if (bureaucrat.getGrade() > this->_gradeToSign) {
        throw AForm::GradeTooLowException();
    }
    // Якщо перевірка пройшла — підписуємо форму
    this->_isSigned = true;
}

// =============================================================================
// 4. РЕАЛІЗАЦІЯ ВИНЯТКІВ
// =============================================================================

const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm grade is too high! (Must be between 1 and 150)";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm grade is too low! (Bureaucrat doesn't have enough authority)";
}

// =============================================================================
// 5. ПЕРЕВАНТАЖЕННЯ ОПЕРАТОРА <<
// =============================================================================

std::ostream& operator<<(std::ostream& out, const AForm& f) {
    out << "AForm \"" << f.getName() << "\": "
        << "Status: " << (f.getIsSigned() ? "Signed" : "Unsigned") << ", "
        << "Required Grade to Sign: " << f.getGradeToSign() << ", "
        << "Required Grade to Execute: " << f.getGradeToExecute() << ".";
    return out;
}
