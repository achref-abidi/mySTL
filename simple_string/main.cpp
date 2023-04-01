#include <iostream>
#include <cstring>

#include "Simple_String.h"

typedef mySTL::Simple_String string;

/**
 * @brief Entity class will just consume Simple_String.
 */
class Entity{
public:
    Entity(const string & name)
    : m_name(name) // this will copy the Simple_String
    {
       // m_name = name; // this is an assignment
        // it will call
        // 1. default constructor to create `m_name`
        // 2. copy assignment operator
    }

    Entity(string && name)
    : m_name(std::move(name))
    {
    }

    void PrintString(){
        m_name.print();
    }

    ~Entity() = default;

private:
    string m_name;
};

class testPointer{

public:
    int * i;
    testPointer(){
        std::cout << "Created!" << std::endl;
        i = new int(10);
    }

    ~testPointer(){
        std::cout << "destroyed!" << std::endl;
        delete i;
    }

    void print(){
        std::cout << *i << std::endl;
    };
};

void PassPointer(testPointer * p){
    std::cout << *p->i << std::endl;
}

int main() {

   /* Entity entity(Simple_String("Achref"));
    entity.PrintString();

    int b = 5;
    const int a = b;*/

    {
        testPointer * ptr = new testPointer();
        ptr->print();
        delete ptr;

        PassPointer(ptr);
    }
    //delete ptr; // out of scope
    std::cout << "Hello!" << std::endl;


    std::cin.get();
    return 0;
}
