#include "../matrix.h"
#include "../special_math.h"

void test_matrix()
{
    printf("------------------------------\n");
    printf("-         Test matrix        -\n");
    printf("------------------------------\n");
    Matrix *m1 = Matrix__constructor(5, 3);
    printf("m1:\n");
    m1->print(m1);
    m1->size(m1);

    double arr[10] = {1.0, 2.0, 3.0, 4.0, 5.0,
                      6.0, 7.0, 8.0, 9.0, 10.0};

    Matrix *m2 = Matrix__fromArr(2, 5, arr, 10);
    printf("m2:\n");
    m2->print(m2);
    m2->size(m2);

    printf("row_swap(m2, 0, 1) for m2:\n");
    m2->row_swap(m2, 0, 1);
    printf("m2:\n");
    m2->print(m2);
    m2->size(m2);

    printf("scalar_multiply(m2, 0.5) for m2:\n");
    m2->scalar_multiply(m2, 0.5);
    printf("m2:\n");
    m2->print(m2);
    m2->size(m2);

    printf("row_scalar_multiply(m2, 1, 3) for m2:\n");
    m2->row_scalar_multiply(m2, 1, 3);
    printf("m2:\n");
    m2->print(m2);
    m2->size(m2);

    printf("putting values into m1:\n");
    m1->set(m1, 0, 0, 2);
    m1->set(m1, 0, 1, 4);
    m1->set(m1, 0, 2, 2);
    m1->set(m1, 1, 0, 4);
    m1->set(m1, 1, 1, 2);
    m1->set(m1, 1, 2, 4);
    m1->set(m1, 2, 0, 2);
    m1->set(m1, 2, 1, 4);
    m1->set(m1, 2, 2, 2);
    m1->set(m1, 3, 0, 4);
    m1->set(m1, 3, 1, 2);
    m1->set(m1, 3, 2, 4);
    m1->set(m1, 4, 0, 2);
    m1->set(m1, 4, 1, 4);
    m1->set(m1, 4, 2, 2);
    printf("m1:\n");
    m1->print(m1);
    m1->size(m1);

    Matrix *m3 = m2->multiply(m2, m1);
    printf("m3 = m2 multiply m1:\n");
    m3->print(m3);
    m3->size(m3);

    double arr2[6] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    Matrix *m4 = Matrix__fromArr(2, 3, arr2, 6);
    m4->scalar_multiply(m4, 0.1);
    printf("m4:\n");
    m4->print(m4);
    m4->size(m4);

    m3->hadamard(m3, m4);
    printf("hadamard(m3, m4) into m3:\n");
    m3->print(m3);
    m3->size(m3);

    m3->add(m3, m4);
    printf("add(m3, m4) into m3:\n");
    m3->print(m3);
    m3->size(m3);

    Matrix *m5 = m3->transpose(m3);
    printf("transpose(m3) into m5:\n");
    m5->print(m5);
    m5->size(m5);

    m1->set(m1, 0, 2, 0);
    m1->set(m1, 1, 2, 0);
    m1->set(m1, 2, 2, 0);
    m1->set(m1, 3, 2, 0);
    m1->set(m1, 4, 2, 0);
    printf("zero_vector(m1) (Expected true): %s\n", m1->zero_vector(m1) ? "true" : "false");

    double arr3[6] = {5.7, 25.6, 13, 36.5, 17.1, 38.4};
    Matrix *m6 = Matrix__fromArr(3, 2, arr3, 6);

    printf("equals(m5, m6) (Expected: true) : %s\n", m5->equals(m5, m6) ? "true" : "false");
    printf("equals(m5, m3) (Expected: false) : %s\n", m5->equals(m5, m3) ? "true" : "false");

    m1->destroy(m1);
    m2->destroy(m2);
    m3->destroy(m3);
    m4->destroy(m4);
    m5->destroy(m5);
    m6->destroy(m6);
}

void test_special_maths()
{
    printf("------------------------------\n");
    printf("-      Test special_math     -\n");
    printf("------------------------------\n");
    printf("abs_val(5.32) = %f (Expected: 5.32)\n", abs_val(5.32));
    printf("abs_val(-5.32) = %f (Expected: 5.32)\n", abs_val(-5.32));
    printf("sigmoid(0) = %f (Expected: 0.5)\n", sigmoid(0));
    printf("d_sigmoid(0) = %f (Expected: 0)\n", d_sigmoid(0));
    printf("rand_weight() = %f (Expected: who knows?)\n", rand_weight());
    printf("double_equals(3.14, 3.14) = %s (Expected: true)\n", double_equals(3.14, 3.14) ? "true" : "false");
    printf("double_equals(3.15, 3.14) = %s (Expected: false)\n", double_equals(3.15, 3.14) ? "true" : "false");
    printf("double_equals(3.0, 3.0000000001) = %s (Expected: false)\n", double_equals(3.0, 3.0000000001) ? "true" : "false");
}

int main()
{
    printf("-----------------------------------------\n");
    printf("-  Testing all components of Alcobra... -\n");
    printf("-----------------------------------------\n");
    test_special_maths();
    test_matrix();
    printf("-----------------------------------------\n");
    printf("-              END OF TESTS             -\n");
    printf("-----------------------------------------\n");
}