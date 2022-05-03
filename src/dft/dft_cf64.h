#ifndef DFT_CF64_H
#define DFT_CF64_H

#include "../imaginary/cf64.h"
#include "../poly/poly_cf64.h"
#include "../functions/functions.h"

void dft_cf64(struct poly_cf64 p, struct poly_cf64* result);
void idft_cf64(struct poly_cf64 p, struct poly_cf64* result);

#endif
