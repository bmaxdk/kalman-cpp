Kalman Filter
=============
This is a basic Kalman filter implementation in C++ using the [Eigen](http://eigen.tuxfamily.org/) library.

Currently implementations of these filter variants are included:

* Basic Kalman Filter(KF)
* Extended Kalman Filter (EKF)

## Dependencies

This library makes heavy use of the excellent [Eigen library](http://eigen.tuxfamily.org). Eigen is a C++ template library for linear algebra: matrices, vectors, numerical solvers, and related algorithms.

## Usage
In order to use the library to do state estimation, a number of things have to be done:

1. Define a state-vector type
2. (Optional) Define a control-vector type
3. Define a system model
4. Define one (or more) measurement models with corresponding measurement vector types

Navigate to your home directory and execute:

```
$ git clone https://github.com/bmaxdk/kalman-cpp.git
$ cd kalman-cpp
$ g++ <cpp file name>.cpp -o <cpp file name>
$ ./<cpp file name>
```

