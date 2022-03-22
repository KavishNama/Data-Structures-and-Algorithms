#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node* next;

};

template <class T>
class Queue_LL {
private:
    Node<T>* front;
    Node<T>* rear;

    //void swap(T* x, T* y);
    int getLength();

public:
    T element;

    // Default Constructor 
    Queue_LL();

    // Parameterized Constructor
    Queue_LL(int s);

    // Destructor
    ~Queue_LL();

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
Queue_LL<T>::Queue_LL() {
    front = NULL;
    rear = NULL;
}

template <class T>
Queue_LL<T>::~Queue_LL() {
    Node<T>* p = front;
    while (front) {
        front = front->next;
        delete p;
        p = front;
    }
}

//// Helper function to be used in other functions
//template <class T>
//void Array<T>::swap(T* x, T* y) {
//    T temp;
//    temp = *x;
//    *x = *y;
//    *y = temp;
//}

// Helper function to get length of the queue
template <class T>
int Queue_LL<T>::getLength() {
    Node<T>* p = front;
    int len = 0;
    while (p != NULL) {
        len++;
        p = p->next;
    }
    return len;
}

// Function to display the contents of the queue
template <class T>
void Queue_LL<T>::Display() {
    Node<T>* p = front;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

/// Function to enqueue an element into the queue
template <class T>
void Queue_LL<T>::Enqueue(T x) {
    Node<T>* t = new Node<T>;
    if (t == NULL) {
        cout << "Queue is Full. Unable to enqueue!" << endl;
    }
    else {
        t->data = x;
        t->next = NULL;
        if (front == NULL) {
            front = rear = t;
        }
        else {
            rear->next = t;
            rear = t;
        }
        cout << x << " enqueued into the queue!" << endl;
    }
}

// Function to dequeue an element from the queue
template <class T>
T Queue_LL<T>::Dequeue() {
    T x = -1;
    Node<T>* p;
    if (front == NULL) {
        cout << "Queue is Empty. Unable to dequeue!" << endl;
    }
    else {
        p = front;
        front = front->next;
        x = p->data;
        delete p;
    }
    return x;
}

// Function to look an element at a given position in the queue
template <class T>
T Queue_LL<T>::Peek(int pos) {
    T x = -1;
    if (front == NULL) {
        cout << "Queue is Empty. Nothing to peek!" << endl;
        return x;
    }

    if (pos <= 0 || pos > getLength()) {
        cout << "Invalid Position!" << endl;
    }
    else {
        Node<T>* p = front;
        for (int i = 0; i < pos - 1; i++) {
            p = p->next;
        }
        x = p->data;
    }

    return x;
}

// Function to check if the queue is empty
template <class T>
bool Queue_LL<T>::isEmpty() {
    if (front == NULL) {
        return true;
    }
    else {
        return false;
    }
}

// Function to check if the queue is full
template <class T>
bool Queue_LL<T>::isFull() {
    Node<T>* t = new Node<T>;
    if (t == NULL) {
        return true;
    }
    else {
        return false;
    }
}

// Function to find the frontmost element in the queue
template <class T>
T Queue_LL<T>::queueFront() {
    if (!isEmpty()) {
        return front->data;
    }
    else {
        return -1;
    }
}


int main()
{
    Queue_LL<int>* que;

    que = new Queue_LL<int>;

    int choice, position;
    decltype(que->element) x;

    do {
        cout << "\nMain Menu:\tChoose an operation to be performed on the QUEUE\n\n";
        cout << "1. Display\n";
        cout << "2. Enqueue\n";
        cout << "3. Dequeue\n";
        cout << "4. Peek\n";
        cout << "5. Check if the QUEUE is empty\n";
        cout << "6. Check if the QUEUE is full\n";
        cout << "7. Find the frontmost value in the QUEUE\n";
        cout << "8. Exit Menu\n\n";

        cin >> choice;

        switch (choice) {
        case 1: // Displaying the elements of the queue
            cout << "Elements of the queue are: ";
            que->Display();
            break;

        case 2: // Enqueue an element into the queue
            cout << "Please enter an element: ";
            cin >> x;
            que->Enqueue(x);
            break;

        case 3: // Dequeue an element from the queue
            x = que->Dequeue();
            if (x != -1) {
                cout << x << " dequeued from the queue" << endl;
            }
            break;

        case 4: // Looking an element at a given position in the queue
            cout << "Please enter a position: ";
            cin >> position;
            x = que->Peek(position);
            if (x != -1) {
                cout << x << " is present at position " << position << endl;
            }
            break;

        case 5: // Checking if the queue is empty
            if (que->isEmpty()) {
                cout << "QUEUE is empty" << endl;
            }
            else {
                cout << "QUEUE is not empty" << endl;
            }
            break;

        case 6: // Checking if the queue is full
            if (que->isFull()) {
                cout << "QUEUE is full" << endl;
            }
            else {
                cout << "QUEUE is not full" << endl;
            }
            break;

        case 7: // Finding the frontmost element in the QUEUE
            x = que->queueFront();
            if (x != -1) {
                cout << "Frontmost element in the QUEUE: " << x << endl;
            }
            else {
                cout << "QUEUE is empty. No frontmost element" << endl;
            }
            break;

        }

    } while (choice < 8);

    return 0;
}
