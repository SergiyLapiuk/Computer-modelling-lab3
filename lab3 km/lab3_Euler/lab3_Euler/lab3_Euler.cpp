#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    double y[1000] = { 0 }; // starting y0
    double z[1000] = { 1.07 }; // starting z0
    int i = 0;
    double x[9] = { 0 }; // starting x0
    double h = 0.1; // step
    while (i <= 10)
    {
        std::cout << "Iteration:" << i << std::endl;
        std::cout << "x[" << i << "] = " << x[i] << std::endl;
        y[i + 1] += y[i] + h * z[i];
        std::cout << "y[" << i << "] = " << y[i] << std::endl;
        z[i + 1] = z[i] + h * (z[i]  + 2*y[i]-3*exp(-1*x[i]));
        std::cout << "z[" << i << "] = " << z[i] << std::endl;
        x[i + 1] = x[i] + h;
        i++;
    }
    return 0;
}