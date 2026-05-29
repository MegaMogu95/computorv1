#include "complex.hpp"

Complex::Complex():
    re(0),
    im(0)
{
}

Complex::Complex(double _re, double _im):
    re(_re),
    im(_im)
{
}

double  Complex::modulus()
{
    return (std::sqrt(re * re + im * im));
}

Complex     Complex::sqrt()
{
    double  sign = 1;
    if (im < 0)
        sign = -1;

    if (im == 0)
        return (Complex(std::sqrt(re), 0));
    return (Complex(std::sqrt((modulus() + re) / 2), sign * std::sqrt((modulus() - re) / 2)));
}

std::ostream& operator<<(std::ostream &os, const Complex &z)
{
    if (z.re != 0)
    {
        os << z.re;
        if (z.im > 0)
            os << " + " << z.im << "i";
        else if (z.im < 0)
            os << " - " << -z.im << "i";
    }
    else
    {
        os << z.im;
        if (z.im != 0)
            os << "i";
    }
    return (os);
}