#ifndef BASE_HPP
#define BASE_HPP

class Base {
public:
    // Віртуальний деструктор робить клас поліморфним.
    // Це критично важливо для роботи dynamic_cast!
    virtual ~Base() {}
};

#endif