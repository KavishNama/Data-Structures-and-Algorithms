#include <iostream>
using namespace std;

template <class T>
class Stack_Array {
private:
    int size;
    int top;
    T* A;

    //void swap(T* x, T* y);

public:
    T element;

    // Default Constructor 
    Stack_Array();

    // Parameterized Constructor
    Stack_Array(int s);

    // Destructor
    ~Stack_Array();

    // Function prototypes
    void Display();
    void reverseDisplay();
    void Push(T x);
    T Pop();
    T Peek(int pos);
    bool isEmpty();
    bool isFull();
    int getTop();

};

template <class T>
Stack_Array<T>::Stack_Array() {
    size = 10;
    top = -1;
    A = new T[size];
}

template <class T>
Stack_Array<T>::Stack_Array(int s) {
    size = s;
    top = -1;
    A = new T[size];
}

template <class T>
Stack_Array<T>::~Stack_Array() {
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

// Function to display the contents of the stack
template <class T>
void Stack_Array<T>::Display() {
    for (int i = top; i >= 0; i--) {
        cout << A[i] << " ";
    }
}

// Function to display the contents of the stack in reverse order - Bottom to Top
template <class T>
void Stack_Array<T>::reverseDisplay() {
    for (int i = 0; i <= top; i++) {
        cout << A[i] << " ";
    }
}

// Function to push an element onto the stack
template <class T>
void Stack_Array<T>::Push(T x) {
    if (top == size - 1) {
        cout << "Stack Overflow. Unable to push!" << endl;
    }
    else {
        top++;
        A[top] = x;
    }
}

// Function to pop an element from the stack
template <class T>
T Stack_Array<T>::Pop() {
    T x = -1;
    if (top == -1) {
        cout << "Stack Underflow. Unable to pop!" << endl;
    }
    else {
        x = A[top];
        top--;
    }
    return x;
}

// Function to look an element at a given position in the stack
template <class T>
T Stack_Array<T>::Peek(int pos) {
    T x = -1;
    if (top - pos + 1 < 0) {
        cout << "Invalid Position!" << endl;
    }
    else {
        x = A[top - pos + 1];
    }
    return x;
}

// Function to check if the stack is empty
template <class T>
bool Stack_Array<T>::isEmpty() {
    if (top == -1) {
        return true;
    }
    else {
        return false;
    }
}

// Function to check if the stack is full
template <class T>
bool Stack_Array<T>::isFull() {
    if (top == size - 1) {
        return true;
    }
    else {
        return false;
    }
}

// Function to get the number of elements in the stack
template <class T>
int Stack_Array<T>::stackTop() {
    if (!isEmpty()) {
        return A[top];
    }
    else {
        return -1;
    }
}

template <class T>
class Queue_TwoStacks_Array {
private:
    int size;
    Stack_Array<T>* stk1;
    Stack_Array<T>* stk2;

    //void swap(T* x, T* y);

public:
    T element;

    // Default Constructor 
    Queue_TwoStacks_Array();

    // Parameterized Constructor
    Queue_TwoStacks_Array(int s);

    // Destructor
    ~Queue_TwoStacks_Array();

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
Queue_TwoStacks_Array<T>::Queue_TwoStacks_Array() {
    size = 10;
    stk1 = new Stack_Array<T>(size);
    stk2 = new Stack_Array<T>(size);
}

template <class T>
Queue_TwoStacks_Array<T>::Queue_TwoStacks_Array(int s) {
    size = s;
    stk1 = new Stack_Array<T>(size);
    stk2 = new Stack_Array<T>(size);
}

template <class T>
Queue_TwoStacks_Array<T>::~Queue_TwoStacks_Array() {
    delete[]stk1;
    delete[]stk2;
}

//// Helper function to be used in other functions
//template <class T>
//void Array<T>::swap(T* x, T* y) {
//    T temp;
//    temp = *x;
//    *x = *y;
//    *y = temp;
//}

// Function to display the contents of the queue
template <class T>
void Queue_TwoStacks_Array<T>::Display() {
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

// Function to enqueue an element into the queue
template <class T>
void Queue_TwoStacks_Array<T>::Enqueue(T x) {
    if (stk1->isFull()) {
        cout << "Queue is Full. Unable to enqueue!" << endl;
    }
    else {
        stk1->Push(x);
        cout << x << " enqueued into the queue!" << endl;
    }
}

// Function to dequeue an element from the queue
template <class T>
T Queue_TwoStacks_Array<T>::Dequeue() {
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
T Queue_TwoStacks_Array<T>::Peek(int pos) {
    T x = -1;
    if (stk2->isEmpty()) {
        if (pos <= 0 || pos > stk1->top) {
            cout << "Invalid Position!" << endl;
        }
    }

    if (pos <= 0 || pos > rear - front) {
        cout << "Invalid Position!" << endl;
    }
    else {
        x = A[front + pos];
    }

    return x;
}

//// Function to check if the queue is empty
//template <class T>
//bool Queue_Array<T>::isEmpty() {
//    if (front == rear) {
//        return true;
//    }
//    else {
//        return false;
//    }
//}
//
//// Function to check if the queue is full
//template <class T>
//bool Queue_Array<T>::isFull() {
//    if (rear == size - 1) {
//        return true;
//    }
//    else {
//        return false;
//    }
//}
//
//// Function to find the frontmost element in the queue
//template <class T>
//T Queue_Array<T>::queueFront() {
//    if (!isEmpty()) {
//        return A[front + 1];
//    }
//    else {
//        return -1;
//    }
//}


int main()
{
    Queue_TwoStacks_Array<int>* que;
    int s;

    cout << "Please enter the size of the queue: ";
    cin >> s;
    que = new Queue_TwoStacks_Array<int>(s);

    int choice, position;
    decltype(que->element) x;

    do {
        cout << "\nMain Menu:\tChoose an operation to be performed on the QUEUE\n\n";
        cout << "1. Display\n";
        cout << "2. Enqueue\n";
        cout << "3. Dequeue\n";
        /*cout << "4. Peek\n";
        cout << "5. Check if the QUEUE is empty\n";
        cout << "6. Check if the QUEUE is full\n";
        cout << "7. Find the frontmost value in the QUEUE\n";*/
        cout << "4. Exit Menu\n\n";

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

        //case 4: // Looking an element at a given position in the queue
        //    cout << "Please enter a position: ";
        //    cin >> position;
        //    x = que->Peek(position);
        //    if (x != -1) {
        //        cout << x << " is present at position " << position << endl;
        //    }
        //    break;

        //case 5: // Checking if the queue is empty
        //    if (que->isEmpty()) {
        //        cout << "QUEUE is empty" << endl;
        //    }
        //    else {
        //        cout << "QUEUE is not empty" << endl;
        //    }
        //    break;

        //case 6: // Checking if the queue is full
        //    if (que->isFull()) {
        //        cout << "QUEUE is full" << endl;
        //    }
        //    else {
        //        cout << "QUEUE is not full" << endl;
        //    }
        //    break;

        //case 7: // Finding the frontmost element in the QUEUE
        //    x = que->queueFront();
        //    if (x != -1) {
        //        cout << "Frontmost element in the QUEUE: " << x << endl;
        //    }
        //    else {
        //        cout << "QUEUE is empty. No frontmost element" << endl;
        //    }
        //    break;

        }

    } while (choice < 4);

    return 0;
}