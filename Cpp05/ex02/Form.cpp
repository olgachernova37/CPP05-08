#include "Form.hpp"
#include "Bureaucrat.hpp" //щоб бачити b.getGrade()


Form::Form():_name("Default Bureaucrat"),_gradeToSign(50), _gradeToExecute(100) {};

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute, bool isSigned) 
:_name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSigned(isSigned)
{  
    if (_gradeToSign > 150 || _gradeToExecute >150)
            throw Form::GradeTooLowException();
    if (_gradeToSign < 1 || _gradeToExecute < 1)
            throw Form::GradeTooHighException();
}


// Конструктор копіювання:
Form::Form(const Form& other)
    : _name(other._name),
    _gradeToSign(other._gradeToSign),
    _gradeToExecute(other._gradeToExecute),
    _isSigned(other._isSigned){}

// Оператор присвоювання
Form& Form::operator=(const Form& other) {
    if (this != &other) {
        this->_isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form() {}

std::string Form::getName() const { return this->_name; }
bool Form::getIsSigned() const { return this->_isSigned; }
int Form::getGradeToSign() const { return this->_gradeToSign; }
int Form::getGradeToExecute() const { return this->_gradeToExecute; }

// =============================================================================
// 3. ОСНОВНА ЛОГІКА: МЕТОД beSigned
// =============================================================================

void Form::beSigned(const Bureaucrat& bureaucrat) {
    // Пам'ятаємо: ранг 1 вищий за ранг 2.
    // Якщо ранг бюрократа більший (наприклад, 50) за необхідний (наприклад, 20),
    // це означає, що його ранг занадто НИЗЬКИЙ для цього підпису.
    if (bureaucrat.getGrade() > this->_gradeToSign) {
        throw Form::GradeTooLowException();
    }
    // Якщо перевірка пройшла — підписуємо форму
    this->_isSigned = true;
}

// =============================================================================
// 4. РЕАЛІЗАЦІЯ ВИНЯТКІВ
// =============================================================================

const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high! (Must be between 1 and 150)";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low! (Bureaucrat doesn't have enough authority)";
}

// =============================================================================
// 5. ПЕРЕВАНТАЖЕННЯ ОПЕРАТОРА <<
// =============================================================================

std::ostream& operator<<(std::ostream& out, const Form& f) {
    out << "Form \"" << f.getName() << "\": "
        << "Status: " << (f.getIsSigned() ? "Signed" : "Unsigned") << ", "
        << "Required Grade to Sign: " << f.getGradeToSign() << ", "
        << "Required Grade to Execute: " << f.getGradeToExecute() << ".";
    return out;
}
