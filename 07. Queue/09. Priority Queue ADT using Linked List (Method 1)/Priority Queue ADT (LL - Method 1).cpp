#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node* next;

};

template <class T>
class PriorityQueue_LL1 {
private:
    int numPriorities;
    Node<T>** front;
    Node<T>** rear;

    //void swap(T* x, T* y);
    int getLength(int i);

public:
    T element;

    // Default Constructor 
    PriorityQueue_LL1();

    // Parameterized Constructor 
    PriorityQueue_LL1(int p);

    // Destructor
    ~PriorityQueue_LL1();

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
PriorityQueue_LL1<T>::PriorityQueue_LL1() {
    numPriorities = 3;
    front = new Node<T>*[numPriorities];
    rear = new Node<T>*[numPriorities];
    for (int i = 0; i < numPriorities; i++) {
        front[i] = NULL;
        rear[i] = NULL;
    }
}

template <class T>
PriorityQueue_LL1<T>::PriorityQueue_LL1(int p) {
    numPriorities = p;
    front = new Node<T>*[numPriorities];
    rear = new Node<T>*[numPriorities];
    for (int i = 0; i < numPriorities; i++) {
        front[i] = NULL;
        rear[i] = NULL;
    }
}

template <class T>
PriorityQueue_LL1<T>::~PriorityQueue_LL1() {
    for (int i = 0; i < numPriorities; i++) {
        Node<T>* p = front[i];
        while (p) {
            front[i] = front[i]->next;
            delete p;
            p = front[i];
        }
    }
    delete[] front;
    delete[] rear;

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
int PriorityQueue_LL1<T>::getLength(int i) {
    Node<T>* p = front[i];
    int len = 0;
    while (p != NULL) {
        len++;
        p = p->next;
    }
    return len;
}

// Function to display the contents of the priority queue
template <class T>
void PriorityQueue_LL1<T>::Display() {
    for (int i = 0; i < numPriorities; i++) {
        cout << "Priority " << i << " Queue: ";
        Node<T>* p = front[i];
        while (p) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    cout << endl;
}

/// Function to enqueue an element into the priority queue
template <class T>
void PriorityQueue_LL1<T>::Enqueue(T x, int p) {
    Node<T>* t = new Node<T>;
    if (t == NULL) {
        cout << "Priority Queue " << p << " is Full. Unable to enqueue!" << endl;
    }
    else {
        t->data = x;
        t->next = NULL;
        if (front[p] == NULL) {
            front[p] = t;
            rear[p] = t;
        }
        else {
            rear[p]->next = t;
            rear[p] = t;
        }
        cout << x << " enqueued into Priority Queue " << p << "!" << endl;
    }
}

// Function to dequeue an element from the priority queue
template <class T>
T PriorityQueue_LL1<T>::Dequeue() {
    T x = -1;
    for (int i = 0; i < numPriorities; i++) {
        if ((front[i] == NULL) && (i != numPriorities - 1)) {
            continue;
        }
        else if ((front[i] == NULL) && (i == numPriorities - 1)) {
            cout << "Priority Queue is Empty. Unable to dequeue!" << endl;
        }
        else {
            Node<T>* p = front[i];
            front[i] = front[i]->next;
            x = p->data;
            delete p;
            break;
        }
    }
    return x;
}

// Function to look an element at a given position in the priority queue
template <class T>
T PriorityQueue_LL1<T>::Peek(int pos) {
    T x = -1;
    int totalElements = 0;
    for (int i = 0; i < numPriorities; i++) {
        totalElements += getLength(i);
    }

    if (pos <= 0 || pos > totalElements) {
        cout << "Invalid Position!" << endl;
    }
    else {
        for (int i = 0; i < numPriorities; i++) {
            if (pos > getLength(i)) {
                pos -= getLength(i);
                continue;
            }
            else {
                Node<T>* p = front[i];
                for (int i = 0; i < pos - 1; i++) {
                    p = p->next;
                }
                x = p->data;
                break;
            }
        }
    }

    return x;
}

// Function to check if the priority queue is empty
template <class T>
bool PriorityQueue_LL1<T>::isEmpty() {
    for (int i = 0; i < numPriorities; i++) {
        if ((front[i] == NULL) && (i != numPriorities - 1)) {
            continue;
        }
        else if ((front[i] == NULL) && (i == numPriorities - 1)) {
            return true;
        }
        else {
            return false;
        }
    }
}

// Function to check if the priority queue is full
template <class T>
bool PriorityQueue_LL1<T>::isFull() {
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
T PriorityQueue_LL1<T>::queueFront() {
    for (int i = 0; i < numPriorities; i++) {
        if ((front[i] == NULL) && (i != numPriorities - 1)) {
            continue;
        }
        else if ((front[i] == NULL) && (i == numPriorities - 1)) {
            return -1;
        }
        else {
            return front[i]->data;
        }
    }
}


int main()
{
    PriorityQueue_LL1<char>* que;

    int p;
    cout << "Please enter the number of priorities: ";
    cin >> p;

    que = new PriorityQueue_LL1<char>(p);

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
