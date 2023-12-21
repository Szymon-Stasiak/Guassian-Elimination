#include "input.h"

matrix_t* matrixFile(const char* filename, const char* filename2) {
    FILE* file = fopen(filename, "r");
    FILE* file2 = fopen(filename2, "r");
    if(!file) return NULL;
    if(!file2) return NULL;

    int m, n;
    if(fscanf(file, "%d %d", &m, &n) == 0) {    
        fclose(file);
        fclose(file2);
        return NULL;
    }

    int m2, n2;
    if(fscanf(file2, "%d %d", &m2, &n2) == 0) {    
        fclose(file);
        fclose(file2);
        return NULL;
    }

    if(m2 != m) {    
        fclose(file);
        fclose(file2);
        return NULL;
    }

    matrix_t* mat = initMatrix(m, n + n2);
    if(!mat) {        
        fclose(file);
        fclose(file2);
        return NULL;
    }

    double num = 0;
    while(fscanf(file, "%lf", &num) == 1) {
        addToMatrix(mat, num);
        if(!((mat->i + 1) % mat->i_k)) {
            fscanf(file2, "%lf", &num);
            addToMatrix(mat, num);
        }
    }

    if(mat->i != mat->i_k * mat->i_w) {
        freeMatrix(mat);
        fclose(file);
        fclose(file2);
        return NULL;
    }

    fclose(file);
    fclose(file2);
    return mat;
}