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
class DoublyCircularLinkedList {
private:
    Node<T>* head;

public:
    T element;

    // Default Constructor 
    DoublyCircularLinkedList();

    // Parameterized Constructor
    DoublyCircularLinkedList(T A[], int n);

    // Destructor
    ~DoublyCircularLinkedList();

    // Function prototypes
    Node<T>* getHead();
    void Display();
    void RecursiveDisplay(Node<T>* h);
    void Append(T x);
    int getLength();
    T Sum();
    T MaxValue();
    T MinValue();
    void Insert(int index, T x);
    T Delete(int index);
    Node<T>* LinearSearch(T key);
    bool IsSorted();
    void Reverse();

};

template <class T>
DoublyCircularLinkedList<T>::DoublyCircularLinkedList() {
    head = NULL;
}

template <class T>
DoublyCircularLinkedList<T>::DoublyCircularLinkedList(T A[], int n) {
    Node<T>* last, * t;
    int i = 0;
    head = new Node<T>;
    head->data = A[0];
    head->next = head;
    head->prev = head;
    last = head;

    for (i = 1; i < n; i++) {
        t = new Node<T>;
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        head->prev = t;
        last = t;
    }
}

template <class T>
DoublyCircularLinkedList<T>::~DoublyCircularLinkedList() {
    Node<T>* h = head;

    if (head != NULL) {
        while (head->next != head) {
            head = head->next;
            (h->prev)->next = head;
            head->prev = h->prev;
            delete h;
            h = head;
        }
        if (head->next == head) {
            delete h;
        }
    }
    
}

// Helper function to get the head of doubly circular linked list
template <class T>
Node<T>* DoublyCircularLinkedList<T>::getHead() {
    return head;
}

// Function to display the contents of doubly circular linked list
template <class T>
void DoublyCircularLinkedList<T>::Display() {
    Node<T>* h = head;
    if (head == NULL) {
        return;
    }
    do {
        cout << h->data << " ";
        h = h->next;
    } while (h != head);
    cout << endl;
}

// Function to display the contents of doubly circular linked list using Recursion
template <class T>
void DoublyCircularLinkedList<T>::RecursiveDisplay(Node<T>* h) {
    if (h == NULL) {
        return;
    }
    static bool flag = false;
    if (h != head || !flag) {
        flag = true;
        cout << h->data << " ";
        RecursiveDisplay(h->next);
    }
    flag = false;
}

// Function to append an element to doubly circular linked list
template <class T>
void DoublyCircularLinkedList<T>::Append(T x) {
    Node<T>* t = new Node<T>;
    t->data = x;

    if (head == NULL) {
        head = t;
        head->next = head;
        head->prev = head;
    }
    else {
        (head->prev)->next = t;
        t->prev = head->prev;
        t->next = head;
        head->prev = t;
    }
}

// Helper function to get length of doubly circular linked list
template <class T>
int DoublyCircularLinkedList<T>::getLength() {
    Node<T>* h = head;
    int len = 0;
    if (head == NULL) {
        return len;
    }
    do {
        len++;
        h = h->next;
    } while (h != head);

    return len;
}

// Function to find sum of all values in doubly circular linked list
template <class T>
T DoublyCircularLinkedList<T>::Sum() {
    Node<T>* h = head;
    T sum = 0;
    if (head == NULL) {
        return sum;
    }
    do {
        sum += h->data;
        h = h->next;
    } while (h != head);

    return sum;
}

// Function to find maximum value in doubly circular linked list
template <class T>
T DoublyCircularLinkedList<T>::MaxValue() {
    Node<T>* h = head;
    T max = INT_MIN;
    if (head == NULL) {
        return max;
    }
    do {
        if (h->data > max) {
            max = h->data;
        }
        h = h->next;
    } while (h != head);

    return max;
}

// Function to find minimum value in doubly circular linked list
template <class T>
T DoublyCircularLinkedList<T>::MinValue() {
    Node<T>* h = head;
    T min = INT_MAX;
    if (head == NULL) {
        return min;
    }
    do {
        if (h->data < min) {
            min = h->data;
        }
        h = h->next;
    } while (h != head);

    return min;
}

// Function to insert an element at a given index
template <class T>
void DoublyCircularLinkedList<T>::Insert(int index, T x) {
    if (index < 0 || index > getLength()) {
        return;
    }
    Node<T>* h = head;
    Node<T>* t = new Node<T>;
    t->data = x;

    if (index == 0) {
        if (head == NULL) {
            head = t;
            head->next = head;
            head->prev = head;
        }
        else {
            (head->prev)->next = t;
            t->next = head;
            t->prev = head->prev;
            head->prev = t;
            head = t;
        }
    }
    else {
        for (int i = 0; i < index - 1; i++) {
            h = h->next;
        }
        t->next = h->next;
        t->prev = h;
        (h->next)->prev = t;
        h->next = t;
    }
}

// Function to delete an element from the doubly circular linked list
template <class T>
T DoublyCircularLinkedList<T>::Delete(int index) {
    T x = -1;
    if (index < 1 || index > getLength()) {
        return x;
    }
    Node<T>* h, * q = NULL;

    if (index == 1) {
        h = head;
        x = head->data;
        if (head->prev == head) {
            delete head;
            head = NULL;
        }
        else {
            (head->prev)->next = head->next;
            (head->next)->prev = head->prev;
            head = head->next;
            delete h;
        }
    }
    else {
        h = head;
        for (int i = 0; i < index - 2; i++) {
            h = h->next;
        }
        q = h->next;
        h->next = q->next;
        (q->next)->prev = h;
        x = q->data;
        delete q;
    }
    return x;
}

// Function to perform linear search on doubly circular linked list
template <class T>
Node<T>* DoublyCircularLinkedList<T>::LinearSearch(T key) {
    Node<T>* h = head;
    if (head == NULL) {
        return NULL;
    }
    do {
        if (key == h->data) {
            return h;
        }
        h = h->next;
    } while (h != head);

    return NULL;
}

// Function to check if doubly circular linked list is sorted or not
template <class T>
bool DoublyCircularLinkedList<T>::IsSorted() {
    T x = INT_MIN;
    Node<T>* h = head;
    if (head == NULL) {
        return false;
    }
    do {
        if (h->data < x) {
            return false;
        }
        x = h->data;
        h = h->next;
    } while (h != head);
    return true;
}

// Function to reverse a doubly circular linked list by Reversing links
template <class T>
void DoublyCircularLinkedList<T>::Reverse() {
    Node<T>* p = head, * q = NULL, * r = NULL;
    if (head == NULL) {
        return;
    }
    q = head->prev;
    r = head->prev->prev;
    do {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
        q->prev = p;
    } while (p != head);
    head = q;
}


int main()
{
    DoublyCircularLinkedList<int>* l = new DoublyCircularLinkedList<int>();

    int choice, index;

    decltype(l->element) x;

    do {
        cout << "\nMain Menu:\tChoose an operation to perform on the doubly circular linked list\n\n";
        cout << "1. Display\n";
        cout << "2. Append an element\n";
        cout << "3. Display number of elements\n";
        cout << "4. Find Sum of all values\n";
        cout << "5. Find Maximum value\n";
        cout << "6. Find Minimum value\n";
        cout << "7. Insert an element at a given indext\n";
        cout << "8. Delete an element\n";
        cout << "9. Perform simple linear search\n";
        cout << "10. Checking if the doubly circular linked list is sorted or not\n";
        cout << "11. Reverse\n";
        cout << "12. Exit Menu\n\n";

        cin >> choice;

        switch (choice) {
        case 1: // Displaying the elements of doubly circular linked list
            cout << "Elements of the doubly circular linked list are: ";
            l->Display();
            // or, use l->RecursiveDisplay(l->getHead());
            break;

        case 2: // Appending an element to the doubly circular linked list
            cout << "Please enter an element: ";
            cin >> x;
            l->Append(x);
            cout << x << " appended to the doubly circular linked list" << endl;
            break;

        case 3: // Displaying number of elements in the doubly circular linked list
            cout << "Number of elements in the doubly circular linked list is: " << l->getLength() << endl;
            break;

        case 4: // Find Sum of all values in the doubly circular linked list
            cout << "Sum of all elements in the doubly circular linked list is: " << l->Sum() << endl;
            break;

        case 5: // Find Maximum value in the doubly circular linked list
            cout << "Maximum value in the doubly circular linked list is: " << l->MaxValue() << endl;
            break;

        case 6: // Find Minimum value in the doubly circular linked list
            cout << "Minimum value in the doubly circular linked list is: " << l->MinValue() << endl;
            break;

        case 7: // Inserting an element at a given index
            cout << "Please enter an index: ";
            cin >> index;
            cout << "Please enter an element: ";
            cin >> x;
            l->Insert(index, x);
            cout << x << " inserted at the index " << index << endl;
            break;

        case 8: // Deleting an element from the doubly circular linked list
            cout << "Please enter an index: ";
            cin >> index;
            cout << l->Delete(index) << " deleted from the doubly circular linked list" << endl;
            break;

        case 9: // Linear Search for an element in the doubly circular linked list
            cout << "Please enter an element: ";
            cin >> x;
            if (auto node = l->LinearSearch(x)) {
                cout << x << " is found at address: " << node << endl;
            }
            else {
                cout << x << " not found" << endl;
            }
            break;

        case 10: // Checking if the doubly circular linked list is sorted or not
            if (l->IsSorted()) {
                cout << "Doubly Circular Linked List is sorted" << endl;
            }
            else {
                cout << "Doubly Circular Linked List is not sorted" << endl;
            }
            break;

        case 11: // Reversing the doubly circular linked list by reversing links
            l->Reverse();
            cout << "Circular Linked List Reversed" << endl;
            break;

        }

    } while (choice < 12);

    return 0;
}
