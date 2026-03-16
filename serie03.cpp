// GITHUB L4ZY404
// Convergent Test Series

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

    if (N < 1) {
        cout << "For this series, N must be a positive integer greater than or equal to 1." << endl;
        return 1;
    }

    double sum = 0.0;
    for (int n = 1; n <= N; ++n) {
        sum += 8.0 / (n * factorial(n + 2));
    }

    cout << "The result of series S3 is: " << sum << endl;
    return 0;
}