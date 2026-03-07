// GITHUB L4ZY404

#include <iostream>

int main() {
    int number;
    char next;
    
    std::cout << "\033[36m ------------------------------------\033[0m\n";
    std::cout << "\033[36m --- NATURAL FACTORIAL CALCULATOR ---\033[0m\n";
    std::cout << "\033[36m ------------------------------------\033[0m\n";
    std::cout << "\033[36m ------------- BY L4ZY404 -----------\033[0m\n";
    std::cout << "\033[36m ------------------------------------\033[0m\n";
    
    std::cout << "Please enter natural number: ";

    while (true) {
        if (std::cin >> number && number > 0) {
            next = std::cin.peek(); 
            if (next == '\n') {
                break; 
            }
        }
        
        std::cout << "Error. Please enter a natural number ";
        std::cin.clear(); 
        
        while (std::cin.get() != '\n') {}
    }

    if (number == 0){
        std::cout << "The factorial of 0 is 1" << std::endl;
        return 0;

    }
    
    unsigned long long factorial = 1;     
    for (int i = 1; i <= number; ++i) {
        factorial *= i; 
    }

    std::cout << "The factorial of " << number << "! is: " << factorial << std::endl;
    return 0;
}