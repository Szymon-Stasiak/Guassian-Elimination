#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef struct Matrix {
    double** m; //Wskaznik macierzy [wiersz][kolumna]
    int i_w; //Ilosc wierszy
    int i_k; //Ilosc kolumn

    int i; //Ilosc wczytanych elementow
} matrix_t;

matrix_t* initMatrix(int, int); //Funkcja inicjalizujaca macierz z i_w wierszami i i_k kolumnami
int addToMatrix(matrix_t*, double); //Dodaje element do pierwszego pustego miejsca macierzy
void printMatrix(matrix_t*); //Funkcja wypisujaca zawartosc macierzy
void freeMatrix(matrix_t*); //Zwolnienie pamieci macierzy
void countSolutions(matrix_t* mat);
