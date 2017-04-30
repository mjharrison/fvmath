#include "fvmath.hpp"


void fvmuls(float vector[4], float factor)
{
    __m128 u = _mm_load_ps(vector);
    __m128 k = _mm_load_ps1(&factor);
    
    u = _mm_mul_ps(u, k);
    
    _mm_store_ps(vector, u);
}


void fvdivs(float vector[4], float factor)
{
    __m128 a = _mm_load_ps(vector);
    __m128 b = _mm_load_ps1(&factor);
    
    a = _mm_div_ps(a, b);
    
    _mm_store_ps(vector, a);
}


void fvadd(float vectorA[4], float vectorB[4])
{
    __m128 a = _mm_load_ps(vectorA);
    __m128 b = _mm_load_ps(vectorB);
    
    a = _mm_add_ps(a, b);
    
    _mm_store_ps(vectorA, a);
}


void fvsub(float vectorA[4], float vectorB[4])
{
    __m128 a = _mm_load_ps(vectorA);
    __m128 b = _mm_load_ps(vectorB);
    
    a = _mm_sub_ps(a, b);
    
    _mm_store_ps(vectorA, a);
}


__m128 _fvhsum(__m128 a)
{
	__m128 b = _mm_movehdup_ps(a);
	__m128 c = _mm_add_ps(a, b);

	b = _mm_movehl_ps(b, c);
	c = _mm_add_ss(c, b);

	return c;
}


__m128 _fvlen(__m128 a)
{
    a = _mm_mul_ps(a, a);
    a = _fvhsum(a);
    a = _mm_sqrt_ps(a);
    
    return a;
}


float fvlen(float vector[4])
{
    float result;
    __m128 a = _mm_load_ps(vector);
    
    a = _fvlen(a);
    
    _mm_store_ss(&result, a);
    return result;
}


__m128 _fvnorm(__m128 a)
{
    __m128 b = _fvlen(a);
    
    a = _mm_div_ps(a, b);
    
    return a;
}


void fvnorm(float vector[4])
{
    __m128 a = _mm_load_ps(vector);

    a = _fvnorm(a);
    
    _mm_store_ps(vector, a);
}


// source: http://stackoverflow.com/a/35270026
__m128 _fvdotp(__m128 a, __m128 b)
{
    a = _mm_mul_ps(a, b);
    a = _fvhsum(a);
    
    return a;
}


float fvdotp(float vectorA[4], float vectorB[4])
{
    float result;
    __m128 a = _mm_load_ps(vectorA);
    __m128 b = _mm_load_ps(vectorB);
    
    a = _fvdotp(a, b);
    
    _mm_store_ss(&result, a);
    return result;
}


__m128 _fvproj(__m128 a, __m128 b)
{
    a = _fvdotp(a, b);
    b = _fvlen(b);
    b = _mm_mul_ps(b, b);
    a = _mm_mul_ps(a, b);
    
    return a;
}


void fvproj(float vectorA[4], float vectorB[4])
{
    __m128 a = _mm_load_ps(vectorA);
    __m128 b = _mm_load_ps(vectorB);
    
    a = _fvproj(a, b);
    _mm_store_ps(vectorA, a);
}
