// GITHUB L4ZY404

#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;

int GetPosNum() {
    int num = 0;
    char check;
    while (true) {
        if (cin >> num && num >= 1) {
            check = cin.peek(); 
            if (check == '\n') break; 
        }
        cout << "Error. Enter number of fractions (positive integer): ";
        cin.clear(); 
        while (cin.get() != '\n') {} 
    }
    return num;
}

int main() {
    cout << "\033[32m --------------------------------------\033[0m\n";
    cout << "\033[32m ----  PI Calculation (Brouncker)  ----\033[0m\n";
    cout << "\033[32m --------------------------------------\033[0m\n";
    cout << "\033[32m ------------- BY L4ZY404 -------------\033[0m\n";
    cout << "\033[32m --------------------------------------\033[0m\n\n";

    cout << "Enter the number of fractions to calculate: ";
    int n = GetPosNum();

    long double fraction = 0.0;
    for (int i = n; i >= 1; i--) {
        long double numerator = (2.0 * i - 1.0) * (2.0 * i - 1.0);
        if (i == n) fraction = numerator / 2.0;
        else fraction = numerator / (2.0 + fraction);
    }

    long double pi_quarters = 1.0 / (1.0 + fraction);
    long double pi_calculated = pi_quarters * 4.0;

    cout << std::fixed << std::setprecision(15);
    cout << "\nResults with " << n << " fractions:" << endl;
    cout << "Calculated PI/4: " << pi_quarters << endl;
    cout << "Calculated PI:   " << pi_calculated << endl;
    cout << "Real PI (ref):   3.141592653589793" << endl;

    return 0;
}