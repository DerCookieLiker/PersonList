#pragma once
#include <iostream>

class Address {
public:
    Address(const char* city, const char* zip, const char* street, const int number);
    ~Address();
    Address(const Address &a);

    void setCity(const char* city);
    void setZip(const char* zip);
    void setStreet(const char* street);
    void setNumber(int number);

    const char* getCity() const;
    const char* getZip() const;
    const char* getStreet() const;
    int getNumber() const;

    void show() const;

    Address& operator=(const Address& that);
    friend std::ostream& operator<<(std::ostream& os, const Address& that);
private:
    char* city;
    char* zip;
    char* street;
    int number;

    char* createMemory(const char* str) const;
};
