#include <stdexcept>

double  dist(double x, double target)
{
    double  absolute_dist = target > x ? target - x : x - target;

    if (target < 1)
        return (absolute_dist);
    return (absolute_dist / target);
}

double  newton_raphson_sqrt(double xn, double y)
{
    if (y == 0)
        return (0);
    return (xn - 0.5 * (xn - y / xn));
}

//2xn(x - xn) + xn * xn - y = 0
//x = (y - xn * xn)/2xn + xn

double  sqrt_err(double y, double err)
{
    double  xn = y;
    int     max_iter = 8;

    if (y < 0)
        throw   std::domain_error("sqrt of a negative number");

    while (dist(xn * xn, y) > err && --max_iter >= 0)
        xn = newton_raphson_sqrt(xn, y);
    return (xn);
}

#include <cmath>
#include <iostream>
int main()
{
    double  x;
    double  err = 1e-15;

    while (true)
    {
        std::cin >> x;
        std::cout << "sqrt_err(x, err) = " << sqrt_err(x, err) << '\n';
        std::cout << "sqrt(x) = " << sqrt(x) << '\n';
        std::cout << sqrt_err(x, err) - sqrt(x) << '\n';
    }
}