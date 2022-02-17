#include <iostream>
using namespace std;

template <class T>
class UpperTriangular {
private:
    T* A;
    int dim;

public:
    T element;

    // Default Constructor 
    UpperTriangular();

    // Parameterized Constructor
    UpperTriangular(int n);

    // Destructor
    ~UpperTriangular();

    // Function prototypes
    void Create();
    T GetValue(int i, int j);
    void SetValue(int i, int j, T x);
    void Display();

};

template <class T>
UpperTriangular<T>::UpperTriangular() {
    dim = 3;
    A = new T[dim * (dim + 1) / 2];
}

template <class T>
UpperTriangular<T>::UpperTriangular(int n) {
    dim = n;
    A = new T[dim * (dim + 1) / 2];
}

template <class T>
UpperTriangular<T>::~UpperTriangular() {
    delete[]A;
}

// Function to create a diagonal matrix
template <class T>
void UpperTriangular<T>::Create() {
    T x;
    for (int i = 1; i <= dim; i++) {
        for (int j = 1; j <= dim; j++) {
            cin >> x;
            if (i <= j) {
                A[(dim * (i - 1)) - ((i - 2) * (i - 1) / 2) + (j - i)] = x;
            }
        }
    }
    cout << endl;
}

// Getter function to get value at a certain index of the array
template <class T>
T UpperTriangular<T>::GetValue(int i, int j) {
    if (i <= j) {
        return A[(dim * (i - 1)) - ((i - 2) * (i - 1) / 2) + (j - i)];
    }
    else {
        return 0;
    }
}

// Setter function to replace value at a certain index of the diagonal matrix
template <class T>
void UpperTriangular<T>::SetValue(int i, int j, T x) {
    if (i <= j) {
        A[(dim * (i - 1)) - ((i - 2) * (i - 1) / 2) + (j - i)] = x;
    }
}

// Function to display the diagonal matrix
template <class T>
void UpperTriangular<T>::Display() {
    for (int i = 1; i <= dim; i++) {
        for (int j = 1; j <= dim; j++) {
            if (i <= j) {
                cout << A[(dim * (i - 1)) - ((i - 2) * (i - 1) / 2) + (j - i)] << " ";
            }
            else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    cout << endl;
}


int main()
{
    UpperTriangular<int>* mat;
    int n;

    cout << "Please enter the dimension of matrix: ";
    cin >> n;
    mat = new UpperTriangular<int>(n);

    int choice, i, j;
    decltype(mat->element) x;

    do {
        cout << "\nMain Menu:\tChoose an operation to be performed on Upper Triangular Matrix\n\n";
        cout << "1. Create\n";
        cout << "2. Display\n";
        cout << "3. Get value at a certain index\n";
        cout << "4. Set/Replace value at a certain index\n";
        cout << "5. Exit Menu\n\n";

        cin >> choice;

        switch (choice) {
        case 1: // Creating the Upper Triangular matrix
            cout << "Please enter the elements: " << endl;
            mat->Create();
            break;

        case 2: // Displaying the Upper Triangular matrix
            cout << "Elements of the Upper Triangular Matrix are: " << endl;
            mat->Display();
            break;

        case 3: // Get value at a certain index
            cout << "Please enter the i and j index: " << endl;
            cin >> i >> j;
            cout << mat->GetValue(i, j) << " is found at index (" << i << ", " << j << ")" << endl;
            break;

        case 4: // Set/Replace value at a certain index
            cout << "Please enter the i and j index: " << endl;
            cin >> i >> j;
            cout << "Please enter an element: ";
            cin >> x;
            mat->SetValue(i, j, x);
            cout << x << " replaced the element at index (" << i << ", " << j << ")" << endl;
            break;

        }

    } while (choice < 5);

    return 0;
}