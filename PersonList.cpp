#include "PersonList.h"
#include <cstring>

void deletePersonArray(Person** personList, const int noe);

PersonList::PersonList(){
    this->noe = 0;
    this->personList = nullptr;
}
PersonList::PersonList(const std::initializer_list<const Person> &personList) {
    this->noe = 0;

    for(int i = 0; i < (int) personList.size(); i++){
        this->copyMemory(1);
        this->personList[i] = new Person(*(personList.begin() + i));
        this->noe += 1;
    }
}
PersonList::~PersonList(){
    deletePersonArray(this->personList, this->noe);
}
PersonList::PersonList(const PersonList &p){

    this->noe = p.noe;
    this->personList = new Person*[p.noe];

    for(int i = 0; i < p.noe; i++){
        this->personList[i] = new Person(*(p.personList[i]));
    }
}

void PersonList::add(const Person &p){
    this->copyMemory(1);

    this->personList[this->noe] = new Person(p);
    this->noe += 1;
}
void PersonList::removeAt(int index){
    if(!inRange(index)) return;
    if(this->noe == 1){
        delete this->personList[this->noe - 1];
        delete [] this->personList;
        this->noe = 0;
        return;
    }

    for(int i = index; i < this->noe - 1; i++){
        delete this->personList[i];
        this->personList[i] = new Person(*(this->personList[i + 1]));
    }
    delete this->personList[this->noe - 1];
    this->noe -= 1;
    this->copyMemory();
}

Person* PersonList::getPersonbyIndex(int index) const{
    if(!this->inRange(index)) return NULL;
    return new Person(*(this->personList[index]));
}
PersonList PersonList::getPersonListFromWithZIP(const char* fromStr) const{

    PersonList temp;
    for(int i = 0; i < this->noe; i++){
        if(strcmp(this->personList[i]->getAddress().getZip(), fromStr) >= 0){
            temp.add(*(this->personList[i]));
        }
    }
    return temp;
}
void PersonList::show() const {

    std::cout << "PersonList: [\n";
    for(int i = 0; i < this->noe; i++){
        std::cout << i << " ";
        this->personList[i]->show();
        if(i != this->noe - 1) std::cout << ",";
        std::cout << "\n";
    }
    std::cout << "]";
}

void PersonList::copyMemory(int addValue){
    if(!this->noe){
        this->personList = new Person*[1];
        return;
    }
    Person* *temp = new Person*[this->noe + addValue];

    for(int i = 0; i < this->noe; i++){
        temp[i] = new Person(*(this->personList[i]));
    }

    deletePersonArray(this->personList, this->noe);

    this->personList = temp;
}

void deletePersonArray(Person** personList, const int noe) {
    for(int i = 0; i < noe; i++){
        delete personList[i];
    }
    delete [] personList;
}
bool PersonList::inRange(int index) const{
    return !(index < 0 || index > this->noe - 1);
}
