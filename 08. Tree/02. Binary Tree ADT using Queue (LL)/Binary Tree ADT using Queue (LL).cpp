#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    Node* lchild;
    T data;
    Node* rchild;

};

template <class T>
class Queue {
private:
    int size;
    int front;
    int rear;
    Node** A;

public:
    T element;

    // Default Constructor 
    Queue();

    // Parameterized Constructor
    Queue(int s);

    // Destructor
    ~Queue();

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
Queue<T>::Queue() {
    size = 10;
    front = 0;
    rear = 0;
    A = new Node*[size];
}

template <class T>
Queue<T>::Queue(int s) {
    size = s;
    front = 0;
    rear = 0;
    A = new Node*[size];
}

template <class T>
Queue<T>::~Queue() {
    for (int i = 0; i < size; i++) {
        delete[] A[i];
    }
    delete[]A;
}

// Function to display the contents of the circular queue
template <class T>
void Queue<T>::Display() {
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
void Queue<T>::Enqueue(T x) {
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
T Queue<T>::Dequeue() {
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
T Queue<T>::Peek(int pos) {
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
bool Queue<T>::isEmpty() {
    if (front == rear) {
        return true;
    }
    else {
        return false;
    }
}

// Function to check if the circular queue is full
template <class T>
bool Queue<T>::isFull() {
    if ((rear + 1) % size == front) {
        return true;
    }
    else {
        return false;
    }
}

// Function to find the frontmost element in the circular queue
template <class T>
T Queue<T>::queueFront() {
    if (!isEmpty()) {
        return A[(front + 1) % size];
    }
    else {
        return -1;
    }
}