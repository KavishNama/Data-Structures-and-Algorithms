#include <iostream>
using namespace std;

class Node {
public:
    int col;
    int value;
    Node* next;
};

class SparseLL {
private:
    int m;
    int n;
    int numEle;
    Node** A;

public:

    // Parameterized Constructor
    SparseLL(int m, int n, int numEle);

    // Destructor
    ~SparseLL();

    // Function prototypes
    void Create();
    void Display();
    SparseLL* Add(SparseLL* s);
    
};

SparseLL::SparseLL(int m, int n, int numEle) {
    this->m = m;
    this->n = n;
    this->numEle = numEle;
    A = new Node*[this->m];
    for (int i = 0; i < m; i++) {
        A[i] = NULL;
    }
}

SparseLL::~SparseLL() {
    for (int i = 0; i < m; i++) {
        Node* p = A[i];
        while (p!=NULL) {
            A[i] = A[i]->next;
            delete p;
            p = A[i];
        }
    }
}

// Function to create a sparse matrix
void SparseLL::Create() {
    cout << "Please enter the non-zero elements in the given format: (Row No) (Col No) (Element)" << endl;
    int rownum;
    
    for (int i = 0; i < numEle; i++) {
        cin >> rownum;
        Node* p = new Node;
        cin >> p->col;
        cin >> p->value;
        p->next = NULL;
        if (A[rownum] == NULL) {
            A[rownum] = p;
        }
        else {
            Node* q = A[rownum];
            while (q->next != NULL) {
                q = q->next;
            }
            q->next = p;
        }
    }
    cout << endl;
}

// Function to display the sparse matrix
void SparseLL::Display() {
    for (int i = 0; i < m; i++) {
        Node* p = A[i];

        for (int j = 0; j < n; j++) {
            if (p != NULL) {
                if (j == p->col) {
                    cout << p->value << " ";
                    p = p->next;
                }
                else {
                    cout << 0 << " ";
                }
            }
            else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}


// Function to add two sparse matrices
SparseLL* SparseLL::Add(SparseLL* s) {
    int i, j;
    if (m != s->m || n != s->n) {
        cout << "Sparse Matrices cannot be added" << endl;
        return new SparseLL(0, 0, 0);
    }

    SparseLL* sum = new SparseLL(m, n, numEle + s->numEle);
    j = 0;
    for (i = 0; i < m; i++) {
        Node* p = A[i];
        Node* q = s->A[i];
        while (p != NULL && q != NULL) {
            if (p->col < q->col) {
                Node* t = new Node;
                t->col = p->col;
                t->value = p->value;
                t->next = NULL;
                if (sum->A[i] == NULL) {
                    sum->A[i] = t;
                }
                else {
                    Node* r = sum->A[i];
                    while (r->next != NULL) {
                        r = r->next;
                    }
                    r->next = t;
                }
                p = p->next;
            }
            else if (p->col > q->col) {
                Node* t = new Node;
                t->col = q->col;
                t->value = q->value;
                t->next = NULL;
                if (sum->A[i] == NULL) {
                    sum->A[i] = t;
                }
                else {
                    Node* r = sum->A[i];
                    while (r->next != NULL) {
                        r = r->next;
                    }
                    r->next = t;
                }
                q = q->next;
            }
            else {
                Node* t = new Node;
                t->col = p->col;
                t->value = p->value + q->value;
                t->next = NULL;
                if (sum->A[i] == NULL) {
                    sum->A[i] = t;
                }
                else {
                    Node* r = sum->A[i];
                    while (r->next != NULL) {
                        r = r->next;
                    }
                    r->next = t;
                }
                p = p->next;
                q = q->next;
            }
            j++;
        }



        if (p == NULL) {
            while (q != NULL) {
                Node* t = new Node;
                t->col = q->col;
                t->value = q->value;
                t->next = NULL;
                if (sum->A[i] == NULL) {
                    sum->A[i] = t;
                }
                else {
                    Node* r = sum->A[i];
                    while (r->next != NULL) {
                        r = r->next;
                    }
                    r->next = t;
                }
                q = q->next;
                j++;
            }
        }
        else {
            while (p != NULL) {
                Node* t = new Node;
                t->col = p->col;
                t->value = p->value;
                t->next = NULL;
                if (sum->A[i] == NULL) {
                    sum->A[i] = t;
                }
                else {
                    Node* r = sum->A[i];
                    while (r->next != NULL) {
                        r = r->next;
                    }
                    r->next = t;
                }
                p = p->next;
                j++;
            }
        }
    }

    
    sum->numEle = j;

    return sum;
}

int main()
{
    int m, n, numEle;
    cout << "Please enter the dimension of matrix, m and n: " << endl;
    cin >> m >> n;
    cout << "Please enter the number of non-zero elements: " << endl;
    cin >> numEle;
    SparseLL* S = new SparseLL(m, n, numEle);

    int choice;

    do {
        cout << "\nMain Menu:\tChoose an operation to be performed on Sparse Matrix\n\n";
        cout << "1. Create\n";
        cout << "2. Display\n";
        cout << "3. Add two sparse matrices\n";
        cout << "4. Exit Menu\n\n";

        cin >> choice;

        switch (choice) {
        case 1: // Creating the Sparse matrix
            S->Create();
            break;

        case 2: // Displaying the Sparse matrix
            cout << "Elements of the Sparse Matrix are: " << endl;
            S->Display();
            break;

        case 3: // Adding two sparse matrices
            cout << "Please enter the dimension of second matrix, m and n: " << endl;
            cin >> m >> n;
            cout << "Please enter the number of non-zero elements in second matrix: " << endl;
            cin >> numEle;
            SparseLL* S2 = new SparseLL(m, n, numEle);
            S2->Create();

            cout << "First Matrix: " << endl;
            S->Display();
            cout << "Second Matrix: " << endl;
            S2->Display();
            cout << "Sum Matrix: " << endl;

            SparseLL* Sum = S->Add(S2);
            Sum->Display();
            break;

        }

    } while (choice < 4);

    return 0;
}
