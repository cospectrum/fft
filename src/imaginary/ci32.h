#ifndef CI32_H
#define CI32_H

#ifndef STDINT_H
#define STDINT_H
#include <stdint.h>
#endif

typedef struct {
    int32_t re;
    int32_t im;
} ci32;

ci32 add_ci64(ci32 lhs, ci32 rhs);
ci32 sub_ci64(ci32 lhs, ci32 rhs);
ci32 mult_ci64(ci32 lhs, ci32 rhs);
ci32 conj_ci64(ci32 z);
ci32 zero_ci32(void);

#endif
