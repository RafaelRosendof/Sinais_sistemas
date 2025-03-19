#ifndef LINEARAL_HPP
#define LINEARAL_HPP

#include <vector>
#include <iostream>

/*
#include <stdexcept> lançar exceções
*/


/*

* This methods is gonna give the option to print the graphical form of the vectors with an external API in python 
* We gonna use the function to call the python script that will plot the graph

*/

namespace LinearAl {

    template<typename T>
    double norma(std::vector<T> &vecA);

    //check if the vectors need to be some type different from double
    template<typename T>
    std::vector<T> add_vec(std::vector<T> &vecA , std::vector<T> &vecB);

    template<typename T>
    std::vector<T> sub_vec(std::vector<T> &vecA , std::vector<T> &vecB);

    template<typename T>
    std::vector<T> multi_vec(std::vector<T> &vecA , std::vector<T> &vecB);

    template<typename T>
    std:vector<std::vector<T>> add_mat(std::vector<std::vector<T>> &matA , std::vector<std::vector<T>> &matB);

    template<typename T>
    std:vector<std::vector<T>> multi_mat(std::vector<std::vector<T>> &matA , std::vector<std::vector<T>> &matB);

    template<typename T>
    std::vector<std::vector<T>> LU_decomposition(std::vector<std::vector<T>> &matA , std::vector<T> &b); //Ax = b 

    //for while only the methods for vectors and matrices will be implemented
    //the methods for signals and systems will be implemented in the future


}

#endif //LINEARAL_HPP