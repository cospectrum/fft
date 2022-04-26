#ifndef UTILS_H
#define UTILS_H

#ifndef TIME_H
#define TIME_H
#include <time.h>
#endif

#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif

#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

#define eq(lhs, rhs) (lhs.re == rhs.re && lhs.im == rhs.im)

//! return random number in [min, max]
#define random(min, max) min + (rand() / RAND_MAX)*(max - min)

#endif
