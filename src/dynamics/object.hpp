

#include <iostream>
#include <autodiff/forward/real.hpp>
#include <autodiff/forward/real/eigen.hpp>
#include <Eigen/Dense>
#include <Eigen/Core>

#include "rotation.hpp"

// using namespace autodiff;
using namespace Eigen;

class Object {
    public:
        Object();
        virtual autodiff::real U(const autodiff::ArrayXreal& pos);
        VectorXd DLT1(const autodiff::ArrayXreal& q1, const autodiff::ArrayXreal& q2, double h);
    private:

    protected:
        double m = 1;  // mass (kg)
        double g = 1;  // gravity accel (m/s^2)
        MatrixXd J;  // (3x3) Inertia Tensor (kg*m^2)

};
