#include <iostream>
#include "funcs.h"

int main() {
    int a; int b; int c;
    std::cout << "Give first number: ", std::cin >> a;
    std::cout << "Give second number: ", std::cin >> b;
    std::cout << "Give third number: ", std::cin >> c;
    std::cout << add2(a,b) << std::endl;
    std::cout << add3(a,b,c) << std::endl;
}