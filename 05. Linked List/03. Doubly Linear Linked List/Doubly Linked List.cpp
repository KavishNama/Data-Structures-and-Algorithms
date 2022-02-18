#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;
};

template <class T>
class DoublyLinkedList {
private:
    Node<T>* first;

public:
    T element;

    // Default Constructor 
    DoublyLinkedList();

    // Parameterized Constructor
    DoublyLinkedList(T A[], int n);

    // Destructor
    ~DoublyLinkedList();

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
    void Reverse();
    DoublyLinkedList<T>* Concatenate(DoublyLinkedList<T>* l2);
    DoublyLinkedList<T>* Merge(DoublyLinkedList<T>* l2);

};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {
    first = NULL;
}

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(T A[], int n) {
    Node<T>* last, * t;
    int i = 0;
    first = new Node<T>;
    first->data = A[0];
    first->prev = NULL;
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++) {
        t = new Node<T>;
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Node<T>* p = first;
    while (first) {
        first = first->next;
        delete p;
        p = first;
    }
}

// Helper function to get the first node of doubly linked list
template <class T>
Node<T>* DoublyLinkedList<T>::getFirst() {
    return first;
}

// Function to display the contents of doubly linked list
template <class T>
void DoublyLinkedList<T>::Display() {
    Node<T>* p = first;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// Function to display the contents of doubly linked list using Recursion
template <class T>
void DoublyLinkedList<T>::RecursiveDisplay(Node<T>* p) {
    if (p != NULL) {
        cout << p->data << " ";
        RecursiveDisplay(p->next);
    }
}

// Function to append an element at the end of doubly linked list
template <class T>
void DoublyLinkedList<T>::Append(T x) {
    Node<T>* t = new Node<T>;
    t->data = x;
    t->next = NULL;
    t->prev = NULL;

    if (first == NULL) {
        first = t;
    }
    else {
        Node<T>* p = first;
        while (p->next != NULL) {
            p = p->next;
        }
        t->next = p->next;
        t->prev = p;
        p->next = t;
    }
}

// Helper function to get length of doubly linked list
template <class T>
int DoublyLinkedList<T>::getLength() {
    Node<T>* p = first;
    int len = 0;
    while (p != NULL) {
        len++;
        p = p->next;
    }
    return len;
}

// Helper function to get length of doubly linked list using Recursion
template <class T>
int DoublyLinkedList<T>::getLengthRecursive(Node<T>* p) {
    if (p != NULL) {
        return 1 + getLengthRecursive(p->next);
    }
    else {
        return 0;
    }
}

// Function to find sum of all values in doubly linked list
template <class T>
T DoublyLinkedList<T>::Sum() {
    Node<T>* p = first;
    T sum = 0;
    while (p != NULL) {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

// Function to find sum of all values in doubly linked list using Recursion
template <class T>
T DoublyLinkedList<T>::SumRecursive(Node<T>* p) {
    if (p != NULL) {
        return p->data + SumRecursive(p->next);
    }
    else {
        return 0;
    }
}

// Function to find maximum value in doubly linked list
template <class T>
T DoublyLinkedList<T>::MaxValue() {
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

// Function to find minimum value in doubly linked list
template <class T>
T DoublyLinkedList<T>::MinValue() {
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

// Function to perform linear search on doubly linked list
template <class T>
Node<T>* DoublyLinkedList<T>::LinearSearch(T key) {
    Node<T>* p = first;
    while (p != NULL) {
        if (key == p->data) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

// Function to perform linear search on doubly linked list using Move to Head
template <class T>
Node<T>* DoublyLinkedList<T>::LinearSearchMoveToHead(T key) {
    Node<T>* p = first, * q = NULL;
    while (p != NULL) {
        if (key == p->data) {
            if (p == first) {
                return p;
            }
            q->next = p->next;
            p->next = first;
            p->prev = first->prev;
            first->prev = p;
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
void DoublyLinkedList<T>::Insert(int index, T x) {
    if (index < 0 || index > getLength()) {
        return;
    }
    Node<T>* p = first;
    Node<T>* t = new Node<T>;
    t->data = x;

    if (index == 0) {
        t->next = first;
        t->prev = NULL;
        if (first != NULL) {
            first->prev = t;
        }
        first = t;
    }
    else {
        for (int i = 0; i < index - 1; i++) {
            p = p->next;
        }
        t->next = p->next;
        t->prev = p;
        if (p->next != NULL) {
            (p->next)->prev = t;
        }
        p->next = t;
    }

}

// Function to insert an element in a sorted linked list
template <class T>
void DoublyLinkedList<T>::InsertSorted(T x) {
    Node<T>* p = first, * q = NULL;
    Node<T>* t = new Node<T>;
    t->data = x;
    t->next = NULL;
    t->prev = NULL;
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
            first->prev = t;
            first = t;
        }
        else {
            t->next = p;
            t->prev = q;
            q->next = t;
            if (p != NULL) {
                p->prev = t;
            }
        }
    }
}

// Function to delete an element from doubly linked list
template <class T>
T DoublyLinkedList<T>::Delete(int index) {
    T x = -1;
    if (index < 1 || index > getLength()) {
        return x;
    }
    Node<T>* p, * q = NULL;

    if (index == 1) {
        p = first;
        x = first->data;
        first = first->next;
        delete p;
        if (first != NULL) {
            first->prev = NULL;
        }
    }
    else {
        p = first;
        for (int i = 0; i < index - 1; i++) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        if (p->next != NULL) {
            (p->next)->prev = q;
        }
        x = p->data;
        delete p;
    }
    return x;
}

// Function to check if doubly linked list is sorted or not
template <class T>
bool DoublyLinkedList<T>::IsSorted() {
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

// Function to remove the duplicates in a sorted doubly linked list
template <class T>
void DoublyLinkedList<T>::RemoveDuplicates() {
    Node<T>* p = first;
    if (p == NULL) {
        return;
    }
    Node<T>* q = p->next;
    while (q != NULL) {
        if (p->data != q->data) {
            p = q;
            q = q->next;
        }
        else {
            p->next = q->next;
            if (q->next != NULL) {
                (q->next)->prev = p;
            }
            delete q;
            q = p->next;
        }
    }
}

// Function to reverse a doubly linked list by reversing links
template <class T>
void DoublyLinkedList<T>::Reverse() {
    Node<T>* p = first, * temp;
    while (p != NULL) {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if (p != NULL && p->next == NULL) {
            first = p;
        }
    }
}

// Function to concatenate two linked lists
template <class T>
DoublyLinkedList<T>* DoublyLinkedList<T>::Concatenate(DoublyLinkedList<T>* l2) {
    Node<T>* p = first;
    Node<T>* q = l2->first;
    DoublyLinkedList<T>* l3 = new DoublyLinkedList<T>();

    while (p != NULL) {
        l3->Append(p->data);
        p = p->next;
    }
    while (q != NULL) {
        l3->Append(q->data);
        q = q->next;
    }
    return l3;
}

// Function to merge two linked lists
template <class T>
DoublyLinkedList<T>* DoublyLinkedList<T>::Merge(DoublyLinkedList<T>* l2) {
    Node<T>* p = first;
    Node<T>* q = l2->first;
    DoublyLinkedList<T>* l3 = new DoublyLinkedList<T>();

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
        while (p != NULL) {
            l3->Append(p->data);
            p = p->next;
        }
    }
    else {
        while (q != NULL) {
            l3->Append(q->data);
            q = q->next;
        }
    }

    return l3;
}


int main()
{
    DoublyLinkedList<int>* l = new DoublyLinkedList<int>();
    DoublyLinkedList<int>* l2;
    DoublyLinkedList<int>* l3;

    int choice, index;

    decltype(l->element) x;
    decltype(l->element)* arr;
    int s2;


    do {
        cout << "\nMain Menu:\tChoose an operation to be performed on Doubly Linked List\n\n";
        cout << "1. Display\n";
        cout << "2. Append an element\n";
        cout << "3. Display number of elements\n";
        cout << "4. Find Sum of all values\n";
        cout << "5. Find Maximum value\n";
        cout << "6. Find Minimum value\n";
        cout << "7. Perform simple linear search\n";
        cout << "8. Perform Move-to-Head linear search\n";
        cout << "9. Insert an element at a given index\n";
        cout << "10. Insert an element into a sorted doubly linked list\n";
        cout << "11. Delete an element\n";
        cout << "12. Checking if the doubly linked list is sorted or not\n";
        cout << "13. Remove duplicate elements from a sorted doubly linked list\n";
        cout << "14. Reverse\n";
        cout << "15. Concatenating two doubly linked lists\n";
        cout << "16. Merging two doubly linked lists\n";
        cout << "17. Exit Menu\n\n";

        cin >> choice;

        switch (choice) {
        case 1: // Displaying the elements of doubly linked list
            cout << "Elements of the doubly linked list are: ";
            l->Display();
            // or, use l->RecursiveDisplay(l->getFirst());
            break;

        case 2: // Appending an element to the doubly linked list
            cout << "Please enter an element: ";
            cin >> x;
            l->Append(x);
            cout << x << " appended to the doubly linked list" << endl;
            break;

        case 3: // Displaying number of elements in the doubly linked list
            cout << "Number of elements in the doubly linked list is: " << l->getLength() << endl;
            // or, use l->getLengthRecursive(l->getFirst());
            break;

        case 4: // Find Sum of all values in the doubly linked list
            cout << "Sum of all elements in the doubly linked list is: " << l->Sum() << endl;
            // or, use l->SumRecursive(l->getFirst());
            break;

        case 5: // Find Maximum value in the doubly linked list
            cout << "Maximum value in the doubly linked list is: " << l->MaxValue() << endl;
            break;

        case 6: // Find Minimum value in the doubly linked list
            cout << "Minimum value in the doubly linked list is: " << l->MinValue() << endl;
            break;

        case 7: // Linear Search for an element in the doubly linked list
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

        case 10: // Inserting an element in a sorted doubly linked list
            cout << "Please enter an element: ";
            cin >> x;
            l->InsertSorted(x);
            cout << x << " inserted into the doubly linked list" << endl;
            break;

        case 11: // Deleting an element from the doubly linked list
            cout << "Please enter an index: ";
            cin >> index;
            cout << l->Delete(index) << " deleted from the doubly linked list" << endl;
            break;

        case 12: // Checking if the doubly linked list is sorted or not
            if (l->IsSorted()) {
                cout << "Doubly Linked List is sorted" << endl;
            }
            else {
                cout << "Doubly Linked List is not sorted" << endl;
            }
            break;

        case 13: // Removing duplicate elements from a sorted doubly linked list
            l->RemoveDuplicates();
            cout << "Duplicates removed from the doubly linked list" << endl;
            break;

        case 14: // Reversing the doubly linked list by reversing links
            l->Reverse();
            cout << "Doubly Linked List Reversed" << endl;
            break;

        case 15: // Concatenating two doubly linked lists
            cout << "Please enter the size of second doubly linked list: ";
            cin >> s2;
            arr = new int[s2];
            cout << "Please enter the elements in second doubly linked list: ";
            for (int i = 0; i < s2; i++) {
                cin >> arr[i];
            }
            l2 = new DoublyLinkedList<int>(arr, s2);
            delete[]arr;

            l3 = l->Concatenate(l2);

            cout << "Elements of first doubly linked list are: ";
            l->Display();
            cout << "Elements of second doubly linked list are: ";
            l2->Display();
            cout << "Elements of the concatenated doubly linked list are: ";
            l3->Display();
            break;

        case 16: // Merging two doubly linked lists
            cout << "Please enter the size of second doubly linked list: ";
            cin >> s2;
            arr = new decltype(l->element)[s2];
            cout << "Please enter the elements in second doubly linked list: ";
            for (int i = 0; i < s2; i++) {
                cin >> arr[i];
            }
            l2 = new DoublyLinkedList<int>(arr, s2);
            delete[]arr;

            l3 = l->Merge(l2);

            cout << "Elements of first doubly linked list are: ";
            l->Display();
            cout << "Elements of second doubly linked list are: ";
            l2->Display();
            cout << "Elements of the merged doubly linked list are: ";
            l3->Display();
            break;

        }

    } while (choice < 17);

    return 0;
}
