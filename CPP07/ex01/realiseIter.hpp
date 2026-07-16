#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef> // Для size_t

// Шаблон функції iter
// T - тип елементів масиву
// F - тип функції, що викликається для кожного елемента
template <typename T, typename F>
void iter(T* array, size_t length, F f) {
    if (array == NULL || f == NULL) {
        return;
    }
    for (size_t i = 0; i < length; ++i) {
        f(array[i]); // Викликаємо функцію f для i-го елемента масиву
    }
}

#endif