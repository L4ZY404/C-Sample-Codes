// GITHUB L4ZY404

#include <iostream>

int main (){
    int year; 
    char next;
    std::cout << "\033[36m --------------------------\033[0m\n";
    std::cout << "\033[36m ---  Is it leap year?  ---\033[0m\n";
    std::cout << "\033[36m --------------------------\033[0m\n";
    std::cout << "\033[36m ------- BY L4ZY404 -------\033[0m\n";
    std::cout << "\033[36m --------------------------\033[0m\n";
    
    std::cout << "Please enter a integer positive year: ";
    while (true) {
        if (std::cin >> year && year > 0) {
            next = std::cin.peek(); 
            if (next == '\n') {
                break;
            }
        }
    
        std::cout << "Error. Please enter a integer positive number: ";
        std::cin.clear(); 
        
        while (std::cin.get() != '\n') {}
    }
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
        std::cout << "Its a leap year!" << std::endl;
    }
    else{
        std::cout << "It isnt a leap year!" << std::endl;
    }
    return 0;
}