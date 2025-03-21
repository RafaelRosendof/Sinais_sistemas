#include <iostream>
#include <complex>
#include <cstdlib>   
#include <sstream>
#include <includes/ComplexMethods.hpp>

void plotComplexNumbers(const std::complex<double>& a, const std::complex<double>& b, const std::complex<double>& c) {
    std::ostringstream command;
    command << "python3 plot.py"
            << " --x1 " << a.real() << " --y1 " << a.imag()
            << " --x2 " << b.real() << " --y2 " << b.imag()
            << " --x3 " << c.real() << " --y3 " << c.imag();

    int result = std::system(command.str().c_str());
    
    if (result != 0) {
        std::cerr << "Erro ao executar o script Python!" << std::endl;
    }
}

void processaComplex(){

    std::cout << "Digite o tipo de operação que deseja fazer: " << std::endl;
    std::cout << "1 - Adição" << std::endl;
    std::cout << "2 - Subtração" << std::endl;
    std::cout << "3 - Multiplicação" << std::endl;
    std::cout << "4 - Divisão" << std::endl;
    std::cout << "5 - Norma" << std::endl;
    std::cout << "6 - Conjugado" << std::endl;

    int op; 

    std::cin >> op;

    std::complex<double> a, b, c;

    if( op == 1){
        std::cout << "Digite o primeiro número complexo (real e imaginário): ";
        std::cin >> a;

        std::cout << "Digite o segundo número complexo (real e imaginário): ";
        std::cin >> b;

        c = ComplexOps::add(a,b);

        plotComplexNumbers(a, b, c);
    }

    if( op == 2){
        std::cout << "Digite o primeiro número complexo (real e imaginário): ";
        std::cin >> a;

        std::cout << "Digite o segundo número complexo (real e imaginário): ";
        std::cin >> b;

        c = ComplexOps::sub(a,b);

        plotComplexNumbers(a, b, c);
    }

    if( op == 3){
        std::cout << "Digite o primeiro número complexo (real e imaginário): ";
        std::cin >> a;

        std::cout << "Digite o segundo número complexo (real e imaginário): ";
        std::cin >> b;

        c = ComplexOps::multiply(a,b);

        plotComplexNumbers(a, b, c);
    }

    if( op == 4){
        std::cout << "Digite o primeiro número complexo (real e imaginário): ";
        std::cin >> a;

        std::cout << "Digite o segundo número complexo (real e imaginário): ";
        std::cin >> b;

        c = ComplexOps::divide(a,b);

        plotComplexNumbers(a, b, c);
    }

    if( op == 5){
        std::cout << "Digite o número complexo (real e imaginário): ";
        std::cin >> a;

        std::cout << "Norma: " << ComplexOps::norma(a) << std::endl;
    }

    if( op == 6){
        std::cout << "Digite o número complexo (real e imaginário): ";
        std::cin >> a;

        c = ComplexOps::conjugate(a);

        plotComplexNumbers(a, b, c);
    }


}


def main(){

    std::cout << "Seja bem vindo " << std::endl;
    std::cout << "Escolha o tipo de operação que deseja fazer: " << std::endl;
    std::cout << "1 - Operações com números complexos" << std::endl;
    std::cout << "2 No momento estamos trabalhando em mais métodos para a biblioteca" << std::endl;

    int op;
    std::cin >> op;

    if (op == 1){
        processaComplex();
    }

    return 0;
}


/*

#include <iostream>
#include <complex>
#include <cstdlib>  // Para system()
#include <sstream>  // Para construir a string de comando

void plotComplexNumbers(const std::complex<double>& a, const std::complex<double>& b, const std::complex<double>& c) {
    // Construindo o comando para chamar o Python
    std::ostringstream command;
    command << "python3 plot.py"
            << " --x1 " << a.real() << " --y1 " << a.imag()
            << " --x2 " << b.real() << " --y2 " << b.imag()
            << " --x3 " << c.real() << " --y3 " << c.imag();

    // Executando o comando
    int result = std::system(command.str().c_str());
    
    if (result != 0) {
        std::cerr << "Erro ao executar o script Python!" << std::endl;
    }
}

int main() {
    std::complex<double> a, b, c;

    std::cout << "Digite o primeiro número complexo (real e imaginário): ";
    std::cin >> a;

    std::cout << "Digite o segundo número complexo (real e imaginário): ";
    std::cin >> b;

    std::cout << "Digite o terceiro número complexo (real e imaginário): ";
    std::cin >> c;

    plotComplexNumbers(a, b, c);

    return 0;
}

*/