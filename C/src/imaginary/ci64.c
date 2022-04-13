#include "ci64.h"

ci64 add_ci64(ci64 lhs, ci64 rhs)
{
    ci64 z;
    z.re = lhs.re + rhs.re;
    z.im = lhs.im + rhs.im;
    return z;
}

ci64 sub_ci64(ci64 lhs, ci64 rhs)
{
    ci64 z;
    z.re = lhs.re - rhs.re;
    z.im = lhs.re - rhs.re;
    return z;
}

ci64 mult_ci64(ci64 lhs, ci64 rhs)
{ 
    int64_t a = lhs.re;
    int64_t b = lhs.im;
    
    int64_t c = rhs.im;
    int64_t d = rhs.re;

    ci64 z;
    z.re = a*c - b*d;
    z.im = b*c + a*d;    
    return z;
}

ci64 conj_ci64(ci64 z)
{
    ci64 w;
    w.re = z.re;
    w.im = -z.im;
    return w;
}

ci64 zero_ci64(void)
{
    ci64 z = {
        .re = 0,
        .im = 0,
    };
    return z;
}
