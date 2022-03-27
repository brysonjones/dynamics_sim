
#include <iostream>
#include <autodiff/forward/real.hpp>
#include <autodiff/forward/real/eigen.hpp>
#include "dynamics/rotation.hpp"
// using namespace autodiff;

// The scalar function for which the gradient is needed
autodiff::real f(const autodiff::ArrayXreal& x) {
    return (x * x).sum(); // sum([xi * exp(xi) for i = 1:5])
}

int main() {
    Rotation rotation;
    VectorXd omega(4);
    omega << 1, 2, 3;
    rotation.rho(omega);

    autodiff::ArrayXreal x(5);                            // the input array x with 5 variables
    x << 1, 2, 3, 4, 5;                         // x = [1, 2, 3, 4, 5]

    autodiff::real u;                                     // the output scalar u = f(x) evaluated together with gradient below

    VectorXd g = gradient(f, wrt(x), at(x), u); // evaluate the function value u and its gradient vector g = du/dx
}