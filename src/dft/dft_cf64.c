#include "dft_cf64.h"

void dft_cf64(struct poly_cf64 p, struct poly_cf64* result)
{
    size_t N = p.len;
    result->len = N;

    cf64 z = {
        .re = 0,
        .im = -2 * PI / (double) N,
    };
    cf64 w_1 = exp_cf64(z);  /// e^(-i*2pi/N)

    /// e^(k * -i*2pi/N)
    cf64 w_k = {
        .re = 1,
        .im = 0,
    };    
    cf64 w_kn;  /// e^(kn * -i*2pi/N)        
    cf64 z_n;   /// x_n * e^(kn * -i*2pi/N)
    cf64 sum;   /// X_n == sum x_n * e^(kn * -i*2pi/N)

    for (size_t k = 0; k < N; ++k) {
        sum = zero_cf64();
        for (size_t n = 0; n < N; ++n) {
            w_kn = mult_cf64(w_kn, w_k);
            z_n =  mult_cf64(p.coeffs[n], w_kn);
            sum = add_cf64(sum, z_n);
        }
        result->coeffs[k] = sum;
        w_k = mult_cf64(w_1, w_k);
    }
}

void idft_cf64(struct poly_cf64 p, struct poly_cf64* result)
{
    size_t N = p.len;
    result->len = N;

    /// 1/N
    cf64 denominator = {
        .re = 1 / N,
        .im = 0,
    };

    cf64 z = {
        .re = 0,
        .im = 2 * PI / (double) N,
    };
    cf64 w_1 = exp_cf64(z);  /// e^(i*2pi/N)

    /// e^(k * i*2pi/N)
    cf64 w_k = {
        .re = 1,
        .im = 0,
    }; 

    cf64 w_kn;  /// e^(kn * i*2pi/N)        
    cf64 z_n;   /// X_n * e^(kn * i*2pi/N)
    cf64 sum;   /// N * x_n == sum X_n * e^(kn * i*2pi/N)

    for (size_t k = 0; k < N; ++k) {
        sum = zero_cf64();
        for (size_t n = 0; n < N; ++n) {
            w_kn = mult_cf64(w_kn, w_k);
            z_n =  mult_cf64(p.coeffs[n], w_kn);
            sum = add_cf64(sum, z_n);
        }
        result->coeffs[k] = mult_cf64(sum, denominator);
        w_k = mult_cf64(w_1, w_k);
    }
}
