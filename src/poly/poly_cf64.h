#ifndef POLY_CF64_H
#define POLY_CF64_H

#ifndef STDLIB_H
#define STDLIB_H
#include "stdlib.h"
#endif

#include "../imaginary/cf64.h"

struct poly_cf64 {
    cf64* coeffs;
    size_t len;
};

void add_poly_cf64(struct poly_cf64 lhs,
                   struct poly_cf64 rhs,
                   struct poly_cf64* result);

void sub_poly_cf64(struct poly_cf64 lhs,
                   struct poly_cf64 rhs,
                   struct poly_cf64* result);

#endif
