// GITHUB L4ZY404
#include <iostream>

int GetPosNum() {
    int num = 0;
    char check;
    while (true) {
        if (std::cin >> num && num > 0) {
            check = std::cin.peek(); 
            if (check == '\n') break; 
        }
        std::cout << "Error. Please enter a positive value: ";
        std::cin.clear(); 
        while (std::cin.get() != '\n') {}
    }
    return num;
}

int main(){
    unsigned long long a = 0, b = 1, next_term = 0;
    int n = 0;

    std::cout << "\033[36m ------------------------------\033[0m\n";
    std::cout << "\033[36m ----   Fibonacci Series   ----\033[0m\n";
    std::cout << "\033[36m ------------------------------\033[0m\n";
    std::cout << "\033[36m --------- BY L4ZY404 ---------\033[0m\n";
    std::cout << "\033[36m ------------------------------\033[0m\n";

    std::cout << "Enter the number of terms: ";
    n = GetPosNum();

    std::cout << a << " " << b << " ";

    for (int i = 0; i < n; i++){
        next_term = a + b;
        a = b;
        b = next_term;
        std::cout << next_term << " ";
    }
    std::cout << "\n";
    return 0;
}