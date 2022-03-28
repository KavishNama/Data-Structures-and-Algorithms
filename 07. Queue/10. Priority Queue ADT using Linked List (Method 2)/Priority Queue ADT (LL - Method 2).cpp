#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node<T>* next;

};

template <class T>
class PriorityQueue_LL2 {
private:
    Node<T>* front;
    Node<T>* rear;

    //void swap(T* x, T* y);
    int getLength();

public:
    T element;

    // Default Constructor 
    PriorityQueue_LL2();

    // Destructor
    ~PriorityQueue_LL2();

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
PriorityQueue_LL2<T>::PriorityQueue_LL2() {
    front = NULL;
    rear = NULL;
}

template <class T>
PriorityQueue_LL2<T>::~PriorityQueue_LL2() {
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

// Helper function to get length of the priority queue
template <class T>
int PriorityQueue_LL2<T>::getLength() {
    Node<T>* p = front;
    int len = 0;
    while (p != NULL) {
        len++;
        p = p->next;
    }
    return len;
}

// Function to display the contents of the priority queue
template <class T>
void PriorityQueue_LL2<T>::Display() {
    Node<T>* p = front;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

/// Function to enqueue an element into the priority queue
template <class T>
void PriorityQueue_LL2<T>::Enqueue(T x) {
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
        else if (x > rear->data) {
            rear->next = t;
            rear = t;
        }
        else {
            Node<T>* p = front, * q = NULL;
            while (p != NULL && p->data <= x) {
                q = p;
                p = p->next;
            }
            if (p == front) {
                t->next = front;
                front = t;
            }
            else {
                t->next = q->next;
                q->next = t;
            }
        }
        cout << x << " enqueued into the queue!" << endl;
    }
}

// Function to dequeue an element from the priority queue
template <class T>
T PriorityQueue_LL2<T>::Dequeue() {
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

// Function to look an element at a given position in the priority queue
template <class T>
T PriorityQueue_LL2<T>::Peek(int pos) {
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

// Function to check if the priority queue is empty
template <class T>
bool PriorityQueue_LL2<T>::isEmpty() {
    if (front == NULL) {
        return true;
    }
    else {
        return false;
    }
}

// Function to check if the priority queue is full
template <class T>
bool PriorityQueue_LL2<T>::isFull() {
    Node<T>* t = new Node<T>;
    if (t == NULL) {
        return true;
    }
    else {
        return false;
    }
}

// Function to find the frontmost element in the priority queue
template <class T>
T PriorityQueue_LL2<T>::queueFront() {
    if (!isEmpty()) {
        return front->data;
    }
    else {
        return -1;
    }
}


int main()
{
    PriorityQueue_LL2<int>* que;

    que = new PriorityQueue_LL2<int>;

    int choice, position;
    decltype(que->element) x;

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
            cout << "Elements of the queue are: ";
            que->Display();
            break;

        case 2: // Enqueue an element into the priority queue
            cout << "Please enter an element: ";
            cin >> x;
            que->Enqueue(x);
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
