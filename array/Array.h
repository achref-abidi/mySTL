//
// Created by achref on 27/03/2023.
//

#ifndef MYSTL_ARRAY_H
#define MYSTL_ARRAY_H

namespace mySTL{
    /**
     * @brief Array is a static, STACK allocated, fixed size array
     */
     // Usually in C++ if you want to refer to sizes use size_t
    template<typename T, size_t S>
    class Array{
    private:
        T m_data[S];

    public:
        Array()= default;
        virtual ~Array() = default;

        /**
         *
         * @return the size of the array
         * @remark const means that our function won't modify the state of our objectt
         * meaning that this function can be called by a const object
         * @remark `constexpr` indicates that the value, or return value, is constant and, where possible,
         * is computed at compile time.
         */
        constexpr size_t Size() const { return S; }

        /**
         * @brief Simple version of the index operator
         * @param index index of the element to access
         * @return reference of the data at the specified index.
         * @remark Return by value makes a copy of our data, which may introduce some
         * performance issues(if the data type is complex types)
         * @remark return by reference doesn't in fact make a copy, in addition to that we can assign
         * a new value to the returned one, i.e change the content of our Array
         */
        T& operator[] (size_t index) {
            return m_data[index];
        }

        /**
         * @brief index operator
         * @param index
         * @return
         * @remark this add some features:
         * @remark if our Array is constant the we can't access the index
         * operator for either reading or writing
         * The second const means we can call the index operator if the instance of
         * array in constant.
         * The first const makes sure that our data items won't change
         * by the user.
         */
        const T& operator[] (size_t index) const{
            return m_data[index];
        }

        /**
         * @brief  returns a pointer to the first element of the underlying array. This is done so that the user can
         * access the underlying data of the array directly by pointer arithmetic.
         *
         * @remarks If we modify the function to return a reference to the entire array, the signature would be
         * T (&Data())[S]. This would return a reference to the entire array, allowing the user to modify the array as
         * a whole, but not allowing the user to access individual elements of the array by pointer arithmetic.
         *
         * In general, returning a pointer to the first element of the array is more flexible and allows for more advanced use
         * cases, while returning a reference to the entire array is more restrictive but can provide better encapsulation.
         */
         T* Data() { return m_data; }

    };
} // End namespace mySTL

#endif //MYSTL_ARRAY_H
