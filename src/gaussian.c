#include "gaussian.h"

int swapRow(matrix_t* matrix, int columnNum) {
    double** maxAbs = NULL;
    double abs = 0;
    for(int i=columnNum; i<matrix->i_w; i++) {
        double num = (matrix->m[i][columnNum] < 0)? -1 * matrix->m[i][columnNum] : matrix->m[i][columnNum];
        if(!maxAbs || abs < num) {
            maxAbs = &matrix->m[i];
            abs = num;
        }
    }
    double* temp = *maxAbs;
    *maxAbs = matrix->m[columnNum];
    matrix->m[columnNum] = temp;
    return 0;
}

int solveGaus(matrix_t* mat) {
    int min_s = (mat->i_w < mat->i_k)? mat->i_w : mat->i_k;
    for(int i=0; i<min_s; i++) {
        swapRow(mat, i);
        if(mat->m[i][i] == 0) {
            return -1;
        }
        for(int j=i+1; j<mat->i_w; j++) {
            double mult = mat->m[j][i] / mat->m[i][i];
            for(int z=i; z<mat->i_k; z++) {
                mat->m[j][z] -= mult * mat->m[i][z];
            }
        }
    }
    return 0;
}
