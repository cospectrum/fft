#include "poly_f64.h"

poly_f64 add_poly_f64(poly_f64 lhs, poly_f64 rhs)
{
    size_t max_len;
    size_t min_len;
    poly_f64* max_poly;

    if (lhs.len > rhs.len) {
        max_len = lhs.len;
        min_len = rhs.len;
        max_poly = &lhs;
    } else {
        max_len = rhs.len;
        min_len = lhs.len;
        max_poly = &rhs;
    }

    poly_f64 p;
    p.len = max_len;
    p.coeffs = malloc(max_len * sizeof(double));

    for (size_t i = 0; i < min_len; ++i) 
        p.coeffs[i] = lhs.coeffs[i] + rhs.coeffs[i];

    for (size_t i = min_len; i < max_len; ++i)
        p.coeffs[i] = max_poly->coeffs[i];
    
    return p;
}

