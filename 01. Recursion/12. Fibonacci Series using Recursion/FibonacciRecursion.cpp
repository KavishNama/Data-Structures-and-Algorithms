#include <iostream>
using namespace std;

int fibArray[25];

double FibonacciSeries(int n) {
    if (n <= 1) {
        return n;
    }
    return FibonacciSeries(n - 2) + FibonacciSeries(n - 1);
    // This function will take time O(2^n).
}

double FibonacciSeriesLooping(int n) {
    int term0 = 0, term1 = 1, sum;
    if (n <= 1) {
        return n;
    }
    for (int i = 2; i <= n; i++) {
        sum = term0 + term1;
        term0 = term1;
        term1 = sum;
    }
    return sum;
}

double FibonacciSeriesMemoization(int n) {
    if (n <= 1) {
        fibArray[n] = n;
        return n;
    }
    else {
        if (fibArray[n - 2] == -1) {
            fibArray[n - 2] = FibonacciSeriesMemoization(n - 2);
        }
        if (fibArray[n - 1] == -1) {
            fibArray[n - 1] = FibonacciSeriesMemoization(n - 1);
        }
        fibArray[n] = fibArray[n - 2] + fibArray[n - 1];
        return fibArray[n];
    }
    // This function will take time O(n).
}


int main()
{
    for (int i = 0; i < 25; i++) {
        fibArray[i] = -1;
    }
    cout << "Fibonacci series for n = 7 using recursion is " << FibonacciSeries(7) << endl;
    cout << "Fibonacci series for n = 7 using looping is " << FibonacciSeriesLooping(7) << endl;
    cout << "Fibonacci series for n = 7 using memoization recursion is " << FibonacciSeriesMemoization(7) << endl;
    return 0;
}