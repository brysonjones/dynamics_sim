
// Some standard functions for dealing with rotation matrices and quaternions 

#include <iostream>
#include <vector>
#include <autodiff/forward/real.hpp>
#include <autodiff/forward/real/eigen.hpp>
#include <Eigen/Dense>
#include <Eigen/Core>

// using namespace autodiff;
using namespace Eigen;

class Rotation {
    public:
        Rotation();
    // private:
        MatrixXd hat(VectorXd omega);
        MatrixXd L(VectorXd Q);
        MatrixXd R(VectorXd Q);
        MatrixXd G(VectorXd Q);
        MatrixXd G_tilde(VectorXd q);
        MatrixXd rho(VectorXd phi);
        MatrixXd H; // (Matrix3d::Zero(3, 3), Matrix3d::Identity(3, 3));
        MatrixXd T;


};
