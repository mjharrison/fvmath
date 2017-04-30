#ifndef FVMATH_HPP
#define FVMATH_HPP

#include <x86intrin.h>

#ifdef __SSE__

__m128 _fvlen(__m128 a);
__m128 _fvnorm(__m128 a);
__m128 _fvdotp(__m128 a, __m128 b);
__m128 _fvproj(__m128 a, __m128 b);

#endif

void fvmuls(float vector[4], float factor);
void fvdivs(float vector[4], float factor);
void fvadd(float vectorA[4], float vectorB[4]);
void fvsub(float vectorA[4], float vectorB[4]);
float fvlen(float vector[4]);
void fvnorm(float vector[4]);
float fvdotp(float vectorA[4], float vectorB[4]);
void fvproj(float vectorA[4], float vectorB[4]);

void fvmuls(double vector[4], double factor);
void fvdivs(double vector[4], double factor);
void fvadd(double vectorA[4], double vectorB[4]);
void fvsub(double vectorA[4], double vectorB[4]);
float fvlen(double vector[4]);
void fvnorm(double vector[4]);
float fvdotp(double vectorA[4], double vectorB[4]);
void fvproj(double vectorA[4], double vectorB[4]);

#endif
