#include <iostream>
using namespace std;

template <class T>
class PriorityQueue_Array1 {
private:
    int size;
    int numPriorities;
    int *front;
    int *rear;
    T** A;

    //void swap(T* x, T* y);

public:
    T element;

    // Default Constructor 
    PriorityQueue_Array1();

    // Parameterized Constructor
    PriorityQueue_Array1(int s, int p);

    // Destructor
    ~PriorityQueue_Array1();

    // Function prototypes
    void Display();
    void Enqueue(T x, int p);
    T Dequeue();
    T Peek(int pos);
    bool isEmpty();
    bool isFull();
    T queueFront();

};

template <class T>
PriorityQueue_Array1<T>::PriorityQueue_Array1() {
    size = 10;
    numPriorities = 3;
    front = new int[numPriorities];
    rear = new int[numPriorities];
    A = new T * [numPriorities];
    for (int i = 0; i < numPriorities; i++) {
        front[i] = -1;
        rear[i] = -1;
        A[i] = new T[size];
    }

}

template <class T>
PriorityQueue_Array1<T>::PriorityQueue_Array1(int s, int p) {
    size = s;
    numPriorities = p;
    front = new int[numPriorities];
    rear = new int[numPriorities];
    A = new T * [numPriorities];
    for (int i = 0; i < numPriorities; i++) {
        front[i] = -1;
        rear[i] = -1;
        A[i] = new T[size];
    }

}

template <class T>
PriorityQueue_Array1<T>::~PriorityQueue_Array1() {
    delete[]front;
    delete[]rear;
    for (int i = 0; i < numPriorities; i++) {
        delete[] A[i];
    }
    delete[]A;

}

//// Helper function to be used in other functions
//template <class T>
//void Array<T>::swap(T* x, T* y) {
//    T temp;
//    temp = *x;
//    *x = *y;
//    *y = temp;
//}

// Function to display the contents of the priority queue
template <class T>
void PriorityQueue_Array1<T>::Display() {
    for (int i = 0; i < numPriorities; i++) {
        cout << "Priority " << i << " Queue: ";
        for (int j = front[i] + 1; j <= rear[i]; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to enqueue an element into the priority queue
template <class T>
void PriorityQueue_Array1<T>::Enqueue(T x, int p) {
    if (rear[p] == size - 1) {
        cout << "Priority Queue " << p << " is Full. Unable to enqueue!" << endl;
    }
    else {
        rear[p]++;
        A[p][rear[p]] = x;
        cout << x << " enqueued into Priority Queue " << p << "!" << endl;
    }
}

// Function to dequeue an element from the priority queue
template <class T>
T PriorityQueue_Array1<T>::Dequeue() {
    T x = -1;
    for (int i = 0; i < numPriorities; i++) {
        if ((front[i] == rear[i]) && (i != numPriorities - 1)) {
            continue;
        }
        else if ((front[i] == rear[i]) && (i == numPriorities - 1)) {
            cout << "Priority Queue is Empty. Unable to dequeue!" << endl;
        }
        else {
            front[i]++;
            x = A[i][front[i]];
            break;
        }
    }
    return x;
}

// Function to look an element at a given position in the priority queue
template <class T>
T PriorityQueue_Array1<T>::Peek(int pos) {
    T x = -1;
    int totalElements = 0;
    for (int i = 0; i < numPriorities; i++) {
        totalElements += (rear[i] - front[i]);
    }

    if (pos <= 0 || pos > totalElements) {
        cout << "Invalid Position!" << endl;
    }
    else {
        for (int i = 0; i < numPriorities; i++) {
            if (pos > rear[i] - front[i]) {
                pos -= rear[i] - front[i];
                continue;
            }
            else {
                x = A[i][front[i] + pos];
                break;
            }
        }
    }

    return x;
}

// Function to check if the priority queue is empty
template <class T>
bool PriorityQueue_Array1<T>::isEmpty() {
    for (int i = 0; i < numPriorities; i++) {
        if ((front[i] == rear[i]) && (i != numPriorities - 1)) {
            continue;
        }
        else if ((front[i] == rear[i]) && (i == numPriorities - 1)) {
            return true;
        }
        else {
            return false;
        }
    }
}

// Function to check if the queue is full
template <class T>
bool PriorityQueue_Array1<T>::isFull() {
    for (int i = 0; i < numPriorities; i++) {
        if ((rear[i]==size-1) && (i != numPriorities - 1)) {
            continue;
        }
        else if ((rear[i]==size-1) && (i == numPriorities - 1)) {
            return true;
        }
        else {
            return false;
        }
    }
}

// Function to find the frontmost element in the priority queue
template <class T>
T PriorityQueue_Array1<T>::queueFront() {
    for (int i = 0; i < numPriorities; i++) {
        if ((front[i] == rear[i]) && (i != numPriorities - 1)) {
            continue;
        }
        else if ((front[i] == rear[i]) && (i == numPriorities - 1)) {
            return -1;
        }
        else {
            return A[i][front[i] + 1];
        }
    }
}


int main()
{
    PriorityQueue_Array1<char>* que;

    int s;
    cout << "Please enter the size of the queue: ";
    cin >> s;
    int p;
    cout << "Please enter the number of priorities: ";
    cin >> p;

    que = new PriorityQueue_Array1<char>(s, p);

    int choice, position;
    decltype(que->element) x;
    int xPriority;

    do {
        cout << "\nMain Menu:\tChoose an operation to be performed on the PRIORITY QUEUE\n\n";
        cout << "1. Display\n";
        cout << "2. Enqueue\n";
        cout << "3. Dequeue\n";
        cout << "4. Peek\n";
        cout << "5. Check if the PRIORITY QUEUE is empty\n";
        cout << "6. Check if the PRIORITY QUEUE is full\n";
        cout << "7. Find the frontmost value in the PRIORITY QUEUE\n";
        cout << "8. Exit Menu\n\n";

        cin >> choice;

        switch (choice) {
        case 1: // Displaying the elements of the priority queue
            cout << "Elements of the queue are: " << endl;
            que->Display();
            break;

        case 2: // Enqueue an element into the priority queue
            cout << "Please enter an element and its priority: ";
            cin >> x >> xPriority;
            que->Enqueue(x, xPriority);
            break;

        case 3: // Dequeue an element from the priority queue
            x = que->Dequeue();
            if (x != -1) {
                cout << x << " dequeued from the queue" << endl;
            }
            break;

        case 4: // Looking an element at a given position in the priority queue
            cout << "Please enter a position: ";
            cin >> position;
            x = que->Peek(position);
            if (x != -1) {
                cout << x << " is present at position " << position << endl;
            }
            break;

        case 5: // Checking if the priority queue is empty
            if (que->isEmpty()) {
                cout << "PRIORITY QUEUE is empty" << endl;
            }
            else {
                cout << "PRIORITY QUEUE is not empty" << endl;
            }
            break;

        case 6: // Checking if the priority queue is full
            if (que->isFull()) {
                cout << "PRIORITY QUEUE is full" << endl;
            }
            else {
                cout << "PRIORITY QUEUE is not full" << endl;
            }
            break;

        case 7: // Finding the frontmost element in the PRIORITY QUEUE
            x = que->queueFront();
            if (x != -1) {
                cout << "Frontmost element in the PRIORITY QUEUE: " << x << endl;
            }
            else {
                cout << "PRIORITY QUEUE is empty. No frontmost element" << endl;
            }
            break;

        }

    } while (choice < 8);

    return 0;
}
