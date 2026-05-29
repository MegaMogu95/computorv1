#include <iostream>
#include <string>
#include <vector>

class Polynomial
{
    private:
        std::vector<double> _coeffs;
        void                parse_coeff(std::stringstream &ss_str, double sign);

    public:
        Polynomial();
        Polynomial(const std::string &str);
        ~Polynomial();
        Polynomial(const Polynomial &other);
        Polynomial& operator=(const Polynomial &other);

        const std::vector<double> &get_coeffs() const;
        int     degree() const;
        double  solve_quad(std::vector<double> &roots); //returns delta and changes roots.
};

std::ostream& operator<<(std::ostream &os, const Polynomial &pol);