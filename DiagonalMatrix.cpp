//
// Created by fell2 on 03.04.2020.
//

#include "DiagonalMatrix.h"


template<class T>
DiagonalMatrix<T>::DiagonalMatrix(Sequence<T> **rows, int dimension, int diagonalCount, bool array_or_list) {
    if (diagonalCount % 2 == 0 || diagonalCount > 2 * dimension - 1 || dimension != rows[0]->getLength() || diagonalCount < 1) {
        std::cout << "Matrix cannot be initialized\n";
        throw std::exception();
    }
    this->dim = dimension;
    this->diagonalCount = diagonalCount;

    if (!array_or_list) {
        this->table = new ArraySequence<Sequence<T> *>(rows, this->dim);
    } else {
        this->table = new LinkedListSequence<Sequence<T> *>(rows, this->dim);
    }

    for (int k = (this->diagonalCount + 1)/2; k < this->dim; k++) {
        int i = k;
        for (int j = 0; j < this->dim - k; j++) {
            this->table->get(i)->set(j, 0);
            this->table->get(j)->set(i, 0);
            i++;
        }
    }
}

template<class T>
void DiagonalMatrix<T>::print() {
    for (int i = 0; i < this->dim; i++) {
        std::cout << "\n";
        this->table->get(i)->print();
    }
}

template<class T>
T DiagonalMatrix<T>::getItem(int i, int j) {
    return this->table->get(i)->get(j);
}

