#include "matrix.h"

matrix_t* initMatrix(int i_w, int i_k) {
    matrix_t* mat = malloc(sizeof(matrix_t));
    if(!mat) return NULL;

    double** matrix = malloc(sizeof(double*) * i_w);
    if(!matrix) return NULL;

    for(int i=0; i<i_w; i++) {
        matrix[i] = malloc(sizeof(double) * i_k);
        if(!matrix[i]) return NULL;
    }

    mat->m = matrix;
    mat->i_w = i_w;
    mat->i_k = i_k;
    mat->i = 0;

    return mat;
}

int addToMatrix(matrix_t* mat, double val) {
    if(mat->i == mat->i_k * mat->i_w) return -1;
    mat->m[(int)(mat->i/mat->i_k)][mat->i%mat->i_k] = val;
    mat->i++;
    return 0;
}

void printMatrix(matrix_t* mat) {
    for(int i=0; i<mat->i_w; i++) {
        for(int j=0; j<mat->i_k; j++) {
            printf("%lf ", mat->m[i][j]);
        }
        printf("\n");
    }
}

void freeMatrix(matrix_t* mat) {
    for(int i=0; i<mat->i_k; i++) {
        free(mat->m[i]);
    }
    free(mat->m);
    free(mat);
}

void countSolutions(matrix_t* mat) {
 	
 	double solutions[mat->i_w]={0};
    for(int i=mat->i_w-1; i>=0; i--) {
    	double temp=[i][mat->k-1];
        for(int j=0; j<mat->i_k; j++) {
        temp-=mat->m[i][j]*soultions[j];
            printf("%lf ", mat->m[i][j]);
            
        }
        solutions[i]=temp;
    }
    for(int i=mat->i_w-1; i>=0; i--) {
    	printf("x %lf " ,soultions[i]);
    }
}