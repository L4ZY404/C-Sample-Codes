// GITHUB L4ZY404

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int GetPosNum(int limit = 1) {
    int num = 0;
    char check;
    while (true) {
        if (cin >> num && num >= 1 && num <= limit){
            check = cin.peek(); 
            if (check == '\n') break; 
        }
        cout << "Error. Please enter a number between 1 and " << limit << ": ";
        cin.clear(); 
        while (cin.get() != '\n') {} 
    }
    return num;
}

void FullDiamond(int num_row){
    int spaces = num_row;
    int stars = 1;
    for (int i = 0; i < num_row; i++){
        for (int j = 0; j < spaces; j++) cout << " ";
        for (int k = 0; k < stars; k++) cout << "*";
        cout << endl;
        --spaces; stars += 2;
    }
    for (int i = num_row; i >= 0; i--){
        for (int j = 0; j < spaces; j++) cout << " ";
        for (int k = 0; k < stars; k++) cout << "*";
        cout << endl;
        ++spaces; stars -= 2;
    }
}

void HalfDiamond(int num_row){
    for (int i = 0; i < num_row; i++){
        for (int j = 0; j <= i; j++) cout << "*";
        cout << endl;
    }
    for (int i = num_row; i >= 0; i--){
        for (int j = i; j >= 0; j--) cout << "*";
        cout << endl;
    }
}

void Staircase(int num_row){
    for (int i = 0; i < num_row; i++){
        for (int j = 0; j <= i; j++) cout << "*";
        cout << endl;
    }
}

int main(){
    cout << "\033[36m -----------------------\033[0m\n";
    cout << "\033[36m --- Shape Generator ---\033[0m\n";
    cout << "\033[36m -----------------------\033[0m\n";
    cout << "\033[36m ----- BY L4ZY404 ------\033[0m\n";
    cout << "\033[36m -----------------------\033[0m\n\n";

    cout << "Choose a shape (1 - 3):" << endl;
    cout << "1) Staircase\n2) Half Diamond\n3) Full Diamond\nOption: ";
    int choice = GetPosNum(3);

    cout << "Enter number of rows (1 - 20): ";
    int rows = GetPosNum(20);

    cout << endl;
    switch (choice) {
        case 1: Staircase(rows); break;
        case 2: HalfDiamond(rows); break;
        case 3: FullDiamond(rows); break;
    }
    return 0;
}