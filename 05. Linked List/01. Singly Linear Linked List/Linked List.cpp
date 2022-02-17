#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node* next;

};

template <class T>
class LinkedList {
private:
    Node<T>* first;

public:
    T element;

    // Default Constructor 
    LinkedList();

    // Parameterized Constructor
    LinkedList(T A[], int n);

    // Destructor
    ~LinkedList();

    // Function prototypes
    Node<T>* getFirst();
    void Display();
    void RecursiveDisplay(Node<T>* p);
    void Append(T x);
    int getLength();
    int getLengthRecursive(Node<T>* p);
    T Sum();
    T SumRecursive(Node<T>* p);
    T MaxValue();
    T MinValue();
    Node<T>* LinearSearch(T key);
    Node<T>* LinearSearchMoveToHead(T key);
    void Insert(int index, T x);
    void InsertSorted(T x);
    T Delete(int index);
    bool IsSorted();
    void RemoveDuplicates();
    void ReverseElements();
    void ReverseLinks();
    void ReverseLinksRecursion(Node<T>* q, Node<T>* p);
    LinkedList<T>* Concatenate(LinkedList<T>* l2);
    LinkedList<T>* Merge(LinkedList<T>* l2);
    bool IsLoop();
};

template <class T>
LinkedList<T>::LinkedList() {
    first = NULL;
}

template <class T>
LinkedList<T>::LinkedList(T A[], int n) {
    Node<T>* last, * t;
    int i = 0;
    first = new Node<T>;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++) {
        t = new Node<T>;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

template <class T>
LinkedList<T>::~LinkedList() {
    Node<T>* p = first;
    while (first) {
        first = first->next;
        delete p;
        p = first;
    }
}

// Helper function to get the first node of linked list
template <class T>
Node<T>* LinkedList<T>::getFirst() {
    return first;
}

// Function to display the contents of a linked list
template <class T>
void LinkedList<T>::Display() {
    Node<T>* p = first;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// Function to display the contents of a linked list using Recursion
template <class T>
void LinkedList<T>::RecursiveDisplay(Node<T>* p) {
    if (p != NULL) {
        cout << p->data << " ";
        RecursiveDisplay(p->next);
    }
}

// Function to append an element at the end of a linked list
template <class T>
void LinkedList<T>::Append(T x) {
    Node<T>* t = new Node<T>;
    t->data = x;
    t->next = NULL;

    if (first == NULL) {
        first = t;
    }
    else {
        Node<T>* p = first;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = t;
    }

}

// Helper function to get length of the linked list
template <class T>
int LinkedList<T>::getLength() {
    Node<T>* p = first;
    int len = 0;
    while (p != NULL) {
        len++;
        p = p->next;
    }
    return len;
}

// Helper function to get length of the linked list using Recursion
template <class T>
int LinkedList<T>::getLengthRecursive(Node<T>* p) {
    if (p != NULL) {
        return 1 + getLengthRecursive(p->next);
    }
    else {
        return 0;
    }
}

// Function to find sum of all values in a linked list
template <class T>
T LinkedList<T>::Sum() {
    Node<T>* p = first;
    T sum = 0;
    while (p != NULL) {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

// Function to find sum of all values in a linked list using Recursion
template <class T>
T LinkedList<T>::SumRecursive(Node<T>* p) {
    if (p != NULL) {
        return p->data + SumRecursive(p->next);
    }
    else {
        return 0;
    }
}

// Function to find maximum value in a linked list
template <class T>
T LinkedList<T>::MaxValue() {
    Node<T>* p = first;
    T max = INT_MIN;
    while (p != NULL) {
        if (p->data > max) {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

// Function to find minimum value in a linked list
template <class T>
T LinkedList<T>::MinValue() {
    Node<T>* p = first;
    T min = INT_MAX;
    while (p != NULL) {
        if (p->data < min) {
            min = p->data;
        }
        p = p->next;
    }
    return min;
}

// Function to perform linear search on a linked list
template <class T>
Node<T>* LinkedList<T>::LinearSearch(T key) {
    Node<T>* p = first;
    while (p != NULL) {
        if (key == p->data) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

// Function to perform linear search on a linked list using Move to Head
template <class T>
Node<T>* LinkedList<T>::LinearSearchMoveToHead(T key) {
    Node<T>* p = first, * q = NULL;
    while (p != NULL) {
        if (key == p->data) {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        else {
            q = p;
            p = p->next;
        }
    }
    return NULL;
}

// Function to insert an element at a given index
template <class T>
void LinkedList<T>::Insert(int index, T x) {
    if (index < 0 || index > getLength()) {
        return;
    }
    Node<T>* p = first;
    Node<T>* t = new Node<T>;
    t->data = x;
    
    if (index == 0) {
        t->next = first;
        first = t;
    }
    else {
        for (int i = 0; i < index - 1; i++) {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }

}

// Function to insert an element in a sorted linked list
template <class T>
void LinkedList<T>::InsertSorted(T x) {
    Node<T>* p = first, * q = NULL;
    Node<T>* t = new Node<T>;
    t->data = x;
    t->next = NULL;
    if (first == NULL) {
        first = t;
    }
    else {
        while (p != NULL && p->data < x) {
            q = p;
            p = p->next;
        }
        if (p == first) {
            t->next = first;
            first = t;
        }
        else {
            t->next = q->next;
            q->next = t;
        }
    }
}

// Function to delete an element from the linked list
template <class T>
T LinkedList<T>::Delete(int index) {
    T x = -1;
    if (index < 1 || index > getLength()) {
        return x;
    }
    Node<T>* p, * q = NULL;
    
    if (index == 1) {
        p = first;
        x = first->data;
        if (p->next == NULL) {
            delete p;
            first = NULL;
        }
        else {
            first = first->next;
            delete p;
        }
    }
    else {
        p = first;
        for (int i = 0; i < index - 1; i++) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
    }
    return x;
}

// Function to check if a linked list is sorted or not
template <class T>
bool LinkedList<T>::IsSorted() {
    T x = INT_MIN;
    Node<T>* p = first;
    while (p != NULL) {
        if (p->data < x) {
            return false;
        }
        x = p->data;
        p = p->next;
    }
    return true;
}

// Function to remove the duplicates in a sorted linked list
template <class T>
void LinkedList<T>::RemoveDuplicates() {
    Node<T>* p = first;
    Node<T>* q = p->next;
    while (q != NULL) {
        if (p->data != q->data) {
            p = q;
            q = q->next;
        }
        else {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

// Function to reverse a linked list - Method 1: Reversing elements
template <class T>
void LinkedList<T>::ReverseElements() {
    Node<T>* p = first;
    int i = 0;
    T* A = new T[getLength()];
    while (p != NULL) {
        A[i] = p->data;
        p = p->next;
        i++;
    }
    p = first;
    i--;
    while (p != NULL) {
        p->data = A[i];
        p = p->next;
        i--;
    }
}

// Function to reverse a linked list - Method 2: Reversing links
template <class T>
void LinkedList<T>::ReverseLinks() {
    Node<T>* p = first;
    Node<T>* q = NULL;
    Node<T>* r = NULL;
    while (p != NULL) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

// Function to reverse a linked list - Method 3: Reversing links using Recursion
template <class T>
void LinkedList<T>::ReverseLinksRecursion(Node<T>* q, Node<T>* p) {
    if (p != NULL) {
        ReverseLinksRecursion(p, p->next);
        p->next = q;
    }
    else {
        first = q;
    }
}

// Function to concatenate two linked lists
template <class T>
LinkedList<T>* LinkedList<T>::Concatenate(LinkedList<T>* l2) {
    Node<T>* p = first;
    Node<T>* q = l2->first;
    LinkedList<T>* l3 = new LinkedList<T>();

    while (p != NULL) {
        l3->Append(p->data);
        p = p->next;
    }

    Node<T>* r = l3->first;
    while (r->next != NULL) {
        r = r->next;
    }
    r->next = q;

    return l3;
}

// Function to merge two linked lists
template <class T>
LinkedList<T>* LinkedList<T>::Merge(LinkedList<T>* l2) {
    Node<T>* p = first;
    Node<T>* q = l2->first;
    LinkedList<T>* l3 = new LinkedList<T>();
    
    while (p != NULL && q != NULL) {
        if (p->data < q->data) {
            l3->Append(p->data);
            p = p->next;
        }
        else {
            l3->Append(q->data);
            q = q->next;
        }
    }

    Node<T>* r = l3->first;
    while (r->next != NULL) {
        r = r->next;
    }
    if (p != NULL) {
        r->next = p;
    }
    else {
        r->next = q;
    }

    return l3;
}

// Function to check if a linked list contains a LOOP or not
template <class T>
bool LinkedList<T>::IsLoop() {
    Node<T>* p = first, * q = first;
    do {
        p = p->next;
        q = q->next;
        if (q != NULL) {
            q = q->next;
        }
    } while (p != NULL && q != NULL && p != q);

    if (p == q) {
        return true;
    }
    else {
        return false;
    }

}


int main()
{
    LinkedList<int>* l = new LinkedList<int>();
    LinkedList<int>* l2;
    LinkedList<int>* l3;

    int choice, index;

    decltype(l->element) x;
    decltype(l->element)* arr;
    int s2;


    do {
        cout << "\nMain Menu:\tChoose an operation\n\n";
        cout << "1. Display the linked list\n";
        cout << "2. Append an element to the linked list\n";
        cout << "3. Display number of elements in the linked list\n";
        cout << "4. Find Sum of all values in the linked list\n";
        cout << "5. Find Maximum value in the linked list\n";
        cout << "6. Find Minimum value in the linked list\n";
        cout << "7. Perform simple linear search on the linked list\n";
        cout << "8. Perform Move-to-Head linear search on the linked list\n";
        cout << "9. Insert an element into the linked list\n";
        cout << "10. Insert an element into a sorted linked list\n";
        cout << "11. Delete an element from the linked list\n";
        cout << "12. Checking if the linked list is sorted or not\n";
        cout << "13. Remove duplicate elements from a sorted linked list\n";
        cout << "14. Reversing the linked list by reversing elements\n";
        cout << "15. Reversing the linked list by reversing links\n";
        cout << "16. Reversing the linked list by reversing links using Recursion\n";
        cout << "17. Concatenating two linked lists\n";
        cout << "18. Merging two linked lists\n";
        cout << "19. Checking if the linked list contains a LOOP or not\n";
        cout << "20. Exit Menu\n\n";

        cin >> choice;

        switch (choice) {
        case 1: // Displaying the elements of linked list
            cout << "Elements of the linked list are: ";
            l->Display();
            // or, use l->RecursiveDisplay(l->getFirst());
            break;

        case 2: // Appending an element to the linked list
            cout << "Please enter an element: ";
            cin >> x;
            l->Append(x);
            cout << x << " appended to the linked list" << endl;
            break;

        case 3: // Displaying number of elements in the linked list
            cout << "Number of elements in the linked list is: " << l->getLength() << endl;
            // or, use l->getLengthRecursive(l->getFirst());
            break;

        case 4: // Find Sum of all values in the linked list
            cout << "Sum of all elements in the linked list is: " << l->Sum() << endl;
            // or, use l->SumRecursive(l->getFirst());
            break;

        case 5: // Find Maximum value in the linked list
            cout << "Maximum value in the linked list is: " << l->MaxValue() << endl;
            break;

        case 6: // Find Minimum value in the linked list
            cout << "Minimum value in the linked list is: " << l->MinValue() << endl;
            break;

         case 7: // Linear Search for an element in the linked list
            cout << "Please enter an element: ";
            cin >> x;
            if (auto node = l->LinearSearch(x)) {
                cout << x << " is found at address: " << node << endl;
            }
            else {
                cout << x << " not found" << endl;
            }
            break;

         case 8: // Modified Linear Search using Move To Head method
             cout << "Please enter an element: ";
             cin >> x;
             if (auto node = l->LinearSearchMoveToHead(x)) {
                 cout << x << " is found at address: " << node << endl;
             }
             else {
                 cout << x << " not found" << endl;
             }
             break;

        case 9: // Inserting an element at a given index
            cout << "Please enter an index: ";
            cin >> index;
            cout << "Please enter an element: ";
            cin >> x;
            l->Insert(index, x);
            cout << x << " inserted at the index " << index << endl;
            break;

        case 10: // Inserting an element in a sorted linked list
            cout << "Please enter an element: ";
            cin >> x;
            l->InsertSorted(x);
            cout << x << " inserted into the linked list" << endl;
            break;

        case 11: // Deleting an element from the linked list
            cout << "Please enter an index: ";
            cin >> index;
            cout << l->Delete(index) << " deleted from the linked list" << endl;
            break;

        case 12: // Checking if the linked list is sorted or not
            if (l->IsSorted()) {
                cout << "Linked List is sorted" << endl;
            }
            else {
                cout << "Linked List is not sorted" << endl;
            }
            break;

        case 13: // Removing duplicate elements from a sorted linked list
            l->RemoveDuplicates();
            cout << "Duplicates removed from the linked list" << endl;
            break;

        case 14: // Reversing the linked list by reversing elements
            l->ReverseElements();
            cout << "Linked List Reversed" << endl;
            break;
        
        case 15: // Reversing the linked list by reversing links
            l->ReverseLinks();
            cout << "Linked List Reversed" << endl;
            break;

        case 16: // Reversing the linked list by reversing links using Recursion
            l->ReverseLinksRecursion(NULL, l->getFirst());
            cout << "Linked List Reversed" << endl;
            break;

        case 17: // Concatenating two linked lists
            cout << "Please enter the size of second linked list: ";
            cin >> s2;
            arr = new int[s2];
            cout << "Please enter the elements in second linked list: ";
            for (int i = 0; i < s2; i++) {
                cin >> arr[i];
            }
            l2 = new LinkedList<int>(arr, s2);
            delete[]arr;

            l3 = l->Concatenate(l2);

            cout << "Elements of first linked list are: ";
            l->Display();
            cout << "Elements of second linked list are: ";
            l2->Display();
            cout << "Elements of the concatenated linked list are: ";
            l3->Display();
            break;

        case 18: // Merging two linked lists
            cout << "Please enter the size of second linked list: ";
            cin >> s2;
            arr = new decltype(l->element)[s2];
            cout << "Please enter the elements in second linked list: ";
            for (int i = 0; i < s2; i++) {
                cin >> arr[i];
            }
            l2 = new LinkedList<int>(arr, s2);
            delete[]arr;

            l3 = l->Merge(l2);

            cout << "Elements of first linked list are: ";
            l->Display();
            cout << "Elements of second linked list are: ";
            l2->Display();
            cout << "Elements of the merged linked list are: ";
            l3->Display();
            break;

        case 19: // Checking if the linked list contains a LOOP or not
            /*Node<int>* t1 = (l->getFirst())->next;
            Node<int>* t2 = l->getFirst()->next->next->next->next;
            t2->next = t1;*/
            if (l->IsLoop()) {
                cout << "Linked List contains a LOOP" << endl;
            }
            else {
                cout << "Linked List does not contain a LOOP" << endl;
            }
            break;

        }

    } while (choice < 20);

    return 0;
}
