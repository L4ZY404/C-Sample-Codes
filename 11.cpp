// GITHUB L4ZY404

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::to_string;

long GetPosNum() {
    long long num = 0;
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
    cout << "\033[36m ----------------------------\033[0m\n";
    cout << "\033[36m ---- Sum Expansion Tool ----\033[0m\n";
    cout << "\033[36m ----------------------------\033[0m\n";
    cout << "\033[36m -------- BY L4ZY404 --------\033[0m\n";
    cout << "\033[36m ----------------------------\033[0m\n";    

    cout << "Enter a number from 0 to 1,000,000: ";
    long n = GetPosNum();

    if (n > 1000000) {
        cout << "Error: Number must not be greater than 1,000,000." << endl;
        return 1;
    }

    if (n == 0) {
        cout << "0 = 0" << endl;
        return 0;
    }

    string text = to_string(n);
    int totalDigits = text.length();

    cout << n << " = ";
    bool first = true;

    for (int i = 0; i < totalDigits; i++) {
        if (text[i] != '0') {
            if (!first) cout << " + ";
            cout << text[i];
            for (int j = 0; j < totalDigits - i - 1; j++) {
                cout << "0";
            }
            first = false;
        }
    }
    cout << ";" << endl;
    return 0;
}