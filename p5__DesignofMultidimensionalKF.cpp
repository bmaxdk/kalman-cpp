#include <iostream>
#include <math.h>
#include <tuple>
#include "Core" // Eigen Library
#include "LU"   // Eigen Library

using namespace std;
using namespace Eigen;

float measurements[3] = { 1, 2, 3 };


// tie(x, P) = kalman_filter(x, P, u, F, H, R, I);
tuple<MatrixXf, MatrixXf> kalman_filter(MatrixXf x, MatrixXf P, MatrixXf u, MatrixXf F, MatrixXf H, MatrixXf R, MatrixXf I)
{
    for (int n = 0; n < sizeof(measurements) / sizeof(measurements[0]); n++) {
        //****** TODO: Kalman-filter function********//
        // cout << "hihihihihihi n= " << n << endl;
        MatrixXf x_hat(F.rows(), x.cols());
        MatrixXf P_hat(P.rows(), P.cols());
        x_hat = F*x;
        P_hat = F*P*F.transpose();
        // cout << "x_hat= " << x_hat << endl;
        // cout << "P_hat= " << P_hat << endl;
        // Measurement Update
        MatrixXf y(H.rows(), x_hat.cols());
        MatrixXf z(H.rows(), x_hat.cols());
        // z = measurements[n];
        // cout << "measurements[n]= " << measurements[n] << endl;
        // cout << "P_hat= " << P_hat << endl;
        // y = measurements[n] - H*x_hat;

        y = - H*x_hat;
        y = z - y;
        // cout << "y= " << y << endl;

        MatrixXf S(R.rows(), R.cols());
        S = H*P_hat*H.transpose() + R;


        // // Code the Measurement Update
        // // MatrixXf P(2, 2);//Initial Uncertainty
        // // P << 100, 0, 
        // //     0, 100; 

        MatrixXf K(P_hat.rows(), S.inverse().cols());
        K = P_hat*H.transpose()*S.inverse();
        x = x_hat + K*y;
        MatrixXf Im;
        Im.setIdentity(K.rows(), H.cols());
        // P = Im - (K*H))*P_hat;
        P = (Im - (K*H))*P_hat;

        // // Initialize and Compute Z, y, S, K, x, and P
        
        
        
        
        
        
        
        
        // // Prediction
        // // Code the Prediction
        // // Compute x and P



        
        
    }

    return make_tuple(x, P);
}

int main()
{

    MatrixXf x(2, 1);// Initial state (location and velocity) 
    x << 0,
    	 0; 
    MatrixXf P(2, 2);//Initial Uncertainty
    P << 100, 0, 
    	 0, 100; 
    MatrixXf u(2, 1);// External Motion
    u << 0,
    	 0; 
    MatrixXf F(2, 2);//Next State Function
    F << 1, 1,
    	 0, 1; 
    MatrixXf H(1, 2);//Measurement Function
    H << 1,
    	 0; 
    MatrixXf R(1, 1); //Measurement Uncertainty
    R << 1;
    MatrixXf I(2, 2);// Identity Matrix
    I << 1, 0,
    	 0, 1; 

    tie(x, P) = kalman_filter(x, P, u, F, H, R, I);
    cout << "x= " << x << endl;
    cout << "P= " << P << endl;

    return 0;
}