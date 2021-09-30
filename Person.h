#pragma once
#include "Address.h"

class Person{
public:
    Person(const char* name = "", const Address &address = Address("", "", "", 0));
    ~Person();
    Person(const Person &p);

    void setName(const char* name);
    void setAddress(const Address &a);

    const char* getName() const;
    Address getAddress() const;

    void show() const;
private:
    char* name;
    Address address;
};
