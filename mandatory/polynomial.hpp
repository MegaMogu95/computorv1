#include <iostream>
#include <string>
#include <vector>

class Polynomial
{
    private:
        std::vector<double> coeff;

    public:
        Polynomial();
        Polynomial(const std::string &str);
        ~Polynomial();
        Polynomial(const Polynomial &other);
        Polynomial& operator=(const Polynomial &other);

        int degree();
        double  solve_quad(std::vector<double> &roots); //returns delta and changes roots.
};