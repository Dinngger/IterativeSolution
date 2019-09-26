/*
 * IterativeSolutionTest.cpp
 * 
 * Created Date: Friday, September 20th 2019, 7:30:29 pm
 * by Dinger
 */
#include "IterativeSolution.hpp"

double func(double x)
{
    return x * x * x + 2 * x * x + 10 * x - 20;
}

double dFunc(double x)
{
    return 3 * x * x + 4 * x + 10;
}

int main()
{
    std::cout << "Newton Method:\n";
    NewtonMethod<double> newtonMethod(0, 1e-6, func, dFunc);
    newtonMethod.iterate();

    std::cout << "Secant Method:\n";
    SecantMethod<double> secantMethod(0, 0.1, 1e-6, func);
    secantMethod.iterate();
    return 0;
}
