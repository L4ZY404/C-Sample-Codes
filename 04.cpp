// GITHUB L4ZY404

#include <iostream>

int main(){
    int num = 1;

    std::cout << "\033[36m ---------------------------\033[0m\n";
    std::cout << "\033[36m ----  Stair generator  ----\033[0m\n";
    std::cout << "\033[36m ---------------------------\033[0m\n";
    std::cout << "\033[36m -------- BY L4ZY404 -------\033[0m\n";
    std::cout << "\033[36m ---------------------------\033[0m\n";

    std::cout << "Enter a number between 1 y 20: ";

    do {
        std::cin >> num;
        if (num < 1 || num > 20){
            std::cout << "Enter a number between 1 y 20: ";
        }
    } while (num < 1 || num > 20);

    for (int i = 0; i < num; i++){
        for (int j = 0; j <= i; j++){
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    return 0;
}