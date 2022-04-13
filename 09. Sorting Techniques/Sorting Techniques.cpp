#include <iostream>
using namespace std;

template <class T>
class Array {
private:
    T* A;
    int size;
    int length;

    void swap(T* x, T* y);
    int partition(int l, int h);
    void merge(int l, int mid, int h);

public:
    T element;

    // Default Constructor 
    Array();

    // Parameterized Constructor
    Array(int s);

    // Destructor
    ~Array();

    // Function prototypes
    int getLength();
    void Display();
    void Append(T x);
    void Insert(int index, T x);
    T Delete(int index);
    void bubbleSort();
    void insertionSort();
    void selectionSort();
    void quickSort();
    void quickSort(int l, int h);
    void mergeSortIterative();
    void mergeSortRecursive();
    void mergeSortRecursive(int l, int h);
    
    
};

template <class T>
Array<T>::Array() {
    size = 10;
    length = 0;
    A = new T[size];
}

template <class T>
Array<T>::Array(int s) {
    size = s;
    length = 0;
    A = new T[size];
}

template <class T>
Array<T>::~Array() {
    delete[]A;
}

// Helper function to get length of the array
template <class T>
int Array<T>::getLength() {
    return length;
}

// Helper function to be used in other functions
template <class T>
void Array<T>::swap(T* x, T* y) {
    T temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Function to display the content of an array
template <class T>
void Array<T>::Display() {
    for (int i = 0; i < length; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

// Function to append an element at the end of an array
template <class T>
void Array<T>::Append(T x) {
    if (length < size) {
        A[length] = x;
        length++;
    }
}

// Function to insert an element at a given index
template <class T>
void Array<T>::Insert(int index, T x) {
    int i;
    if (index >= 0 && index <= length) {
        for (i = length; i > index; i--) {
            A[i] = A[i - 1];
        }
        A[index] = x;
        length++;
    }
}

// Function to delete an element from a given index
template <class T>
T Array<T>::Delete(int index) {
    T x = 0;
    int i;
    if (index >= 0 && index < length) {
        x = A[index];
        for (i = index; i < length - 1; i++) {
            A[i] = A[i + 1];
        }
        length--;
        return x;
    }
    return 0;
}

// Function to sort the elements of the array using Bubble Sort Algorithm
template <class T>
void Array<T>::bubbleSort() {
    int i, j;
    bool flag = false;
    for (i = 0; i < length - 1; i++) {
        flag = false;
        for (j = 0; j < length - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                swap(&A[j], &A[j + 1]);
                flag = true;
            }
        }
        if (flag == false) {
            break;
        }
    }
}

// Function to sort the elements of the array using Insertion Sort Algorithm
template <class T>
void Array<T>::insertionSort() {
    int i, j;
    T x;
    for (i = 1; i < length; i++) {
        j = i - 1;
        x = A[i];
        while (j > -1 && A[j] > x) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
    }
}

// Function to sort the elements of the array using Selection Sort Algorithm
template <class T>
void Array<T>::selectionSort() {
    int i, j, k;
    for (i = 0; i < length - 1; i++) {
        for (j = k = i; j < length; j++) {
            if (A[j] < A[k]) {
                k = j;
            }
        }
        swap(&A[i], &A[k]);
    }
}

// Function to find the partition in the array for implementing Quick Sort Algorithm
template <class T>
int Array<T>::partition(int l, int h) {
    T pivot = A[l];
    int i = l, j = h;
    do {
        do {
            i++;
        } while (A[i] <= pivot);

        do {
            j--;
        } while (A[j] > pivot);

        if (i < j) {
            swap(&A[i], &A[j]);
        }
    } while (i < j);

    swap(&A[l], &A[j]);
    return j;
}

// Function to sort the elements of the array using Quick Sort Algorithm
template <class T>
void Array<T>::quickSort() {
    quickSort(0, length - 1);
}
template <class T>
void Array<T>::quickSort(int l, int h) {
    int j;
    if (l < h) {
        j = partition(l, h);
        quickSort(l, j);
        quickSort(j + 1, h);
    }
}

// Function to merge two lists in a single array for implementing Merge Sort Algorithm
template <class T>
void Array<T>::merge(int l, int mid, int h) {
    int i = l, j = mid + 1, k = l;
    T* B = new T[length];
    //T B[100];

    while (i <= mid && j <= h) {
        if (A[i] < A[j]) {
            B[k] = A[i];
            k++;
            i++;
        }
        else {
            B[k] = A[j];
            k++;
            j++;
        }
    }

    for (; i <= mid; i++) {
        B[k] = A[i];
        k++;
    }
    for (; j <= h; j++) {
        B[k] = A[j];
        k++;
    }
    for (i = l; i <= h; i++) {
        A[i] = B[i];
    }

}

// Function to sort the elements of the array using Merge Sort Algorithm - Iterative version
template <class T>
void Array<T>::mergeSortIterative() {
    int p, i, l, mid, h;
    for (p = 2; p <= length; p = p * 2) {
        for (i = 0; i + p - 1 < length; i = i + p) {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            merge(l, mid, h);
        }
    }
    if (p / 2 < length) {
        merge(p / 2, ((p / 2) + length) / 2, length - 1);
        merge(0, p / 2 - 1, length - 1);
    }
}

// Function to sort the elements of the array using Merge Sort Algorithm - Recursive version
template <class T>
void Array<T>::mergeSortRecursive() {
    mergeSortRecursive(0, length - 1);
}
template <class T>
void Array<T>::mergeSortRecursive(int l, int h) {
    int mid;
    if (l < h) {
        mid = (l + h) / 2;
        mergeSortRecursive(l, mid);
        mergeSortRecursive(mid + 1, h);
        merge(l, mid, h);
    }
}


int main()
{
    Array<int>* arr;

    int s;
    cout << "Please enter the size of array: ";
    cin >> s;

    arr = new Array<int>(s);

    int choice, index;
    decltype(arr->element) x;

    do {
        cout << "\nMain Menu:\tChoose an operation to be performed on the ARRAY\n\n";
        cout << "1. Display\n";
        cout << "2. Append\n";
        cout << "3. Insert at an index\n";
        cout << "4. Delete from an index\n";
        cout << "5. Perform Bubble Sort\n";
        cout << "6. Perform Insertion Sort\n";
        cout << "7. Perform Selection Sort\n";
        cout << "8. Perform Quick Sort\n";
        cout << "9. Perform Merge Sort - Iterative\n";
        cout << "10. Perform Merge Sort - Recursive\n";

        cout << "11. Exit Menu\n\n";

        cin >> choice;

        switch (choice) {
        case 1: // Displaying the elements of an array
            cout << "Elements of the array are: ";
            arr->Display();
            break;

        case 2: // Appending an element to an array
            cout << "Please enter an element: ";
            cin >> x;
            arr->Append(x);
            cout << x << " appended to the array" << endl;
            break;

        case 3: // Inserting an element at a given index
            cout << "Please enter an index: ";
            cin >> index;
            cout << "Please enter an element: ";
            cin >> x;
            arr->Insert(index, x);
            cout << x << " inserted at the index " << index << endl;
            break;

        case 4: // Deleting an element from an array
            cout << "Please enter an index: ";
            cin >> index;
            cout << arr->Delete(index) << " deleted from the array" << endl;
            break;

        case 5: // Sorting the elements in the array using Bubble Sort Algorithm
            cout << "Before Bubble Sort: ";
            arr->Display();

            arr->bubbleSort();

            cout << "After Bubble Sort: ";
            arr->Display();
            break;

        case 6: // Sorting the elements in the array using Insertion Sort Algorithm
            cout << "Before Insertion Sort: ";
            arr->Display();

            arr->insertionSort();

            cout << "After Insertion Sort: ";
            arr->Display();
            break;

        case 7: // Sorting the elements in the array using Selection Sort Algorithm
            cout << "Before Selection Sort: ";
            arr->Display();

            arr->selectionSort();

            cout << "After Selection Sort: ";
            arr->Display();
            break;

        case 8: // Sorting the elements in the array using Quick Sort Algorithm
            cout << "Before Quick Sort: ";
            arr->Display();

            arr->quickSort();

            cout << "After Quick Sort: ";
            arr->Display();
            break;

        case 9: // Sorting the elements in the array using Merge Sort Algorithm - Iterative version
            cout << "Before Merge Sort: ";
            arr->Display();

            arr->mergeSortIterative();

            cout << "After Merge Sort: ";
            arr->Display();
            break;

        case 10: // Sorting the elements in the array using Merge Sort Algorithm - Recursive version
            cout << "Before Merge Sort: ";
            arr->Display();

            arr->mergeSortRecursive();

            cout << "After Merge Sort: ";
            arr->Display();
            break;


        }

    } while (choice < 11);

    return 0;
}
