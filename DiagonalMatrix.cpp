//
// Created by fell2 on 03.04.2020.
//

#include "DiagonalMatrix.h"

template<class T>
DiagonalMatrix<T>::DiagonalMatrix(Sequence<T> **rows, int dimension, int diagonalCount) {
    this->table = new ArraySequence<Sequence<T> *>(rows, dimension);
    this->dim = dimension;
    this->diagonalCount = diagonalCount;
}

template<class T>
DiagonalMatrix<T>::DiagonalMatrix(const DiagonalMatrix<T> &matrix) {
    Sequence<T> **rows = new ArraySequence<T> *[matrix.dim];
    for (int i = 0; i < matrix.dim; i++) {
        rows[i] = new ArraySequence<T>(*matrix.table->get(i));
    }
    this->table = new ArraySequence<Sequence<T> *>(rows, matrix.dim);
}

template<class T>
void DiagonalMatrix<T>::print() {
    std::cout << "\n";
    for (int i = 0; i < this->dim; i++) {
        std::cout << "| ";
        this->table->get(i)->print();
        std::cout << "|" << std::endl;
    }
}

template<class T>
DiagonalMatrix<T> *DiagonalMatrix<T>::sum(DiagonalMatrix *matrix1, DiagonalMatrix *matrix2) {

}



