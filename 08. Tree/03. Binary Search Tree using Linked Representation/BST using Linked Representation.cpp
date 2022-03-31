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



    /*void preOrder();
    void preOrder(treeNode<T>* p);
    void preOrderIterative();


    void postOrder();
    void postOrder(treeNode<T>* p);
    void postOrderIterative();

    void levelOrder();
    void levelOrder(treeNode<T>* p);

    int getHeight();
    int getHeight(treeNode<T>* p);

    int countNodes();
    int countNodes(treeNode<T>* p);
    int countNodesRecursive();
    int countNodesRecursive(treeNode<T>* p);

    int countNodesBothChildren();
    int countNodesBothChildren(treeNode<T>* p);

    int countLeafNodes();
    int countLeafNodes(treeNode<T>* p);

    int countInternalNodes();
    int countInternalNodes(treeNode<T>* p);

    int countNodesDegreeOne();
    int countNodesDegreeOne(treeNode<T>* p);

    T sumNodes();
    T sumNodes(treeNode<T>* p);*/

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

// Function to insert elements into the Binary Search Tree
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

//
//// Function to display the contents of the tree in Postorder Traversal Fashion
//template <class T>
//void BinaryTree_Queue_LL<T>::postOrder() {
//    postOrder(root);
//    cout << endl;
//}
//template <class T>
//void BinaryTree_Queue_LL<T>::postOrder(treeNode<T>* p) {
//    if (p != NULL) {
//        postOrder(p->lchild);
//        postOrder(p->rchild);
//        cout << p->data << " ";
//    }
//}
//template <class T>
//void BinaryTree_Queue_LL<T>::postOrderIterative() {
//    Stack<T>* stk = new Stack<T>();
//    treeNode<T>* p = root;
//    long long int temp;
//
//    while (p != NULL || !stk->isEmpty()) {
//        if (p != NULL) {
//            stk->Push(p);
//            p = p->lchild;
//        }
//        else {
//            //temp = stk->Pop();
//            temp = reinterpret_cast<long long int>(stk->Pop());
//            if (temp > 0) {
//                stk->Push((treeNode<T>*)(-temp));
//                p = ((treeNode<T>*)temp)->rchild;
//            }
//            else {
//                cout << ((treeNode<T>*)(-temp))->data << " ";
//                p = NULL;
//            }
//        }
//    }
//
//    cout << endl;
//}
//
//// Function to display the contents of the tree in Levelorder Traversal Fashion
//template <class T>
//void BinaryTree_Queue_LL<T>::levelOrder() {
//    levelOrder(root);
//    cout << endl;
//}
//template <class T>
//void BinaryTree_Queue_LL<T>::levelOrder(treeNode<T>* p) {
//    Queue<T>* que1 = new Queue<T>();
//    cout << p->data << " ";
//    que1->Enqueue(p);
//
//    while (!que1->isEmpty()) {
//        p = que1->Dequeue();
//        if (p->lchild != NULL) {
//            cout << p->lchild->data << " ";
//            que1->Enqueue(p->lchild);
//        }
//        if (p->rchild != NULL) {
//            cout << p->rchild->data << " ";
//            que1->Enqueue(p->rchild);
//        }
//    }
//}
//
//// Function to find the height of the tree
//template <class T>
//int BinaryTree_Queue_LL<T>::getHeight() {
//    return getHeight(root);
//}
//template <class T>
//int BinaryTree_Queue_LL<T>::getHeight(treeNode<T>* p) {
//    int x = 0, y = 0;
//    if (p == NULL) {
//        return 0;
//    }
//    x = getHeight(p->lchild);
//    y = getHeight(p->rchild);
//
//    if (x > y) {
//        return x + 1;
//    }
//    else {
//        return y + 1;
//    }
//}
//
//// Function to find the number of nodes in the tree
//template <class T>
//int BinaryTree_Queue_LL<T>::countNodes() {
//    return countNodes(root);
//}
//template <class T>
//int BinaryTree_Queue_LL<T>::countNodes(treeNode<T>* p) {
//    int x, y;
//    if (p != NULL) {
//        x = countNodes(p->lchild);
//        y = countNodes(p->rchild);
//        return x + y + 1;
//    }
//    return 0;
//}
//template <class T>
//int BinaryTree_Queue_LL<T>::countNodesRecursive() {
//    return countNodesRecursive(root);
//}
//template <class T>
//int BinaryTree_Queue_LL<T>::countNodesRecursive(treeNode<T>* p) {
//    if (p == NULL) {
//        return 0;
//    }
//    return countNodesRecursive(p->lchild) + countNodesRecursive(p->rchild) + 1;
//}
//
//// Function to find the number of nodes in the tree which have both children
//template <class T>
//int BinaryTree_Queue_LL<T>::countNodesBothChildren() {
//    return countNodesBothChildren(root);
//}
//template <class T>
//int BinaryTree_Queue_LL<T>::countNodesBothChildren(treeNode<T>* p) {
//    int x, y;
//    if (p != NULL) {
//        x = countNodesBothChildren(p->lchild);
//        y = countNodesBothChildren(p->rchild);
//        if (p->lchild && p->rchild) {
//            return x + y + 1;
//        }
//        else {
//            return x + y;
//        }
//    }
//    return 0;
//}
//
//// Function to find the number of leaf/external nodes in the tree
//template <class T>
//int BinaryTree_Queue_LL<T>::countLeafNodes() {
//    return countLeafNodes(root);
//}
//template <class T>
//int BinaryTree_Queue_LL<T>::countLeafNodes(treeNode<T>* p) {
//    int x, y;
//    if (p != NULL) {
//        x = countLeafNodes(p->lchild);
//        y = countLeafNodes(p->rchild);
//        if (p->lchild == NULL && p->rchild == NULL) {
//            return x + y + 1;
//        }
//        else {
//            return x + y;
//        }
//    }
//    return 0;
//}
//
//// Function to find the number of non-leaf/internal nodes in the tree
//template <class T>
//int BinaryTree_Queue_LL<T>::countInternalNodes() {
//    return countInternalNodes(root);
//}
//template <class T>
//int BinaryTree_Queue_LL<T>::countInternalNodes(treeNode<T>* p) {
//    int x, y;
//    if (p != NULL) {
//        x = countInternalNodes(p->lchild);
//        y = countInternalNodes(p->rchild);
//        if (p->lchild || p->rchild) {
//            return x + y + 1;
//        }
//        else {
//            return x + y;
//        }
//    }
//    return 0;
//}
//
//// Function to find the number of nodes in the tree with degree exactly equal to 1
//template <class T>
//int BinaryTree_Queue_LL<T>::countNodesDegreeOne() {
//    return countNodesDegreeOne(root);
//}
//template <class T>
//int BinaryTree_Queue_LL<T>::countNodesDegreeOne(treeNode<T>* p) {
//    int x, y;
//    if (p != NULL) {
//        x = countNodesDegreeOne(p->lchild);
//        y = countNodesDegreeOne(p->rchild);
//        if ((p->lchild && p->rchild == NULL) || (p->lchild == NULL && p->rchild)) { // We can also use EXCLUSIVE OR Operator ^ in the condition, if (p->lchild ^ p->rchild){...}
//            return x + y + 1;
//        }
//        else {
//            return x + y;
//        }
//    }
//    return 0;
//}
//
//// Function to find the sum of all nodes in the tree
//template <class T>
//T BinaryTree_Queue_LL<T>::sumNodes() {
//    return sumNodes(root);
//}
//template <class T>
//T BinaryTree_Queue_LL<T>::sumNodes(treeNode<T>* p) {
//    T x, y;
//    if (p != NULL) {
//        x = sumNodes(p->lchild);
//        y = sumNodes(p->rchild);
//        return x + y + p->data;
//    }
//    return 0;
//}



int main()
{
    BST_Linked<int>* bst;

    decltype(bst->element) x;

    bst = new BST_Linked<int>();

    int choice;

    do {
        cout << "\nMain Menu:\tChoose an operation to be performed on the BINARY SEARCH TREE\n\n";
        cout << "1. Insert - Recursive Approach\n";
        cout << "2. Insert - Iterative Approach\n";
        cout << "3. Display in Inorder Traversal Fashion\n";
        /*cout << "4. Display in Inorder Traversal Fashion - Iterative\n";
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
        cout << "15. Find sum of all nodes\n";*/
        cout << "4. Exit Menu\n\n";

        cin >> choice;

        switch (choice) {
        case 1: // Inserting elements into the Binary Search Tree - Recursive Approach
            cout << "Please enter an element: ";
            cin >> x;
            bst->insertRecursive(x);
            break;

        case 2: // Inserting elements into the Binary Search Tree - Iterative Approach
            cout << "Please enter an element: ";
            cin >> x;
            bst->insertIterative(x);
            break;

        case 3: // Displaying the contents of the Binary Search Tree in Inorder Traversal Fashion
            cout << "Inorder Traversal: ";
            bst->inOrder();
            break;

        //case 4: // Displaying the contents of the tree in Inorder Traversal Fashion - Iterative Approach
        //    cout << "Inorder Traversal - Iterative: ";
        //    btree->inOrderIterative();
        //    break;

        //case 5: // Displaying the contents of the tree in Postorder Traversal Fashion
        //    cout << "Postorder Traversal: ";
        //    btree->postOrder();
        //    break;

        //case 6: // Displaying the contents of the tree in Postorder Traversal Fashion - Iterative Approach
        //    cout << "Postorder Traversal - Iterative: ";
        //    btree->postOrderIterative();
        //    break;

        //case 7: // Displaying the contents of the tree in Levelorder Traversal Fashion
        //    cout << "Levelorder Traversal: ";
        //    btree->levelOrder();
        //    break;

        //case 8: // Find the height of the tree
        //    cout << "The height of the tree is: ";
        //    cout << btree->getHeight();
        //    break;

        //case 9: // Find number of nodes in the tree
        //    cout << "The number of nodes in the tree are: ";
        //    cout << btree->countNodes();
        //    break;

        //case 10: // Find number of nodes in the tree - Recursive Approach
        //    cout << "The number of nodes in the tree are: ";
        //    cout << btree->countNodesRecursive();
        //    break;

        //case 11: // Find number of nodes in the tree with both children
        //    cout << "The number of nodes in the tree with both children are: ";
        //    cout << btree->countNodesBothChildren();
        //    break;

        //case 12: // Find number of leaf nodes in the tree
        //    cout << "The number of leaf nodes in the tree are: ";
        //    cout << btree->countLeafNodes();
        //    break;

        //case 13: // Find number of intenal nodes in the tree
        //    cout << "The number of internal nodes in the tree are: ";
        //    cout << btree->countInternalNodes();
        //    break;

        //case 14: // Find number of nodes in the tree with degree exactly equal to one
        //    cout << "The number of nodes in the tree with degree exactly 1 are: ";
        //    cout << btree->countNodesDegreeOne();
        //    break;

        //case 15: // Find sum of all nodes in the tree
        //    cout << "The sum of all nodes in the tree is: ";
        //    cout << btree->sumNodes();
        //    break;

        }

    } while (choice < 4);

    return 0;
}
