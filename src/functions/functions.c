#include "functions.h"

uint64_t FACTORIAL[21] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800, 87178291200ul, 1307674368000ul, 20922789888000ul, 355687428096000ul, 6402373705728000ul, 121645100408832000ul, 2432902008176640000ul};

float pow_f32(float base, uint64_t exp)
{
    if (exp == 0)
        return 1;
        
    if (exp % 2 == 0) {
        float power = pow_f32(base, exp/2);
        return power * power;
    }
    return base * pow_f32(base, (exp - 1)/2);
}

double pow_f64(double base, uint64_t exp)
{
    if (exp == 0)
        return 1;
        
    if (exp % 2 == 0) {
        double power = pow_f64(base, exp/2);
        return power * power;
    }
    return base * pow_f64(base, (exp - 1)/2);
}

int32_t pow_i32(int32_t base, uint64_t exp)
{
    if (exp == 0)
        return 1;
        
    if (exp % 2 == 0) {
        int32_t power = pow_i32(base, exp/2);
        return power * power;
    }
    return base * pow_i32(base, (exp - 1)/2);
}

int64_t pow_i64(int64_t base, uint64_t exp)
{
    if (exp == 0)
        return 1;        
 
    if (exp % 2 == 0) {
        int64_t power = pow_i64(base, exp/2);
        return power * power;
    }
    return base * pow_i64(base, (exp - 1)/2);
}

cf32 pow_cf32(cf32 base, uint64_t exp)
{
    if (exp == 0) {
        cf32 zero = { .re = 0, .im = 0 };
        return zero;
    }
    if (exp % 2 == 0) {
        cf32 power = pow_cf32(base, exp/2);
        return mult_cf32(power, power);
    }
    return mult_cf32(base, pow_cf32(base, (exp - 1)/2));
}

cf64 pow_cf64(cf64 base, uint64_t exp)
{
    if (exp == 0) {
        cf64 zero = { .re = 0, .im = 0 };
        return zero;
    }
    if (exp % 2 == 0) {
        cf64 power = pow_cf64(base, exp/2);
        return mult_cf64(power, power);
    }
    return mult_cf64(base, pow_cf64(base, (exp - 1)/2));
}

double cos_f64(double x)
{
    double result = 1;
    int8_t sign = -1;
        
    for (uint8_t n = 2; n < 21; n += 2) {
        result += sign * pow_f64(x, n) / FACTORIAL[n];
        sign *= -1;
    }
    return result;
}

double sin_f64(double x)
{
    double result = x;
    int8_t sign = -1;

    for (uint8_t n = 3; n < 21; n += 2) {
        result += sign * pow_f64(x, n) / FACTORIAL[n];
        sign *= -1;
    }
    return result;
}

double exp_f64(double x)
{
    double result = 1 + x;
    for (uint8_t n = 2; n < 21; ++n)
        result += pow_f64(x, n) / FACTORIAL[n];
    
    return result;
}

cf64 exp_cf64(cf64 z)
{
    double r = exp_f64(z.re);
    
    double cos = cos_f64(z.im);
    double sin = sin_f64(z.im);

    cf64 exp = {
        .re = r * cos,
        .im = r * sin
    };
    return exp;
}
