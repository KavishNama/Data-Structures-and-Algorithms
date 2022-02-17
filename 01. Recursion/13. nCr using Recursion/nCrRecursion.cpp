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

int nCrFormula(int n, int r) {
    return factorialRecursion(n) / (factorialRecursion(r) * factorialRecursion(n - r));
    // nCr = !n / (!r*!(n-r))
}

int nCrRecursion(int n, int r) {
    if (r == 0 || n == r) {
        return 1;
    }
    return nCrRecursion(n - 1, r - 1) + nCrRecursion(n - 1, r);
}


int main()
{
    cout << "nCr value for n = 5 and r = 1 using formula is " << nCrFormula(5, 3) << endl;
    cout << "nCr value for n = 5 and r = 1 using recursion is " << nCrRecursion(5, 3) << endl;
    return 0;
}