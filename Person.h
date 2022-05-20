#pragma once
#include "Address.h"
#include <iostream>

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
    Person& operator=(const Person& that);
    friend std::ostream& operator<<(std::ostream& os, const Person& that);
private:
    char* name;
    Address address;
};
