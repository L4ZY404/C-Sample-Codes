// GITHUB L4ZY404
// Wallis Product

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N;
    cout << "Enter the number of terms (N) to calculate: ";
    cin >> N;

    if (N < 1) {
        cout << "For this series, N must be a positive integer greater than or equal to 1." << endl;
        return 1;
    }

    double product = 1.0; 
    
    for (int n = 1; n <= N; ++n) {
        double term1 = (2.0 * n) / (2.0 * n - 1.0);
        double term2 = (2.0 * n) / (2.0 * n + 1.0);
        product *= (term1 * term2);
    }

    double final_result = 2.0 * product;

    cout << "The result of series S5 is: " << final_result << endl;
    return 0;
}