
#include "box.hpp"

Box::Box(): Object()
{
    m = 1;
    g = 9.81;
    J << MatrixXd::Identity(3, 3);
}

// potential energy function
// pos - x, y, z
autodiff::real Box::U(const autodiff::ArrayXreal& pos)
{
    return m*g*pos(2);
}  

