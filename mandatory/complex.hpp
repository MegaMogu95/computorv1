#include <cmath>
#include <utility>
#include <iostream>

struct Complex
{
    double  re;
    double  im;

    Complex(double _re, double _im);
    double      modulus();
    Complex     sqrt();
};

std::ostream& operator<<(std::ostream &os, const Complex &z);