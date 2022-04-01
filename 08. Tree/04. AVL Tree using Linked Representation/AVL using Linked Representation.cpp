#include <iostream>
using namespace std;

template <class T>
class treeNode {
public:
    treeNode<T>* lchild;
    T data;
    int height;
    treeNode<T>* rchild;

};

template <class T>
class AVL_Linked {
private:
    treeNode<T>* root;

public:
    T element;

    // Default Constructor 
    AVL_Linked();

    // Destructor
    ~AVL_Linked();
    void destroyRecursive(treeNode<T>* p);

    // Function prototypes
    int nodeHeight(treeNode<T>* p);
    int balanceFactor(treeNode<T>* p);

    treeNode<T>* LLRotation(treeNode<T>* p);
    treeNode<T>* LRRotation(treeNode<T>* p);
    treeNode<T>* RRRotation(treeNode<T>* p);
    treeNode<T>* RLRotation(treeNode<T>* p);

    void insertRecursive(T key);
    treeNode<T>* insertRecursive(treeNode<T>* p, T key);

    void preOrder();
    void preOrder(treeNode<T>* p);
    
    void inOrder();
    void inOrder(treeNode<T>* p);

    void postOrder();
    void postOrder(treeNode<T>* p);

    treeNode<T>* searchRecursive(T key);
    treeNode<T>* searchRecursive(treeNode<T>* p, T key);

    int getHeight();
    int getHeight(treeNode<T>* p);

    treeNode<T>* inorderPredecessor(treeNode<T>* p);
    treeNode<T>* inorderSuccessor(treeNode<T>* p);

    treeNode<T>* deleteRecursive(T key);
    treeNode<T>* deleteRecursive(treeNode<T>* p, T key);

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
AVL_Linked<T>::AVL_Linked() {
    root = NULL;
}

template <class T>
AVL_Linked<T>::~AVL_Linked() {
    destroyRecursive(root);
}

template <class T>
void AVL_Linked<T>::destroyRecursive(treeNode<T>* p) {
    if (p != NULL) {
        destroyRecursive(p->lchild);
        destroyRecursive(p->rchild);
        delete p;
    }
}

// Function to find the height of a node in AVL Tree
template <class T>
int AVL_Linked<T>::nodeHeight(treeNode<T>* p) {
    int heightLeftSubtree, heightRightSubtree;

    if (p && p->lchild) {
        heightLeftSubtree = p->lchild->height;
    }
    else {
        heightLeftSubtree = 0;
    }

    if (p && p->rchild) {
        heightRightSubtree = p->rchild->height;
    }
    else {
        heightRightSubtree = 0;
    }

    if (heightLeftSubtree > heightRightSubtree) {
        return heightLeftSubtree + 1;
    }
    else {
        return heightRightSubtree + 1;
    }
}

// Function to find the balance factor of a node in AVL Tree
template <class T>
int AVL_Linked<T>::balanceFactor(treeNode<T>* p) {
    int heightLeftSubtree, heightRightSubtree;

    if (p && p->lchild) {
        heightLeftSubtree = p->lchild->height;
    }
    else {
        heightLeftSubtree = 0;
    }

    if (p && p->rchild) {
        heightRightSubtree = p->rchild->height;
    }
    else {
        heightRightSubtree = 0;
    }

    return heightLeftSubtree - heightRightSubtree;
}

// Function to perform LL Rotation on a node in AVL Tree
template <class T>
treeNode<T>* AVL_Linked<T>::LLRotation(treeNode<T>* p) {
    treeNode<T>* pl = p->lchild;
    treeNode<T>* plr = p->lchild->rchild;

    pl->rchild = p;
    p->lchild = plr;
    p->height = nodeHeight(p);
    pl->height = nodeHeight(pl);

    if (root == p) {
        root = pl;
    }
    return pl;
}

// Function to perform LR Rotation on a node in AVL Tree
template <class T>
treeNode<T>* AVL_Linked<T>::LRRotation(treeNode<T>* p) {
    treeNode<T>* pl = p->lchild;
    treeNode<T>* plr = p->lchild->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
    plr->lchild = pl;
    plr->rchild = p;
    p->height = nodeHeight(p);
    pl->height = nodeHeight(pl);
    plr->height = nodeHeight(plr);
    
    if (root == p) {
        root = plr;
    }
    return plr;
}

// Function to perform RR Rotation on a node in AVL Tree
template <class T>
treeNode<T>* AVL_Linked<T>::RRRotation(treeNode<T>* p) {
    treeNode<T>* pr = p->rchild;
    treeNode<T>* prl = p->rchild->lchild;

    pr->lchild = p;
    p->rchild = prl;
    p->height = nodeHeight(p);
    pr->height = nodeHeight(pr);

    if (root == p) {
        root = pr;
    }
    return pr;
}

// Function to perform RL Rotation on a node in AVL Tree
template <class T>
treeNode<T>* AVL_Linked<T>::RLRotation(treeNode<T>* p) {
    treeNode<T>* pr = p->rchild;
    treeNode<T>* prl = p->rchild->lchild;

    p->rchild = prl->lchild;
    pr->lchild = prl->rchild;
    prl->lchild = p;
    prl->rchild = pr;
    p->height = nodeHeight(p);
    pr->height = nodeHeight(pr);
    prl->height = nodeHeight(prl);

    if (root == p) {
        root = prl;
    }
    return prl;
}


// Function to insert an element into the AVL Tree
template <class T>
void AVL_Linked<T>::insertRecursive(T key) {
    treeNode<T>* p = insertRecursive(root, key);
}
template <class T>
treeNode<T>* AVL_Linked<T>::insertRecursive(treeNode<T>* p, T key) {
    treeNode<T>* t;

    if (root == NULL) {
        t = new treeNode<T>;
        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = NULL;
        root = t;
        cout << key << " inserted into the BST" << endl;
        return t;
    }

    if (p == NULL) {
        t = new treeNode<T>;
        t->data = key;
        t->height = 1;
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

    p->height = nodeHeight(p);

    if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1) {
        return LLRotation(p);
    }
    else if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1) {
        return LRRotation(p);
    }
    else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1) {
        return RRRotation(p);
    }
    else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1) {
        return RLRotation(p);
    }

    return p;
}

// Function to display the contents of the AVL Tree in Preorder Traversal Fashion
template <class T>
void AVL_Linked<T>::preOrder() {
    preOrder(root);
    cout << endl;
}
template <class T>
void AVL_Linked<T>::preOrder(treeNode<T>* p) {
    if (p != NULL) {
        cout << p->data << " ";
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}

// Function to display the contents of the AVL Tree in Inorder Traversal Fashion
template <class T>
void AVL_Linked<T>::inOrder() {
    inOrder(root);
    cout << endl;
}
template <class T>
void AVL_Linked<T>::inOrder(treeNode<T>* p) {
    if (p != NULL) {
        inOrder(p->lchild);
        cout << p->data << " ";
        inOrder(p->rchild);
    }
}

// Function to display the contents of the AVL Tree in Postorder Traversal Fashion
template <class T>
void AVL_Linked<T>::postOrder() {
    postOrder(root);
    cout << endl;
}
template <class T>
void AVL_Linked<T>::postOrder(treeNode<T>* p) {
    if (p != NULL) {
        postOrder(p->lchild);
        postOrder(p->rchild);
        cout << p->data << " ";
    }
}

// Function to search an element in the Binary Search Tree
template <class T>
treeNode<T>* AVL_Linked<T>::searchRecursive(T key) {
    return searchRecursive(root, key);
}
template <class T>
treeNode<T>* AVL_Linked<T>::searchRecursive(treeNode<T>* p, T key) {
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

// Function to find the height of the AVL Tree
template <class T>
int AVL_Linked<T>::getHeight() {
    return getHeight(root);
}
template <class T>
int AVL_Linked<T>::getHeight(treeNode<T>* p) {
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

// Function to find the Inorder Predecessor of an element in the AVL Tree
template <class T>
treeNode<T>* AVL_Linked<T>::inorderPredecessor(treeNode<T>* p) {
    while (p != NULL && p->rchild != NULL) {
        p = p->rchild;
    }
    return p;
}

// Function to find the Inorder Successor of an element in the AVL Tree
template <class T>
treeNode<T>* AVL_Linked<T>::inorderSuccessor(treeNode<T>* p) {
    while (p != NULL && p->lchild != NULL) {
        p = p->lchild;
    }
    return p;
}

// Function to delete an element from the AVL Tree
template <class T>
treeNode<T>* AVL_Linked<T>::deleteRecursive(T key) {
    return deleteRecursive(root, key);
}
template <class T>
treeNode<T>* AVL_Linked<T>::deleteRecursive(treeNode<T>* p, T key) {
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

    p->height = nodeHeight(p);

    if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1) { // L 1 Rotation
        return LLRotation(p); 
    }
    else if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1) { // L -1 Rotation
        return LRRotation(p);
    }
    else if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == 0) { // L 0 Rotation
        return LLRotation(p); // Or, we can do LR Rotation also
    }
    else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1) { // R -1 Rotation
        return RRRotation(p);
    }
    else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1) { // R 1 Rotation
        return RLRotation(p);
    }
    else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 0) { // R 0 Rotation
        return RRRotation(p); // Or, we can do RL Rotation also
    }

    return p;
}

// Function to find the number of nodes in the AVL Tree
template <class T>
int AVL_Linked<T>::countNodes() {
    return countNodes(root);
}
template <class T>
int AVL_Linked<T>::countNodes(treeNode<T>* p) {
    int x, y;
    if (p != NULL) {
        x = countNodes(p->lchild);
        y = countNodes(p->rchild);
        return x + y + 1;
    }
    return 0;
}

// Function to find the number of nodes in the AVL Tree which have both children
template <class T>
int AVL_Linked<T>::countNodesBothChildren() {
    return countNodesBothChildren(root);
}
template <class T>
int AVL_Linked<T>::countNodesBothChildren(treeNode<T>* p) {
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

// Function to find the number of leaf/external nodes in the AVL Tree
template <class T>
int AVL_Linked<T>::countLeafNodes() {
    return countLeafNodes(root);
}
template <class T>
int AVL_Linked<T>::countLeafNodes(treeNode<T>* p) {
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

// Function to find the number of non-leaf/internal nodes in the AVL Tree
template <class T>
int AVL_Linked<T>::countInternalNodes() {
    return countInternalNodes(root);
}
template <class T>
int AVL_Linked<T>::countInternalNodes(treeNode<T>* p) {
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

// Function to find the number of nodes in the AVL Tree with degree exactly equal to 1
template <class T>
int AVL_Linked<T>::countNodesDegreeOne() {
    return countNodesDegreeOne(root);
}
template <class T>
int AVL_Linked<T>::countNodesDegreeOne(treeNode<T>* p) {
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

// Function to find the sum of all nodes in the AVL Tree
template <class T>
T AVL_Linked<T>::sumNodes() {
    return sumNodes(root);
}
template <class T>
T AVL_Linked<T>::sumNodes(treeNode<T>* p) {
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
    AVL_Linked<int>* avl, * avl1;

    decltype(avl->element) x;

    avl = new AVL_Linked<int>();

    int choice, numNodes;
    decltype(avl->element)* arr;

    do {
        cout << "\nMain Menu:\tChoose an operation to be performed on the AVL TREE\n\n";
        cout << "1. Insert - Recursive Approach\n";
        cout << "2. Display in Preorder Traversal Fashion\n";
        cout << "3. Display in Inorder Traversal Fashion\n";
        cout << "4. Display in Postorder Traversal Fashion\n"; 
        cout << "5. Search - Recursive Approach\n";
        cout << "6. Delete\n";
        cout << "7. Find Height\n";
        cout << "8. Find number of nodes\n";
        cout << "9. Find number of nodes with both children\n";
        cout << "10. Find number of leaf nodes\n";
        cout << "11. Find number of internal nodes\n";
        cout << "12. Find number of nodes with degree exactly 1\n";
        cout << "13. Find sum of all nodes\n";
        cout << "14. Exit Menu\n\n";

        cin >> choice;

        switch (choice) {
        case 1: // Inserting an element into the AVL Tree - Recursive Approach
            cout << "Please enter an element: ";
            cin >> x;
            avl->insertRecursive(x);
            break;

        case 2: // Displaying the contents of the AVL Tree in Preorder Traversal Fashion
            cout << "Preorder Traversal: ";
            avl->preOrder();
            break;

        case 3: // Displaying the contents of the AVL Tree in Inorder Traversal Fashion
            cout << "Inorder Traversal: ";
            avl->inOrder();
            break;

        case 4: // Displaying the contents of the AVL Tree in Postorder Traversal Fashion
            cout << "Postorder Traversal: ";
            avl->postOrder();
            break;

        case 5: // Searching an element in the AVL Tree - Recursive Approach
            cout << "Please enter an element: ";
            cin >> x;
            if (avl->searchRecursive(x)) {
                cout << "Element Found!" << endl;
            }
            else {
                cout << "Element NOT Found!" << endl;
            }
            break;

        case 6: // Deleting an element from the AVL Tree
            cout << "Please enter an element: ";
            cin >> x;
            if (avl->searchRecursive(x)) {
                avl->deleteRecursive(x);
                cout << "Element Deleted!" << endl;
            }
            else {
                cout << "Element NOT Found!" << endl;
            }
            break;

        case 7: // Find the height of the AVL Tree
            cout << "The height of the AVL Tree is: ";
            cout << avl->getHeight();
            break;

        case 8: // Find number of nodes in the AVL Tree
            cout << "The number of nodes in the AVL Tree are: ";
            cout << avl->countNodes();
            break;

        case 9: // Find number of nodes in the AVL Tree with both children
            cout << "The number of nodes in the AVL Tree with both children are: ";
            cout << avl->countNodesBothChildren();
            break;

        case 10: // Find number of leaf nodes in the AVL Tree
            cout << "The number of leaf nodes in the AVL Tree are: ";
            cout << avl->countLeafNodes();
            break;

        case 11: // Find number of intenal nodes in the AVL Tree
            cout << "The number of internal nodes in the AVL Tree are: ";
            cout << avl->countInternalNodes();
            break;

        case 12: // Find number of nodes in the AVL Tree with degree exactly equal to one
            cout << "The number of nodes in the AVL Tree with degree exactly 1 are: ";
            cout << avl->countNodesDegreeOne();
            break;

        case 13: // Find sum of all nodes in the AVL Tree
            cout << "The sum of all nodes in the AVL Tree is: ";
            cout << avl->sumNodes();
            break;

        }

    } while (choice < 14);

    return 0;
}
