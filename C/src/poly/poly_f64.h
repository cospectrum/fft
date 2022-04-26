#ifndef POLY_F64_H
#define POLY_F64_H

#ifndef STDLIB_H
#define STDLIB_H
#include "stdlib.h"
#endif

typedef struct {
    double* coeffs;
    size_t len;
} poly_f64;

poly_f64 add_poly_f64(poly_f64 lhs, poly_f64 rhs);
poly_f64 sub_poly_f64(poly_f64 lhs, poly_f64 rhs);

#endif
