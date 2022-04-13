#ifndef CF64_H
#define CF64_H

typedef struct {
    double re;
    double im;
} cf64;

cf64 add_cf64(cf64 lhs, cf64 rhs);
cf64 sub_cf64(cf64 lhs, cf64 rhs);
cf64 mult_cf64(cf64 lhs, cf64 rhs);
cf64 conj_cf64(cf64 z);
cf64 zero_cf64(void);

#endif