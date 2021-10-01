#pragma once
#include "Person.h"
#include <iostream>
#include <initializer_list>

class PersonList {

public:
    PersonList();
    PersonList(const std::initializer_list<const Person> &personList);
    ~PersonList();
    PersonList(const PersonList &p);

    void add(const Person &p);
    void removeAt(int index);

    Person* getPersonbyIndex(int index) const;
    PersonList getPersonListFromWithZIP(const char* fromStr) const;

    void show() const;
private:
    Person* *personList;
    int noe;

    void copyMemory(int addValue = 0);
    bool inRange(int index) const;
};
