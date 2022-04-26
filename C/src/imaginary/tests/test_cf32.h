#ifndef TEST_CF32_H
#define TEST_CF32_H

#include "utils.h"
#include "../cf32.h"

cf32 random_cf32(float min, float max);
void test_add_cf32(void);
void test_sub_cf32(void);
void test_mult_cf32(void);
void test_conj_cf32(void);
void test_cf32(unsigned int tries);

#endif
