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

int Padovan(int n) {
    if (n == 0 || n == 1 || n == 2) return 1;
    return Padovan(n - 2) + Padovan(n - 3);
}

int main() {
    int n = 0;
    std::cout << "\033[36m ----------------------------\033[0m\n";
    std::cout << "\033[36m ----   Padovan Series   ----\033[0m\n";
    std::cout << "\033[36m ----------------------------\033[0m\n";
    std::cout << "\033[36m -------- BY L4ZY404 --------\033[0m\n";
    std::cout << "\033[36m ----------------------------\033[0m\n";
    
    std::cout << "Enter how many numbers you want to see: ";
    n = GetPosNum(); 

    for (int i = 0; i < n; i++) {
        std::cout << Padovan(i) << " "; 
    }
    std::cout << "\n";
    return 0;
}