#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SUCCESS = true;
#define FAILURE = false;

typedef struct _Matrix Matrix;

/* type definitions for VTable */
/* destructor */
typedef bool (*fptrDestroy)(Matrix *);

/* Matrix manipulators */
typedef bool (*fptrRowSwap)(Matrix *, int, int);
typedef bool (*fptrScalarMultiply)(Matrix *, double);
typedef bool (*fptrScalarRowMultiply)(Matrix *m, int row, double factor);
typedef bool (*fptrAdd)(Matrix *);
typedef bool (*fptrSubtract)(Matrix *);

/* Matrix derived values */
typedef double (*fptrDeterminant)(Matrix *);
typedef int (*fptrZeroVector)(Matrix *);

/* Matrix-derived constructions */
typedef Matrix (*fptrInvert)(Matrix *);
typedef Matrix (*fptrTranspose)(Matrix *);
typedef Matrix (*fptrMultiply)(Matrix *, Matrix *);
typedef Matrix (*fptrHadamard)(Matrix *, Matrix *);

/* Misc */
typedef bool (*fptrPrint)(Matrix *);
typedef bool (*fptrEquals)(Matrix *, Matrix *);

typedef struct _Matrix
{
    void *Matrix__DerivedObj;
    int rows;
    int cols;
    double *data;
    fptrDestroy destroy;
    fptrRowSwap row_swap;
    fptrScalarMultiply scalar_multiply;
    fptrScalarRowMultiply row_multiply;
    fptrAdd add;
    fptrSubtract subtract;
    fptrDeterminant determinant;
    fptrZeroVector zero_vector;
    fptrInvert invert;
    fptrTranspose transpose;
    fptrMultiply multiply;
    fptrHadamard hadamard;
    fptrPrint print;
    fptrEquals equals;

} Matrix;

/* Constructors and destructors */
Matrix *Matrix__constructor(int r, int c);
Matrix *Matrix__identity(int length);
Matrix *Matrix__clone(Matrix *m);
bool Matrix__destroy(Matrix *m);

/* Matrix manipulators */
bool Matrix__row_swap(Matrix *m, int a, int b);
bool Matrix__scalar_multiply(Matrix *m, double f);
bool Matrix__row_scalar_multiply(Matrix *m, int row, double factor);
bool Matrix__add(Matrix *m1, Matrix *m2);
bool Matrix__subtract(Matrix *m1, Matrix *m2);

/* Matrix-derived values */
double Matrix__determinant(Matrix *m);
bool Matrix__zero_vector(Matrix *m);

/* Matrix-derived constructions */
Matrix *Matrix__invert(Matrix *m);
Matrix *Matrix__transpose(Matrix *m);
Matrix *Matrix__multiply(Matrix *m1, Matrix *m2);
Matrix *Matrix__hadamard(Matrix *m1, Matrix *m2);

/* Input/Output Saving/Loading */

/* Misc */
bool Matrix__print(Matrix *m);
bool Matrix__equals(Matrix *m1, Matrix *m2);

//Planned features for the future:
// int reduce(Matrix *m, int a, int b, float factor);
// Matrix *gram_schmidt(Matrix *);
// double *projection(Matrix *, double *, int length);
// Matrix *orthonormal_basis(Matrix *);
// Matrix *solved_aug_matrix(Matrix *);
// double *eigenvalues(Matrix *m);

// static double vector_multiply(double *col, double *row, int length);
// static void vector_addition(double *v1, double *v2, int length);
// static void scalar_vector_multiplication(double factor, double *vector, int length);
// static void vector_subtraction(double *v1, double *v2, int length);

#endif