
#include "object.hpp"

Object::Object():
J(3, 3)
{

}

autodiff::real Object::U(const autodiff::ArrayXreal& pos)
{
    autodiff::real x;
    return x;
}

VectorXd Object::DLT1(const autodiff::ArrayXreal& q1, const autodiff::ArrayXreal& q2, double h)
{
    using Eigen::VectorXd;

    // TODO: revisit this initalization to determine if it can b cleaned up
    autodiff::ArrayXreal r1(3);
    autodiff::ArrayXreal Q1(4);
    autodiff::ArrayXreal r2(3);
    autodiff::ArrayXreal Q2(4);
    r1 << q1(0), q1(1), q1(2);
    Q1 << q1(3), q1(4), q1(5), q1(6);
    r2 << q2(0), q2(1), q2(2);
    Q2 << q2(3), q2(4), q2(5), q2(6);
    
    autodiff::real u; 
    // output the right discrete Legendre transform for a free rigid body
    // VectorXd dU = autodiff::gradient(U, autodiff::wrt((r1 + r2)/2), autodiff::at((r1 + r2)/2), u);
    // VectorXd out_trans = -m * (r2 - r1) / h + (h/2)*m*(-dU);
    // VectorXd out_rot = (2/h)*G(Q1).transpose()*T*R(Q2).transpose()*H*J*H.transpose()*L(Q1).transpose()*Q2;
    VectorXd xx;
    // return [out_trans; out_rot]
    return xx;
}
