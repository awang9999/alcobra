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
    Matrix *result = Matrix__constructor(length, length);
    for (int i = 0; i < length; i++)
    {
        result->set(result, i, i, 1.0);
    }
    return result;
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

Matrix *Matrix__fromArr(int r, int c, double *vals, int arr_size)
{
    if (arr_size != r * c)
    {
        printf("Cannot form matrix from array because the provided array does not match specified dimensions.\n");
        return NULL;
    }

    Matrix *ret = Matrix__constructor(r, c);

    for (int i = 0; i < arr_size; i++)
    {
        (ret->data)[i] = vals[i];
    }

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
    if (a < 0 || b < 0 || a > m->rows || b > m->rows)
    {
        printf("Error (row_swap): rows are out of bounds.\n");
        printf("m:");
        m->size(m);
        return false;
    }

    for (int i = 0; i < m->cols; i++)
    {
        double tmp1 = m->get(m, a, i);
        double tmp2 = m->get(m, b, i);
        m->set(m, a, i, tmp2);
        m->set(m, b, i, tmp1);
    }
    return true;
}
bool Matrix__scalar_multiply(Matrix *m, double factor)
{
    for (int r = 0; r < m->rows; r++)
    {
        for (int c = 0; c < m->cols; c++)
        {
            double x = (m->get(m, r, c)) * factor;
            m->set(m, r, c, x);
        }
    }
    return true;
}
bool Matrix__row_scalar_multiply(Matrix *m, int row, double factor)
{
    for (int c = 0; c < (m->cols); c++)
    {
        double x = (m->get(m, row, c)) * factor;
        m->set(m, row, c, x);
    }
    return true;
}
/*
    m1 is modified such that every element of m1 becomes the sum
    of every element of m1 with the corresponding element of m2.
*/
bool Matrix__add(Matrix *m1, Matrix *m2)
{
    if (m1->rows != m2->rows || m1->cols != m2->cols)
    {
        printf("Error (add): Matrices m1 and m2 have mismatched dimensions.\n");
        printf("m1:");
        m1->size(m1);
        printf("m2:");
        m2->size(m2);
        return false;
    }

    for (int r = 0; r < m1->rows; r++)
    {
        for (int c = 0; c < m1->cols; c++)
        {
            double x = (m1->get(m1, r, c)) + (m2->get(m2, r, c));
            m1->set(m1, r, c, x);
        }
    }
    return true;
}
/*
    m1 is modified such that every element of m1 becomes the difference
    of every element of m1 with the corresponding element of m2.
*/
bool Matrix__subtract(Matrix *m1, Matrix *m2)
{
    if (m1->rows != m2->rows || m1->cols != m2->cols)
    {
        printf("Error (subtract): Matrices m1 and m2 have mismatched dimensions.\n");
        printf("m1:");
        m1->size(m1);
        printf("m2:");
        m2->size(m2);
        return false;
    }

    for (int r = 0; r < m1->rows; r++)
    {
        for (int c = 0; c < m1->cols; c++)
        {
            double x = (m1->get(m1, r, c)) - (m2->get(m2, r, c));
            m1->set(m1, r, c, x);
        }
    }
    return true;
}

/* Matrix-derived values */
double Matrix__determinant(Matrix *m)
{
    //TODO
    printf("WARNING: Matrix__determinant is unimplemented.\n");
    return 0;
}
bool Matrix__zero_vector(Matrix *m)
{
    for (int i = 0; i < m->cols; i++)
    {
        double sum = 0.0;
        for (int j = 0; j < m->rows; j++)
        {
            sum += m->get(m, j, i);
        }
        if (double_equals(sum, 0.0))
        {
            return true;
        }
    }
    return false;
}

/* Matrix-derived constructions */
Matrix *Matrix__invert(Matrix *m)
{
    //TODO
    printf("WARNING: Matrix__invert is unimplemented.\n");
    return NULL;
}

Matrix *Matrix__transpose(Matrix *m)
{
    Matrix *result = Matrix__constructor(m->cols, m->rows);
    for (int r = 0; r < (m->rows); r++)
    {
        for (int c = 0; c < (m->cols); c++)
        {
            result->set(result, c, r, m->get(m, r, c));
        }
    }
    return result;
}

Matrix *Matrix__multiply(Matrix *m1, Matrix *m2)
{
    if (m1->cols != m2->rows)
    {
        printf("Error (multiply): Matrices m1 and m2 have mismatched dimensions.\n");
        printf("m1:");
        m1->size(m1);
        printf("m2:");
        m2->size(m2);
        return NULL;
    }

    Matrix *result = Matrix__constructor(m1->rows, m2->cols);

    for (int i = 0; i < result->rows; i++)
    {
        for (int j = 0; j < result->cols; j++)
        {
            double sum = 0.0;
            for (int k = 0; k < (m1->cols); k++)
            {
                sum += (m1->get(m1, i, k)) * (m2->get(m2, k, j));
            }
            result->set(result, i, j, sum);
        }
    }
    return result;
}

Matrix *Matrix__hadamard(Matrix *m1, Matrix *m2)
{
    if (m1->rows != m2->rows || m1->cols != m2->cols)
    {
        printf("Error (hadamard): Matrices m1 and m2 have mismatched dimensions.\n");
        printf("m1:");
        m1->size(m1);
        printf("m2:");
        m2->size(m2);
        return NULL;
    }

    for (int r = 0; r < m1->rows; r++)
    {
        for (int c = 0; c < m1->cols; c++)
        {
            double x = (m1->get(m1, r, c)) * (m2->get(m2, r, c));
            m1->set(m1, r, c, x);
        }
    }
    return m1;
}

/* Mutators and accessors */
double Matrix__get(Matrix *m, int r, int c)
{
    if (r < 0 || c < 0 || r > m->rows || c > m->cols)
    {
        printf("Error (get): row or column is out of bounds.\n");
        printf("m:");
        m->size(m);
        return 0.0;
    }
    return m->data[r * (m->cols) + c];
}

bool Matrix__set(Matrix *m, int r, int c, double val)
{
    if (r < 0 || c < 0 || r > m->rows || c > m->cols)
    {
        printf("Error (set): row or column is out of bounds.\n");
        printf("m:");
        m->size(m);
        return false;
    }
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
            printf(" %.4lf ", m->get(m, i, j));
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