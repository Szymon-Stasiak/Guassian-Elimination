#include "matrix.h"
#include "gaussian.h"
#include "input.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    if(argc < 3) {
        fprintf(stderr, "Nie wystarczajaca liczba arg\n");
        return -1;
    }

    matrix_t* mat = matrixFile(argv[1], argv[2]);
    if(!mat) {
        fprintf(stderr, "Nie udalo sie wczytac macierzy z plikow: %s oraz %s", argv[1], argv[2]);
        return -1;
    }

    solveGaus(mat);
    printMatrix(mat);
    freeMatrix(mat);
    return 0;
}