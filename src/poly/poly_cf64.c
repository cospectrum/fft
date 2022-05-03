#include "poly_cf64.h"

void add_poly_cf64(struct poly_cf64 lhs, struct poly_cf64 rhs, struct poly_cf64* result)
{
    size_t max_len;
    size_t min_len;
    struct poly_cf64* max_poly;

    if (lhs.len > rhs.len) {
        max_len = lhs.len;
        min_len = rhs.len;
        max_poly = &lhs;
    } else {
        max_len = rhs.len;
        min_len = lhs.len;
        max_poly = &rhs;
    }

    for (size_t i = 0; i < min_len; ++i) 
        result->coeffs[i] = add_cf64(lhs.coeffs[i], rhs.coeffs[i]);

    for (size_t i = min_len; i < max_len; ++i)
        result->coeffs[i] = max_poly->coeffs[i];

    result->len = max_len;
}

