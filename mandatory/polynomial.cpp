#include <polynomial.hpp>
#include <sstream>

Polynomial::Polynomial()
{
}

int Polynomial::degree() const
{
    bool    non_zero = false;
    int     degree;

    for (std::vector<double>::size_type i = 0; i < _coeffs.size(); i++)
    {
        if (_coeffs[i] != 0)
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
            _coeffs.resize(power + 1);
        _coeffs[power] += sign * coeff;
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
    _coeffs(other._coeffs)
{
}

Polynomial& Polynomial::operator=(const Polynomial &other)
{
    _coeffs = other._coeffs;
    return (*this);
}

const std::vector<double> &Polynomial::get_coeffs() const
{
    return (_coeffs);
}

std::ostream& operator<<(std::ostream &os, const Polynomial &pol)
{
    std::vector<double> coeffs = pol.get_coeffs();
    int deg = pol.degree();
    if (deg == -1)
    {
        os << "0 * X^0";
        return (os);
    }
    for (int i = 0; i <= deg; i++)
    {
        if (i == 0)
            os << coeffs[i] << " * X^" << i;
        else if (coeffs[i] >= 0)
            os << "+ " << coeffs[i] << " * X^" << i;
        else if (coeffs[i] < 0)
            os << "- " << -coeffs[i] << " * X^" << i;
        if (i != deg)
            os << " ";
    }
    return (os);
}