#include <iostream>
using namespace std;

template <class T>
class HEAP_Array {
private:
    int size;
    int newPosition;
    T* A;

public:
    T element;

    // Default Constructor 
    HEAP_Array();

    // Parameterized Constructor
    HEAP_Array(int s);

    // Destructor
    ~HEAP_Array();

    // Function prototypes
    void DisplayHeap();
    void DisplayArray();
    T Insert();
    T Delete();

};

template <class T>
HEAP_Array<T>::HEAP_Array() {
    size = 10;
    newPosition = 0;
    A = new T[size];
    A[newPosition] = 0;
    newPosition++;
}

template <class T>
HEAP_Array<T>::HEAP_Array(int s) {
    size = s;
    newPosition = 0;
    A = new T[size+1];
    A[newPosition] = 0;
    newPosition++;
    for (int i = 1; i <= size; i++) {
        cout << "Please enter an element: ";
        cin >> A[i];
    }
}

template <class T>
HEAP_Array<T>::~HEAP_Array() {
    delete[]A;
}

// Function to display the elements in the HEAP
template <class T>
void HEAP_Array<T>::DisplayHeap() {
    for (int i = 1; i < newPosition; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

// Function to display all the elements in the ARRAY
template <class T>
void HEAP_Array<T>::DisplayArray() {
    for (int i = 1; i <= size; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

// Function to insert an element in the HEAP
template <class T>
T HEAP_Array<T>::Insert() {
    if (newPosition > size) {
        return -1;
    }

    T temp;
    int i = newPosition;
    temp = A[newPosition];
    while (i > 1 && temp > A[i / 2]) {
        A[i] = A[i / 2];
        i = i / 2;
    }
    A[i] = temp;
    newPosition++;
    return temp;
}

// Function to delete an element from the HEAP
template <class T>
T HEAP_Array<T>::Delete() {
    if (newPosition == 1) {
        return -1;
    }

    T x, temp;
    int i, j;
    x = A[1];
    newPosition--;
    A[1] = A[newPosition];
    A[newPosition] = x;
    i = 1, j = 2 * i;
    while (j < newPosition - 1) {
        if (A[j + 1] > A[j]) {
            j = j + 1;
        }

        if (A[i] < A[j]) {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2 * j;
        }
        else {
            break;
        }
    }
    return x;
}


int main()
{
    HEAP_Array<int>* heap;
    int s;
    cout << "Please enter the size of the HEAP: ";
    cin >> s;

    decltype(heap->element) x;

    heap = new HEAP_Array<int>(s);

    int choice;

    do {
        cout << "\nMain Menu:\tChoose an operation to be performed on the HEAP\n\n";
        cout << "1. Display HEAP\n";
        cout << "2. Display ARRAY\n";
        cout << "3. Insert\n";
        cout << "4. Delete\n";
        cout << "5. HEAP Sort\n";
        cout << "6. Exit Menu\n\n";

        cin >> choice;

        switch (choice) {
        case 1: // Displaying the contents of the HEAP
            cout << "HEAP: ";
            heap->DisplayHeap();
            break;

        case 2: // Displaying the contents of the ARRAY
            cout << "ARRAY: ";
            heap->DisplayArray();
            break;

        case 3: // Inserting an element from ARRAY into HEAP
            x = heap->Insert();
            if (x != -1) {
                cout << x << " inserted into the HEAP" << endl;
            }
            else {
                cout << "HEAP is full. Unable to insert!" << endl;
            }
            break;
        
        case 4: // Deleting an element from the HEAP
            x = heap->Delete();
            if (x != -1) {
                cout << x << " deleted from the HEAP" << endl;
            }
            else {
                cout << "HEAP is empty. Unable to delete!" << endl;
            }
            break;

        case 5: // Performing HEAP sort on the elements of the ARRAY
            cout << "Before HEAP Sort: ";
            heap->DisplayArray();

            for (int i = 0; i < s; i++) {
                heap->Insert();
            }
            for (int i = 0; i < s; i++) {
                heap->Delete();
            }

            cout << "After HEAP Sort: ";
            heap->DisplayArray();
            break;
        
        }

    } while (choice < 6);

    return 0;
}
