// GITHUB L4ZY404

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int GetPosNum() {
    int num = 0;
    char check;
    while (true) {
        if (cin >> num && num >= 0) {
            check = cin.peek(); 
            if (check == '\n') break; 
        }
        cout << "Error. Please enter a positive value or zero: ";
        cin.clear(); 
        while (cin.get() != '\n') {} 
    }
    return num;
}

int main(){
    cout << "\033[36m -----------------------------\033[0m\n";
    cout << "\033[36m ----  Double Factorial!!  ---\033[0m\n";
    cout << "\033[36m -----------------------------\033[0m\n";
    cout << "\033[36m -------- BY L4ZY404 ---------\033[0m\n";
    cout << "\033[36m -----------------------------\033[0m\n";    

    cout << "Enter the number to calculate the double factorial: ";
    int n = GetPosNum();
    double fact = 1;

    if (n > 1) {
        if (n % 2 == 0){
            for (int i = 2; i <= n; i += 2) fact *= i;
        } else {
            for (int i = 1; i <= n; i += 2) fact *= i;
        }
    }

    cout << "The double factorial of " << n << "!! is: " << fact << endl;
    return 0;
}