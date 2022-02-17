#include <iostream>
using namespace std;

int main()
{
    // Three Methods of creating a 2D Array

    // 1. Creating Array inside STACK
    int A[3][4] = { {1,2,3,4},{2,4,6,8},{3,5,7,9} };

    // 2. Creating an array of Pointers (which are in STACK) and they point to 1D arrays (in HEAP)
    int* arrayPointer1[3];
    arrayPointer1[0] = new int[4];
    arrayPointer1[1] = new int[4];
    arrayPointer1[2] = new int[4];

    // 3. Creating a Double Pointer (which is in STACK), which points to an array of pointer (in HEAP), and these pointers point to 1D arrays (in HEAP)
    int** arrayDoublePointer;
    arrayDoublePointer = new int* [3];
    arrayDoublePointer[0] = new int[4];
    arrayDoublePointer[1] = new int[4];
    arrayDoublePointer[2] = new int[4];

    // Accessing elements of a 2D Array
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
