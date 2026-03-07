// GITHUB L4ZY404

#include <iostream>

int GetPosNum() {
    int num = 0;
    char check;

    while (true) {
        if (std::cin >> num && num > 0) {
            check = std::cin.peek(); 
            if (check == '\n') {
                break; 
            }
        }
    
        std::cout << "Error. Ingrese un valor positivo: ";
        std::cin.clear(); 
        
        while (std::cin.get() != '\n') {}
    }
    return num;
}

int main() {
    int a = 0;
    int b = 0;
    int c = 0;

    std::cout << "\033[36m ---------------------------\033[0m\n";
    std::cout << "\033[36m ---  Triangle verifier  ---\033[0m\n";
    std::cout << "\033[36m ---------------------------\033[0m\n";
    std::cout << "\033[36m -------- BY L4ZY404 -------\033[0m\n";
    std::cout << "\033[36m ---------------------------\033[0m\n";
    
    std::cout << "Length of A \n";
    a = GetPosNum();
    
    std::cout << "Length of B \n";
    b = GetPosNum();
    
    std::cout << "Length of C \n";
    c = GetPosNum();

    std::cout << "\nPerfect! your lengths are: \n";
    std::cout << "A: " << a << std::endl;
    std::cout << "B: " << b << std::endl;
    std::cout << "C: " << c << std::endl;

    if (a+b>c && a+c>b && b+c>a){
        std::cout << "\nIts a triangle! \n";
    }
    else {
        std::cout << "\nIts not a triangle! \n";
    }

    return 0;
}