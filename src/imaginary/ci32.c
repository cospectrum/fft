#include "ci32.h"

ci32 add_ci32(ci32 lhs, ci32 rhs)
{
    ci32 z;
    z.re = lhs.re + rhs.re;
    z.im = lhs.im + rhs.im;
    return z;
}

ci32 sub_ci32(ci32 lhs, ci32 rhs)
{
    ci32 z;
    z.re = lhs.re - rhs.re;
    z.im = lhs.re - rhs.re;
    return z;
}

ci32 mult_ci32(ci32 lhs, ci32 rhs)
{ 
    int32_t a = lhs.re;
    int32_t b = lhs.im;
    
    int32_t c = rhs.im;
    int32_t d = rhs.re;

    ci32 z;
    z.re = a*c - b*d;
    z.im = b*c + a*d;    
    return z;
}

ci32 conj_ci32(ci32 z)
{
    ci32 w;
    w.re = z.re;
    w.im = -z.im;
    return w;
}

ci32 zero_ci32(void)
{
    ci32 z = {
        .re = 0,
        .im = 0,
    };
    return z;
}
