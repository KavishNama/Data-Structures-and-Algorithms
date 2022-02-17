#include <iostream>
using namespace std;

int main()
{
    // Different methods of initializing and declaring arrays.
    int A[5];
    int B[5] = { 1,2,3,4,5 };
    int C[10] = { 2,4,6 };
    int D[5] = { 1 };
    int E[] = { 1,2,3,4,5,6,7 };

    // Addresses of elements of an array are contiguous.
    for (int i = 0; i < 5; i++) {
        cout << &B[i] << endl;
    }

    // Static vs Dynamic Array
    int arrayStatic[5];     // Static Array created in STACK
    int* p;                 // Pointer for storing array inside HEAP
    p = new int[5];         // Dynamic Array created in HEAP

    delete[]p;              // Freeing the memory in HEAP

    arrayStatic[0] = 24;    // Accessing elements in Static Array
    p[0] = 17;              // Accessing elements in Dynamic Array

    // Increasing the size of a Dynamic Array

    int* arrayPointer1;                         // Initial array of size 5
    arrayPointer1 = new int[5];
    arrayPointer1[0] = 2;
    arrayPointer1[1] = 3;
    arrayPointer1[2] = 6;
    arrayPointer1[3] = 7;
    arrayPointer1[4] = 11;

    int* arrayPointer2;                         // New array of size greater than previous array (i.e. 10)
    arrayPointer2 = new int[10];

    for (int i = 0; i < 5; i++) {
        arrayPointer2[i] = arrayPointer1[i];    // Copying values from old array into new array
    }

    delete[]arrayPointer1;                      // Deleting old array from HEAP
    arrayPointer1 = arrayPointer2;              // Pointing old pointer to new array
    arrayPointer2 = NULL;                       // Declaring new pointer as NULL as it's work is over now


    return 0;
}
