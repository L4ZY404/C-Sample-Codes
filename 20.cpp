// GITHUB L4ZY404

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

long long Combinations(int n, int r) {
    if (r == 0 || r == n) return 1;
    long long res = 1;
    for (int i = 1; i <= r; i++) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

int GetPower() {
    int num = 0;
    while (true) {
        cout << "Enter the power n (positive integer less than 15): ";
        if (cin >> num && num > 0 && num < 15) {
            if (cin.peek() == '\n') break; 
        }
        cout << "\033[31mError. Value must be an integer between 1 and 14.\033[0m\n";
        cin.clear(); 
        while (cin.get() != '\n') {} 
    }
    return num;
}

int main() {
    cout << "\033[33m -------------------------------\033[0m\n";
    cout << "\033[33m ----    Binomial Theorem   ----\033[0m\n";
    cout << "\033[33m -------------------------------\033[0m\n";
    cout << "\033[33m ---------- BY L4ZY404 ---------\033[0m\n";
    cout << "\033[33m -------------------------------\033[0m\n\n";

    int n = GetPower();

    cout << "\n\033[36mExpansion of (a+b)^" << n << ":\033[0m\n";
    cout << "(a+b)^" << n << " = ";

    for (int r = 0; r <= n; r++) {
        long long coefficient = Combinations(n, r);
        int power_a = n - r;
        int power_b = r;

        cout << coefficient;

        if (power_a > 0) {
            cout << "*a";
            if (power_a > 1) cout << "^" << power_a;
        }

        if (power_b > 0) {
            cout << "*b";
            if (power_b > 1) cout << "^" << power_b;
        }

        if (r < n) cout << " + ";
    }

    cout << "\n\n";
    return 0;
}