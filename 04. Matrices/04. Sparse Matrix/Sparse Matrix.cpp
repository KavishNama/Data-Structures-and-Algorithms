#include <iostream>
using namespace std;

class Element {
public:
    int i;
    int j;
    int x;
};

class Sparse {
private:
    int m;
    int n;
    int numEle;
    Element* ele;
    
public:

    // Parameterized Constructor
    Sparse(int m, int n, int eleNum);

    // Destructor
    ~Sparse();

    // Function prototypes
    void Create();
    void Display();
    Sparse* Add(Sparse* s);

    // // Overloading Extraction and Insertion Operators
    friend istream& operator>>(istream& is, Sparse& s);
    friend ostream& operator<<(ostream& os, Sparse& s);

};

Sparse::Sparse(int m, int n, int numEle) {
    this->m = m;
    this->n = n;
    this->numEle = numEle;
    ele = new Element[this->numEle];
}

Sparse::~Sparse() {
    delete[]ele;
}

// Function to create a sparse matrix
void Sparse::Create() {
    cout << "Please enter the non-zero elements in the given format: (Row No) (Col No) (Element)" << endl;
    for (int i = 0; i < numEle; i++) {
        cin >> ele[i].i >> ele[i].j >> ele[i].x;
    }
    cout << endl;
}

// Function to display the sparse matrix
void Sparse::Display() {
    int k = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (ele[k].i == i && ele[k].j == j) {
                cout << ele[k].x << " ";
                k++;
            }
            else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

// Overloaded Extraction Operator to create a sparse matrix
istream& operator>>(istream& is, Sparse& s) {
    cout << "Please enter the non-zero elements in the given format: (Row No) (Col No) (Element)" << endl;
    for (int i = 0; i < s.numEle; i++) {
        cin >> s.ele[i].i >> s.ele[i].j >> s.ele[i].x;
    }
    cout << endl;
    return is;
}

// Overloaded Insertion Operator to display the sparse matrix
ostream& operator<<(ostream& os, Sparse& s) {
    int k = 0;
    for (int i = 0; i < s.m; i++) {
        for (int j = 0; j < s.n; j++) {
            if (s.ele[k].i == i && s.ele[k].j == j) {
                cout << s.ele[k].x << " ";
                k++;
            }
            else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
    return os;
}

// Function to add two sparse matrices
Sparse* Sparse::Add(Sparse *s) {
    int i, j, k;
    if (m != s->m || n!= s->n) {
        return new Sparse(0, 0, 0);
    }

    Sparse* sum = new Sparse(m, n, numEle + s->numEle);
    i = j = k = 0;
    while (i < numEle && j < s->numEle) {
        if (ele[i].i < s->ele[j].i) {
            sum->ele[k] = ele[i];
            k++;
            i++;
        }
        else if (ele[i].i > s->ele[j].i) {
            sum->ele[k] = s->ele[j];
            k++;
            j++;
        }
        else {
            if (ele[i].j < s->ele[j].j) {
                sum->ele[k] = ele[i];
                k++;
                i++;
            }
            else if (ele[i].j > s->ele[j].j) {
                sum->ele[k] = s->ele[j];
                k++;
                j++;
            }
            else {
                sum->ele[k] = ele[i];
                sum->ele[k].x = ele[i].x + s->ele[j].x;
                i++;
                j++;
                k++;
            }
        }
    }

    for (; i < numEle; i++) {
        sum->ele[k] = ele[i];
        k++;
    }

    for (; j < s->numEle; j++) {
        sum->ele[k] = s->ele[j];
        k++;
    }

    sum->numEle = k;

    return sum;    
}

int main()
{
    int m, n, numEle;
    cout << "Please enter the dimension of matrix, m and n: " << endl;
    cin >> m >> n;
    cout << "Please enter the number of non-zero elements: " << endl;
    cin >> numEle;
    Sparse *S = new Sparse(m, n, numEle);

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
            // or, use cin>>S; by overloading extraction operator
            break;

        case 2: // Displaying the Sparse matrix
            cout << "Elements of the Sparse Matrix are: " << endl;
            S->Display();
            // or, use cout<<S; by overloading insertion operator
            break;

        case 3: // Adding two sparse matrices
            cout << "Please enter the dimension of second matrix, m and n: " << endl;
            cin >> m >> n;
            cout << "Please enter the number of non-zero elements in second matrix: " << endl;
            cin >> numEle;
            Sparse* S2 = new Sparse(m, n, numEle);
            S2->Create();

            Sparse *Sum = S->Add(S2);
            cout << "First Matrix:" << endl;
            S->Display();
            cout << "Second Matrix:" << endl;
            S2->Display();
            cout << "Sum Matrix:" << endl;
            Sum->Display();
            break;

        }

    } while (choice < 4);

    return 0;
}
