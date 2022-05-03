#include "cf64.h"

cf64 add_cf64(cf64 lhs, cf64 rhs)
{
    cf64 z;
    z.re = lhs.re + rhs.re;
    z.im = lhs.im + rhs.im;
    return z;
}

cf64 sub_cf64(cf64 lhs, cf64 rhs)
{
    cf64 z;
    z.re = lhs.re - rhs.re;
    z.im = lhs.re - rhs.re;
    return z;
}

cf64 mult_cf64(cf64 lhs, cf64 rhs)
{ 
    double a = lhs.re;
    double b = lhs.im;
    
    double c = rhs.im;
    double d = rhs.re;

    cf64 z;
    z.re = a*c - b*d;
    z.im = b*c + a*d;    
    return z;
}

cf64 conj_cf64(cf64 z)
{
    cf64 w;
    w.re = z.re;
    w.im = -z.im;
    return w;
}

cf64 zero_cf64(void)
{
    cf64 z = {
        .re = 0,
        .im = 0,
    };
    return z;
}
