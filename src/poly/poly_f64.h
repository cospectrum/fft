#ifndef POLY_F64_H
#define POLY_F64_H

#ifndef STDLIB_H
#define STDLIB_H
#include "stdlib.h"
#endif

struct poly_f64 {
    double* coeffs;
    size_t len;
};

void add_poly_f64(struct poly_f64 lhs, 
                  struct poly_f64 rhs,
                  struct poly_f64* result);

void sub_poly_f64(struct poly_f64 lhs,
                  struct poly_f64 rhs,
                  struct poly_f64* result);

#endif
