#pragma once

#include "matrix.h"

static void swap(double**, double**);
static int swapRow(matrix_t*, int);
static void rowElim(double**, double**, int size);
int solveGaus(matrix_t*);