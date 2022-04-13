#ifndef POLY_CF64_H
#define POLY_CF64_H

#ifndef STDLIB_H
#define STDLIB_H
#include "stdlib.h"
#endif

#include "../imaginary/cf64.h"

typedef struct {
    cf64* coeffs;
    size_t len;
} poly_cf64;

poly_cf64 add_poly_cf64(poly_cf64 lhs, poly_cf64 rhs);
poly_cf64 sub_poly_cf64(poly_cf64 lhs, poly_cf64 rhs);

#endif
