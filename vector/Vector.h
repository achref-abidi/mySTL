//
// Created by achref on 28/03/2023.
//

#ifndef MYSTL_VECTOR_H
#define MYSTL_VECTOR_H

namespace mySTL {

    template<typename T>
    class Vector {
    public:
         // constructor with no arguments
         Vector(){
             m_data = new T[m_capacity];
             // this will initialize the m_data
             // note that the T constructor will be called m_capacity times in order to create m_data
         }

          // to add new elements
          // element are passed by const reference
          void push_back(const T& element){
              if (m_size >= m_capacity) {
                  allocate_copy_();
              }
              m_data[m_size] = element;
              // note that this will call the copy assingnment operator of T
              m_size++;
          }

          // element are passed by rvalue reference
          void push_back(T&& element){
             std::cout << "called push_back( T&& )\n";
              if (m_size >= m_capacity) {
                  allocate_copy_();
              }
              m_data[m_size] = std::move(element);
              m_size++;
         }

         // pop the last element and return it
         const T& pop_back(){
             if(m_size >= 0){
                 m_size--;
                 return m_data[m_size];
                 // Note that it doesn't free the memory
             }
             throw ;
         }

         // [] oerator (Read only)
         const T& operator[] (size_t index) const{
             if(index < m_size){
                 return m_data[index];
             }
             throw ;
         }

         size_t size(){return m_size;}
         size_t capacity(){return m_capacity;}

          // Destructor
         virtual ~Vector(){
             delete [] m_data;
         };

    private:
        T* m_data;
        size_t m_capacity = 1;
        size_t m_size =0;     //< index of the last element === number of items in the vector

    private:
        // to allocate more space
        void allocate_copy(){
            m_capacity *= 2;

            T* tmp_data = new T[m_capacity];
            // copying
            for(size_t i =0; i < m_size; i++){
                tmp_data[i] = m_data[i]; // call copy assignment operator of datatype T
            }

            delete[] m_data; // delete old allocated resource to avoid any memory leak.
            m_data = tmp_data; // now m_data is pointing to the newly allocated data

            //tmp_data = nullptr; // create hollow object, so delete[] tmp_data wont delete anything.

            std::cout << "Vector capacity has changed to " << m_capacity << std::endl;
        }

        // Reallocate memory for more space
        void allocate_copy_(){
            m_capacity *= 2;

            T* tmp_data = new T[m_capacity];
            //copying
            memcpy(tmp_data, m_data, m_size);

            delete [] m_data;
            m_data = tmp_data;
            tmp_data = nullptr;
        }
    };

} // End namespace mySTL
#endif //MYSTL_VECTOR_H
