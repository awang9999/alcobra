#include "matrix.h"
#include "special_math.h"

/* Constructors and destructors */
Matrix *Matrix__constructor(int r, int c)
{
    //memory allocation
    Matrix *mObj = NULL;
    mObj = (Matrix *)malloc(sizeof(Matrix));
    if (mObj == NULL)
    {
        return NULL;
    }

    //pointer to itself because Matrix has no parent class
    mObj->Matrix__DerivedObj = mObj;
    mObj->rows = r;
    mObj->cols = c;
    mObj->data = malloc(sizeof(double) * r * c);

    if (mObj->data == NULL)
    {
        return NULL;
    }

    //Initializing matrix with 0.0 entries
    for (int i = 0; i < (mObj->rows) * (mObj->cols); i++)
    {
        (mObj->data)[i] = 0.0;
    }

    //initializing interface for access to functions
    mObj->destroy = Matrix__destroy;
    mObj->row_swap = Matrix__row_swap;
    mObj->scalar_multiply = Matrix__scalar_multiply;
    mObj->row_scalar_multiply = Matrix__row_scalar_multiply;
    mObj->add = Matrix__add;
    mObj->subtract = Matrix__subtract;
    mObj->determinant = Matrix__determinant;
    mObj->zero_vector = Matrix__zero_vector;
    mObj->invert = Matrix__invert;
    mObj->transpose = Matrix__transpose;
    mObj->multiply = Matrix__multiply;
    mObj->hadamard = Matrix__hadamard;
    mObj->get = Matrix__get;
    mObj->set = Matrix__set;
    mObj->print = Matrix__print;
    mObj->size = Matrix__print_size;
    mObj->equals = Matrix__equals;

    return mObj;
}

Matrix *Matrix__identity(int length)
{
    return Matrix__constructor(length, length);
}

Matrix *Matrix__clone(Matrix *m)
{
    Matrix *copy = Matrix__constructor(m->rows, m->cols);
    for (int i = 0; i < m->rows * m->cols; i++)
    {
        (copy->data)[i] = (m->data)[i];
    }
    return copy;
}

Matrix *Matrix__fromArr(int r, int c, double *vals)
{
    Matrix *ret = Matrix__constructor(r, c);
    return ret;
}
bool Matrix__destroy(Matrix *m)
{
    free(m->data);
    free(m);
    return true;
}

/* Matrix manipulators */
bool Matrix__row_swap(Matrix *m, int a, int b)
{
    //TODO
    printf("WARNING: Matrix__row_swap is unimplemented\n");
    return false;
}
bool Matrix__scalar_multiply(Matrix *m, double f)
{
    //TODO
    printf("WARNING: Matrix__scalar_multiply is unimplemented\n");
    return false;
}
bool Matrix__row_scalar_multiply(Matrix *m, int row, double factor)
{
    //TODO
    printf("WARNING: Matrix__row_scalar_multiply is unimplemented\n");
    return false;
}
bool Matrix__add(Matrix *m1, Matrix *m2)
{
    //TODO
    printf("WARNING: Matrix__add is unimplemented\n");
    return false;
}
bool Matrix__subtract(Matrix *m1, Matrix *m2)
{
    //TODO
    printf("WARNING: Matrix__subtract is unimplemented\n");
    return false;
}

/* Matrix-derived values */
double Matrix__determinant(Matrix *m)
{
    //TODO
    printf("WARNING: Matrix__determinant is unimplemented\n");
    return 0;
}
bool Matrix__zero_vector(Matrix *m)
{
    //TODO
    printf("WARNING: Matrix__zero_vector is unimplemented\n");
    return false;
}

/* Matrix-derived constructions */
Matrix *Matrix__invert(Matrix *m)
{
    //TODO
    printf("WARNING: Matrix__invert is unimplemented\n");
    return NULL;
}
Matrix *Matrix__transpose(Matrix *m)
{
    //TODO
    printf("WARNING: Matrix__transpose is unimplemented\n");
    return NULL;
}

Matrix *Matrix__multiply(Matrix *m1, Matrix *m2)
{
    //TODO
    printf("WARNING: Matrix__multiply is unimplemented\n");
    return NULL;
}
Matrix *Matrix__hadamard(Matrix *m1, Matrix *m2)
{
    //TODO
    printf("WARNING: Matrix__hadamard is unimplemented\n");
    return NULL;
}

/* Mutators and accessors */
double Matrix__get(Matrix *m, int r, int c)
{
    return m->data[r * (m->cols) + c];
}
bool Matrix__set(Matrix *m, int r, int c, double val)
{
    m->data[r * (m->cols) + c] = val;
    return true;
}

/* Misc */
bool Matrix__print(Matrix *m)
{
    printf("[");
    for (int i = 0; i < m->rows; i++)
    {
        if (i > 0)
        {
            printf(" [");
        }
        else
        {
            printf("[");
        }

        for (int j = 0; j < m->cols; j++)
        {
            printf(" %f ", m->get(m, i, j));
        }

        if (i == (m->rows) - 1)
        {
            printf("]");
        }
        else
        {
            printf("]\n");
        }
    }
    printf("]\n");
    return true;
}

bool Matrix__print_size(Matrix *m)
{
    printf("(%d, %d)\n", m->rows, m->cols);
    return true;
}

bool Matrix__equals(Matrix *m1, Matrix *m2)
{
    if (m1->rows != m2->rows || m1->cols != m2->cols)
    {
        return false;
    }
    for (int i = 0; i < m1->rows * m2->cols; i++)
    {
        double a = (m1->data)[i];
        double b = (m2->data)[i];
        if (!double_equals(a, b))
        {
            return false;
        }
    }
    return true;
}