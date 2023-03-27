An array is a collection of elements of the same data type, which are stored sequentially in memory. The size of an
array is fixed and must be specified at compile time. This means that once the array is created, its size cannot be
changed.

In C++, arrays can be either stack-allocated or heap-allocated. Stack-allocated arrays are created on the program's call
stack, and their lifetime is tied to the scope in which they are declared. Heap-allocated arrays, on the other hand, are
created using dynamic memory allocation functions, such as `new` and `delete`, and their lifetime must be managed manually
by the programmer.

One important difference between arrays and vectors in C++ is that vectors are dynamically allocated on the heap, while
arrays are statically allocated on the stack. This means that the size of an array must be specified at compile time,
whereas the size of a vector can be changed dynamically at runtime.

While allocating memory on the heap can provide more flexibility, it can also slow down the program due to the overhead
of dynamic memory management. For this reason, stack-allocated arrays are often preferred when the size of the array is
known at compile time.

To declare a stack-allocated array in C++, we can use the following syntax:

```
int array[5];
```
This creates an array of five integers that is allocated on the stack. To declare a heap-allocated array, we can use
dynamic memory allocation functions, such as `new`:

```
int* arrayOnHeap = new int[5];
```
This creates an array of five integers that is allocated on the heap. We can then access the elements of the array using
the subscript operator ([]). It is important to note that we must properly deallocate the memory allocated on the heap
using the `delete` operator:

```
delete[] arrayOnHeap;
```
Assigning a pointer to a stack-allocated array does not immediately mean that the array is heap-allocated. Only using
the `new` keyword will allocate data on the heap.

