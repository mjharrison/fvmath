#ifndef FVMATH_HPP
#define FVMATH_HPP

#include <x86intrin.h>


#ifdef __SSE__

__m128 _fvlen(__m128 a);
__m128 _fvnorm(__m128 a);
__m128 _fvdotp(__m128 a, __m128 b);
__m128 _fvproj(__m128 a, __m128 b);

#endif

#ifdef __AVX__

__m256 _fvlen(__m256 a);
__m256 _fvnorm(__m256 a);
__m256 _fvdotp(__m256 a, __m256 b);
__m256 _fvproj(__m256 a, __m256 b);

#endif

void fvmuls(float vector_v[4], float vector_u);
void fvdivs(float vector_v[4], float factor_k);
void fvadd(float vector_v[4], float vector_u[4]);
void fvsub(float vector_v[4], float vector_u[4]);
float fvlen(float vector_v[4]);
void fvnorm(float vector_v[4]);
float fvdotp(float vector_v[4], float vector_u[4]);
void fvproj(float vector_v[4], float vector_u[4]);

void fvmuls(double vector_v[4], double factor_k);
void fvdivs(double vector_v[4], double factor_k);
void fvadd(double vector_v[4], double vector_u[4]);
void fvsub(double vector_v[4], double vector_u[4]);
double fvlen(double vector_v[4]);
void fvnorm(double vector_v[4]);
double fvdotp(double vector_v[4], double vector_u[4]);
void fvproj(double vector_v[4], double vector_u[4]);


#endif
