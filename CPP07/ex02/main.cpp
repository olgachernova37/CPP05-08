#include <iostream>
#include <string>
#include "Array.hpp"

int main() {
    std::cout << "=== Тест 1: Створення пустих масивів ===" << std::endl;
    Array<int> emptyArr;
    std::cout << "Розмір пустого масиву: " << emptyArr.size() << std::endl;

    std::cout << "\n=== Тест 2: Створення масиву з ініціалізацією нулями ===" << std::endl;
    Array<int> intArr(5);
    std::cout << "Розмір intArr: " << intArr.size() << std::endl;
    std::cout << "Значення елементів (мають бути 0): ";
    for (unsigned int i = 0; i < intArr.size(); i++) {
        std::cout << intArr[i] << " ";
    }
    std::cout << std::endl;

    // Заповнюємо масив значеннями
    for (unsigned int i = 0; i < intArr.size(); i++) {
        intArr[i] = i * 10;
    }
    std::cout << "Нові значення intArr: ";
    for (unsigned int i = 0; i < intArr.size(); i++) {
        std::cout << intArr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "\n=== Тест 3: Глибоке копіювання ===" << std::endl;
    Array<int> copyArr(intArr); // Конструктор копіювання
    std::cout << "Значення copyArr: ";
    for (unsigned int i = 0; i < copyArr.size(); i++) {
        std::cout << copyArr[i] << " ";
    }
    std::cout << std::endl;

    // Змінюємо копію і перевіряємо, що оригінал не змінився
    copyArr[0] = 999;
    std::cout << "Після зміни copyArr[0] на 999:" << std::endl;
    std::cout << "intArr[0] (оригінал):  " << intArr[0] << " (має залишитися 0)" << std::endl;
    std::cout << "copyArr[0] (копія):    " << copyArr[0] << " (має стати 999)" << std::endl;

    std::cout << "\n=== Тест 4: Вихід за межі масиву (Exception) ===" << std::endl;
    try {
        std::cout << "Спроба звернутися до елементу з індексом 10 у масиві розміром 5..." << std::endl;
        intArr[10] = 42;
    } catch (const std::exception& e) {
        std::cout << "Зловлено виняток: " << e.what() << std::endl;
    }

    try {
        std::cout << "Спроба звернутися до від'ємного індексу..." << std::endl;
        // Оскільки параметр unsigned int, передача -1 перетвориться на гігантське число, 
        // що також призведе до out_of_range.
        intArr[-1] = 42;
    } catch (const std::exception& e) {
        std::cout << "Зловлено виняток: " << e.what() << std::endl;
    }

    std::cout << "\n=== Тест 5: Масив об'єктів складних типів (std::string) ===" << std::endl;
    Array<std::string> strArr(3);
    strArr[0] = "School";
    strArr[1] = "42";
    strArr[2] = "Kyiv";
    for (unsigned int i = 0; i < strArr.size(); i++) {
        std::cout << strArr[i] << " ";
    }
    std::cout << "\n\n=== Всі тести завершено успішно! ===" << std::endl;

    return 0;
}