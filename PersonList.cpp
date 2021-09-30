#include "PersonList.h"
#include <cstring>

PersonList::PersonList(){
    this->noe = 0;
    this->personList = nullptr;
}
PersonList::PersonList(std::initializer_list<Person> personList, int noe) {

    this->noe = 0;

    for(int i = 0; i < noe; i++){
        this->addMemory();
        this->personList[i] = new Person(*(personList.begin() + i));
        this->noe += 1;
    }
}
PersonList::~PersonList(){
    for(int i = 0; i < this->noe; i++){
        delete this->personList[i];
    }
    delete [] this->personList;
}
PersonList::PersonList(const PersonList &p){

    this->noe = p.noe;
    this->personList = new Person*[p.noe];

    for(int i = 0; i < p.noe; i++){
        this->personList[i] = new Person(*(p.personList[i]));
    }
}

void PersonList::add(const Person &p){
    this->addMemory();

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

    this->noe -= 1;

    Person* *temp = new Person*[this->noe];
    for(int i = 0; i < this->noe; i++){
        temp[i] = new Person(*(this->personList[i]));
    }

    for(int i = 0; i < this->noe + 1; i++){
        delete this->personList[i];
    }
    delete [] this->personList;

    this->personList = new Person*[this->noe];
    for(int i = 0; i < this->noe; i++){
        this->personList[i] = new Person(*temp[i]);
    }

    for(int i = 0; i < this->noe; i++){
        delete temp[i];
    }
    delete [] temp;
}

Person* PersonList::getPersonbyIndex(int index) const{
    if(!this->inRange(index)) return NULL;
    return new Person(*(this->personList[index]));
}
/*Person***/PersonList PersonList::getPersonListFromWithZIP(const char* fromStr, const char* toStr) const{


    PersonList temp;
    for(int i = 0; i < this->noe; i++){
        if(strcmp(this->personList[i]->getAddress().getZip(), fromStr) >= 0 && strcmp(this->personList[i]->getAddress().getZip(), toStr) <= 0){
            temp.add(*(this->personList[i]));
        }
    }
    return temp;
    /*
    Person* *retVal = new Person*[temp.noe];
    for(int i = 0; i < temp.noe; i++){
        retVal[i] = new Person(*(temp.personList[i]));
    }

    return retVal;
    */
}
void PersonList::show() const {

    std::cout << "[\n";
    for(int i = 0; i < this->noe; i++){
        std::cout << i << " ";
        this->personList[i]->show();
        std::cout << "\n";
    }
    std::cout << "]";
}
void PersonList::addMemory(){
    if(!this->noe){
        this->personList = new Person*[1];
        return;
    }
    Person* *temp = new Person*[this->noe];
    for(int i = 0; i < this->noe; i++){
        temp[i] = new Person(*(this->personList[i]));
    }

    for(int i = 0; i < this->noe; i++){
        delete this->personList[i];
    }
    delete [] this->personList;

    this->personList = new Person*[this->noe + 1];
    for(int i = 0; i < this->noe; i++){
        this->personList[i] = new Person(*temp[i]);
    }

    for(int i = 0; i < this->noe; i++){
        delete temp[i];
    }
    delete [] temp;
}
bool PersonList::inRange(int index) const{

    return !(index < 0 || index > this->noe - 1);
}
