#ifndef METHODS_H
#define METHODS_H


#include <iostream>
#include <cmath>
#include <vector>
#include <complex>
#include <algorithm>
#include <string>
#include <boost/multiprecision/cpp_dec_float.hpp> //métodos de precisão arbitrária

//Adicionar bibilioteca para plotar gráficos em tempo real
//Adicionar métodos de boost para numeros de precisão arbitrária


class Methods {
    /*
    MÉTODOS A FAZER
    todos os métodos de números complexos{
    adição
    subtração
    multiplicalçao
    divisão
    norma
    conjugado
    }
    Métodos de matrizes e sistemas lineares{
    multiplicação de vetores e adição de vetores e subtração de vetores também (métodos deles para plotar também em tempo real)
    adição de matrizes
    multiplicação matrizes
    decomposição LU
    norma de vetor
    por enquanto só
    }
    agora parte de sinais e sistemas
    transformada de fourier
    e métodos adjacentes
    buscar biblioteca para visualizar dados em tempo real e animações posso usar uma api de python para issso
    TODO:    posturmamente
    transformada de laplace
    e métodos adjacentes
    transformada de z
    e métodos adjacentes
    */

    public:
    //Métodos de números complexos
    std::complex<double> add_complex(std::complex<double> a, std::complex<double> b);
    std::complex<double> sub_complex(std::complex<double> a , std::complex<double>b);
    std::complex<double> multi_complex(std::complex<double> a , std::complex<double>b);
    std::complex<double> div_complex(std::complex<double> a , std::complex<double>b);
    std::complex<double> norma(std::complex<double>a);
    std::complex<double> conjug(std::complex<double>a);


    //Métodos de matrizes, sistemas lineares e vetores

    double norma(std::vector<double>& vecA);
    double add_vec(std::vector<double>& vecA , std::vector<double> &Vecb);
    //Para métodos onde precisam da soma de mais de dois vetores será necessário melhorias póstumas ou uma composição por parte do cliente de um método por um
    double sub_vec(std::vector<double>& vecA , std::vector<double> &Vecb);
    double multi_vec(std::vector<double>& vecA , std::vector<double> &Vecb);
    double add_mat(std::vector<std::vector<double>>& matA , std::vector<std::vector<double>>& matB);
    double sub_mat(std::vector<std::vector<double>>& matA , std::vector<std::vector<double>>& matB);
    double multi_mat(std::vector<std::vector<double>>& matA , std::vector<std::vector<double>>& matB);
    double LU_decomposition(std::vector<std::vector<double>>& matA std::vector<double>& b);

    //Métodos de sinais e sistemas




};

#endif // METHODS_H
