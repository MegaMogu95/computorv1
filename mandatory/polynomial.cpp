#include <polynomial.hpp>
#include <sstream>

Polynomial::Polynomial()
{
}

int Polynomial::degree() const
{
    bool    non_zero = false;
    int     degree;

    for (std::vector<double>::size_type i = 0; i < coeffs.size(); i++)
    {
        if (coeffs[i] != 0)
        {
            non_zero = true;
            degree = i;
        }
    }
    if (non_zero)
        return (degree);
    return (-1);
}

void    Polynomial::parse_coeff(std::stringstream &ss_str, double sign)
{
    double          coeff;
    std::string     monomial;
    int             power;

    ss_str >> coeff;
    ss_str >> std::ws;
    if (ss_str.peek() == '*')
    {
        ss_str.ignore(1);
        ss_str >> std::ws;
        ss_str.ignore(2);
        ss_str >> power;
        if (power > degree())
            coeffs.resize(power + 1);
        coeffs[power] += sign * coeff;
    }
}

Polynomial::Polynomial(const std::string &str)
{
    std::stringstream   ss_str(str);
    std::string         op;
    bool                lhs = true;
    double              sign;

    parse_coeff(ss_str, 1);
    while (ss_str >> op)
    {
        sign = 1;
        if (op == "=")
            lhs = false;
        if (op == "-")
            sign *= -1;
        if (!lhs)
            sign *= -1;
        parse_coeff(ss_str, sign);
    }
}

Polynomial::~Polynomial()
{
}

Polynomial::Polynomial(const Polynomial &other):
    coeffs(other.coeffs)
{
}

Polynomial& Polynomial::operator=(const Polynomial &other)
{
    coeffs = other.coeffs;
    return (*this);
}

std::ostream& operator<<(std::ostream &os, const Polynomial &pol)
{
    int deg = pol.degree();
    if (deg == -1)
    {
        os << "0 * X^0";
        return (os);
    }
    for (int i = 0; i <= deg; i++)
    {
        if (i == 0)
            os << pol.coeffs[i] << " * X^" << i;
        else if (pol.coeffs[i] >= 0)
            os << "+ " << pol.coeffs[i] << " * X^" << i;
        else if (pol.coeffs[i] < 0)
            os << "- " << -pol.coeffs[i] << " * X^" << i;
        if (i != deg)
            os << " ";
    }
    return (os);
}

double  Polynomial::solve_quad(std::pair<Complex, Complex> &roots)
{
    double  delta;
    double  a = coeffs[2];
    double  b = coeffs[1];
    double  c = coeffs[0];

    delta = b * b - 4 * a * c;
    roots.first.re = -b / (2 * a);
    roots.second.re = -b / (2 * a);
    if (delta >= 0)
    {
        roots.first.re += std::sqrt(delta) / (2 * a);
        roots.second.re -= std::sqrt(delta) / (2 * a);
    }
    else
    {
        roots.first.im += std::sqrt(-delta) / (2 * a);
        roots.second.im -= std::sqrt(-delta) / (2 * a);
    }
    return (delta);
}