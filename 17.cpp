// GITHUB L4ZY404

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

string GetEAN7() {
    string input;
    bool valid = false;
    while (!valid) {
        cout << "Enter the first 7 digits of the EAN-8 code: ";
        cin >> input;
        valid = true;
        if (input.length() != 7) valid = false;
        else {
            for (char c : input) {
                if (!isdigit(c)) { valid = false; break; }
            }
        }
        if (!valid) {
            cout << "\033[31mError. You must enter exactly 7 integers.\033[0m\n";
            cin.clear();
            while (cin.peek() != '\n' && cin.peek() != EOF) cin.get();
        } else {
             while (cin.peek() != '\n' && cin.peek() != EOF) cin.get();
        }
    }
    return input;
}

int main() {
    cout << "\033[36m -----------------------------------\033[0m\n";
    cout << "\033[36m ---- EAN-8 Checksum Calculator ----\033[0m\n";
    cout << "\033[36m -----------------------------------\033[0m\n";
    cout << "\033[36m ------------ BY L4ZY404 -----------\033[0m\n";
    cout << "\033[36m -----------------------------------\033[0m\n\n";

    string ean7 = GetEAN7();
    int sum = 0;
    cout << "\nWeighting Breakdown:\n";
    
    for (int i = 0; i < 7; i++) {
        int digit = ean7[i] - '0';
        int weight = (i % 2 == 0) ? 3 : 1;
        int value = digit * weight;
        sum += value;
        cout << "Digit " << digit << " x " << weight << " = " << value << "\n";
    }

    int remainder = sum % 10;
    int controlDigit = (remainder == 0) ? 0 : 10 - remainder;

    cout << "\nControl Digit is: [" << controlDigit << "]\n";
    cout << "\033[32mFull EAN-8 code: " << ean7 << controlDigit << "\033[0m\n";
    return 0;
}