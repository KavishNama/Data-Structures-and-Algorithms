#include <iostream>
using namespace std;


int sumRecursion(int n) {
    if (n >= 1) {
        return sumRecursion(n - 1) + n;
    }
    else {
        return 0;
    }
}

int sumDirect(int n) {
    return n * (n + 1) / 2;
}

int sumLoop(int n) {
    int sum = 0;
    for (int i = n; i > 0; i--) {
        sum += i;
    }
    return sum;
}

int main()
{
    cout << "Sum of first 15 natural numbers using recursion is " << sumRecursion(15) << endl;
    cout << "Sum of first 15 natural numbers using direct formula is " << sumDirect(15) << endl;
    cout << "Sum of first 15 natural numbers using looping is " << sumLoop(15) << endl;
    return 0;
}
