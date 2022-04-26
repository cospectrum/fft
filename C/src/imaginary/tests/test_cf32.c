#include "test_cf32.h"

static float MIN = -10;
static float MAX = 10;

void test_cf32(unsigned int tries)
{
    srand((unsigned int) time(NULL));
    
    const char* minus = "----------";
    printf("%sTEST: cf32%s\n", minus, minus);

    for (int i = 0; i < tries; ++i) {
        test_add_cf32();
        test_sub_cf32();
        test_mult_cf32();
    }
    printf("\n");

}

//! return random complex number with ".re" and ".im" in [min, max]
cf32 random_cf32(float min, float max)
{
    cf32 z = {
        .re = random(min, max),
        .im = random(min, max)
    };
    return z;
}

void test_add_cf32(void)
{   
    cf32 lhs = random_cf32(MIN, MAX);
    cf32 rhs = random_cf32(MIN, MAX);

    cf32 actual = add_cf32(lhs, rhs);
    
    cf32 expected = {
        .re = lhs.re + rhs.re,
        .im = lhs.im + rhs.im
    };

    if (!eq(actual, expected)) {
        printf(
            "FAILED test_add_cf32:\n"
            "\t add_cf32((%f, %f), (%f, %f)) == (%f, %f);\n",
            lhs.re, lhs.im, rhs.re, rhs.im,
            actual.re, actual.im
        );
        printf(
            "\t expected == (%f, %f);\n\n",
            expected.re, expected.im
        );
    }
}

void test_sub_cf32(void)
{
    cf32 lhs = random_cf32(MIN, MAX);
    cf32 rhs = random_cf32(MIN, MAX);

    cf32 actual = sub_cf32(lhs, rhs);

    cf32 expected = {
        .re = lhs.re - rhs.re,
        .im = lhs.im - rhs.im
    };
 
    if (!eq(actual, expected)) {
         printf(
            "FAILED test_sub_cf32:\n"
            "\t sub_cf32((%f, %f), (%f, %f)) == (%f, %f);\n",
            lhs.re, lhs.im, rhs.re, rhs.im,
            actual.re, actual.im
        );
        printf(
            "\t expected == (%f, %f);\n\n",
            expected.re, expected.im
        );
    }
}

void test_mult_cf32 (void)
{
    cf32 lhs = random_cf32(MIN, MAX);
    cf32 rhs = random_cf32(MIN, MAX);
    
    float a, b, c, d;
    a = lhs.re;
    b = lhs.im;
    c = rhs.re;
    d = rhs.im;

    cf32 actual = mult_cf32(lhs, rhs);

    // (a + ib)(c + id) = ac - bd + ibc + iad
    cf32 expected = {
        .re = a*c - b*d,
        .im = b*c + a*d
    };
    
    if (!eq(actual, expected)) {
         printf(
            "FAILED test_mult_cf32:\n"
            "\t mult_cf32((%f, %f), (%f, %f)) == (%f, %f);\n",
            lhs.re, lhs.im, rhs.re, rhs.im,
            actual.re, actual.im
        );
        printf(
            "\t expected == (%f, %f);\n\n",
            expected.re, expected.im
        );
    }
}

void test_conj_cf32(void)
{
    cf32 z = random_cf32(MIN, MAX);
    
    cf32 actual = conj_cf32(z);
    cf32 expected = { .re = z.re, .im = -z.im };

    if (!eq(actual, expected)) {
        printf(
            "FAILED test_conj_cf32:\n"
            "\t conj_cf32((%f, %f)) == (%f, %f);\n",
            z.re, z.im,
            actual.re, actual.im
        );
        printf(
            "\t expected == (%f, %f);\n\n",
            expected.re, expected.im
        );
    }
}


