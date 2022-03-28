#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node<T>* next;

};

template <class T>
class Stack_LL {
private:
    Node<T>* top;

public:
    T element;

    // Default Constructor 
    Stack_LL();

    // Destructor
    ~Stack_LL();

    // Function prototypes
    void Display();
    void reverseDisplay();
    void reverseDisplayRecursive(Node<T>* t);
    void Push(T x);
    T Pop();
    T Peek(int pos);
    bool isEmpty();
    bool isFull();
    int getLength();    

};

template <class T>
Stack_LL<T>::Stack_LL() {
    top = NULL;
}

template <class T>
Stack_LL<T>::~Stack_LL() {
    Node<T>* p = top;
    while (top) {
        top = top->next;
        delete p;
        p = top;
    }
}

// Helper function to get length of the stack
template <class T>
int Stack_LL<T>::getLength() {
    Node<T>* t = top;
    int len = 0;
    while (t) {
        len++;
        t = t->next;
    }
    return len;
}

// Function to display the contents of the stack
template <class T>
void Stack_LL<T>::Display() {
    Node<T>* t = top;
    while (t) {
        cout << t->data << " ";
        t = t->next;
    }
}

// Function to display the contents of the stack in reverse order - Bottom to Top
template <class T>
void Stack_LL<T>::reverseDisplay() {
    reverseDisplayRecursive(top);
}
template <class T>
void Stack_LL<T>::reverseDisplayRecursive(Node<T>* t) {
    if (t == NULL)
        return;

    reverseDisplayRecursive(t->next);
    cout << t->data << " ";
}

// Function to push an element onto the stack
template <class T>
void Stack_LL<T>::Push(T x) {
    Node<T>* t = new Node<T>;
    if (t == NULL) {
        cout << "Stack Overflow. Unable to push!" << endl;
    }
    else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

// Function to pop an element from the stack
template <class T>
T Stack_LL<T>::Pop() {
    Node<T>* t;
    T x = -1;
    if (top == NULL) {
        cout << "Stack Underflow. Unable to pop!" << endl;
    }
    else {
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}

// Function to look an element at a given position in the stack
template <class T>
T Stack_LL<T>::Peek(int pos) {
    Node<T>* t = top;
    for (int i = 0; t != NULL && i < pos - 1; i++) {
        t = t->next;
    }
    if (t != NULL) {
        return t->data;
    }
    else {
        cout << "Invalid Position!" << endl;
    }
    return -1;
}

// Function to check if the stack is empty
template <class T>
bool Stack_LL<T>::isEmpty() {
    if (top == NULL) {
        return true;
    }
    else {
        return false;
    }
}

// Function to check if the stack is full
template <class T>
bool Stack_LL<T>::isFull() {
    Node<T>* t = new Node<T>;
    bool result;
    if (t == NULL) {
        result = true;
    }
    else {
        result = false;
    }
    delete t;
    return result;
}


template <class T>
class Queue_TwoStacks_LL {
private:
    Stack_LL<T>* stk1;
    Stack_LL<T>* stk2;

public:
    T element;

    // Default Constructor 
    Queue_TwoStacks_LL();

    // Destructor
    ~Queue_TwoStacks_LL();

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
Queue_TwoStacks_LL<T>::Queue_TwoStacks_LL() {
    stk1 = new Stack_LL<T>;
    stk2 = new Stack_LL<T>;
}

template <class T>
Queue_TwoStacks_LL<T>::~Queue_TwoStacks_LL() {
    delete[]stk1;
    delete[]stk2;
}

// Function to display the contents of the queue
template <class T>
void Queue_TwoStacks_LL<T>::Display() {
    if (!stk2->isEmpty()) {
        stk2->Display();
        if (!stk1->isEmpty()) {
            stk1->reverseDisplay();
        }
    }
    else {
        if (!stk1->isEmpty()) {
            stk1->reverseDisplay();
        }
    }
    cout << endl;
}

/// Function to enqueue an element into the queue
template <class T>
void Queue_TwoStacks_LL<T>::Enqueue(T x) {
    if (isFull()) {
        cout << "Queue is Full. Unable to enqueue!" << endl;
    }
    else {
        stk1->Push(x);
        cout << x << " enqueued into the queue!" << endl;
    }
}

// Function to dequeue an element from the queue
template <class T>
T Queue_TwoStacks_LL<T>::Dequeue() {
    if (stk2->isEmpty()) {
        if (stk1->isEmpty()) {
            cout << "Queue is Empty. Unable to dequeue!" << endl;
            return -1;
        }
        else {
            while (!stk1->isEmpty()) {
                stk2->Push(stk1->Pop());
            }
        }
    }
    return stk2->Pop();
}

// Function to look an element at a given position in the queue
template <class T>
T Queue_TwoStacks_LL<T>::Peek(int pos) {
    T x = -1;
    if (stk2->isEmpty()) {
        if (pos <= 0 || pos > stk1->getLength()) {
            cout << "Invalid Position!" << endl;
        }
        else {
            x = stk1->Peek(stk1->getLength() - pos + 1);
        }
    }
    else {
        if (pos <= 0 || pos > stk1->getLength() + stk2->getLength()) {
            cout << "Invalid Position!" << endl;
        }
        else if (pos >= 1 && pos <= stk2->getLength()) {
            x = stk2->Peek(pos);
        }
        else if (pos > stk2->getLength() && pos <= stk1->getLength() + stk2->getLength()) {
            x = stk1->Peek(stk1->getLength() - pos + stk2->getLength() + 1);
        }
    }
    return x;
}

// Function to check if the queue is empty
template <class T>
bool Queue_TwoStacks_LL<T>::isEmpty() {
    if (stk2->isEmpty()) {
        if (stk1->isEmpty()) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

// Function to check if the queue is full
template <class T>
bool Queue_TwoStacks_LL<T>::isFull() {
    return stk1->isFull();
}

// Function to find the frontmost element in the queue
template <class T>
T Queue_TwoStacks_LL<T>::queueFront() {
    if (stk2->isEmpty()) {
        if (stk1->isEmpty()) {
            return -1;
        }
        else {
            return stk1->Peek(stk1->getLength());
        }
    }
    else {
        return stk2->Peek(1);
    }
}


int main()
{
    Queue_TwoStacks_LL<int>* que;

    que = new Queue_TwoStacks_LL<int>;

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
