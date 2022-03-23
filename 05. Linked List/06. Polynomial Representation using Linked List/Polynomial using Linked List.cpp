#include <iostream>
using namespace std;

class Node {
public:
    int coeff;
    int exp;
    Node* next;
};

class PolynomialLL {
private:
    int n;
    Node* t;

public:

    // Default Constructor
    PolynomialLL(int n);

    // Destructor
    ~PolynomialLL();

    // Function prototypes
    void Create();
    void Display();
    void Evaluate(int x);
    PolynomialLL* Add(PolynomialLL* p);

};

PolynomialLL::PolynomialLL(int n) {
    this->n = n;
    t = NULL;
}

PolynomialLL::~PolynomialLL() {
    Node* p = t;
    while (t != NULL) {
        t = t->next;
        delete p;
        p = t;
    }
}

// Function to create a polynomial
void PolynomialLL::Create() {
    cout << "Please enter the coefficients and exponents in the given format: (Coeff) (Exponent)" << endl;
    for (int i = 0; i < n; i++) {
        Node* p = new Node;
        cin >> p->coeff;
        cin >> p->exp;
        p->next = NULL;
        if (t == NULL) {
            t = p;
        }
        else {
            Node* q = t;
            while (q->next != NULL) {
                q = q->next;
            }
            q->next = p;
        }
    }
    
    cout << endl;
}

// Function to display the polynomial
void PolynomialLL::Display() {
    Node* p = t;
    while (p != NULL) {
        if (p->exp != 0) {
            cout << p->coeff << "x^" << p->exp;
        }
        else {
            cout << p->coeff;
        }
        if (p->next != NULL) {
            cout << " + ";
        }
        p = p->next;
    }
    cout << endl;
}

// Function to evaluate the value of a polynomial
void PolynomialLL::Evaluate(int x) {
    Node* p = t;
    cout << "The value of the polynomial when x = " << x << " is: ";
    int sum = 0;
    while (p != NULL) {
        sum += p->coeff * pow(x, p->exp);
        p = p->next;
    }
    cout << sum << endl;
}

// Function to add two polynomials
PolynomialLL* PolynomialLL::Add(PolynomialLL* P) {
    Node* p = t;
    Node* q = P->t;

    PolynomialLL* sum = new PolynomialLL(n + P->n);

    while (p != NULL && q != NULL) {
        if (p->exp > q->exp) {
            Node* r = new Node;
            r->coeff = p->coeff;
            r->exp = p->exp;
            r->next = NULL;
            if (sum->t == NULL) {
                sum->t = r;
            }
            else {
                Node* s = sum->t;
                while (s->next != NULL) {
                    s = s->next;
                }
                s->next = r;
            }
            p = p->next;
        }
        else if (p->exp < q->exp) {
            Node* r = new Node;
            r->coeff = q->coeff;
            r->exp = q->exp;
            r->next = NULL;
            if (sum->t == NULL) {
                sum->t = r;
            }
            else {
                Node* s = sum->t;
                while (s->next != NULL) {
                    s = s->next;
                }
                s->next = r;
            }
            q = q->next;
        }
        else {
            Node* r = new Node;
            r->coeff = p->coeff + q->coeff;
            r->exp = p->exp;
            r->next = NULL;
            if (sum->t == NULL) {
                sum->t = r;
            }
            else {
                Node* s = sum->t;
                while (s->next != NULL) {
                    s = s->next;
                }
                s->next = r;
            }
            p = p->next;
            q = q->next;
        }
    }

    if (p == NULL) {
        while (q != NULL) {
            Node* r = new Node;
            r->coeff = q->coeff;
            r->exp = q->exp;
            r->next = NULL;
            if (sum->t == NULL) {
                sum->t = r;
            }
            else {
                Node* s = sum->t;
                while (s->next != NULL) {
                    s = s->next;
                }
                s->next = r;
            }
            q = q->next;
        }
    }
    else {
        while (p != NULL) {
            Node* r = new Node;
            r->coeff = p->coeff;
            r->exp = p->exp;
            r->next = NULL;
            if (sum->t == NULL) {
                sum->t = r;
            }
            else {
                Node* s = sum->t;
                while (s->next != NULL) {
                    s = s->next;
                }
                s->next = r;
            }
            p = p->next;
        }
    }

    sum->n = n + P->n;

    return sum;
}

int main()
{
    int n;
    cout << "Please enter the number of non-zero terms: " << endl;
    cin >> n;
    PolynomialLL* P = new PolynomialLL(n);

    int choice;

    do {
        cout << "\nMain Menu:\tChoose an operation to be performed on the Polynomial\n\n";
        cout << "1. Create\n";
        cout << "2. Display\n";
        cout << "3. Evaluate\n";
        cout << "4. Add two polynomials\n";
        cout << "5. Exit Menu\n\n";

        cin >> choice;

        switch (choice) {
        case 1: // Creating the Polynomial
            P->Create();
            break;

        case 2: // Displaying the Polynomial
            cout << "The polynomial is: " << endl;
            P->Display();
            break;

        case 3: // Evaluating the Polynomial
            cout << "Please enter the value of x: " << endl;
            int x;
            cin >> x;
            P->Evaluate(x);
            break;

        case 4: // Adding two polynomials
            cout << "Please enter the number of non-zero terms in second polynomial: " << endl;
            cin >> n;
            PolynomialLL* P2 = new PolynomialLL(n);
            P2->Create();

            PolynomialLL* Sum = P->Add(P2);
            cout << "First Polynomial:" << endl;
            P->Display();
            cout << "Second Polynomial:" << endl;
            P2->Display();
            cout << "Sum Polynomial:" << endl;
            Sum->Display();
            break;

        }

    } while (choice < 5);

    return 0;
}