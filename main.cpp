#include <iostream>
#include "DiagonalMatrix.cpp"
#include "Complex/Complex.h"
#include "windows.h"

void showInfo() {
    std::cout << "LIST OF COMMANDS:\n";
    std::cout << "create (dimension) (diagonalCount) (implementation) (type)  -  creating diagonal matrix (implementation = list or array)";
    std::cout << "print  -  printing entering matrix\n";
    std::cout << "norm  -  calculating matrix's norm\n";
    std::cout << "add (diagonalCount)  -  entering new matrix to add it to main matrix\n";
    std::cout << "exit  -  to finish the programm\n\n";
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
        matrix = new DiagonalMatrix<double>(reinterpret_cast<Sequence<double> **>(rows), dim, diagonalCount, array_or_list);
    } else {
        LinkedListSequence<double> **rows = new LinkedListSequence<double> *[dim];
        for (int i = 0; i < dim; i++) {
            rows[i] = new LinkedListSequence<double>(array[i], dim);
        }
        matrix = new DiagonalMatrix<double>(reinterpret_cast<Sequence<double> **>(rows), dim, diagonalCount, array_or_list);
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
                                                         |___/                                                    )" << "\n";
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
            if (diagonalCount % 2 == 0 || diagonalCount < 1 || diagonalCount > 2 * dim){
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
                complexMatrix;
            }
            std::cout << "\n";

        } else if (firstWord(request) == "print") {
            if (intMatrix != nullptr) {
                intMatrix->print();
            } else if (doubleMatrix != nullptr) {
                doubleMatrix->print();
            } else if (complexMatrix != nullptr) {

            } else {
                std::cout << "Matrix doesn't exist\n";
            }
            std::cout << "\n\n";

        } else if (firstWord(request) == "norm") {
            if (intMatrix != nullptr) {
                std::cout << "= " << intMatrix->norm() << "\n";
            } else if (doubleMatrix != nullptr) {
                std::cout << "= " << doubleMatrix->norm() << "\n";
            } else if (complexMatrix != nullptr) {

            } else {
                std::cout << "Matrix doesn't exist\n";
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
            }
            
        } else if (firstWord(request) == "help") {
            showInfo();

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
        }
    }

    return 0;
}

