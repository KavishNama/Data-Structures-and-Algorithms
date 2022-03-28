#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node<T>* next;

};

template <class T>
class Stack_LL {
private:
    Node<T>* top;

    //void swap(T* x, T* y);

public:
    T element;

    // Default Constructor 
    Stack_LL();

    // Destructor
    ~Stack_LL();

    // Function prototypes
    void Display();
    void Push(T x);
    T Pop();
    T Peek(int pos);
    bool isEmpty();
    bool isFull();
    T stackTop();
    bool isBalanced(char* exp);
    bool isBalancedComplex(char* exp);

    bool isOperand(char x);
    int precedence(char x);
    char* infixToPostfix(char* infix);

    bool isOperandComplex(char x);
    int outsidePrecedence(char x);
    int insidePrecedence(char x);
    char* infixToPostfixComplex(char* infix);

    int evaluate(char* postfix);

};

template <class T>
Stack_LL<T>::Stack_LL() {
    top = NULL;
}

template <class T>
Stack_LL<T>::~Stack_LL() {
    Node<T>* p = top;
    while (top) {
        top = top->next;
        delete p;
        p = top;
    }
}

//// Helper function to be used in other functions
//template <class T>
//void Array<T>::swap(T* x, T* y) {
//    T temp;
//    temp = *x;
//    *x = *y;
//    *y = temp;
//}

// Function to display the contents of the stack
template <class T>
void Stack_LL<T>::Display() {
    Node<T>* t = top;
    while (t) {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

// Function to push an element onto the stack
template <class T>
void Stack_LL<T>::Push(T x) {
    Node<T>* t = new Node<T>;
    if (t == NULL) {
        cout << "Stack Overflow. Unable to push!" << endl;
    }
    else {
        t->data = x;
        t->next = top;
        top = t;
        cout << x << " pushed onto the stack!" << endl;
    }
}

// Function to pop an element from the stack
template <class T>
T Stack_LL<T>::Pop() {
    Node<T>* t;
    T x = -1;
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

// Function to look an element at a given position in the stack
template <class T>
T Stack_LL<T>::Peek(int pos) {
    Node<T>* t = top;
    for (int i = 0; t != NULL && i < pos - 1; i++) {
        t = t->next;
    }
    if (t != NULL) {
        return t->data;
    }
    else{
        cout << "Invalid Position!" << endl;
    }
    return -1;
}

// Function to check if the stack is empty
template <class T>
bool Stack_LL<T>::isEmpty() {
    if (top == NULL) {
        return true;
    }
    else {
        return false;
    }
}

// Function to check if the stack is full
template <class T>
bool Stack_LL<T>::isFull() {
    Node<T>* t = new Node<T>;
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
T Stack_LL<T>::stackTop() {
    if (top != NULL) {
        return top->data;
    }
    else {
        return -1;
    }
}

// Function to check if the parenthesis are balanced or not, in a given expression
template <class T>
bool Stack_LL<T>::isBalanced(char* exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') {
            Push(exp[i]);
        }
        else if (exp[i] == ')') {
            if (top == NULL) {
                cout << "\nClosing parenthesis are greater than opening parenthesis. Hence, ";
                return false;
            }
            cout << Pop() << " poppped from the stack" << endl;
        }
    }
    if (top == NULL) {
        return true;
    }
    else {
        cout << "\nOpening parenthesis are greater than closing parenthesis. Hence, ";
        return false;
    }
}

// Function to check if the complex parenthesis are balanced or not, in a given expression
template <class T>
bool Stack_LL<T>::isBalancedComplex(char* exp) {
    T charElement;
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(') {
            Push(exp[i]);
        }
        else if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')') {
            if (top == NULL) {
                return false;
            }
            charElement = Pop();
            cout << charElement << " poppped from the stack" << endl;
            if (!(charElement == '{' && exp[i] == '}') && !(charElement == '[' && exp[i] == ']') && !(charElement == '(' && exp[i] == ')')) {
                return false;
            }
        }
    }
    if (top == NULL) {
        return true;
    }
    else {
        return false;
    }
}

// Helper function to be check if a character is Operand or Operator
template <class T>
bool Stack_LL<T>::isOperand(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/') {
        return false;
    }
    else {
        return true;
    }
}

// Helper function to find the precendence of a character
template <class T>
int Stack_LL<T>::precedence(char x) {
    if (x == '+' || x == '-') {
        return 1;
    }
    else if (x == '*' || x == '/') {
        return 2;
    }
    else {
        return 0;
    }
}

// Function to convert an Infix expression into Postfix expression
template <class T>
char* Stack_LL<T>::infixToPostfix(char* infix) {
    char* postfix;
    int len = strlen(infix);
    postfix = new char[len + 1];
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        if (isOperand(infix[i])) {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else {
            if (precedence(infix[i]) > precedence(stackTop())) {
                Push(infix[i]);
                i++;
            }
            else {
                postfix[j] = Pop();
                cout << postfix[j] << " popped from the stack!" << endl;
                j++;
            }
        }
    }
    while (top != NULL) {
        postfix[j] = Pop();
        cout << postfix[j] << " popped from the stack!" << endl;
        j++;
    }
    postfix[j] = '\0';
    return postfix;

}

// Helper function to be check if a character is Operand or Operator - Complex Version
template <class T>
bool Stack_LL<T>::isOperandComplex(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' || x == ')') {
        return false;
    }
    else {
        return true;
    }
}

// Helper function to find the precendence of a character when it is outside STACK
template <class T>
int Stack_LL<T>::outsidePrecedence(char x) {
    if (x == '+' || x == '-') {
        return 1;
    }
    else if (x == '*' || x == '/') {
        return 3;
    }
    else if (x == '^') {
        return 6;
    }
    else if (x == '(') {
        return 7;
    }
    else if (x == ')') {
        return 0;
    }
    else {
        return 0;
    }
}

// Helper function to find the precendence of a character when it is inside STACK
template <class T>
int Stack_LL<T>::insidePrecedence(char x) {
    if (x == '+' || x == '-') {
        return 2;
    }
    else if (x == '*' || x == '/') {
        return 4;
    }
    else if (x == '^') {
        return 5;
    }
    else if (x == '(') {
        return 0;
    }
    else {
        return 0;
    }
}

// Function to convert an Infix expression into Postfix expression - Complex Version
template <class T>
char* Stack_LL<T>::infixToPostfixComplex(char* infix) {
    char* postfix;
    int len = strlen(infix);
    postfix = new char[len + 1];
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        if (isOperandComplex(infix[i])) {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else {
            if (outsidePrecedence(infix[i]) > insidePrecedence(stackTop())) {
                Push(infix[i]);
                i++;
            }
            else if (outsidePrecedence(infix[i]) == insidePrecedence(stackTop())) {
                cout << Pop() << " popped from the stack!" << endl;
                i++;
            }
            else {
                postfix[j] = Pop();
                cout << postfix[j] << " popped from the stack!" << endl;
                j++;
            }
        }
    }
    while (top != NULL) {
        postfix[j] = Pop();
        cout << postfix[j] << " popped from the stack!" << endl;
        j++;
    }
    postfix[j] = '\0';
    return postfix;

}

// Function to evaluate a Postfix expression
template <class T>
int Stack_LL<T>::evaluate(char* postfix) {
    int x1, x2, r;
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isOperand(postfix[i])) {
            Push(postfix[i] - '0');
        }
        else {
            x2 = Pop();
            x1 = Pop();
            switch (postfix[i]) {
            case '+': r = x1 + x2;
                break;

            case '-': r = x1 - x2;
                break;

            case '*': r = x1 * x2;
                break;

            case '/': r = x1 / x2;
                break;
            }
            Push(r);
        }
    }

    return stackTop();

}


int main()
{
    Stack_LL<int>* stk;

    stk = new Stack_LL<int>;

    int choice, position;
    decltype(stk->element) x;

    char* expression;
    int sizeExp;

    Stack_LL<char>* stkExp;
    Stack_LL<int>* stkExp2;

    do {
        cout << "\nMain Menu:\tChoose an operation to be performed on the STACK\n\n";
        cout << "1. Display\n";
        cout << "2. Push\n";
        cout << "3. Pop\n";
        cout << "4. Peek\n";
        cout << "5. Check if the STACK is empty\n";
        cout << "6. Check if the STACK is full\n";
        cout << "7. Find the topmost value of STACK\n";
        cout << "8. Check if parenthesis are balanced\n";
        cout << "9. Check if complex parenthesis are balanced\n";
        cout << "10. Convert Infix to Postfix\n";
        cout << "11. Convert Infix to Postfix - Parenthesis and Associativity included\n";
        cout << "12. Evaluate a Postfix expression\n";
        cout << "13. Exit Menu\n\n";

        cin >> choice;

        switch (choice) {
        case 1: // Displaying the elements of the stack
            cout << "Elements of the stack are: ";
            stk->Display();
            break;

        case 2: // Pushing an element to the stack
            cout << "Please enter an element: ";
            cin >> x;
            stk->Push(x);
            break;

        case 3: // Popping an element from the stack
            x = stk->Pop();
            if (x != -1) {
                cout << x << " popped from the stack" << endl;
            }
            break;

        case 4: // Looking an element at a given position in the stack
            cout << "Please enter a position: ";
            cin >> position;
            x = stk->Peek(position);
            if (x != -1) {
                cout << x << " is present at position " << position << endl;
            }
            break;

        case 5: // Checking if the stack is empty
            if (stk->isEmpty()) {
                cout << "STACK is empty" << endl;
            }
            else {
                cout << "STACK is not empty" << endl;
            }
            break;

        case 6: // Checking if the stack is full
            if (stk->isFull()) {
                cout << "STACK is full" << endl;
            }
            else {
                cout << "STACK is not full" << endl;
            }
            break;

        case 7: // Finding the topmmost element in the stack
            x = stk->stackTop();
            if (x != -1) {
                cout << "Topmost element in the STACK: " << x << endl;
            }
            else {
                cout << "STACK is empty. No topmost element" << endl;
            }
            break;

        case 8: // Checking if parenthesis are balanced
            cout << "Please enter the size of the expression: ";
            cin >> sizeExp;
            expression = new char[sizeExp + 1];
            cout << "Please enter the expression: ";
            cin >> expression;

            stkExp = new Stack_LL<char>();
            if (stkExp->isBalanced(expression)) {
                cout << "\nParenthesis are balanced" << endl;
            }
            else {
                cout << "parenthesis are not balanced" << endl;
            }

            delete[]expression;
            break;

        case 9: // Checking if complex parenthesis are balanced
            cout << "Please enter the size of the expression: ";
            cin >> sizeExp;
            expression = new char[sizeExp + 1];
            cout << "Please enter the expression: ";
            cin >> expression;

            stkExp = new Stack_LL<char>();
            if (stkExp->isBalancedComplex(expression)) {
                cout << "\nParenthesis are balanced" << endl;
            }
            else {
                cout << "\nParenthesis are not balanced" << endl;
            }

            delete[]expression;
            break;

        case 10: // Converting Infix expression to Postfix expression
            cout << "Please enter the size of the expression: ";
            cin >> sizeExp;
            expression = new char[sizeExp + 1];
            cout << "Please enter the expression: ";
            cin >> expression;

            stkExp = new Stack_LL<char>();
            cout << "Infix Expression:\t" << expression << endl;
            cout << "Postfix Expression:\t" << stkExp->infixToPostfix(expression) << endl;

            delete[]expression;
            break;

        case 11: // Converting Infix expression to Postfix expression - Complex Version
            cout << "Please enter the size of the expression: ";
            cin >> sizeExp;
            expression = new char[sizeExp + 1];
            cout << "Please enter the expression: ";
            cin >> expression;

            stkExp = new Stack_LL<char>();
            cout << "Infix Expression:\t" << expression << endl;
            cout << "Postfix Expression:\t" << stkExp->infixToPostfixComplex(expression) << endl;

            delete[]expression;
            break;

        case 12: // Evaluating a Postfix expression
            cout << "Please enter the size of the expression: ";
            cin >> sizeExp;
            expression = new char[sizeExp + 1];
            cout << "Please enter the expression: ";
            cin >> expression;

            stkExp2 = new Stack_LL<int>();
            cout << "Result:\t" << stkExp2->evaluate(expression) << endl;

            delete[]expression;
            break;

        }

    } while (choice < 13);

    return 0;
}
