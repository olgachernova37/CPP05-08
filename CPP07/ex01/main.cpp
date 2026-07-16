#include <iostream>
#include <string>
#include "realiseIter.hpp"

// Тестова функція 1: виводить елемент (приймає за константним посиланням)
template <typename T>
void printElement(const T& element) {
    std::cout << element << " ";
}

// Тестова функція 2: збільшує число на 1 (приймає за неконстантним посиланням)
void increment(int& n) {
    n += 1;
}

int main() {
    // --- Тест 1: Звичайний масив int ---
    std::cout << "=== Тест 1: Масив цілих чисел (int) ===" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLen = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Початковий масив: ";
    ::iter(intArray, intLen, printElement<int>);
    std::cout << std::endl;

    // Модифікуємо елементи за допомогою iter та функції increment
    ::iter(intArray, intLen, increment);

    std::cout << "Після інкременту: ";
    ::iter(intArray, intLen, printElement<int>);
    std::cout << "\n" << std::endl;


    // --- Тест 2: Константний масив рядків (const std::string) ---
    std::cout << "=== Тест 2: Константний масив рядків (const std::string) ===" << std::endl;
    const std::string strArray[] = {"C++", "is", "awesome", "at", "School 42"};
    size_t strLen = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "Елементи масиву: ";
    // Оскільки масив const, printElement автоматично інстанціюється для const std::string
    ::iter(strArray, strLen, printElement<std::string>);
    std::cout << "\n" << std::endl;


    // --- Тест 3: Масив символів (char) ---
    std::cout << "=== Тест 3: Масив символів (char) ===" << std::endl;
    char charArray[] = {'a', 'b', 'c', 'd'};
    size_t charLen = sizeof(charArray) / sizeof(charArray[0]);

    std::cout << "Символи: ";
    ::iter(charArray, charLen, printElement<char>);
    std::cout << std::endl;

    return 0;
}