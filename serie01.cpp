// GITHUB L4ZY404
// Euler's Number

#include <iostream>
#include <cmath>

using namespace std;

double factorial(int n) {
    if (n <= 1) return 1.0;
    double fact = 1.0;
    for (int i = 2; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

int main() {
    int N;
    cout << "Enter the number of terms (N) to calculate: ";
    cin >> N;

    if (N < 0) {
        cout << "N must be a positive integer or zero." << endl;
        return 1;
    }

    double sum = 0.0;
    for (int n = 0; n <= N; ++n) {
        sum += 1.0 / factorial(n);
    }

    cout << "The result of series S1 is: " << sum << endl;
    return 0;
}