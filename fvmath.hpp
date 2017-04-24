#ifndef VIVEK_HPP
#define VIVEK_HPP

#include <x86intrin.h>


void fvmuls(float vector[4], float factor);

void fvdivs(float vector[4], float factor);

void fvadd(float vectorA[4], float vectorB[4]);

void fvsub(float vectorA[4], float vectorB[4]);

__m128 fvhsum(__m128 a);

__m128 _fvlen(__m128 a);
float fvlen(float vector[4]);

__m128 _fvnorm(__m128 a);
void fvnorm(float vector[4]);

__m128 _fvdotp(__m128 a, __m128 b);
float fvdotp(float vectorA[4], float vectorB[4]);

__m128 _fvproj(__m128 a, __m128 b);
void fvproj(float vectorA[4], float vectorB[4]);


#endif
