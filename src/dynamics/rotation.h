
// Some standard functions for dealing with rotation matrices and quaternions 

#include <iostream>
#include <autodiff/forward/real.hpp>
#include <autodiff/forward/real/eigen.hpp>
#include <Eigen/Dense>
#include <Eigen/Core>

// using namespace autodiff;
using namespace Eigen;


// TODO: hat function is used to ...
MatrixXd hat(VectorXd omega){
    MatrixXd mat(3, 3);
    
    mat << 0, -omega(2), omega(1), 
           omega(2), 0, -omega(0), 
           -omega(1), omega(0), 0;

    return mat;
}

// function L(Q)
//     [Q[1] -Q[2:4]'; Q[2:4] Q[1]*I + hat(Q[2:4])]
// end

// function R(Q)
//     [Q[1] -Q[2:4]'; Q[2:4] Q[1]*I - hat(Q[2:4])]
// end

// const H = [zeros(1,3); I];

// const T = Diagonal([1.0; -1; -1; -1])

// function G(Q)
//     return L(Q)*H
// end

// function Ḡ(q)
//     Q = q[4:7]
//     return [I zeros(3,3); zeros(4,3) G(Q)]
// end
// function ρ(ϕ)
//     # convert from ϕ to a quaternion 
//     # read more: https://roboticexplorationlab.org/papers/planning_with_attitude.pdf
//     return (1/sqrt(1 + dot(ϕ,ϕ)))*[1;ϕ]
// end