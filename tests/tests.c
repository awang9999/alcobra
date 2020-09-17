#include "../matrix.h"

void test_matrix()
{
    Matrix *m1 = Matrix__constructor(5, 3);
    m1->print(m1);
    m1->size(m1);
    m1->destroy(m1);
}

int main()
{
    printf("Testing all components of Alcobra...\n");
    test_matrix();
}