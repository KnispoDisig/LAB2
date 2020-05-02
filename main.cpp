#include <iostream>
#include "DiagonalMatrix.cpp"


int main() {

    int **array = new int *[5];
    array[0] = new int[5]{2, 3, 6, 4, 7};
    array[1] = new int[5]{4, 3, 5, 7, 5};
    array[2] = new int[5]{3, 4, 1, 4, 9};
    array[3] = new int[5]{4, 3, 3, 9, 8};
    array[4] = new int[5]{5, 2, 1, 4, 5};

    ArraySequence<int> **arrayOfSequences = new ArraySequence<int>*[5];
    for (int i = 0; i < 5; i++) {
        arrayOfSequences[i] = new ArraySequence<int>(array[i], 5);
    }

    DiagonalMatrix<int> *matrix = new DiagonalMatrix<int>(reinterpret_cast<Sequence<int> **>(arrayOfSequences), 5, 1, 0);
    matrix->print();

    return 0;
}
