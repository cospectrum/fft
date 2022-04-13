#include "poly_cf64.h"

poly_cf64 add_poly_cf64(poly_cf64 lhs, poly_cf64 rhs)
{
    size_t max_len;
    size_t min_len;
    poly_cf64* max_poly;

    if (lhs.len > rhs.len) {
        max_len = lhs.len;
        min_len = rhs.len;
        max_poly = &lhs;
    } else {
        max_len = rhs.len;
        min_len = lhs.len;
        max_poly = &rhs;
    }

    poly_cf64 p;
    p.len = max_len;
    p.coeffs = (cf64*) malloc(max_len * sizeof(cf64));

    for (size_t i = 0; i < min_len; ++i) 
        p.coeffs[i] = add_cf64(lhs.coeffs[i], rhs.coeffs[i]);

    for (size_t i = min_len; i < max_len; ++i)
        p.coeffs[i] = max_poly->coeffs[i];
    
    return p;
}

