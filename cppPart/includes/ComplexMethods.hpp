#ifndef COMPLEXMEHTODS_HPP
#define COMPLEXMEHTODS_HPP


#include <complex>
#include <vector>
#include <iostream>

namespace ComplexOps {

    template<typename T>
    std::complex<T> add(std::complex<T> a, std::complex<T> b);

    template<typename T>
    std::complex<T> sub(std::complex<T> a, std::complex<T> b);

    template<typename T>
    std::complex<T> multiply(std::complex<T> a, std::complex<T> b);

    template<typename T>
    std::complex<T> divide(std::complex<T> a, std::complex<T> b);

    double norma(std::complex<double> a);

    template<typename T>
    std::complex<T> conjugate(std::complex<T> a);

}



#endif // !COMPLEXMETHODS_HPP
