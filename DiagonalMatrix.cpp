//
// Created by fell2 on 03.04.2020.
//

#include "DiagonalMatrix.h"
#include <cmath>
#include <iomanip>

template<class T>
DiagonalMatrix<T>::DiagonalMatrix(Sequence<T> **rows, int dimension, int diagonalCount, bool array_or_list) {
    if (diagonalCount % 2 == 0 || diagonalCount > 2 * dimension - 1 || dimension != rows[0]->getLength() ||
        diagonalCount < 1) {
        std::cout << "Matrix cannot be initialized\n";
        throw std::exception();
    }
    this->dim = dimension;
    this->diagonalCount = diagonalCount;
    this->array_or_list = array_or_list;

    if (!array_or_list) {
        this->table = new ArraySequence<Sequence<T> *>(rows, this->dim);
    } else {
        this->table = new LinkedListSequence<Sequence<T> *>(rows, this->dim);
    }

    for (int k = (this->diagonalCount + 1) / 2; k < this->dim; k++) {
        int i = k;
        for (int j = 0; j < this->dim - k; j++) {
            this->table->get(i)->set(j, {0});
            this->table->get(j)->set(i, {0});
            i++;
        }
    }
}

template<class T>
DiagonalMatrix<T>::DiagonalMatrix(const DiagonalMatrix<T> &matrix) {
    this->dim = matrix.dim;
    this->diagonalCount = matrix.diagonalCount;
    this->array_or_list = matrix.array_or_list;

    Sequence<T> **rows = new Sequence<T> *[this->dim];
    if (!this->array_or_list) {
        for (int i = 0; i < this->dim; i++) {
            rows[i] = new ArraySequence<T>(*dynamic_cast<ArraySequence<T> *> (matrix.table->get(i)));
        }
        this->table = new ArraySequence<Sequence<T> *>(rows, this->dim);
    } else {
        for (int i = 0; i < this->dim; i++) {
            rows[i] = new LinkedListSequence<T>(*dynamic_cast<LinkedListSequence<T> *> (matrix.table->get(i)));
        }
        this->table = new LinkedListSequence<Sequence<T> *>(rows, this->dim);
    }
}

template<class T>
void DiagonalMatrix<T>::print() {
    std::cout << "\n";
    for (int i = 0; i < this->dim; i++) {
        for (int j = 0; j < this->dim; j++) {
            std::cout << std::setw(4) << this->getItem(i, j);
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

template<class T>
T DiagonalMatrix<T>::getItem(int i, int j) {
    return this->table->get(i)->get(j);
}

template<class T>
DiagonalMatrix<T> *DiagonalMatrix<T>::skalarMultiply(T num) {
    DiagonalMatrix<T> *newMatrix = new DiagonalMatrix<T>(*this);

    for (int i = 0; i < newMatrix->dim; i++) {
        for (int j = 0; j < newMatrix->dim; j++) {
            newMatrix->table->get(i)->set(j, num * newMatrix->getItem(i, j));
        }
    }
    return newMatrix;
}

template<class T>
double DiagonalMatrix<T>::norm() {
    double qSum = 0;
    for (int i = 0; i < this->dim; i++) {
        for (int j = 0; j < this->dim; j++) {
            qSum += this->getItem(i, j) * this->getItem(i, j);
        }
    }
    return sqrt(qSum);
}

template<class T>
std::string DiagonalMatrix<T>::getImplementation() {
    if (!this->array_or_list) {
        return "array";
    } else {
        return "list";
    }
}

template<class T>
int DiagonalMatrix<T>::getDiagonalCount() {
    return this->diagonalCount;
}

template<class T>
int DiagonalMatrix<T>::getDim() {
    return this->dim;
}

template<class T>
DiagonalMatrix<T> *DiagonalMatrix<T>::sum(DiagonalMatrix *matrix) {
    if (matrix->dim != this->dim) {
        std::cout << "Cannot to implement sum\n";
        throw std::exception();
    }

    T sumElem;
    DiagonalMatrix<T> *matrixSum = new DiagonalMatrix<T>(*matrix);
    for (int i = 0; i < matrixSum->dim; i++) {
        for (int j = 0; j < matrixSum->dim; j++) {
            sumElem = matrixSum->getItem(i, j) + this->getItem(i, j);
            matrixSum->table->get(i)->set(j, sumElem);
        }
    }
    return matrixSum;
}

template<class T>
DiagonalMatrix<T> *DiagonalMatrix<T>::sumOfList(LinkedListSequence<DiagonalMatrix<T> *> *matrixList, int count) {
    DiagonalMatrix<T> *sumMatrix = new DiagonalMatrix<T>(*(matrixList->get(0)));

    for (int i = 1; i < count; i++) {
        sumMatrix = sumMatrix->sum(matrixList->get(i));
    }

    return sumMatrix;
}

template<class T>
DiagonalMatrix<T> *DiagonalMatrix<T>::map(T (*func)(T)) {
    DiagonalMatrix<T> *newMatrix = new DiagonalMatrix<T>(*this);

    for (int i = 0; i < newMatrix->dim; i++) {
        for (int j = 0; j < newMatrix->dim; j++) {
            T newElem = func(newMatrix->getItem(i, j));
            newMatrix->table->get(i)->set(j, newElem);
        }
    }

    return newMatrix;
}

