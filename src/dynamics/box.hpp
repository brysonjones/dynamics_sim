
#include <iostream>
#include <autodiff/forward/real.hpp>
#include <autodiff/forward/real/eigen.hpp>
#include <Eigen/Dense>
#include <Eigen/Core>

#include "object.hpp"

// using namespace autodiff;
using namespace Eigen;

class Box : public Object {
    public:
        Box();
        autodiff::real U(const autodiff::ArrayXreal& pos);  // potential energy function
    private:

    protected:
        double length = 1;
        double width = 1;
        double height = 1;

};
