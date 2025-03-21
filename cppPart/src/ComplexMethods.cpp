#include <iostream>
#include <complex>
#include <vector>
#include "../includes/ComplexMethods.hpp"


namespace ComplexOps{

    template<typename T>
    std::complex<T> add(std::complex<T> a, std::complex<T> b){
        return a + b;
    }

    template<typename T>
    std::complex<T> sub(std::complex<T> a, std::complex<T> b){
        return a - b;
    }

    template<typename T>
    std::complex<T> multiply(std::complex<T> a, std::complex<T> b){
        return a * b;
    }

    template<typename T>
    std::complex<T> divide(std::complex<T> a, std::complex<T> b){
        return a / b;
    }

    double norma(std::complex<double> a){
        return std::abs(a);
    }

    template<typename T>
    std::complex<T> conjugate(std::complex<T> a){
        return std::conj(a);
    }

}