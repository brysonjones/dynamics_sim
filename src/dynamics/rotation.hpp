
#pragma once

// Some standard functions for dealing with rotation matrices and quaternions 

#include <iostream>
#include <vector>
#include <Eigen/Dense>
#include <Eigen/Core>

using namespace Eigen;

const MatrixXd H = (MatrixXd() << MatrixXd::Zero(1, 3), MatrixXd::Identity(3, 3)).finished();
const MatrixXd T = (MatrixXd()  << 1, MatrixXd::Zero(1, 3), MatrixXd::Zero(3, 1), -MatrixXd::Identity(3, 3)).finished();

MatrixXd hat(VectorXd omega);
MatrixXd L(VectorXd Q);
MatrixXd R(VectorXd Q);
MatrixXd G(VectorXd Q);
MatrixXd G_tilde(VectorXd q);
MatrixXd rho(VectorXd phi);