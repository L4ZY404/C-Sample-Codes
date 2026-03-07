// GITHUB L4ZY404

#include <iostream>
#include <random>

using std::cout;
using std::cin;
using std::endl;

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<double> dis(0.0, 1000000.0);

int GetPosNum() {
    int num = 0;
    char check;
    while (true) {
        if (cin >> num && num > 0) {
            check = cin.peek(); 
            if (check == '\n') break; 
        }
        cout << "Error. Please enter a positive non-zero value: ";
        cin.clear(); 
        while (cin.get() != '\n') {} 
    }
    return num;
}

int main(){
    cout << "\033[36m -------------------------------------------------\033[0m\n";
    cout << "\033[36m ----   Pseudorandom Number Generator (PRNG)  ----\033[0m\n";
    cout << "\033[36m -------------------------------------------------\033[0m\n";
    cout << "\033[36m -------------------- BY L4ZY404 -----------------\033[0m\n";
    cout << "\033[36m -------------------------------------------------\033[0m\n";
    
    cout << "Enter the quantity of pseudorandom numbers: ";
    int n = GetPosNum();

    for (int i = 0; i < n; i++){
        int random_num = dis(gen);
        cout << random_num << " ";
    }
    cout << "\n";
    return 0;
}