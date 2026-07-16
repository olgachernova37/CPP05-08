#include "identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib> // Для rand() та srand()
#include <exception> // Для std::exception

// Функція випадковим чином створює об'єкт A, B або C і повертає його як Base*
Base* generate(void) {
    int randomValue = std::rand() % 3; // Отримуємо 0, 1 або 2

    if (randomValue == 0) {
        std::cout << "[Generator] Створено об'єкт типу A" << std::endl;
        return new A();
    } else if (randomValue == 1) {
        std::cout << "[Generator] Створено об'єкт типу B" << std::endl;
        return new B();
    } else {
        std::cout << "[Generator] Створено об'єкт типу C" << std::endl;
        return new C();
    }
}

// Ідентифікація через ВКАЗІВНИК (Base*)
void identify(Base* p) {
    if (p == NULL) {
        std::cout << "Вказівник NULL" << std::endl;
        return;
    }

    // dynamic_cast з вказівниками повертає NULL, якщо приведення типів неуспішне.
    // Ми просто перевіряємо кожен варіант по черзі.
    if (dynamic_cast<A*>(p) != NULL) {
        std::cout << "A" << std::endl;
    } 
    else if (dynamic_cast<B*>(p) != NULL) {
        std::cout << "B" << std::endl;
    } 
    else if (dynamic_cast<C*>(p) != NULL) {
        std::cout << "C" << std::endl;
    } 
    else {
        std::cout << "Невідомий тип" << std::endl;
    }
}

// Ідентифікація через ПОСИЛАННЯ (Base&)
void identify(Base& p) {
    // Оскільки посилання не можуть бути NULL, dynamic_cast у разі невдачі
    // кидає виняток std::bad_cast. Ми обробляємо його за допомогою try-catch.
    
    // Спроба 1: Перевіряємо на тип A
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a; // Позбавляємося попередження про невикористану змінну
        std::cout << "A" << std::endl;
        return; // Якщо кастинг успішний, завершуємо функцію
    } catch (const std::exception& e) {
        // Якщо це не A, переходимо до наступної перевірки
    }

    // Спроба 2: Перевіряємо на тип B
    try {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return;
    } catch (const std::exception& e) {
        // Якщо це не B, йдемо далі
    }

    // Спроба 3: Перевіряємо на тип C
    try {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return;
    } catch (const std::exception& e) {
        // Якщо досі не визначили
        std::cout << "Невідомий тип" << std::endl;
    }
}