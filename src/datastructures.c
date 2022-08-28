#include "datastructures.h"
#include <stdlib.h>

MATRIX *alloc_matrix(unsigned num_rows, unsigned num_cols) {
    unsigned j;

    MATRIX *matrix = (MATRIX *) malloc(sizeof(MATRIX));
    double **data = (double **) malloc(num_cols * sizeof(double *));
    double *underlying_data = (double *) malloc(num_rows * num_cols * sizeof(double));
    if (!matrix || !data || !underlying_data) return NULL;
    
    for (j = 0; j < num_cols; j++)
        data[j] = underlying_data + j * num_rows * sizeof(double);
    matrix->data = data;
    matrix->num_rows = num_rows;
    matrix->num_cols = num_cols;

    return matrix;
}

void free_matrix(MATRIX *matrix) {
    if (!matrix) return;
    free(matrix->data[0]);
    free(matrix->data);
    free(matrix);
}