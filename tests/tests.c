#include "../matrix.h"

void test_matrix()
{
    Matrix *m1 = Matrix__constructor(5, 3);
    m1->print(m1);
    m1->size(m1);

    double arr[6] = {1.0, 2.0, 3.0,
                     4.0, 5.0, 6.0};

    Matrix *m2 = Matrix__fromArr(2, 3, arr, 6);
    m2->print(m2);
    m2->size(m2);

    m1->destroy(m1);
    m2->destroy(m2);
}

int main()
{
    printf("Testing all components of Alcobra...\n");
    test_matrix();
}