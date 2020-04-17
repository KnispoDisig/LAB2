#include <iostream>
#include "DiagonalMatrix.cpp"


int main() {
    int **array = new int *[5];
    array[0] = new int[5]{2, 0, 0, 0, 0};
    array[1] = new int[5]{0, 3, 0, 0, 0};
    array[2] = new int[5]{0, 0, 1, 0, 0};
    array[3] = new int[5]{0, 0, 0, 9, 0};
    array[4] = new int[5]{0, 0, 0, 0, 5};

    Sequence<int> **rows = reinterpret_cast<Sequence<int> **>(new ArraySequence<int> *[5]);
    for (int i = 0; i < 5; i++) {
        rows[i] = new ArraySequence<int>(array[i], 5);
    }

    DiagonalMatrix<int> *matrix = new DiagonalMatrix<int>(rows, 5, 1);

    DiagonalMatrix<int> *matrix1 = new DiagonalMatrix<int>(*matrix);
    matrix1->print();

    return 0;
}
