#ifndef VIVEK_HPP
#define VIVEK_HPP

#include <x86intrin.h>


void vmuls(float vector[4], float factor);

void vdivs(float vector[4], float factor);

void vadd(float vectorA[4], float vectorB[4]);

void vsub(float vectorA[4], float vectorB[4]);

__m128 _vlen(__m128 a);
float vlen(float vector[4]);

__m128 _vnorm(__m128 a);
void vnorm(float vector[4]);

__m128 _vdotp(__m128 a, __m128 b);
float vdotp(float vectorA[4], float vectorB[4]);

__m128 _vproj(__m128 a, __m128 b, __m128 c);
void vproj(float vectorA[4], float vectorB[4]);


#endif
