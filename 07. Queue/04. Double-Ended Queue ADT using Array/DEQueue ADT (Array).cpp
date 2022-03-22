#include <iostream>
using namespace std;

template <class T>
class DEQueue_Array {
private:
    int size;
    int front;
    int rear;
    T* A;

    //void swap(T* x, T* y);

public:
    T element;

    // Default Constructor 
    DEQueue_Array();

    // Parameterized Constructor
    DEQueue_Array(int s);

    // Destructor
    ~DEQueue_Array();

    // Function prototypes
    void Display();
    void frontEnqueue(T x);
    void rearEnqueue(T x);
    T frontDequeue();
    T rearDequeue();
    T Peek(int pos);
    bool isEmpty();
    bool isFull();
    T queueFront();

};

template <class T>
DEQueue_Array<T>::DEQueue_Array() {
    size = 10;
    front = -1;
    rear = -1;
    A = new T[size];
}

template <class T>
DEQueue_Array<T>::DEQueue_Array(int s) {
    size = s;
    front = -1;
    rear = -1;
    A = new T[size];
}

template <class T>
DEQueue_Array<T>::~DEQueue_Array() {
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

// Function to display the contents of the DEQueue
template <class T>
void DEQueue_Array<T>::Display() {
    for (int i = front + 1; i <= rear; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

// Function to enqueue an element into the DEQueue from front end
template <class T>
void DEQueue_Array<T>::frontEnqueue(T x) {
    if (rear == size - 1) {
        cout << "Queue is Full. Unable to enqueue!" << endl;
    }
    else {
        for (int i = rear + 1; i > front + 1; i--) {
            A[i] = A[i - 1];
        }
        rear++;
        A[front + 1] = x;
        cout << x << " enqueued into the Queue!" << endl;
    }
}

// Function to enqueue an element into the DEQueue from rear end
template <class T>
void DEQueue_Array<T>::rearEnqueue(T x) {
    if (rear == size - 1) {
        cout << "Queue is Full. Unable to enqueue!" << endl;
    }
    else {
        rear++;
        A[rear] = x;
        cout << x << " enqueued into the Queue!" << endl;
    }
}

// Function to dequeue an element from the DEQueue from front end
template <class T>
T DEQueue_Array<T>::frontDequeue() {
    T x = -1;
    if (front == rear) {
        cout << "Queue is Empty. Unable to dequeue!" << endl;
    }
    else {
        front++;
        x = A[front];
    }
    return x;
}

// Function to dequeue an element from the DEQueue fron rear end
template <class T>
T DEQueue_Array<T>::rearDequeue() {
    T x = -1;
    if (front == rear) {
        cout << "Queue is Empty. Unable to dequeue!" << endl;
    }
    else {
        x = A[rear];
        rear--;
    }
    return x;
}

// Function to look an element at a given position in the DEQueue
template <class T>
T DEQueue_Array<T>::Peek(int pos) {
    T x = -1;
    if (pos <= 0 || pos > rear - front) {
        cout << "Invalid Position!" << endl;
    }
    else {
        x = A[front + pos];
    }

    return x;
}

// Function to check if the DEQueue is empty
template <class T>
bool DEQueue_Array<T>::isEmpty() {
    if (front == rear) {
        return true;
    }
    else {
        return false;
    }
}

// Function to check if the DEQueue is full
template <class T>
bool DEQueue_Array<T>::isFull() {
    if (rear == size - 1) {
        return true;
    }
    else {
        return false;
    }
}

// Function to find the frontmost element in the DEQueue
template <class T>
T DEQueue_Array<T>::queueFront() {
    if (!isEmpty()) {
        return A[front + 1];
    }
    else {
        return -1;
    }
}


int main()
{
    DEQueue_Array<int>* que;
    int s;

    cout << "Please enter the size of the DEQueue: ";
    cin >> s;
    que = new DEQueue_Array<int>(s);

    int choice, position;
    decltype(que->element) x;

    do {
        cout << "\nMain Menu:\tChoose an operation to be performed on the DEQUEUE\n\n";
        cout << "1. Display\n";
        cout << "2. Enqueue from front end\n";
        cout << "3. Enqueue from rear end\n";
        cout << "4. Dequeue from front end\n";
        cout << "5. Dequeue from rear end\n";
        cout << "6. Peek\n";
        cout << "7. Check if the DEQUEUE is empty\n";
        cout << "8. Check if the DEQUEUE is full\n";
        cout << "9. Find the frontmost value in the DEQUEUE\n";
        cout << "10. Exit Menu\n\n";

        cin >> choice;

        switch (choice) {
        case 1: // Displaying the elements of the DEQueue
            cout << "Elements of the queue are: ";
            que->Display();
            break;

        case 2: // Enqueue an element into the DEQueue from front end
            cout << "Please enter an element: ";
            cin >> x;
            que->frontEnqueue(x);
            break;

        case 3: // Enqueue an element into the DEQueue from rear end
            cout << "Please enter an element: ";
            cin >> x;
            que->rearEnqueue(x);
            break;

        case 4: // Dequeue an element from the DEQueue from front end
            x = que->frontDequeue();
            if (x != -1) {
                cout << x << " dequeued from the queue" << endl;
            }
            break;

        case 5: // Dequeue an element from the DEQueue from rear end
            x = que->rearDequeue();
            if (x != -1) {
                cout << x << " dequeued from the queue" << endl;
            }
            break;

        case 6: // Looking an element at a given position in the DEQueue
            cout << "Please enter a position: ";
            cin >> position;
            x = que->Peek(position);
            if (x != -1) {
                cout << x << " is present at position " << position << endl;
            }
            break;

        case 7: // Checking if the DEQueue is empty
            if (que->isEmpty()) {
                cout << "QUEUE is empty" << endl;
            }
            else {
                cout << "QUEUE is not empty" << endl;
            }
            break;

        case 8: // Checking if the DEQueue is full
            if (que->isFull()) {
                cout << "QUEUE is full" << endl;
            }
            else {
                cout << "QUEUE is not full" << endl;
            }
            break;

        case 9: // Finding the frontmost element in the DEQueue
            x = que->queueFront();
            if (x != -1) {
                cout << "Frontmost element in the QUEUE: " << x << endl;
            }
            else {
                cout << "QUEUE is empty. No frontmost element" << endl;
            }
            break;

        }

    } while (choice < 10);

    return 0;
}
