Ласкаво просимо до **CPP Module 08**! Як зазначено в загальних правилах модуля, тепер твій головний фокус — це активне та правильне використання **STL (Standard Template Library)**, зокрема контейнерів та алгоритмів.

Вправа **ex00 (Easy find)** — це ідеальний старт для знайомства з алгоритмами STL, а саме з функцією `std::find`.

Нижче детальний переклад завдання, теорія, яка тобі знадобиться, та готова C++98-сумісна реалізація.

---

## 🇺🇦 Переклад завдання

### Вправа 00: Простий пошук (Easy find)

* **Каталог для здачі:** `ex00/`
* **Файли для здачі:** `Makefile`, `main.cpp`, `easyfind.{h, hpp}` (та необов'язковий `easyfind.tpp`)
* **Заборонено:** Немає

Напиши шаблон функції `easyfind`, який приймає тип `T`. Функція приймає два параметри:

1. Перший параметр має тип `T` (контейнер).
2. Другий параметр є цілим числом (`int`).

Припускаючи, що `T` — це контейнер цілих чисел (наприклад, `std::vector<int>`, `std::list<int>` тощо), ця функція повинна знайти **перше входження** другого параметра (числа) у першому параметрі (контейнері).

Якщо елемент не знайдено, ти можеш або викинути виняток (exception), або повернути помилку на свій вибір. Якщо тобі потрібне натхнення — подивись, як поводяться стандартні контейнери.

*Тобі не потрібно обробляти асоціативні контейнери (такі як `std::map`, `std::set` тощо).*

Звичайно ж, напиши та здай власні тести у `main.cpp`, щоб переконатися, що все працює правильно.

---

## 📚 Теорія, яка знадобиться для захисту

### 1. Що таке контейнери та ітератори в STL?

Контейнери (як-от `std::vector` або `std::list`) зберігають дані. Для навігації по цих даних використовуються **ітератори** (`iterator`). Ітератори працюють як розумні вказівники:

* `container.begin()` — повертає ітератор на перший елемент.
* `container.end()` — повертає ітератор на елемент, що йде **після** останнього (це маркер кінця контейнера).

### 2. Алгоритм `std::find`

У бібліотеці `<algorithm>` є готова функція `std::find`, яка ідеально підходить для цього завдання. Вона приймає:

1. Початок діапазону пошуку (`container.begin()`).
2. Кінець діапазону пошуку (`container.end()`).
3. Значення, яке треба знайти.

```cpp
std::find(container.begin(), container.end(), value);

```

* **Якщо елемент знайдено:** функція повертає ітератор, який вказує на цей елемент.
* **Якщо елемент НЕ знайдено:** функція повертає ітератор, рівний `container.end()`.

### 3. Обробка помилки (Винятки)

Оскільки стандартні алгоритми сигналізують про невдачу поверненням `end()`, найкращим рішенням для нашої функції `easyfind` буде **викинути виняток** типу `std::runtime_error` або створити свій власний клас винятку, якщо елемент не знайдено. Це набагато безпечніше, ніж повертати якісь "магічні" числа.

---

## 🛠️ Реалізація коду

### 1. `easyfind.hpp`

Реалізація нашого шаблону. Оскільки ми працюємо з контейнером, ми передаємо його за константним посиланням `const T&`, щоб уникнути зайвого копіювання. Відповідно, використовувати будемо константні ітератори (`const_iterator`).

```cpp
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm> // Для std::find
#include <exception> // Для std::exception
#include <stdexcept> // Для std::runtime_error

// Створюємо власний простий виняток для випадку, коли елемент не знайдено
class ElementNotFoundException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Error: Element not found in the container!";
    }
};

// Шаблон функції easyfind
// T - тип контейнера (наприклад, std::vector<int>)
template <typename T>
typename T::const_iterator easyfind(const T& container, int to_find) {
    // Шукаємо елемент за допомогою STL алгоритму std::find
    typename T::const_iterator it = std::find(container.begin(), container.end(), to_find);

    // Якщо std::find дійшов до кінця і нічого не знайшов
    if (it == container.end()) {
        throw ElementNotFoundException();
    }

    // Повертаємо ітератор на знайдений елемент
    return it;
}

#endif

```

> 💡 **Чому перед `T::const_iterator` стоїть слово `typename`?** > Компілятор на етапі аналізу шаблону ще не знає, чим буде `T`. Слово `typename` підказує йому, що `T::const_iterator` — це саме тип даних (type), а не статична змінна чи функція всередині класу `T`. Без `typename` код не скомпілюється.

---

### 2. `main.cpp`

У тестах ми перевіримо роботу нашої функції з двома різними контейнерами: динамічним масивом `std::vector` та двонаправленим списком `std::list`.

```cpp
#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    // --- Тест 1: Робота з std::vector ---
    std::cout << "=== Тест 1: Пошук у std::vector ===" << std::endl;
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(42);
    vec.push_back(50);

    try {
        std::cout << "Шукаємо число 42..." << std::endl;
        std::vector<int>::const_iterator it = ::easyfind(vec, 42);
        std::cout << "Знайдено! Значення: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << "\nШукаємо число 99 (якого немає)..." << std::endl;
        std::vector<int>::const_iterator it = ::easyfind(vec, 99);
        std::cout << "Знайдено! Значення: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Зловлено виняток: " << e.what() << std::endl;
    }


    // --- Тест 2: Робота з std::list ---
    std::cout << "\n=== Тест 2: Пошук у std::list ===" << std::endl;
    std::list<int> lst;
    lst.push_back(100);
    lst.push_back(200);
    lst.push_back(300);

    try {
        std::cout << "Шукаємо число 200..." << std::endl;
        std::list<int>::const_iterator it = ::easyfind(lst, 200);
        std::cout << "Знайдено! Значення: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << "\nШукаємо число 500 (якого немає)..." << std::endl;
        std::list<int>::const_iterator it = ::easyfind(lst, 500);
        std::cout << "Знайдено! Значення: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Зловлено виняток: " << e.what() << std::endl;
    }

    return 0;
}

```

---

### 3. `Makefile`

```makefile
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
TARGET   = program

SRC      = main.cpp
HEADERS  = easyfind.hpp

all: $(TARGET)

$(TARGET): $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	@echo "Очищення..."

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re

```