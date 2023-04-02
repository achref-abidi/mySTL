//
// Created by achref on 28/03/2023.
//

#ifndef MYSTL_SIMPLE_STRING_H
#define MYSTL_SIMPLE_STRING_H

#include <cstring>
#include <iostream>
#include "../util.h"

namespace mySTL{
    class Simple_String {
    public:

        Simple_String(){
            LOG_TRACE("default");
            // The reason that we have a default constructor is that if we
            // initialize a block of Simple_String it will call this constructor
        }
         // constructor for creating Simple_String
        Simple_String (const char * someString){
             LOG_TRACE(someString);

            m_size = strlen(someString) + 1;// +1 for the null character
            // allocating data
            m_data = new char [m_size];
            // coping someString content
            memcpy(m_data, someString, m_size);
        }

        // copy constructor
        Simple_String(const Simple_String & other){
            LOG("Copied", other);

            m_size = other.m_size;
            // coping
            memcpy(m_data, other.m_data, m_size );
        }

        // move constructor that takes an rvalue
        // transfer ownership in some sens
        Simple_String(Simple_String && other) noexcept {
            LOG("Moved", other);

            if(this != &other) {
                m_size = other.m_size;

                delete [] m_data;
                m_data = other.m_data;

                //delete [] other.m_data;// NO!! we intent to steal it
                // creating hollow object, so the original owner won't be able to delete it
                other.m_data = nullptr;
                other.m_size = 0;
            }
        }

        void print() const{
            std::cout << m_data << std::endl;
        }

        //copy assingment operator
        Simple_String & operator= (const Simple_String & rhs){
            LOG("Copy Assignment", rhs);

            delete [] m_data; // to prevent any data leak

            m_size = rhs.m_size;
            m_data = new char[m_size];
            // coping
            memcpy(m_data, rhs.m_data, m_size );

            return *this;
        }

        //move assingment
        Simple_String & operator=(Simple_String && rhs){
            LOG("Move assignment", rhs);

            delete [] m_data;

            m_size = rhs.m_size;
            m_data = rhs.m_data;

            rhs.m_data = nullptr;
            rhs.m_size = 0;

            return *this;
        }

        ~Simple_String(){
            // if we don't do this check of whever m_data == nullptr or not
            // the behavior of std::cout became unpredictable..
            // see https://stackoverflow.com/questions/7019454/why-does-stdcout-output-disappear-completely-after-null-is-sent-to-it
            // or replace the following with LOG("~Simple_String()", m_data);
            LOG("~Simple_String()", (m_data == nullptr ? "nullptr" : m_data));
            delete [] m_data;
            m_data = nullptr;
        }

        friend std::ostream& operator<<(std::ostream& os, const Simple_String& str){
            os << str.m_data;
            return os;
        }

    private:
        char * m_data;
        size_t m_size;
    };
}
#endif //MYSTL_SIMPLE_STRING_H
