#include <iostream>
#include "DiagonalMatrix.cpp"
#include "Complex/Complex.h"
#include "windows.h"

void showInfo() {
    std::cout << "LIST OF COMMANDS:\n";
    std::cout
            << "create (dimension) (diagonalCount) (implementation) (type)  -  creating diagonal matrix (implementation = list or array)";
    std::cout << "print  -  printing entering matrix\n";
    std::cout << "norm  -  calculating matrix's norm\n";
    std::cout << "add (diagonalCount)  -  entering new matrix to add it to main matrix\n";
    std::cout << "scalar (real number)  -  scalar multiplication\n";
    std::cout << "list (count) (dimension) (type) -  entering list of matrices and sum them\n";
    std::cout << "map (operation)  -  operation == 'add3' or 'sqr'\n";
    std::cout << "exit  -  to finish the programm\n\n";
}

template<typename T>
T sqr(T elem) {
    return elem * elem;
}

template<typename T>
T add3(T elem) {
    T three = {3};
    return elem + three;
}

std::string firstWord(std::string str) {
    std::string word;
    int i = 0;
    while (str[i] != ' ' && i != str.length()) {
        word += str[i];
        i++;
    }
    return word;
}

void removeFirstWord(std::string *str) {
    int i = 0;
    while ((*str)[i] != ' ' && i != (*str).length()) {
        i++;
    }
    if (i == (*str).length()) {
        (*str) = "";
    } else {
        (*str).erase(0, i + 1);
    }
}

DiagonalMatrix<int> *buildIntMatrix(int dim, int diagonalCount, bool array_or_list) {
    std::string line;
    std::cout << "Enter the matrix\n";

    int **array = new int *[dim];        //creating simple table of int
    for (int i = 0; i < dim; i++) {
        array[i] = new int[dim];
    }

    for (int i = 0; i < dim; i++) {
        std::getline(std::cin, line);
        for (int j = 0; j < dim; j++) {
            array[i][j] = std::stoi(firstWord(line));
            removeFirstWord(&line);
        }
    }

    DiagonalMatrix<int> *matrix = nullptr;
    if (!array_or_list) {
        ArraySequence<int> **rows = new ArraySequence<int> *[dim];
        for (int i = 0; i < dim; i++) {
            rows[i] = new ArraySequence<int>(array[i], dim);
        }
        matrix = new DiagonalMatrix<int>(reinterpret_cast<Sequence<int> **>(rows), dim, diagonalCount, array_or_list);
    } else {
        LinkedListSequence<int> **rows = new LinkedListSequence<int> *[dim];
        for (int i = 0; i < dim; i++) {
            rows[i] = new LinkedListSequence<int>(array[i], dim);
        }
        matrix = new DiagonalMatrix<int>(reinterpret_cast<Sequence<int> **>(rows), dim, diagonalCount, array_or_list);
    }

    return matrix;
}

DiagonalMatrix<double> *buildDoubleMatrix(int dim, int diagonalCount, bool array_or_list) {
    std::string line;
    std::cout << "Enter the matrix\n";

    double **array = new double *[dim];        //creating simple table of double
    for (int i = 0; i < dim; i++) {
        array[i] = new double[dim];
    }

    for (int i = 0; i < dim; i++) {
        std::getline(std::cin, line);
        for (int j = 0; j < dim; j++) {
            array[i][j] = std::stod(firstWord(line));
            removeFirstWord(&line);
        }
    }

    DiagonalMatrix<double> *matrix = nullptr;
    if (!array_or_list) {
        ArraySequence<double> **rows = new ArraySequence<double> *[dim];
        for (int i = 0; i < dim; i++) {
            rows[i] = new ArraySequence<double>(array[i], dim);
        }
        matrix = new DiagonalMatrix<double>(reinterpret_cast<Sequence<double> **>(rows), dim, diagonalCount,
                                            array_or_list);
    } else {
        LinkedListSequence<double> **rows = new LinkedListSequence<double> *[dim];
        for (int i = 0; i < dim; i++) {
            rows[i] = new LinkedListSequence<double>(array[i], dim);
        }
        matrix = new DiagonalMatrix<double>(reinterpret_cast<Sequence<double> **>(rows), dim, diagonalCount,
                                            array_or_list);
    }

    return matrix;
}

DiagonalMatrix<Complex> *buildComplexMatrix(int dim, int diagonalCount, bool array_or_list) {
    std::string line;
    double tempRe;
    double tempIm;
    std::cout << "Enter the matrix\nComplex number N + i * M is written like (N,M)\n";

    Complex **array = new Complex *[dim];
    for (int i = 0; i < dim; i++) {
        array[i] = new Complex[dim];
    }

    for (int i = 0; i < dim; i++) {
        std::getline(std::cin, line);
        for (int j = 0; j < dim; j++) {
            std::string elem = firstWord(line);
            tempRe = std::stod(elem.substr(1, elem.find_first_of(",") - 1));
            tempIm = std::stod(elem.substr(elem.find_first_of(",") + 1, elem.length() - elem.find_first_of(",") - 1));
            array[i][j] = Complex(tempRe, tempIm);
            removeFirstWord(&line);
        }
    }

    DiagonalMatrix<Complex> *matrix = nullptr;
    if (!array_or_list) {
        ArraySequence<Complex> **rows = new ArraySequence<Complex> *[dim];
        for (int i = 0; i < dim; i++) {
            rows[i] = new ArraySequence<Complex>(array[i], dim);
        }
        matrix = new DiagonalMatrix<Complex>(reinterpret_cast<Sequence<struct Complex> **>(rows), dim, diagonalCount,
                                             array_or_list);
    } else {
        LinkedListSequence<Complex> **rows = new LinkedListSequence<Complex> *[dim];
        for (int i = 0; i < dim; i++) {
            rows[i] = new LinkedListSequence<Complex>(array[i], dim);
        }
        matrix = new DiagonalMatrix<Complex>(reinterpret_cast<Sequence<struct Complex> **>(rows), dim, diagonalCount,
                                             array_or_list);
    }

    return matrix;
}

int main() {
    DiagonalMatrix<int> *intMatrix = nullptr;
    DiagonalMatrix<double> *doubleMatrix = nullptr;
    DiagonalMatrix<Complex> *complexMatrix = nullptr;

    std::string request;
    std::cout << R"(
  _               ____      _  _  ___     _____  _                               _   __  __       _        _
 | |        /\   |  _ \   _| || ||__ \   |  __ \(_)                             | | |  \/  |     | |      (_)
 | |       /  \  | |_) | |_  __  _| ) |  | |  | |_  __ _  __ _  ___  _ __   __ _| | | \  / | __ _| |_ _ __ ___  __
 | |      / /\ \ |  _ <   _| || |_ / /   | |  | | |/ _` |/ _` |/ _ \| '_ \ / _` | | | |\/| |/ _` | __| '__| \ \/ /
 | |____ / ____ \| |_) | |_  __  _/ /_   | |__| | | (_| | (_| | (_) | | | | (_| | | | |  | | (_| | |_| |  | |>  <
 |______/_/    \_\____/    |_||_||____|  |_____/|_|\__,_|\__, |\___/|_| |_|\__,_|_| |_|  |_|\__,_|\__|_|  |_/_/\_\
                                                          __/ |
                                                         |___/                                                    )"
              << "\n";
    std::cout << "INFO: here you can create diagonal matrix with INT, DOUBLE or COMPLEX values and work with it\n";
    std::cout << "print 'help' for showing list of commands\n\n";

    while (request != "exit") {
        std::getline(std::cin, request);

        if (firstWord(request) == "create") {
            removeFirstWord(&request);

            int dim = std::stoi(firstWord(request));
            if (dim < 1) {
                std::cout << "Wrong parameter\n";
                throw std::exception();
            }
            removeFirstWord(&request);

            int diagonalCount = std::stoi(firstWord(request));
            if (diagonalCount % 2 == 0 || diagonalCount < 1 || diagonalCount > 2 * dim) {
                std::cout << "Wrong parameter\n";
                throw std::exception();
            }
            removeFirstWord(&request);

            bool array_or_list;
            if (firstWord(request) == "array") {
                array_or_list = 0;
            } else if (firstWord(request) == "list") {
                array_or_list = 1;
            } else {
                std::cout << "Error: not found such parameter\n";
                continue;
            }
            removeFirstWord(&request);

            std::string type = firstWord(request);
            if (type != "int" && type != "double" && type != "complex") {
                std::cout << "Invalid type\n";
                continue;
            }
            removeFirstWord(&request);

            if (type == "int") {
                intMatrix = buildIntMatrix(dim, diagonalCount, array_or_list);
                doubleMatrix = nullptr;
                complexMatrix = nullptr;
                intMatrix->print();
            } else if (type == "double") {
                doubleMatrix = buildDoubleMatrix(dim, diagonalCount, array_or_list);
                intMatrix = nullptr;
                complexMatrix = nullptr;
                doubleMatrix->print();
            } else if (type == "complex") {
                complexMatrix = buildComplexMatrix(dim, diagonalCount, array_or_list);
                intMatrix = nullptr;
                doubleMatrix = nullptr;
                complexMatrix->print();
            }
            std::cout << "\n";

        } else if (firstWord(request) == "print") {
            if (intMatrix != nullptr) {
                intMatrix->print();
            } else if (doubleMatrix != nullptr) {
                doubleMatrix->print();
            } else if (complexMatrix != nullptr) {
                complexMatrix->print();
            } else {
                std::cout << "Matrix doesn't exist\n";
            }
            std::cout << "\n\n";

        } else if (firstWord(request) == "norm") {
            if (intMatrix != nullptr) {
                std::cout << "= " << intMatrix->norm() << "\n\n";
            } else if (doubleMatrix != nullptr) {
                std::cout << "= " << doubleMatrix->norm() << "\n\n";
            } else if (complexMatrix != nullptr) {
                std::cout << "What does it mean???\n\n";
            } else {
                std::cout << "Matrix doesn't exist\n\n";
            }

        } else if (firstWord(request) == "add") {
            if (intMatrix == nullptr && doubleMatrix == nullptr && complexMatrix == nullptr) {
                std::cout << "Main matrix doesn't exist\n";
            }
            removeFirstWord(&request);
            int diagonalCount = std::stoi(firstWord(request));

            std::cout << "\nPlease, enter a matrix with dimension = ";
            if (intMatrix != nullptr) {
                std::cout << intMatrix->getDim() << "\n";
                DiagonalMatrix<int> *temp = buildIntMatrix(intMatrix->getDim(), diagonalCount, 0);
                intMatrix = intMatrix->sum(temp);
                intMatrix->print();
            } else if (doubleMatrix != nullptr) {
                std::cout << doubleMatrix->getDim() << "\n";
                DiagonalMatrix<double> *temp = buildDoubleMatrix(doubleMatrix->getDim(), diagonalCount, 0);
                doubleMatrix = doubleMatrix->sum(temp);
                doubleMatrix->print();
            } else if (complexMatrix != nullptr) {
                std::cout << complexMatrix->getDim() << "\n";
                DiagonalMatrix<Complex> *temp = buildComplexMatrix(complexMatrix->getDim(), diagonalCount, 0);
                complexMatrix = complexMatrix->sum(temp);
                complexMatrix->print();
            }

        } else if (firstWord(request) == "help") {
            showInfo();

        } else if (firstWord(request) == "scalar") {
            removeFirstWord(&request);
            double lambda = std::stod(firstWord(request));
            if (complexMatrix != nullptr) {
                Complex cLambda = {lambda};
                complexMatrix = complexMatrix->skalarMultiply(cLambda);
            } else if (intMatrix != nullptr) {
                intMatrix = intMatrix->skalarMultiply(lambda);
            } else if (doubleMatrix != nullptr) {
                doubleMatrix = doubleMatrix->skalarMultiply(lambda);
            } else {
                std::cout << "Matrix doesn't exist\n\n";
            }

        } else if (firstWord(request) == "list") {
            removeFirstWord(&request);
            int count = std::stoi(firstWord(request));
            removeFirstWord(&request);
            int dim = std::stoi(firstWord(request));
            removeFirstWord(&request);
            std::string type = firstWord(request);

            std::string diagonalCount;
            if (type == "int") {
                DiagonalMatrix<int> **matrixArrI = new DiagonalMatrix<int> *[count];
                for (int i = 0; i < count; i++) {
                    std::cout << "Enter the " << i + 1 << " matrix!\n";
                    std::cout << "Diagonal count = \n";
                    std::getline(std::cin, diagonalCount);
                    matrixArrI[i] = buildIntMatrix(dim, std::stoi(diagonalCount), 0);
                }
                LinkedListSequence<DiagonalMatrix<int> *> *list = new LinkedListSequence<DiagonalMatrix<int> *>(
                        matrixArrI, count);
                DiagonalMatrix<int> *summaryMatrix = DiagonalMatrix<int>::sumOfList(list, count);
                summaryMatrix->print();
            } else if (type == "double") {
                DiagonalMatrix<double> **matrixArrD = new DiagonalMatrix<double> *[count];
                for (int i = 0; i < count; i++) {
                    std::cout << "Enter the " << i + 1 << " matrix!\n";
                    std::cout << "Diagonal count = \n";
                    std::getline(std::cin, diagonalCount);
                    matrixArrD[i] = buildDoubleMatrix(dim, std::stoi(diagonalCount), 0);
                }
                LinkedListSequence<DiagonalMatrix<double> *> *list = new LinkedListSequence<DiagonalMatrix<double> *>(
                        matrixArrD, count);
                DiagonalMatrix<double> *summaryMatrix = DiagonalMatrix<double>::sumOfList(list, count);
                summaryMatrix->print();
            } else if (type == "complex") {
                DiagonalMatrix<Complex> **matrixArrC = new DiagonalMatrix<Complex> *[count];
                for (int i = 0; i < count; i++) {
                    std::cout << "Enter the " << i + 1 << " matrix!\n";
                    std::cout << "Diagonal count = \n";
                    std::getline(std::cin, diagonalCount);
                    matrixArrC[i] = buildComplexMatrix(dim, std::stoi(diagonalCount), 0);
                }
                LinkedListSequence<DiagonalMatrix<Complex> *> *list = new LinkedListSequence<DiagonalMatrix<Complex> *>(
                        matrixArrC, count);
                DiagonalMatrix<Complex> *summaryMatrix = DiagonalMatrix<Complex>::sumOfList(list, count);
                summaryMatrix->print();
            } else {
                std::cout << "Such type is not found\n\n";
                continue;
            }

        } else if (firstWord(request) == "map") {
            removeFirstWord(&request);
            std::string operation = firstWord(request);

            if (operation == "add3") {
                if (intMatrix != nullptr) {
                    intMatrix->map(add3<int>);
                } else if (doubleMatrix != nullptr) {
                    doubleMatrix->map(add3<double>);
                } else if (complexMatrix != nullptr) {
                    complexMatrix->map(add3<Complex>);
                } else {
                    std::cout << "Matrix doesn't exist\n";
                    continue;
                }

            } else if (operation == "sqr") {
                if (intMatrix != nullptr) {
                    intMatrix->map([](int &n)->int
                    {
                        return n;
                    });
                } else if (doubleMatrix != nullptr) {
                    doubleMatrix->map(sqr<double>);
                } else if (complexMatrix != nullptr) {
                    complexMatrix->map([]());
                } else {
                    std::cout << "Matrix doesn't exist\n";
                    continue;
                }

            } else {
                std::cout << "We have no such operation!\n";
                continue;
            }

        } else if (firstWord(request) == "exit") {
            std::cout << R"(
 _
| |
| |__  _   _  ___
| '_ \| | | |/ _ \
| |_) | |_| |  __/
|_.__/ \__, |\___|
        __/ |
       |___/      )";

        } else {
            std::cout << "UNKNOWN COMMAND\nSELF DESTRUCTION IN\n";
            for (int i = 3; i > 0; i--) {
                std::cout << i << "\n";
                Sleep(1000);
            }
            std::cout << R"(
     _.-^^---....,,--
 _--                  --_
<                        >)
|                         |
 \._                   _./
    ```--. . , ; .--'''
          | |   |
       .-=||  | |=-.
       `-=#$%&%$#=-'
          | ;  :|
 _____.,-#%&$@%#&#~,._____
        )" << "\n";
            Sleep(1000);
            std::cout << "\n\n";
            showInfo();
        }
    }


    return 0;
}

