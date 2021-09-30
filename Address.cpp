#include "Address.h"
#include <cstring>
#include <iostream>

Address::Address(const char* city, const char* zip, const char* street, const int number) : number(number){

    this->city = this->createMemory(city);
    strcpy(this->city, city);

    this->zip = this->createMemory(zip);
    strcpy(this->zip, zip);

    this->street = this->createMemory(street);
    strcpy(this->street, street);
}
Address::~Address(){
    delete [] this->city;
    delete [] this->zip;
    delete [] this->street;
}
Address::Address(const Address &a){

    this->city = this->createMemory(a.city);
    strcpy(this->city, a.city);

    this->zip = this->createMemory(a.zip);
    strcpy(this->zip, a.zip);

    this->street = this->createMemory(a.street);
    strcpy(this->street, a.street);

    this->number = a.number;
}
void Address::setCity(const char* city){
    delete [] this->city;
    this->city = this->createMemory(city);
    strcpy(this->city, city);
}
void Address::setZip(const char* zip){
    delete [] this->zip;
    this->zip = this->createMemory(zip);
    strcpy(this->zip, zip);
}
void Address::setStreet(const char* street){
    delete [] this->street;
    this->street = this->createMemory(street);
    strcpy(this->street, street);
}
void Address::setNumber(int number) {
    this->number = this->number;
}

const char* Address::getCity() const{
    return this->city;
}
const char* Address::getZip() const{
    return this->zip;
}
const char* Address::getStreet() const{
    return this->street;
}
int Address::getNumber() const {
    return this->number;
}

char* Address::createMemory(const char* str) const{
    return new char[strlen(str) + 1];
}

void Address::show() const {

    std::cout << "Address: [ city: " << this->city << " | zip: " << this->zip << " | street: " << this->street << " | number: " << this->number << " ]";
}
