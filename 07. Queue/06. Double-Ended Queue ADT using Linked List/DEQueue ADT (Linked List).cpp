#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node* next;

};

template <class T>
class DEQueue_LL {
private:
    Node<T>* front;
    Node<T>* rear;

    //void swap(T* x, T* y);
    int getLength();

public:
    T element;

    // Default Constructor 
    DEQueue_LL();

    // Destructor
    ~DEQueue_LL();

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
DEQueue_LL<T>::DEQueue_LL() {
    front = NULL;
    rear = NULL;
}

template <class T>
DEQueue_LL<T>::~DEQueue_LL() {
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

// Helper function to get length of the DEQueue
template <class T>
int DEQueue_LL<T>::getLength() {
    Node<T>* p = front;
    int len = 0;
    while (p != NULL) {
        len++;
        p = p->next;
    }
    return len;
}

// Function to display the contents of the DEQueue
template <class T>
void DEQueue_LL<T>::Display() {
    Node<T>* p = front;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// Function to enqueue an element into the DEQueue from front end
template <class T>
void DEQueue_LL<T>::frontEnqueue(T x) {
    Node<T>* t = new Node<T>;
    if (t == NULL) {
        cout << "Queue is Full. Unable to enqueue!" << endl;
    }
    else {
        t->data = x;
        
        if (front == NULL) {
            t->next = NULL;
            front = rear = t;
        }
        else {
            t->next = front;
            front = t;
        }
        cout << x << " enqueued into the queue!" << endl;
    }
}

// Function to enqueue an element into the DEQueue from rear end
template <class T>
void DEQueue_LL<T>::rearEnqueue(T x) {
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

// Function to dequeue an element from the DEQueue from front end
template <class T>
T DEQueue_LL<T>::frontDequeue() {
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

// Function to dequeue an element from the DEQueue from rear end
template <class T>
T DEQueue_LL<T>::rearDequeue() {
    T x = -1;
    Node<T>* p, * q = NULL;
    if (front == NULL) {
        cout << "Queue is Empty. Unable to dequeue!" << endl;
    }
    else {
        p = front;
        while (p != rear) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        rear = q;
        delete p;
    }
    return x;
}

// Function to look an element at a given position in the DEQueue
template <class T>
T DEQueue_LL<T>::Peek(int pos) {
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

// Function to check if the DEQueue is empty
template <class T>
bool DEQueue_LL<T>::isEmpty() {
    if (front == NULL) {
        return true;
    }
    else {
        return false;
    }
}

// Function to check if the DEQueue is full
template <class T>
bool DEQueue_LL<T>::isFull() {
    Node<T>* t = new Node<T>;
    if (t == NULL) {
        return true;
    }
    else {
        return false;
    }
}

// Function to find the frontmost element in the DEQueue
template <class T>
T DEQueue_LL<T>::queueFront() {
    if (!isEmpty()) {
        return front->data;
    }
    else {
        return -1;
    }
}


int main()
{
    DEQueue_LL<int>* que;

    que = new DEQueue_LL<int>;

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
