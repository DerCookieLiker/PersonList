#pragma once
#include "Person.h"
#include <iostream>
#include <initializer_list>

class PersonList {

public:
    PersonList();
    PersonList(std::initializer_list<Person> personList, int noe);
    ~PersonList();
    PersonList(const PersonList &p);

    void add(const Person &p);
    void removeAt(int index);

    Person* getPersonbyIndex(int index) const;
    /*Person***/PersonList getPersonListFromWithZIP(const char* fromStr, const char* toStr) const;

    void show() const;
private:
    Person* *personList;
    int noe;

    void addMemory();
    bool inRange(int index) const;
};
