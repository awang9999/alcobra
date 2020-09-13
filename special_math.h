
#ifndef SPECIAL_MATH_H
#define SPECIAL_MATH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/* simple math functions on doubles */
double abs_val(double x);
bool double_equals(double a, double b);
double rand_weight();

/* common activation functions and their derivatives */
double sigmoid(double x);
double d_sigmoid(double x);

#endif