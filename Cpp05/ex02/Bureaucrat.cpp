#include "Bureaucrat.hpp"
#include "AForm.hpp"

class AForm;

Bureaucrat::Bureaucrat():_name("Default Bureaucrat"), _grade(150) {}; //називається списком ініціалізації членів класу (Member Initializer List)

// Конструктор з параметрами (тут робимо першу перевірку оцінки)
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    this->_grade = grade;
}

// Конструктор копіювання
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

// Оператор присвоювання (Orthodox Canonical AForm)
// Примітка: Оскільки _name є `const std::string`, ми не можемо його переприсвоїти.
// Змінюємо тільки _grade. Це абсолютно нормально для цього завдання.
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) { ///this mean змінна класу exactly this one
    if (this != &other) {                                       ///other just variable name
        this->_grade = other._grade;
    }
    return *this;
}

// Деструктор
Bureaucrat::~Bureaucrat() {}

// Геттери
std::string Bureaucrat::getName() const {
    return this->_name;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

// Збільшення рангу (число зменшується: з 3 до 2)
void Bureaucrat::incrementGrade() {
    if (this->_grade - 1 < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    this->_grade--;
}

// Зменшення рангу (число збільшується: з 3 до 4)
void Bureaucrat::decrementGrade() {
    if (this->_grade + 1 > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    this->_grade++;
}

// Реалізація винятків (Exceptions)
// Метод what() повертає рядок-пояснення помилки
const char* Bureaucrat::GradeTooHighException::what() const throw() { //promise compilator that this funk will not throw another error or exception
    return "Grade is too high! Highest possible grade is 1.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low! Lowest possible grade is 150.";
}

void Bureaucrat::signAForm(AForm& AForm) {
    try {
        // Намагаємось підписати форму. 
        // Якщо ранг малий, beSigned() викине AForm::GradeTooLowException
        AForm.beSigned(*this); 
        
        // Якщо виняток не викинуто — виводимо успіх
        std::cout << this->_name << " signed " << AForm.getName() << std::endl;
    }
    catch (const std::exception& e) {
        // Якщо зловили помилку — виводимо причину (e.what())
        std::cout << this->_name << " couldn't sign " << AForm.getName() 
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) const {
    try {
        // Викликаємо метод execute самої форми, передаючи поточного бюрократа (*this)
        form.execute(*this);
        
        // Якщо виняток не вилетів — виводимо успішний лог за умовою завдання
        std::cout << this->_name << " executed " << form.getName() << std::endl;
    } 
    catch (const std::exception& e) {
        // Якщо зловили виняток (не підписано або занизький ранг) — виводимо помилку
        std::cout << this->_name << " couldn't execute " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}



// Перевантаження оператора виводу <<
std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return out;
}