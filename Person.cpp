#include "Person.h"
#include <cstring>

Person::Person(const char* name, const Address &address) : address(address) {

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}
Person::~Person() {
    delete [] this->name;
}
Person::Person(const Person &p) : address(p.address){

    this->name = new char[strlen(p.name) + 1];
    strcpy(this->name, p.name);
}

void Person::setName(const char* name){
    delete [] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}
void Person::setAddress(const Address &a){
    this->address = a;
}

const char* Person::getName() const{
    return this->name;
}
Address Person::getAddress() const{
    return this->address;
}

void Person::show() const {
    std::cout << "Person { \n   name: " << this->name << "\n   ";
    this->address.show();
    std::cout << "\n}";
}
Person& Person::operator=(const Person& that){
    if(this == &that) return *this;
    delete [] this->name;

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    this->address = that.address;

    return *this;
}
std::ostream& operator<<(std::ostream& os, const Person& that){
    os << "Person { \n   name: " << that.name << "\n   " << that.address << "\n}";
    return os;
}
