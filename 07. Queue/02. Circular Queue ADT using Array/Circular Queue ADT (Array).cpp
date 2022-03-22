#include <iostream>
using namespace std;

template <class T>
class CircularQueue_Array {
private:
    int size;
    int front;
    int rear;
    T* A;

    //void swap(T* x, T* y);

public:
    T element;

    // Default Constructor 
    CircularQueue_Array();

    // Parameterized Constructor
    CircularQueue_Array(int s);

    // Destructor
    ~CircularQueue_Array();

    // Function prototypes
    void Display();
    void Enqueue(T x);
    T Dequeue();
    T Peek(int pos);
    bool isEmpty();
    bool isFull();
    T queueFront();

};

template <class T>
CircularQueue_Array<T>::CircularQueue_Array() {
    size = 10;
    front = 0;
    rear = 0;
    A = new T[size];
}

template <class T>
CircularQueue_Array<T>::CircularQueue_Array(int s) {
    size = s;
    front = 0;
    rear = 0;
    A = new T[size];
}

template <class T>
CircularQueue_Array<T>::~CircularQueue_Array() {
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

// Function to display the contents of the circular queue
template <class T>
void CircularQueue_Array<T>::Display() {
    int i = (front + 1) % size;
    if (!isEmpty()) {
        do {
            cout << A[i] << " ";
            i = (i + 1) % size;
        } while (i != (rear + 1) % size);
    }
        
    cout << endl;
}

// Function to enqueue an element into the circular queue
template <class T>
void CircularQueue_Array<T>::Enqueue(T x) {
    if ((rear + 1) % size == front) {
        cout << "Queue is Full. Unable to enqueue!" << endl;
    }
    
    else {
        rear = (rear + 1) % size;
        A[rear] = x;
        cout << x << " enqueued into the queue!" << endl;
    }
}

// Function to dequeue an element from the circular queue
template <class T>
T CircularQueue_Array<T>::Dequeue() {
    T x = -1;
    if (front == rear) {
        cout << "Queue is Empty. Unable to dequeue!" << endl;
    }
    else {
        front = (front + 1) % size;
        x = A[front];
    }
    return x;
}


// Function to look an element at a given position in the circular queue
template <class T>
T CircularQueue_Array<T>::Peek(int pos) {
    T x = -1;
    if (pos <= 0 || front == rear || (rear > front && pos > rear - front) || (rear < front && pos > size - front + rear)) {
        cout << "Invalid Position!" << endl;
    }

    else {
        x = A[(front + pos) % size];
    }

    return x;
}

// Function to check if the circular queue is empty
template <class T>
bool CircularQueue_Array<T>::isEmpty() {
    if (front == rear) {
        return true;
    }
    else {
        return false;
    }
}

// Function to check if the circular queue is full
template <class T>
bool CircularQueue_Array<T>::isFull() {
    if ((rear + 1) % size == front) {
        return true;
    }
    else {
        return false;
    }
}

// Function to find the frontmost element in the circular queue
template <class T>
T CircularQueue_Array<T>::queueFront() {
    if (!isEmpty()) {
        return A[(front + 1) % size];
    }
    else {
        return -1;
    }
}


int main()
{
    CircularQueue_Array<int>* que;
    int s;

    cout << "Please enter the size of the circular queue: ";
    cin >> s;
    que = new CircularQueue_Array<int>(s);

    int choice, position;
    decltype(que->element) x;
    
    do {
        cout << "\nMain Menu:\tChoose an operation to be performed on the CIRCULAR QUEUE\n\n";
        cout << "1. Display\n";
        cout << "2. Enqueue\n";
        cout << "3. Dequeue\n";
        cout << "4. Peek\n";
        cout << "5. Check if the CIRCULAR QUEUE is empty\n";
        cout << "6. Check if the CIRCULAR QUEUE is full\n";
        cout << "7. Find the frontmost value in the CIRCULAR QUEUE\n";
        cout << "8. Exit Menu\n\n";

        cin >> choice;

        switch (choice) {
        case 1: // Displaying the elements of the circular queue
            cout << "Elements of the circular queue are: ";
            que->Display();
            break;

        case 2: // Enqueue an element into the circular queue
            cout << "Please enter an element: ";
            cin >> x;
            que->Enqueue(x);
            break;

        case 3: // Dequeue an element from the circular queue
            x = que->Dequeue();
            if (x != -1) {
                cout << x << " dequeued from the circular queue" << endl;
            }
            break;

        case 4: // Looking an element at a given position in the circular queue
            cout << "Please enter a position: ";
            cin >> position;
            x = que->Peek(position);
            if (x != -1) {
                cout << x << " is present at position " << position << endl;
            }
            break;

        case 5: // Checking if the circular queue is empty
            if (que->isEmpty()) {
                cout << "CIRCULAR QUEUE is empty" << endl;
            }
            else {
                cout << "CIRCULAR QUEUE is not empty" << endl;
            }
            break;

        case 6: // Checking if the circular queue is full
            if (que->isFull()) {
                cout << "CIRCULAR QUEUE is full" << endl;
            }
            else {
                cout << "CIRCULAR QUEUE is not full" << endl;
            }
            break;

        case 7: // Finding the frontmost element in the CIRCULAR QUEUE
            x = que->queueFront();
            if (x != -1) {
                cout << "Frontmost element in the CIRCULAR QUEUE: " << x << endl;
            }
            else {
                cout << "CIRCULAR QUEUE is empty. No frontmost element" << endl;
            }
            break;

        }

    } while (choice < 8);

    return 0;
}
