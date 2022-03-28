#include <iostream>
using namespace std;

template <class T>
class treeNode {
public:
    treeNode<T>* lchild;
    T data;
    treeNode<T>* rchild;

};

template <class T>
class queueNode {
public:
    treeNode<T>* data;
    queueNode<T>* next;

};

template <class T>
class Queue {
private:
    queueNode<T>* front;
    queueNode<T>* rear;

    int getLength();

public:
    T element;

    // Default Constructor 
    Queue();

    // Destructor
    ~Queue();

    // Function prototypes
    void Display();
    void Enqueue(treeNode<T>* x);
    treeNode<T>* Dequeue();
    bool isEmpty();
    bool isFull();

};

template <class T>
Queue<T>::Queue() {
    front = NULL;
    rear = NULL;
}

template <class T>
Queue<T>::~Queue() {
    queueNode<T>* p = front;
    while (front) {
        front = front->next;
        delete p;
        p = front;
    }
}


// Helper function to get length of the queue
template <class T>
int Queue<T>::getLength() {
    queueNode<T>* p = front;
    int len = 0;
    while (p != NULL) {
        len++;
        p = p->next;
    }
    return len;
}

// Function to display the contents of the queue
template <class T>
void Queue<T>::Display() {
    queueNode<T>* p = front;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

/// Function to enqueue an element into the queue
template <class T>
void Queue<T>::Enqueue(treeNode<T>* x) {
    queueNode<T>* t = new queueNode<T>;
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
    }
}

// Function to dequeue an element from the queue
template <class T>
treeNode<T>* Queue<T>::Dequeue() {
    treeNode<T>* x = NULL;
    queueNode<T>* p;
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

// Function to check if the queue is empty
template <class T>
bool Queue<T>::isEmpty() {
    if (front == NULL) {
        return true;
    }
    else {
        return false;
    }
}

// Function to check if the queue is full
template <class T>
bool Queue<T>::isFull() {
    queueNode<T>* t = new queueNode<T>;
    if (t == NULL) {
        return true;
    }
    else {
        return false;
    }
}


template <class T>
class BinaryTree_Queue_LL {
private:
    treeNode<T>* root;

public:
    T element;

    // Default Constructor 
    BinaryTree_Queue_LL();

    // Parameterized Constructor
    BinaryTree_Queue_LL(T x);

    // Destructor
    ~BinaryTree_Queue_LL();
    void destroyRecursive(treeNode<T>* p);

    // Function prototypes
    void preOrder();
    void preOrder(treeNode<T>* p);
    void inOrder();
    void inOrder(treeNode<T>* p);
    void postOrder();
    void postOrder(treeNode<T>* p);
    void levelOrder();
    void levelOrder(treeNode<T>* p);
    int getHeight();
    int getHeight(treeNode<T>* p);

};

template <class T>
BinaryTree_Queue_LL<T>::BinaryTree_Queue_LL() {
    root = NULL;
    Queue<T>* que = new Queue<T>();
}

template <class T>
BinaryTree_Queue_LL<T>::BinaryTree_Queue_LL(T x) {
    Queue<T>* que = new Queue<T>();

    root = new treeNode<T>;
    root->data = x;
    root->lchild = root->rchild = NULL;
    que->Enqueue(root);

    treeNode<T>* p, * t;

    while (!que->isEmpty()) {
        p = que->Dequeue();
        cout << "Please enter the left child of " << p->data << ": ";
        cin >> x;
        if (x != -1) {
            t = new treeNode<T>;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            que->Enqueue(t);
        }
        cout << "Please enter the right child of " << p->data << ": ";
        cin >> x;
        if (x != -1) {
            t = new treeNode<T>;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            que->Enqueue(t);
        }
    }
}

template <class T>
BinaryTree_Queue_LL<T>::~BinaryTree_Queue_LL() {
    destroyRecursive(root);
}

template <class T>
void BinaryTree_Queue_LL<T>::destroyRecursive(treeNode<T>* p) {
    if (p != NULL) {
        destroyRecursive(p->lchild);
        destroyRecursive(p->rchild);
        delete p;
    }
}


// Function to display the contents of the tree in Preorder Traversal Fashion
template <class T>
void BinaryTree_Queue_LL<T>::preOrder() {
    preOrder(root);
    cout << endl;
}
template <class T>
void BinaryTree_Queue_LL<T>::preOrder(treeNode<T>* p) {
    if (p != NULL) {
        cout << p->data << " ";
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}

// Function to display the contents of the tree in Inorder Traversal Fashion
template <class T>
void BinaryTree_Queue_LL<T>::inOrder() {
    inOrder(root);
    cout << endl;
}
template <class T>
void BinaryTree_Queue_LL<T>::inOrder(treeNode<T>* p) {
    if (p != NULL) {
        inOrder(p->lchild);
        cout << p->data << " ";
        inOrder(p->rchild);
    }
}

// Function to display the contents of the tree in Postorder Traversal Fashion
template <class T>
void BinaryTree_Queue_LL<T>::postOrder() {
    postOrder(root);
    cout << endl;
}
template <class T>
void BinaryTree_Queue_LL<T>::postOrder(treeNode<T>* p) {
    if (p != NULL) {
        postOrder(p->lchild);
        postOrder(p->rchild);
        cout << p->data << " ";
    }
}

// Function to display the contents of the tree in Levelorder Traversal Fashion
template <class T>
void BinaryTree_Queue_LL<T>::levelOrder() {
    levelOrder(root);
    cout << endl;
}
template <class T>
void BinaryTree_Queue_LL<T>::levelOrder(treeNode<T>* p) {
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
int BinaryTree_Queue_LL<T>::getHeight() {
    return getHeight(root);
}
template <class T>
int BinaryTree_Queue_LL<T>::getHeight(treeNode<T>* p) {
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
    BinaryTree_Queue_LL<int>* btree;

    decltype(btree->element) x;
    cout << "Please enter the root value of the tree: ";
    cin >> x;

    btree = new BinaryTree_Queue_LL<int>(x);

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
