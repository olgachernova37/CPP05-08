#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <stdexcept>

template <typename T>
class Array {
private:
    T* _elements;
    unsigned int _size;

public:
    // 1. Конструктор за замовчуванням
    Array() : _elements(NULL), _size(0) {}

    // 2. Конструктор з параметром розміру
    Array(unsigned int n) : _size(n) {
        if (n > 0) {
            // Круглі дужки () наприкінці ініціалізують примітивні типи нулями
            _elements = new T[n]();
        } else {
            _elements = NULL;
        }
    }

    // 3. Конструктор копіювання (Глибоке копіювання)
    Array(const Array& src) : _size(src._size) {
        if (_size > 0) {
            _elements = new T[_size];
            for (unsigned int i = 0; i < _size; i++) {
                _elements[i] = src._elements[i];
            }
        } else {
            _elements = NULL;
        }
    }

    // 4. Оператор присвоювання (Глибоке копіювання)
    Array& operator=(const Array& rhs) {
        if (this != &rhs) {
            // Очищаємо стару пам'ять
            delete[] _elements;

            _size = rhs._size;
            if (_size > 0) {
                _elements = new T[_size];
                for (unsigned int i = 0; i < _size; i++) {
                    _elements[i] = rhs._elements[i];
                }
            } else {
                _elements = NULL;
            }
        }
        return *this;
    }

    // 5. Деструктор
    ~Array() {
        delete[] _elements;
    }

    // 6. Оператор [ ] для звичайних (неконстантних) об'єктів
    T& operator[](unsigned int index) {
        if (index >= _size) {
            throw std::out_of_range("Index out of bounds!");
        }
        return _elements[index];
    }

    // 7. Оператор [ ] для константних об'єктів
    const T& operator[](unsigned int index) const {
        if (index >= _size) {
            throw std::out_of_range("Index out of bounds!");
        }
        return _elements[index];
    }

    // 8. Метод size()
    unsigned int size() const {
        return _size;
    }
};

#endif