#include <iostream>
using namespace std;

class Term {
public:
    int coeff;
    int exp;
};

class Polynomial {
private:
    int n;
    Term* t;

public:

    // Parameterized Constructor
    Polynomial(int n);

    // Destructor
    ~Polynomial();

    // Function prototypes
    void Create();
    void Display();
    void Evaluate(int x);
    Polynomial* Add(Polynomial* p);

};

Polynomial::Polynomial(int n) {
    this->n = n;
    t = new Term[this->n];
}

Polynomial::~Polynomial() {
    delete[]t;
}

// Function to create a polynomial
void Polynomial::Create() {
    cout << "Please enter the coefficients and exponents in the given format: (Coeff) (Exponent)" << endl;
    for (int i = 0; i < n; i++) {
        cin >> t[i].coeff >> t[i].exp;
    }
    cout << endl;
}

// Function to display the polynomial
void Polynomial::Display() {
    for (int i = 0; i < n; i++) {
        if (t[i].exp != 0) {
            cout << t[i].coeff << "x^" << t[i].exp;
        }
        else {
            cout << t[i].coeff;
        }
        if (i != n - 1) {
            cout << " + ";
        }
    }
    cout << endl;
}

// Function to evaluate the value of a polynomial
void Polynomial::Evaluate(int x) {
    cout << "The value of the polynomial when x = " << x << " is: ";
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += t[i].coeff * pow(x, t[i].exp);
    }
    cout << sum << endl;
}

// Function to add two polynomials
Polynomial* Polynomial::Add(Polynomial* p) {
    int i, j, k;

    Polynomial* sum = new Polynomial(n+p->n);
    i = j = k = 0;
    while (i < n && j < p->n) {
        if (t[i].exp > p->t[j].exp) {
            sum->t[k] = t[i];
            k++;
            i++;
        }
        else if (t[i].exp < p->t[j].exp) {
            sum->t[k] = p->t[i];
            k++;
            j++;
        }
        else {
            sum->t[k].exp = t[i].exp;
            sum->t[k].coeff = t[i].coeff+p->t[j].coeff;
            k++;
            i++;
            j++;
        }
    }

    for (; i < n; i++) {
        sum->t[k] = t[i];
        k++;
    }

    for (; j < p->n; j++) {
        sum->t[k] = p->t[j];
        k++;
    }

    sum->n = k;

    return sum;
}

int main()
{
    int n;
    cout << "Please enter the number of non-zero terms: " << endl;
    cin >> n;
    Polynomial* P = new Polynomial(n);

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
            // or, use cin>>P; by overloading extraction operator
            break;

        case 2: // Displaying the Polynomial
            cout << "The polynomial is: " << endl;
            P->Display();
            // or, use cout<<P; by overloading insertion operator
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
            Polynomial* P2 = new Polynomial(n);
            P2->Create();

            Polynomial* Sum = P->Add(P2);
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