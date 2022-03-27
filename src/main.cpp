
#include <iostream>
#include <autodiff/forward/real.hpp>
#include <autodiff/forward/real/eigen.hpp>
#include "dynamics/rotation.h"
// using namespace autodiff;

// The scalar function for which the gradient is needed
autodiff::real f(const autodiff::ArrayXreal& x) {
    return (x * x).sum(); // sum([xi * exp(xi) for i = 1:5])
}

int main() {
    VectorXd omega(3);
    omega << 1, 2, 3;
    hat(omega);

    autodiff::ArrayXreal x(5);                            // the input array x with 5 variables
    x << 1, 2, 3, 4, 5;                         // x = [1, 2, 3, 4, 5]

    autodiff::real u;                                     // the output scalar u = f(x) evaluated together with gradient below

    VectorXd g = gradient(f, wrt(x), at(x), u); // evaluate the function value u and its gradient vector g = du/dx

    std::cout << "u = " << u << std::endl;      // print the evaluated output u
    std::cout << "g = \n" << g << std::endl;    // print the evaluated gradient vector g = du/dx
}