#include "dft_cf64.h"

poly_cf64 dft_cf64(poly_cf64 p)
{
    size_t N = p.len;

    poly_cf64 f;
    f.len = N;
    f.coeffs = (cf64*) calloc(N, sizeof(cf64));

    cf64 z;
    z.re = 0;
    z.im = -2 * PI / (double) N;
    cf64 w_n = exp_cf64(z);

    cf64 w = w_n;
    w.re = 1;
    w.im = 0;
    for (size_t k = 0; k < N; ++k) {
        for (size_t n = 0; n < N; ++n)
            f.coeffs[k] = add_cf64(
                f.coeffs[k],
                mult_cf64(p.coeffs[n], pow_cf64(w, n))
            );
        w = mult_cf64(w, w_n);
    }
    
    return f;
}
