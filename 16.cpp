// GITHUB L4ZY404

#include <iostream>
#include <cmath>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::fixed;
using std::setprecision;

double GetRealNum(std::string coefName) {
    double num = 0;
    char check;
    while (true) {
        cout << "Enter coefficient " << coefName << ": ";
        if (cin >> num) {
            check = cin.peek(); 
            if (check == '\n') break; 
        }
        cout << "\033[31mError. Please enter a valid real number.\033[0m" << endl;
        cin.clear(); 
        while (cin.get() != '\n') {} 
    }
    return num;
}

int main() {
    cout << "\033[35m -------------------------------------------\033[0m\n";
    cout << "\033[35m ----     Quadratic Equation Solver     ----\033[0m\n";
    cout << "\033[35m -------------------------------------------\033[0m\n";
    cout << "\033[35m ---------------- BY L4ZY404 ---------------\033[0m\n";
    cout << "\033[35m -------------------------------------------\033[0m\n\n";

    double a = GetRealNum("a");
    while (a == 0) {
        cout << "Coefficient 'a' cannot be 0. ";
        a = GetRealNum("a");
    }
    double b = GetRealNum("b");
    double c = GetRealNum("c");

    cout << "\nEquation: (" << a << ")x^2 + (" << b << ")x + (" << c << ") = 0" << endl;

    double discriminant = pow(b, 2) - (4 * a * c);
    cout << fixed << setprecision(4);

    if (discriminant > 0) {
        double x1 = (-b + sqrt(discriminant)) / (2 * a);
        double x2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Solution Type: Distinct Real Roots" << endl;
        cout << "x1 = " << x1 << "\nx2 = " << x2 << endl;
    } else if (discriminant == 0) {
        double x = -b / (2 * a);
        cout << "Solution Type: Repeated Real Roots" << endl;
        cout << "x1 = x2 = " << x << endl;
    } else {
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        cout << "Solution Type: Complex Roots" << endl;
        cout << "x1 = " << realPart << " + " << imaginaryPart << "i" << endl;
        cout << "x2 = " << realPart << " - " << imaginaryPart << "i" << endl;
    }
    return 0;
}