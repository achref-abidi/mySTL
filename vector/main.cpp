#include <iostream>
#include "Vector.h"
#include "../simple_string/Simple_String.h"
#include "string"

void TestPushandPop();
void TestmyStringVector();
void TestAllocationWithInteger();
void TestAllocationWithString();
void TestAllocationWithSimpleString();
void TestDestructorOfPointers();
void TestClear();

int main(){

    //TestmyStringVector();
    //TestAllocationWithString();
    //TestAllocationWithInteger();
    //TestmyStringVector();
    //TestPushandPop();
    TestClear();

    return 0;
}

void TestPushandPop()
{
    mySTL::Vector<mySTL::Simple_String> stringVector;

    stringVector.push_back("hello1");
    stringVector.push_back("hello2");

    std::cout << "Size of vector : " << stringVector.size() << std::endl;

    for(int i = stringVector.size() -1; i >= 0 ; i--){
        stringVector.pop_back();
    }
    std::cout << "Size of vector : " << stringVector.size() << std::endl;
}

void TestAllocationWithInteger(){
    mySTL::Vector<int> vect;
    for(int i = 0; i < 20; i++){
        vect.push_back(i * 2);
    }

    for(int i = 0; i < vect.size(); i++){
        std::cout << "Vect[" << i << "] = " << vect[i] << std::endl;
    }
}

void TestAllocationWithString(){
    mySTL::Vector<std::string> stringVector;

    stringVector.push_back("hello1");
    stringVector.push_back("hello2");
    stringVector.push_back("hello3");
    stringVector.push_back("hello4");
    stringVector.push_back("hello5");
    stringVector.push_back("hello6");

    for(size_t i = 0; i < stringVector.size(); i++)
        std::cout << "Vect[" << i << "] = " << stringVector[i] << std::endl;
}

void TestmyStringVector(){
    mySTL::Vector<mySTL::Simple_String> stringVector;

    stringVector.push_back("hello1");
    stringVector.push_back("hello2");
    stringVector.push_back("hello3");
    stringVector.push_back("hello4");
    stringVector.push_back("hello5");
    stringVector.push_back("hello6");

    for(size_t i = 0; i < stringVector.size(); i++) {
        std::cout << "Vect[" << i << "] = " << stringVector[i] << std::endl;
    }
}

void TestClear(){
    mySTL::Vector<mySTL::Simple_String> stringVector;

    stringVector.push_back("hello1");
    stringVector.push_back("hello2");

    std::cout << "Size of vector : " << stringVector.size() << std::endl;

    stringVector.clear();

    std::cout << "Size of vector : " << stringVector.size() << std::endl;
}