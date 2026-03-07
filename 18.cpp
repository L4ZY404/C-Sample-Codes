// GITHUB L4ZY404

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::fixed;
using std::setprecision;

int GetIntGreater(int limit, string message) {
    int num = 0;
    while (true) {
        cout << message;
        if (cin >> num && num > limit) {
            if (cin.peek() == '\n') break; 
        }
        cout << "\033[31mError. Please enter an integer greater than " << limit << ".\033[0m\n";
        cin.clear(); 
        while (cin.get() != '\n') {} 
    }
    return num;
}

double GetRealNum(string message) {
    double num = 0;
    while (true) {
        cout << message;
        if (cin >> num) {
            if (cin.peek() == '\n') break; 
        }
        cout << "\033[31mError. Please enter a valid number.\033[0m\n";
        cin.clear(); 
        while (cin.get() != '\n') {} 
    }
    return num;
}

double GetRealNumInRange(string message, double min, double max) {
    double num = 0;
    while (true) {
        cout << message;
        if (cin >> num && num >= min && num <= max) {
            if (cin.peek() == '\n') break; 
        }
        cout << "\033[31mError. Value must be in range [" << min << ", " << max << "].\033[0m\n";
        cin.clear(); 
        while (cin.get() != '\n') {} 
    }
    return num;
}

int main() {
    cout << "\033[34m -------------------------------------------\033[0m\n";
    cout << "\033[34m ----   Least Squares Regression Line   ----\033[0m\n";
    cout << "\033[34m -------------------------------------------\033[0m\n";
    cout << "\033[34m --------------   BY L4ZY404   -------------\033[0m\n";
    cout << "\033[34m -------------------------------------------\033[0m\n\n";

    double x_min = GetRealNum("Lower limit for X (x_min): ");
    double x_max = GetRealNum("Upper limit for X (x_max): ");
    if (x_min > x_max) std::swap(x_min, x_max);

    int n = GetIntGreater(1, "How many points (x,y) do you want to enter? (Min 2): ");
    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;

    for (int i = 0; i < n; i++) {
        cout << "\nPoint " << i + 1 << ":\n";
        double x = GetRealNumInRange("X value: ", x_min, x_max);
        double y = GetRealNum("Y value: ");
        sum_x += x; sum_y += y; sum_xy += (x * y); sum_x2 += (x * x);
    }

    double denominator = (n * sum_x2) - (sum_x * sum_x);
    if (denominator == 0) return 1;

    double m = ((n * sum_xy) - (sum_x * sum_y)) / denominator;
    double b = (sum_y - (m * sum_x)) / n;

    cout << fixed << setprecision(4) << "\n\033[32m================ RESULTS =================\033[0m\n";
    cout << "Slope (m) = " << m << "\nY-Intercept (b) = " << b << "\n";
    cout << "\033[33mBest fit equation:\033[0m\n";
    if (b >= 0) cout << "y = " << m << "x + " << b << "\n";
    else cout << "y = " << m << "x - " << std::abs(b) << "\n";
    return 0;
}