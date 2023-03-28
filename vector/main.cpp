#include <iostream>
#include "Vector.h"
#include "../simple_string/Simple_String.h"
#include "string"

int main(){

/*    mySTL::Vector<int> vect;

    for(int i=0; i< 5; i++){
        vect.push_back(i * 2);
    }

    std::cout << "Size of vector : " << vect.size() << std::endl;

    for(int i = vect.size() -1; i >= 0 ; i--){
        std::cout << "Element [" << i << "] = " << vect.pop_back() << std::endl;
    }

    std::cout << "Size of vector : " << vect.size() << std::endl;

    // testing the allocate_copy()
    for(int i = 0; i < 20; i++){
        vect.push_back(i * 2);
    }

    for(int i = 0; i < vect.size(); i++){
        std::cout << "Vect[" << i << "] = " << vect[i] << std::endl;
    }*/

    mySTL::Vector<std::string> stringVector;
    // testing the allocate_copy()
    stringVector.push_back("hello");

    // set m_capacity of the Vector class to 1
    // the see what you get
    stringVector.push_back("hello");
    // this will call push_back(T&&), std::move() to force this call

    /*for(int i = 0; i < 20; i++){
        stringVector.push_back(mySTL::Simple_String("hello"));

    }*/

    std::cin.get();

    for(size_t i = 0; i < stringVector.size(); i++){
        std::cout << "Vect[" << i << "] = " ;
        //stringVector[i].print();
        std::cout << std::endl;
    }


    return 0;
}