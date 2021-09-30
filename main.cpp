#include <iostream>
#include "Address.h"
#include "Person.h"
#include "PersonList.h"

using namespace std;

void testPersonListRemoveAt(const PersonList &src, const int index, const PersonList &xpt);
void testPersonListAdd(const PersonList &src, const Person &in, const PersonList &xpt);
void testPersonListGetFromWithZip(const PersonList &src, const char* from, const char* to, const PersonList &xpt);

int main(){

    PersonList src({Person("Max", Address("Tester", "7042", "Testmedia", 42)),
                    Person("Jessy", Address("Tester", "7042", "Testmedia", 43))}, 2);
    Person in("Franz", Address("World", "4200", "Hello", 1));
    PersonList testZip({
                        Person("Test0", Address("Test0", "5000", "Testmedia", 0)),
                        Person("Test1", Address("Test1", "5050", "Testmedia", 1)),
                        Person("Test2", Address("Test2", "6000", "Testmedia", 2)),
                        Person("Test3", Address("Test3", "5999", "Testmedia", 3)),
                        Person("Test4", Address("Test4", "8050", "Testmedia", 4)),
                        Person("Test5", Address("Test5", "6001", "Testmedia", 5)),
                        Person("Test6", Address("Test6", "4999", "Testmedia", 6)),
                       }, 7);
    testPersonListRemoveAt(src, 1, PersonList({Person("Max", Address("Tester", "7042", "Testmedia", 42))}, 1));
    testPersonListRemoveAt(src, 2, src);
    std::cout << std::endl;

    PersonList xpt = src;
    xpt.add(in);

    testPersonListAdd(src, in, xpt);

    std::cout << std::endl;

    testPersonListGetFromWithZip(testZip, "5000", "6000", PersonList({
                        Person("Test0", Address("Test0", "5000", "Testmedia", 0)),
                        Person("Test1", Address("Test1", "5050", "Testmedia", 1)),
                        Person("Test2", Address("Test2", "6000", "Testmedia", 2)),
                        Person("Test3", Address("Test3", "5999", "Testmedia", 3))}, 4));

    testPersonListGetFromWithZip(testZip, "5050", "8050", PersonList({
                        Person("Test1", Address("Test1", "5050", "Testmedia", 1)),
                        Person("Test2", Address("Test2", "6000", "Testmedia", 2)),
                        Person("Test3", Address("Test3", "5999", "Testmedia", 3)),
                        Person("Test4", Address("Test4", "8050", "Testmedia", 4)),
                        Person("Test5", Address("Test5", "6001", "Testmedia", 5))}, 5));
}
void testPersonListRemoveAt(const PersonList &src, const int index, const PersonList &xpt){

    PersonList result = src;
    result.removeAt(index);

    std::cout << "Test RemoveAt" << std::endl;
    src.show();
    std::cout << " Remove at Index " << index;
    std::cout << std::endl << "Result:  " << std::endl;
    result.show();
    std::cout << std::endl << "Expected:" << std::endl;
    xpt.show();
    std::cout << std::endl << "-----------------------------------------------------------------------------" << std::endl;
}
void testPersonListAdd(const PersonList &src, const Person &in, const PersonList &xpt){

    PersonList result = src;
    result.add(in);

    std::cout << "Test Add" << std::endl;
    src.show();
    std::cout << " Add:" << std::endl;
    in.show();
    std::cout << std::endl << "Result:  " << std::endl;
    result.show();
    std::cout << std::endl << "Expected:" << std::endl;
    xpt.show();
    std::cout << std::endl << "-----------------------------------------------------------------------------" << std::endl;
}
void testPersonListGetFromWithZip(const PersonList &src, const char* from, const char* to, const PersonList &xpt){

    PersonList result = src.getPersonListFromWithZIP(from, to);

    std::cout << "Test GetFromWithZip" << std::endl;
    src.show();
    std::cout << " Get PersonList From [ " << from << " ] - TO [ " << to << " ]";
    std::cout << std::endl << "Result:  " << std::endl;
    result.show();
    std::cout << std::endl << "Expected:" << std::endl;
    xpt.show();
    std::cout << std::endl << "-----------------------------------------------------------------------------" << std::endl;

}
