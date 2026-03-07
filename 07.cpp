// GITHUB L4ZY404

#include <iostream>

long long n1 = 0;
long long n2 = 0;
long long a = 0;
long long b = 0;
long long q = 0;
long long r = 0;
long long gcd = 0;

unsigned long long ab = 0;
long long lcm = 0;

long long dummy = 0;


int GetPosNum() {
    long long num = 0;
    char check;

    while (true) {
        if (std::cin >> num && num > 0) {
            check = std::cin.peek(); 
            if (check == '\n') {
                break; 
            }
        }
    
        std::cout << "Error. Enter a natural number: ";
        std::cin.clear(); 
        
        while (std::cin.get() != '\n') {}
    }
    return num;
}

int main(){
    std::cout << "\033[36m ---------------------\033[0m\n";
    std::cout << "\033[36m ----  lcm & gcd  ----\033[0m\n";
    std::cout << "\033[36m ---------------------\033[0m\n";
    std::cout << "\033[36m ----- BY L4ZY404 ----\033[0m\n";
    std::cout << "\033[36m ---------------------\033[0m\n";

    std::cout << "Enter the first number: ";
    n1 = GetPosNum();
    std::cout << "Enter the second number: ";
    n2 = GetPosNum();

    if (n1<n2){
        dummy=n1;
        n1=n2;
        n2=dummy;
    }

    a = n1;
    b = n2;

    while (b != 0) { // Euclid's algorithm
        r = a%b;
        a = b;
        b = r;
    }
    gcd = a;

    ab = n1*n2;

    lcm = ab/gcd;

    std::cout << "The gcd of " << n1 << " y " << n2 << " is: " << gcd << std::endl;
    std::cout << "The lcm of " << n1 << " y " << n2 << " is: " << lcm << std::endl;
}