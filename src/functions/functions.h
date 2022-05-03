#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#ifndef STDINT_H
#define STDINT_H
#include <stdint.h>
#endif

#include "../imaginary/cf32.h"
#include "../imaginary/cf64.h"

#ifndef PI
#define PI 3.1415926535
#endif

#ifndef E
#define E 2.7182818284
#endif

float pow_f32(float base, uint64_t exp);
double pow_f64(double base, uint64_t exp);
int32_t pow_i32(int32_t base, uint64_t exp);
int64_t pow_i64(int64_t base, uint64_t exp);
cf32 pow_cf32(cf32 base, uint64_t exp);
cf64 pow_cf64(cf64 base, uint64_t exp);

double cos_f64(double x);
double sin_f64(double x);

double exp_f64(double x);
cf64 exp_cf64(cf64 z);

#endif
