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
class stackNode {
public:
    treeNode<T>* data;
    stackNode<T>* next;

};

template <class T>
class Stack {
private:
    stackNode<T>* top;

public:
    T element;

    // Default Constructor 
    Stack();

    // Destructor
    ~Stack();

    // Function prototypes
    void Display();
    void Push(treeNode<T>* x);
    treeNode<T>* Pop();
    bool isEmpty();
    bool isFull();
    treeNode<T>* stackTop();

};

template <class T>
Stack<T>::Stack() {
    top = NULL;
}

template <class T>
Stack<T>::~Stack() {
    stackNode<T>* p = top;
    while (top) {
        top = top->next;
        delete p;
        p = top;
    }
}

// Function to display the contents of the stack
template <class T>
void Stack<T>::Display() {
    stackNode<T>* t = top;
    while (t) {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

// Function to push an element onto the stack
template <class T>
void Stack<T>::Push(treeNode<T>* x) {
    stackNode<T>* t = new stackNode<T>;
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
treeNode<T>* Stack<T>::Pop() {
    stackNode<T>* t;
    treeNode<T>* x = NULL;
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

// Function to check if the stack is empty
template <class T>
bool Stack<T>::isEmpty() {
    if (top == NULL) {
        return true;
    }
    else {
        return false;
    }
}

// Function to check if the stack is full
template <class T>
bool Stack<T>::isFull() {
    stackNode<T>* t = new stackNode<T>;
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

// Function to find the topmost value of stack
template <class T>
treeNode<T>* Stack<T>::stackTop() {
    if (top != NULL) {
        return top->data;
    }
    else {
        treeNode<T>* t = new treeNode<T>;
        t->data = INT_MAX;
        t->lchild = t->rchild = NULL;
        return t;
    }
}


template <class T>
class BST_Linked {
private:
    treeNode<T>* root;

public:
    T element;

    // Default Constructor 
    BST_Linked();

    // Parameterized Constructor
    BST_Linked(T x);

    // Destructor
    ~BST_Linked();
    void destroyRecursive(treeNode<T>* p);

    // Function prototypes
    void insertRecursive(T key);
    treeNode<T>* insertRecursive(treeNode<T>* p, T key);
    void insertIterative(T key);

    void inOrder();
    void inOrder(treeNode<T>* p);

    treeNode<T>* searchRecursive(T key);
    treeNode<T>* searchRecursive(treeNode<T>* p, T key);
    treeNode<T>* searchIterative(T key);

    int getHeight();
    int getHeight(treeNode<T>* p);

    treeNode<T>* inorderPredecessor(treeNode<T>* p);
    treeNode<T>* inorderSuccessor(treeNode<T>* p);

    treeNode<T>* deleteRecursive(T key);
    treeNode<T>* deleteRecursive(treeNode<T>* p, T key);

    void generateFromPreorder(T pre[], int n);

    void preOrder();
    void preOrder(treeNode<T>* p);

    void postOrder();
    void postOrder(treeNode<T>* p);

    int countNodes();
    int countNodes(treeNode<T>* p);

    int countNodesBothChildren();
    int countNodesBothChildren(treeNode<T>* p);

    int countLeafNodes();
    int countLeafNodes(treeNode<T>* p);

    int countInternalNodes();
    int countInternalNodes(treeNode<T>* p);

    int countNodesDegreeOne();
    int countNodesDegreeOne(treeNode<T>* p);

    T sumNodes();
    T sumNodes(treeNode<T>* p);

};

template <class T>
BST_Linked<T>::BST_Linked() {
    root = NULL;
}

template <class T>
BST_Linked<T>::~BST_Linked() {
    destroyRecursive(root);
}

template <class T>
void BST_Linked<T>::destroyRecursive(treeNode<T>* p) {
    if (p != NULL) {
        destroyRecursive(p->lchild);
        destroyRecursive(p->rchild);
        delete p;
    }
}

// Function to insert an element into the Binary Search Tree
template <class T>
void BST_Linked<T>::insertRecursive(T key) {
    treeNode<T>* p = insertRecursive(root, key);
}
template <class T>
treeNode<T>* BST_Linked<T>::insertRecursive(treeNode<T>* p, T key) {
    treeNode<T>* t;

    if (root == NULL) {
        t = new treeNode<T>;
        t->data = key;
        t->lchild = t->rchild = NULL;
        root = t;
        cout << key << " inserted into the BST" << endl;
        return t;
    }

    if (p == NULL) {
        t = new treeNode<T>;
        t->data = key;
        t->lchild = t->rchild = NULL;
        cout << key << " inserted into the BST" << endl;
        return t;
    }
    if (key < p->data) {
        p->lchild = insertRecursive(p->lchild, key);
    }
    else if (key > p->data) {
        p->rchild = insertRecursive(p->rchild, key);
    }
    else {
        cout << "Element already present in BST" << endl;
    }
    return p;
}
template <class T>
void BST_Linked<T>::insertIterative(T key) {
    treeNode<T>* t = root;
    treeNode<T>* p, * r = NULL;

    if (root == NULL) {
        p = new treeNode<T>;
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        cout << key << " inserted into the BST" << endl;
        return;
    }

    while (t != NULL) {
        r = t;
        if (key == t->data) {
            cout << "Element already present in BST" << endl;
            return;
        }
        else if (key < t->data) {
            t = t->lchild;
        }
        else {
            t = t->rchild;
        }
    }

    p = new treeNode<T>;
    p->data = key;
    p->lchild = p->rchild = NULL;

    if (key < r->data) {
        r->lchild = p;
    }
    else {
        r->rchild = p;
    }
    cout << key << " inserted into the BST" << endl;
}

// Function to display the contents of the BST in Inorder Traversal Fashion
template <class T>
void BST_Linked<T>::inOrder() {
    inOrder(root);
    cout << endl;
}
template <class T>
void BST_Linked<T>::inOrder(treeNode<T>* p) {
    if (p != NULL) {
        inOrder(p->lchild);
        cout << p->data << " ";
        inOrder(p->rchild);
    }
}

// Function to search an element in the Binary Search Tree
template <class T>
treeNode<T>* BST_Linked<T>::searchRecursive(T key) {
    return searchRecursive(root, key);
}
template <class T>
treeNode<T>* BST_Linked<T>::searchRecursive(treeNode<T>* p, T key) {
    if (p == NULL) {
        return NULL;
    }
    if (key == p->data) {
        return p;
    }
    else if (key < p->data) {
        return searchRecursive(p->lchild, key);
    }
    else {
        return searchRecursive(p->rchild, key);
    }
}
template <class T>
treeNode<T>* BST_Linked<T>::searchIterative(T key) {
    treeNode<T>* t = root;

    while (t != NULL) {
        if (key == t->data) {
            return t;
        }
        else if (key < t->data) {
            t = t->lchild;
        }
        else {
            t = t->rchild;
        }
    }
    return NULL;
}

// Function to find the height of the tree
template <class T>
int BST_Linked<T>::getHeight() {
    return getHeight(root);
}
template <class T>
int BST_Linked<T>::getHeight(treeNode<T>* p) {
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

// Function to find the Inorder Predecessor of an element in the Binary Search Tree
template <class T>
treeNode<T>* BST_Linked<T>::inorderPredecessor(treeNode<T>* p) {
    while (p != NULL && p->rchild != NULL) {
        p = p->rchild;
    }
    return p;
}

// Function to find the Inorder Successor of an element in the Binary Search Tree
template <class T>
treeNode<T>* BST_Linked<T>::inorderSuccessor(treeNode<T>* p) {
    while (p != NULL && p->lchild != NULL) {
        p = p->lchild;
    }
    return p;
}

// Function to delete an element from the Binary Search Tree
template <class T>
treeNode<T>* BST_Linked<T>::deleteRecursive(T key) {
    return deleteRecursive(root, key);
}
template <class T>
treeNode<T>* BST_Linked<T>::deleteRecursive(treeNode<T>* p, T key) {
    treeNode<T>* q;

    if (p == NULL) {
        return NULL;
    }

    if (key < p->data) {
        p->lchild = deleteRecursive(p->lchild, key);
    }
    else if (key > p->data) {
        p->rchild = deleteRecursive(p->rchild, key);
    }
    else {
        if (p->lchild == NULL && p->rchild == NULL) {
            if (p == root) {
                root = NULL;
            }
            delete p;
            return NULL;
        }
        else {
            if (getHeight(p->lchild) > getHeight(p->rchild)) {
                q = inorderPredecessor(p->lchild);
                p->data = q->data;
                p->lchild = deleteRecursive(p->lchild, q->data);
            }
            else {
                q = inorderSuccessor(p->rchild);
                p->data = q->data;
                p->rchild = deleteRecursive(p->rchild, q->data);
            }
        }
    }
    return p;
}

// Function to generate a Binary Search Tree from Preorder Traversal
template <class T>
void BST_Linked<T>::generateFromPreorder(T pre[], int n) {
    Stack<T>* stk = new Stack<T>;
    treeNode<T>* t, *p = NULL;
    int i = 0;
    root = new treeNode<T>;
    root->data = pre[i];
    i++;
    root->lchild = root->rchild = NULL;
    p = root;
    while (i < n) {
        if (pre[i] < p->data) {
            t = new treeNode<T>;
            t->data = pre[i];
            i++;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            stk->Push(p);
            p = t;
        }
        else {
            if (pre[i] > p->data && pre[i] < (stk->stackTop())->data) {
                t = new treeNode<T>;
                t->data = pre[i];
                i++;
                t->lchild = t->rchild = NULL;
                p->rchild = t;
                p = t;
            }
            else {
                p = stk->Pop();
            }
        }
    }
}

// Function to display the contents of the BST in Preorder Traversal Fashion
template <class T>
void BST_Linked<T>::preOrder() {
    preOrder(root);
    cout << endl;
}
template <class T>
void BST_Linked<T>::preOrder(treeNode<T>* p) {
    if (p != NULL) {
        cout << p->data << " ";
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}

// Function to display the contents of the BST in Postorder Traversal Fashion
template <class T>
void BST_Linked<T>::postOrder() {
    postOrder(root);
    cout << endl;
}
template <class T>
void BST_Linked<T>::postOrder(treeNode<T>* p) {
    if (p != NULL) {
        postOrder(p->lchild);
        postOrder(p->rchild);
        cout << p->data << " ";
    }
}

// Function to find the number of nodes in the Binary Search Tree
template <class T>
int BST_Linked<T>::countNodes() {
    return countNodes(root);
}
template <class T>
int BST_Linked<T>::countNodes(treeNode<T>* p) {
    int x, y;
    if (p != NULL) {
        x = countNodes(p->lchild);
        y = countNodes(p->rchild);
        return x + y + 1;
    }
    return 0;
}

// Function to find the number of nodes in the BST which have both children
template <class T>
int BST_Linked<T>::countNodesBothChildren() {
    return countNodesBothChildren(root);
}
template <class T>
int BST_Linked<T>::countNodesBothChildren(treeNode<T>* p) {
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

// Function to find the number of leaf/external nodes in the Binary Search Tree
template <class T>
int BST_Linked<T>::countLeafNodes() {
    return countLeafNodes(root);
}
template <class T>
int BST_Linked<T>::countLeafNodes(treeNode<T>* p) {
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

// Function to find the number of non-leaf/internal nodes in the Binary Search Tree
template <class T>
int BST_Linked<T>::countInternalNodes() {
    return countInternalNodes(root);
}
template <class T>
int BST_Linked<T>::countInternalNodes(treeNode<T>* p) {
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

// Function to find the number of nodes in the BST with degree exactly equal to 1
template <class T>
int BST_Linked<T>::countNodesDegreeOne() {
    return countNodesDegreeOne(root);
}
template <class T>
int BST_Linked<T>::countNodesDegreeOne(treeNode<T>* p) {
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

// Function to find the sum of all nodes in the Binary Search Tree
template <class T>
T BST_Linked<T>::sumNodes() {
    return sumNodes(root);
}
template <class T>
T BST_Linked<T>::sumNodes(treeNode<T>* p) {
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
    BST_Linked<int>* bst, * bst1;

    decltype(bst->element) x;

    bst = new BST_Linked<int>();

    int choice, numNodes;
    decltype(bst->element)* arr;

    do {
        cout << "\nMain Menu:\tChoose an operation to be performed on the BINARY SEARCH TREE\n\n";
        cout << "1. Insert - Recursive Approach\n";
        cout << "2. Insert - Iterative Approach\n";
        cout << "3. Display in Preorder Traversal Fashion\n";
        cout << "4. Display in Inorder Traversal Fashion\n";
        cout << "5. Display in Postorder Traversal Fashion\n";
        cout << "6. Search - Recursive Approach\n";
        cout << "7. Search - Iterative Approach\n";
        cout << "8. Delete\n";
        cout << "9. Generate BST from Preorder Traversal\n";
        cout << "10. Find Height\n";
        cout << "11. Find number of nodes\n";
        cout << "12. Find number of nodes with both children\n";
        cout << "13. Find number of leaf nodes\n";
        cout << "14. Find number of internal nodes\n";
        cout << "15. Find number of nodes with degree exactly 1\n";
        cout << "16. Find sum of all nodes\n";
        cout << "17. Exit Menu\n\n";

        cin >> choice;

        switch (choice) {
        case 1: // Inserting an element into the Binary Search Tree - Recursive Approach
            cout << "Please enter an element: ";
            cin >> x;
            bst->insertRecursive(x);
            break;

        case 2: // Inserting an element into the Binary Search Tree - Iterative Approach
            cout << "Please enter an element: ";
            cin >> x;
            bst->insertIterative(x);
            break;

        case 3: // Displaying the contents of the Binary Search Tree in Preorder Traversal Fashion
            cout << "Preorder Traversal: ";
            bst->preOrder();
            break;

        case 4: // Displaying the contents of the Binary Search Tree in Inorder Traversal Fashion
            cout << "Inorder Traversal: ";
            bst->inOrder();
            break;

        case 5: // Displaying the contents of the Binary Search Tree in Postorder Traversal Fashion
            cout << "Postorder Traversal: ";
            bst->postOrder();
            break;

        case 6: // Searching an element in the Binary Search Tree - Recursive Approach
            cout << "Please enter an element: ";
            cin >> x;
            if (bst->searchRecursive(x)) {
                cout << "Element Found!" << endl;
            }
            else {
                cout << "Element NOT Found!" << endl;
            }
            break;

        case 7: // Searching an element in the Binary Search Tree - Iterative Approach
            cout << "Please enter an element: ";
            cin >> x;
            if (bst->searchIterative(x)) {
                cout << "Element Found!" << endl;
            }
            else {
                cout << "Element NOT Found!" << endl;
            }
            break;

        case 8: // Deleting an element from the Binary Search Tree
            cout << "Please enter an element: ";
            cin >> x;
            if (bst->searchRecursive(x)) {
                bst->deleteRecursive(x);
                cout << "Element Deleted!" << endl;
            }
            else {
                cout << "Element NOT Found!" << endl;
            }
            break;

        case 9: // Generating a BST from Preorder traversal
            cout << "Please enter the number of nodes: ";
            cin >> numNodes;
            arr = new int[numNodes];

            cout << "Please enter the elements in Preorder Traversal: ";
            for (int i = 0; i < numNodes; i++) {
                cin >> arr[i];
            }

            bst1 = new BST_Linked<int>();
            bst1->generateFromPreorder(arr, numNodes);
            cout << "Generated BST's Inorder Traversal: ";
            bst1->inOrder();
            delete[]arr;

            break;

        case 10: // Find the height of the Binary Search Tree
            cout << "The height of the Binary Search Tree is: ";
            cout << bst->getHeight();
            break;

        case 11: // Find number of nodes in the Binary Search Tree
            cout << "The number of nodes in the Binary Search Tree are: ";
            cout << bst->countNodes();
            break;

        case 12: // Find number of nodes in the BST with both children
            cout << "The number of nodes in the BST with both children are: ";
            cout << bst->countNodesBothChildren();
            break;

        case 13: // Find number of leaf nodes in the Binary Search Tree
            cout << "The number of leaf nodes in the Binary Search Tree are: ";
            cout << bst->countLeafNodes();
            break;

        case 14: // Find number of intenal nodes in the Binary Search Tree
            cout << "The number of internal nodes in the Binary Search Tree are: ";
            cout << bst->countInternalNodes();
            break;

        case 15: // Find number of nodes in the BST with degree exactly equal to one
            cout << "The number of nodes in the BST with degree exactly 1 are: ";
            cout << bst->countNodesDegreeOne();
            break;

        case 16: // Find sum of all nodes in the Binary Search Tree
            cout << "The sum of all nodes in the Binary Search Tree is: ";
            cout << bst->sumNodes();
            break;

        }

    } while (choice < 17);

    return 0;
}
