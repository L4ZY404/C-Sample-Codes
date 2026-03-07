// GITHUB L4ZY404

#include <iostream>

int main(){
    int n = 0, count = 0;
    long long current_num = 2;

    std::cout << "\033[36m --------------------------\033[0m\n";
    std::cout << "\033[36m ----   Prime Numbers  ----\033[0m\n";
    std::cout << "\033[36m --------------------------\033[0m\n";
    std::cout << "\033[36m -------- BY L4ZY404 ------\033[0m\n";
    std::cout << "\033[36m --------------------------\033[0m\n";
    
    std::cout << "How many prime numbers do you want to get? ";
    std::cin >> n;

    while (count < n) {
        bool is_prime = true;
        for (long long i = 2; i * i <= current_num; i++){
            if (current_num % i == 0){
                is_prime = false;
                break;
            }
        }
        if (is_prime){
            std::cout << current_num << " ";
            count++;
        }
        current_num++;
    }
    std::cout << "\n";
    return 0;
}