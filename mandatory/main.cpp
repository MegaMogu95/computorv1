#include <string>
#include <iostream>

int 

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
    std::cout << "L'equation c'est " << equation << std::endl;
}