#include <iostream>
using namespace std;

template <class T>
class Queue_Array {
private:
    int size;
    int front;
    int rear;
    T* A;

    //void swap(T* x, T* y);

public:
    T element;

    // Default Constructor 
    Queue_Array();

    // Parameterized Constructor
    Queue_Array(int s);

    // Destructor
    ~Queue_Array();

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
Queue_Array<T>::Queue_Array() {
    size = 10;
    front = -1;
    rear = -1;
    A = new T[size];
}

template <class T>
Queue_Array<T>::Queue_Array(int s) {
    size = s;
    front = -1;
    rear = -1;
    A = new T[size];
}

template <class T>
Queue_Array<T>::~Queue_Array() {
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

// Function to display the contents of the queue
template <class T>
void Queue_Array<T>::Display() {
    for (int i = front + 1; i <= rear; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

// Function to enqueue an element into the queue
template <class T>
void Queue_Array<T>::Enqueue(T x) {
    if (rear == size - 1) {
        cout << "Queue is Full. Unable to enqueue!" << endl;
    }
    else {
        rear++;
        A[rear] = x;
        cout << x << " enqueued into the queue!" << endl;
    }
}

// Function to dequeue an element from the queue
template <class T>
T Queue_Array<T>::Dequeue() {
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

// Function to look an element at a given position in the queue
template <class T>
T Queue_Array<T>::Peek(int pos) {
    T x = -1;
    if (pos <= 0 || pos > rear - front) {
        cout << "Invalid Position!" << endl;
    }
    else {
        x = A[front+pos];
    }

    return x;
}

// Function to check if the queue is empty
template <class T>
bool Queue_Array<T>::isEmpty() {
    if (front == rear) {
        return true;
    }
    else {
        return false;
    }
}

// Function to check if the queue is full
template <class T>
bool Queue_Array<T>::isFull() {
    if (rear == size - 1) {
        return true;
    }
    else {
        return false;
    }
}

// Function to find the frontmost element in the queue
template <class T>
T Queue_Array<T>::queueFront() {
    if (!isEmpty()) {
        return A[front+1];
    }
    else {
        return -1;
    }
}


int main()
{
    Queue_Array<int>* que;
    int s;

    cout << "Please enter the size of the queue: ";
    cin >> s;
    que = new Queue_Array<int>(s);

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
