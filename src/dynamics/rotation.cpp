
#include "rotation.hpp"


// TODO: hat function is used to ...
MatrixXd hat(VectorXd omega) {
    MatrixXd mat(3, 3);
    
    mat << 0, -omega(2), omega(1), 
           omega(2), 0, -omega(0), 
           -omega(1), omega(0), 0;

    return mat;
}

MatrixXd L(VectorXd Q) {
    VectorXd Q_tail(3);
    Q_tail << Q(1), Q(2), Q(3);
    
    MatrixXd I = MatrixXd::Identity(3, 3);

    MatrixXd mat(4, 4);
    mat << Q(0), -Q_tail.transpose(),
           Q_tail, (Q(0) * I + hat(Q_tail));

    return mat;
}

MatrixXd R(VectorXd Q) {
    VectorXd Q_tail(3);
    Q_tail << Q(1), Q(2), Q(3);
    
    MatrixXd I = MatrixXd::Identity(3, 3);

    MatrixXd mat(4, 4);
    mat << Q(0), -Q_tail.transpose(),
           Q_tail, (Q(0) * I - hat(Q_tail));

    return mat;
}

MatrixXd G(VectorXd Q) {
    return L(Q)*H;
}

MatrixXd G_tilde(VectorXd q) {
    VectorXd Q(4);
    Q << q(3), q(4), q(5), q(6);
    MatrixXd out(7, 6);
    out << MatrixXd::Identity(3, 3), MatrixXd::Zero(3, 3), MatrixXd::Zero(4, 3), G(Q);
    return out;
}

// rho represents the Cayley map
MatrixXd rho(VectorXd phi) {
    VectorXd phi_new(4);
    phi_new << 1, phi;
    VectorXd out(4);
    out = (1 / sqrt(1 + phi.dot(phi))) * phi_new;
    return out;
}
