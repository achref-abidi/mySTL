//
// Created by achref on 28/03/2023.
//

#ifndef MYSTL_SIMPLE_STRING_H
#define MYSTL_SIMPLE_STRING_H

namespace mySTL{
    class Simple_String {
    public:
        // default constructor
        Simple_String(){
            std::cout << "Called Simple_String()" << std::endl;
        }


         // constructor for creating Simple_String
        Simple_String (const char * someString){
            std::cout << "Creating String" << std::endl;
            m_size = strlen(someString);
            // allocating data
            m_data = new char [m_size];
            // coping someString content
            memcpy(m_data, someString, m_size);
        }

        // copy constructor
        Simple_String(const Simple_String & other){
            std::cout << "Copied!\n";
            m_size = other.m_size;
            // coping
            memcpy(m_data, other.m_data, m_size );
        }

        // move constructor that takes an rvalue
        // transfer ownership in some sens
        Simple_String(Simple_String && other) noexcept {
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
        Simple_String & operator= (const Simple_String & rhs){
            std::cout << "Copy Assignment!\n";
            delete [] m_data; // to prevent any data leak

            m_size = rhs.m_size;
            m_data = new char[m_size];
            // coping
            memcpy(m_data, rhs.m_data, m_size );

            return *this;
        }

        //move assingment
        Simple_String & operator=(Simple_String && rhs){
            std::cout << "Move assignment!\n";
            return *this;
        }

        ~Simple_String(){
            delete [] m_data;
            std::cout << "Destroyed!\n";
        }

    private:
        char * m_data;
        size_t m_size;
    };
}
#endif //MYSTL_SIMPLE_STRING_H
