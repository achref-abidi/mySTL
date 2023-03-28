#include <iostream>
#include <cstring>


class string {
public:
    // default constructor
    string(){
        std::cout << "Called Simple_String()" << std::endl;
    }

    /**
     * @brief constructor for creating Simple_String
     *
     */
    string (const char * someString){
        std::cout << "Creating String" << std::endl;
        m_size = strlen(someString);
        // allocating data
        m_data = new char [m_size];
        // coping someString content
        memcpy(m_data, someString, m_size);
    }

    // copy constructor
    string(const string & other){
        std::cout << "Copied!\n";
        m_size = other.m_size;
        // coping
        memcpy(m_data, other.m_data, m_size );
    }

    // move constructor that takes an rvalue
    // transfer ownership in some sens
    string(string && other) noexcept {
        std::cout << "Moved!\n";
        if(this != &other) {
            m_size = other.m_size;
            // allocating data
            //m_data = new char[m_size];
            // coping someString content
            m_data = other.m_data;

            //delete [] other.m_data;// NO!! we intent to steal it
            other.m_data = nullptr;
            other.m_size = 0; // creating hollow object, so the original owner won't be able to delete it
        }
    }

    void print(){
        std::cout << m_data << std::endl;
    }

    //copy assingment operator
    string &operator= (const string & rhs){
        std::cout << "Assigned!\n";
        return *this;
    }
    ~string(){
        delete [] m_data;
        std::cout << "Destroyed!\n";
    }

private:
    char * m_data;
    size_t m_size;
};

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
