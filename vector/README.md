## Introduction

The code you provided implements a simple vector container class with some basic functionality such as adding elements
to the back, removing elements from the back, and clearing the vector.

The vector is implemented as a dynamically allocated array of elements of type T. The class has three private data
members: a pointer to the beginning of the array (__m_data__), the actual capacity of the vector (m_capacity), and the
number of elements currently in the vector (__m_size__).

The __push_back()__ member function adds an element to the back of the vector. If the current number of elements in the
vector is equal to the capacity, the function doubles the capacity of the vector by calling the ReAlloc() member
function. If the argument passed to push_back() is an rvalue reference, it uses std::move() to move the object into the
vector. Otherwise, it calls the copy assignment operator of T.

The __pop_back()__ member function removes the last element from the vector. If the vector is not empty, it calls the
destructor of the last element in the vector and decrements the size of the vector.

The __clear()__ member function removes all elements from the vector by calling the destructor of each element in the
vector
and setting the size of the vector to 0.

The __operator[]__ member function returns a const reference to the element at the specified index in the vector. If the
index is out of range, the function throws an exception.

The __ReAlloc()__ member function reallocates memory for the vector. If the new capacity is greater than the current
capacity, it creates a new block of memory and moves the elements from the old block to the new block using move
assignment. Finally, it deallocates the old block of memory.

## About The use operator delete:

`new[]` allocates a block of memory and calls the constructor of each element in the block, while `delete[]` (do the
opposed) calls the
destructor of each element and frees the block of memory allocated by `new[]`.

It's important to note that calling the destructor of each element in the block won't automatically free the space
allocated for the block itself. The memory block is still present and needs to be freed separately to return to the free
list of memory.

```
Vector(){
m_data = new T[m_capacity];
}

void clear(){
for(item in m_data){
    p->~T();
    }
    m_size = 0;
}

~Vector(){
delete[] m_data;
}
```

In the case of a (simple) vector implementation(as in this example above, psydo-code), the destructor of the vector
calls the destructor of each element in
the vector
and then frees the memory block using `delete[]`. However, there is a bug here; if the `clear()` method is called before
the vector's destructor,
it will call the destructor of each element, but the memory block won't be freed. and then vector's destructor is
called, which will -as we said call the destructor of each element- This can result in a double
deletion error, leading to undefined behavior and potential program crashes.
Note that this bug will occure only when the elemnts of vector are complex types meaning that they also have memory
allocated members.

## ChatGPT : The BUG

the bug that can occur is related to double-deleting memory. In the ~Vector() destructor, there is a call to clear()
that explicitly calls the destructor of each element in the vector. Then, the destructor deallocates the memory using ::
operator delete without calling the destructor of each element again. However, if the clear() function is also called
before calling the destructor, the destructor will attempt to call the destructor of each element again, resulting in
undefined behavior. To avoid this issue, one solution is to manually delete the vector's items in the ~Vector()
destructor using the clear() function, and then delete the memory without calling the destructor of each element
using ::operator delete.

## Good References

- [VECTOR/DYNAMIC ARRAY - Making DATA STRUCTURES in C++](https://www.youtube.com/watch?v=ryRf4Jh_YC0).
- [The NEW Keyword in C++](https://www.youtube.com/watch?v=NUZdUSqsCs4).

## ChatGPT explaining: The Dangers of Double Deletion in C++ Memory Management

When an array is allocated with new[] operator, the compiler internally keeps track of the number of elements in the
array. When we use the delete[] operator to deallocate the memory, the compiler uses this information to deallocate the
correct number of elements.

In the case of a vector, the internal array is allocated using new[], but the vector class keeps track of the number of
elements and the capacity of the array using separate member variables. When we call delete[] on m_data in the vector's
destructor, the compiler doesn't know how many elements were allocated using new[] since it's only aware of the size of
the array itself and not the number of elements stored in it. Therefore, it will try to deallocate the entire array,
which will result in undefined behavior and program crashes if the array was reallocated or resized.
