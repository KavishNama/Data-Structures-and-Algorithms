#include <iostream>
using namespace std;

template <class T>
class Array {
private:
    T* A;
    int size;
    int length;

    void swap(T* x, T* y);

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
    T LinearSearch(T key);
    T LinearSearchTransposition(T key);
    T LinearSearchMoveToHead(T key);
    T BinarySearchLoop(T key);
    T BinarySearchRecursion(int l, int h, T key);
    T GetValue(int index);
    void SetValue(int index, T x);
    T MaxValue();
    T MinValue();
    T Sum();
    double Average();
    void ReverseAuxiliary();
    void ReverseSwap();
    void InsertSorted(T x);
    bool IsSorted();
    void RearrangePosNeg();
    Array<T>* Merge(Array<T> *arr2);
    Array<T>* Union(Array<T>* arr2);
    Array<T>* Intersection(Array<T>* arr2);
    Array<T>* SetDifference(Array<T>* arr2);
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

// Function to perform linear search on an array
template <class T>
T Array<T>::LinearSearch(T key) {
    int i = 0;
    for (i = 0; i < length; i++) {
        if (key == A[i]) {
            return i;
        }
    }
    return -1;
}

// Function to perform linear search on an array using transposition
template <class T>
T Array<T>::LinearSearchTransposition(T key) {
    int i = 0;
    for (i = 0; i < length; i++) {
        if (key == A[i]) {
            swap(&A[i], &A[i - 1]);
            return i;
        }
    }
    return -1;
}

// Function to perform linear search on an array using Move to Head
template <class T>
T Array<T>::LinearSearchMoveToHead(T key) {
    int i = 0;
    for (i = 0; i < length; i++) {
        if (key == A[i]) {
            swap(&A[i], &A[0]);
            return i;
        }
    }
    return -1;
}

// Function to perform binary search on an array using loops
template <class T>
T Array<T>::BinarySearchLoop(T key) {
    int l, mid, h;
    l = 0;
    h = length - 1;


    while (l <= h) {
        mid = (l + h) / 2;
        if (key == A[mid])
            return mid;
        else if (key < A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }

    return -1;
}

// Function to perform binary search on an array using Recursion
template <class T>
T Array<T>::BinarySearchRecursion(int l, int h, T key) {
    int mid;

    if (l <= h) {
        mid = (l + h) / 2;
        if (key == A[mid])
            return mid;
        else if (key < A[mid])
            return BinarySearchRecursion(l, mid - 1, key);
        else
            return BinarySearchRecursion(mid + 1, h, key);
    }

    return -1;
}

// Getter function to get value at a certain index of the array
template <class T>
T Array<T>::GetValue(int index) {
    if (index >= 0 && index < length) {
        return A[index];
    }
    return -1;
}

// Setter function to replace value at a certain index of the array
template <class T>
void Array<T>::SetValue(int index, T x) {
    if (index >= 0 && index < length) {
        A[index] = x;
    }
}

// Function to find maximum value in an array
template <class T>
T Array<T>::MaxValue() {
    T max = A[0];
    for (int i = 1; i < length; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    return max;
}

// Function to find minimum value in an array
template <class T>
T Array<T>::MinValue() {
    T min = A[0];
    for (int i = 1; i < length; i++) {
        if (A[i] < min) {
            min = A[i];
        }
    }
    return min;
}

// Function to find sum of all values in an array
template <class T>
T Array<T>::Sum() {
    T s = 0;
    for (int i = 0; i < length; i++) {
        s += A[i];
    }
    return s;
}

// Function to find average of all values in an array
template <class T>
double Array<T>::Average() {
    return (double)Sum() / length;
}

// Function to reverse an array using an auxiliary array
template <class T>
void Array<T>::ReverseAuxiliary() {
    T* B;
    int i, j;
    B = new T[length];
    for (i = length - 1, j = 0; i >= 0; i--, j++) {
        B[j] = A[i];
    }
    for (i = 0; i < length; i++) {
        A[i] = B[i];
    }
}

// Function to reverse an array using swap function
template <class T>
void Array<T>::ReverseSwap() {
    int i, j;
    for (i =0, j = length-1; i <j ; i++, j--) {
        swap(&A[i], &A[j]);
    }
}

// Function to insert an element in a sorted array
template <class T>
void Array<T>::InsertSorted(T x) {
    int i = length - 1;
    if (length < size) {
        while (i >= 0 && A[i] > x) {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = x;
        length++;
    }
}

// Function to check if an array is sorted or not
template <class T>
bool Array<T>::IsSorted() {
    int i = 0;
    for (i = 0; i < length - 1; i++) {
        if (A[i] > A[i + 1]) {
            return false;
        }
    }
    return true;
}

// Function to arrange all positive elements on one side and all negative elements on the other
template <class T>
void Array<T>::RearrangePosNeg() {
    int i = 0, j = length - 1;
    while (i < j) {
        while (A[i] < 0) {
            i++;
        }
        while (A[j] >= 0) {
            j--;
        }
        if (i < j) {
            swap(&A[i], &A[j]);
        }
    }
}

// Function to merge two arrays
template <class T>
Array<T>* Array<T>::Merge(Array<T> *arr2) {
    int i = 0, j = 0, k = 0;
    Array<T> *arr3;
    arr3 = new Array<T>[length + arr2->length];

    while (i < length && j < arr2->length) {
        if (A[i] < arr2->A[j]) {
            arr3->A[k] = A[i];
            k++;
            i++;
        }
        else {
            arr3->A[k] = arr2->A[j];
            k++;
            j++;
        }
    }
    for (; i < length; i++) {
        arr3->A[k] = A[i];
        k++;
    }
    for (; j < arr2->length; j++) {
        arr3->A[k] = arr2->A[j];
        k++;
    }
    arr3->length = length + arr2->length;

    return arr3;
}

// Function to find union of two arrays
template <class T>
Array<T>* Array<T>::Union(Array<T>* arr2) {
    int i = 0, j = 0, k = 0;
    Array<T>* arr3;
    arr3 = new Array<T>[length + arr2->length];

    while (i < length && j < arr2->length) {
        if (A[i] < arr2->A[j]) {
            arr3->A[k] = A[i];
            k++;
            i++;
        }
        else if (A[i] > arr2->A[j]) {
            arr3->A[k] = arr2->A[j];
            k++;
            j++;
        }
        else { // i.e. A[i] == arr2->A[j]
            arr3->A[k] =A[i];
            k++;
            i++;
            j++;
        }
    }
    for (; i < length; i++) {
        arr3->A[k] = A[i];
        k++;
    }
    for (; j < arr2->length; j++) {
        arr3->A[k] = arr2->A[j];
        k++;
    }
    arr3->length = k;

    return arr3;
}

// Function to find intersection of two arrays
template <class T>
Array<T>* Array<T>::Intersection(Array<T>* arr2) {
    int i = 0, j = 0, k = 0;
    Array<T>* arr3;
    arr3 = new Array<T>[length + arr2->length];

    while (i < length && j < arr2->length) {
        if (A[i] < arr2->A[j]) {
            i++;
        }
        else if (A[i] > arr2->A[j]) {
            j++;
        }
        else { // i.e. A[i] == arr2->A[j]
            arr3->A[k] = A[i];
            k++;
            i++;
            j++;
        }
    }

    arr3->length = k;

    return arr3;
}

template <class T>
Array<T>* Array<T>::SetDifference(Array<T>* arr2) {
    int i = 0, j = 0, k = 0;
    Array<T>* arr3;
    arr3 = new Array<T>[length + arr2->length];

    while (i < length && j < arr2->length) {
        if (A[i] < arr2->A[j]) {
            arr3->A[k] = A[i];
            k++;
            i++;
        }
        else if (A[i] > arr2->A[j]) {
            j++;
        }
        else { // i.e. A[i] == arr2->A[j]
            i++;
            j++;
        }
    }
    for (; i < length; i++) {
        arr3->A[k] = A[i];
        k++;
    }

    arr3->length = k;

    return arr3;
}


int main()
{
    Array<int> *arr, *arr2, *arr3;
    int s;

    cout << "Please enter the size of array: ";
    cin >> s;
    arr = new Array<int>(s);

    int choice, index;
    decltype(arr->element) x;
    decltype(arr2->element) x2;
    int s2, length2;

    do {
        cout << "\nMain Menu:\tChoose an operation\n\n";
        cout << "1. Display the array\n";
        cout << "2. Append an element to the array\n";
        cout << "3. Insert an element into the array\n";
        cout << "4. Delete an element from the array\n";
        cout << "5. Perform simple linear search on the array\n";
        cout << "6. Perform Transposition linear search on the array\n";
        cout << "7. Perform Move-to-Head linear search on the array\n";
        cout << "8. Perform binary search on the array using Loop\n";
        cout << "9. Perform binary search on the array using Recursion\n";
        cout << "10. Get value at a certain index\n";
        cout << "11. Set/Replace value at a certain index\n";
        cout << "12. Find Maximum value in the array\n";
        cout << "13. Find Minimum value in the array\n";
        cout << "14. Find Sum of all values in the array\n";
        cout << "15. Find Average of all values in the array\n";
        cout << "16. Reversing the array using Auxiliary array\n";
        cout << "17. Reversing the array using swap function\n";
        cout << "18. Inserting an element in a sorted array\n";
        cout << "19. Checking if the array is sorted or not\n";
        cout << "20. Arranging all positive elements on one side and all negative elements on the other\n";
        cout << "21. Merging two arrays\n";
        cout << "22. Find union of two arrays\n";
        cout << "23. Find intersection of two arrays\n";
        cout << "24. Find set difference of two arrays\n";
        cout << "25. Exit Menu\n\n";

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

        case 5: // Linear Search for an element in an array
            cout << "Please enter an element: ";
            cin >> x;
            cout << x << " is found at index: " << arr->LinearSearch(x) << endl;
            break;

        case 6: // Modified Linear Search using Transposition
            cout << "Please enter an element: ";
            cin >> x;
            cout << x << " is found at index: " << arr->LinearSearchTransposition(x) << endl;
            break;

        case 7: // Modified Linear Search using Move To Head method
            cout << "Please enter an element: ";
            cin >> x;
            cout << x << " is found at index: " << arr->LinearSearchMoveToHead(x) << endl;
            break;

        case 8: // Binary Search using Loop
            cout << "Please enter an element: ";
            cin >> x;
            cout << x << " is found at index: " << arr->BinarySearchLoop(x) << endl;
            break;

        case 9: // Binary Search using Recursion
            cout << "Please enter an element: ";
            cin >> x;
            cout << x << " is found at index: " << arr->BinarySearchRecursion(0, arr->getLength()-1, x) << endl;
            break;

        case 10: // Get value at a certain index
            cout << "Please enter an index: ";
            cin >> index;
            cout << arr->GetValue(index) << " is found at index " << index << endl;
            break;

        case 11: // Set/Replace value at a certain index
            cout << "Please enter an index: ";
            cin >> index;
            cout << "Please enter an element: ";
            cin >> x;
            arr->SetValue(index, x);
            cout << x << " replaced the element at index " << index << endl;
            break;

        case 12: // Find Maximum value in the array
            cout << "Maximum value in the array is: " << arr->MaxValue() << endl;
            break;

        case 13: // Find Minimum value in the array
            cout << "Minimum value in the array is: " << arr->MinValue() << endl;
            break;

        case 14: // Find Sum of all values in the array
            cout << "Sum of all values in the array is: " << arr->Sum() << endl;
            break;

        case 15: // Find Average of all values in the array
            cout << "Average of all values in the array is: " << arr->Average() << endl;
            break;

        case 16: // Reversing the array using Auxiliary array
            arr->ReverseAuxiliary();
            cout << "Array Reversed" << endl;
            break;

        case 17: // Reversing the array using swap function
            arr->ReverseSwap();
            cout << "Array Reversed" << endl;
            break;

        case 18: // Inserting an element in a sorted array
            cout << "Please enter an element: ";
            cin >> x;
            arr->InsertSorted(x);
            cout << x << " inserted into the array" << endl;
            break;

        case 19: // Checking if the array is sorted or not
            if (arr->IsSorted()) {
                cout << "Array is sorted" << endl;
            }
            else {
                cout << "Array is not sorted" << endl;
            }
            break;

        case 20: // Arranging all positive elements on one side and all negative elements on the other
            arr->RearrangePosNeg();
            cout << "Array Rearranged" << endl;
            break;

        case 21: // Merging two arrays
            cout << "Please enter the size of array 2: ";
            cin >> s2;
            arr2 = new Array<int>[s2];
            cout << "Please enter number of elements in array 2: ";
            cin >> length2;
            cout << "Please enter the elements in array 2: ";
            for (int i = 0; i < length2; i++) {
                cin >> x2;
                arr2->Append(x2);
            }
            
            arr3 = arr->Merge(arr2);
            cout << "\nArray 1: ";
            arr->Display();
            cout << "\nArray 2: ";
            arr2->Display();
            cout << "\nArray 3: ";
            arr3->Display();
            break;

        case 22: // Find union of two arrays
            cout << "Please enter the size of array 2: ";
            cin >> s2;
            arr2 = new Array<int>[s2];
            cout << "Please enter number of elements in array 2: ";
            cin >> length2;
            cout << "Please enter the elements in array 2: ";
            for (int i = 0; i < length2; i++) {
                cin >> x2;
                arr2->Append(x2);
            }

            arr3 = arr->Union(arr2);
            cout << "\nArray 1: ";
            arr->Display();
            cout << "\nArray 2: ";
            arr2->Display();
            cout << "\nArray 3: ";
            arr3->Display();
            break;

        case 23: // Find intersection of two arrays
            cout << "Please enter the size of array 2: ";
            cin >> s2;
            arr2 = new Array<int>[s2];
            cout << "Please enter number of elements in array 2: ";
            cin >> length2;
            cout << "Please enter the elements in array 2: ";
            for (int i = 0; i < length2; i++) {
                cin >> x2;
                arr2->Append(x2);
            }

            arr3 = arr->Intersection(arr2);
            cout << "\nArray 1: ";
            arr->Display();
            cout << "\nArray 2: ";
            arr2->Display();
            cout << "\nArray 3: ";
            arr3->Display();
            break;

        case 24: // Find set difference of two arrays
            cout << "Please enter the size of array 2: ";
            cin >> s2;
            arr2 = new Array<int>[s2];
            cout << "Please enter number of elements in array 2: ";
            cin >> length2;
            cout << "Please enter the elements in array 2: ";
            for (int i = 0; i < length2; i++) {
                cin >> x2;
                arr2->Append(x2);
            }

            arr3 = arr->SetDifference(arr2);
            cout << "\nArray 1: ";
            arr->Display();
            cout << "\nArray 2: ";
            arr2->Display();
            cout << "\nArray 3: ";
            arr3->Display();
            break;

        }

    } while (choice < 25);

    return 0;
}
