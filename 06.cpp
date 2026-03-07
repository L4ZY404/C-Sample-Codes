// GITHUB L4ZY404

#include <iostream>
#include <random>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> dis(0,10);

int random_num = dis(gen);
int user_num = 0;
int attempts = 5;

int main(){
    
    std::cout << "\033[36m ---------------------------\033[0m\n";
    std::cout << "\033[36m ----  Guess the number ----\033[0m\n";
    std::cout << "\033[36m ---------------------------\033[0m\n";
    std::cout << "\033[36m -------- BY L4ZY404 -------\033[0m\n";
    std::cout << "\033[36m ---------------------------\033[0m\n";

    std::cout << "The number i have in mind is between 0 y 10, you have 5 attempts to guess it...\n";

    do {
        std::cout << "\nEnter yout guess: ";
        std::cin >> user_num;

        if (user_num == random_num){
            std::cout << "\nIts correct, perfect!\n";
            return 0;
        }
        else if (user_num > random_num){
            std::cout << "Your guess is greater than my number. \n";
        }
        else if (user_num < random_num){
            std::cout << "Your guess is less than my number.\n";
        }

    attempts--;
    std::cout << "remaining attempts: " << attempts << std::endl;

    } while (attempts > 0);

    std::cout << "\n\nYou ran out of attempts! " << random_num << std::endl;
    std::cout << "Try again!\n";

    return 0;
}