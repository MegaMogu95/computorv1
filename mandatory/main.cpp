#include <string>
#include <iostream>
#include "polynomial.hpp"

int main(int argc, char **argv)
{
    std::string  equation;

    if (argc > 2)
    {
        std::cerr << "Wrong number of arguments\n";
        return (1);
    }
    else if (argc == 2)
        equation = argv[1];
    else
        std::getline(std::cin, equation);
    Polynomial  pol(equation);
    std::cout << pol << " = 0\n";
}