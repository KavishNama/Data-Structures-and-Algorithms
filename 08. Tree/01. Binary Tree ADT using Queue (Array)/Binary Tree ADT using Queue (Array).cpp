#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    Node<T>* lchild;
    T data;
    Node<T>* rchild;

};

template <class T>
class Queue {
private:
    int size;
    int front;
    int rear;
    Node<T>** A;

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
    void Enqueue(Node<T>* x);
    Node<T>* Dequeue();
    bool isEmpty();
    bool isFull();

};

template <class T>
Queue<T>::Queue() {
    size = 100;
    front = 0;
    rear = 0;
    A = new Node<T>*[size];
}

template <class T>
Queue<T>::Queue(int s) {
    size = s;
    front = 0;
    rear = 0;
    A = new Node<T>*[size];
}

template <class T>
Queue<T>::~Queue() {
    delete[]A;
}

// Function to display the contents of the queue
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

// Function to enqueue an element into the queue
template <class T>
void Queue<T>::Enqueue(Node<T>* x) {
    if ((rear + 1) % size == front) {
        cout << "Queue is Full. Unable to enqueue!" << endl;
    }

    else {
        rear = (rear + 1) % size;
        A[rear] = x;
    }
}

// Function to dequeue an element from the queue
template <class T>
Node<T>* Queue<T>::Dequeue() {
    Node<T>* x = NULL;
    if (front == rear) {
        cout << "Queue is Empty. Unable to dequeue!" << endl;
    }
    else {
        front = (front + 1) % size;
        x = A[front];
    }
    return x;
}

// Function to check if the queue is empty
template <class T>
bool Queue<T>::isEmpty() {
    if (front == rear) {
        return true;
    }
    else {
        return false;
    }
}

// Function to check if the queue is full
template <class T>
bool Queue<T>::isFull() {
    if ((rear + 1) % size == front) {
        return true;
    }
    else {
        return false;
    }
}


template <class T>
class BinaryTree_Queue_Array {
private:
    Node<T>* root;

public:
    T element;

    // Default Constructor 
    BinaryTree_Queue_Array();

    // Parameterized Constructor
    BinaryTree_Queue_Array(int s, T x);

    // Destructor
    ~BinaryTree_Queue_Array();
    void destroyRecursive(Node<T>* p);

    // Function prototypes
    void preOrder();
    void preOrder(Node<T>* p);
    void inOrder();
    void inOrder(Node<T>* p);
    void postOrder();
    void postOrder(Node<T>* p);
    void levelOrder();
    void levelOrder(Node<T>* p);
    int getHeight();
    int getHeight(Node<T>* p);

};

template <class T>
BinaryTree_Queue_Array<T>::BinaryTree_Queue_Array() {
    root = NULL;
    Queue<T>* que = new Queue<T>();
}

template <class T>
BinaryTree_Queue_Array<T>::BinaryTree_Queue_Array(int s, T x) {
    Queue<T>* que = new Queue<T>(s);

    root = new Node<T>;
    root->data = x;
    root->lchild = root->rchild = NULL;
    que->Enqueue(root);

    Node<T>* p, * t;

    while (!que->isEmpty()) {
        p = que->Dequeue();
        cout << "Please enter the left child of " << p->data << ": ";
        cin >> x;
        if (x != -1) {
            t = new Node<T>;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            que->Enqueue(t);
        }
        cout << "Please enter the right child of " << p->data << ": ";
        cin >> x;
        if (x != -1) {
            t = new Node<T>;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            que->Enqueue(t);
        }
    }
}

template <class T>
BinaryTree_Queue_Array<T>::~BinaryTree_Queue_Array() {
    destroyRecursive(root);
}

template <class T>
void BinaryTree_Queue_Array<T>::destroyRecursive(Node<T>* p) {
    if (p != NULL) {
        destroyRecursive(p->lchild);
        destroyRecursive(p->rchild);
        delete p;
    }
}

// Function to display the contents of the tree in Preorder Traversal Fashion
template <class T>
void BinaryTree_Queue_Array<T>::preOrder() {
    preOrder(root);
    cout << endl;
}
template <class T>
void BinaryTree_Queue_Array<T>::preOrder(Node<T> *p) {
    if (p != NULL) {
        cout << p->data << " ";
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}

// Function to display the contents of the tree in Inorder Traversal Fashion
template <class T>
void BinaryTree_Queue_Array<T>::inOrder() {
    inOrder(root);
    cout << endl;
}
template <class T>
void BinaryTree_Queue_Array<T>::inOrder(Node<T>* p) {
    if (p != NULL) {
        inOrder(p->lchild);
        cout << p->data << " ";
        inOrder(p->rchild);
    }
}

// Function to display the contents of the tree in Postorder Traversal Fashion
template <class T>
void BinaryTree_Queue_Array<T>::postOrder() {
    postOrder(root);
    cout << endl;
}
template <class T>
void BinaryTree_Queue_Array<T>::postOrder(Node<T>* p) {
    if (p != NULL) {
        postOrder(p->lchild);
        postOrder(p->rchild);
        cout << p->data << " ";
    }
}

// Function to display the contents of the tree in Levelorder Traversal Fashion
template <class T>
void BinaryTree_Queue_Array<T>::levelOrder() {
    levelOrder(root);
    cout << endl;
}
template <class T>
void BinaryTree_Queue_Array<T>::levelOrder(Node<T>* p) {
    Queue<T>* que1 = new Queue<T>();
    cout << p->data << " ";
    que1->Enqueue(p);

    while (!que1->isEmpty()) {
        p = que1->Dequeue();
        if (p->lchild != NULL) {
            cout << p->lchild->data << " ";
            que1->Enqueue(p->lchild);
        }
        if (p->rchild != NULL) {
            cout << p->rchild->data << " ";
            que1->Enqueue(p->rchild);
        }
    }
}

// Function to find the height of the tree
template <class T>
int BinaryTree_Queue_Array<T>::getHeight() {
    return getHeight(root);
}
template <class T>
int BinaryTree_Queue_Array<T>::getHeight(Node<T>* p) {
    int x = 0, y = 0;
    if (p == NULL) {
        return 0;
    }
    x = getHeight(p->lchild);
    y = getHeight(p->rchild);

    if (x > y) {
        return x + 1;
    }
    else {
        return y + 1;
    }
}


int main()
{
    BinaryTree_Queue_Array<int>* btree;
    int s;
    cout << "Please enter the size of the tree: ";
    cin >> s;

    decltype(btree->element) x;
    cout << "Please enter the root value of the tree: ";
    cin >> x;

    btree = new BinaryTree_Queue_Array<int>(s, x);

    int choice;

    do {
        cout << "\nMain Menu:\tChoose an operation to be performed on the TREE\n\n";
        cout << "1. Display in Preorder Traversal Fashion\n";
        cout << "2. Display in Inorder Traversal Fashion\n";
        cout << "3. Display in Postorder Traversal Fashion\n";
        cout << "4. Display in Levelorder Traversal Fashion\n";
        cout << "5. Find Height\n";
        cout << "6. Exit Menu\n\n";

        cin >> choice;

        switch (choice) {
        case 1: // Displaying the contents of the tree in Preorder Traversal Fashion
            cout << "Preorder Traversal: ";
            btree->preOrder();
            break;

        case 2: // Displaying the contents of the tree in Inorder Traversal Fashion
            cout << "Inorder Traversal: ";
            btree->inOrder();
            break;

        case 3: // Displaying the contents of the tree in Postorder Traversal Fashion
            cout << "Postorder Traversal: ";
            btree->postOrder();
            break;

        case 4: // Displaying the contents of the tree in Levelorder Traversal Fashion
            cout << "Levelorder Traversal: ";
            btree->levelOrder();
            break;

        case 5: // Find the height of the tree
            cout << "The height of the tree is: ";
            cout << btree->getHeight();
            break;

        }

    } while (choice < 6);

    return 0;
}
