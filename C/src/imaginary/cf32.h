#ifndef CF32_H
#define CF32_H

typedef struct {
    float re;
    float im;
} cf32;

cf32 add_cf32(cf32 lhs, cf32 rhs);
cf32 sub_cf32(cf32 lhs, cf32 rhs);
cf32 mult_cf32(cf32 lhs, cf32 rhs);
cf32 conj_cf32(cf32 z);
cf32 zero_cf32(void);

#endif
