#include "Base.hpp"
#include "identify.hpp"
#include <iostream>
#include <ctime>   // Для time(NULL)
#include <cstdlib> // Для srand()

int main() {
    // Ініціалізуємо генератор випадкових чисел поточним часом
    std::srand(std::time(NULL));

    std::cout << "=== Запуск тестів ===" << std::endl;

    for (int i = 0; i < 5; i++) {
        std::cout << "\n--- Тест #" << i + 1 << " ---" << std::endl;

        // 1. Генеруємо випадковий об'єкт
        Base* instance = generate();

        // 2. Тестуємо ідентифікацію через вказівник
        std::cout << "Ідентифікація через вказівник (*):  ";
        identify(instance);

        // 3. Тестуємо ідентифікацію через посилання
        std::cout << "Ідентифікація через посилання (&):  ";
        identify(*instance);

        // 4. Очищуємо пам'ять! (Оскільки деструктор Base віртуальний,
        // видалення через Base* викличе також деструктор правильного підкласу)
        delete instance;
    }

    std::cout << "\n=====================" << std::endl;
    return 0;
}