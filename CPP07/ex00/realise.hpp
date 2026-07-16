#ifndef REALISE_HPP
#define REALISE_HPP

#include <ostream>
#include <string>

// Шаблон функції swap
template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// Шаблон функції min
// Якщо a і b рівні, має повернутися b (другий аргумент).
// Тому ми повертаємо a тільки тоді, коли a строго менше за b (a < b).
// Якщо a >= b (зокрема коли вони рівні), повертається b.
template <typename T>
const T& min(const T& a, const T& b) {
    return (a < b) ? a : b;
}

// Шаблон функції max
// Якщо a і b рівні, має повернутися b (другий аргумент).
// Тому ми повертаємо a тільки тоді, коли a строго більше за b (a > b).
// Якщо a <= b (зокрема коли вони рівні), повертається b.
template <typename T>
const T& max(const T& a, const T& b) {
    return (a > b) ? a : b;
}

#endif