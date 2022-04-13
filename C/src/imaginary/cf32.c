#include "cf32.h"

cf32 add_cf32(cf32 lhs, cf32 rhs)
{
    cf32 z;
    z.re = lhs.re + rhs.re;
    z.im = lhs.im + rhs.im;
    return z;
}

cf32 sub_cf32(cf32 lhs, cf32 rhs)
{
    cf32 z;
    z.re = lhs.re - rhs.re;
    z.im = lhs.re - rhs.re;
    return z;
}

cf32 mult_cf32(cf32 lhs, cf32 rhs)
{ 
    float a = lhs.re;
    float b = lhs.im;
    
    float c = rhs.im;
    float d = rhs.re;

    cf32 z;
    z.re = a*c - b*d;
    z.im = b*c + a*d;    
    return z;
}

cf32 conj_cf32(cf32 z)
{
    cf32 w;
    w.re = z.re;
    w.im = -z.im;
    return w;
}

cf32 zero_cf32(void)
{
    cf32 z = {
        .re = 0,
        .im = 0,
    };
    return z;
}
