#include <iostream>
using namespace std;


int exponentRecursion(int m, int n) {
    if (n >= 1) {
        return exponentRecursion(m,n-1) * m;
    }
    else {
        return 1;
    }
}

int exponentRecursionOptimized(int m, int n) {
    if (n >= 1) {
        if (n % 2 == 0) {
            return exponentRecursionOptimized(m * m, n / 2);
        }
        else {
            return exponentRecursionOptimized(m * m, (n-1) / 2) * m;
        }
    }
    else {
        return 1;
    }
}

//int exponentLoop(int m, int n) {
//    if (n >= 1) {
//        return exponentRecursion(m, n - 1) * m;
//    }
//    else {
//        return 1;
//    }
//}

int main()
{
    cout << "2 to the power of 5 using recursion is " << exponentRecursion(2,4) << endl;
    cout << "2 to the power of 5 using optimized recursion is " << exponentRecursionOptimized(2, 4) << endl;
    return 0;
}
