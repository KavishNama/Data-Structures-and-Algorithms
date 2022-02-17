#include <iostream>
using namespace std;

double taylorSeries(double x, double n) {
    static double power = 1, denominatorFactorial = 1;
    double returningVariable;
    if (n == 0) {
        return 1;
    }
    else {
        returningVariable = taylorSeries(x, n - 1);
        power *= x;
        denominatorFactorial *= n;
        return returningVariable + (power / denominatorFactorial);
    }
}

double taylorSeriesOptimized(double x, double n) {
    static double returningVariable = 1;
    if (n == 0) {
        return returningVariable;
    }
    else {
        returningVariable = 1 + (x / n) * returningVariable;
        return taylorSeriesOptimized(x, n - 1);
    }
}

double taylorSeriesLooping(double x, double n) {
    double numerator = 1, denominator = 1;
    double result = 1;
    
    for (int i = 1; i <= n; i++) {
        numerator *= x;
        denominator *= i;
        result += (numerator / denominator);
    }
    return result;
}

int main()
{
    cout << "Taylor series for n = 5 using recursion is " << taylorSeries(1, 15) << endl;
    cout << "Taylor series for n = 5 using optimized recursion is " << taylorSeriesOptimized(1, 15) << endl;
    cout << "Taylor series for n = 5 using looping is " << taylorSeriesLooping(1, 15) << endl;
    return 0;
}