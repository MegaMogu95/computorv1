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

    std::cout << "Reduced form: " << pol << " = 0\n";

    int deg = pol.degree();

    if (deg == -1)
        std::cout << "Any real number is a solution.\n";
    else if (deg == 0)
        std::cout << "No solution.\n";
    else
    {
        std::cout << "Polynomial degree: " << deg << '\n';
        if (deg == 1)
        {
            std::cout << "The solution is:\n";
            std::cout << -pol.coeffs[0] / pol.coeffs[1] << '\n';
        }
        else if (deg == 2)
        {
            std::pair<Complex, Complex> roots;
            double  delta = pol.solve_quad(roots);
            if (delta > 0)
            {
                std::cout << "Discriminant is strictly positive, the two solutions are:\n";
                std::cout << roots.first << '\n';
                std::cout << roots.second << '\n';
            }
            else if (delta == 0)
            {
                std::cout << "Discriminant is null, the solution is:\n";
                std::cout << roots.first << '\n';
            }
            else
            {
                std::cout << "Discriminant is strictly negative, the two complex solutions are:\n";
                std::cout << roots.first << '\n';
                std::cout << roots.second << '\n';
            }
        }
        else
            std::cout << "The polynomial degree is strictly greater than 2, I can't solve.\n";
    }
}