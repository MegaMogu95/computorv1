#include <polynomial.hpp>
#include <sstream>

class Polynomial
{
    private:
        std::vector<double> coeffs;

    public:
        Polynomial();
        Polynomial(const std::string &str);
        ~Polynomial();
        Polynomial(const Polynomial &other);
        Polynomial& operator=(const Polynomial &other);

        int degree();
        double  solve_quad(std::vector<double> &roots); //returns delta and changes roots.
};

Polynomial::Polynomial()
{
}

int Polynomial::degree()
{
    bool    non_zero = false;
    int     degree;

    for (int i = 0; i <= coeffs)
}

Polynomial::Polynomial(const std::string &str)
{
    std::stringstream   ss_str(str);
    double              coeff;
    char                operator;
    std::string         monomial;
    int                 power;

    while (ss_str >> coeff)
    {
        ss_str >> operator;
        ss_str >> monomial;
        std::stringstream   ss_power(monomial);
        ss_power.ignore(2);
        ss_power >> power;

    }
}