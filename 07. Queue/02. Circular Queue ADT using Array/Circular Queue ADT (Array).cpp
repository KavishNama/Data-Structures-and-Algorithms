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

    /*


    T Peek(int pos);
    bool isEmpty();
    bool isFull();
    T stackTop();
    */


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
    do {
        cout << A[i] << " ";
        i = (i + 1) % size;
    } while (i != (rear + 1) % size);
    
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




//// Function to look an element at a given position in the stack
//template <class T>
//T Stack_Array<T>::Peek(int pos) {
//    T x = -1;
//    if (top - pos + 1 < 0) {
//        cout << "Invalid Position!" << endl;
//    }
//    else {
//        x = A[top - pos + 1];
//    }
//    return x;
//}
//
//// Function to check if the stack is empty
//template <class T>
//bool Stack_Array<T>::isEmpty() {
//    if (top == -1) {
//        return true;
//    }
//    else {
//        return false;
//    }
//}
//
//// Function to check if the stack is full
//template <class T>
//bool Stack_Array<T>::isFull() {
//    if (top == size - 1) {
//        return true;
//    }
//    else {
//        return false;
//    }
//}
//
//// Function to find the topmost value of stack
//template <class T>
//T Stack_Array<T>::stackTop() {
//    if (!isEmpty()) {
//        return A[top];
//    }
//    else {
//        return -1;
//    }
//}


int main()
{
    CircularQueue_Array<int>* que;
    int s;

    cout << "Please enter the size of the queue: ";
    cin >> s;
    que = new CircularQueue_Array<int>(s);

    int choice, position;
    decltype(que->element) x;
    /*

    char* expression;
    int sizeExp;

    Stack_Array<char>* stkExp;
    Stack_Array<int>* stkExp2;*/

    do {
        cout << "\nMain Menu:\tChoose an operation to be performed on the CIRCULAR QUEUE\n\n";
        cout << "1. Display\n";
        cout << "2. Enqueue\n";
        cout << "3. Dequeue\n";


        /*cout << "4. Peek\n";
        cout << "5. Check if the STACK is empty\n";
        cout << "6. Check if the STACK is full\n";
        cout << "7. Find the topmost value of STACK\n";
        */
        cout << "4. Exit Menu\n\n";

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

            //case 4: // Looking an element at a given position in the stack
            //    cout << "Please enter a position: ";
            //    cin >> position;
            //    x = stk->Peek(position);
            //    if (x != -1) {
            //        cout << x << " is present at position " << position << endl;
            //    }
            //    break;

            //case 5: // Checking if the stack is empty
            //    if (stk->isEmpty()) {
            //        cout << "STACK is empty" << endl;
            //    }
            //    else {
            //        cout << "STACK is not empty" << endl;
            //    }
            //    break;

            //case 6: // Checking if the stack is full
            //    if (stk->isFull()) {
            //        cout << "STACK is full" << endl;
            //    }
            //    else {
            //        cout << "STACK is not full" << endl;
            //    }
            //    break;

            //case 7: // Finding the topmmost element in the stack
            //    x = stk->stackTop();
            //    if (x != -1) {
            //        cout << "Topmost element in the STACK: " << x << endl;
            //    }
            //    else {
            //        cout << "STACK is empty. No topmost element" << endl;
            //    }
            //    break;

        }

    } while (choice < 4);

    return 0;
}
