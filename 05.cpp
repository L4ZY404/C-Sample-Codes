// GITHUB L4ZY404

#include <iostream>
#include <cmath> // Necesary for sen and cos

int main(){

    double real = 0;
    double img = 0;
    double arg = 0;
    double mag = 0;
    
    std::cout << "\033[36m ---------------------------------------------\033[0m\n";
    std::cout << "\033[36m ----  Complex number to binomial & polar ----\033[0m\n";
    std::cout << "\033[36m ---------------------------------------------\033[0m\n";
    std::cout << "\033[36m ------------------ BY L4ZY404 ---------------\033[0m\n";
    std::cout << "\033[36m ---------------------------------------------\033[0m\n";

    std::cout << "Enter the real part of the complex number: ";
    std::cin >> real;
    std::cout << "Enter the imaginary part of the complex number: ";
    std::cin >> img;

    arg = atan(img/real);
    
    double real_pow = pow(real,2);
    double img_pow = pow(img, 2);
    double sum_pow = real_pow + img_pow;
    mag = sqrt(sum_pow);
    
    std::cout << "Binomial form: \n";
    std::cout << real << " + " << img <<"i" << std::endl;

    std::cout << "Polar form (take into account that the angle is in radians): \n";
    std::cout << mag << "(cos(" << arg <<") + i sin(" << arg << "))" << std::endl;
}