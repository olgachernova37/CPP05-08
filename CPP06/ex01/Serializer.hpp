

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h> // uintptr_t у C++98 часто береться з <stdint.h> або <cstdint>
#include "Data.hpp"

class Serializer {
private:
    // Приватні конструктори та деструктор унеможливлюють створення об'єкта
    Serializer();
    Serializer(const Serializer& src);
    Serializer& operator=(const Serializer& rhs);
    ~Serializer();

public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif