#ifndef CI64_H
#define CI64_H

#ifndef STDINT_H
#define STDINT_H
#include <stdint.h>
#endif

typedef struct {
    int64_t re;
    int64_t im;
} ci64;

ci64 add_ci64(ci64 lhs, ci64 rhs);
ci64 sub_ci64(ci64 lhs, ci64 rhs);
ci64 mult_ci64(ci64 lhs, ci64 rhs);
ci64 conj_ci64(ci64 z);
ci64 zero_ci64(void);

#endif