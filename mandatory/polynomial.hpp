#include <iostream>
#include <string>
#include <vector>
#include "complex.hpp"

struct Polynomial
{
    std::vector<double> coeffs;

    Polynomial();
    Polynomial(const std::string &str);
    ~Polynomial();
    Polynomial(const Polynomial &other);
    Polynomial& operator=(const Polynomial &other);

    int     degree() const;
    double  solve_quad(std::vector<Complex> &roots);
    private:
        void                parse_coeff(std::stringstream &ss_str, double sign);
};

std::ostream& operator<<(std::ostream &os, const Polynomial &pol);