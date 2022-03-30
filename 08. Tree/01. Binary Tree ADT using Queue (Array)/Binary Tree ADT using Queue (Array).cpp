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
class Stack {
private:
    int size;
    int top;
    Node<T>** A;

public:
    T element;

    // Default Constructor 
    Stack();

    // Parameterized Constructor
    Stack(int s);

    // Destructor
    ~Stack();

    // Function prototypes
    void Display();
    void Push(Node<T>* x);
    Node<T>* Pop();
    bool isEmpty();
    bool isFull();

};

template <class T>
Stack<T>::Stack() {
    size = 10;
    top = -1;
    A = new Node<T>*[size];
}

template <class T>
Stack<T>::Stack(int s) {
    size = s;
    top = -1;
    A = new Node<T>*[size];
}

template <class T>
Stack<T>::~Stack() {
    delete[]A;
}

// Function to display the contents of the stack
template <class T>
void Stack<T>::Display() {
    for (int i = top; i >= 0; i--) {
        cout << A[i] << " ";
    }
    cout << endl;
}

// Function to push an element onto the stack
template <class T>
void Stack<T>::Push(Node<T>* x) {
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
Node<T>* Stack<T>::Pop() {
    Node<T>* x = NULL;
    if (top == -1) {
        cout << "Stack Underflow. Unable to pop!" << endl;
    }
    else {
        x = A[top];
        top--;
    }
    return x;
}

// Function to check if the stack is empty
template <class T>
bool Stack<T>::isEmpty() {
    if (top == -1) {
        return true;
    }
    else {
        return false;
    }
}

// Function to check if the stack is full
template <class T>
bool Stack<T>::isFull() {
    if (top == size - 1) {
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
    void preOrderIterative();

    void inOrder();
    void inOrder(Node<T>* p);
    void inOrderIterative();


    void postOrder();
    void postOrder(Node<T>* p);
    void postOrderIterative();

    void levelOrder();
    void levelOrder(Node<T>* p);

    int getHeight();
    int getHeight(Node<T>* p);

    int countNodes();
    int countNodes(Node<T>* p);
    int countNodesRecursive();
    int countNodesRecursive(Node<T>* p);

    int countNodesBothChildren();
    int countNodesBothChildren(Node<T>* p);

    int countLeafNodes();
    int countLeafNodes(Node<T>* p);

    int countInternalNodes();
    int countInternalNodes(Node<T>* p);

    int countNodesDegreeOne();
    int countNodesDegreeOne(Node<T>* p);

    T sumNodes();
    T sumNodes(Node<T>* p);


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
template <class T>
void BinaryTree_Queue_Array<T>::preOrderIterative() {
    Stack<T>* stk = new Stack<T>();
    Node<T>* p = root;

    while (p != NULL || !stk->isEmpty()) {
        if (p != NULL) {
            cout << p->data << " ";
            stk->Push(p);
            p = p->lchild;
        }
        else {
            p = stk->Pop();
            p = p->rchild;
        }
    }

    cout << endl;
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
template <class T>
void BinaryTree_Queue_Array<T>::inOrderIterative() {
    Stack<T>* stk = new Stack<T>();
    Node<T>* p = root;

    while (p != NULL || !stk->isEmpty()) {
        if (p != NULL) {
            stk->Push(p);
            p = p->lchild;
        }
        else {
            p = stk->Pop();
            cout << p->data << " ";
            p = p->rchild;
        }
    }

    cout << endl;
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
template <class T>
void BinaryTree_Queue_Array<T>::postOrderIterative() {
    Stack<T>* stk = new Stack<T>();
    Node<T>* p = root;
    long long int temp;

    while (p != NULL || !stk->isEmpty()) {
        if (p != NULL) {
            stk->Push(p);
            p = p->lchild;
        }
        else {
            //temp = stk->Pop();
            temp = reinterpret_cast<long long int>(stk->Pop());
            if (temp > 0) {
                stk->Push((Node<T>*)(-temp));
                p = ((Node<T>*)temp)->rchild;
            }
            else {
                cout << ((Node<T>*)(-temp))->data << " ";
                p = NULL;
            }
        }
    }

    cout << endl;
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

// Function to find the number of nodes in the tree
template <class T>
int BinaryTree_Queue_Array<T>::countNodes() {
    return countNodes(root);
}
template <class T>
int BinaryTree_Queue_Array<T>::countNodes(Node<T>* p) {
    int x, y;
    if (p != NULL) {
        x = countNodes(p->lchild);
        y = countNodes(p->rchild);
        return x + y + 1;
    }
    return 0;
}
template <class T>
int BinaryTree_Queue_Array<T>::countNodesRecursive() {
    return countNodesRecursive(root);
}
template <class T>
int BinaryTree_Queue_Array<T>::countNodesRecursive(Node<T>* p) {
    if (p == NULL) {
        return 0;
    }
    return countNodesRecursive(p->lchild) + countNodesRecursive(p->rchild) + 1;
}

// Function to find the number of nodes in the tree which have both children
template <class T>
int BinaryTree_Queue_Array<T>::countNodesBothChildren() {
    return countNodesBothChildren(root);
}
template <class T>
int BinaryTree_Queue_Array<T>::countNodesBothChildren(Node<T>* p) {
    int x, y;
    if (p != NULL) {
        x = countNodesBothChildren(p->lchild);
        y = countNodesBothChildren(p->rchild);
        if (p->lchild && p->rchild) {
            return x + y + 1;
        }
        else {
            return x + y;
        }
    }
    return 0;
}

// Function to find the number of leaf/external nodes in the tree
template <class T>
int BinaryTree_Queue_Array<T>::countLeafNodes() {
    return countLeafNodes(root);
}
template <class T>
int BinaryTree_Queue_Array<T>::countLeafNodes(Node<T>* p) {
    int x, y;
    if (p != NULL) {
        x = countLeafNodes(p->lchild);
        y = countLeafNodes(p->rchild);
        if (p->lchild == NULL && p->rchild == NULL) {
            return x + y + 1;
        }
        else {
            return x + y;
        }
    }
    return 0;
}

// Function to find the number of non-leaf/internal nodes in the tree
template <class T>
int BinaryTree_Queue_Array<T>::countInternalNodes() {
    return countInternalNodes(root);
}
template <class T>
int BinaryTree_Queue_Array<T>::countInternalNodes(Node<T>* p) {
    int x, y;
    if (p != NULL) {
        x = countInternalNodes(p->lchild);
        y = countInternalNodes(p->rchild);
        if (p->lchild || p->rchild) {
            return x + y + 1;
        }
        else {
            return x + y;
        }
    }
    return 0;
}

// Function to find the number of nodes in the tree with degree exactly equal to 1
template <class T>
int BinaryTree_Queue_Array<T>::countNodesDegreeOne() {
    return countNodesDegreeOne(root);
}
template <class T>
int BinaryTree_Queue_Array<T>::countNodesDegreeOne(Node<T>* p) {
    int x, y;
    if (p != NULL) {
        x = countNodesDegreeOne(p->lchild);
        y = countNodesDegreeOne(p->rchild);
        if ((p->lchild && p->rchild == NULL) || (p->lchild == NULL && p->rchild)) { // We can also use EXCLUSIVE OR Operator ^ in the condition, if (p->lchild ^ p->rchild){...}
            return x + y + 1;
        }
        else {
            return x + y;
        }
    }
    return 0;
}

// Function to find the sum of all nodes in the tree
template <class T>
T BinaryTree_Queue_Array<T>::sumNodes() {
    return sumNodes(root);
}
template <class T>
T BinaryTree_Queue_Array<T>::sumNodes(Node<T>* p) {
    T x, y;
    if (p != NULL) {
        x = sumNodes(p->lchild);
        y = sumNodes(p->rchild);
        return x + y + p->data;
    }
    return 0;
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
        cout << "2. Display in Preorder Traversal Fashion - Iterative\n";
        cout << "3. Display in Inorder Traversal Fashion\n";
        cout << "4. Display in Inorder Traversal Fashion - Iterative\n";
        cout << "5. Display in Postorder Traversal Fashion\n";
        cout << "6. Display in Postorder Traversal Fashion - Iterative\n";
        cout << "7. Display in Levelorder Traversal Fashion\n";
        cout << "8. Find Height\n";
        cout << "9. Find number of nodes\n";
        cout << "10. Find number of nodes - Recursive Approach\n";
        cout << "11. Find number of nodes with both children\n";
        cout << "12. Find number of leaf nodes\n";
        cout << "13. Find number of internal nodes\n";
        cout << "14. Find number of nodes with degree exactly 1\n";
        cout << "15. Find sum of all nodes\n";
        cout << "16. Exit Menu\n\n";

        cin >> choice;

        switch (choice) {
        case 1: // Displaying the contents of the tree in Preorder Traversal Fashion
            cout << "Preorder Traversal: ";
            btree->preOrder();
            break;

        case 2: // Displaying the contents of the tree in Preorder Traversal Fashion - Iterative Approach
            cout << "Preorder Traversal - Iterative: ";
            btree->preOrderIterative();
            break;

        case 3: // Displaying the contents of the tree in Inorder Traversal Fashion
            cout << "Inorder Traversal: ";
            btree->inOrder();
            break;

        case 4: // Displaying the contents of the tree in Inorder Traversal Fashion - Iterative Approach
            cout << "Inorder Traversal - Iterative: ";
            btree->inOrderIterative();
            break;

        case 5: // Displaying the contents of the tree in Postorder Traversal Fashion
            cout << "Postorder Traversal: ";
            btree->postOrder();
            break;

        case 6: // Displaying the contents of the tree in Postorder Traversal Fashion - Iterative Approach
            cout << "Postorder Traversal - Iterative: ";
            btree->postOrderIterative();
            break;

        case 7: // Displaying the contents of the tree in Levelorder Traversal Fashion
            cout << "Levelorder Traversal: ";
            btree->levelOrder();
            break;

        case 8: // Find the height of the tree
            cout << "The height of the tree is: ";
            cout << btree->getHeight();
            break;

        case 9: // Find number of nodes in the tree
            cout << "The number of nodes in the tree are: ";
            cout << btree->countNodes();
            break;

        case 10: // Find number of nodes in the tree - Recursive Approach
            cout << "The number of nodes in the tree are: ";
            cout << btree->countNodesRecursive();
            break;

        case 11: // Find number of nodes in the tree with both children
            cout << "The number of nodes in the tree with both children are: ";
            cout << btree->countNodesBothChildren();
            break;

        case 12: // Find number of leaf nodes in the tree
            cout << "The number of leaf nodes in the tree are: ";
            cout << btree->countLeafNodes();
            break;

        case 13: // Find number of intenal nodes in the tree
            cout << "The number of internal nodes in the tree are: ";
            cout << btree->countInternalNodes();
            break;

        case 14: // Find number of nodes in the tree with degree exactly equal to one
            cout << "The number of nodes in the tree with degree exactly 1 are: ";
            cout << btree->countNodesDegreeOne();
            break;

        case 15: // Find sum of all nodes in the tree
            cout << "The sum of all nodes in the tree is: ";
            cout << btree->sumNodes();
            break;

        }

    } while (choice < 16);

    return 0;
}
