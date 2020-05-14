//
// Created by fell2 on 03.04.2020.
//

#include "Sequence/ArraySequence/ArraySequence.cpp"
#include "Sequence/ListSequence/LinkedListSequence.cpp"

#ifndef THEFIRSTAPP_DIAGONALMATRIX_H
#define THEFIRSTAPP_DIAGONALMATRIX_H

template<class T>
class DiagonalMatrix {
private:
    Sequence<Sequence<T> *> *table;
    int dim{};
    int diagonalCount{};
    bool array_or_list{};
public:
    DiagonalMatrix(Sequence<T> **rows, int dimension, int diagonalCount, bool array_or_list);

    DiagonalMatrix(const DiagonalMatrix<T> &matrix);

    DiagonalMatrix *sum(DiagonalMatrix *matrix2);

    DiagonalMatrix *skalarMultiply(T num);

    double norm();

    void print();

    static DiagonalMatrix<T> *sumOfList(LinkedListSequence<DiagonalMatrix<T>*> *matrixList, int count);

    void map(T* t) {
        for (int i = 0; i < this->dim; i++) {
            for (int j = 0; j < this->dim; j++) {
                T newElem = t(this->getItem(i, j));
                this->table->get(i)->set(j, newElem);
            }
        }
    }

    T getItem(int i, int j);

    int getDim();

    int getDiagonalCount();

    std::string getImplementation();

    ~DiagonalMatrix() = default;

};


#endif //THEFIRSTAPP_DIAGONALMATRIX_H
