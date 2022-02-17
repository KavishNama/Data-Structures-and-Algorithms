#include <iostream>
using namespace std;


int factorialRecursion(int n) {
    if (n >= 1) {
        return factorialRecursion(n - 1) * n;
    }
    else {
        return 1;
    }
}

int factorialLoop(int n) {
    int product = 1;
    for (int i = 1; i <= n; i++) {
        product *= i;
    }
    return product;
}

int main()
{
    cout << "Factorial of 5 using recursion is " << factorialRecursion(5) << endl;
    cout << "Factorial of 5 using looping is " << factorialLoop(5) << endl;
    return 0;
}
