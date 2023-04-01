//
// Created by achref on 28/03/2023.
//

#ifndef MYSTL_VECTOR_H
#define MYSTL_VECTOR_H

#include "cstring"
#include "../util.h"

namespace mySTL {

    template<typename T>
    class Vector {
    private:
        T *m_data = nullptr;    //< A block of allocated data.
        size_t m_capacity = 4;  //< The actual capacity of the vector.
        size_t m_size = 0;      //< Number of items in the vector.

    public:
        /**
         * @brief constructor with no arguments
         */
        Vector() {
            ReAlloc(2);
        }

        /**
         * @brief Adds new elemnt at the end.
         * @param element an lvalue const reference.
         */
        void push_back(const T &element) {
            if (m_size >= m_capacity)
                ReAlloc(m_capacity + m_capacity / 2);

            m_data[m_size] = element; // note that this will call the copy assingnment operator of T
            m_size++;
        }

        /**
         * @brief Adds new element at the end of the vector.
         * @param element an rvalue reference.
         */
        void push_back(T &&element) {
            if (m_size >= m_capacity)
                ReAlloc(m_capacity + m_capacity / 2);

            m_data[m_size] = std::move(element);
            m_size++;
        }

        __attribute__((unused)) void emplace_back() {};

        /**
         * @brief Remove last element.
         */
        void pop_back() {
            if (m_size >= 0) {
                m_data[m_size - 1].~T(); // free the memory by explicitly calling the destructor of T
                m_size--;
            }
        }

        /**
         * @brief Remove all the elements from the vector, leaving it with a size of 0.
         * The memory previously occupied by the elements will be freed, but the capacity
         * of the vector will remain unchanged.
         */
        void clear() {
            for (size_t i = 0; i < m_size; i++) {
                m_data[i].~T();
                // to solve the problem presented in `~Vector()`
                //m_data[i] = nullptr; //this will re-create a T object!!!
            }
            m_size = 0;
        }

        /**
         * Return a const reference of element at index.
         * @param index index of the elemnt
         * @return [index]
         */
        const T &operator[](size_t index) const {
            if (index < m_size) {
                return m_data[index];
            }
            throw;
        }

        size_t size() {
            return m_size;
        }

        // Destructor
        virtual ~Vector() {
#if 0
            /**
             * @brief delete the used memory
             *
             * @bug if we `clear()` all elements, `delete[] m_data` will call the destructor of each T
             * which will delete an already de-allocated memory.
             * This often happens when we call the destructors explicitly like in `pop_back()` and `clear()`.
             */
            delete[] m_data;
#endif
#if 1
            /**
             * @brief Manually deleting vector's items.
             */
            clear();
            /**
             * @brief Delete m_data without calling the destructor of each element.
            */
            ::operator delete(m_data, (void *) (m_capacity * sizeof(T)));
#endif
        };

    private:
/*        void allocate_copy(){
            m_capacity *= 2;

            T* tmp_data = new T[m_capacity];
            // copying
            // we actually need to hit the copy/move constructor of the data T
            // so we wont use memcpy()
            //memcpy(tmp_data, m_data, m_size); wont work with integer (for some reasons)
            //memcpy(tmp_data[i, m_data[i], m_size); //!!!
            for(size_t i =0; i < m_size; i++){
                tmp_data[i] = m_data[i]; // call copy assignment operator of datatype T
            }
            delete[] m_data; // delete old allocated resource to avoid any memory leak.
            m_data = tmp_data; // now m_data is pointing to the newly allocated data
            tmp_data = nullptr; // create hollow object, so delete[] tmp_data wont delete anything.
        }*/

        // Reallocate memory for more space
        void ReAlloc(size_t newCapacity) {
            LOG("ReAlloc", newCapacity);
#if 0
            /**
             * @note T constructor will be called m_capacity times in order to create m_data
             * @bug De-Allocating memory explicitly by calling the destructor can cause problems
             * (see ~Vector() for more details)
             */
            T *newBlockOfData = new T[newCapacity];
#endif
#if 1
            /**
             * @brief we are using versions of new and delete that do not call the constructor or the
             * destructor.
             *
             * @note this version doesn't call the constructor of T
             */
            T *newBlockOfData = (T *) ::operator new(newCapacity * sizeof(T));
#endif
            //copying
            for (size_t i = 0; i < m_size; i++) {
                newBlockOfData[i] = std::move(m_data[i]); // will call move assignment operator
            }
#if 0
            /**
             * @bug De-Allocating memory explicitly by calling the destructor can cause problems
             * (see ~Vector() member function for more details)
             */
            delete[] m_data;   // Free the previous allocated block of memory
#endif

#if 1
            for (size_t i = 0; i < m_size; i++)
                m_data[i].~T(); // call the destructor of each element.

            /**
             * @brief Delete m_data without calling the destructor of each element.
             */
            ::operator delete(m_data, (void *) (m_capacity * sizeof(T)));
#endif
            m_data = newBlockOfData;
            newBlockOfData = nullptr; // So delete on newBlockOfData won't free anything

            m_capacity = newCapacity;
        }
    };

} // End namespace mySTL
#endif //MYSTL_VECTOR_H
