#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    // 1. Створюємо та ініціалізуємо об'єкт Data
    Data myData;
    myData.text = "Hello, School 42!";
    myData.number = 42;
    myData.decimal = 3.14159;

    std::cout << "=== Початковий об'єкт ===" << std::endl;
    std::cout << "Адреса об'єкта: " << &myData << std::endl;
    std::cout << "Data.text:      " << myData.text << std::endl;
    std::cout << "Data.number:    " << myData.number << std::endl;
    std::cout << "Data.decimal:   " << myData.decimal << std::endl;
    std::cout << "------------------------------------" << std::endl;

    // 2. Серіалізація (вказівник -> число)
    uintptr_t rawAddress = Serializer::serialize(&myData);
    std::cout << "Результат серіалізації (uintptr_t): " << rawAddress << " (0x" << std::hex << rawAddress << std::dec << ")" << std::endl;
    std::cout << "------------------------------------" << std::endl;

    // 3. Десеріалізація (число -> вказівник)
    Data* ptrDecoded = Serializer::deserialize(rawAddress);

    // 4. Перевірка результатів
    std::cout << "=== Десеріалізований об'єкт ===" << std::endl;
    std::cout << "Отримана адреса: " << ptrDecoded << std::endl;
    std::cout << "Data.text:       " << ptrDecoded->text << std::endl;
    std::cout << "Data.number:     " << ptrDecoded->number << std::endl;
    std::cout << "Data.decimal:    " << ptrDecoded->decimal << std::endl;
    std::cout << "------------------------------------" << std::endl;

    if (ptrDecoded == &myData) {
        std::cout << "✅ УСПІХ: Адреси повністю співпадають!" << std::endl;
    } else {
        std::cout << "❌ ПОМИЛКА: Адреси відрізняються!" << std::endl;
    }

    // Спроба створити об'єкт класу Serializer (розкоментуй для перевірки помилки компіляції):
    // Serializer test; // Повинно видати помилку компіляції (constructor is private)

    return 0;
}