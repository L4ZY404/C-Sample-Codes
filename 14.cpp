// GITHUB L4ZY404

#include <iostream>
#include <vector>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::setw;

int GetPosNum() {
    int num = 0;
    char check;
    while (true) {
        if (cin >> num && num >= 1) {
            check = cin.peek(); 
            if (check == '\n') break; 
        }
        cout << "Error. Please enter an integer greater than 0: ";
        cin.clear(); 
        while (cin.get() != '\n') {} 
    }
    return num;
}

int main() {
    cout << "\033[36m ---------------------------\033[0m\n";
    cout << "\033[33m ---- PASCAL'S TRIANGLE ----\033[0m\n";
    cout << "\033[36m ---------------------------\033[0m\n";
    cout << "\033[36m -------- BY L4ZY404 -------\033[0m\n";
    cout << "\033[36m ---------------------------\033[0m\n";

    cout << "How many rows do you want? ";
    int rows = GetPosNum();

    vector<vector<long long>> m(rows);

    for (int i = 0; i < rows; i++) {
        m[i].resize(i + 1);
        m[i][0] = 1;
        m[i][i] = 1;
        for (int j = 1; j < i; j++) {
            m[i][j] = m[i - 1][j - 1] + m[i - 1][j];
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int s = 0; s < (rows - i); s++) cout << "   ";
        for (int j = 0; j <= i; j++) {
            cout << setw(6) << m[i][j];
        }
        cout << endl;
    }
    return 0;
}